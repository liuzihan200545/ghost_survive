cmake_minimum_required(VERSION 3.28)
project(hello)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

find_package(SDL3 REQUIRED)
find_package(SDL3_mixer REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_ttf REQUIRED)
find_package(glm REQUIRED)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE ALL_FILES
        CONFIGURE_DEPENDS
        "src/*.cpp"
        "src/*.h"
        "src/*.hpp"
)

# 2. 检查是否找到了文件（防止路径写错）
if(NOT ALL_FILES)
    message(FATAL_ERROR "未能在 src 目录下找到任何源码文件！")
endif()

# 3. 创建可执行文件
add_executable(hello ${ALL_FILES})

target_link_libraries(hello PRIVATE
        SDL3::SDL3
        SDL3_mixer::SDL3_mixer
        SDL3_ttf::SDL3_ttf
        SDL3_image::SDL3_image
        glm::glm)

target_compile_definitions(hello PRIVATE
        $<$<CONFIG:Debug>:MY_DEBUG>
)