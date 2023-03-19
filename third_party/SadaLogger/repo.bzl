load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def download_SadaLogger():
    http_archive(
        name = "SadaLogger",
        url = "https://github.com/Sadaananth/SadaLogger/releases/download/v0.0.1/Linux_SadaLogger_x86-64_0.0.1.zip",
    )
