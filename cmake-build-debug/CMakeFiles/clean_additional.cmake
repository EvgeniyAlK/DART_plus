# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/GeoDart_Standalone_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/GeoDart_Standalone_autogen.dir/ParseCache.txt"
  "GeoDart_Standalone_autogen"
  )
endif()
