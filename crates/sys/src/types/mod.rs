use serde::{Deserialize, Serialize};

pub mod audio_status;
pub mod file_position;
pub mod mp3_entry;
pub mod playlist_info;
pub mod system_status;
pub mod user_settings;

#[derive(Serialize, Deserialize)]
pub struct RockboxVersion {
    pub version: String,
}
