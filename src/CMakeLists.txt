set(SRC "main.cpp"
        "Side/Side.cpp"
        "Color/Color.cpp"
        "Plane/Plane.cpp"
        "Cube/Cube.cpp"
        "Cube/Rotation_B.cpp"
        "Cube/Rotation_D.cpp"
        "Cube/Rotation_F.cpp"
        "Cube/Rotation_L.cpp"
        "Cube/Rotation_R.cpp"
        "Cube/Rotation_U.cpp"
)

set(LIBS

)

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} ${LIBS})