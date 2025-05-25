cmake_minimum_required(VERSION 3.10)
project(FinanCell)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(FinanCell ${SOURCES})

include(FetchContent)
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(json)

target_link_libraries(FinanCell PRIVATE nlohmann_json::nlohmann_json)