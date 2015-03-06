cmake_minimum_required(VERSION 2.6)
SET(CMAKE_CXX_FLAGS "-O2 -Wall")
project(example)
add_executable(example 
	main.cpp 
	ImageLoaderPng.cpp
	ImageSerializerDefault.cpp
	ChannelNoisy.cpp
	CoderTrivial.cpp
	CoderHamming.cpp
	)
find_package(PNG 1.6)
if(PNG_FOUND)
	include_directories(${PNG_INCLUDE_DIRS})
	target_link_libraries(example ${PNG_LIBRARIES})
else(PNG_FOUND)
	set(PNG_TESTS OFF CACHE BOOL NO)
	set(PNG_STATIC OFF)
	add_subdirectory(libpng)
	include_directories(${CMAKE_SOURCE_DIR}/libpng ${CMAKE_BINARY_DIR}/libpng)
	target_link_libraries(example png16)
endif(PNG_FOUND)
