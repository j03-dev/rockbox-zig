fn main() -> Result<(), Box<dyn std::error::Error>> {
    tonic_build::configure()
        .out_dir("src/api")
        .file_descriptor_set_path("src/api/rockbox_descriptor.bin")
        .compile(
            &[
                "proto/rockbox/v1alpha1/browse.proto",
                "proto/rockbox/v1alpha1/metadata.proto",
                "proto/rockbox/v1alpha1/playback.proto",
                "proto/rockbox/v1alpha1/playlist.proto",
                "proto/rockbox/v1alpha1/settings.proto",
                "proto/rockbox/v1alpha1/sound.proto",
                "proto/rockbox/v1alpha1/tagcache.proto",
            ],
            &["proto"],
        )?;
    Ok(())
}
