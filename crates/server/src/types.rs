use serde::{Deserialize, Serialize};

#[derive(Debug, Serialize, Deserialize)]
pub struct NewPlaylist {
    pub name: String,
    pub tracks: Vec<String>,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct InsertTracks {
    pub position: i32,
    pub tracks: Vec<String>,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct DeleteTracks {
    pub positions: Vec<i32>,
}
