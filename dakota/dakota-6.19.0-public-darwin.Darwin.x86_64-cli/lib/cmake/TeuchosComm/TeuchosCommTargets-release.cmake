#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "teuchoscomm" for configuration "Release"
set_property(TARGET teuchoscomm APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(teuchoscomm PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libteuchoscomm.13.0.dylib"
  IMPORTED_SONAME_RELEASE "@rpath/libteuchoscomm.13.dylib"
  )

list(APPEND _IMPORT_CHECK_TARGETS teuchoscomm )
list(APPEND _IMPORT_CHECK_FILES_FOR_teuchoscomm "${_IMPORT_PREFIX}/lib/libteuchoscomm.13.0.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
