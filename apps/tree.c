/***************************************************************************
 *             __________               __   ___.
 *   Open      \______   \ ____   ____ |  | _\_ |__   _______  ___
 *   Source     |       _//  _ \_/ ___\|  |/ /| __ \ /  _ \  \/  /
 *   Jukebox    |    |   (  <_> )  \___|    < | \_\ (  <_> > <  <
 *   Firmware   |____|_  /\____/ \___  >__|_ \|___  /\____/__/\_ \
 *                     \/            \/     \/    \/            \/
 * $Id$
 *
 * Copyright (C) 2002 Daniel Stenberg
 *
 * All files in this archive are subject to the GNU General Public License.
 * See the file COPYING in the source tree root for full license agreement.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ****************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "applimits.h"
#include "dir.h"
#include "file.h"
#include "lcd.h"
#include "font.h"
#include "backlight.h"
#include "button.h"
#include "kernel.h"
#include "usb.h"
#include "tree.h"
#include "main_menu.h"
#include "sprintf.h"
#include "audio.h"
#include "playlist.h"
#include "menu.h"
#include "gwps.h"
#include "settings.h"
#include "status.h"
#include "debug.h"
#include "ata.h"
#include "rolo.h"
#include "icons.h"
#include "lang.h"
#include "language.h"
#include "screens.h"
#include "keyboard.h"
#include "bookmark.h"
#include "onplay.h"
#include "buffer.h"
#include "plugin.h"
#include "power.h"
#include "action.h"
#include "talk.h"
#include "filetypes.h"
#include "misc.h"
#include "filetree.h"
#include "tagtree.h"
#ifdef HAVE_RECORDING
#include "recorder/recording.h"
#endif
#include "rtc.h"
#include "dircache.h"
#ifdef HAVE_TAGCACHE
#include "tagcache.h"
#endif
#include "yesno.h"
#include "gwps-common.h"
#include "eeprom_settings.h"
#include "scrobbler.h"

/* gui api */
#include "list.h"
#include "statusbar.h"
#include "splash.h"
#include "buttonbar.h"
#include "textarea.h"
#include "action.h"

#include "root_menu.h"

#if LCD_DEPTH > 1
#include "backdrop.h"
#endif

