use crate::{PlaylistInfo, PlaylistTrackInfo};
use std::ffi::{c_int, CString};

pub fn get_current() -> PlaylistInfo {
    unsafe { crate::playlist_get_current() }
}

pub fn get_resume_info(mut resume_index: i32) -> i32 {
    unsafe { crate::playlist_get_resume_info(&mut resume_index as *mut i32 as *mut c_int) }
}

pub fn get_track_info(playlist: PlaylistInfo, index: i32, info: PlaylistTrackInfo) -> i32 {
    unsafe { crate::playlist_get_track_info(playlist, index, info) }
}

pub fn get_first_index(info: *mut PlaylistInfo) -> i32 {
    unsafe { crate::playlist_get_first_index(info) }
}

pub fn get_display_index() -> i32 {
    unsafe { crate::playlist_get_display_index() }
}

pub fn amount() -> i32 {
    unsafe { crate::playlist_amount() }
}

pub fn resume() -> i32 {
    unsafe { crate::playlist_resume() }
}

pub fn resume_track(start_index: i32, crc: u32, elapsed: u64, offset: u64) {
    unsafe { crate::playlist_resume_track(start_index, crc, elapsed, offset) }
}

pub fn set_modified(playlist: *mut PlaylistInfo, modified: bool) {
    unsafe { crate::playlist_set_modified(playlist, modified as u8) }
}

pub fn start(start_index: i32, elapsed: u64, offset: u64) {
    unsafe { crate::playlist_start(start_index, elapsed, offset) }
}

pub fn sync(playlist: *mut PlaylistInfo) {
    unsafe { crate::playlist_sync(playlist) }
}

pub fn remove_all_tracks(playlist: *mut PlaylistInfo) -> i32 {
    unsafe { crate::playlist_remove_all_tracks(playlist) }
}

pub fn create(dir: &str, file: &str) -> i32 {
    let dir = CString::new(dir).unwrap();
    let file = CString::new(file).unwrap();
    unsafe { crate::playlist_create(dir.as_ptr(), file.as_ptr()) }
}

pub fn insert_track(
    playlist: *mut PlaylistInfo,
    filename: &str,
    position: i32,
    queue: bool,
    sync: bool,
) -> i32 {
    let filename = CString::new(filename).unwrap();
    unsafe {
        crate::playlist_insert_track(
            playlist,
            filename.as_ptr(),
            position,
            queue as u8,
            sync as u8,
        )
    }
}

pub fn insert_directory(
    playlist: *mut PlaylistInfo,
    dir: &str,
    position: i32,
    queue: bool,
    recurse: bool,
) -> i32 {
    let dir = CString::new(dir).unwrap();
    unsafe {
        crate::playlist_insert_directory(
            playlist,
            dir.as_ptr(),
            position,
            queue as u8,
            recurse as u8,
        )
    }
}

pub fn insert_playlist(
    playlist: *mut PlaylistInfo,
    filename: &str,
    position: i32,
    queue: bool,
) -> i32 {
    let filename = CString::new(filename).unwrap();
    unsafe { crate::playlist_insert_playlist(playlist, filename.as_ptr(), position, queue as u8) }
}

pub fn shuffle(random_sed: i32, start_index: i32) -> i32 {
    unsafe { crate::playlist_shuffle(random_sed, start_index) }
}

pub fn warn_on_pl_erase() -> bool {
    let ret = unsafe { crate::warn_on_pl_erase() };
    ret != 0
}
