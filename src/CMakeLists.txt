set(SRC "main.cpp"
        "Side/Side.cpp"
        "Color/Color.cpp"
        "Plane/Plane.cpp"
        "Cube/Cube.cpp"
)

set(LIBS

)

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} ${LIBS})