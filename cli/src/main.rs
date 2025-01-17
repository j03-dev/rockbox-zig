use std::ffi::OsString;

use anyhow::Error;
use clap::{arg, Command};
use owo_colors::OwoColorize;

use cmd::{community::*, repl::*, run::*, scan::*, start::*, webui::*};

pub mod cmd;

fn cli() -> Command {
    let banner = format!(
        "{}\nA fork of the original Rockbox project, with a focus on modernization and more features.",
        r#"
              __________               __   ___.
    Open      \______   \ ____   ____ |  | _\_ |__   _______  ___
    Source     |       _//  _ \_/ ___\|  |/ /| __ \ /  _ \  \/  /
    Jukebox    |    |   (  <_> )  \___|    < | \_\ (  <_> > <  <
    Firmware   |____|_  /\____/ \___  >__|_ \|___  /\____/__/\_ \
                      \/            \/     \/    \/            \/
    "#
        .yellow()
    );
    const VERSION: &str = match option_env!("TAG") {
        Some(tag) => tag,
        None => env!("CARGO_PKG_VERSION"),
    };
    Command::new("rockbox")
        .version(VERSION)
        .about(&banner)
        .subcommand(
            Command::new("scan")
                .arg(arg!(--directory -d [PATH] "path to your music library").required(false))
                .about("Scan your music library for new media files"),
        )
        .subcommand(
            Command::new("community").about("Join our community on Discord to chat with us!"),
        )
        .subcommand(Command::new("start").about("Start Rockbox server"))
        .subcommand(Command::new("tui").about("Start Rockbox TUI"))
        .subcommand(
            Command::new("webui")
                .about("Open the Rockbox web UI in your browser")
                .visible_alias("web"),
        )
        .subcommand(
            Command::new("repl")
                .about("Start the Rockbox REPL")
                .visible_alias("shell"),
        )
        .subcommand(
            Command::new("run")
                .arg(arg!(<FILE> "JavaScript or TypeScript file to run"))
                .about("Run a JavaScript or TypeScript program")
                .visible_alias("x"),
        )
}

#[tokio::main]
async fn main() -> Result<(), Error> {
    let args = std::env::args().collect::<Vec<String>>();
    if args.len() > 1 && args[1] == "run" {
        let _args = args
            .into_iter()
            .map(|s| match s.as_str() {
                "rockbox" => "deno".into(),
                _ => s.into(),
            })
            .collect::<Vec<OsString>>();

        run(_args);
        return Ok(());
    }

    let matches = cli().get_matches();

    match matches.subcommand() {
        Some(("scan", args)) => {
            let directory = args.get_one::<String>("directory").map(|d| d.to_string());
            scan(directory).await?;
        }
        Some(("community", _)) => {
            community();
        }
        Some(("start", _)) => {
            start(true)?;
        }
        Some(("webui", _)) => {
            webui()?;
        }
        Some(("repl", _)) => {
            repl();
        }
        Some(("tui", _)) => {
            rmpc::main_tui()?;
        }
        _ => {
            start(true)?;
        }
    }
    Ok(())
}
