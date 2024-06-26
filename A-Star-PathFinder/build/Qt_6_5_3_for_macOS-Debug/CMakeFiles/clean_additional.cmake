# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "A-Star-PathFinder_autogen"
  "CMakeFiles/A-Star-PathFinder_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/A-Star-PathFinder_autogen.dir/ParseCache.txt"
  )
endif()
