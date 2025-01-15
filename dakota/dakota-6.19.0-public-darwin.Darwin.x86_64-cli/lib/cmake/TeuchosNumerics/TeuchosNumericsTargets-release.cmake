#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "teuchosnumerics" for configuration "Release"
set_property(TARGET teuchosnumerics APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(teuchosnumerics PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libteuchosnumerics.13.0.dylib"
  IMPORTED_SONAME_RELEASE "@rpath/libteuchosnumerics.13.dylib"
  )

list(APPEND _IMPORT_CHECK_TARGETS teuchosnumerics )
list(APPEND _IMPORT_CHECK_FILES_FOR_teuchosnumerics "${_IMPORT_PREFIX}/lib/libteuchosnumerics.13.0.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
