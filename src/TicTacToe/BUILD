load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "Game",
    srcs = [
        "main.cpp",
        "TicTacToe.cpp",
        "TicTacToe.hpp",
    ],
    linkopts = [
        "-lsfml-graphics",
        "-lsfml-window",
        "-lsfml-system",
    ],
    data = [
        "//resources:CommonAssets",
    ],
    deps = [
        "@SadaLogger",
    ]
)
