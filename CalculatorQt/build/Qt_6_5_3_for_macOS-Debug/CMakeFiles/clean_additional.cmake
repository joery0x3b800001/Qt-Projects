# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/CalculatorQt_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/CalculatorQt_autogen.dir/ParseCache.txt"
  "CalculatorQt_autogen"
  )
endif()
