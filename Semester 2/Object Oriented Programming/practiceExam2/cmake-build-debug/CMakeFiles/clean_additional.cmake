# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\practiceExam2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\practiceExam2_autogen.dir\\ParseCache.txt"
  "practiceExam2_autogen"
  )
endif()
