# tests/CMakeLists.txt

add_executable(tests
        TestHelpers.cpp
        TemperatureTests.cpp
        LengthTests.cpp
        MassTests.cpp
        ErrorTests.cpp
        ${PROJECT_SOURCE_DIR}/src/Units.cpp
        )

# Force debug compilation
target_compile_options(tests PRIVATE -g -O0)
if(APPLE)
    target_compile_options(tests PRIVATE -gdwarf-4)
endif()

target_include_directories(tests PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}      # So tests can find common/TestHelpers.h
        )

target_link_libraries(tests PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)