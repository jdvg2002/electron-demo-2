#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "teuchosparser" for configuration "Release"
set_property(TARGET teuchosparser APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(teuchosparser PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libteuchosparser.13.0.dylib"
  IMPORTED_SONAME_RELEASE "@rpath/libteuchosparser.13.dylib"
  )

list(APPEND _cmake_import_check_targets teuchosparser )
list(APPEND _cmake_import_check_files_for_teuchosparser "${_IMPORT_PREFIX}/lib/libteuchosparser.13.0.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)