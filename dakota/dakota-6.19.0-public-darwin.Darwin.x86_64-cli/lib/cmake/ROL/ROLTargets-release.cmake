#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rol" for configuration "Release"
set_property(TARGET rol APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rol PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/librol.13.0.dylib"
  IMPORTED_SONAME_RELEASE "@rpath/librol.13.dylib"
  )

list(APPEND _IMPORT_CHECK_TARGETS rol )
list(APPEND _IMPORT_CHECK_FILES_FOR_rol "${_IMPORT_PREFIX}/lib/librol.13.0.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