/* a table for the know file types */
const struct filetype filetypes[] = {
    { "mp3", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "mp2", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "mpa", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
#if CONFIG_CODEC == SWCODEC
    /* Temporary hack to allow playlist creation */
    { "mp1", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "ogg", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "wma", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "wav", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "flac",TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "ac3", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "a52", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "mpc", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "wv",  TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "m4a", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "m4b", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "mp4", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "shn", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "aif", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "aiff",TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "spx" ,TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "sid", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "adx", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "nsf", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "nsfe", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
    { "spc", TREE_ATTR_MPA, Icon_Audio, VOICE_EXT_MPA },
#endif
    { "m3u", TREE_ATTR_M3U, Icon_Playlist, LANG_PLAYLIST },
    { "m3u8", TREE_ATTR_M3U, Icon_Playlist, LANG_PLAYLIST },
    { "cfg", TREE_ATTR_CFG, Icon_Config, VOICE_EXT_CFG },
    { "wps", TREE_ATTR_WPS, Icon_Wps, VOICE_EXT_WPS },
#ifdef HAVE_REMOTE_LCD
    { "rwps", TREE_ATTR_RWPS, Icon_Wps, VOICE_EXT_RWPS },
#endif
#if LCD_DEPTH > 1
    { "bmp", TREE_ATTR_BMP, Icon_Wps, VOICE_EXT_WPS },
#endif
#if CONFIG_TUNER
    { "fmr", TREE_ATTR_FMR, Icon_Preset, LANG_FMR },
#endif
    { "lng", TREE_ATTR_LNG, Icon_Language, LANG_LANGUAGE },
    { "rock",TREE_ATTR_ROCK,Icon_Plugin, VOICE_EXT_ROCK },
#ifdef HAVE_LCD_BITMAP
    { "fnt", TREE_ATTR_FONT,Icon_Font, VOICE_EXT_FONT },
    { "kbd", TREE_ATTR_KBD, Icon_Keyboard, VOICE_EXT_KBD },
#endif
    { "bmark",TREE_ATTR_BMARK, Icon_Bookmark, VOICE_EXT_BMARK },
    { "cue", TREE_ATTR_CUE, Icon_Bookmark, LANG_CUESHEET },
#ifdef BOOTFILE_EXT
    { BOOTFILE_EXT, TREE_ATTR_MOD, Icon_Firmware, VOICE_EXT_AJZ },
#endif /* #ifndef SIMULATOR */
};

struct gui_synclist tree_lists;

/* I put it here because other files doesn't use it yet,
 * but should be elsewhere since it will be used mostly everywhere */
#ifdef HAS_BUTTONBAR
struct gui_buttonbar tree_buttonbar;
#endif
static struct tree_context tc;

bool boot_changed = false;

char lastfile[MAX_PATH];
static char lastdir[MAX_PATH];
#ifdef HAVE_TAGCACHE
static int lasttable, lastextra, lastfirstpos;
#endif
static int max_files = 0;

static bool reload_dir = false;

static bool start_wps = false;
static int curr_context = false;/* id3db or tree*/

static int dirbrowse(void);
static int ft_play_filenumber(int pos, int attr);
static int ft_play_dirname(char* name);
static void ft_play_filename(char *dir, char *file);

/*
 * removes the extension of filename (if it doesn't start with a .)
 * puts the result in buffer
 */
static char * strip_extension(char * filename, char * buffer)
{
    int dotpos;
    char * dot=strrchr(filename, '.');
    if(dot!=0 && filename[0]!='.')
    {
        dotpos = dot-filename;
        strncpy(buffer, filename, dotpos);
        buffer[dotpos]='\0';
        return(buffer);
    }
    else
        return(filename);
}

static char * tree_get_filename(int selected_item, void * data, char *buffer)
{
    struct tree_context * local_tc=(struct tree_context *)data;
    char *name;
    int attr=0;
#ifdef HAVE_TAGCACHE
    bool id3db = *(local_tc->dirfilter) == SHOW_ID3DB;

    if (id3db)
    {
        return tagtree_get_entry(&tc, selected_item)->name;
    }
    else 
#endif
    {
        struct entry* dc = local_tc->dircache;
        struct entry* e = &dc[selected_item];
        name = e->name;
        attr = e->attr;
    }
    /* if any file filter is on, and if it's not a directory,
     * strip the extension */

    if ( (*(local_tc->dirfilter) != SHOW_ID3DB) && !(attr & ATTR_DIRECTORY)
        && (*(local_tc->dirfilter) != SHOW_ALL) )
    {
        return(strip_extension(name, buffer));
    }
    return(name);
}


static void tree_get_fileicon(int selected_item, void * data, ICON * icon)
{
    struct tree_context * local_tc=(struct tree_context *)data;
#ifdef HAVE_TAGCACHE
    bool id3db = *(local_tc->dirfilter) == SHOW_ID3DB;
    if (id3db) {
        *icon = (ICON)tagtree_get_icon(&tc);
    }
    else
#endif
        {
        struct entry* dc = local_tc->dircache;
        struct entry* e = &dc[selected_item];
        *icon = (ICON)filetype_get_icon(e->attr);
    }
}

bool check_rockboxdir(void)
{
    DIR *dir = opendir(ROCKBOX_DIR);
    if(!dir)
    {   /* No need to localise this message.
           If .rockbox is missing, it wouldn't work anyway */
        int i;
        FOR_NB_SCREENS(i)
            screens[i].clear_display();
        gui_syncsplash(HZ*2, "No .rockbox directory");
        FOR_NB_SCREENS(i)
            screens[i].clear_display();
        gui_syncsplash(HZ*2, "Installation incomplete");
        return false;
    }
    closedir(dir);
    return true;
}

void browse_root(void)
{
    gui_sync_wps_screen_init();

    check_rockboxdir();

    strcpy(tc.currdir, "/");

#ifdef HAVE_LCD_CHARCELLS
    int i;
    FOR_NB_SCREENS(i)
        screens[i].double_height(false);
#endif
#ifdef HAS_BUTTONBAR
    gui_buttonbar_init(&tree_buttonbar);
    /* since archos only have one screen, no need to create more than that */
    gui_buttonbar_set_display(&tree_buttonbar, &(screens[SCREEN_MAIN]) );
#endif
    gui_synclist_init(&tree_lists, &tree_get_filename, &tc, false, 1);
    gui_synclist_set_icon_callback(&tree_lists, &tree_get_fileicon);
    /* not the best place for this call... but... */
    root_menu();
}

void tree_get_filetypes(const struct filetype** types, int* count)
{
    *types = filetypes;
    *count = sizeof(filetypes) / sizeof(*filetypes);
}

struct tree_context* tree_get_context(void)
{
    return &tc;
}

/* talkbox hovering delay, to avoid immediate disk activity */
#define HOVER_DELAY (HZ/2)
/*
 * Returns the position of a given file in the current directory
 * returns -1 if not found
 */
static int tree_get_file_position(char * filename)
{
    int i;

    /* use lastfile to determine the selected item (default=0) */
    for (i=0; i < tc.filesindir; i++)
    {
        struct entry* dc = tc.dircache;
        struct entry* e = &dc[i];
        if (!strcasecmp(e->name, filename))
            return(i);
    }
    return(-1);/* no file can match, returns undefined */
}

/*
 * Called when a new dir is loaded (for example when returning from other apps ...)
 * also completely redraws the tree
 */
static int update_dir(void)
{
  bool changed = false;
#ifdef HAVE_TAGCACHE
    bool id3db = *tc.dirfilter == SHOW_ID3DB;
    /* Checks for changes */
    if (id3db) {
        if (tc.currtable != lasttable ||
            tc.currextra != lastextra ||
            tc.firstpos  != lastfirstpos ||
            reload_dir)
        {
            if (tagtree_load(&tc) < 0)
                return -1;

            lasttable = tc.currtable;
            lastextra = tc.currextra;
            lastfirstpos = tc.firstpos;
            changed = true;
        }
    }
    else 
#endif
        {
        /* if the tc.currdir has been changed, reload it ...*/
        if (strncmp(tc.currdir, lastdir, sizeof(lastdir)) || reload_dir) {

            if (ft_load(&tc, NULL) < 0)
                return -1;
            strcpy(lastdir, tc.currdir);
            changed = true;
        }
    }
    /* if selected item is undefined */
    if (tc.selected_item == -1)
    {
        /* use lastfile to determine the selected item */
        tc.selected_item = tree_get_file_position(lastfile);

        /* If the file doesn't exists, select the first one (default) */
        if(tc.selected_item < 0)
            tc.selected_item = 0;
        changed = true;
    }
    if (changed)
    {
        if(
#ifdef HAVE_TAGCACHE
        !id3db && 
#endif
        (tc.dirfull ||
                      tc.filesindir == global_settings.max_files_in_dir) )
        {
            gui_syncsplash(HZ, str(LANG_SHOWDIR_BUFFER_FULL));
        }
    }
#ifdef HAVE_TAGCACHE
    if (id3db) 
    {
        if (global_settings.show_path_in_browser == SHOW_PATH_FULL
            || global_settings.show_path_in_browser == SHOW_PATH_CURRENT)
        {
            gui_synclist_set_title(&tree_lists, tagtree_get_title(&tc),
                filetype_get_icon(ATTR_DIRECTORY));
        }
        else
        {
            /* Must clear the title as the list is reused */
            gui_synclist_set_title(&tree_lists, NULL, NOICON);
        } 
    }
    else
#endif
    {
        if (global_settings.show_path_in_browser == SHOW_PATH_FULL)
        {
            gui_synclist_set_title(&tree_lists, tc.currdir,
                filetype_get_icon(ATTR_DIRECTORY));
        }
        else if (global_settings.show_path_in_browser == SHOW_PATH_CURRENT)
        {
            char *title = strrchr(tc.currdir, '/') + 1;
            if (*title == '\0')
            {
                /* Display "Files" for the root dir */
                gui_synclist_set_title(&tree_lists, str(LANG_DIR_BROWSER),
                    filetype_get_icon(ATTR_DIRECTORY));
            }
            else
                gui_synclist_set_title(&tree_lists, title,
                    filetype_get_icon(ATTR_DIRECTORY));
        }
        else
        {
            /* Must clear the title as the list is reused */
            gui_synclist_set_title(&tree_lists, NULL, NOICON);
        } 
    }
    
    gui_synclist_set_nb_items(&tree_lists, tc.filesindir);
    gui_synclist_set_icon_callback(&tree_lists, tree_get_fileicon);
    if( tc.selected_item >= tc.filesindir)
        tc.selected_item=tc.filesindir-1;

    gui_synclist_select_item(&tree_lists, tc.selected_item);
#ifdef HAS_BUTTONBAR
    if (global_settings.buttonbar) {
        if (*tc.dirfilter < NUM_FILTER_MODES)
            gui_buttonbar_set(&tree_buttonbar, str(LANG_SYSFONT_DIRBROWSE_F1),
                          str(LANG_SYSFONT_DIRBROWSE_F2),
                          str(LANG_SYSFONT_DIRBROWSE_F3));
        else
            gui_buttonbar_set(&tree_buttonbar, "<<<", "", "");
        gui_buttonbar_draw(&tree_buttonbar);
    }
#endif
    gui_synclist_draw(&tree_lists);
    gui_syncstatusbar_draw(&statusbars, true);
    return tc.filesindir;
}

/* load tracks from specified directory to resume play */
void resume_directory(const char *dir)
{
#ifdef HAVE_TAGCACHE
    bool id3db = *tc.dirfilter == SHOW_ID3DB;
#endif

    if (ft_load(&tc, dir) < 0)
        return;
    lastdir[0] = 0;

    ft_build_playlist(&tc, 0);

#ifdef HAVE_TAGCACHE
    if (id3db)
        tagtree_load(&tc);
#endif
}

/* Returns the current working directory and also writes cwd to buf if
   non-NULL.  In case of error, returns NULL. */
char *getcwd(char *buf, int size)
{
    if (!buf)
        return tc.currdir;
    else if (size > 0)
    {
        strncpy(buf, tc.currdir, size);
        return buf;
    }
    else
        return NULL;
}

/* Force a reload of the directory next time directory browser is called */
void reload_directory(void)
{
    reload_dir = true;
}

void get_current_file(char* buffer, int buffer_len)
{
#ifdef HAVE_TAGCACHE
    /* in ID3DB mode it is a bad idea to call this function */
    /* (only happens with `follow playlist') */
    if( *tc.dirfilter == SHOW_ID3DB )
        return;
#endif

    struct entry* dc = tc.dircache;
    struct entry* e = &dc[tc.selected_item];
    snprintf(buffer, buffer_len, "%s/%s", getcwd(NULL,0),
                                          tc.dirlength ? e->name : "");
}

/* Selects a file and update tree context properly */
static void set_current_file(char *path)
{
    char *name;
    int i;

#ifdef HAVE_TAGCACHE
    /* in ID3DB mode it is a bad idea to call this function */
    /* (only happens with `follow playlist') */
    if( *tc.dirfilter == SHOW_ID3DB )
        return;
#endif

    /* separate directory from filename */
    /* gets the directory's name and put it into tc.currdir */
    name = strrchr(path+1,'/');
    if (name)
    {
        *name = 0;
        strcpy(tc.currdir, path);
        *name = '/';
        name++;
    }
    else
    {
        strcpy(tc.currdir, "/");
        name = path+1;
    }

    strcpy(lastfile, name);


    /* If we changed dir we must recalculate the dirlevel
       and adjust the selected history properly */
    if (strncmp(tc.currdir,lastdir,sizeof(lastdir)))
    {
        tc.dirlevel =  0;
        tc.selected_item_history[tc.dirlevel] = -1;

        /* use '/' to calculate dirlevel */
        for (i = 1; path[i] != '\0'; i++)
        {
            if (path[i] == '/')
            {
                tc.dirlevel++;
                tc.selected_item_history[tc.dirlevel] = -1;
            }
        }
    }
    if (ft_load(&tc, NULL) >= 0)
    {
        tc.selected_item = tree_get_file_position(lastfile);
    }
}


/* main loop, handles key events */
static int dirbrowse()
{
    int numentries=0;
    char buf[MAX_PATH];
    int lasti = -1;
    unsigned button, returned_button;
    bool reload_root = false;
    int lastfilter = *tc.dirfilter;
    bool lastsortcase = global_settings.sort_case;
    bool need_update = true;
    bool exit_func = false;
    long thumbnail_time = -1; /* for delaying a thumbnail */
    long last_cancel = 0;

    char* currdir = tc.currdir; /* just a shortcut */
#ifdef HAVE_TAGCACHE
    bool id3db = *tc.dirfilter == SHOW_ID3DB;

    if (id3db)
        curr_context=CONTEXT_ID3DB;
    else
#endif
        curr_context=CONTEXT_TREE;
    if (tc.selected_item < 0)
        tc.selected_item = 0;
#ifdef HAVE_TAGCACHE
    tc.firstpos=0;
    lasttable = -1;
    lastextra = -1;
    lastfirstpos = 0;
#endif

    start_wps = false;
    numentries = update_dir();
    if (numentries == -1)
        return false;  /* currdir is not a directory */

    if (*tc.dirfilter > NUM_FILTER_MODES && numentries==0)
    {
        gui_syncsplash(HZ*2, str(LANG_NO_FILES));
        return false;  /* No files found for rockbox_browser() */
    }
    
    while(1) {
        struct entry *dircache = tc.dircache;
        bool restore = false;
        if (tc.dirlevel < 0)
          tc.dirlevel = 0; /* shouldnt be needed.. this code needs work! */
#ifdef BOOTFILE
        if (boot_changed) {
            char *lines[]={str(LANG_BOOT_CHANGED), str(LANG_REBOOT_NOW)};
            struct text_message message={lines, 2};
            if(gui_syncyesno_run(&message, NULL, NULL)==YESNO_YES)
                rolo_load("/" BOOTFILE);
            restore = true;
            boot_changed = false;
        }
#endif
        button = get_action(CONTEXT_TREE,HZ/5);
        returned_button = gui_synclist_do_button(&tree_lists, button,LIST_WRAP_UNLESS_HELD);
        if (returned_button)
            need_update = true;
        if (returned_button == ACTION_STD_CANCEL)
            button = ACTION_STD_CANCEL;

        tc.selected_item = gui_synclist_get_sel_pos(&tree_lists);
        switch ( button ) {
            case ACTION_STD_OK:
                /* nothing to do if no files to display */
                if ( numentries == 0 )
                    break;

#ifdef HAVE_TAGCACHE
                switch (id3db?tagtree_enter(&tc):ft_enter(&tc))
#else
                switch (ft_enter(&tc))
#endif
                {
                    case 1: reload_dir = true; break;
                    case 2: start_wps = true; break;
                    case 3: exit_func = true; break;
                    default: break;
                }
                restore = true;
                break;

            case ACTION_STD_CANCEL:
                if (*tc.dirfilter > NUM_FILTER_MODES && tc.dirlevel < 1) {
                    exit_func = true;
                    break;
                }
                if ((*tc.dirfilter == SHOW_ID3DB && tc.dirlevel == 0) ||
                    ((*tc.dirfilter != SHOW_ID3DB && !strcmp(currdir,"/"))))
                {
                    if (last_cancel && TIME_BEFORE(current_tick, last_cancel+HZ/2))
                    {
                        last_cancel = 0;
                        action_signalscreenchange(); /* eat the cancel presses */
                        break;
                    }
                    else
                        return GO_TO_ROOT;
                }
                last_cancel = current_tick;
                
#ifdef HAVE_TAGCACHE
                if (id3db)
                    tagtree_exit(&tc);
                else
#endif
                    if (ft_exit(&tc) == 3)
                        exit_func = true;
                
                restore = true;
                break;

            case ACTION_TREE_STOP:
                if (list_stop_handler())
                    restore = true;
                break;

            case ACTION_STD_MENU:
                return GO_TO_ROOT;
                break;

            case ACTION_TREE_WPS:
                return GO_TO_PREVIOUS_MUSIC;
                break;
#ifdef HAVE_QUICKSCREEN
            case ACTION_STD_QUICKSCREEN:
                /* don't enter f2 from plugin browser */
                if (*tc.dirfilter < NUM_FILTER_MODES)
                {
                    if (quick_screen_quick(button))
                        reload_dir = true;
                    restore = true;
                }
                break;
#endif
#ifdef BUTTON_F3
            case ACTION_F3:
                /* don't enter f3 from plugin browser */
                if (*tc.dirfilter < NUM_FILTER_MODES)
                {
                    if (quick_screen_f3(BUTTON_F3))
                        reload_dir = true;
                    restore = true;
                }
                break;
#endif

            case ACTION_STD_CONTEXT:
            {
                int onplay_result;
                int attr = 0;

                if(!numentries)
                    onplay_result = onplay(NULL, 0, curr_context);
                else {
#ifdef HAVE_TAGCACHE
                    if (id3db)
                    {
                        if (tagtree_get_attr(&tc) == TREE_ATTR_MPA)
                        {
                            attr = TREE_ATTR_MPA;
                            tagtree_get_filename(&tc, buf, sizeof(buf));
                        }
                        else
                            attr = ATTR_DIRECTORY;
                    }
                    else
#endif
                    {
                        attr = dircache[tc.selected_item].attr;

                        if (currdir[1]) /* Not in / */
                            snprintf(buf, sizeof buf, "%s/%s",
                                     currdir,
                                     dircache[tc.selected_item].name);
                        else /* In / */
                            snprintf(buf, sizeof buf, "/%s",
                                     dircache[tc.selected_item].name);
                    }
                    onplay_result = onplay(buf, attr, curr_context);
                }
                switch (onplay_result)
                {
                    case ONPLAY_MAINMENU:
                        return GO_TO_ROOT;

                    case ONPLAY_OK:
                        restore = true;
                        break;

                    case ONPLAY_RELOAD_DIR:
                        reload_dir = true;
                        break;

                    case ONPLAY_START_PLAY:
                        return GO_TO_WPS;
                        break;
                }
                break;
            }

            case ACTION_NONE:
                if (thumbnail_time != -1 &&
                    TIME_AFTER(current_tick, thumbnail_time))
                {   /* a delayed hovering thumbnail is due now */
                    int res;
                    int attr;
                    char* name;

#ifdef HAVE_TAGCACHE
                    if (id3db)
                    {
                        attr = tagtree_get_attr(&tc);
                        name = tagtree_get_entry(&tc, lasti)->name;
                    }
                    else
#endif
                    {
                        attr = dircache[lasti].attr;
                        name = dircache[lasti].name;
                    }

                    if (attr & ATTR_DIRECTORY)
                    {
                        DEBUGF("Playing directory thumbnail: %s", currdir);
                        res = ft_play_dirname(name);
                        if (res < 0) /* failed, not existing */
                        {   /* say the number instead, as a fallback */
                            talk_id(VOICE_DIR, false);
                            talk_number(lasti+1, true);
                        }
                    }
                    else
                    {
                        DEBUGF("Playing file thumbnail: %s/%s%s\n",
                               currdir, name,
                               file_thumbnail_ext);
                        /* no fallback necessary, we knew in advance
                           that the file exists */
                        ft_play_filename(currdir, name);
                    }
                    thumbnail_time = -1; /* job done */
                }
                gui_syncstatusbar_draw(&statusbars, false);
                break;

#ifdef HAVE_HOTSWAP
            case SYS_FS_CHANGED:
#ifdef HAVE_TAGCACHE
                if (!id3db)
#endif
                    reload_dir = true;
                /* The 'dir no longer valid' situation will be caught later
                 * by checking the showdir() result. */
                break;
#endif

            default:
                if (default_event_handler(button) == SYS_USB_CONNECTED)
                {
                    if(*tc.dirfilter > NUM_FILTER_MODES)
                        /* leave sub-browsers after usb, doing otherwise
                           might be confusing to the user */
                        exit_func = true;
                    else
                        reload_dir = true;
                }
                break;
        }
        if (start_wps)
            return GO_TO_WPS;
        if ( button )
        {
            ata_spin();
        }


    check_rescan:
        /* do we need to rescan dir? */
        if (reload_dir || reload_root ||
            lastfilter != *tc.dirfilter ||
            lastsortcase != global_settings.sort_case)
        {
            if ( reload_root ) {
                strcpy(currdir, "/");
                tc.dirlevel = 0;
#ifdef HAVE_TAGCACHE
                tc.currtable = 0;
                tc.currextra = 0;
                lasttable = -1;
                lastextra = -1;
#endif
                reload_root = false;
            }

            if (! reload_dir )
            {
                gui_synclist_select_item(&tree_lists, 0);
                gui_synclist_draw(&tree_lists);
                tc.selected_item = 0;
                lastdir[0] = 0;
            }

            lastfilter = *tc.dirfilter;
            lastsortcase = global_settings.sort_case;
            restore = true;
        }

        if (exit_func)
            return GO_TO_PREVIOUS;

        if (restore || reload_dir) {
            /* restore display */
            numentries = update_dir();
            if (currdir[1] && (numentries < 0))
            {   /* not in root and reload failed */
                reload_root = true; /* try root */
                reload_dir = false;
                goto check_rescan;
            }
            need_update = true;
            reload_dir = false;
        }

        if(need_update) {
            need_update=false;
            if ( numentries > 0 ) {
                /* Voice the file if changed */
                if(lasti != tc.selected_item || restore) {
                    int attr;
                    char* name;

                    lasti = tc.selected_item;
                    thumbnail_time = -1; /* Cancel whatever we were
                                            about to say */

#ifdef HAVE_TAGCACHE
                    if (id3db)
                    {
                        attr = tagtree_get_attr(&tc);
                        name = tagtree_get_entry(&tc, tc.selected_item)->name;
                    }
                    else
#endif
                    {
                        attr = dircache[tc.selected_item].attr;
                        name = dircache[tc.selected_item].name;
                    }

                    /* Directory? */
                    if (attr & ATTR_DIRECTORY)
                    {
                        /* play directory thumbnail */
                        switch (global_settings.talk_dir) {
                            case 1: /* dirs as numbers */
                                talk_id(VOICE_DIR, false);
                                talk_number(tc.selected_item+1, true);
                                break;

                            case 2: /* dirs spelled */
                                talk_spell(name, false);
                                break;

                            case 3: /* thumbnail clip */
                                /* "schedule" a thumbnail, to have a little
                                   delay */
                                thumbnail_time = current_tick + HOVER_DELAY;
                                break;

                            default:
                                break;
                        }
                    }
                    else /* file */
                    {
                        switch (global_settings.talk_file) {
                            case 1: /* files as numbers */
                                ft_play_filenumber(
                                    tc.selected_item-tc.dirsindir+1,
                                    attr & TREE_ATTR_MASK);
                                break;

                            case 2: /* files spelled */
                                talk_spell(name, false);
                                break;

                            case 3: /* thumbnail clip */
                                /* "schedule" a thumbnail, to have a little
                                   delay */
                                if (attr & TREE_ATTR_THUMBNAIL)
                                    thumbnail_time = current_tick + HOVER_DELAY;
                                else
                                    /* spell the number as fallback */
                                    talk_spell(name, false);
                                break;

                            default:
                                break;
                        }
                    }
                }
            }
        }
    }
    action_signalscreenchange();
    return true;
}

static int plsize = 0;
static long pltick;
static bool add_dir(char* dirname, int len, int fd)
{
    bool abort = false;
    DIRCACHED* dir;

    /* check for user abort */
    if (action_userabort(TIMEOUT_NOBLOCK))
        return true;

    dir = opendir_cached(dirname);
    if(!dir)
        return true;

    while (true) {
        struct dircache_entry *entry;

        entry = readdir_cached(dir);
        if (!entry)
            break;
        if (entry->attribute & ATTR_DIRECTORY) {
            int dirlen = strlen(dirname);
            bool result;

            if (!strcmp((char *)entry->d_name, ".") ||
                !strcmp((char *)entry->d_name, ".."))
                continue;

            if (dirname[1])
                snprintf(dirname+dirlen, len-dirlen, "/%s", entry->d_name);
            else
                snprintf(dirname, len, "/%s", entry->d_name);

            result = add_dir(dirname, len, fd);
            dirname[dirlen] = '\0';
            if (result) {
                abort = true;
                break;
            }
        }
        else {
            int x = strlen((char *)entry->d_name);
            unsigned int i;
            char *cp = strrchr((char *)entry->d_name,'.');

            if (cp) {
                cp++;

                /* add all supported audio files to playlists */
                for (i=0; i < sizeof(filetypes)/sizeof(struct filetype); i++) {
                    if (filetypes[i].tree_attr == TREE_ATTR_MPA) {
                        if (!strcasecmp(cp, filetypes[i].extension)) {
                            char buf[8];
                            int i;
                            write(fd, dirname, strlen(dirname));
                            write(fd, "/", 1);
                            write(fd, entry->d_name, x);
                            write(fd, "\n", 1);

                            plsize++;
                            if(TIME_AFTER(current_tick, pltick+HZ/4)) {
                                pltick = current_tick;

                                snprintf(buf, sizeof buf, "%d", plsize);
#ifdef HAVE_LCD_BITMAP
                                FOR_NB_SCREENS(i)
                                {
                                    screens[i].puts(0, 4, (unsigned char *)buf);
                                    gui_textarea_update(&screens[i]);
                                }
#else
                                x = 10;
                                if (plsize > 999)
                                    x=7;
                                else {
                                    if (plsize > 99)
                                        x=8;
                                    else {
                                        if (plsize > 9)
                                            x=9;
                                    }
                                }
                                FOR_NB_SCREENS(i) {
                                    screens[i].puts(x,0,buf);
                                }
#endif
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
    closedir_cached(dir);

    return abort;
}

bool create_playlist(void)
{
    int fd;
    int i;
    char filename[MAX_PATH];

    pltick = current_tick;

    snprintf(filename, sizeof filename, "%s.m3u8",
             tc.currdir[1] ? tc.currdir : "/root");
    FOR_NB_SCREENS(i)
    {
        gui_textarea_clear(&screens[i]);
        screens[i].puts(0, 0, str(LANG_CREATING));
        screens[i].puts_scroll(0, 1, (unsigned char *)filename);
#if defined(HAVE_LCD_BITMAP) || defined(SIMULATOR)
        gui_textarea_update(&screens[i]);
#endif
    }
    fd = creat(filename);
    if (fd < 0)
        return false;

    trigger_cpu_boost();

    snprintf(filename, sizeof(filename), "%s",
             tc.currdir[1] ? tc.currdir : "/");
    plsize = 0;
    add_dir(filename, sizeof(filename), fd);
    close(fd);

    sleep(HZ);

    return true;
}

int rockbox_browse(const char *root, int dirfilter)
{
    int ret_val = 0;
    int *last_filter = tc.dirfilter;
    tc.dirfilter = &dirfilter;
    
    reload_dir = true;
    if (dirfilter >= NUM_FILTER_MODES)
    {
        static struct tree_context backup;
        int last_context;
        
        backup = tc;
        tc.selected_item = 0;
        tc.dirlevel = 0;
        memcpy(tc.currdir, root, sizeof(tc.currdir));
        start_wps = false;
        last_context = curr_context;
        
        ret_val = dirbrowse();
        tc = backup;
        curr_context = last_context;
    }
    else
    {
        static char buf[MAX_PATH];
        if (dirfilter != SHOW_ID3DB)
            tc.dirfilter = &global_settings.dirfilter;
        strcpy(buf,root);
        set_current_file(buf);
        ret_val = dirbrowse();
    }
    tc.dirfilter = last_filter;
    return ret_val;
}

void tree_init(void)
{
    /* We copy the settings value in case it is changed by the user. We can't
       use it until the next reboot. */
    max_files = global_settings.max_files_in_dir;

    /* initialize tree context struct */
    memset(&tc, 0, sizeof(tc));
    tc.dirfilter = &global_settings.dirfilter;

    tc.name_buffer_size = AVERAGE_FILENAME_LENGTH * max_files;
    tc.name_buffer = buffer_alloc(tc.name_buffer_size);

    tc.dircache_size = max_files * sizeof(struct entry);
    tc.dircache = buffer_alloc(tc.dircache_size);
}

void bookmark_play(char *resume_file, int index, int offset, int seed,
                   char *filename)
{
    int i;
    char* suffix = strrchr(resume_file, '.');

    if (suffix != NULL &&
        (!strcasecmp(suffix, ".m3u") || !strcasecmp(suffix, ".m3u8")))
    {
        /* Playlist playback */
        char* slash;
        /* check that the file exists */
        int fd = open(resume_file, O_RDONLY);
        if(fd<0)
            return;
        close(fd);

        slash = strrchr(resume_file,'/');
        if (slash)
        {
            char* cp;
            *slash=0;

            cp=resume_file;
            if (!cp[0])
                cp="/";

            if (playlist_create(cp, slash+1) != -1)
            {
                if (global_settings.playlist_shuffle)
                    playlist_shuffle(seed, -1);
                playlist_start(index,offset);
            }
            *slash='/';
        }
    }
    else
    {
        /* Directory playback */
        lastdir[0]='\0';
        if (playlist_create(resume_file, NULL) != -1)
        {
            char* peek_filename;
            resume_directory(resume_file);
            if (global_settings.playlist_shuffle)
                playlist_shuffle(seed, -1);

            /* Check if the file is at the same spot in the directory,
               else search for it */
            peek_filename = playlist_peek(index);
            
            if (peek_filename == NULL)
                return;
                
            if (strcmp(strrchr(peek_filename, '/') + 1, filename))
            {
                for ( i=0; i < playlist_amount(); i++ )
                {
                    peek_filename = playlist_peek(i);

                    if (peek_filename == NULL)
                        return;

                    if (!strcmp(strrchr(peek_filename, '/') + 1, filename))
                        break;
                }
                if (i < playlist_amount())
                    index = i;
                else
                    return;
            }
            playlist_start(index,offset);
        }
    }

    start_wps=true;
}

static int ft_play_filenumber(int pos, int attr)
{
    /* try to find a voice ID for the extension, if known */
    unsigned int j;
    int ext_id = -1; /* default to none */
    for (j=0; j<sizeof(filetypes)/sizeof(*filetypes); j++)
    {
        if (attr == filetypes[j].tree_attr)
        {
            ext_id = filetypes[j].voiceclip;
            break;
        }
    }

    talk_id(VOICE_FILE, false);
    talk_number(pos, true);
    talk_id(ext_id, true);
    return 1;
}

static int ft_play_dirname(char* name)
{
    int fd;
    char dirname_mp3_filename[MAX_PATH+1];

#if CONFIG_CODEC != SWCODEC
    if (audio_status() & AUDIO_STATUS_PLAY)
        return 0;
#endif

    snprintf(dirname_mp3_filename, sizeof(dirname_mp3_filename), "%s/%s/%s",
             tc.currdir[1] ? tc.currdir : "" , name, 
             dir_thumbnail_name);

    DEBUGF("Checking for %s\n", dirname_mp3_filename);

    fd = open(dirname_mp3_filename, O_RDONLY);
    if (fd < 0)
    {
        DEBUGF("Failed to find: %s\n", dirname_mp3_filename);
        return -1;
    }

    close(fd);

    DEBUGF("Found: %s\n", dirname_mp3_filename);

    talk_file(dirname_mp3_filename, false);
    return 1;
}

static void ft_play_filename(char *dir, char *file)
{
    char name_mp3_filename[MAX_PATH+1];

#if CONFIG_CODEC != SWCODEC
    if (audio_status() & AUDIO_STATUS_PLAY)
        return;
#endif

    if (strcasecmp(&file[strlen(file) - strlen(file_thumbnail_ext)],
                    file_thumbnail_ext))
    {   /* file has no .talk extension */
        snprintf(name_mp3_filename, sizeof(name_mp3_filename),
                 "%s/%s%s", dir, file, file_thumbnail_ext);

        talk_file(name_mp3_filename, false);
    }
    else
    {   /* it already is a .talk file, play this directly */
        snprintf(name_mp3_filename, sizeof(name_mp3_filename),
            "%s/%s", dir, file);
        talk_id(LANG_VOICE_DIR_HOVER, false); /* prefix it */
        talk_file(name_mp3_filename, true);
    }
}

/* These two functions are called by the USB and shutdown handlers */
void tree_flush(void)
{
    scrobbler_shutdown();
#ifdef HAVE_TAGCACHE
    tagcache_shutdown();
#endif
    playlist_shutdown();

#ifdef HAVE_TC_RAMCACHE
    tagcache_unload_ramcache();
#endif

#ifdef HAVE_DIRCACHE
    {
        int old_val = global_status.dircache_size;
        if (global_settings.dircache)
        {
            global_status.dircache_size = dircache_get_cache_size();
# ifdef HAVE_EEPROM_SETTINGS
            if (firmware_settings.initialized)
                dircache_save();
# endif
            dircache_disable();
        }
        else
        {
            global_status.dircache_size = 0;
        }
        if (old_val != global_status.dircache_size)
            status_save();
    }
#endif
}

void tree_restore(void)
{
#ifdef HAVE_EEPROM_SETTINGS
    firmware_settings.disk_clean = false;
#endif
    
#ifdef HAVE_TC_RAMCACHE
    remove(TAGCACHE_STATEFILE);
#endif
    
#ifdef HAVE_DIRCACHE
    remove(DIRCACHE_FILE);
    if (global_settings.dircache)
    {
        /* Print "Scanning disk..." to the display. */
        int i;
        FOR_NB_SCREENS(i)
        {
            screens[i].putsxy((LCD_WIDTH/2) -
                              ((strlen(str(LANG_DIRCACHE_BUILDING)) *
                                screens[i].char_width)/2),
                              LCD_HEIGHT-screens[i].char_height*3,
                              str(LANG_DIRCACHE_BUILDING));
            gui_textarea_update(&screens[i]);
        }

        dircache_build(global_status.dircache_size);

        /* Clean the text when we are done. */
        FOR_NB_SCREENS(i)
        {
            gui_textarea_clear(&screens[i]);
        }
    }
#endif
#ifdef HAVE_TAGCACHE
    tagcache_start_scan();
#endif
    scrobbler_init();
}
