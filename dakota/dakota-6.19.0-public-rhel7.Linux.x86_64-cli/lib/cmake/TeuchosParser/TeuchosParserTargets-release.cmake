#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "teuchosparser" for configuration "Release"
set_property(TARGET teuchosparser APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(teuchosparser PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libteuchosparser.so.13.0"
  IMPORTED_SONAME_RELEASE "libteuchosparser.so.13"
  )

list(APPEND _IMPORT_CHECK_TARGETS teuchosparser )
list(APPEND _IMPORT_CHECK_FILES_FOR_teuchosparser "${_IMPORT_PREFIX}/lib/libteuchosparser.so.13.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
