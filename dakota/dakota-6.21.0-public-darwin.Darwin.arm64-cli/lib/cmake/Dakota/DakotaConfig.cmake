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

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

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
  set(Dakota_INCLUDE_DIRS_TMP "/opt/jenkins/workspace/public_darwin_builder/build/generated/src;/opt/jenkins/workspace/public_darwin_builder/build;/opt/jenkins/workspace/public_darwin_builder/build/src;/opt/jenkins/workspace/public_darwin_builder/source/src;/opt/jenkins/workspace/public_darwin_builder/source/packages;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/trilinos;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/teuchos/remainder/src;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/trilinos/packages/teuchos/remainder/src;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/trilinos/packages/teuchos/core/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/teuchos/core/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/teuchos/numerics/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/teuchos/comm/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/teuchos/parameterlist/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/teuchos/parser/src;/opt/jenkins/workspace/public_darwin_builder/build/packages/pecos;/opt/jenkins/workspace/public_darwin_builder/source/packages/pecos/util/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/pecos/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/VPISparseGrid/src;/opt/jenkins/workspace/public_darwin_builder/build/packages/surfpack;/opt/jenkins/workspace/public_darwin_builder/source/packages/surfpack/src;/opt/jenkins/workspace/public_darwin_builder/source/src/util;/opt/jenkins/workspace/public_darwin_builder/source/src/surrogates;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/eigen3/include/eigen3;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/acro/packages;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/acro/packages/utilib;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/acro/packages/interfaces/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/acro/packages/scolib/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/acro/packages/utilib/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/acro/packages/colin/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/acro/packages/pebbl/src/bb;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/acro/packages/pebbl/src/comm;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/acro/packages/pebbl/src/misc;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/acro/packages/pebbl/src/pbb;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/acro/packages/pebbl/src/sched;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/acro/tpl/tinyxml;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/approxnn/include;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/DDACE;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/DDACE/include;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/dream;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/FSUDace;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/FSUDace;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/hopspack/src/src-shared;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/hopspack/src/src-shared;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/hopspack/src/src-citizens;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/hopspack/src/src-evaluator;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/hopspack/src/src-executor;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/hopspack/src/src-framework;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/hopspack/src/src-main;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/JEGA;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/JEGA/eddy;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/JEGA/eddy;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/JEGA/include;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/NOMAD/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/NOMAD/src;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/OPTPP/include;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/OPTPP/include;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/muq2;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/trilinos;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/trilinos/packages/rol/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/compatibility/teuchos/rcp;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/compatibility/teuchos/parameterlist;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/compatibility/teuchos/stacktrace;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/compatibility/teuchos/la;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/compatibility/teuchos/lapack;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/compatibility/teuchos/blas;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/vector;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/function;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/function/dynamic;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/function/boundconstraint;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/function/constraint;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/function/nlls;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/function/objective;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/function/operator;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/function/simopt;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/function/sketching;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/function/std;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/step;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/step/linesearch;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/step/trustregion;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/step/secant;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/step/krylov;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/step/bundle;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/step/augmentedlagrangian;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/step/moreauyosidapenalty;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/step/interiorpoint;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/step/nonlinearcg;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/step/fletcher;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/algorithm;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/status;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol/function;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol/function/distribution;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol/function/expectationquad;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/risk;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/risk/fdivergence;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/risk/spectral;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/error;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/regret;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/deviation;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/probability;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol/function/progressivehedging;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol/algorithm;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol/algorithm/PrimalDual;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol/vector;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol/sampler;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol/sampler/SROM;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/sol/status;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/elementwise;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/utils;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/utils/function_bindings;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/zoo;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/rol/src/zoo/testproblems;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/teuchos/remainder/src;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/trilinos/packages/teuchos/remainder/src;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/trilinos/packages/teuchos/core/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/teuchos/core/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/teuchos/numerics/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/teuchos/comm/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/teuchos/parameterlist/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/trilinos/packages/teuchos/parser/src;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/PSUADE;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/ampl")
  # This won't work yet.  Since Dakota is in a build tree the
  # libraries are scattered, but the import doesn't know where they
  # are.
  set(Dakota_LIBRARY_DIRS_TMP "/opt/jenkins/workspace/public_darwin_builder/build/packages/external/trilinos/packages/teuchos/remainder/src;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/trilinos/packages/teuchos/core/src;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/trilinos/packages/teuchos/numerics/src;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/trilinos/packages/teuchos/comm/src;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/trilinos/packages/teuchos/parameterlist/src;/opt/jenkins/workspace/public_darwin_builder/build/packages/external/trilinos/packages/teuchos/parser/src")
else()
  set_and_check(Dakota_INCLUDE_DIRS_TMP "${PACKAGE_PREFIX_DIR}/include")
  set_and_check(Dakota_LIB_DIRS_TMP "${PACKAGE_PREFIX_DIR}/lib")
