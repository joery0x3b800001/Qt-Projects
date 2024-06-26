# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appSampleQt_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appSampleQt_autogen.dir/ParseCache.txt"
  "appSampleQt_autogen"
  )
endif()
