find_package(GTest REQUIRED)

macro(add_gtest_test testName files libraries)
    add_executable(${testName} ${files})
    target_link_libraries(
        ${testName} ${libraries} ${GTEST_LIBRARIES}
    )
    add_test(NAME ${testName} COMMAND ${testName})
endmacro()
