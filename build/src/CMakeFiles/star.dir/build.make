# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/sjinglong/Test/star

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sjinglong/Test/star/build

# Include any dependencies generated for this target.
include src/CMakeFiles/star.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/star.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/star.dir/flags.make

src/CMakeFiles/star.dir/star.cpp.o: src/CMakeFiles/star.dir/flags.make
src/CMakeFiles/star.dir/star.cpp.o: ../src/star.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sjinglong/Test/star/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/star.dir/star.cpp.o"
	cd /home/sjinglong/Test/star/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/star.dir/star.cpp.o -c /home/sjinglong/Test/star/src/star.cpp

src/CMakeFiles/star.dir/star.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/star.dir/star.cpp.i"
	cd /home/sjinglong/Test/star/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sjinglong/Test/star/src/star.cpp > CMakeFiles/star.dir/star.cpp.i

src/CMakeFiles/star.dir/star.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/star.dir/star.cpp.s"
	cd /home/sjinglong/Test/star/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sjinglong/Test/star/src/star.cpp -o CMakeFiles/star.dir/star.cpp.s

src/CMakeFiles/star.dir/star.cpp.o.requires:

.PHONY : src/CMakeFiles/star.dir/star.cpp.o.requires

src/CMakeFiles/star.dir/star.cpp.o.provides: src/CMakeFiles/star.dir/star.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/star.dir/build.make src/CMakeFiles/star.dir/star.cpp.o.provides.build
.PHONY : src/CMakeFiles/star.dir/star.cpp.o.provides

src/CMakeFiles/star.dir/star.cpp.o.provides.build: src/CMakeFiles/star.dir/star.cpp.o


src/CMakeFiles/star.dir/angleSolver.cpp.o: src/CMakeFiles/star.dir/flags.make
src/CMakeFiles/star.dir/angleSolver.cpp.o: ../src/angleSolver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sjinglong/Test/star/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/star.dir/angleSolver.cpp.o"
	cd /home/sjinglong/Test/star/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/star.dir/angleSolver.cpp.o -c /home/sjinglong/Test/star/src/angleSolver.cpp

src/CMakeFiles/star.dir/angleSolver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/star.dir/angleSolver.cpp.i"
	cd /home/sjinglong/Test/star/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sjinglong/Test/star/src/angleSolver.cpp > CMakeFiles/star.dir/angleSolver.cpp.i

src/CMakeFiles/star.dir/angleSolver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/star.dir/angleSolver.cpp.s"
	cd /home/sjinglong/Test/star/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sjinglong/Test/star/src/angleSolver.cpp -o CMakeFiles/star.dir/angleSolver.cpp.s

src/CMakeFiles/star.dir/angleSolver.cpp.o.requires:

.PHONY : src/CMakeFiles/star.dir/angleSolver.cpp.o.requires

src/CMakeFiles/star.dir/angleSolver.cpp.o.provides: src/CMakeFiles/star.dir/angleSolver.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/star.dir/build.make src/CMakeFiles/star.dir/angleSolver.cpp.o.provides.build
.PHONY : src/CMakeFiles/star.dir/angleSolver.cpp.o.provides

src/CMakeFiles/star.dir/angleSolver.cpp.o.provides.build: src/CMakeFiles/star.dir/angleSolver.cpp.o


src/CMakeFiles/star.dir/getCube.cpp.o: src/CMakeFiles/star.dir/flags.make
src/CMakeFiles/star.dir/getCube.cpp.o: ../src/getCube.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sjinglong/Test/star/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/star.dir/getCube.cpp.o"
	cd /home/sjinglong/Test/star/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/star.dir/getCube.cpp.o -c /home/sjinglong/Test/star/src/getCube.cpp

src/CMakeFiles/star.dir/getCube.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/star.dir/getCube.cpp.i"
	cd /home/sjinglong/Test/star/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sjinglong/Test/star/src/getCube.cpp > CMakeFiles/star.dir/getCube.cpp.i

src/CMakeFiles/star.dir/getCube.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/star.dir/getCube.cpp.s"
	cd /home/sjinglong/Test/star/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sjinglong/Test/star/src/getCube.cpp -o CMakeFiles/star.dir/getCube.cpp.s

src/CMakeFiles/star.dir/getCube.cpp.o.requires:

.PHONY : src/CMakeFiles/star.dir/getCube.cpp.o.requires

src/CMakeFiles/star.dir/getCube.cpp.o.provides: src/CMakeFiles/star.dir/getCube.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/star.dir/build.make src/CMakeFiles/star.dir/getCube.cpp.o.provides.build
.PHONY : src/CMakeFiles/star.dir/getCube.cpp.o.provides

src/CMakeFiles/star.dir/getCube.cpp.o.provides.build: src/CMakeFiles/star.dir/getCube.cpp.o


src/CMakeFiles/star.dir/serial_mul.cpp.o: src/CMakeFiles/star.dir/flags.make
src/CMakeFiles/star.dir/serial_mul.cpp.o: ../src/serial_mul.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sjinglong/Test/star/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/star.dir/serial_mul.cpp.o"
	cd /home/sjinglong/Test/star/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/star.dir/serial_mul.cpp.o -c /home/sjinglong/Test/star/src/serial_mul.cpp

