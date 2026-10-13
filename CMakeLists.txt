cmake_minimum_required(VERSION 3.16)

project(TestPaperVariantGenerator LANGUAGES CXX)

add_executable(TestPaperVariantGenerator
    src/main.cpp
)

target_compile_features(TestPaperVariantGenerator PRIVATE cxx_std_17)