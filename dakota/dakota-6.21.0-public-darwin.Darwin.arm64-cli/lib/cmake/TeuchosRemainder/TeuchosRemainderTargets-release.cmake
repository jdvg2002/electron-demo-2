#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "teuchosremainder" for configuration "Release"
set_property(TARGET teuchosremainder APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(teuchosremainder PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libteuchosremainder.13.0.dylib"
  IMPORTED_SONAME_RELEASE "@rpath/libteuchosremainder.13.dylib"
  )

list(APPEND _cmake_import_check_targets teuchosremainder )
list(APPEND _cmake_import_check_files_for_teuchosremainder "${_IMPORT_PREFIX}/lib/libteuchosremainder.13.0.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
