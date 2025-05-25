cmake_minimum_required(VERSION 3.10)
project(FinanCell)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

add_executable(FinanCell
  src/main.cpp
   ${SOURCES}
   )

# --- JSON ---
include(FetchContent)
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(json)

target_link_libraries(FinanCell PRIVATE nlohmann_json::nlohmann_json)

# --- TESTS ---
file(GLOB TEST_SOURCES "tests/*.cpp")

add_subdirectory(external/googletest)

enable_testing()

add_executable(Tests
    ${TEST_SOURCES}
    ${SOURCES}
    
)

target_link_libraries(Tests PRIVATE
    gtest
    gtest_main
    pthread
    nlohmann_json::nlohmann_json
)

add_test(NAME AllTests COMMAND Tests)