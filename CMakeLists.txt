cmake_minimum_required(VERSION 3.5)

include(GNUInstallDirs)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

# put Project Name
project(projectName)

include(CMakeModules)

include_directories(src)
add_subdirectory(src)