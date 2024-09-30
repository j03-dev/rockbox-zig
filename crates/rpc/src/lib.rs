pub mod browse;
pub mod library;
pub mod metadata;
pub mod playback;
pub mod playlist;
pub mod server;
pub mod settings;
pub mod sound;
pub mod system;

pub mod api {
    #[path = ""]
    pub mod rockbox {
        use rockbox_sys::types::{
            mp3_entry::Mp3Entry,
            system_status::SystemStatus,
            user_settings::{CompressorSettings, EqBandSetting, ReplaygainSettings, UserSettings},
        };
        use v1alpha1::{
            Album, Artist, CurrentTrackResponse, Entry, GetGlobalSettingsResponse,
            GetGlobalStatusResponse, NextTrackResponse, Track,
        };

        #[path = "rockbox.v1alpha1.rs"]
        pub mod v1alpha1;

        pub(crate) const FILE_DESCRIPTOR_SET: &[u8] = include_bytes!("api/rockbox_descriptor.bin");

        impl From<Mp3Entry> for CurrentTrackResponse {
            fn from(mp3entry: Mp3Entry) -> Self {
                let title = mp3entry.title;
                let artist = mp3entry.artist;
                let album = mp3entry.album;
                let genre = mp3entry.genre_string;
                let disc = mp3entry.disc_string;
                let track_string = mp3entry.track_string;
                let year_string = mp3entry.year_string;
                let composer = mp3entry.composer;
                let album_artist = mp3entry.albumartist;
                let comment = mp3entry.comment;
                let grouping = mp3entry.grouping;
                let discnum = mp3entry.discnum;
                let tracknum = mp3entry.tracknum;
                let layer = mp3entry.layer;
                let year = mp3entry.year;
                let bitrate = mp3entry.bitrate;
                let frequency = mp3entry.frequency;
                let filesize = mp3entry.filesize;
                let length = mp3entry.length;
                let elapsed = mp3entry.elapsed;
                let path = mp3entry.path;

                CurrentTrackResponse {
                    title,
                    artist,
                    album,
                    genre,
                    disc,
                    track_string,
                    year_string,
                    composer,
                    album_artist,
                    comment,
                    grouping,
                    discnum,
                    tracknum,
                    layer,
                    year,
                    bitrate,
                    frequency,
                    filesize,
                    length,
                    elapsed,
                    path,
                }
            }
        }

        impl From<Option<Mp3Entry>> for CurrentTrackResponse {
            fn from(mp3entry: Option<Mp3Entry>) -> Self {
                match mp3entry {
                    Some(mp3entry) => mp3entry.into(),
                    None => CurrentTrackResponse {
                        title: "".to_string(),
                        artist: "".to_string(),
                        album: "".to_string(),
                        genre: "".to_string(),
                        disc: "".to_string(),
                        track_string: "".to_string(),
                        year_string: "".to_string(),
                        composer: "".to_string(),
                        album_artist: "".to_string(),
                        comment: "".to_string(),
                        grouping: "".to_string(),
                        discnum: 0,
                        tracknum: 0,
                        layer: 0,
                        year: 0,
                        bitrate: 0,
                        frequency: 0,
                        filesize: 0,
                        length: 0,
                        elapsed: 0,
                        path: "".to_string(),
                    },
                }
            }
        }

        impl From<Mp3Entry> for NextTrackResponse {
            fn from(mp3entry: Mp3Entry) -> Self {
                let title = mp3entry.title;
                let artist = mp3entry.artist;
                let album = mp3entry.album;
                let genre = mp3entry.genre_string;
                let disc = mp3entry.disc_string;
                let track_string = mp3entry.track_string;
                let year_string = mp3entry.year_string;
                let composer = mp3entry.composer;
                let album_artist = mp3entry.albumartist;
                let comment = mp3entry.comment;
                let grouping = mp3entry.grouping;
                let discnum = mp3entry.discnum;
                let tracknum = mp3entry.tracknum;
                let layer = mp3entry.layer;
                let year = mp3entry.year;
                let bitrate = mp3entry.bitrate;
                let frequency = mp3entry.frequency;
                let filesize = mp3entry.filesize;
                let length = mp3entry.length;
                let elapsed = mp3entry.elapsed;
                let path = mp3entry.path;

                NextTrackResponse {
                    title,
                    artist,
                    album,
                    genre,
                    disc,
                    track_string,
                    year_string,
                    composer,
                    album_artist,
                    comment,
                    grouping,
                    discnum,
                    tracknum,
                    layer,
                    year,
                    bitrate,
                    frequency,
                    filesize,
                    length,
                    elapsed,
                    path,
                }
            }
        }

