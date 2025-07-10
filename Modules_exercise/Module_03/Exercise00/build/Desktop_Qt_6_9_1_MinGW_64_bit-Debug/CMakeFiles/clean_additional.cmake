# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Exercise00_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Exercise00_autogen.dir\\ParseCache.txt"
  "Exercise00_autogen"
  )
endif()