src/CMakeFiles/star.dir/serial_mul.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/star.dir/serial_mul.cpp.i"
	cd /home/sjinglong/Test/star/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sjinglong/Test/star/src/serial_mul.cpp > CMakeFiles/star.dir/serial_mul.cpp.i

src/CMakeFiles/star.dir/serial_mul.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/star.dir/serial_mul.cpp.s"
	cd /home/sjinglong/Test/star/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sjinglong/Test/star/src/serial_mul.cpp -o CMakeFiles/star.dir/serial_mul.cpp.s

src/CMakeFiles/star.dir/serial_mul.cpp.o.requires:

.PHONY : src/CMakeFiles/star.dir/serial_mul.cpp.o.requires

src/CMakeFiles/star.dir/serial_mul.cpp.o.provides: src/CMakeFiles/star.dir/serial_mul.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/star.dir/build.make src/CMakeFiles/star.dir/serial_mul.cpp.o.provides.build
.PHONY : src/CMakeFiles/star.dir/serial_mul.cpp.o.provides

src/CMakeFiles/star.dir/serial_mul.cpp.o.provides.build: src/CMakeFiles/star.dir/serial_mul.cpp.o


src/CMakeFiles/star.dir/setCamera.cpp.o: src/CMakeFiles/star.dir/flags.make
src/CMakeFiles/star.dir/setCamera.cpp.o: ../src/setCamera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sjinglong/Test/star/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/star.dir/setCamera.cpp.o"
	cd /home/sjinglong/Test/star/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/star.dir/setCamera.cpp.o -c /home/sjinglong/Test/star/src/setCamera.cpp

src/CMakeFiles/star.dir/setCamera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/star.dir/setCamera.cpp.i"
	cd /home/sjinglong/Test/star/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sjinglong/Test/star/src/setCamera.cpp > CMakeFiles/star.dir/setCamera.cpp.i

src/CMakeFiles/star.dir/setCamera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/star.dir/setCamera.cpp.s"
	cd /home/sjinglong/Test/star/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sjinglong/Test/star/src/setCamera.cpp -o CMakeFiles/star.dir/setCamera.cpp.s

src/CMakeFiles/star.dir/setCamera.cpp.o.requires:

.PHONY : src/CMakeFiles/star.dir/setCamera.cpp.o.requires

src/CMakeFiles/star.dir/setCamera.cpp.o.provides: src/CMakeFiles/star.dir/setCamera.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/star.dir/build.make src/CMakeFiles/star.dir/setCamera.cpp.o.provides.build
.PHONY : src/CMakeFiles/star.dir/setCamera.cpp.o.provides

src/CMakeFiles/star.dir/setCamera.cpp.o.provides.build: src/CMakeFiles/star.dir/setCamera.cpp.o


src/CMakeFiles/star.dir/vision_mul.cpp.o: src/CMakeFiles/star.dir/flags.make
src/CMakeFiles/star.dir/vision_mul.cpp.o: ../src/vision_mul.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sjinglong/Test/star/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/star.dir/vision_mul.cpp.o"
	cd /home/sjinglong/Test/star/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/star.dir/vision_mul.cpp.o -c /home/sjinglong/Test/star/src/vision_mul.cpp

src/CMakeFiles/star.dir/vision_mul.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/star.dir/vision_mul.cpp.i"
	cd /home/sjinglong/Test/star/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sjinglong/Test/star/src/vision_mul.cpp > CMakeFiles/star.dir/vision_mul.cpp.i

src/CMakeFiles/star.dir/vision_mul.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/star.dir/vision_mul.cpp.s"
	cd /home/sjinglong/Test/star/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sjinglong/Test/star/src/vision_mul.cpp -o CMakeFiles/star.dir/vision_mul.cpp.s

src/CMakeFiles/star.dir/vision_mul.cpp.o.requires:

.PHONY : src/CMakeFiles/star.dir/vision_mul.cpp.o.requires

src/CMakeFiles/star.dir/vision_mul.cpp.o.provides: src/CMakeFiles/star.dir/vision_mul.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/star.dir/build.make src/CMakeFiles/star.dir/vision_mul.cpp.o.provides.build
.PHONY : src/CMakeFiles/star.dir/vision_mul.cpp.o.provides

src/CMakeFiles/star.dir/vision_mul.cpp.o.provides.build: src/CMakeFiles/star.dir/vision_mul.cpp.o


# Object files for target star
star_OBJECTS = \
"CMakeFiles/star.dir/star.cpp.o" \
"CMakeFiles/star.dir/angleSolver.cpp.o" \
"CMakeFiles/star.dir/getCube.cpp.o" \
"CMakeFiles/star.dir/serial_mul.cpp.o" \
"CMakeFiles/star.dir/setCamera.cpp.o" \
"CMakeFiles/star.dir/vision_mul.cpp.o"

# External object files for target star
star_EXTERNAL_OBJECTS =

