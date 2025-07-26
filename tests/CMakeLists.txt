# tests/CMakeLists.txt

# Erstelle ein ausführbares Test-Target namens "tests"
add_executable(tests
        test_main.cpp
        UnitTests.cpp
        UnitTests.h
        ${PROJECT_SOURCE_DIR}/src/Units.cpp)

# Header-Include Verzeichnis
target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR}/include)

# GoogleTest statisch linken
target_link_libraries(tests PRIVATE gtest_main)

# GoogleTest Modul einbinden, um gtest_discover_tests zu nutzen
include(GoogleTest)

# Automatische Test-Discovery aktivieren
gtest_discover_tests(tests)
