# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appQDBusServer_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appQDBusServer_autogen.dir/ParseCache.txt"
  "appQDBusServer_autogen"
  )
endif()