endif()

# Variables intended for use by other projects

set_and_check(Dakota_DIR ${DAKOTA_CMAKE_DIR})

# TODO: reference in src vs bin
set(Dakota_EXECUTABLE dakota)


set(Dakota_DEFINES "HAVE_CONFIG_H;HAVE_DAKOTA_SURROGATES;HAVE_CONFIG_H;DISABLE_DAKOTA_CONFIG_H;BOOST_DISABLE_ASSERTS;HAVE_UNISTD_H;HAVE_SYSTEM;HAVE_WORKING_FORK;HAVE_WORKING_VFORK;HAVE_SYS_WAIT_H;DAKOTA_PYBIND11;DAKOTA_PYTHON_NUMPY;DAKOTA_HAVE_MPI;DAKOTA_HAVE_HDF5;HAVE_;HAVE_SURFPACK;HAVE_DAKOTA_SURROGATES;HAVE_DAKOTA_PYTHON_SURROGATES;DAKOTA_F90;HAVE_ACRO;DAKOTA_UTILIB;HAVE_APPROXNN;HAVE_ADAPTIVE_SAMPLING;HAVE_CONMIN;HAVE_DDACE;HAVE_DREAM;HAVE_FSUDACE;DAKOTA_HOPS;HAVE_JEGA;HAVE_NCSU;HAVE_NL2SOL;HAVE_NOMAD;HAVE_OPTPP;DAKOTA_OPTPP;HAVE_MUQ;HAVE_ROL;HAVE_PSUADE;HAVE_AMPL")

set(Dakota_INCLUDE_DIRS ${Dakota_INCLUDE_DIRS_TMP})

set(Dakota_LIBRARY_DIRS ${Dakota_LIB_DIRS_TMP})

# These are IMPORTED targets created by DakotaTargets.cmake
set(Dakota_LIBRARIES "dakota_util;dakota_surrogates;dakota_src;dakota_src_fortran;nidr;teuchosremainder;teuchosnumerics;teuchoscomm;teuchosparameterlist;teuchosparser;teuchoscore;pecos_util;pecos_src;lhs;lhs_mods;lhs_mod;dfftpack;sparsegrid;surfpack;surfpack;surfpack_fortran;utilib;colin;interfaces;scolib;3po;pebbl;tinyxml;approxnn;conmin;ddace;dream;fsudace;hopspack;jega;jega_fe;moga;soga;eutils;utilities;ncsuopt;cport;nomad;optpp;muqUtilities;muqModeling;muqSamplingAlgorithms;psuade;amplsolver")

# Not built in Dakota's CMake process
set(Dakota_EXTPROJ_LIBRARIES "")

# TPLs external to the build
set(Dakota_TPL_INCLUDE_DIRS "/opt/jenkins/workspace/public_darwin_builder/source/packages/external/json/single_include;/opt/jenkins/workspace/public_darwin_builder/source/packages/external/pybind11/include;/opt/spack/darwin-ventura-m1/apple-clang-15.0.0/py-numpy-1.24.4-qojtcembpmghkuul2makjsawwjlwdxbb/lib/python3.8/site-packages/numpy/core/include;/opt/spack/darwin-ventura-m1/apple-clang-15.0.0/openmpi-4.1.6-i75qncn7vtb3savyytodm5ksdwev633l/include;/opt/spack/darwin-ventura-m1/apple-clang-15.0.0/openmpi-4.1.6-i75qncn7vtb3savyytodm5ksdwev633l/include;/opt/spack/darwin-ventura-m1/apple-clang-15.0.0/hdf5-1.10.4-ejc3e7ox7mtdpcm2z2gggmarsp7bwhhy/include")

set(Dakota_TPL_LIBRARY_DIRS "")

include(CMakeFindDependencyMacro)
find_dependency(Boost 1.71.0 REQUIRED COMPONENTS filesystem;program_options;regex;serialization;system)

set(Dakota_TPL_LIBRARIES "/opt/spack/darwin-ventura-m1/apple-clang-15.0.0/openmpi-4.1.6-i75qncn7vtb3savyytodm5ksdwev633l/lib/libmpi.dylib;hdf5::hdf5_hl-shared;hdf5::hdf5_hl_cpp-shared;hdf5::hdf5-shared;hdf5::hdf5_cpp-shared;/opt/spack/darwin-ventura-m1/apple-clang-15.0.0/netlib-lapack-3.10.1-u2yzn46m35ncqgdaesem7nbibap4atbq/lib/liblapack.dylib;/opt/spack/darwin-ventura-m1/apple-clang-15.0.0/netlib-lapack-3.10.1-u2yzn46m35ncqgdaesem7nbibap4atbq/lib/libblas.dylib")
