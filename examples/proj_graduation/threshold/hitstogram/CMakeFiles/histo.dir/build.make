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
CMAKE_SOURCE_DIR = /home/ljl/ljl_OpenCV/examples/proj_graduation/threshold/hitstogram

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ljl/ljl_OpenCV/examples/proj_graduation/threshold/hitstogram

# Include any dependencies generated for this target.
include CMakeFiles/histo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/histo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/histo.dir/flags.make

CMakeFiles/histo.dir/histo.cpp.o: CMakeFiles/histo.dir/flags.make
CMakeFiles/histo.dir/histo.cpp.o: histo.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ljl/ljl_OpenCV/examples/proj_graduation/threshold/hitstogram/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/histo.dir/histo.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/histo.dir/histo.cpp.o -c /home/ljl/ljl_OpenCV/examples/proj_graduation/threshold/hitstogram/histo.cpp

CMakeFiles/histo.dir/histo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/histo.dir/histo.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ljl/ljl_OpenCV/examples/proj_graduation/threshold/hitstogram/histo.cpp > CMakeFiles/histo.dir/histo.cpp.i

CMakeFiles/histo.dir/histo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/histo.dir/histo.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ljl/ljl_OpenCV/examples/proj_graduation/threshold/hitstogram/histo.cpp -o CMakeFiles/histo.dir/histo.cpp.s

CMakeFiles/histo.dir/histo.cpp.o.requires:
.PHONY : CMakeFiles/histo.dir/histo.cpp.o.requires

CMakeFiles/histo.dir/histo.cpp.o.provides: CMakeFiles/histo.dir/histo.cpp.o.requires
	$(MAKE) -f CMakeFiles/histo.dir/build.make CMakeFiles/histo.dir/histo.cpp.o.provides.build
.PHONY : CMakeFiles/histo.dir/histo.cpp.o.provides

CMakeFiles/histo.dir/histo.cpp.o.provides.build: CMakeFiles/histo.dir/histo.cpp.o

# Object files for target histo
histo_OBJECTS = \
"CMakeFiles/histo.dir/histo.cpp.o"

# External object files for target histo
histo_EXTERNAL_OBJECTS =

histo: CMakeFiles/histo.dir/histo.cpp.o
histo: CMakeFiles/histo.dir/build.make
histo: /usr/local/lib/libopencv_videostab.so.2.4.11
histo: /usr/local/lib/libopencv_video.so.2.4.11
histo: /usr/local/lib/libopencv_ts.a
histo: /usr/local/lib/libopencv_superres.so.2.4.11
histo: /usr/local/lib/libopencv_stitching.so.2.4.11
histo: /usr/local/lib/libopencv_photo.so.2.4.11
histo: /usr/local/lib/libopencv_ocl.so.2.4.11
histo: /usr/local/lib/libopencv_objdetect.so.2.4.11
histo: /usr/local/lib/libopencv_nonfree.so.2.4.11
histo: /usr/local/lib/libopencv_ml.so.2.4.11
histo: /usr/local/lib/libopencv_legacy.so.2.4.11
histo: /usr/local/lib/libopencv_imgproc.so.2.4.11
histo: /usr/local/lib/libopencv_highgui.so.2.4.11
histo: /usr/local/lib/libopencv_gpu.so.2.4.11
histo: /usr/local/lib/libopencv_flann.so.2.4.11
histo: /usr/local/lib/libopencv_features2d.so.2.4.11
histo: /usr/local/lib/libopencv_core.so.2.4.11
histo: /usr/local/lib/libopencv_contrib.so.2.4.11
histo: /usr/local/lib/libopencv_calib3d.so.2.4.11
histo: /usr/local/lib/libopencv_nonfree.so.2.4.11
histo: /usr/local/lib/libopencv_ocl.so.2.4.11
histo: /usr/local/lib/libopencv_gpu.so.2.4.11
histo: /usr/local/lib/libopencv_photo.so.2.4.11
histo: /usr/local/lib/libopencv_objdetect.so.2.4.11
histo: /usr/local/lib/libopencv_legacy.so.2.4.11
histo: /usr/local/lib/libopencv_video.so.2.4.11
histo: /usr/local/lib/libopencv_ml.so.2.4.11
histo: /usr/local/lib/libopencv_calib3d.so.2.4.11
histo: /usr/local/lib/libopencv_features2d.so.2.4.11
histo: /usr/local/lib/libopencv_highgui.so.2.4.11
histo: /usr/local/lib/libopencv_imgproc.so.2.4.11
histo: /usr/local/lib/libopencv_flann.so.2.4.11
histo: /usr/local/lib/libopencv_core.so.2.4.11
histo: CMakeFiles/histo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable histo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/histo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/histo.dir/build: histo
.PHONY : CMakeFiles/histo.dir/build

CMakeFiles/histo.dir/requires: CMakeFiles/histo.dir/histo.cpp.o.requires
.PHONY : CMakeFiles/histo.dir/requires

CMakeFiles/histo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/histo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/histo.dir/clean

CMakeFiles/histo.dir/depend:
	cd /home/ljl/ljl_OpenCV/examples/proj_graduation/threshold/hitstogram && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ljl/ljl_OpenCV/examples/proj_graduation/threshold/hitstogram /home/ljl/ljl_OpenCV/examples/proj_graduation/threshold/hitstogram /home/ljl/ljl_OpenCV/examples/proj_graduation/threshold/hitstogram /home/ljl/ljl_OpenCV/examples/proj_graduation/threshold/hitstogram /home/ljl/ljl_OpenCV/examples/proj_graduation/threshold/hitstogram/CMakeFiles/histo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/histo.dir/depend

