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
CMAKE_SOURCE_DIR = /home/ljl/ljl_OpenCV/Pixel_Operations/sharpen/sharpen3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ljl/ljl_OpenCV/Pixel_Operations/sharpen/sharpen3

# Include any dependencies generated for this target.
include CMakeFiles/sharpen3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sharpen3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sharpen3.dir/flags.make

CMakeFiles/sharpen3.dir/sharpen3.cpp.o: CMakeFiles/sharpen3.dir/flags.make
CMakeFiles/sharpen3.dir/sharpen3.cpp.o: sharpen3.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ljl/ljl_OpenCV/Pixel_Operations/sharpen/sharpen3/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/sharpen3.dir/sharpen3.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/sharpen3.dir/sharpen3.cpp.o -c /home/ljl/ljl_OpenCV/Pixel_Operations/sharpen/sharpen3/sharpen3.cpp

CMakeFiles/sharpen3.dir/sharpen3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sharpen3.dir/sharpen3.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ljl/ljl_OpenCV/Pixel_Operations/sharpen/sharpen3/sharpen3.cpp > CMakeFiles/sharpen3.dir/sharpen3.cpp.i

CMakeFiles/sharpen3.dir/sharpen3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sharpen3.dir/sharpen3.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ljl/ljl_OpenCV/Pixel_Operations/sharpen/sharpen3/sharpen3.cpp -o CMakeFiles/sharpen3.dir/sharpen3.cpp.s

CMakeFiles/sharpen3.dir/sharpen3.cpp.o.requires:
.PHONY : CMakeFiles/sharpen3.dir/sharpen3.cpp.o.requires

CMakeFiles/sharpen3.dir/sharpen3.cpp.o.provides: CMakeFiles/sharpen3.dir/sharpen3.cpp.o.requires
	$(MAKE) -f CMakeFiles/sharpen3.dir/build.make CMakeFiles/sharpen3.dir/sharpen3.cpp.o.provides.build
.PHONY : CMakeFiles/sharpen3.dir/sharpen3.cpp.o.provides

CMakeFiles/sharpen3.dir/sharpen3.cpp.o.provides.build: CMakeFiles/sharpen3.dir/sharpen3.cpp.o

# Object files for target sharpen3
sharpen3_OBJECTS = \
"CMakeFiles/sharpen3.dir/sharpen3.cpp.o"

# External object files for target sharpen3
sharpen3_EXTERNAL_OBJECTS =

sharpen3: CMakeFiles/sharpen3.dir/sharpen3.cpp.o
sharpen3: CMakeFiles/sharpen3.dir/build.make
sharpen3: /usr/local/lib/libopencv_videostab.so.2.4.11
sharpen3: /usr/local/lib/libopencv_video.so.2.4.11
sharpen3: /usr/local/lib/libopencv_ts.a
sharpen3: /usr/local/lib/libopencv_superres.so.2.4.11
sharpen3: /usr/local/lib/libopencv_stitching.so.2.4.11
sharpen3: /usr/local/lib/libopencv_photo.so.2.4.11
sharpen3: /usr/local/lib/libopencv_ocl.so.2.4.11
sharpen3: /usr/local/lib/libopencv_objdetect.so.2.4.11
sharpen3: /usr/local/lib/libopencv_nonfree.so.2.4.11
sharpen3: /usr/local/lib/libopencv_ml.so.2.4.11
sharpen3: /usr/local/lib/libopencv_legacy.so.2.4.11
sharpen3: /usr/local/lib/libopencv_imgproc.so.2.4.11
sharpen3: /usr/local/lib/libopencv_highgui.so.2.4.11
sharpen3: /usr/local/lib/libopencv_gpu.so.2.4.11
sharpen3: /usr/local/lib/libopencv_flann.so.2.4.11
sharpen3: /usr/local/lib/libopencv_features2d.so.2.4.11
sharpen3: /usr/local/lib/libopencv_core.so.2.4.11
sharpen3: /usr/local/lib/libopencv_contrib.so.2.4.11
sharpen3: /usr/local/lib/libopencv_calib3d.so.2.4.11
sharpen3: /usr/local/lib/libopencv_nonfree.so.2.4.11
sharpen3: /usr/local/lib/libopencv_ocl.so.2.4.11
sharpen3: /usr/local/lib/libopencv_gpu.so.2.4.11
sharpen3: /usr/local/lib/libopencv_photo.so.2.4.11
sharpen3: /usr/local/lib/libopencv_objdetect.so.2.4.11
sharpen3: /usr/local/lib/libopencv_legacy.so.2.4.11
sharpen3: /usr/local/lib/libopencv_video.so.2.4.11
sharpen3: /usr/local/lib/libopencv_ml.so.2.4.11
sharpen3: /usr/local/lib/libopencv_calib3d.so.2.4.11
sharpen3: /usr/local/lib/libopencv_features2d.so.2.4.11
sharpen3: /usr/local/lib/libopencv_highgui.so.2.4.11
sharpen3: /usr/local/lib/libopencv_imgproc.so.2.4.11
sharpen3: /usr/local/lib/libopencv_flann.so.2.4.11
sharpen3: /usr/local/lib/libopencv_core.so.2.4.11
sharpen3: CMakeFiles/sharpen3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable sharpen3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sharpen3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sharpen3.dir/build: sharpen3
.PHONY : CMakeFiles/sharpen3.dir/build

CMakeFiles/sharpen3.dir/requires: CMakeFiles/sharpen3.dir/sharpen3.cpp.o.requires
.PHONY : CMakeFiles/sharpen3.dir/requires

CMakeFiles/sharpen3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sharpen3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sharpen3.dir/clean

CMakeFiles/sharpen3.dir/depend:
	cd /home/ljl/ljl_OpenCV/Pixel_Operations/sharpen/sharpen3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ljl/ljl_OpenCV/Pixel_Operations/sharpen/sharpen3 /home/ljl/ljl_OpenCV/Pixel_Operations/sharpen/sharpen3 /home/ljl/ljl_OpenCV/Pixel_Operations/sharpen/sharpen3 /home/ljl/ljl_OpenCV/Pixel_Operations/sharpen/sharpen3 /home/ljl/ljl_OpenCV/Pixel_Operations/sharpen/sharpen3/CMakeFiles/sharpen3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sharpen3.dir/depend
