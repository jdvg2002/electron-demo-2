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
  set(Dakota_INCLUDE_DIRS_TMP "/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/generated/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/trilinos;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/teuchos/remainder/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/trilinos/packages/teuchos/remainder/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/trilinos/packages/teuchos/core/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/teuchos/core/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/teuchos/numerics/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/teuchos/comm/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/teuchos/parameterlist/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/teuchos/parser/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/pecos;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/pecos/util/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/pecos/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/VPISparseGrid/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/surfpack;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/surfpack/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/src/util;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/src/surrogates;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/eigen3/include/eigen3;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/acro/packages;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/acro/packages/utilib;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/acro/packages/interfaces/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/acro/packages/scolib/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/acro/packages/utilib/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/acro/packages/colin/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/acro/packages/pebbl/src/bb;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/acro/packages/pebbl/src/comm;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/acro/packages/pebbl/src/misc;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/acro/packages/pebbl/src/pbb;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/acro/packages/pebbl/src/sched;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/acro/tpl/tinyxml;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/approxnn/include;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/DDACE;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/DDACE/include;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/dream;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/FSUDace;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/FSUDace;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/hopspack/src/src-shared;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/hopspack/src/src-shared;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/hopspack/src/src-citizens;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/hopspack/src/src-evaluator;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/hopspack/src/src-executor;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/hopspack/src/src-framework;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/hopspack/src/src-main;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/JEGA;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/JEGA/eddy;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/JEGA/eddy;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/JEGA/include;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/NOMAD/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/NOMAD/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/OPTPP/include;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/OPTPP/include;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/muq2;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/trilinos;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/trilinos/packages/rol/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/compatibility/teuchos/rcp;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/compatibility/teuchos/parameterlist;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/compatibility/teuchos/stacktrace;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/compatibility/teuchos/la;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/compatibility/teuchos/lapack;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/compatibility/teuchos/blas;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/vector;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/function;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/function/dynamic;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/function/boundconstraint;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/function/constraint;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/function/nlls;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/function/objective;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/function/operator;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/function/simopt;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/function/sketching;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/function/std;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/step;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/step/linesearch;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/step/trustregion;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/step/secant;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/step/krylov;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/step/bundle;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/step/augmentedlagrangian;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/step/moreauyosidapenalty;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/step/interiorpoint;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/step/nonlinearcg;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/step/fletcher;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/algorithm;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/status;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol/function;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol/function/distribution;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol/function/expectationquad;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/risk;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/risk/fdivergence;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/risk/spectral;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/error;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/regret;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/deviation;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol/function/randvarfunctional/probability;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol/function/progressivehedging;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol/algorithm;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol/algorithm/PrimalDual;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol/vector;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol/sampler;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol/sampler/SROM;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/sol/status;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/elementwise;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/utils;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/utils/function_bindings;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/zoo;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/rol/src/zoo/testproblems;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/teuchos/remainder/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/trilinos/packages/teuchos/remainder/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/trilinos/packages/teuchos/core/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/teuchos/core/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/teuchos/numerics/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/teuchos/comm/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/teuchos/parameterlist/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/trilinos/packages/teuchos/parser/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/PSUADE;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/ampl")
  # This won't work yet.  Since Dakota is in a build tree the
  # libraries are scattered, but the import doesn't know where they
  # are.
  set(Dakota_LIBRARY_DIRS_TMP "/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/trilinos/packages/teuchos/remainder/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/trilinos/packages/teuchos/core/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/trilinos/packages/teuchos/numerics/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/trilinos/packages/teuchos/comm/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/trilinos/packages/teuchos/parameterlist/src;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/build/packages/external/trilinos/packages/teuchos/parser/src")
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
set(Dakota_TPL_INCLUDE_DIRS "/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/json/single_include;/home/dakota-jenkins/jenkins/workspace/public_rhel8_builder/source/packages/external/pybind11/include;/projects/aue/cee/deploy/ed0e84f4/linux-rhel8-x86_64/gcc-12.3.0/anaconda3-2024.06-1-jxxucpn/lib/python3.12/site-packages/numpy/core/include;/projects/aue/cee/deploy/9d138342/linux-rhel8-x86_64/gcc-12.3.0/openmpi-4.1.6-hfp5vwq/include;/projects/aue/cee/deploy/9d138342/linux-rhel8-x86_64/gcc-12.3.0/openmpi-4.1.6-hfp5vwq/include;/usr/include")

set(Dakota_TPL_LIBRARY_DIRS "")

include(CMakeFindDependencyMacro)
find_dependency(Boost 1.82.0 REQUIRED COMPONENTS filesystem;program_options;regex;serialization;system)

set(Dakota_TPL_LIBRARIES "/projects/aue/cee/deploy/9d138342/linux-rhel8-x86_64/gcc-12.3.0/openmpi-4.1.6-hfp5vwq/lib/libmpi.so;/usr/lib64/libhdf5_hl.so;/usr/lib64/libhdf5.so;/usr/lib64/libhdf5_hl_cpp.so;/usr/lib64/libhdf5_hl.so;/usr/lib64/libhdf5.so;/usr/lib64/libhdf5_cpp.so;/usr/lib64/libhdf5.so;/usr/lib64/libhdf5.so;/usr/lib64/libhdf5_cpp.so;/usr/lib64/libhdf5.so;/usr/lib64/liblapack.so;/usr/lib64/libblas.so")