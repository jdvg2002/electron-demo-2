# @HEADER
# ************************************************************************
#
#            TriBITS: Tribal Build, Integrate, and Test System
#                    Copyright 2013 Sandia Corporation
#
#
# Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
# the U.S. Government retains certain rights in this software.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# 1. Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in the
# documentation and/or other materials provided with the distribution.
#
# 3. Neither the name of the Corporation nor the names of the
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# ************************************************************************
# @HEADER

##############################################################################
#
# CMake variable for use by Trilinos/ROL clients.
#
# Do not edit: This file was generated automatically by CMake.
#
##############################################################################


# Include guard
IF (ROL_CONFIG_INCLUDED)
  RETURN()
ENDIF()
SET(ROL_CONFIG_INCLUDED TRUE)

# Make sure CMAKE_CURRENT_LIST_DIR is usable
IF (NOT DEFINED CMAKE_CURRENT_LIST_DIR)
  GET_FILENAME_COMPONENT(_THIS_SCRIPT_PATH ${CMAKE_CURRENT_LIST_FILE} PATH)
  SET(CMAKE_CURRENT_LIST_DIR ${_THIS_SCRIPT_PATH})
ENDIF()


## ---------------------------------------------------------------------------
## Compilers used by Trilinos/ROL build
## ---------------------------------------------------------------------------

SET(ROL_CXX_COMPILER "/Library/Developer/CommandLineTools/usr/bin/c++")

SET(ROL_C_COMPILER "/Library/Developer/CommandLineTools/usr/bin/cc")

SET(ROL_FORTRAN_COMPILER "/usr/local/bin/gfortran")


## ---------------------------------------------------------------------------
## Compiler flags used by Trilinos/ROL build
## ---------------------------------------------------------------------------

## Give the build type
SET(ROL_CMAKE_BUILD_TYPE "Release")

## Set compiler flags, including those determined by build type
SET(ROL_CXX_FLAGS " ")

SET(ROL_C_FLAGS " ")

SET(ROL_FORTRAN_FLAGS " ")

## Extra link flags (e.g., specification of fortran libraries)
SET(ROL_EXTRA_LD_FLAGS "")

## This is the command-line entry used for setting rpaths. In a build
## with static libraries it will be empty.
SET(ROL_SHARED_LIB_RPATH_COMMAND "-Wl,-rpath,/usr/local/lib")
SET(ROL_BUILD_SHARED_LIBS "TRUE")

SET(ROL_LINKER /Library/Developer/CommandLineTools/usr/bin/ld)
SET(ROL_AR /Library/Developer/CommandLineTools/usr/bin/ar)

## ---------------------------------------------------------------------------
## Set library specifications and paths
## ---------------------------------------------------------------------------

## Base install location (if not in the build tree)
SET(ROL_INSTALL_DIR "/usr/local")

## List of package include dirs
SET(ROL_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../../../include")

## List of package library paths
SET(ROL_LIBRARY_DIRS "${CMAKE_CURRENT_LIST_DIR}/../../../lib")

## List of package libraries
SET(ROL_LIBRARIES "rol;teuchosremainder;teuchosnumerics;teuchoscomm;teuchosparameterlist;teuchosparser;teuchoscore")

## Specification of directories for TPL headers
SET(ROL_TPL_INCLUDE_DIRS "")

## Specification of directories for TPL libraries
SET(ROL_TPL_LIBRARY_DIRS "")

## List of required TPLs
SET(ROL_TPL_LIBRARIES "/usr/local/opt/spack/darwin-monterey-ivybridge/apple-clang-14.0.0/netlib-lapack-3.10.1-gbahfupur2vwfpq6qvwd6z2nwszounpm/lib/liblapack.dylib;/usr/local/opt/spack/darwin-monterey-ivybridge/apple-clang-14.0.0/netlib-lapack-3.10.1-gbahfupur2vwfpq6qvwd6z2nwszounpm/lib/libblas.dylib")

## ---------------------------------------------------------------------------
## MPI specific variables
##   These variables are provided to make it easier to get the mpi libraries
##   and includes on systems that do not use the mpi wrappers for compiling
## ---------------------------------------------------------------------------

SET(ROL_MPI_LIBRARIES "")
SET(ROL_MPI_LIBRARY_DIRS "")
SET(ROL_MPI_INCLUDE_DIRS "")
SET(ROL_MPI_EXEC "")
SET(ROL_MPI_EXEC_MAX_NUMPROCS "")
SET(ROL_MPI_EXEC_NUMPROCS_FLAG "")

## ---------------------------------------------------------------------------
## Set useful general variables
## ---------------------------------------------------------------------------

## The packages enabled for this project
SET(ROL_PACKAGE_LIST "ROL;Teuchos;TeuchosRemainder;TeuchosNumerics;TeuchosComm;TeuchosParameterList;TeuchosParser;TeuchosCore")

## The TPLs enabled for this project
SET(ROL_TPL_LIST "LAPACK;BLAS")


# Include configuration of dependent packages
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/../Teuchos/TeuchosConfig.cmake")
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/../TeuchosRemainder/TeuchosRemainderConfig.cmake")
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/../TeuchosNumerics/TeuchosNumericsConfig.cmake")
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/../TeuchosComm/TeuchosCommConfig.cmake")
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/../TeuchosParameterList/TeuchosParameterListConfig.cmake")
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/../TeuchosParser/TeuchosParserConfig.cmake")
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/../TeuchosCore/TeuchosCoreConfig.cmake")

# Import ROL targets
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/ROLTargets.cmake")
