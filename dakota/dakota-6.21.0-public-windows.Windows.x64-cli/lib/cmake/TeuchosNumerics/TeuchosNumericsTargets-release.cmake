#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "teuchosnumerics" for configuration "Release"
set_property(TARGET teuchosnumerics APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(teuchosnumerics PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/teuchosnumerics.lib"
  )

list(APPEND _cmake_import_check_targets teuchosnumerics )
list(APPEND _cmake_import_check_files_for_teuchosnumerics "${_IMPORT_PREFIX}/lib/teuchosnumerics.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