        impl From<Option<Mp3Entry>> for NextTrackResponse {
            fn from(mp3entry: Option<Mp3Entry>) -> Self {
                match mp3entry {
                    Some(mp3entry) => mp3entry.into(),
                    None => NextTrackResponse {
                        title: "".to_string(),
                        artist: "".to_string(),
                        album: "".to_string(),
                        genre: "".to_string(),
                        disc: "".to_string(),
                        track_string: "".to_string(),
                        year_string: "".to_string(),
                        composer: "".to_string(),
                        album_artist: "".to_string(),
                        comment: "".to_string(),
                        grouping: "".to_string(),
                        discnum: 0,
                        tracknum: 0,
                        layer: 0,
                        year: 0,
                        bitrate: 0,
                        frequency: 0,
                        filesize: 0,
                        length: 0,
                        elapsed: 0,
                        path: "".to_string(),
                    },
                }
            }
        }

        impl From<ReplaygainSettings> for v1alpha1::ReplaygainSettings {
            fn from(settings: ReplaygainSettings) -> Self {
                let noclip = settings.noclip;
                let r#type = settings.r#type;
                let preamp = settings.preamp;

                v1alpha1::ReplaygainSettings {
                    noclip,
                    r#type,
                    preamp,
                }
            }
        }

        impl From<EqBandSetting> for v1alpha1::EqBandSetting {
            fn from(band: EqBandSetting) -> Self {
                let cutoff = band.cutoff;
                let q = band.q;
                let gain = band.gain;

                v1alpha1::EqBandSetting { cutoff, q, gain }
            }
        }

        impl From<CompressorSettings> for v1alpha1::CompressorSettings {
            fn from(settings: CompressorSettings) -> Self {
                let threshold = settings.threshold;
                let makeup_gain = settings.makeup_gain;
                let ratio = settings.ratio;
                let knee = settings.knee;
                let release_time = settings.release_time;
                let attack_time = settings.attack_time;

                v1alpha1::CompressorSettings {
                    threshold,
                    makeup_gain,
                    ratio,
                    knee,
                    release_time,
                    attack_time,
                }
            }
        }

