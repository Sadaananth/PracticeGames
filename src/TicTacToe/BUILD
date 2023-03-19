load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "SampleGame",
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
        "//src/TicTacToe/resources:GameAssets",
    ],
    deps = [
        "@SadaLogger",
    ]
)