star: src/CMakeFiles/star.dir/star.cpp.o
star: src/CMakeFiles/star.dir/angleSolver.cpp.o
star: src/CMakeFiles/star.dir/getCube.cpp.o
star: src/CMakeFiles/star.dir/serial_mul.cpp.o
star: src/CMakeFiles/star.dir/setCamera.cpp.o
star: src/CMakeFiles/star.dir/vision_mul.cpp.o
star: src/CMakeFiles/star.dir/build.make
star: /usr/local/lib/libopencv_videostab.so.3.4.3
star: /usr/local/lib/libopencv_superres.so.3.4.3
star: /usr/local/lib/libopencv_stitching.so.3.4.3
star: /usr/local/lib/libopencv_rgbd.so.3.4.3
star: /usr/local/lib/libopencv_xphoto.so.3.4.3
star: /usr/local/lib/libopencv_xobjdetect.so.3.4.3
star: /usr/local/lib/libopencv_surface_matching.so.3.4.3
star: /usr/local/lib/libopencv_stereo.so.3.4.3
star: /usr/local/lib/libopencv_freetype.so.3.4.3
star: /usr/local/lib/libopencv_dpm.so.3.4.3
star: /usr/local/lib/libopencv_fuzzy.so.3.4.3
star: /usr/local/lib/libopencv_optflow.so.3.4.3
star: /usr/local/lib/libopencv_dnn_objdetect.so.3.4.3
star: /usr/local/lib/libopencv_face.so.3.4.3
star: /usr/local/lib/libopencv_ccalib.so.3.4.3
star: /usr/local/lib/libopencv_line_descriptor.so.3.4.3
star: /usr/local/lib/libopencv_saliency.so.3.4.3
star: /usr/local/lib/libopencv_bgsegm.so.3.4.3
star: /usr/local/lib/libopencv_hfs.so.3.4.3
star: /usr/local/lib/libopencv_tracking.so.3.4.3
star: /usr/local/lib/libopencv_xfeatures2d.so.3.4.3
star: /usr/local/lib/libopencv_ximgproc.so.3.4.3
star: /usr/local/lib/libopencv_structured_light.so.3.4.3
star: /usr/local/lib/libopencv_datasets.so.3.4.3
star: /usr/local/lib/libopencv_aruco.so.3.4.3
star: /usr/local/lib/libopencv_img_hash.so.3.4.3
star: /usr/local/lib/libopencv_bioinspired.so.3.4.3
star: /usr/local/lib/libopencv_reg.so.3.4.3
star: /usr/local/lib/libopencv_shape.so.3.4.3
star: /usr/local/lib/libopencv_photo.so.3.4.3
star: /usr/local/lib/libopencv_objdetect.so.3.4.3
star: /usr/local/lib/libopencv_video.so.3.4.3
star: /usr/local/lib/libopencv_plot.so.3.4.3
star: /usr/local/lib/libopencv_text.so.3.4.3
star: /usr/local/lib/libopencv_ml.so.3.4.3
star: /usr/local/lib/libopencv_dnn.so.3.4.3
star: /usr/local/lib/libopencv_phase_unwrapping.so.3.4.3
star: /usr/local/lib/libopencv_calib3d.so.3.4.3
star: /usr/local/lib/libopencv_features2d.so.3.4.3
star: /usr/local/lib/libopencv_flann.so.3.4.3
star: /usr/local/lib/libopencv_highgui.so.3.4.3
star: /usr/local/lib/libopencv_videoio.so.3.4.3
star: /usr/local/lib/libopencv_imgcodecs.so.3.4.3
star: /usr/local/lib/libopencv_imgproc.so.3.4.3
star: /usr/local/lib/libopencv_core.so.3.4.3
star: src/CMakeFiles/star.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sjinglong/Test/star/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ../star"
	cd /home/sjinglong/Test/star/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/star.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/star.dir/build: star

.PHONY : src/CMakeFiles/star.dir/build

src/CMakeFiles/star.dir/requires: src/CMakeFiles/star.dir/star.cpp.o.requires
src/CMakeFiles/star.dir/requires: src/CMakeFiles/star.dir/angleSolver.cpp.o.requires
src/CMakeFiles/star.dir/requires: src/CMakeFiles/star.dir/getCube.cpp.o.requires
src/CMakeFiles/star.dir/requires: src/CMakeFiles/star.dir/serial_mul.cpp.o.requires
src/CMakeFiles/star.dir/requires: src/CMakeFiles/star.dir/setCamera.cpp.o.requires
src/CMakeFiles/star.dir/requires: src/CMakeFiles/star.dir/vision_mul.cpp.o.requires

.PHONY : src/CMakeFiles/star.dir/requires

src/CMakeFiles/star.dir/clean:
	cd /home/sjinglong/Test/star/build/src && $(CMAKE_COMMAND) -P CMakeFiles/star.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/star.dir/clean

src/CMakeFiles/star.dir/depend:
	cd /home/sjinglong/Test/star/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sjinglong/Test/star /home/sjinglong/Test/star/src /home/sjinglong/Test/star/build /home/sjinglong/Test/star/build/src /home/sjinglong/Test/star/build/src/CMakeFiles/star.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/star.dir/depend
