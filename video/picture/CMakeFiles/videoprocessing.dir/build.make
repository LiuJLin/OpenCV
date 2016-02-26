# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ljl/ljl_OpenCV/video/picture

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ljl/ljl_OpenCV/video/picture

# Include any dependencies generated for this target.
include CMakeFiles/videoprocessing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/videoprocessing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/videoprocessing.dir/flags.make

CMakeFiles/videoprocessing.dir/videoprocessing.cpp.o: CMakeFiles/videoprocessing.dir/flags.make
CMakeFiles/videoprocessing.dir/videoprocessing.cpp.o: videoprocessing.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ljl/ljl_OpenCV/video/picture/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/videoprocessing.dir/videoprocessing.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/videoprocessing.dir/videoprocessing.cpp.o -c /home/ljl/ljl_OpenCV/video/picture/videoprocessing.cpp

CMakeFiles/videoprocessing.dir/videoprocessing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/videoprocessing.dir/videoprocessing.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ljl/ljl_OpenCV/video/picture/videoprocessing.cpp > CMakeFiles/videoprocessing.dir/videoprocessing.cpp.i

CMakeFiles/videoprocessing.dir/videoprocessing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/videoprocessing.dir/videoprocessing.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ljl/ljl_OpenCV/video/picture/videoprocessing.cpp -o CMakeFiles/videoprocessing.dir/videoprocessing.cpp.s

CMakeFiles/videoprocessing.dir/videoprocessing.cpp.o.requires:
.PHONY : CMakeFiles/videoprocessing.dir/videoprocessing.cpp.o.requires

CMakeFiles/videoprocessing.dir/videoprocessing.cpp.o.provides: CMakeFiles/videoprocessing.dir/videoprocessing.cpp.o.requires
	$(MAKE) -f CMakeFiles/videoprocessing.dir/build.make CMakeFiles/videoprocessing.dir/videoprocessing.cpp.o.provides.build
.PHONY : CMakeFiles/videoprocessing.dir/videoprocessing.cpp.o.provides

CMakeFiles/videoprocessing.dir/videoprocessing.cpp.o.provides.build: CMakeFiles/videoprocessing.dir/videoprocessing.cpp.o

# Object files for target videoprocessing
videoprocessing_OBJECTS = \
"CMakeFiles/videoprocessing.dir/videoprocessing.cpp.o"

# External object files for target videoprocessing
videoprocessing_EXTERNAL_OBJECTS =

videoprocessing: CMakeFiles/videoprocessing.dir/videoprocessing.cpp.o
videoprocessing: CMakeFiles/videoprocessing.dir/build.make
videoprocessing: /usr/local/lib/libopencv_videostab.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_video.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_ts.a
videoprocessing: /usr/local/lib/libopencv_superres.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_stitching.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_photo.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_ocl.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_objdetect.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_nonfree.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_ml.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_legacy.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_imgproc.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_highgui.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_gpu.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_flann.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_features2d.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_core.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_contrib.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_calib3d.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_nonfree.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_ocl.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_gpu.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_photo.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_objdetect.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_legacy.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_video.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_ml.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_calib3d.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_features2d.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_highgui.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_imgproc.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_flann.so.2.4.11
videoprocessing: /usr/local/lib/libopencv_core.so.2.4.11
videoprocessing: CMakeFiles/videoprocessing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable videoprocessing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/videoprocessing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/videoprocessing.dir/build: videoprocessing
.PHONY : CMakeFiles/videoprocessing.dir/build

CMakeFiles/videoprocessing.dir/requires: CMakeFiles/videoprocessing.dir/videoprocessing.cpp.o.requires
.PHONY : CMakeFiles/videoprocessing.dir/requires

CMakeFiles/videoprocessing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/videoprocessing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/videoprocessing.dir/clean

CMakeFiles/videoprocessing.dir/depend:
	cd /home/ljl/ljl_OpenCV/video/picture && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ljl/ljl_OpenCV/video/picture /home/ljl/ljl_OpenCV/video/picture /home/ljl/ljl_OpenCV/video/picture /home/ljl/ljl_OpenCV/video/picture /home/ljl/ljl_OpenCV/video/picture/CMakeFiles/videoprocessing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/videoprocessing.dir/depend

