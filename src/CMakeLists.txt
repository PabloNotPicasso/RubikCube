set(SRC "main.cpp")

set(LIBS
    # Add libs
)

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} ${LIBS})