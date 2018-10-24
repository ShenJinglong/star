project(src)

message(STATUS "Configuring sub_project: src")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    /usr/local/include
    ${CURRENT_PROJET_DIR}/inc
)

add_executable(star
    star.cpp
    angleSolver.cpp
    getCube.cpp
    serial_mul.cpp
    setCamera.cpp
    vision_mul.cpp
)

target_include_directories(star
  PUBLIC
  ${OpenCV_INCLUDE_DIRS}
  ${CURRENT_PROJET_DIR}/inc
)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

target_link_libraries(star
    ${OpenCV_LIBRARIES}
)