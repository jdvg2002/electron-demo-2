# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.8)
   message(FATAL_ERROR "CMake >= 2.8.0 required")
endif()
if(CMAKE_VERSION VERSION_LESS "2.8.3")
   message(FATAL_ERROR "CMake >= 2.8.3 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.8.3...3.25)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_cmake_targets_defined "")
set(_cmake_targets_not_defined "")
set(_cmake_expected_targets "")
foreach(_cmake_expected_target IN ITEMS dakota_util dakota_surrogates surrogates jni_dakota_surrogates conmin ncsuopt nidr amplsolver optpp dfftpack lhs_mod lhs_mods lhs sparsegrid pecos_util pecos_src approxnn surfpack_interpreter surfpack surfpack_fortran 3po tinyxml utilib colin pebbl scolib interfaces ddace dream fsudace fsu_halton_standalone fsu_hammersley_standalone fsu_cvt_standalone fsu_latinize_standalone fsu_quality_standalone hopspack moga soga utilities jega_fe eutils jega cport nomad psuade dakota_src_fortran dakota_src environment)
  list(APPEND _cmake_expected_targets "${_cmake_expected_target}")
  if(TARGET "${_cmake_expected_target}")
    list(APPEND _cmake_targets_defined "${_cmake_expected_target}")
  else()
    list(APPEND _cmake_targets_not_defined "${_cmake_expected_target}")
  endif()
endforeach()
unset(_cmake_expected_target)
if(_cmake_targets_defined STREQUAL _cmake_expected_targets)
  unset(_cmake_targets_defined)
  unset(_cmake_targets_not_defined)
  unset(_cmake_expected_targets)
  unset(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT _cmake_targets_defined STREQUAL "")
  string(REPLACE ";" ", " _cmake_targets_defined_text "${_cmake_targets_defined}")
  string(REPLACE ";" ", " _cmake_targets_not_defined_text "${_cmake_targets_not_defined}")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_cmake_targets_defined_text}\nTargets not yet defined: ${_cmake_targets_not_defined_text}\n")
endif()
unset(_cmake_targets_defined)
unset(_cmake_targets_not_defined)
unset(_cmake_expected_targets)


# Compute the installation prefix relative to this file.
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

# Create imported target dakota_util
add_library(dakota_util SHARED IMPORTED)

