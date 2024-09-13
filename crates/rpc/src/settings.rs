use rockbox_sys::types::user_settings::UserSettings;
use tonic::{Request, Response, Status};

use crate::{
    api::rockbox::v1alpha1::{
        settings_service_server::SettingsService, GetGlobalSettingsRequest,
        GetGlobalSettingsResponse, GetSettingsListRequest, GetSettingsListResponse,
    },
    rockbox_url,
};

#[derive(Default)]
pub struct Settings {
    client: reqwest::Client,
}

impl Settings {
    pub fn new(client: reqwest::Client) -> Self {
        Self { client }
    }
}

#[tonic::async_trait]
impl SettingsService for Settings {
    async fn get_global_settings(
        &self,
        _request: Request<GetGlobalSettingsRequest>,
    ) -> Result<Response<GetGlobalSettingsResponse>, Status> {
        let url = format!("{}/settings", rockbox_url());
        let response = self
            .client
            .get(url)
            .send()
            .await
            .map_err(|e| Status::internal(e.to_string()))?;
        let settings = response
            .json::<UserSettings>()
            .await
            .map_err(|e| Status::internal(e.to_string()))?;
        Ok(Response::new(settings.into()))
    }

    async fn get_settings_list(
        &self,
        _request: Request<GetSettingsListRequest>,
    ) -> Result<Response<GetSettingsListResponse>, Status> {
        let url = format!("{}/settingslist", rockbox_url());
        let _response = self
            .client
            .get(url)
            .send()
            .await
            .map_err(|e| Status::internal(e.to_string()))?;
        //let settings = response.json::<UserSettings>().await?;
        todo!()
    }
}