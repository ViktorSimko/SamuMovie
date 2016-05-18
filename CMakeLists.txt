project(SamuMovie)

cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

add_definitions(-DGAMEOFLIFE)
add_definitions(-DQ_LOOKUP_TABLE)

set(CMAKE_AUTOMOC ON)
set(Qt5_DIR "/home/chris/Qt/5.5/gcc_64/lib/cmake/Qt5")

find_package(Qt5 REQUIRED COMPONENTS
    Core
    Widgets
)

find_package(OpenMP REQUIRED)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -g ${OpenMP_CXX_FLAGS}")

set(SamuMovie_SRCS main.cpp SamuLife.cpp GameOfLife.cpp SVideoConverter.cpp Recorder.cpp)

add_executable(SamuMovie ${SamuMovie_SRCS})

target_link_libraries(SamuMovie Qt5::Core Qt5::Widgets ${OpenCV_LIBS})
