
add_executable(webcam_demo webcam.cpp)
target_link_libraries(webcam_demo PRIVATE opencv::opencv)
if (UNIX)
    target_link_libraries(webcam_demo PRIVATE pthread)
endif()