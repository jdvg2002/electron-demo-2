#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "muqUtilities" for configuration "Release"
set_property(TARGET muqUtilities APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(muqUtilities PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libmuqUtilities.dylib"
  IMPORTED_SONAME_RELEASE "@rpath/libmuqUtilities.dylib"
  )

list(APPEND _cmake_import_check_targets muqUtilities )
list(APPEND _cmake_import_check_files_for_muqUtilities "${_IMPORT_PREFIX}/lib/libmuqUtilities.dylib" )

# Import target "muqModeling" for configuration "Release"
set_property(TARGET muqModeling APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(muqModeling PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libmuqModeling.dylib"
  IMPORTED_SONAME_RELEASE "@rpath/libmuqModeling.dylib"
  )

list(APPEND _cmake_import_check_targets muqModeling )
list(APPEND _cmake_import_check_files_for_muqModeling "${_IMPORT_PREFIX}/lib/libmuqModeling.dylib" )

# Import target "muqSamplingAlgorithms" for configuration "Release"
set_property(TARGET muqSamplingAlgorithms APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(muqSamplingAlgorithms PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libmuqSamplingAlgorithms.dylib"
  IMPORTED_SONAME_RELEASE "@rpath/libmuqSamplingAlgorithms.dylib"
  )

list(APPEND _cmake_import_check_targets muqSamplingAlgorithms )
list(APPEND _cmake_import_check_files_for_muqSamplingAlgorithms "${_IMPORT_PREFIX}/lib/libmuqSamplingAlgorithms.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
