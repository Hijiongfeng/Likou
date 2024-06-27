cmake_minimum_required(VERSION 3.5)
project(LiKou)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-std=c++14 -O3 -Wall")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

file( GLOB APP_SOURCE src/*.cpp )    # src文件夹内的cpp 文件，不包含子文件夹

foreach(sourcefile IN LISTS APP_SOURCE)

  STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1_src" program ${sourcefile})
  add_executable(${program} ${sourcefile})
  
endforeach(sourcefile)

add_subdirectory(src/LC)         # 子文件夹
