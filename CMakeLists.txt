cmake_minimum_required(VERSION 3.14)

project(NoSQLDatabase VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(nosql ${SOURCES})

include(FetchContent)

FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(json)

target_link_libraries(nosql PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(nosql PRIVATE ${CMAKE_SOURCE_DIR}/include)
