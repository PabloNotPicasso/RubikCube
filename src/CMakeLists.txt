include(GNUInstallDirs)

set( SRC
    "src/Side.cpp"
    "src/Color.cpp"
    "src/Plane.cpp"
    "src/Cube.cpp"
    "src/Rotation_B.cpp"
    "src/Rotation_D.cpp"
    "src/Rotation_F.cpp"
    "src/Rotation_L.cpp"
    "src/Rotation_R.cpp"
    "src/Rotation_U.cpp"
)
set( HEADERS
    "include/Color.hpp"
    "include/Cube.hpp"
    "include/Plane.hpp"
    "include/Side.hpp"
    "include/Helper.hpp"
    "include/RubikApi.hpp"
)

add_library(${PROJECT_NAME} SHARED ${SRC})

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    PUBLIC_HEADER "include/RubikApi.hpp")

install(FILES ${HEADERS}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

##################################
add_executable(mainTest "main.cpp")
target_link_libraries(mainTest ${PROJECT_NAME})