set_target_properties(dakota_util PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "EIGEN_MPL2_ONLY"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include;${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "teuchosremainder;teuchosnumerics;teuchoscomm;teuchosparameterlist;teuchosparser;teuchoscore;Eigen3::Eigen;Boost::serialization"
)

# Create imported target dakota_surrogates
add_library(dakota_surrogates SHARED IMPORTED)

set_target_properties(dakota_surrogates PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include;${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "dakota_util;pybind11::embed;teuchosremainder;teuchosnumerics;teuchoscomm;teuchosparameterlist;teuchosparser;teuchoscore;Boost::serialization"
)

# Create imported target surrogates
add_library(surrogates MODULE IMPORTED)

# Create imported target jni_dakota_surrogates
add_library(jni_dakota_surrogates SHARED IMPORTED)

set_target_properties(jni_dakota_surrogates PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/projects/dakota/utils/rhel8/jdk-17.0.11/include;/projects/dakota/utils/rhel8/jdk-17.0.11/include/linux;/projects/dakota/utils/rhel8/jdk-17.0.11/include"
  INTERFACE_LINK_LIBRARIES "dakota_surrogates"
)

# Create imported target conmin
add_library(conmin SHARED IMPORTED)

# Create imported target ncsuopt
add_library(ncsuopt SHARED IMPORTED)

# Create imported target nidr
add_library(nidr SHARED IMPORTED)

# Create imported target amplsolver
add_library(amplsolver SHARED IMPORTED)

# Create imported target optpp
add_library(optpp SHARED IMPORTED)

set_target_properties(optpp PROPERTIES
  INTERFACE_LINK_LIBRARIES "teuchosremainder;teuchosnumerics;teuchoscomm;teuchosparameterlist;teuchosparser;teuchoscore;/usr/lib64/libblas.so;/usr/lib64/liblapack.so"
)

# Create imported target dfftpack
add_library(dfftpack SHARED IMPORTED)

# Create imported target lhs_mod
add_library(lhs_mod SHARED IMPORTED)

# Create imported target lhs_mods
add_library(lhs_mods SHARED IMPORTED)

set_target_properties(lhs_mods PROPERTIES
  INTERFACE_LINK_LIBRARIES "lhs_mod"
)

# Create imported target lhs
add_library(lhs SHARED IMPORTED)

set_target_properties(lhs PROPERTIES
  INTERFACE_LINK_LIBRARIES "lhs_mod;lhs_mods"
)

# Create imported target sparsegrid
add_library(sparsegrid SHARED IMPORTED)

# Create imported target pecos_util
add_library(pecos_util SHARED IMPORTED)

set_target_properties(pecos_util PROPERTIES
  INTERFACE_LINK_LIBRARIES "teuchosremainder;teuchosnumerics;teuchoscomm;teuchosparameterlist;teuchosparser;teuchoscore;/usr/lib64/liblapack.so;/usr/lib64/libblas.so;Boost::boost"
)

# Create imported target pecos_src
add_library(pecos_src SHARED IMPORTED)

set_target_properties(pecos_src PROPERTIES
  INTERFACE_LINK_LIBRARIES "pecos_util;lhs;lhs_mods;lhs_mod;dfftpack;sparsegrid;teuchosremainder;teuchosnumerics;teuchoscomm;teuchosparameterlist;teuchosparser;teuchoscore;/usr/lib64/liblapack.so;/usr/lib64/libblas.so;Boost::boost"
)

# Create imported target approxnn
add_library(approxnn SHARED IMPORTED)

# Create imported target surfpack_interpreter
add_library(surfpack_interpreter SHARED IMPORTED)

# Create imported target surfpack
add_library(surfpack SHARED IMPORTED)

set_target_properties(surfpack PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "SURFPACK_HAVE_BOOST_SERIALIZATION"
  INTERFACE_LINK_LIBRARIES "surfpack_fortran;Boost::boost;Boost::serialization"
)

# Create imported target surfpack_fortran
add_library(surfpack_fortran SHARED IMPORTED)

# Create imported target 3po
add_library(3po SHARED IMPORTED)

# Create imported target tinyxml
add_library(tinyxml SHARED IMPORTED)

set_target_properties(tinyxml PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target utilib
add_library(utilib SHARED IMPORTED)

set_target_properties(utilib PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "m;tinyxml"
)

# Create imported target colin
add_library(colin SHARED IMPORTED)

set_target_properties(colin PROPERTIES
  INTERFACE_LINK_LIBRARIES "tinyxml;utilib;/usr/lib64/libdl.so;amplsolver"
)

# Create imported target pebbl
add_library(pebbl SHARED IMPORTED)

set_target_properties(pebbl PROPERTIES
  INTERFACE_LINK_LIBRARIES "utilib"
)

# Create imported target scolib
add_library(scolib SHARED IMPORTED)

set_target_properties(scolib PROPERTIES
  INTERFACE_LINK_LIBRARIES "utilib;pebbl;amplsolver"
)

# Create imported target interfaces
add_library(interfaces SHARED IMPORTED)

set_target_properties(interfaces PROPERTIES
  INTERFACE_LINK_LIBRARIES "3po"
)

# Create imported target ddace
add_library(ddace SHARED IMPORTED)

# Create imported target dream
add_library(dream SHARED IMPORTED)

# Create imported target fsudace
add_library(fsudace SHARED IMPORTED)

# Create imported target fsu_halton_standalone
add_executable(fsu_halton_standalone IMPORTED)

# Create imported target fsu_hammersley_standalone
add_executable(fsu_hammersley_standalone IMPORTED)

# Create imported target fsu_cvt_standalone
add_executable(fsu_cvt_standalone IMPORTED)

# Create imported target fsu_latinize_standalone
add_executable(fsu_latinize_standalone IMPORTED)

# Create imported target fsu_quality_standalone
add_executable(fsu_quality_standalone IMPORTED)

# Create imported target hopspack
add_library(hopspack SHARED IMPORTED)

set_target_properties(hopspack PROPERTIES
  INTERFACE_LINK_LIBRARIES "Boost::boost"
)

# Create imported target moga
add_library(moga SHARED IMPORTED)

set_target_properties(moga PROPERTIES
  INTERFACE_LINK_LIBRARIES "jega;utilities"
)

# Create imported target soga
add_library(soga SHARED IMPORTED)

set_target_properties(soga PROPERTIES
  INTERFACE_LINK_LIBRARIES "jega;utilities"
)

# Create imported target utilities
add_library(utilities SHARED IMPORTED)

# Create imported target jega_fe
add_library(jega_fe SHARED IMPORTED)

set_target_properties(jega_fe PROPERTIES
  INTERFACE_LINK_LIBRARIES "moga;soga;eutils"
)

# Create imported target eutils
add_library(eutils SHARED IMPORTED)

# Create imported target jega
add_library(jega SHARED IMPORTED)

# Create imported target cport
add_library(cport SHARED IMPORTED)

# Create imported target nomad
add_library(nomad SHARED IMPORTED)

# Create imported target psuade
add_library(psuade SHARED IMPORTED)

# Create imported target dakota_src_fortran
add_library(dakota_src_fortran SHARED IMPORTED)

# Create imported target dakota_src
add_library(dakota_src SHARED IMPORTED)

set_target_properties(dakota_src PROPERTIES
  INTERFACE_LINK_LIBRARIES "dakota_src_fortran;Boost::boost;Boost::filesystem;Boost::program_options;Boost::regex;Boost::serialization;Boost::system;dakota_util;dakota_surrogates;utilib;colin;interfaces;scolib"
)

# Create imported target environment
add_library(environment MODULE IMPORTED)

if(CMAKE_VERSION VERSION_LESS 2.8.12)
  message(FATAL_ERROR "This file relies on consumers using CMake 2.8.12 or greater.")
endif()

# Load information for each installed configuration.
file(GLOB _cmake_config_files "${CMAKE_CURRENT_LIST_DIR}/DakotaTargets-*.cmake")
foreach(_cmake_config_file IN LISTS _cmake_config_files)
  include("${_cmake_config_file}")
endforeach()
unset(_cmake_config_file)
unset(_cmake_config_files)

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(_cmake_target IN LISTS _cmake_import_check_targets)
  foreach(_cmake_file IN LISTS "_cmake_import_check_files_for_${_cmake_target}")
    if(NOT EXISTS "${_cmake_file}")
      message(FATAL_ERROR "The imported target \"${_cmake_target}\" references the file
   \"${_cmake_file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
  endforeach()
  unset(_cmake_file)
  unset("_cmake_import_check_files_for_${_cmake_target}")
endforeach()
unset(_cmake_target)
unset(_cmake_import_check_targets)

# Make sure the targets which have been exported in some other
# export set exist.
unset(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets)
foreach(_target "teuchosremainder" "teuchosnumerics" "teuchoscomm" "teuchosparameterlist" "teuchosparser" "teuchoscore" )
  if(NOT TARGET "${_target}" )
    set(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets "${${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets} ${_target}")
  endif()
endforeach()

if(DEFINED ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets)
  if(CMAKE_FIND_PACKAGE_NAME)
    set( ${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE)
    set( ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE "The following imported targets are referenced, but are missing: ${${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets}")
  else()
    message(FATAL_ERROR "The following imported targets are referenced, but are missing: ${${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets}")
  endif()
endif()
unset(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets)

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)