        impl From<UserSettings> for GetGlobalSettingsResponse {
            fn from(settings: UserSettings) -> Self {
                let volume = settings.volume;
                let balance = settings.balance;
                let bass = settings.bass;
                let treble = settings.treble;
                let channel_config = settings.channel_config;
                let stereo_width = settings.stereo_width;
                let bass_cutoff = settings.bass_cutoff;
                let treble_cutoff = settings.treble_cutoff;
                let crossfade = settings.crossfade;
                let crossfade_fade_in_delay = settings.crossfade_fade_in_delay;
                let crossfade_fade_out_delay = settings.crossfade_fade_out_delay;
                let crossfade_fade_in_duration = settings.crossfade_fade_in_duration;
                let crossfade_fade_out_duration = settings.crossfade_fade_out_duration;
                let crossfade_fade_out_mixmode = settings.crossfade_fade_out_mixmode;
                let replaygain_settings =
                    v1alpha1::ReplaygainSettings::from(settings.replaygain_settings);
                let crossfeed = settings.crossfeed;
                let crossfeed_direct_gain = settings.crossfeed_direct_gain;
                let crossfeed_cross_gain = settings.crossfeed_cross_gain;
                let crossfeed_hf_attenuation = settings.crossfeed_hf_attenuation;
                let crossfeed_hf_cutoff = settings.crossfeed_hf_cutoff;
                let eq_enabled = settings.eq_enabled;
                let eq_precut = settings.eq_precut;
                let eq_band_settings = settings
                    .eq_band_settings
                    .into_iter()
                    .map(|band| band.into())
                    .collect();
                let beep = settings.beep;
                let keyclick = settings.keyclick;
                let keyclick_repeats = settings.keyclick_repeats;
                let dithering_enabled = settings.dithering_enabled;
                let timestretch_enabled = settings.timestretch_enabled;
                let list_accel_start_delay = settings.list_accel_start_delay;
                let list_accel_wait = settings.list_accel_wait;
                let touchpad_sensitivity = settings.touchpad_sensitivity;
                let touchpad_deadzone = settings.touchpad_deadzone;
                let pause_rewind = settings.pause_rewind;
                let unplug_mode = settings.unplug_mode;
                let unplug_autoresume = settings.unplug_autoresume;
                let timeformat = settings.timeformat;
                let disk_spindown = settings.disk_spindown;
                let buffer_margin = settings.buffer_margin;
                let dirfilter = settings.dirfilter;
                let show_filename_ext = settings.show_filename_ext;
                let default_codepage = settings.default_codepage;
                let hold_lr_for_scroll_in_list = settings.hold_lr_for_scroll_in_list;
                let play_selected = settings.play_selected;
                let single_mode = settings.single_mode;
                let party_mode = settings.party_mode;
                let car_adapter_mode = settings.car_adapter_mode;
                let car_adapter_mode_delay = settings.car_adapter_mode_delay;
                let start_in_screen = settings.start_in_screen;
                let ff_rewind_min_step = settings.ff_rewind_min_step;
                let ff_rewind_accel = settings.ff_rewind_accel;
                let peak_meter_release = settings.peak_meter_release;
                let peak_meter_hold = settings.peak_meter_hold;
                let peak_meter_clip_hold = settings.peak_meter_clip_hold;
                let peak_meter_dbfs = settings.peak_meter_dbfs;
                let peak_meter_min = settings.peak_meter_min;
                let peak_meter_max = settings.peak_meter_max;
                let wps_file = settings.wps_file;
                let sbs_file = settings.sbs_file;
                let lang_file = settings.lang_file;
                let playlist_catalog_dir = settings.playlist_catalog_dir;
                let skip_length = settings.skip_length;
                let max_files_in_dir = settings.max_files_in_dir;
                let max_files_in_playlist = settings.max_files_in_playlist;
                let volume_type = settings.volume_type;
                let battery_display = settings.battery_display;
                let show_icons = settings.show_icons;
                let statusbar = settings.statusbar;
                let scrollbar = settings.scrollbar;
                let scrollbar_width = settings.scrollbar_width;
                let list_line_padding = settings.list_line_padding;
                let list_separator_color = settings.list_separator_color;
                let browse_current = settings.browse_current;
                let scroll_paginated = settings.scroll_paginated;
                let list_wraparound = settings.list_wraparound;
                let list_order = settings.list_order;
                let scroll_speed = settings.scroll_speed;
                let bidir_limit = settings.bidir_limit;
                let scroll_delay = settings.scroll_delay;
                let scroll_step = settings.scroll_step;
                let autoloadbookmark = settings.autoloadbookmark;
                let autocreatebookmark = settings.autocreatebookmark;
                let autoupdatebookmark = settings.autoupdatebookmark;
                let usemrb = settings.usemrb;
                let dircache = settings.dircache;
                let tagcache_ram = settings.tagcache_ram;
                let tagcache_autoupdate = settings.tagcache_autoupdate;
                let autoresume_enable = settings.autoresume_enable;
                let autoresume_automatic = settings.autoresume_automatic;
                let autoresume_paths = settings.autoresume_paths;
                let runtimedb = settings.runtimedb;
                let tagcache_scan_paths = settings.tagcache_scan_paths;
                let tagcache_db_path = settings.tagcache_db_path;
                let backdrop_file = settings.backdrop_file;
                let bg_color = settings.bg_color;
                let fg_color = settings.fg_color;
                let lss_color = settings.lss_color;
                let lse_color = settings.lse_color;
                let lst_color = settings.lst_color;
                let colors_file = settings.colors_file;
                let browser_default = settings.browser_default;
                let repeat_mode = settings.repeat_mode;
                let next_folder = settings.next_folder;
                let constrain_next_folder = settings.constrain_next_folder;
                let recursive_dir_insert = settings.recursive_dir_insert;
                let fade_on_stop = settings.fade_on_stop;
                let playlist_shuffle = settings.playlist_shuffle;
                let warnon_erase_dynplaylist = settings.warnon_erase_dynplaylist;
                let keep_current_track_on_replace_playlist =
                    settings.keep_current_track_on_replace_playlist;
                let show_shuffled_adding_options = settings.show_shuffled_adding_options;
                let show_queue_options = settings.show_queue_options;
                let album_art = settings.album_art;
                let rewind_across_tracks = settings.rewind_across_tracks;
                let playlist_viewer_icons = settings.playlist_viewer_icons;
                let playlist_viewer_indices = settings.playlist_viewer_indices;
                let playlist_viewer_track_display = settings.playlist_viewer_track_display;
                let sort_case = settings.sort_case;
                let sort_dir = settings.sort_dir;
                let sort_file = settings.sort_file;
                let interpret_numbers = settings.interpret_numbers;
                let poweroff = settings.poweroff;
                let spdif_enable = settings.spdif_enable;
                let contrast = settings.contrast;
                let invert = settings.invert;
                let flip_display = settings.flip_display;
                let cursor_style = settings.cursor_style;
                let screen_scroll_step = settings.screen_scroll_step;
                let show_path_in_browser = settings.show_path_in_browser;
                let offset_out_of_view = settings.offset_out_of_view;
                let disable_mainmenu_scrolling = settings.disable_mainmenu_scrolling;
                let icon_file = settings.icon_file;
                let viewers_icon_file = settings.viewers_icon_file;
                let font_file = settings.font_file;
                let glyphs_to_cache = settings.glyphs_to_cache;
                let kbd_file = settings.kbd_file;
                let backlight_timeout = settings.backlight_timeout;
                let caption_backlight = settings.caption_backlight;
                let bl_filter_first_keypress = settings.bl_filter_first_keypress;
                let backlight_timeout_plugged = settings.backlight_timeout_plugged;
                let bt_selective_softlock_actions = settings.bt_selective_softlock_actions;
                let bt_selective_softlock_actions_mask =
                    settings.bt_selective_softlock_actions_mask;
                let bl_selective_actions = settings.bl_selective_actions;
                let bl_selective_actions_mask = settings.bl_selective_actions_mask;
                let backlight_on_button_hold = settings.backlight_on_button_hold;
                let lcd_sleep_after_backlight_off = settings.lcd_sleep_after_backlight_off;
                let brightness = settings.brightness;
                let speaker_mode = settings.speaker_mode;
                let prevent_skip = settings.prevent_skip;
                let touch_mode = settings.touch_mode;
                let pitch_mode_semitone = settings.pitch_mode_semitone;
                let pitch_mode_timestretch = settings.pitch_mode_timestretch;
                let player_name = settings.player_name;
                let compressor_settings =
                    v1alpha1::CompressorSettings::from(settings.compressor_settings);
                let sleeptimer_duration = settings.sleeptimer_duration;
                let sleeptimer_on_startup = settings.sleeptimer_on_startup;
                let keypress_restarts_sleeptimer = settings.keypress_restarts_sleeptimer;
                let show_shutdown_message = settings.show_shutdown_message;
                let hotkey_wps = settings.hotkey_wps;
                let hotkey_tree = settings.hotkey_tree;
                let resume_rewind = settings.resume_rewind;
                let depth_3d = settings.depth_3d;
                let roll_off = settings.roll_off;
                let power_mode = settings.power_mode;
                let keyclick_hardware = settings.keyclick_hardware;
                let start_directory = settings.start_directory;
                let root_menu_customized = settings.root_menu_customized;
                let shortcuts_replaces_qs = settings.shortcuts_replaces_qs;
                let play_frequency = settings.play_frequency;
                let volume_limit = settings.volume_limit;
                let volume_adjust_mode = settings.volume_adjust_mode;
                let volume_adjust_norm_steps = settings.volume_adjust_norm_steps;
                let surround_enabled = settings.surround_enabled;
                let surround_balance = settings.surround_balance;
                let surround_fx1 = settings.surround_fx1;
                let surround_fx2 = settings.surround_fx2;
                let surround_method2 = settings.surround_method2;
                let surround_mix = settings.surround_mix;
                let pbe = settings.pbe;
                let pbe_precut = settings.pbe_precut;
                let afr_enabled = settings.afr_enabled;
                let governor = settings.governor;
                let stereosw_mode = settings.stereosw_mode;

                GetGlobalSettingsResponse {
                    volume,
                    balance,
                    bass,
                    treble,
                    channel_config,
                    stereo_width,
                    bass_cutoff,
                    treble_cutoff,
                    crossfade,
                    crossfade_fade_in_delay,
                    crossfade_fade_out_delay,
                    crossfade_fade_in_duration,
                    crossfade_fade_out_duration,
                    crossfade_fade_out_mixmode,
                    replaygain_settings: Some(replaygain_settings),
                    crossfeed,
                    crossfeed_direct_gain,
                    crossfeed_cross_gain,
                    crossfeed_hf_attenuation,
                    crossfeed_hf_cutoff,
                    eq_enabled,
                    eq_precut,
                    eq_band_settings,
                    beep,
                    keyclick,
                    keyclick_repeats,
                    dithering_enabled,
                    timestretch_enabled,
                    list_accel_start_delay,
                    list_accel_wait,
                    touchpad_sensitivity,
                    touchpad_deadzone,
                    pause_rewind,
                    unplug_mode,
                    unplug_autoresume,
                    timeformat,
                    disk_spindown,
                    buffer_margin,
                    dirfilter,
                    show_filename_ext,
                    default_codepage,
                    hold_lr_for_scroll_in_list,
                    play_selected,
                    single_mode,
                    party_mode,
                    car_adapter_mode,
                    car_adapter_mode_delay,
                    start_in_screen,
                    ff_rewind_min_step,
                    ff_rewind_accel,
                    peak_meter_release,
                    peak_meter_hold,
                    peak_meter_clip_hold,
                    peak_meter_dbfs,
                    peak_meter_min,
                    peak_meter_max,
                    wps_file,
                    sbs_file,
                    lang_file,
                    playlist_catalog_dir,
                    skip_length,
                    max_files_in_dir,
                    max_files_in_playlist,
                    volume_type,
                    battery_display,
                    show_icons,
                    statusbar,
                    scrollbar,
                    scrollbar_width,
                    list_line_padding,
                    list_separator_color,
                    browse_current,
                    scroll_paginated,
                    list_wraparound,
                    list_order,
                    scroll_speed,
                    bidir_limit,
                    scroll_delay,
                    scroll_step,
                    autoloadbookmark,
                    autocreatebookmark,
                    autoupdatebookmark,
                    usemrb,
                    dircache,
                    tagcache_ram,
                    tagcache_autoupdate,
                    autoresume_enable,
                    autoresume_automatic,
                    autoresume_paths,
                    runtimedb,
                    tagcache_scan_paths,
                    tagcache_db_path,
                    backdrop_file,
                    bg_color,
                    fg_color,
                    lss_color,
                    lse_color,
                    lst_color,
                    colors_file,
                    browser_default,
                    repeat_mode,
                    next_folder,
                    constrain_next_folder,
                    recursive_dir_insert,
                    fade_on_stop,
                    playlist_shuffle,
                    warnon_erase_dynplaylist,
                    keep_current_track_on_replace_playlist,
                    show_shuffled_adding_options,
                    show_queue_options,
                    album_art,
                    rewind_across_tracks,
                    playlist_viewer_icons,
                    playlist_viewer_indices,
                    playlist_viewer_track_display,
                    sort_case,
                    sort_dir,
                    sort_file,
                    interpret_numbers,
                    poweroff,
                    spdif_enable,
                    contrast,
                    invert,
                    flip_display,
                    cursor_style,
                    screen_scroll_step,
                    show_path_in_browser,
                    offset_out_of_view,
                    disable_mainmenu_scrolling,
                    icon_file,
                    viewers_icon_file,
                    font_file,
                    glyphs_to_cache,
                    kbd_file,
                    backlight_timeout,
                    caption_backlight,
                    bl_filter_first_keypress,
                    backlight_timeout_plugged,
                    bt_selective_softlock_actions,
                    bt_selective_softlock_actions_mask,
                    bl_selective_actions,
                    bl_selective_actions_mask,
                    backlight_on_button_hold,
                    lcd_sleep_after_backlight_off,
                    brightness,
                    speaker_mode,
                    prevent_skip,
                    touch_mode,
                    pitch_mode_semitone,
                    pitch_mode_timestretch,
                    player_name,
                    compressor_settings: Some(compressor_settings),
                    sleeptimer_duration,
                    sleeptimer_on_startup,
                    keypress_restarts_sleeptimer,
                    show_shutdown_message,
                    hotkey_wps,
                    hotkey_tree,
                    resume_rewind,
                    depth_3d,
                    roll_off,
                    power_mode,
                    keyclick_hardware,
                    start_directory,
                    root_menu_customized,
                    shortcuts_replaces_qs,
                    play_frequency,
                    volume_limit,
                    volume_adjust_mode,
                    volume_adjust_norm_steps,
                    surround_enabled,
                    surround_balance,
                    surround_fx1,
                    surround_fx2,
                    surround_method2,
                    surround_mix,
                    pbe,
                    pbe_precut,
                    afr_enabled,
                    governor,
                    stereosw_mode,
                }
            }
        }

