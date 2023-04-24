
add_executable(webcam_demo webcam.cpp)
target_link_libraries(webcam_demo PRIVATE ${OpenCV_LIBS})
if (UNIX)
    target_link_libraries(webcam_demo PRIVATE pthread)
endif()