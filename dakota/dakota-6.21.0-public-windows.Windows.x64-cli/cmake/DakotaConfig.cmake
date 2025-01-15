# - Config file for the Dakota package
# It defines the following variables
#  Dakota_INCLUDE_DIRS - include directories for Dakota
#  Dakota_LIBRARIES    - libraries to link against
#  Dakota_EXECUTABLE   - the dakota executable

# Compute paths
get_filename_component(DAKOTA_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)

# Check existence since may be building/installing under
# Trilinos/TriKota, or using an external Trilinos
if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/../Teuchos/TeuchosConfig.cmake")
  include("${CMAKE_CURRENT_LIST_DIR}/../Teuchos/TeuchosConfig.cmake")
endif()

# Conservative approach for now
if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/../../../share/eigen3/cmake")
  set(Eigen3_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../share/eigen3/cmake")
endif()
include(CMakeFindDependencyMacro)
find_dependency(Eigen3)

# Our library dependencies (contains definitions for IMPORTED targets)
include("${DAKOTA_CMAKE_DIR}/DakotaTargets.cmake")


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was DakotaConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

# Build tree option not yet working
if (Dakota_BUILD_TREE)
  # Dakota's build tree doesn't have a single convenient place for headers
  set(Dakota_INCLUDE_DIRS_TMP "C:/jenkins/workspace/public_windows_builder/build/generated/src;C:/jenkins/workspace/public_windows_builder/build;C:/jenkins/workspace/public_windows_builder/build/src;C:/jenkins/workspace/public_windows_builder/source/src;C:/jenkins/workspace/public_windows_builder/source/packages;C:/jenkins/workspace/public_windows_builder/build/packages/external/trilinos;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/cmake/tribits/win_interface/include;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/teuchos/remainder/src;C:/jenkins/workspace/public_windows_builder/build/packages/external/trilinos/packages/teuchos/remainder/src;C:/jenkins/workspace/public_windows_builder/build/packages/external/trilinos/packages/teuchos/core/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/teuchos/core/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/teuchos/numerics/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/teuchos/comm/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/teuchos/parameterlist/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/teuchos/parser/src;C:/jenkins/workspace/public_windows_builder/build/packages/pecos;C:/jenkins/workspace/public_windows_builder/source/packages/pecos/util/src;C:/jenkins/workspace/public_windows_builder/source/packages/pecos/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/VPISparseGrid/src;C:/jenkins/workspace/public_windows_builder/build/packages/surfpack;C:/jenkins/workspace/public_windows_builder/source/packages/surfpack/src;C:/jenkins/workspace/public_windows_builder/source/src/util;C:/jenkins/workspace/public_windows_builder/source/src/surrogates;C:/jenkins/workspace/public_windows_builder/source/packages/external/eigen3/include/eigen3;C:/jenkins/workspace/public_windows_builder/build/packages/external/acro/packages;C:/jenkins/workspace/public_windows_builder/build/packages/external/acro/packages/utilib;C:/jenkins/workspace/public_windows_builder/source/packages/external/acro/packages/interfaces/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/acro/packages/scolib/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/acro/packages/utilib/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/acro/packages/colin/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/acro/packages/pebbl/src/bb;C:/jenkins/workspace/public_windows_builder/source/packages/external/acro/packages/pebbl/src/comm;C:/jenkins/workspace/public_windows_builder/source/packages/external/acro/packages/pebbl/src/misc;C:/jenkins/workspace/public_windows_builder/source/packages/external/acro/packages/pebbl/src/pbb;C:/jenkins/workspace/public_windows_builder/source/packages/external/acro/packages/pebbl/src/sched;C:/jenkins/workspace/public_windows_builder/source/packages/external/acro/tpl/tinyxml;C:/jenkins/workspace/public_windows_builder/source/packages/external/approxnn/include;C:/jenkins/workspace/public_windows_builder/build/packages/external/DDACE;C:/jenkins/workspace/public_windows_builder/source/packages/external/DDACE/include;C:/jenkins/workspace/public_windows_builder/source/packages/external/dream;C:/jenkins/workspace/public_windows_builder/build/packages/external/FSUDace;C:/jenkins/workspace/public_windows_builder/source/packages/external/FSUDace;C:/jenkins/workspace/public_windows_builder/build/packages/external/hopspack/src/src-shared;C:/jenkins/workspace/public_windows_builder/source/packages/external/hopspack/src/src-shared;C:/jenkins/workspace/public_windows_builder/source/packages/external/hopspack/src/src-citizens;C:/jenkins/workspace/public_windows_builder/source/packages/external/hopspack/src/src-evaluator;C:/jenkins/workspace/public_windows_builder/source/packages/external/hopspack/src/src-executor;C:/jenkins/workspace/public_windows_builder/source/packages/external/hopspack/src/src-framework;C:/jenkins/workspace/public_windows_builder/source/packages/external/hopspack/src/src-main;C:/jenkins/workspace/public_windows_builder/build/packages/external/JEGA;C:/jenkins/workspace/public_windows_builder/build/packages/external/JEGA/eddy;C:/jenkins/workspace/public_windows_builder/source/packages/external/JEGA/eddy;C:/jenkins/workspace/public_windows_builder/source/packages/external/JEGA/include;C:/jenkins/workspace/public_windows_builder/build/packages/external/NOMAD/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/NOMAD/src;C:/jenkins/workspace/public_windows_builder/build/packages/external/OPTPP/include;C:/jenkins/workspace/public_windows_builder/source/packages/external/OPTPP/include;C:/jenkins/workspace/public_windows_builder/build/packages/external/trilinos;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/cmake/tribits/win_interface/include;C:/jenkins/workspace/public_windows_builder/build/packages/external/trilinos/packages/rol/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/compatibility/teuchos/rcp;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/compatibility/teuchos/parameterlist;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/compatibility/teuchos/stacktrace;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/compatibility/teuchos/la;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/compatibility/teuchos/lapack;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/compatibility/teuchos/blas;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/vector;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/function;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/function/dynamic;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/function/boundconstraint;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/function/constraint;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/function/nlls;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/function/objective;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/function/operator;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/function/simopt;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/function/sketching;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/function/std;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/step;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/step/linesearch;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/step/trustregion;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/step/secant;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/step/krylov;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/step/bundle;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/step/augmentedlagrangian;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/step/moreauyosidapenalty;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/step/interiorpoint;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/step/nonlinearcg;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/step/fletcher;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/algorithm;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/status;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol/function;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol/function/distribution;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol/function/expectationquad;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/risk;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/risk/fdivergence;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/risk/spectral;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/error;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/regret;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/deviation;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/probability;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol/function/progressivehedging;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol/algorithm;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol/algorithm/PrimalDual;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol/vector;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol/sampler;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol/sampler/SROM;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/sol/status;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/elementwise;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/utils;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/utils/function_bindings;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/zoo;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/rol/src/zoo/testproblems;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/teuchos/remainder/src;C:/jenkins/workspace/public_windows_builder/build/packages/external/trilinos/packages/teuchos/remainder/src;C:/jenkins/workspace/public_windows_builder/build/packages/external/trilinos/packages/teuchos/core/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/teuchos/core/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/teuchos/numerics/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/teuchos/comm/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/teuchos/parameterlist/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/trilinos/packages/teuchos/parser/src;C:/jenkins/workspace/public_windows_builder/source/packages/external/PSUADE;C:/jenkins/workspace/public_windows_builder/build/packages/external/ampl")
  # This won't work yet.  Since Dakota is in a build tree the
  # libraries are scattered, but the import doesn't know where they
  # are.
  set(Dakota_LIBRARY_DIRS_TMP "C:/jenkins/workspace/public_windows_builder/build/packages/external/trilinos/packages/teuchos/remainder/src;C:/jenkins/workspace/public_windows_builder/build/packages/external/trilinos/packages/teuchos/core/src;C:/jenkins/workspace/public_windows_builder/build/packages/external/trilinos/packages/teuchos/numerics/src;C:/jenkins/workspace/public_windows_builder/build/packages/external/trilinos/packages/teuchos/comm/src;C:/jenkins/workspace/public_windows_builder/build/packages/external/trilinos/packages/teuchos/parameterlist/src;C:/jenkins/workspace/public_windows_builder/build/packages/external/trilinos/packages/teuchos/parser/src")
else()
  set_and_check(Dakota_INCLUDE_DIRS_TMP "${PACKAGE_PREFIX_DIR}/include")
  set_and_check(Dakota_LIB_DIRS_TMP "${PACKAGE_PREFIX_DIR}/lib")
endif()

# Variables intended for use by other projects

set_and_check(Dakota_DIR ${DAKOTA_CMAKE_DIR})

# TODO: reference in src vs bin
set(Dakota_EXECUTABLE dakota)


set(Dakota_DEFINES "_CRT_SECURE_NO_DEPRECATE;_CRT_NONSTDC_NO_DEPRECATE;_CRT_SECURE_NO_WARNINGS;_SCL_SECURE_NO_DEPRECATE;_SCL_SECURE_NO_WARNINGS;HAVE_CONFIG_H;HAVE_DAKOTA_SURROGATES;HAVE_CONFIG_H;DISABLE_DAKOTA_CONFIG_H;BOOST_DISABLE_ASSERTS;HAVE_SYSTEM;DAKOTA_HAVE_HDF5;HAVE_;HAVE_SURFPACK;HAVE_DAKOTA_SURROGATES;DAKOTA_F90;HAVE_ACRO;DAKOTA_UTILIB;HAVE_APPROXNN;HAVE_ADAPTIVE_SAMPLING;HAVE_CONMIN;HAVE_DDACE;HAVE_DREAM;HAVE_FSUDACE;DAKOTA_HOPS;HAVE_JEGA;HAVE_NCSU;HAVE_NL2SOL;HAVE_NOMAD;HAVE_OPTPP;DAKOTA_OPTPP;HAVE_ROL;HAVE_PSUADE;HAVE_AMPL")

set(Dakota_INCLUDE_DIRS ${Dakota_INCLUDE_DIRS_TMP})

set(Dakota_LIBRARY_DIRS ${Dakota_LIB_DIRS_TMP})

# These are IMPORTED targets created by DakotaTargets.cmake
set(Dakota_LIBRARIES "dakota_util;dakota_surrogates;dakota_src;dakota_src_fortran;nidr;teuchosremainder;teuchosnumerics;teuchoscomm;teuchosparameterlist;teuchosparser;teuchoscore;pecos_util;pecos_src;lhs;lhs_mods;lhs_mod;dfftpack;sparsegrid;surfpack;surfpack;surfpack_fortran;utilib;colin;interfaces;scolib;3po;pebbl;tinyxml;approxnn;conmin;ddace;dream;fsudace;hopspack;jega;jega_fe;moga;soga;eutils;utilities;ncsuopt;cport;nomad;optpp;psuade;amplsolver")

# Not built in Dakota's CMake process
set(Dakota_EXTPROJ_LIBRARIES "")

# TPLs external to the build
set(Dakota_TPL_INCLUDE_DIRS "C:/jenkins/workspace/public_windows_builder/source/packages/external/json/single_include;C:/local/hdf5/1.10.4/include")

set(Dakota_TPL_LIBRARY_DIRS "")

include(CMakeFindDependencyMacro)
find_dependency(Boost 1.71.0 REQUIRED COMPONENTS filesystem;program_options;regex;serialization;system)

set(Dakota_TPL_LIBRARIES "C:/local/hdf5/1.10.4/lib/libhdf5_hl.lib;C:/local/hdf5/1.10.4/lib/libhdf5.lib;C:/local/hdf5/1.10.4/lib/libhdf5_hl_cpp.lib;C:/local/hdf5/1.10.4/lib/libhdf5_hl.lib;C:/local/hdf5/1.10.4/lib/libhdf5.lib;C:/local/hdf5/1.10.4/lib/libhdf5_cpp.lib;C:/local/hdf5/1.10.4/lib/libhdf5.lib;C:/local/hdf5/1.10.4/lib/libhdf5.lib;C:/local/hdf5/1.10.4/lib/libhdf5_cpp.lib;C:/local/hdf5/1.10.4/lib/libhdf5.lib;C:/local/lapack/3.10.1/static/lib/lapack.lib;C:/local/lapack/3.10.1/static/lib/blas.lib")
