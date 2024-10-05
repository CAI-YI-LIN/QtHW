# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\teamhw1007_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\teamhw1007_autogen.dir\\ParseCache.txt"
  "teamhw1007_autogen"
  )
endif()
