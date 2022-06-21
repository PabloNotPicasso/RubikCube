include(GNUInstallDirs)

set( SRC
    "src/Color.cpp"
    "src/Cube.cpp"
    "src/Plane.cpp"
    "src/Rotation_B.cpp"
    "src/Rotation_D.cpp"
    "src/Rotation_F.cpp"
    "src/Rotation_L.cpp"
    "src/Rotation_R.cpp"
    "src/Rotation_U.cpp"
    "src/Side.cpp"
)
set( HEADERS
    "include/Rubik/Color.hpp"
    "include/Rubik/Cube.hpp"
    "include/Rubik/Plane.hpp"
    "include/Rubik/Side.hpp"
    "include/Rubik/Helper.hpp"
    "include/Rubik/RubikApi.hpp"
)

add_library(${PROJECT_NAME} SHARED ${SRC})

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    PUBLIC_HEADER "include/Rubik/RubikApi.hpp")

install(FILES ${HEADERS}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

##################################
add_executable(mainTest "main.cpp")
target_link_libraries(mainTest ${PROJECT_NAME})