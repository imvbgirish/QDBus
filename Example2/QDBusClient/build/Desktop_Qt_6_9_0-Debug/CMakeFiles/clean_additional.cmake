# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appQDBusClient_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appQDBusClient_autogen.dir/ParseCache.txt"
  "appQDBusClient_autogen"
  )
endif()
