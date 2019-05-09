cmake_minimum_required(VERSION 2.8.3)

project(simpleOpenCV_VideoStream)
set (CMAKE_CXX_STANDARD 11)

set(SOURCES
    src/main.cpp
)

set(HEADERS
  include/
)

# Find dependencies
find_package( OpenCV REQUIRED )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS})
