# tests/CMakeLists.txt

# Erstelle ein ausführbares Test-Target namens "tests"
add_executable(tests
        test_main.cpp
        # Falls weitere Testquellen vorhanden sind, hier hinzufügen
        )

# Header-Include Verzeichnis
target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR}/include)

# GoogleTest statisch linken
target_link_libraries(tests PRIVATE gtest_main)

# GoogleTest Modul einbinden, um gtest_discover_tests zu nutzen
include(GoogleTest)

# Automatische Test-Discovery aktivieren
gtest_discover_tests(tests)
