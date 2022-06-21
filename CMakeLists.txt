cmake_minimum_required(VERSION 3.5)

include(GNUInstallDirs)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

project(rubiklib VERSION 1.0.1 DESCRIPTION "rubik solver lib")

include(AddGoogleTest)
include(CodeFormatting)
include(Macro)
include(SetUp)

include_directories(src/include)
add_subdirectory(src)