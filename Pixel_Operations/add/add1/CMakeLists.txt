cmake_minimum_required(VERSION 2.8)
project( add )
find_package( OpenCV REQUIRED )
add_executable( add add.cpp )
target_link_libraries( add ${OpenCV_LIBS} )
