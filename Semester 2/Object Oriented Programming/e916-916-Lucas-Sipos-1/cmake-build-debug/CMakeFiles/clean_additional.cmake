# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\e916-916-Lucas-Sipos-1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\e916-916-Lucas-Sipos-1_autogen.dir\\ParseCache.txt"
  "e916-916-Lucas-Sipos-1_autogen"
  )
endif()
