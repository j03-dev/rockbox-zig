use anyhow::Error;
use rockbox_library::repo;

use crate::http::{Context, Request, Response};

pub async fn get_albums(ctx: &Context, _req: &Request, res: &mut Response) -> Result<(), Error> {
    let albums = repo::album::all(ctx.pool.clone()).await?;
    res.json(&albums);
    Ok(())
}

pub async fn get_album(ctx: &Context, req: &Request, res: &mut Response) -> Result<(), Error> {
    let album = repo::album::find(ctx.pool.clone(), &req.params[0]).await?;
    res.json(&album);
    Ok(())
}

pub async fn get_album_tracks(
    _ctx: &Context,
    _req: &Request,
    _res: &mut Response,
) -> Result<(), Error> {
    todo!("to be implemented");
}