        impl From<SystemStatus> for GetGlobalStatusResponse {
            fn from(status: SystemStatus) -> Self {
                let resume_index = status.resume_index;
                let resume_crc32 = status.resume_crc32;
                let resume_elapsed = status.resume_elapsed;
                let resume_offset = status.resume_offset;
                let runtime = status.runtime;
                let topruntime = status.topruntime;
                let dircache_size = status.dircache_size;
                let last_screen = status.last_screen as i32;
                let viewer_icon_count = status.viewer_icon_count;
                let last_volume_change = status.last_volume_change;

                GetGlobalStatusResponse {
                    resume_index,
                    resume_crc32,
                    resume_elapsed,
                    resume_offset,
                    runtime,
                    topruntime,
                    dircache_size,
                    last_screen,
                    viewer_icon_count,
                    last_volume_change,
                }
            }
        }

        impl From<rockbox_sys::types::tree::Entry> for Entry {
            fn from(entry: rockbox_sys::types::tree::Entry) -> Self {
                let name = entry.name;
                let attr = entry.attr;
                let time_write = entry.time_write;
                let customaction = entry.customaction;

                Entry {
                    name,
                    attr,
                    time_write,
                    customaction,
                }
            }
        }

        impl From<rockbox_library::entity::artist::Artist> for Artist {
            fn from(artist: rockbox_library::entity::artist::Artist) -> Self {
                Self {
                    id: artist.id,
                    name: artist.name,
                    bio: artist.bio,
                    image: artist.image,
                }
            }
        }

