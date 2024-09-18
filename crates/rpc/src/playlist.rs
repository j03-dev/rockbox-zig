use std::sync::{mpsc::Sender, Arc, Mutex};

use rockbox_sys::events::RockboxCommand;

use crate::api::rockbox::v1alpha1::{playlist_service_server::PlaylistService, *};

pub struct Playlist {
    cmd_tx: Arc<Mutex<Sender<RockboxCommand>>>,
}

impl Playlist {
    pub fn new(cmd_tx: Arc<Mutex<Sender<RockboxCommand>>>) -> Self {
        Self { cmd_tx }
    }
}

#[tonic::async_trait]
impl PlaylistService for Playlist {
    async fn get_current(
        &self,
        _request: tonic::Request<GetCurrentRequest>,
    ) -> Result<tonic::Response<GetCurrentResponse>, tonic::Status> {
        Ok(tonic::Response::new(GetCurrentResponse::default()))
    }

    async fn get_resume_info(
        &self,
        _request: tonic::Request<GetResumeInfoRequest>,
    ) -> Result<tonic::Response<GetResumeInfoResponse>, tonic::Status> {
        Ok(tonic::Response::new(GetResumeInfoResponse::default()))
    }

    async fn get_track_info(
        &self,
        _request: tonic::Request<GetTrackInfoRequest>,
    ) -> Result<tonic::Response<GetTrackInfoResponse>, tonic::Status> {
        Ok(tonic::Response::new(GetTrackInfoResponse::default()))
    }

    async fn get_first_index(
        &self,
        _request: tonic::Request<GetFirstIndexRequest>,
    ) -> Result<tonic::Response<GetFirstIndexResponse>, tonic::Status> {
        Ok(tonic::Response::new(GetFirstIndexResponse::default()))
    }

    async fn get_display_index(
        &self,
        _request: tonic::Request<GetDisplayIndexRequest>,
    ) -> Result<tonic::Response<GetDisplayIndexResponse>, tonic::Status> {
        Ok(tonic::Response::new(GetDisplayIndexResponse::default()))
    }

    async fn amount(
        &self,
        _request: tonic::Request<AmountRequest>,
    ) -> Result<tonic::Response<AmountResponse>, tonic::Status> {
        Ok(tonic::Response::new(AmountResponse::default()))
    }

    async fn playlist_resume(
        &self,
        _request: tonic::Request<PlaylistResumeRequest>,
    ) -> Result<tonic::Response<PlaylistResumeResponse>, tonic::Status> {
        self.cmd_tx
            .lock()
            .unwrap()
            .send(RockboxCommand::PlaylistResume)
            .map_err(|_| tonic::Status::internal("Failed to send command"))?;
        Ok(tonic::Response::new(PlaylistResumeResponse::default()))
    }

    async fn resume_track(
        &self,
        _request: tonic::Request<ResumeTrackRequest>,
    ) -> Result<tonic::Response<ResumeTrackResponse>, tonic::Status> {
        self.cmd_tx
            .lock()
            .unwrap()
            .send(RockboxCommand::PlaylistResumeTrack)
            .map_err(|_| tonic::Status::internal("Failed to send command"))?;
        Ok(tonic::Response::new(ResumeTrackResponse::default()))
    }

    async fn set_modified(
        &self,
        _request: tonic::Request<SetModifiedRequest>,
    ) -> Result<tonic::Response<SetModifiedResponse>, tonic::Status> {
        Ok(tonic::Response::new(SetModifiedResponse::default()))
    }

    async fn start(
        &self,
        _request: tonic::Request<StartRequest>,
    ) -> Result<tonic::Response<StartResponse>, tonic::Status> {
        Ok(tonic::Response::new(StartResponse::default()))
    }

    async fn sync(
        &self,
        _request: tonic::Request<SyncRequest>,
    ) -> Result<tonic::Response<SyncResponse>, tonic::Status> {
        Ok(tonic::Response::new(SyncResponse::default()))
    }

    async fn remove_all_tracks(
        &self,
        _request: tonic::Request<RemoveAllTracksRequest>,
    ) -> Result<tonic::Response<RemoveAllTracksResponse>, tonic::Status> {
        Ok(tonic::Response::new(RemoveAllTracksResponse::default()))
    }

    async fn create_playlist(
        &self,
        _request: tonic::Request<CreatePlaylistRequest>,
    ) -> Result<tonic::Response<CreatePlaylistResponse>, tonic::Status> {
        Ok(tonic::Response::new(CreatePlaylistResponse::default()))
    }

    async fn insert_track(
        &self,
        _request: tonic::Request<InsertTrackRequest>,
    ) -> Result<tonic::Response<InsertTrackResponse>, tonic::Status> {
        Ok(tonic::Response::new(InsertTrackResponse::default()))
    }

    async fn insert_directory(
        &self,
        _request: tonic::Request<InsertDirectoryRequest>,
    ) -> Result<tonic::Response<InsertDirectoryResponse>, tonic::Status> {
        Ok(tonic::Response::new(InsertDirectoryResponse::default()))
    }

    async fn insert_playlist(
        &self,
        _request: tonic::Request<InsertPlaylistRequest>,
    ) -> Result<tonic::Response<InsertPlaylistResponse>, tonic::Status> {
        Ok(tonic::Response::new(InsertPlaylistResponse::default()))
    }

    async fn shuffle_playlist(
        &self,
        _request: tonic::Request<ShufflePlaylistRequest>,
    ) -> Result<tonic::Response<ShufflePlaylistResponse>, tonic::Status> {
        Ok(tonic::Response::new(ShufflePlaylistResponse::default()))
    }

    async fn warn_on_playlist_erase(
        &self,
        _request: tonic::Request<WarnOnPlaylistEraseRequest>,
    ) -> Result<tonic::Response<WarnOnPlaylistEraseResponse>, tonic::Status> {
        Ok(tonic::Response::new(WarnOnPlaylistEraseResponse::default()))
    }
}
