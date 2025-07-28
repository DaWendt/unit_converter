# tests/CMakeLists.txt
add_executable(tests
        test_main.cpp
        UnitTests.cpp
        UnitTests.h
        ${PROJECT_SOURCE_DIR}/src/Units.cpp
        )

# Force debug compilation
target_compile_options(tests PRIVATE -g -O0)
if(APPLE)
    target_compile_options(tests PRIVATE -gdwarf-4)
endif()

target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(tests PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)