        impl From<rockbox_library::entity::album::Album> for Album {
            fn from(album: rockbox_library::entity::album::Album) -> Self {
                Self {
                    id: album.id,
                    title: album.title,
                    artist: album.artist,
                    year: album.year,
                    year_string: album.year_string,
                    album_art: album.album_art,
                    md5: album.md5,
                }
            }
        }

        impl From<rockbox_library::entity::track::Track> for Track {
            fn from(track: rockbox_library::entity::track::Track) -> Self {
                Self {
                    id: track.id,
                    path: track.path,
                    title: track.title,
                    artist: track.artist,
                    album: track.album,
                    album_artist: track.album_artist,
                    bitrate: track.bitrate,
                    composer: track.composer,
                    disc_number: track.disc_number,
                    filesize: track.filesize,
                    frequency: track.frequency,
                    length: track.length,
                    track_number: track.track_number.unwrap_or_default(),
                    year: track.year.unwrap_or_default(),
                    year_string: track.year_string.unwrap_or_default(),
                    genre: track.genre.unwrap_or_default(),
                    md5: track.md5,
                    album_art: track.album_art,
                    artist_id: Some(track.artist_id),
                    album_id: Some(track.album_id),
                    genre_id: Some(track.genre_id),
                    created_at: track.created_at.to_rfc3339(),
                    updated_at: track.updated_at.to_rfc3339(),
                }
            }
        }
    }
}

pub fn rockbox_url() -> String {
    let port = std::env::var("ROCKBOX_TCP_PORT").unwrap_or_else(|_| "6063".to_string());
    format!("http://127.0.0.1:{}", port)
}
