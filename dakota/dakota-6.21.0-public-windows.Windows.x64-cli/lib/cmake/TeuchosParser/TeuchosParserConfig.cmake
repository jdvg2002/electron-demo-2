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
# CMake variable for use by Trilinos/TeuchosParser clients.
#
# Do not edit: This file was generated automatically by CMake.
#
##############################################################################


# Include guard
IF (TeuchosParser_CONFIG_INCLUDED)
  RETURN()
ENDIF()
SET(TeuchosParser_CONFIG_INCLUDED TRUE)

# Make sure CMAKE_CURRENT_LIST_DIR is usable
IF (NOT DEFINED CMAKE_CURRENT_LIST_DIR)
  GET_FILENAME_COMPONENT(_THIS_SCRIPT_PATH ${CMAKE_CURRENT_LIST_FILE} PATH)
  SET(CMAKE_CURRENT_LIST_DIR ${_THIS_SCRIPT_PATH})
ENDIF()


## ---------------------------------------------------------------------------
## Compilers used by Trilinos/TeuchosParser build
## ---------------------------------------------------------------------------

SET(TeuchosParser_CXX_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio/2019/Professional/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/cl.exe")

SET(TeuchosParser_C_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio/2019/Professional/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/cl.exe")

SET(TeuchosParser_FORTRAN_COMPILER "C:/Program Files (x86)/Intel/oneAPI/compiler/2024.2/bin/ifort.exe")


## ---------------------------------------------------------------------------
## Compiler flags used by Trilinos/TeuchosParser build
## ---------------------------------------------------------------------------

## Give the build type
SET(TeuchosParser_CMAKE_BUILD_TYPE "Release")

## Set compiler flags, including those determined by build type
SET(TeuchosParser_CXX_FLAGS "/DWIN32 /D_WINDOWS /GR /EHsc ")

SET(TeuchosParser_C_FLAGS "/DWIN32 /D_WINDOWS ")

SET(TeuchosParser_FORTRAN_FLAGS " ")

## Extra link flags (e.g., specification of fortran libraries)
SET(TeuchosParser_EXTRA_LD_FLAGS "")

## This is the command-line entry used for setting rpaths. In a build
## with static libraries it will be empty.
SET(TeuchosParser_SHARED_LIB_RPATH_COMMAND "")
SET(TeuchosParser_BUILD_SHARED_LIBS "FALSE")

SET(TeuchosParser_LINKER C:/Program Files (x86)/Microsoft Visual Studio/2019/Professional/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/link.exe)
SET(TeuchosParser_AR C:/Program Files (x86)/Microsoft Visual Studio/2019/Professional/VC/Tools/MSVC/14.29.30133/bin/Hostx64/x64/lib.exe)

## ---------------------------------------------------------------------------
## Set library specifications and paths
## ---------------------------------------------------------------------------

## Base install location (if not in the build tree)
SET(TeuchosParser_INSTALL_DIR "C:/Program Files/Dakota")

## List of package include dirs
SET(TeuchosParser_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../../../include")

## List of package library paths
SET(TeuchosParser_LIBRARY_DIRS "${CMAKE_CURRENT_LIST_DIR}/../../../lib")

## List of package libraries
SET(TeuchosParser_LIBRARIES "teuchosparser;teuchoscore")

## Specification of directories for TPL headers
SET(TeuchosParser_TPL_INCLUDE_DIRS "")

## Specification of directories for TPL libraries
SET(TeuchosParser_TPL_LIBRARY_DIRS "")

## List of required TPLs
SET(TeuchosParser_TPL_LIBRARIES "")

## ---------------------------------------------------------------------------
## MPI specific variables
##   These variables are provided to make it easier to get the mpi libraries
##   and includes on systems that do not use the mpi wrappers for compiling
## ---------------------------------------------------------------------------

SET(TeuchosParser_MPI_LIBRARIES "")
SET(TeuchosParser_MPI_LIBRARY_DIRS "")
SET(TeuchosParser_MPI_INCLUDE_DIRS "")
SET(TeuchosParser_MPI_EXEC "")
SET(TeuchosParser_MPI_EXEC_MAX_NUMPROCS "")
SET(TeuchosParser_MPI_EXEC_NUMPROCS_FLAG "")

## ---------------------------------------------------------------------------
## Set useful general variables
## ---------------------------------------------------------------------------

## The packages enabled for this project
SET(TeuchosParser_PACKAGE_LIST "TeuchosParser;TeuchosCore")

## The TPLs enabled for this project
SET(TeuchosParser_TPL_LIST "")


# Include configuration of dependent packages
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/../TeuchosCore/TeuchosCoreConfig.cmake")

# Import TeuchosParser targets
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/TeuchosParserTargets.cmake")
