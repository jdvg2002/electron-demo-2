# @HEADER
# ************************************************************************
#
#            TriBITS: Tribal Build, Integrate, and Test System
#                    Copyright 2013 Sandia Corporation
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

#############################################
#
# TriBITS platform-independent test driver.
#
#############################################

MESSAGE("")
MESSAGE("*******************************")
MESSAGE("*** TribitsCTestDriverCore ***")
MESSAGE("*******************************")
MESSAGE("")


CMAKE_MINIMUM_REQUIRED(VERSION 3.10.0 FATAL_ERROR)

SET(THIS_CMAKE_CURRENT_LIST_DIR "${CMAKE_CURRENT_LIST_DIR}")

#
# Get the basic variables that define the project and the build
#

#
# Set TRIBITS_PROJECT_ROOT
#
# We must locate the source code root directory before processing this
# file. Once the root directory is located, we can make good guesses at other
# properties, but this file contains code that is executed in a CTest -S
# script that is always executed outside of the context of the project's CMake
# build.
#
# We allow the environment variable TRIBITS_PROJECT_ROOT to locate the
# root directory. If the variable doesn't exist, we fall back on the
# default convention.
#MESSAGE("TRIBITS_PROJECT_ROOT (before env) = '${TRIBITS_PROJECT_ROOT}'")
IF (NOT TRIBITS_PROJECT_ROOT)
  SET(TRIBITS_PROJECT_ROOT "$ENV{TRIBITS_PROJECT_ROOT}")
ENDIF()
#MESSAGE("TRIBITS_PROJECT_ROOT (after env) = '${TRIBITS_PROJECT_ROOT}'")
IF (NOT TRIBITS_PROJECT_ROOT)
  # Fall back on the default convention, in which this file is located at:
  #   <root>/cmake/tribits/ctest.
  GET_FILENAME_COMPONENT(CMAKE_CURRENT_LIST_DIR ${CMAKE_CURRENT_LIST_FILE} PATH)
  SET(TRIBITS_PROJECT_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../..")
ENDIF()
GET_FILENAME_COMPONENT(TRIBITS_PROJECT_ROOT "${TRIBITS_PROJECT_ROOT}" ABSOLUTE)
MESSAGE("TRIBITS_PROJECT_ROOT = '${TRIBITS_PROJECT_ROOT}'")

#
# Read in PROJECT_NAME
#
# Assert that the ProjectName.cmake file exists.
SET(TRIBITS_PROJECT_NAME_INCLUDE "${TRIBITS_PROJECT_ROOT}/ProjectName.cmake")
IF(NOT EXISTS "${TRIBITS_PROJECT_NAME_INCLUDE}")
  MESSAGE(FATAL_ERROR
    "Could not locate ProjectName.cmake.\n"
    "  TRIBITS_PROJECT_ROOT = ${TRIBITS_PROJECT_ROOT}\n"
    "  Set the TRIBITS_PROJECT_ROOT environment variable "
    "to point at the source root.")
ENDIF()
# Include the ProjectName.cmake file and get PROJECT_NAME
INCLUDE(${TRIBITS_PROJECT_NAME_INCLUDE})
IF(NOT PROJECT_NAME)
  MESSAGE(FATAL_ERROR
    "The project name has not been set!"
    "  It should be set in ${TRIBITS_PROJECT_ROOT}/ProjectName.cmake.")
ENDIF()
MESSAGE("PROJECT_NAME = ${PROJECT_NAME}")

#
# Set ${PROJECT_NAME}_TRIBITS_DIR
#
IF (NOT "$ENV{${PROJECT_NAME}_TRIBITS_DIR}" STREQUAL "")
  SET(${PROJECT_NAME}_TRIBITS_DIR "$ENV{${PROJECT_NAME}_TRIBITS_DIR}")
ENDIF()
IF ("${${PROJECT_NAME}_TRIBITS_DIR}" STREQUAL "")
  SET(${PROJECT_NAME}_TRIBITS_DIR "${TRIBITS_PROJECT_ROOT}/cmake/tribits")
ENDIF()
MESSAGE("${PROJECT_NAME}_TRIBITS_DIR = ${${PROJECT_NAME}_TRIBITS_DIR}")
# ToDo: If you are really going to allow setting a different
# ${PROJECT_NAME}_TRIBITS_DIR from where this module lives, then you need to
# split off the implementation of this module into a separate
# TribitsCTestDriverCoreImpl.cmake module and then include that based on the
# set ${PROJECT_NAME}_TRIBITS_DIR var.

#
# Set default for CTEST_SOURCE_DIRECTORY
#
IF ("${CTEST_SOURCE_DIRECTORY}" STREQUAL "")
  MESSAGE("Set default for CTEST_SOURCE_DIRECTORY to TRIBITS_PROJECT_ROOT='TRIBITS_PROJECT_ROOT='${TRIBITS_PROJECT_ROOT}'")
  SET(CTEST_SOURCE_DIRECTORY ${TRIBITS_PROJECT_ROOT})
ENDIF()

#
# Set default for CTEST_BINARY_DIRECTORY
#
IF ("${CTEST_BINARY_DIRECTORY}" STREQUAL "")
  MESSAGE("Set defualt for CTEST_BINARY_DIRECTORY to $PWD/BUILD='$ENV{PWD}/BUILD'")
  SET(CTEST_BINARY_DIRECTORY $ENV{PWD}/BUILD)
ENDIF()

#
# Set CMAKE_MODULE_PATH
#
SET( CMAKE_MODULE_PATH
  "${TRIBITS_PROJECT_ROOT}"
  "${TRIBITS_PROJECT_ROOT}/cmake"
  "${${PROJECT_NAME}_TRIBITS_DIR}/core/utils"
  "${${PROJECT_NAME}_TRIBITS_DIR}/core/package_arch"
  "${${PROJECT_NAME}_TRIBITS_DIR}/ci_support"
  )

INCLUDE(TribitsConstants)
TRIBITS_ASESRT_MINIMUM_CMAKE_VERSION()
INCLUDE(TribitsCMakePolicies)

INCLUDE(Split)
INCLUDE(PrintVar)
INCLUDE(MultilineSet)
INCLUDE(SetDefaultAndFromEnv)
INCLUDE(AssertDefined)
INCLUDE(AppendSet)
INCLUDE(AppendStringVar)
INCLUDE(TribitsGlobalMacros)
INCLUDE(TribitsStripCommentsFromCMakeCacheFile)

# Need to include the project's version file to get some Git and CDash
# settings specific to the given version
TRIBITS_PROJECT_READ_VERSION_FILE(${TRIBITS_PROJECT_ROOT})

INCLUDE(TribitsFindPythonInterp)
TRIBITS_FIND_PYTHON()
MESSAGE("PYTHON_EXECUTABLE = ${PYTHON_EXECUTABLE}")

#############################
### Do some initial setup ###
#############################


# Get the host type

IF(WIN32)
  SET(HOST_TYPE $ENV{OS})
ELSE()
  FIND_PROGRAM(UNAME_EXE NAMES uname)
  EXECUTE_PROCESS(
    COMMAND ${UNAME_EXE}
    OUTPUT_VARIABLE HOST_TYPE
    OUTPUT_STRIP_TRAILING_WHITESPACE
    )
ENDIF()


# Find git

FIND_PACKAGE(Git REQUIRED)


# Find gitdist

SET(GITDIST_EXE "${${PROJECT_NAME}_TRIBITS_DIR}/python_utils/gitdist")


# Get the host name

SITE_NAME(CTEST_SITE_DEFAULT)


# Get helper functions

INCLUDE(${CMAKE_CURRENT_LIST_DIR}/TribitsCTestDriverCoreHelpers.cmake)


#
# @FUNCTION: TRIBITS_CTEST_DRIVER()
#
# Universal platform-independent CTest/CDash driver function for CTest -S
# scripts for TriBITS projects
#
# Usage (in ``<script>.cmake`` file run with ``CTest -S <script>.cmake``)::
#
#   # Set some basic vars and include TRIBITS_CTEST_DRIVER()
#   SET(TRIBITS_PROJECT_ROOT "${CMAKE_CURRENT_LIST_DIR}/../../../..")
#   INLCUDE(
#     "${TRIBITS_PROJECT_ROOT}/cmake/tribits/ctest_driver/TribitsCTestDriverCore.cmake")
#
#   # Set variables that define this build
#   SET(CTEST_BUILD_NAME <buildName>)
#   SET(CTEST_TEST_TYPE Nightly)
#   SET(CTEST_DASHBOARD_ROOT PWD)
#   SET(MPI_EXEC_MAX_NUMPROCS 16)
#   SET(CTEST_BUILD_FLAGS "-j16")
#   SET(CTEST_PARALLEL_LEVEL 16)
#   SET(${PROJECT_NAME}_REPOSITORY_LOCATION <git-url-to-the-base-git-repo>)
#   [... Set other vars ...]
#
#   # Call the driver script to handle the rest
#   TRIBITS_CTEST_DRIVER()
#
# This platform independent code is used in CTest -S scripts to drive the
# testing process for submitting to CDash for a TriBITS project.
#
# This function drives the following operations:
# 
# 1) **Clone or update all source version control (VC) repos** (Only if
#    `CTEST_DO_UPDATES`_ ``= TRUE``, otherwise existing source tree pointed to
#    by `CTEST_SOURCE_DIRECTORY`_ must already be in place).  Submit "Update"
#    data to CDash.
#
# 2) **Empty the build directory** pointed to by `CTEST_BINARY_DIRECTORY`_
#    (only if `CTEST_DO_NEW_START`_ ``= TRUE`` and
#    `CTEST_START_WITH_EMPTY_BINARY_DIRECTORY`_ ``= TRUE``).
#
# 3) **Generate the file <Project>PackageDependencies.xml** which is needed to
#    determine which packages need to be tested based on changes (only if
#    `CTEST_GENERATE_OUTER_DEPS_XML_OUTPUT_FILE`_ ``= TRUE``).
#
# 4) **Generate the file CDashSubprojectDependencies.xml** (only if
#    `CTEST_SUBMIT_CDASH_SUBPROJECTS_DEPS_FILE`_ ``= TRUE``).  Submit file to
#    CDash to inform of subproject structure and email addresses.
#
# 5) **Determine the set of packages to be tested**.  If
#    `CTEST_ENABLE_MODIFIED_PACKAGES_ONLY`_ ``= TRUE``, then this is
#    determined by the files that have changed since the last build and
#    therefore what TriBITS packages need to be tested (can only be used if
#    and the underlying source tree repos must are git repos).  Otherwise, one
#    can directly set `${PROJECT_NAME}_PACKAGES`_ and other variables (see
#    `Determining What Packages Get Tested (TRIBITS_CTEST_DRIVER())`_).
#
# 6) **Start a new dashboard calling ctest_start()** which defines a new CDash
#    build (with a unique Build Stamp) (only if `CTEST_DO_NEW_START`_ ``=
#    TRUE``).
#
# 7) **Configure the selected packages to be tested** in the build directory
#    pointed to by `CTEST_BINARY_DIRECTORY`_.  Submit "Configure" and "Notes"
#    data to CDash (only if `CTEST_DO_CONFIGURE`_ ``= TRUE``).
#
# 8) **Build configured packages and the enabled package tests**.  Submit
#    "Build" data to CDash (only if `CTEST_DO_BUILD`_ ``= TRUE``).
#
# 9) **Install the configured and build targets**.  Submit
#    "Build" install data to CDash (only if `CTEST_DO_INSTALL`_ ``= TRUE``).
#
# 10) **Run enabled tests for the configured packages** (only if
#     `CTEST_DO_TEST`_ = ``TRUE``).  (Also, this will generate coverage data if
#     `CTEST_DO_COVERAGE_TESTING`_ ``= TRUE``).  Submit "Test" data to CDash.
#
# 11) **Collect coverage results from tests already run** (only if
#     `CTEST_DO_COVERAGE_TESTING`_ ``= TRUE``).  Submit "Coverage" data to
#     CDash.
#
# 12) **Run dynamic analysis testing on defined test suite** (e.g. run
#     ``valgrind`` with each of the test commands (only if
#     `CTEST_DO_MEMORY_TESTING`_ ``= TRUE``).  Submit "MemCheck" data to CDash.
#
# After each of these steps, results are submitted to CDash if
# `CTEST_DO_SUBMIT`_ ``= TRUE`` and otherwise no data is submitted to any
# CDash site (which is good for local debugging of CTest -S driver scripts).
# For the package-by-package mode these steps 7-11 for configure, build, and
# running tests shown above are actually done in a loop package-by-package
# with submits for each package to be tested.  For the all-at-once mode, these
# steps are done all at once for the selected packages to be tested and
# results are submitted to CDash all-at-once for all packages together (see
# `All-at-once versus package-by-package mode (TRIBITS_CTEST_DRIVER())`_).
#
# For context for how this function is used, see:
#
# * `TriBITS CTest/CDash Driver`_
# * `How to submit testing results to a CDash site`_
#
# Also note that this function executes `Reduced Package Dependency
# Processing`_ so all of the files described in that process are read in while
# this function runs.  This processing is needed to determine the TriBITS
# package dependency graph and to determine the set of packages to be enabled
# or disabled when determining the set of packages to be tested.
#
# *Sections:*
#
# * `List of all variables (TRIBITS_CTEST_DRIVER())`_
# * `Setting variables (TRIBITS_CTEST_DRIVER())`_
# * `Source and Binary Directory Locations (TRIBITS_CTEST_DRIVER())`_
# * `Determining What Packages Get Tested (TRIBITS_CTEST_DRIVER())`_
# * `Setting variables in the inner CMake configure (TRIBITS_CTEST_DRIVER())`_
# * `Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_
# * `Determining how the results are displayed on CDash (TRIBITS_CTEST_DRIVER())`_
# * `Specifying where the results go to CDash (TRIBITS_CTEST_DRIVER())`_
# * `Determining what TriBITS repositories are included (TRIBITS_CTEST_DRIVER())`_
# * `All-at-once versus package-by-package mode (TRIBITS_CTEST_DRIVER())`_
# * `Mutiple ctest -S invocations (TRIBITS_CTEST_DRIVER())`_
# * `Repository Updates (TRIBITS_CTEST_DRIVER())`_
# * `Other CTest Driver options (TRIBITS_CTEST_DRIVER())`_
# * `Return value (TRIBITS_CTEST_DRIVER())`_
#
# .. _List of all variables (TRIBITS_CTEST_DRIVER()):
#
# The following is an alphabetical listing of all of the variables that impact
# the behavior of the function ``TRIBITS_CTEST_DRIVER()`` with links to their
# more detailed documentation:
#
# * ``${PROJECT_NAME}_ADDITIONAL_PACKAGES`` (`Determining What Packages Get Tested (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_BRANCH`` (`Repository Updates (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_CTEST_DO_ALL_AT_ONCE`` (`All-at-once versus package-by-package mode (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_DISABLE_ENABLED_FORWARD_DEP_PACKAGES`` (`Determining What Packages Get Tested (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_ENABLE_ALL_FORWARD_DEP_PACKAGES`` (`Determining What Packages Get Tested (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_ENABLE_DEVELOPMENT_MODE``
# * ``${PROJECT_NAME}_ENABLE_KNOWN_EXTERNAL_REPOS_TYPE`` (`Determining what TriBITS repositories are included (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_ENABLE_SECONDARY_TESTED_CODE`` (`Determining What Packages Get Tested (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_EXCLUDE_PACKAGES`` (`Determining What Packages Get Tested (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_EXTRAREPOS_BRANCH`` (`Repository Updates (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_EXTRAREPOS_FILE`` (`Determining what TriBITS repositories are included (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_EXTRA_REPOSITORIES`` (`Determining what TriBITS repositories are included (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_GENERATE_VERSION_DATE_FILES`` (`Setting variables in the inner CMake configure (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_INNER_ENABLE_TESTS`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_PACKAGES`` (`Determining What Packages Get Tested (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_PRE_REPOSITORIES`` (`Determining what TriBITS repositories are included (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_REPOSITORY_BRANCH`` (`Repository Updates (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_REPOSITORY_LOCATION`` (`Repository Updates (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_SKIP_CTEST_ADD_TEST`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_TESTING_TRACK`` (`Determining how the results are displayed on CDash (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_TRIBITS_DIR`` (`Source and Binary Directory Locations (TRIBITS_CTEST_DRIVER())`_)
# * ``${PROJECT_NAME}_VERBOSE_CONFIGURE`` (`Other CTest Driver options (TRIBITS_CTEST_DRIVER())`_)
# * ``COMPILER_VERSION`` (`Determining how the results are displayed on CDash (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_BINARY_DIRECTORY`` (`Source and Binary Directory Locations (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_BUILD_FLAGS`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_BUILD_NAME`` (`Determining how the results are displayed on CDash (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_CMAKE_GENERATOR`` (`Other CTest Driver options (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_CONFIGURATION_UNIT_TESTING`` (`Other CTest Driver options (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_COVERAGE_COMMAND`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_DASHBOARD_ROOT`` (`Source and Binary Directory Locations (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_DO_BUILD`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_DO_CONFIGURE`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_DO_COVERAGE_TESTING`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_DO_INSTALL`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_DO_MEMORY_TESTING`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_DO_NEW_START`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_DO_SUBMIT`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_DO_TEST`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_DO_UPDATES`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_ENABLE_MODIFIED_PACKAGES_ONLY`` (`Determining What Packages Get Tested (TRIBITS_CTEST_DRIVER())`_) 
# * ``CTEST_EXPLICITLY_ENABLE_IMPLICITLY_ENABLED_PACKAGES`` (`Determining What Packages Get Tested (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_GENERATE_OUTER_DEPS_XML_OUTPUT_FILE`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_MEMORYCHECK_COMMAND_OPTIONS`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_MEMORYCHECK_COMMAND`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_PARALLEL_LEVEL`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_SITE`` (`Determining how the results are displayed on CDash (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_SOURCE_DIRECTORY`` (`Source and Binary Directory Locations (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_SOURCE_NAME`` (`Source and Binary Directory Locations (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_START_WITH_EMPTY_BINARY_DIRECTORY`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_SUBMIT_CDASH_SUBPROJECTS_DEPS_FILE`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_TEST_TYPE`` (`Determining how the results are displayed on CDash (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_UPDATE_ARGS`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``CTEST_WIPE_CACHE`` (`Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER())`_)
# * ``EXTRA_CONFIGURE_OPTIONS`` (`Setting variables in the inner CMake configure (TRIBITS_CTEST_DRIVER())`_)
# * ``EXTRA_SYSTEM_CONFIGURE_OPTIONS`` (`Setting variables in the inner CMake configure (TRIBITS_CTEST_DRIVER())`_)
# * ``TRIBITS_2ND_CTEST_DROP_LOCATION`` (`Specifying where the results go to CDash (TRIBITS_CTEST_DRIVER())`_)
# * ``TRIBITS_2ND_CTEST_DROP_SITE`` (`Specifying where the results go to CDash (TRIBITS_CTEST_DRIVER())`_)
# * ``TRIBITS_PROJECT_ROOT`` (`Source and Binary Directory Locations (TRIBITS_CTEST_DRIVER())`_)
#
# **List of all variables (TRIBITS_CTEST_DRIVER()):**
#
# .. _Setting variables (TRIBITS_CTEST_DRIVER()):
#
# **Setting variables (TRIBITS_CTEST_DRIVER()):**
#
# Variables can be set to control the behavior of this function before the
# function is called.  Some variables must be set in the CTest -S driver
# script before calling this function ``TRIBITS_CTEST_DRIVER()``.  Many
# variables have a default value that will work in most cases.
#
# In general, these variables fall into one of three different categories:
#
# * **Variables that must be set in the outer CTest -S driver script before
#   the TribitsCTestDriverCore.cmake module is even included:** Many of these
#   can also be overridden from an env var of the same name.  There are very
#   few of these variables and they are specifically called out below.
#
# * **Variables with no default value that must set in the outer CTest -S
#   driver script after the TribitsCTestDriverCore.cmake module is included
#   but before TRIBITS_CTEST_DRIVER() is called:** There are very few of these
#   variables and in some cases, they may be optional.  These types of
#   variables will be called out below.
#
# * **Variables that can be are set before TRIBITS_CTEST_DRIVER() is called
#   but have default values provided in the TRIBITS_CTEST_DRIVER() function
#   and may look for env var overrides:** This comprises the majority of the
#   variables used in ``TRIBITS_CTEST_DRIVER()``.  The variables that have
#   default values but allow for an override as an env var use the function
#   `SET_DEFAULT_AND_FROM_ENV()`_.  In the case of variables that are given a
#   default value with ``SET_DEFAULT_AND_FROM_ENV()``, their value is always
#   overridden with what is in the env var of the same name.  In this case,
#   the overriding value that is read in from the env is printed out.  In
#   either case, the value used for these variables is printed out.
#
# Which variables are which are described below for each variable.
#
# .. _Source and Binary Directory Locations (TRIBITS_CTEST_DRIVER()):
#
# **Source and Binary Directory Locations (TRIBITS_CTEST_DRIVER()):**
#
# To understand how to set the source and binary directories, one must
# understand that CTest -S scripts using this function get run in one of two
# different modes:
#
# **Mode 1**: Run where there are **already existing source and binary
# directories** (i.e.  is set empty before call).  In this case,
# `CTEST_SOURCE_DIRECTORY`_ and `CTEST_BINARY_DIRECTORY`_ must be set by the
# user before calling this function (and `CTEST_DASHBOARD_ROOT`_ is empty).
# This mode is typically used to test a local build or an existing cloned and
# setup set source tree and post to CDash (see the custom ``dashboard`` target
# in `Dashboard Submissions`_).
#
# **Mode 2**: A **new binary directory is created and optionally new sources
# are cloned or updated** under a driver directory
# (i.e. ``CTEST_DASHBOARD_ROOT`` is set before call and that directory will be
# created if it does not already exist).  In this case, there are typically
# two (partial) project source tree's, a) the "driver" skeleton source tree
# (typically with an embedded tribits/ directory) that bootstraps the testing
# process that contains the CTest -S driver script, and b) the full "source"
# tree that is (optionally) cloned and/or updated and is directly configured,
# build, and tested.  This mode can also handle the case where the source tree
# is already set up in the location pointed to by `CTEST_SOURCE_DIRECTORY`_
# and `CTEST_DO_SUBMIT`_ is set to ``FALSE`` so this mode can get away with a
# single source tree and can handle a variety of use cases that may
# pre-manipulate the source tree before ``TRIBITS_CTEST_DRIVER()`` is run.
#
# There are a few different directory locations that are significant for this
# script used in one or both of the modes described above:
#
#   .. _TRIBITS_PROJECT_ROOT:
#
#   ``TRIBITS_PROJECT_ROOT=<projectDir>``.
#
#     The root directory to an existing source tree where the project's
#     `<projectDir>/ProjectName.cmake`_ (defining the ``PROJECT_NAME``
#     variable) and `<projectDir>/Version.cmake`_ files can be found.  This
#     can be SET() in the CTest -S script or override as an env var.  The
#     default and env override is set for this during the INCLUDE() of the
#     module ``TribitsCTestDriverCore.cmake``.
#
#   ``${PROJECT_NAME}_TRIBITS_DIR=<tribits-dir>``
#
#     The base directory for the TriBITS system's various CMake modules,
#     python scripts, and other files.  By default this is assumed to be
#     ``${TRIBITS_PROJECT_ROOT}/cmake/tribits``.  This can be SET() in the
#     CTest -S script or overridden as an env var.  The default and env
#     override is set for this during the INCLUDE() of
#     ``TribitsCTestDriverCore.cmake``.
#
#   .. _CTEST_DASHBOARD_ROOT:
#
#   ``CTEST_DASHBOARD_ROOT=<dashboard-root-dir>``
#
#     If set, this is the base directory where this script runs that clones
#     the sources for the project.  If this directory does not exist, it will
#     be created.  If provided as the special value ``PWD``, then the present
#     working directory is used.  If empty, then this var has no effect.  This
#     can be SET() in CTest -S script before the call to
#     ``TRIBITS_CTEST_DRIVER()`` or override as an env var.
#
#   .. _CTEST_SOURCE_NAME:
#
#   ``CTEST_SOURCE_NAME=<src-dir-name>``
#
#     The name of the source directory.  This can be SET() in the CTest -S
#     script before the call to ``TRIBITS_CTEST_DRIVER()`` or overridden as an
#     env var. By default, this is set to ``${PROJECT_NAME}``.
#
#   .. _CTEST_SOURCE_DIRECTORY:
#
#   ``CTEST_SOURCE_DIRECTORY=<src-dir-full-path>``
#
#     Built-in CTest variable that determines the location of the sources that
#     are used to define packages, dependencies and configure, build, and test
#     the software.  This is a variable that CTest directly reads and must
#     therefore be set. This is used to set `PROJECT_SOURCE_DIR`_ which is
#     used by the TriBITS system.  If ``CTEST_DASHBOARD_ROOT`` is set, then
#     this is hard-coded internally to
#     ``${CTEST_DASHBOARD_ROOT}/${CTEST_SOURCE_NAME}`` and will therefore
#     override any value that might be set in the CTest -S driver script.
#     However, if ``CTEST_DASHBOARD_ROOT`` is empty when
#     ``TribitsCTestDriverCore.cmake`` is INCLUDED(), then by default it set
#     to ``${TRIBITS_PROJECT_ROOT}``.  This can only be SET() in the CTest -S
#     driver script and is not overridden as an env var.  The only way to
#     override in the ENV is to indirectly set through
#     ``${CTEST_DASHBOARD_ROOT}``.
#
#   .. _CTEST_BINARY_DIRECTORY:
#
#   ``CTEST_BINARY_DIRECTORY=<binary-dir-full-path>``
#
#     Built-in CTest variable that determines the location of the binary tree
#     where output from CMake/CTest is put.  This is used to set to
#     `PROJECT_BINARY_DIR`_ which is used by the TriBITS system and this
#     variable is directly ready by CTest itself.  If ``CTEST_DASHBOARD_ROOT``
#     is set, then this is hard-coded internally to
#     ``${CTEST_DASHBOARD_ROOT}/BUILD`` (overwriting any existing value of
#     ``CTEST_BINARY_DIRECTORY``).  If ``CTEST_BINARY_DIRECTORY`` is empty
#     when ``TribitsCTestDriverCore.cmake`` is INCLUDED(), then by default it
#     set to ``$ENV{PWD}/BUILD``.  ``CTEST_BINARY_DIRECTORY`` can not be
#     overridden in the env.
#
# .. _Determining What Packages Get Tested (TRIBITS_CTEST_DRIVER()):
#
# **Determining What Packages Get Tested (TRIBITS_CTEST_DRIVER()):**
#
# Before any testing is done, the set of packages to be tested is determined.
# This determination uses the basic `TriBITS Dependency Handling Behaviors`_
# and logic.  By default, the set of packages to be tested and otherwise
# explicitly processed is determined by the vars (which can also be set as env
# vars):
#
#   .. _${PROJECT_NAME}_PACKAGES:
#
#   ``${PROJECT_NAME}_PACKAGES=<pkg0>,<pkg1>,...``
#
#     A semi-colon ';' or comma ',' separated list of packages that determines
#     the specific set of packages to test.  If left at the default value of
#     empty "", then `${PROJECT_NAME}_ENABLE_ALL_PACKAGES`_ is set to ``ON``
#     and that enables packages as described in `<Project>_ENABLE_ALL_PACKAGES
#     enables all PT (cond. ST) SE packages`_.  This variable can use ',' to
#     separate package names instead of ';'.  The default value is empty "".
#
#   .. _${PROJECT_NAME}_ADDITIONAL_PACKAGES:
#
#   ``${PROJECT_NAME}_ADDITIONAL_PACKAGES=<pkg0>,<pkg1>,...``
#
#     If ``${PROJECT_NAME}_PACKAGES`` is empty (and therefore
#     ``${PROJECT_NAME}_ENABLE_ALL_PACKAGES=ON`` is set), then additional
#     packages not enabled in that logic can be listed
#     ``${PROJECT_NAME}_ADDITIONAL_PACKAGES`` and they will be tested as well.
#     For example, if this wold be used when there are some additional ST or
#     EX packages that should be tested in a PT build
#     (e.g. ``${PROJECT_NAME}_ENABLE_SECONDARY_TESTED_CODE=FALSE``.  The
#     default value is empty "".
#
#   .. _${PROJECT_NAME}_ENABLE_ALL_FORWARD_DEP_PACKAGES:
#
#   ``${PROJECT_NAME}_ENABLE_ALL_FORWARD_DEP_PACKAGES=[TRUE|FALSE]``
#
#     If set to ``TRUE``, then all of the downstream packages from those
#     specified in ``${PROJECT_NAME}_PACKAGES`` will be enabled (see
#     `<Project>_ENABLE_ALL_FORWARD_DEP_PACKAGES enables downstream
#     packages/tests`_).  The default value is ``FALSE`` unless
#     ``CTEST_ENABLE_MODIFIED_PACKAGES_ONLY=TRUE`` is set in which case the
#     default value is ``TRUE``.
#
#   ``${PROJECT_NAME}_ENABLE_SECONDARY_TESTED_CODE=[TRUE|FALSE]``
#
#     If set to ``TRUE``, then ST packages will get enabled in automated logic
#     in the outer determination of what packages to get tested.  This value
#     also gets passed to the inner CMake configure.  The default value is
#     ``OFF``.
#
#   .. _${PROJECT_NAME}_EXCLUDE_PACKAGES:
#
#   ``${PROJECT_NAME}_EXCLUDE_PACKAGES=<pkg0>,<pkg1>,...``
#
#     A semi-colon ';' or comma ',' separated list of packages **NOT** to
#     enable when determining the set of packages to be tested.  NOTE: Listing
#     packages here will *not* disable the package in the inner CMake
#     configure when using the package-by-packages approach.  To do that, you
#     will have to disable them in the variable EXTRA_CONFIGURE_OPTIONS (set
#     in your driver script).  But for the all-at-once approach this list of
#     package disables **IS** pass into the inner configure.
#
#   ``${PROJECT_NAME}_DISABLE_ENABLED_FORWARD_DEP_PACKAGES=[TRUE|FALSE]``
#
#     If set to ``ON`` (or ``TRUE``), then if there are conflicts between
#     explicit enables and disables then explicit disables will override the
#     explicit enables (see `Disables trump enables where there is a
#     conflict`_).  The default is ``ON`` and likely should not be changed.
#     The default value is ``ON``.
#
#   .. _CTEST_EXPLICITLY_ENABLE_IMPLICITLY_ENABLED_PACKAGES:
#
#   ``CTEST_EXPLICITLY_ENABLE_IMPLICITLY_ENABLED_PACKAGES=[TRUE|FALSE]``
#
#     If set to ``TRUE``, then all of the upstream packages for those selected
#     to be explicitly tested will be processed with results posted to CDash.
#     The default is ``TRUE`` unless
#     ``CTEST_ENABLE_MODIFIED_PACKAGES_ONLY==TRUE``.  Most builds that specify
#     a specific set of packages in ``${PROJECT_NAME}_PACKAGES`` should likely
#     set this to ``FALSE``.
#
# NOTE: Any and all of the above vars can be set as env vars and they will
# override the value set inside the CTest -S script with ``SET()``` (or
# `SET_DEFAULT()`_) statements.  Also, for any of the vars that take a list,
# the CMake standard semi-colon char ';' can be used to separate list items or
# comas ',' can be used so that they can be used when setting env vars.  (The
# comas ',' are then replaced with semi-colons ';' internally before
# interpreted as an list by CMake.)
#
# The other mode for selecting the set of packages to be tested is to only
# test the packages that have changes since the last time this build was run
# and testing packages that previously failed.  That mode is turned on by the
# var:
#
#   .. _CTEST_ENABLE_MODIFIED_PACKAGES_ONLY:
#
#   ``CTEST_ENABLE_MODIFIED_PACKAGES_ONLY=[TRUE|FALSE]``
#
#     If ``TRUE``, then only packages that have changes pulled from the git
#     repos since the last time the build ran will be tested (in addition to
#     packages that failed in the last build).  If ``FALSE``, the set of
#     packages to be tested is determined by `${PROJECT_NAME}_PACKAGES`_ and
#     other variables as described above.
#
# .. _Setting variables in the inner CMake configure (TRIBITS_CTEST_DRIVER()):
#
# **Setting variables in the inner CMake configure:**
#
# It is important to understand that none of the CMake vars that get set in
# the other CTest -S program that calls ``TRIBITS_CTEST_DRIVER()``
# automatically get passed into the inner configure of the TriBITS CMake
# project using the ``CTEST_CONFIGURE()`` command by CMake.  From the
# perspective of raw CTest and CMake, these are completely separate programs.
# However, the ``TRIBITS_CTEST_DRIVER()`` function will forward subset of
# variables documented below into the inner CMake configure.  The following
# variables that are set in the outer CTest -S program will be passed into the
# inner CMake configure by default (but their values they can be overridden by
# options listed in ``EXTRA_SYSTEM_CONFIGURE_OPTIONS`` or
# ``EXTRA_CONFIGURE_OPTIONS``):
#
#   ``-D${PROJECT_NAME}_IGNORE_MISSING_EXTRA_REPOSITORIES=ON``
#
#     Missing extra repos are always ignored in the inner CMake configure.
#     This is because any problems reading an extra repo will be caught in the
#     outer CTest -S drivers script.
#
#   ``-D${PROJECT_NAME}_ENABLE_ALL_OPTIONAL_PACKAGES:BOOL=ON``
#
#     Because of the behavior of the package-by-package mode, currently, this
#     is hard-coded to ``ON``.  (This set may be removed in the future for the
#     all-at-once mode.)
#
#   ``-D${PROJECT_NAME}_ALLOW_NO_PACKAGES:BOOL=ON``
#
#     This is currently set for the package-by-package mode since some
#     packages may get disabled because required upstream dependent packages
#     may be disabled.  (This set may be removed in the future for the
#     all-at-once mode.)
#
# The following variables set in the CTest -S driver script will be passed
# down into the inner CMake configure through the ``OPTIONS`` variable to the
# ``CTEST_CONFIGURE()`` command:
#
# * ``${PROJECT_NAME}_TRIBITS_DIR``: Direct pass-through
# * ``${PROJECT_NAME}_WARNINGS_AS_ERRORS_FLAGS``: Direct pass-through
# * ``${PROJECT_NAME}_DISABLE_ENABLED_FORWARD_DEP_PACKAGES``: Direct pass-through
# * ``${PROJECT_NAME}_DEPS_XML_OUTPUT_FILE``: Set to empty if
#   ``CTEST_GENERATE_DEPS_XML_OUTPUT_FILE==FALSE``
# * ``${PROJECT_NAME}_ENABLE_SECONDARY_TESTED_CODE``: Direct pass-through
# * ``${PROJECT_NAME}_ENABLE_TESTS``: Set the the same value as
#   `${PROJECT_NAME}_INNER_ENABLE_TESTS`_ set in the outer ctest -S driver script
# * ``${PROJECT_NAME}_SKIP_CTEST_ADD_TEST``: Direct pass-through
# * ``MPI_EXEC_MAX_NUMPROCS``: Direct pass-through
# * ``${PROJECT_NAME}_ENABLE_COVERAGE_TESTING``: Set to ``ON`` if
#   ``CTEST_DO_COVERAGE_TESTING==TRUE``
# * ``${PROJECT_NAME}_EXTRAREPOS_FILE``: Set to empty if
#   ``${PROJECT_NAME}_EXTRAREPOS_FILE=NONE``. Otherwise, passed through.
# * ``${PROJECT_NAME}_ENABLE_KNOWN_EXTERNAL_REPOS_TYPE``: Direct pass-through
# * `${PROJECT_NAME}_GENERATE_VERSION_DATE_FILES`_: Only passed down if
#   non-empty value is set (default empty "")
#
# Arbitrary options can be set to be passed into the inner CMake configure
# after the above options are passed by setting the following variables:
#
#   .. _EXTRA_SYSTEM_CONFIGURE_OPTIONS:
#
#   ``EXTRA_SYSTEM_CONFIGURE_OPTIONS``
#
#     Additional list of system-specific options to be passed to the inner
#     CMake configure.  This must be set in the CTest -S driver script with a
#     ``SET()`` statement (i.e. env var is not read).  These options get added
#     after all of the above pass-through options so they can override any of
#     those options.  **WARNING:** Do not include any semicolons ';' in these
#     arguments (see below WARNING).
#
#   .. _EXTRA_CONFIGURE_OPTIONS:
#
#   ``EXTRA_CONFIGURE_OPTIONS``
#
#     Additional list of extra cmake configure options to be passed to the
#     inner CMake configure.  This must be set in the CTest -S driver script
#     with a ``SET()`` statement (i.e. env var is not read).  These options
#     get added after all of the above pass-through options and the options
#     listed in ``EXTRA_SYSTEM_CONFIGURE_OPTIONS`` so they can override any of
#     those options.  **WARNING:** Do not include any semicolons ';' in these
#     arguments (see below WARNING).
#
#   ``${PROJECT_NAME}_EXTRA_CONFIGURE_OPTIONS``:
#
#     A yet additional list of extra cmake configure options to be passed to
#     the inner CMake configure after all of the others.  Unlike the above
#     options, this var is read from the env and allows the user to set
#     arbitary configure options that overrides all others. **WARNING:** Do
#     not include any semicolons ';' in these arguments (see below WARNING).
#
# These configure options are passed into the ``CTEST_CONFIGURE()`` command in
# the order::
#
#  <initial options> ${EXTRA_SYSTEM_CONFIGURE_OPTIONS}} \
#     ${EXTRA_CONFIGURE_OPTIONS} ${${PROJECT_NAME}_EXTRA_CONFIGURE_OPTIONS}
#
# **WARNING:** The options listed in ``EXTRA_SYSTEM_CONFIGURE_OPTIONS``,
# ``EXTRA_CONFIGURE_OPTIONS``, and ``${PROJECT_NAME}_EXTRA_CONFIGURE_OPTIONS``
# should not contain any semi-colons ';' or they will be interpreted as array
# bounds and mess up the arguments when passed to the inner CMake configure.
# To avoid problems with spaces and semicolons, it is usually a good idea to
# put these cache vars into ``*.cmake`` file fragments and the pass them
# through using the variable `<Project>_CONFIGURE_OPTIONS_FILE`_ as::
#
#   -D<Project>_CONFIGURE_OPTIONS_FILE=<optionsfile1>.cmake,<optionsfile2>.cmake,...
#
# or using the built-in CMake option::
#
#   -C<abs-base>/<optionsfile1>.cmake -C<abs-base>/<optionsfile2>.cmake ...
#
# NOTE: The full list of options passed into the inner CMake is printed out
# before calling ``CTEST_CONFIGURE()`` so any issues setting options and the
# ordering of options can be seen in that printout.
#
# .. _Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER()):
#
# **Determining what testing-related actions are performed (TRIBITS_CTEST_DRIVER()):**
#
# When run, ``TRIBITS_CTEST_DRIVER()`` always performs a configure and build
# but other actions are optional.  By default, a version control update (or
# clone) is performed as well as running tests and submitting results to
# CDash.  But the version control update, the running tests and submitting
# results to CDash can be disabled.  Also, coverage testing and memory testing
# are not performed by default but they can be turned on with results
# submitted to CDash.  These actions are controlled by the following variables
# (which can be set in the CTest -S script before calling
# ``TRIBITS_CTEST_DRIVER()`` and can be overridden by env vars of the same
# name):
#
#   .. _CTEST_DO_NEW_START:
#
#   ``CTEST_DO_NEW_START=[TRUE|FALSE]``
#
#     If ``TRUE``, ``ctest_start()`` is called to set up a new "dashboard"
#     (i.e. define a new CDash build with a unique Build Stamp defined in the
#     ``Testing/TAG`` file).  If ``FALSE``, then ``ctest_start(... APPEND)``
#     is called which allows it this ctest -S invocation to append results to
#     an existing CDash build.  (See ???).  Default ``TRUE``.
#
#   ``CTEST_DO_UPDATES=[TRUE|FALSE]``
#
#     If ``TRUE``, then the source repos will be updated as specified in
#     `Repository Updates (TRIBITS_CTEST_DRIVER())`_.  Default ``TRUE``.
#
#   .. _CTEST_UPDATE_ARGS:
#
#   ``CTEST_UPDATE_ARGS``
#
#     Any extra arguments to use with ``git clone`` to clone the base git repo.
#     The default value is empty "".  This is only used for the base git repo
#     (not the extra repos).
#
#   .. _CTEST_START_WITH_EMPTY_BINARY_DIRECTORY:
#
#   ``CTEST_START_WITH_EMPTY_BINARY_DIRECTORY=[TRUE|FALSE]``
#
#     If ``TRUE``, then if the binary directory ``${CTEST_BINARY_DIRECTORY}``
#     already exists, then it will be clean out using the CTest command
#     ``CTEST_EMPTY_BINARY_DIRECTORY()``.  However, this can set to ``FALSE``
#     in which case a rebuild (using existing object files, libraries, etc.)
#     will be performed which is useful when using an incremental CI server.
#     But this is ignored if ``CTEST_DO_NEW_START=FALSE``. Default ``TRUE``
#     (which is the most robust option).
#
#   .. _CTEST_DO_CONFIGURE:
#
#   ``CTEST_DO_CONFIGURE=[TRUE|FALSE]``
#
#     If ``TRUE``, then the selected packages will be configured.  If
#     ``FALSE``, it is assumed that a relavent configure is already in place
#     in the binary directory if a build or running tests is to be done.  Note
#     that for the package-by-package mode, a configure is always done if a
#     build or any testing is to be done but results will not be sent to CDash
#     unless ``CTEST_DO_CONFIGURE=TRUE``. Default ``TRUE``.
#
#   .. _CTEST_WIPE_CACHE:
#
#   ``CTEST_WIPE_CACHE=[TRUE|FALSE]``
#
#     If ``TRUE``, then ``${CTEST_BINARY_DIRECTORY}/CMakeCache.txt`` and
#     ``${CTEST_BINARY_DIRECTORY}/CMakeFiles/`` will be deleted before
#     performing a configure.  (This value is set to ``FALSE`` by the `make
#     dashboard`_ target that does an experimental build, test, and submit to
#     CDash.)  Default ``TRUE`` (which is the most robust option in general).
#
#   .. _CTEST_DO_BUILD:
#
#   ``CTEST_DO_BUILD=[TRUE|FALSE]``
#
#     If ``TRUE``, then the selected packages will be build.  If ``FALSE``, it
#     is assumed that a relavent build is already in place in the binary
#     directory if any testing is to be done.  Default ``TRUE``.
#
#   .. _CTEST_BUILD_FLAGS:
#
#   ``CTEST_BUILD_FLAGS``
#
#     Build-in CTest variable that gives the flags passed to the build command
#     called inside of the built-in CTest command ``CTEST_BUILD()``.  The
#     default is ``-j2`` when `CTEST_CMAKE_GENERATOR`_ is set to ``Unix
#     Makefiles``.  Otherwise, the default is empty "".  Useful options to set
#     are ``-j<N>`` (to build on parallel) and ``-k`` (to keep going when
#     there are build errors so we can see all of the build errors).  When
#     ``CTEST_CMAKE_GENERATOR`` is set to ``Ninja``, the ``j<N>`` option can
#     be left off (in which case all of the available unloaded cores are used
#     to build) and the option ``-k 999999`` can be used to build all targets
#     when there are build failures.
#
#   .. _CTEST_DO_INSTALL:
#
#   ``CTEST_DO_INSTALL=[TRUE|FALSE]``
#
#     If ``TRUE``, then ``-DCMAKE_SKIP_INSTALL_ALL_DEPENDENCY=ON`` will be
#     passed th the inner CMake configure and the 'install_package_by_package'
#     target will be built to install what has been configured and built by
#     the build step for the all-at-once mode
#     (i.e. ``${PROJECT_NAME}_CTEST_DO_ALL_AT_ONCE=TRUE``).  If ``FALSE``,
#     then ``-DCMAKE_SKIP_INSTALL_ALL_DEPENDENCY=ON`` is **not** added to the
#     inner configure and no install is performed.  (NOTE: The cmake var
#     ``CMAKE_INSTALL_PREFIX`` must be set on the inner cmake configure for
#     this to work correctly.  Also, the install is currently not implemented
#     for the package-by-package mode
#     ``${PROJECT_NAME}_CTEST_DO_ALL_AT_ONCE=FALSE`` and this option will
#     simply be ignored in that case.)  Default ``FALSE``.
#
#   .. _CTEST_DO_TEST:
#
#   ``CTEST_DO_TEST=[TRUE|FALSE]``
#
#     If ``TRUE``, then ``CTEST_TEST()`` will be called and test results will
#     be submitted to CDash.  This should be set to ``FALSE`` when one wanted
#     to only test the configure and build of a project but not run any tests
#     (e.g. when cross compiling or if the tests are too expensive to run).
#     The default value is ``TRUE``.
#
#   .. _CTEST_PARALLEL_LEVEL:
#
#   ``CTEST_PARALLEL_LEVEL=<num>``
#
#     The parallel level passed in the ``PARALLEL_LEVEL`` argument to
#     ``CTEST_TEST()`` AND ``CTEST_MEMCHECK()``.  The default value is ``1``
#     (one).
#
#   .. _${PROJECT_NAME}_INNER_ENABLE_TESTS:
#
#   ``${PROJECT_NAME}_INNER_ENABLE_TESTS``
#
#     If ``OFF``, then ``${PROJECT_NAME}_ENABLE_TESTS=OFF`` will be passed to
#     the inner CMake configure.  This will avoid building of all tests and
#     examples for the enabled packages and also no CTest tests will be
#     defined using calls to ``add_test()`` in the inner project configure.
#     This results in just the building of the libraries and non-test,
#     non-example executables (which will be much faster for some projects).
#     The default value is ``ON`` (in which case all of the test and example
#     executable and other targets will get built for all of the explicitly
#     enabled packages and the associated ctest tests will be defined and
#     run).
#
#   .. _${PROJECT_NAME}_SKIP_CTEST_ADD_TEST:
#
#   ``${PROJECT_NAME}_SKIP_CTEST_ADD_TEST``:
#
#     If set to ``TRUE``, then ``${PROJECT_NAME}_SKIP_CTEST_ADD_TEST=TRUE`` is
#     passed in to the inner CMake configure.  This will result in all of the
#     test and example executables for the enabled packages to be built but no
#     ctest tests will get defined and run by skipping the inner CMake calls
#     to ``add_test()``.  Setting this to ``TRUE`` allows all of the
#     libraries, production executables and the test and example executables
#     and other targets to get built, but no tests will be run.  However, when
#     ``CTEST_DO_TEST=ON``, the ``ctest_test()`` command will still be run and
#     test results will still be submitted to CDash which will report zero
#     tests.  This avoids the test results being reported as missing on CDash
#     for tools like ``ctest_analyze_and_report.py``.  The default value is
#     ``FALSE`` (in which case any enabled tests or examples in the explicitly
#     enabled packages will get run).
#
#   .. _CTEST_DO_COVERAGE_TESTING:
#
#   ``CTEST_DO_COVERAGE_TESTING=[TRUE|FALSE]``
#
#     If ``TRUE``, then ``CTEST_COVERAGE()`` is called to collect coverage and
#     submit results generated from the previous ``CTEST_TEST()`` command.
#     Setting this to ``TRUE`` also results in
#     ``-D${PROJECT_NAME}_ENABLE_COVERAGE_TESTING=ON`` getting passed down to
#     the inner CMake configure of the project (i.e. so that the executables
#     are instrumented to generate coverage data when run by the tests in the
#     ``CTEST_TEST()`` command).
#
#   .. _CTEST_COVERAGE_COMMAND:
#
#   ``CTEST_COVERAGE_COMMAND``
#
#     Built-in CTest variable that determines the command that is run by
#     ``CTEST_COVERAGE()`` to collect coverage results.  That default value is
#     ``gcov``.
#
#   .. _CTEST_DO_MEMORY_TESTING:
#
#   ``CTEST_DO_MEMORY_TESTING=[TRUE|FALSE]``
#
#     If ``TRUE``, then ``CTEST_MEMCHECK()`` is called to run the test suite
#     with the memory checking tool and results submitted to CDash.
#
#   .. _CTEST_MEMORYCHECK_COMMAND:
#
#   ``CTEST_MEMORYCHECK_COMMAND``
#
#     Built-in CTest variable that determines the command that is used to run
#     the command for each test run by the ``CTEST_MEMCHECK()`` command.  If
#     ``valgrind`` is found on the local system, then that is used by default.
#     Otherwise, the default is empty "".
#
#   .. _CTEST_MEMORYCHECK_COMMAND_OPTIONS:
#
#   ``CTEST_MEMORYCHECK_COMMAND_OPTIONS``
#
#     Built-in CTest variable that determines what options are passed to the
#     memory checking command before the actual test command.  The default
#     value is empty "".
#
#   .. _CTEST_GENERATE_OUTER_DEPS_XML_OUTPUT_FILE:
#
#   ``CTEST_GENERATE_OUTER_DEPS_XML_OUTPUT_FILE=[TRUE|FALSE]``
#
#     If ``TRUE``, then ``<Project>PackageDependencies.xml`` file will be
#     generated in the outer CTest -S program.  This file is used to help
#     determine what packages have changed and need to be tested when in CI
#     mode (e.g. when ``CTEST_ENABLE_MODIFIED_PACKAGES_ONLY=TRUE`` is set).
#     It is also needed to generate the ``CDashSubprojectDependencies.xml``
#     file that gets submitted to CDash to inform it of the list of
#     subprojects and subproject dependencies (i.e. TriBITS packages).  The
#     default value is ``TRUE``.
#
#   .. _CTEST_SUBMIT_CDASH_SUBPROJECTS_DEPS_FILE:
#
#   ``CTEST_SUBMIT_CDASH_SUBPROJECTS_DEPS_FILE=[TRUE|FALSE]``
#
#     If ``TRUE``, then CDash subprojects XML file is generated and submitted
#     to CDash.  This file tells CDash about the subproject (i.e. TriBITS
#     package) structure.  The default value is ``TRUE``.
#
#   .. _CTEST_DO_SUBMIT:
#
#   ``CTEST_DO_SUBMIT=[TRUE|FALSE]``
#
#     If ``TRUE``, then all of the results generated locally are submitted to
#     CDash using ``CTEST_SUBMIT()``.  One can set this to ``FALSE`` when
#     locally debugging a CTest -S driver script to avoid spamming CDash.  The
#     default value is ``TRUE``.  (NOTE: This may submit to more than one
#     CDash site as noted in `Specifying where the results go to CDash
#     (TRIBITS_CTEST_DRIVER())`_).
#
# .. _Determining how the results are displayed on CDash (TRIBITS_CTEST_DRIVER()):
#
# **Determining how the results are displayed on CDash (TRIBITS_CTEST_DRIVER()):**
#
# These options all primarily determine how VC update, configure, build, test,
# and other results and submitted and displayed on CDash (but not what CDash
# site(s) or project(s) they are submitted to).  These options can all be set
# in the CTest -S script using ``SET()`` statements before
# ``TRIBITS_CTEST_DRIVER()`` is called and can be overridden in the env.
#
#   .. _CTEST_TEST_TYPE:
#
#   ``CTEST_TEST_TYPE=[Nightly|Continuous|Experimental]``
#
#     Determines the type of build.  This value is passed in as the first
#     argument to the built-in CTest function ``CTEST_START()``.  Valid values
#     include ``Nightly``, ``Continuous``, and ``Experimental``.  This also
#     defines the default value for `${PROJECT_NAME}_TESTING_TRACK`_ as well
#     as defines the default value for
#     ``${PROJECT_NAME}_ENABLE_KNOWN_EXTERNAL_REPOS_TYPE``.  The default value
#     is ``Experimental``.
#
#   .. _${PROJECT_NAME}_TESTING_TRACK:
#
#   ``${PROJECT_NAME}_TESTING_TRACK=<track-name>``
#
#     Specifies the testing track on CDash for which results are displayed
#     under (i.e. the "Group" filter field on CDash).  This is the value used
#     for the ``TRACK`` argument of the built-in CTest function
#     ``CTEST_START()``.  It is given the default value of
#     ``${CTEST_TEST_TYPE}``.  However, if ``CTEST_TEST_TYPE==Experimental``
#     (or ``EXPERIMENTAL``), then ``${PROJECT_NAME}_TESTING_TRACK`` is forced
#     to ``Experimental``, even if it was set to a different value.
#
#   .. _CTEST_SITE:
#
#   ``CTEST_SITE=<site-name>``
#
#     This is a built-in CTest variable that determines what is displayed for
#     the ``site`` field for the build on CDash.  This specified by default by
#     calling the built-in CMake/CTest function ``SITE_NAME()``.
#
#   .. _COMPILER_VERSION:
#
#   ``COMPILER_VERSION=<compiler-version>``
#
#     Gives the name of the compiler that is used to compose a default
#     `CTEST_BUILD_NAME`_.  If ``CTEST_BUILD_NAME`` is explicitly set, then
#     this value is ignored.
#
#   .. _CTEST_BUILD_NAME:
#
#   ``CTEST_BUILD_NAME=<build-name>``
#
#     This is a built-in CTest variable that determines the name of the build
#     on CDash.  Builds that have the same ``CTEST_SITE``,
#     ``CTEST_BUILD_NAME`` and ``${PROJECT_NAME}_TRACK`` are considered to be
#     related builds and CDash will relate them as "previous" and "next"
#     builds (good for showing number of added or removed tests, new test
#     failures, new passing tests, etc.).  If not specified, it is given the
#     default value ``${HOST_TYPE}-${COMPILER_VERSION}-${BUILD_DIR_NAME}``.
#     Here, ``HOST_TYPE`` is determined automatically from the ``uname``
#     system command using ``FIND_PROGRAM(uname)``.  The value of
#     ``BUILD_DIR_NAME`` is expected to be set in each specific CTest -S
#     driver script.
#
#   .. _CTEST_NOTES_FILES:
#
#   ``CTEST_NOTES_FILES="<filepath1>;<filepath2>;..."``
#
#     Built-in CTest variable that specifies a semi-colon separated list of
#     files that will get uploaded to CDash as "notes files".  This function
#     will also add notes files as well such as the file
#     ``CMakeCache.clean.txt`` (cleaned-up version of the CMakeCache.txt
#     file), the file ``Updates.txt`` (lists new git commits pulled in all the
#     git repos), the file ``UpdateCommandsOutput.txt`` (list of commands and
#     their output which are run by ``ctest_update()`` in the base git repo),
#     and the file ``${PROJECT_NAME}RepoVersion.txt`` (gives version of all
#     the git repos being tested).
#
# .. _Specifying where the results go to CDash (TRIBITS_CTEST_DRIVER()):
#
# **Specifying where the results go to CDash (TRIBITS_CTEST_DRIVER()):**
#
# By default, the target CDash server and CDash project are specified by the
# variables set in the file `<projectDir>/CTestConfig.cmake`_; specifically,
# ``CTEST_DROP_SITE``, ``CTEST_PROJECT_NAME``, and ``CTEST_DROP_LOCATION``.
# If these are set using `SET_DEFAULT_AND_FROM_ENV()`_, as shown in the
# example ``TribitsExampleProject/CTestConfig.cmake`` file, then they can be
# overridden with ``SET()`` statements in the CTest -S script or as env vars;
# simple enough.
#
# In addition, results can be sent to a second CDash site using the variables:
#
#   ``TRIBITS_2ND_CTEST_DROP_SITE``
#
#     CDash drop site for second upload of results.  If empty, then
#     ``CTEST_DROP_SITE`` is used.
#
#   ``TRIBITS_2ND_CTEST_DROP_LOCATION``
#
#     Location for the second drop site.  If empty, then
#     ``CTEST_DROP_LOCATION`` is used.
#
# At lease one of these vars must be set to non empty or a second submit will
# not be performed.  For more details, see `TRIBITS_2ND_CTEST_DROP_SITE`_ and
# `TRIBITS_2ND_CTEST_DROP_LOCATION`_.
#
# .. _Determining what TriBITS repositories are included (TRIBITS_CTEST_DRIVER()):
#
# **Determining what TriBITS repositories are included (TRIBITS_CTEST_DRIVER()):**
#
# This script is set up to process extra VC and TriBITS repos that contribute
# additional TriBITS packages to the base TriBITS project.  This set of extra
# repos is determined using the following vars (which can be set in the CTest
# -S script or overridden with env vars of the same name):
#
#   ``${PROJECT_NAME}_EXTRAREPOS_FILE=<extrarepos-file-path>``
#
#     Points to a file that lists the extra VC and TriBITS repos. If not
#     explicitly set, then by default it will read from the file
#     `<projectDir>/cmake/ExtraRepositoriesList.cmake`_ unless
#     ``${PROJECT_NAME}_SKIP_EXTRAREPOS_FILE=TRUE`` is set in the
#     ``ProjectName.cmake`` file in which case no extra repos file is read in.
#     See `<Project>_EXTRAREPOS_FILE`_.
#
#   ``${PROJECT_NAME}_ENABLE_KNOWN_EXTERNAL_REPOS_TYPE=[Nightly|Continuous|Experimental]``
#
#     The category of extra repos to process from the file
#     ``${PROJECT_NAME}_EXTRAREPOS_FILE`` (see
#     `<Project>_ENABLE_KNOWN_EXTERNAL_REPOS_TYPE`_).
#
#   ``${PROJECT_NAME}_PRE_REPOSITORIES=<reponame1>,<reponame2>,...``
#
#     Subset of "pre" extra repos specified in the file
#     ``${PROJECT_NAME}_EXTRAREPOS_FILE`` to process (see
#     `<Project>_PRE_REPOSITORIES`_).
#
#   ``${PROJECT_NAME}_EXTRA_REPOSITORIES=<reponame1>,<reponame2>,...``
#
#     Subset of "post" extra repos specified in the file
#     ``${PROJECT_NAME}_EXTRAREPOS_FILE`` to process (see
#     `<Project>_EXTRA_REPOSITORIES`_).
#
# The behavior for selecting extra repos using these variables is determined
# as described in:
#
# * `Enabling extra repositories through a file`_
#
# .. _All-at-once versus package-by-package mode (TRIBITS_CTEST_DRIVER()):
#
# **All-at-once versus package-by-package mode (TRIBITS_CTEST_DRIVER()):**
#
# This function supports driving the configure, build, testing, and submitting
# to CDash of the packages in the TriBITS project either all-at-once or
# package-by-package, based on the vars (which can be set in the CTest -S
# script and overridden by env vars):
#
#   ``${PROJECT_NAME}_CTEST_DO_ALL_AT_ONCE=[TRUE|FALSE]``
#
#     If ``TRUE``, then single calls to ``CTEST_CONFIGURE()``,
#     ``CTEST_BUILD()`` and ``CTEST_TEST()`` are made for all of the packages
#     to be tested all at once with ``CTEST_SUBMIT()`` called after each of
#     these.  If ``FALSE`` then ``CTEST_CONFIGURE()``, ``CTEST_BUILD()`` and
#     ``CTEST_TEST()`` and ``CTEST_SUBMIT()`` are called in a loop, once for
#     each package to be explicitly tested. 
#
# Both the all-at-once mode and the package-by-package mode should produce
# equivalent builds of the project and submits to CDash (for correctly
# constructed TriBITS projects and packages).  But the package-by-package mode
# will disable packages with failing library builds when processing downstream
# packages, and therefore reduce the propagation of failures to downstream
# packages and therefore is more robust.  But the package-by-package mode is
# more expensive in several respects for many projects.
#
# For versions of CMake 3.10.0 and above and newer versions of CDash, the
# CDash server for the all-at-once mode will break down build and test results
# on a package-by-package basis on CDash together.
#
# **NOTE:** It has been confirmed that older versions of CDash can accept and
# display results from newer CMake/CTest versions when
# ``${PROJECT_NAME}_CTEST_USE_NEW_AAO_FEATURES`` set to ``TRUE``.  It is just
# that for older versions of CDash that it will not break down results on a
# package-by-package basis on CDash and all of the build warnings and errors
# and tests will be all globed together on CDash.
#
# .. _Mutiple ctest -S invocations (TRIBITS_CTEST_DRIVER()):
#
# **Mutiple ctest -S invocations (TRIBITS_CTEST_DRIVER()):**
#
# By default, this function is meant to be used in a single invocation of the
# ``ctest -S <script>.cmake`` command in order to do everything from the
# beginning and submit to CDash.  But there are times when one needs to do the
# various steps in multiple ``ctest -S`` invocations that all send data to the
# same CDash build.  For example, on some clusters, configure and build must
# be done on "compile nodes" but the tests must be run on "compute nodes".
# Typically, these types of machines have a shared file system.  On a system
# like this, one would use two different invocations as::
#
#   # Start new dashboard, update, configure, and build on compile node
#   env CTEST_DO_TEST=OFF \
#     ctest -S <script>.cmake
#
#   # Run tests only on compute node
#   <run-on-compute-node> \
#     env CTEST_DO_NEW_START=OFF CTEST_DO_UPDATES=OFF \
#       CTEST_DO_CONFIGURE=OFF CTEST_DO_BUILD=OFF \
#       CTEST_DO_TEST=ON \
#     ctest -S <script>.cmake
#
# Above, `CTEST_DO_NEW_START`_ ``= OFF`` is needed to ensure that the test
# results go to the same CDash build.  (NOTE: A CDash build is uniquely
# determined by the site name, build name and build stamp.)
#
# This approach works for both the all-at-once mode and the package-by-package
# mode.
#
# Also, one can run each of the basic steps in its own ``ctest -S`` invocation
# starting with ``CTEST_DO_NEW_START = ON``, then `CTEST_DO_UPDATES`_ ``=
# ON``, then `CTEST_DO_CONFIGURE`_ ``= ON``, then `CTEST_DO_BUILD`_ ``= ON``,
# then then `CTEST_DO_TEST`_ ``= ON``, etc.  While there is typically no
# reason to split things up to this level of granularity, CTest and this
# ``TRIBITS_CTEST_DRIVER()`` function will support such usage.  All that is
# required is that those steps be performed in that order.  For example, one
# cannot do a build in one ``ctest -S`` invocation and then try to do a
# configure in the next because the build will fail because a valid
# configuration has not been performed yet.  And one cannot run just tests if
# there is not a valid configuration and build already in place.
#
# .. _Repository Updates (TRIBITS_CTEST_DRIVER()):
#
# **Repository Updates (TRIBITS_CTEST_DRIVER()):**
#
# Like the rest of TriBITS, ``ctest -S`` scripts written using this function
# support a collection of extra repositories in addition to the base git
# repository.
#
# Whether the local repos are updated (or left as is) is determined by the
# variable:
#
#  .. _CTEST_DO_UPDATES:
#
#  ``CTEST_DO_UPDATES=[TRUE|FALSE]``
#
#    If set to ``TRUE``, then each of the git repos will be cloned if they do
#    not already exist and if already present will be updated as described
#    below (and will wipe out any local changes).  If set to ``FALSE``, then
#    the git repos will be left alone and must therefore already be cloned and
#    updated at the desired state.  For example, this should be set to
#    ``FALSE`` when running against a local development repo (e.g. the `make
#    dashboard`_ target sets this to ``FALSE`` automatically) or when other
#    logic is used to setup the source directories. **WARNING:** If you are
#    running against a local repo with local changes and you don't set to
#    ``FALSE``, then your local uncommitted changes will be wiped out and the
#    local branch will be hard reset to the remote tracking branch!  The
#    default value is ``TRUE``.
#
# **WARNING:** If you don't want local changes in your git repos to get blown
# away, then set ``CTEST_DO_UPDATES`` to ``FALSE``!
#
# If the base repo pointed to by ``${CTEST_SOURCE_DIRECTORY}`` is missing, it
# cloned inside of the ``CTEST_START()`` function using the custom command::
#
#   git clone [-b ${${PROJECT_NAME}_BRANCH}] \
#     -o ${${PROJECT_NAME}_GIT_REPOSITORY_REMOTE} \
#     ${${PROJECT_NAME}_REPOSITORY_LOCATION}
#
# where:
#
#   .. _${PROJECT_NAME}_REPOSITORY_LOCATION:
#
#   ``${PROJECT_NAME}_REPOSITORY_LOCATION=<repo-url>``
#
#     The URL of the base git repo ``<repo-url>`` to clone inside of
#     ``CTEST_START()``.  The default is
#     ``${${PROJECT_NAME}_REPOSITORY_LOCATION_NIGHTLY_DEFAULT}`` when
#     ``CTEST_TEST_TYPE=Nightly`` and otherwise the default is
#     ``${${PROJECT_NAME}_REPOSITORY_LOCATION_DEFAULT}``.
#
#   .. _${PROJECT_NAME}_GIT_REPOSITORY_REMOTE:
#
#   ``${PROJECT_NAME}_GIT_REPOSITORY_REMOTE=<remote-name>``
#
#     The git remote name given to the cloned repo.  This is needed for robust
#     git operations as described below (Default 'origin').  If a repo is
#     already cloned, then a remote in the already existing repo must exist
#     with this name or 
#
#   .. _${PROJECT_NAME}_BRANCH:
#
#   ``${PROJECT_NAME}_BRANCH=<branch>``
#
#     The branch of the base repo to explicitly checkout after clone (and on
#     each update).  The value of empty "" is allowed which results in the
#     default branch being checked out on clone (and the ``-b <branch>``
#     argument to be omitted from the ``git clone`` command).  The default
#     value determined by the variable
#     ``${${PROJECT_NAME}_REPOSITORY_BRANCH}}``.  The default value for
#     ``${PROJECT_NAME}_REPOSITORY_BRANCH`` is empty.
#
# If the base repo already exists, no initial clone is performed and it is
# assumed that it is in a state to allow it to be updated as described below.
#
# After the base repo is cloned, any missing extra git repositories are cloned
# using CMake/CTest code in this ``TRIBITS_CTEST_DRIVER()`` function (raw
# CTest does not support cloning a list of extra repos) using the command::
#
#   git clone [-b ${${PROJECT_NAME}_EXTRAREPO_BRANCH}] \
#     -o ${${PROJECT_NAME}_GIT_REPOSITORY_REMOTE} \
#     <extrarepo_url>
#
# where:
#
#   .. _${PROJECT_NAME}_EXTRAREPOS_BRANCH:
#
#   ``${PROJECT_NAME}_EXTRAREPOS_BRANCH=<extrarepo-branch>``
#
#     The branch ``<extrarepo-branch>`` that each extra VC repo that is
#     checked out.  The default value is set to ``${${PROJECT_NAME}_BRANCH}``.
#     If empty "", then the ``-b <branch>`` argument is omitted from the ``git
#     clone`` command.  (NOTE: Checking out a separate branch on the extra
#     repos from the base repo was needed for backward compatibility for the
#     Trilinos project and is not recommended usage as it violates the "single
#     branch" approach for using `gitdist`_.)
#
#   ``<extrarepo_url>``
#
#     The git repo remote URL given in the file
#     `${PROJECT_NAME}_EXTRAREPOS_FILE`_.
#
# When ``CTEST_DO_UPDATES=TRUE`` (after a possible initial clone), the
# function ``CTEST_UPDATE()`` is called to update the base git repo.  The base
# git repo is updated with the custom git commands executed inside of the
# ``CTEST_UPDATE()`` using::
#
#   $ git fetch ${${PROJECT_NAME}_GIT_REPOSITORY_REMOTE}
#   $ git clean -fdx         # Remove untracked ignored files
#   $ git reset --hard HEAD  # Clean files and set ORIG_HEAD to HEAD
#   $ git checkout -B ${${PROJECT_NAME}_BRANCH} \
#       --track origin/${${PROJECT_NAME}_BRANCH}   # Sets HEAD
#
# The above set of commands are the maximally robust way to update a git repo.
# They will correct any local state of the local repo and will put the local
# repo on the requested local tracking branch.  It can handled hard-reset
# remote branches, previous tracking branch now missing, etc.  The only
# requirement is that the remote repo pointed to at
# ``${${PROJECT_NAME}_GIT_REPOSITORY_REMOTE}`` is valid and has not changed
# since the repo was first cloned.  (NOTE: A future version of TriBITS may
# automate the update of this git remote.)
#
# If ``${PROJECT_NAME}_BRANCH`` is empty "", the last ``git checkout -B
# <branch> ...`` command is replaced with the git command::
#
#   $ git reset --hard @{u}  # Sets HEAD
#
# After the base git repo is updated inside of ``CTEST_UPDATE()`` as described
# above, each of the extra repos is updated using a similar set of git
# commands::
#
#   $ git fetch ${${PROJECT_NAME}_GIT_REPOSITORY_REMOTE}
#   $ git clean -fdx         # Remove untracked ignored files
#   $ git reset --hard HEAD  # Clean files and set ORIG_HEAD to HEAD
#   $ git checkout -B ${${PROJECT_NAME}_EXTRAREPO_BRANCH} \
#       --track origin/${${PROJECT_NAME}_EXTRAREPO_BRANCH}  # Sets HEAD
#
# where if ``${PROJECT_NAME}_EXTRAREPO_BRANCH`` is empty, the last ``git
# checkout -B <branch> ...`` command replaced with::
#
#   $ git reset --hard @{u}
#
# **WARNING:** This version of the ``git checkout -B <branch> ...`` command
# is not supported in older versions of git.  Therefore, a newer version of
# git is required when using named branches.
#
# The command ``git clone -fdx`` removes any untracked ignored files that may
# have been created since the last update (either by the build process or by
# someone messing around in that local git repository).  The command ``git
# reset --hard HEAD`` removes any untracked non-ignored files, any modified
# tracked files, and sets ``ORIG_HEAD`` to the current ``HEAD``.  This sets
# ``ORIG_HEAD`` after the initial clone (which is needed since ``ORIG_HEAD``
# is not set after the initial ``git clone`` command).  This allows using the
# range ``ORIG_HEAD..HEAD`` with ``git diff`` and ``git log`` commands even
# after the initial clone.  (Directly after the initial clone, the range
# ``ORIG_HEAD..HEAD`` will be empty). The git commands ``git checkout -B
# <branch> <remote>/<branch>`` or ``git reset --hard @{u}`` are used to update
# the local repo to match the remote tracking branch.  This is done to deal
# with a possible forced push of the remote tracking branch or even changing
# to different tracking branch (when using an explicit ``<branch>`` name).
#
# Note that the repository updating approach described above using non-empty
# ``${PROJECT_NAME}_BRANCH`` is more robust, because it can recover from a
# state where someone may have put a repo on a detached head or checked out a
# different branch.  One of these repos might get into this state when a
# person is messing around in the Nightly build and source directories to try
# to figure out what happened and forgot to put the repos back on the correct
# tracking branch.  Therefore, it is recommended to always set an explicit
# ``${PROJECT_NAME}_BRANCH`` to a non-null value like ``master`` or
# ``develop`` for the git repos, even if this branch is the default repo
# branch.
#
# .. _Other CTest Driver options (TRIBITS_CTEST_DRIVER()):
#
# **Other CTest Driver options (TRIBITS_CTEST_DRIVER()):**
#
# Other miscellaneous vars that can be set in the CTest -S script or as env
# vars are given below.
#
#   .. _CTEST_CMAKE_GENERATOR:
#
#   ``CTEST_CMAKE_GENERATOR="[Unix Makefiles|Ninja|..]"``
#
#     Built-in CTest variable that determines the CMake generator used in the
#     inner configure.  If an existing ``CMakeCache.txt`` file exists, then
#     the default value for the generator will be read out of that file.
#     Otherwise, the default generator is selected to be ``Unix Makefiles``.
#     Another popular option is ``Ninja``.  The value of this variable
#     determines the type of generator used in the inner CMake configure done
#     by the command ``ctest_configure(...)`` called in this function.  This
#     is done implicitly by CTest.  The selected generator has an impact on
#     what flags can be used in `CTEST_BUILD_FLAGS`_ since ``make`` and
#     ``ninja`` accept different arguments in some cases.
#
#   ``${PROJECT_NAME}_ENABLE_DEVELOPMENT_MODE=[TRUE|FALSE]``
#
#     Puts TriBITS configure into development mode (vs. release mode) in the
#     outer CTest -S script.  The default is provided by
#     ``${${PROJECT_NAME}_ENABLE_DEVELOPMENT_MODE_DEFAULT}}`` (which is
#     typically set in the `<projectDir>/Version.cmake`_ file).  See
#     `<Project>_ENABLE_DEVELOPMENT_MODE`_.
#
#   ``${PROJECT_NAME}_VERBOSE_CONFIGURE=[TRUE|FALSE]``
#
#     Make TriBITS run in verbose mode.  (Useful for debugging hard problems.)
#     See `<Project>_VERBOSE_CONFIGURE`_.
#
#   ``CTEST_CONFIGURATION_UNIT_TESTING=[TRUE|FALSE]``
#
#     If set to ``TRUE``, then ``TRIBITS_CTEST_DRIVER()`` is put in unit
#     testing mode and does not actually drive configure, build, test, and
#     submit.  This is used to drive automated testing of the code in
#     ``TRIBITS_CTEST_DRIVER()``.
#
# .. _Return value (TRIBITS_CTEST_DRIVER()):
#
# **Return value (TRIBITS_CTEST_DRIVER()):**
#
# Currently, the ctest -S script will return 0 if all of the requested
# operations completed without failure.  That is, the update, configure,
# build, tests, coverage, dynamic analysis and submits must pass with no CMake
# errors in order for a 0 return code to be returned.  Therefore, the return
# code from the ctest -S script can be used to drive other automated processes
# that require all passing builds and tests.
#
# ToDo: Add another mode that will return 0 if no errors are reported in the
# ctest -S driver script but ignore configure, build, and test failures that
# are submitted to a CDash site (and therefore will be reported there).
#
FUNCTION(TRIBITS_CTEST_DRIVER)

  MESSAGE("")
  MESSAGE("******************************")
  MESSAGE("*** TRIBITS_CTEST_DRIVER() ***")
  MESSAGE("******************************")
  MESSAGE("")

  INITIALIZE_ERROR_QUEUE()

  # The name of the source directory. Defaults to project name, but
  # can be overridden by the environment for cases in which the source
  # directory name does not match the project name.
  SET_DEFAULT_AND_FROM_ENV(CTEST_SOURCE_NAME ${PROJECT_NAME})

  MESSAGE(
    "\n***"
    "\n*** Setting input options to default and reading from env ..."
    "\n***\n")

  SET_DEFAULT_AND_FROM_ENV( CTEST_CONFIGURATION_UNIT_TESTING OFF )

  # The type of test (e.g. Nightly, Experimental, Continuous)
  SET_DEFAULT_AND_FROM_ENV( CTEST_TEST_TYPE Experimental )

  # The default track to send the build to. This can be changed to send
  # the data to a different nightly grouping on the dashboard.
  # If the test type is set to Experimental though the track is forced
  # to "Experimental" this is so that we can have experimental tests
  # on branches.
  IF(${PROJECT_NAME}_TESTING_TRACK)
    SET(${PROJECT_NAME}_TRACK_DEFAULT ${${PROJECT_NAME}_TESTING_TRACK})
  ELSE()
    SET(${PROJECT_NAME}_TRACK_DEFAULT "")
  ENDIF()
  print_var(${PROJECT_NAME}_TRACK_DEFAULT)
  SET_DEFAULT_AND_FROM_ENV(${PROJECT_NAME}_TRACK "${${PROJECT_NAME}_TRACK_DEFAULT}")
  IF(CTEST_TEST_TYPE STREQUAL "Experimental" OR CTEST_TEST_TYPE STREQUAL "EXPERIMENTAL")
    SET(${PROJECT_NAME}_TRACK "Experimental")
    MESSAGE("-- Test type is Experimental. Forcing ${PROJECT_NAME}_TRACK to Experimental")
    PRINT_VAR(${PROJECT_NAME}_TRACK)
  ENDIF()

  # The name of the site in the dashboard (almost never need to override this)
  SET_DEFAULT_AND_FROM_ENV( CTEST_SITE ${CTEST_SITE_DEFAULT} )

  # The root of the dashboard where ${PROJECT_NAME} will be cloned and the
  # BUILD directory will be create (only override for separate testing)
  SET_DEFAULT_AND_FROM_ENV( CTEST_DASHBOARD_ROOT "" )
  IF (CTEST_DASHBOARD_ROOT STREQUAL "PWD")
    SET(CTEST_DASHBOARD_ROOT ${CMAKE_CURRENT_BINARY_DIR})
    PRINT_VAR(CTEST_DASHBOARD_ROOT)
  ENDIF()

  # Verobse configure or now
  SET_DEFAULT_AND_FROM_ENV( ${PROJECT_NAME}_VERBOSE_CONFIGURE OFF )

  # Set the default compiler version
  SET_DEFAULT_AND_FROM_ENV(COMPILER_VERSION UNKNOWN)

  # The name of the build that appears in the dashboard
  SET_DEFAULT_AND_FROM_ENV( CTEST_BUILD_NAME
    "${HOST_TYPE}-${COMPILER_VERSION}-${BUILD_DIR_NAME}" )

  # Remove the entire build directory if it exists or not
  SET_DEFAULT_AND_FROM_ENV( CTEST_START_WITH_EMPTY_BINARY_DIRECTORY TRUE )

  # Call CTEST_START(...) to start a new CDash build case or not
  SET_DEFAULT_AND_FROM_ENV( CTEST_DO_NEW_START TRUE )

  # Remove an existing CMakeCache.txt file or not
  SET_DEFAULT_AND_FROM_ENV( CTEST_WIPE_CACHE TRUE )

  # Extra notes files suggested by user
  SET_DEFAULT_AND_FROM_ENV( CTEST_NOTES_FILES "" )
  SET(CTEST_NOTES_FILES_INPUT_BY_USER "${CTEST_NOTES_FILES}")

  # Select a default generator.
  SELECT_DEFAULT_GENERATOR()
  SET_DEFAULT_AND_FROM_ENV( CTEST_CMAKE_GENERATOR ${DEFAULT_GENERATOR})

  # Do the Git updates or not
  SET_DEFAULT_AND_FROM_ENV( CTEST_DO_UPDATES TRUE )

  # Generate the XML dependency output files or not in the inner CMake
  # configure.  There is really no reason to do this.  This option is
  # maintained for backward compatibility.
  SET_DEFAULT_AND_FROM_ENV( CTEST_GENERATE_DEPS_XML_OUTPUT_FILE FALSE )

  # Flags used on git when doing a Git update
  SET_DEFAULT_AND_FROM_ENV( CTEST_UPDATE_ARGS "")

  # Flags used on update when doing a Git update
  SET_DEFAULT_AND_FROM_ENV( CTEST_UPDATE_OPTIONS "")

  # If doing all-at-one approach, use new CMake/CTest/CDash features to allow
  # it to split out results into different rows on CDash like the
  # package-by-packages approach.
  SET_DEFAULT_AND_FROM_ENV( ${PROJECT_NAME}_CTEST_USE_NEW_AAO_FEATURES  FALSE )
 
  # Do all-at-once configure, build, test and submit (or package-by-package)
  IF ("${${PROJECT_NAME}_CTEST_DO_ALL_AT_ONCE_DEFAULT}" STREQUAL "")
    SET(${PROJECT_NAME}_CTEST_DO_ALL_AT_ONCE_DEFAULT FALSE)
  ENDIF()
  SET_DEFAULT_AND_FROM_ENV( ${PROJECT_NAME}_CTEST_DO_ALL_AT_ONCE
    ${${PROJECT_NAME}_CTEST_DO_ALL_AT_ONCE_DEFAULT} )

  # Extra inner CMake configure options that override everything
  SET_DEFAULT_AND_FROM_ENV(${PROJECT_NAME}_EXTRA_CONFIGURE_OPTIONS "")

  # Call CTEST_CONFIGURE(...) or not
  SET_DEFAULT_AND_FROM_ENV( CTEST_DO_CONFIGURE TRUE )

  # Flags passed to 'make'
  IF("${CTEST_CMAKE_GENERATOR}" MATCHES "Unix Makefiles")
    SET_DEFAULT_AND_FROM_ENV( CTEST_BUILD_FLAGS "-j2")
  ELSE()
    SET_DEFAULT_AND_FROM_ENV( CTEST_BUILD_FLAGS "")
  ENDIF()

  # Generate version date files or not
  SET_DEFAULT_AND_FROM_ENV(${PROJECT_NAME}_GENERATE_VERSION_DATE_FILES "")

  # Call CTEST_BUILD(...) or not
  SET_DEFAULT_AND_FROM_ENV( CTEST_DO_BUILD TRUE )

  # Call CTEST_BUILD( ... install ... ) or not
  SET_DEFAULT_AND_FROM_ENV( CTEST_DO_INSTALL FALSE )

  # Do the tests or not (Note: must be true for coverage testing)
  SET_DEFAULT_AND_FROM_ENV( CTEST_DO_TEST TRUE )

  # Pass through
  SET_DEFAULT_AND_FROM_ENV( ${PROJECT_NAME}_INNER_ENABLE_TESTS ON )

  # Pass through
  SET_DEFAULT_AND_FROM_ENV( ${PROJECT_NAME}_SKIP_CTEST_ADD_TEST FALSE )

  # Maximum number of procs an mpi test can request (if more are requested,
  # the test will be skipped).  Value of 0 means no override (determined
  # internally).
  SET_DEFAULT_AND_FROM_ENV( MPI_EXEC_MAX_NUMPROCS 0 )

  # How many tests ctest will spawn simultaneously
  SET_DEFAULT_AND_FROM_ENV( CTEST_PARALLEL_LEVEL 1 )

  # Turn off or change warnings-as-errors flag(s) (i.e. -Werror)
  SET_DEFAULT_AND_FROM_ENV( ${PROJECT_NAME}_WARNINGS_AS_ERRORS_FLAGS "" )

  # Do coverage testing or not
  SET_DEFAULT_AND_FROM_ENV( CTEST_DO_COVERAGE_TESTING FALSE )

  # Command to run to get coverage results
  SET_DEFAULT_AND_FROM_ENV( CTEST_COVERAGE_COMMAND gcov )

  # Do memory testing (i.e. valgrind) or not
  SET_DEFAULT_AND_FROM_ENV( CTEST_DO_MEMORY_TESTING FALSE )

  # Command used to perform the memory testing (i.e. valgrind)
  FIND_PROGRAM(VALGRIND_EXE NAMES valgrind)
  PRINT_VAR(VALGRIND_EXE)
  IF (VALGRIND_EXE)
    SET(CTEST_MEMORYCHECK_COMMAND_DEFAULT "${VALGRIND_EXE}")
  ELSE()
    SET(CTEST_MEMORYCHECK_COMMAND_DEFAULT)
  ENDIF()
  SET_DEFAULT_AND_FROM_ENV( CTEST_MEMORYCHECK_COMMAND "${CTEST_MEMORYCHECK_COMMAND_DEFAULT}" )

  # Set the default options
  SET_DEFAULT_AND_FROM_ENV( CTEST_MEMORYCHECK_COMMAND_OPTIONS "")

  # Generate the basic package dependencies XML file in the outer CTest
  # program.  This XML file is used to match up modified files with changed
  # TriBITS packages.  This file only needs to be generated in CI iterations
  # and is not needed in Nightly testing.  Turning off its generation can also
  # speed up local manual testing for large projects with lots of TriBITS
  # packages.
  SET_DEFAULT_AND_FROM_ENV( CTEST_GENERATE_OUTER_DEPS_XML_OUTPUT_FILE TRUE )

  # Generate and submit the CDash subprojects XML file
  SET_DEFAULT_AND_FROM_ENV( CTEST_SUBMIT_CDASH_SUBPROJECTS_DEPS_FILE TRUE )

  # Submit the results to the dashboard or not
  SET_DEFAULT_AND_FROM_ENV( CTEST_DO_SUBMIT TRUE )

  # Control the number of submit retries and the delay
  SET_DEFAULT_AND_FROM_ENV( CTEST_SUBMIT_RETRY_COUNT 5 ) # Default defined by ctest 
  SET_DEFAULT_AND_FROM_ENV( CTEST_SUBMIT_RETRY_DELAY 3 ) # Default defined by ctest?

  IF ("${${PROJECT_NAME}_ENABLE_SECONDARY_TESTED_CODE_DEFAULT}" STREQUAL "")
    SET(${PROJECT_NAME}_ENABLE_SECONDARY_TESTED_CODE_DEFAULT OFF)
  ENDIF()
  SET_DEFAULT_AND_FROM_ENV( ${PROJECT_NAME}_ENABLE_SECONDARY_TESTED_CODE
    ${${PROJECT_NAME}_ENABLE_SECONDARY_TESTED_CODE_DEFAULT} )

  # List of additional packages that will be enabled over the current set of
  # all packages (that would be set by ${PROJECT_NAME}_ENABLE_ALL_PACKAGES).
  SET_DEFAULT_AND_FROM_ENV( ${PROJECT_NAME}_ADDITIONAL_PACKAGES "" )

  # List of packages to not directly process.  .
  SET_DEFAULT_AND_FROM_ENV( ${PROJECT_NAME}_EXCLUDE_PACKAGES "" )
  STRING(REPLACE "," ";" ${PROJECT_NAME}_EXCLUDE_PACKAGES
    "${${PROJECT_NAME}_EXCLUDE_PACKAGES}" )

  IF(CTEST_TEST_TYPE STREQUAL "Nightly")
    SET_DEFAULT_AND_FROM_ENV(${PROJECT_NAME}_REPOSITORY_LOCATION
       "${${PROJECT_NAME}_REPOSITORY_LOCATION_NIGHTLY_DEFAULT}")
  ELSE()
    SET_DEFAULT_AND_FROM_ENV(${PROJECT_NAME}_REPOSITORY_LOCATION
       "${${PROJECT_NAME}_REPOSITORY_LOCATION_DEFAULT}")
  ENDIF()

  SET_DEFAULT_AND_FROM_ENV( ${PROJECT_NAME}_GIT_REPOSITORY_REMOTE "origin" )

  IF(${PROJECT_NAME}_REPOSITORY_BRANCH)
    SET(${PROJECT_NAME}_BRANCH_DEFAULT ${${PROJECT_NAME}_REPOSITORY_BRANCH})
  ELSE()
    SET(${PROJECT_NAME}_BRANCH_DEFAULT "")
  ENDIF()
  SET_DEFAULT_AND_FROM_ENV( ${PROJECT_NAME}_BRANCH "${${PROJECT_NAME}_BRANCH_DEFAULT}" )

  SET_DEFAULT_AND_FROM_ENV( ${PROJECT_NAME}_EXTRAREPOS_BRANCH "${${PROJECT_NAME}_BRANCH}" )

  SET_DEFAULT_AND_FROM_ENV( ${PROJECT_NAME}_ENABLE_DEVELOPMENT_MODE "${${PROJECT_NAME}_ENABLE_DEVELOPMENT_MODE_DEFAULT}" )

  # Select the ${PROJECT_NAME} packages to enable (empty means to select all
  # available).  This will override any disabled packages but not those
  # disabled by ${PROJECT_NAME}_EXCLUDE_PACKAGES.
  SET_DEFAULT_AND_FROM_ENV( ${PROJECT_NAME}_PACKAGES "" )
  SET(${PROJECT_NAME}_PACKAGES_USER_SELECTED ${${PROJECT_NAME}_PACKAGES})
  SPLIT("${${PROJECT_NAME}_PACKAGES_USER_SELECTED}" ","
    ${PROJECT_NAME}_PACKAGES_USER_SELECTED)
  SET(${PROJECT_NAME}_PACKAGES "")
  # Note: above, we have to keep the name ${PROJECT_NAME}_PACKAGES to maintain
  # backward compatibility of this CTest script but we want to let
  # ${PROJECT_NAME}_PACKAGES always be the full set of packages as defined by
  # the basic readin process.

  # Set the file that the extra repos will be read from
  #
  # NOTE: Here, we have no choice but to point into the "driver"
  # ${PROJECT_NAME} source tree because the local ${PROJECT_NAME} sources have
  # not even been checked out yet!  Unless, of course, we are unit testing in
  # which case we will use whatever has been passed in.

  IF (${PROJECT_NAME}_SKIP_EXTRAREPOS_FILE)
    SET(${PROJECT_NAME}_EXTRAREPOS_FILE_DEFAULT)
  ELSE()
    SET(${PROJECT_NAME}_EXTRAREPOS_FILE_DEFAULT
      "${TRIBITS_PROJECT_ROOT}/cmake/${${PROJECT_NAME}_EXTRA_EXTERNAL_REPOS_FILE_NAME}")
  ENDIF()
  SET_DEFAULT_AND_FROM_ENV(${PROJECT_NAME}_EXTRAREPOS_FILE
    "${${PROJECT_NAME}_EXTRAREPOS_FILE_DEFAULT}")

  # Select the set of extra external repos to add in packages.
  # These are the same types as CTEST_TEST_TYPE (e.g. 'Continuous' and
  # 'Nightly').  This is set by default to ${CTEST_TEST_TYPE} can be
  # overridden independent of ${CTEST_TEST_TYPE} also.
  #
  # If in release mode generally we do not want any external repositories
  # even though the CTEST_TEST_TYPE is set to "Nightly" for most release
  # builds.
  ASSERT_DEFINED(${PROJECT_NAME}_ENABLE_DEVELOPMENT_MODE)
  IF(${PROJECT_NAME}_ENABLE_DEVELOPMENT_MODE)
    SET(${PROJECT_NAME}_ENABLE_KNOWN_EXTERNAL_REPOS_TYPE_DEFAULT ${CTEST_TEST_TYPE})
  ELSE()
    SET(${PROJECT_NAME}_ENABLE_KNOWN_EXTERNAL_REPOS_TYPE_DEFAULT "None")
  ENDIF()
  SET_DEFAULT_AND_FROM_ENV( ${PROJECT_NAME}_ENABLE_KNOWN_EXTERNAL_REPOS_TYPE
     "${${PROJECT_NAME}_ENABLE_KNOWN_EXTERNAL_REPOS_TYPE_DEFAULT}" )

  SET_DEFAULT_AND_FROM_ENV(${PROJECT_NAME}_PRE_REPOSITORIES "")
  SPLIT("${${PROJECT_NAME}_PRE_REPOSITORIES}"  "," ${PROJECT_NAME}_PRE_REPOSITORIES)

  SET_DEFAULT_AND_FROM_ENV(${PROJECT_NAME}_EXTRA_REPOSITORIES "")
  SPLIT("${${PROJECT_NAME}_EXTRA_REPOSITORIES}"  "," ${PROJECT_NAME}_EXTRA_REPOSITORIES)

  # Set as part of CI testing in order to only enable modified packages
  SET_DEFAULT_AND_FROM_ENV( CTEST_ENABLE_MODIFIED_PACKAGES_ONLY OFF )

  # Set if implicitly enabled packages should be explicitly processed in
  # package-by-package mode.
  IF (CTEST_ENABLE_MODIFIED_PACKAGES_ONLY AND NOT CTEST_START_WITH_EMPTY_BINARY_DIRECTORY)
    SET( CTEST_EXPLICITLY_ENABLE_IMPLICITLY_ENABLED_PACKAGES_DEFAULT FALSE )
  ELSE()
    SET( CTEST_EXPLICITLY_ENABLE_IMPLICITLY_ENABLED_PACKAGES_DEFAULT TRUE )
  ENDIF()
  SET_DEFAULT_AND_FROM_ENV( CTEST_EXPLICITLY_ENABLE_IMPLICITLY_ENABLED_PACKAGES
    ${CTEST_EXPLICITLY_ENABLE_IMPLICITLY_ENABLED_PACKAGES_DEFAULT})

  IF (CTEST_ENABLE_MODIFIED_PACKAGES_ONLY)
    SET(${PROJECT_NAME}_ENABLE_ALL_FORWARD_DEP_PACKAGES_DEFAULT TRUE)
  ELSE()
    SET(${PROJECT_NAME}_ENABLE_ALL_FORWARD_DEP_PACKAGES_DEFAULT FALSE)
  ENDIF()
  SET_DEFAULT_AND_FROM_ENV( ${PROJECT_NAME}_ENABLE_ALL_FORWARD_DEP_PACKAGES
    ${${PROJECT_NAME}_ENABLE_ALL_FORWARD_DEP_PACKAGES_DEFAULT})

  # Set if we should disable enabled fwd packages based on disabled required deps.
  # To make testing robust, we need to do this.
  IF ("${${PROJECT_NAME}_DISABLE_ENABLED_FORWARD_DEP_PACKAGES_DEFAULT}" STREQUAL "")
    SET(${PROJECT_NAME}_DISABLE_ENABLED_FORWARD_DEP_PACKAGES_DEFAULT ON)
  ENDIF()
  SET_DEFAULT_AND_FROM_ENV(${PROJECT_NAME}_DISABLE_ENABLED_FORWARD_DEP_PACKAGES
    ${${PROJECT_NAME}_DISABLE_ENABLED_FORWARD_DEP_PACKAGES_DEFAULT})

  # Set second drop site and location
  SET_DEFAULT_AND_FROM_ENV( TRIBITS_2ND_CTEST_DROP_SITE "" )
  SET_DEFAULT_AND_FROM_ENV( TRIBITS_2ND_CTEST_DROP_LOCATION "" )

  MESSAGE(
    "\n***"
    "\n*** Setting unit testing input options to default and reading from env ..."
    "\n***\n")

  SET_DEFAULT_AND_FROM_ENV( CTEST_DEPENDENCY_HANDLING_UNIT_TESTING FALSE )

  SET_DEFAULT_AND_FROM_ENV( CTEST_UPDATE_UNIT_TESTING_MODE
    ${CTEST_DEPENDENCY_HANDLING_UNIT_TESTING} )

  SET_DEFAULT_AND_FROM_ENV( CTEST_UPDATE_RETURN_VAL 0 )

  IF (CTEST_DEPENDENCY_HANDLING_UNIT_TESTING)
    SET(GIT_EXECUTABLE /somebasedir/git)
  ENDIF()


  MESSAGE(
    "\n***"
    "\n*** Misc setup ..."
    "\n***\n")

  #
  # Setup and create the base dashboard directory if it is not created yet.
  #

  # NOTE: This is only used in general testing dashboard mode, not in local
  # experimental testing mode.

  IF (CTEST_DASHBOARD_ROOT)
    SET( CTEST_BINARY_NAME BUILD )
    SET( CTEST_SOURCE_DIRECTORY "${CTEST_DASHBOARD_ROOT}/${CTEST_SOURCE_NAME}")
    SET( CTEST_BINARY_DIRECTORY "${CTEST_DASHBOARD_ROOT}/${CTEST_BINARY_NAME}")
    IF (NOT EXISTS "${CTEST_DASHBOARD_ROOT}")
      MESSAGE("Creating the dashboard root directory \"${CTEST_DASHBOARD_ROOT}\" ...")
      FILE(MAKE_DIRECTORY "${CTEST_DASHBOARD_ROOT}")
    ENDIF()
  ENDIF()
  PRINT_VAR(CTEST_SOURCE_DIRECTORY)
  PRINT_VAR(CTEST_BINARY_DIRECTORY)

  SET(PROJECT_SOURCE_DIR "${CTEST_SOURCE_DIRECTORY}")
  SET(PROJECT_BINARY_DIR "${CTEST_BINARY_DIRECTORY}")
  PRINT_VAR(PROJECT_SOURCE_DIR)
  PRINT_VAR(PROJECT_BINARY_DIR)

  # Set override hook for unit testing
  SET_DEFAULT_AND_FROM_ENV( ${PROJECT_NAME}_SOURCE_DIRECTORY ${CTEST_SOURCE_DIRECTORY} )

  # Must be set here after CTEST_BINARY_DIRECTORY is set!
  SET(FAILED_PACKAGES_FILE_NAME "${CTEST_BINARY_DIRECTORY}/failedPackages.txt")

  #
  # Some platform-independent setup
  #

  INCLUDE("${TRIBITS_PROJECT_ROOT}/CTestConfig.cmake")
  SET(CTEST_USE_LAUNCHERS 1)

  # For coverage dashboards, send results to specialized dashboard if
  # requested
  IF (CTEST_DO_COVERAGE_TESTING)
    # Allow override of CDash drop site but use standard by default
    SET_DEFAULT(CTEST_DROP_SITE_COVERAGE_DEFAULT
      ${CTEST_DROP_SITE})
    SET_DEFAULT_AND_FROM_ENV(CTEST_DROP_SITE_COVERAGE
      "${CTEST_DROP_SITE_COVERAGE_DEFAULT}")
    SET(CTEST_DROP_SITE "${CTEST_DROP_SITE_COVERAGE}" )
    # Allow override of CDash drop location but use standard by default
    SET_DEFAULT(CTEST_DROP_LOCATION_COVERAGE_DEFAULT
      ${CTEST_DROP_LOCATION})
    SET_DEFAULT_AND_FROM_ENV(CTEST_DROP_LOCATION_COVERAGE
      "${CTEST_DROP_LOCATION_COVERAGE_DEFAULT}")
    SET(CTEST_DROP_LOCATION "${CTEST_DROP_LOCATION_COVERAGE}" )

    # NOTE: You must set these down below the include of
    # CTestConfig.cmake so that CTEST_DROP_SITE and CTEST_DROP_LOCATION read
    # from that file will set the defaults for the coverage options.

  ENDIF()

  #
  # Setup for the VC update
  #

  SET(CREATE_VC_UPDATE_FILE FALSE)

  SET(CTEST_UPDATE_COMMANDS_OUTPUT_FILE
    "${CTEST_BINARY_DIRECTORY}/UpdateCommandsOutput.txt")

  IF (CTEST_DO_UPDATES)

    SET(UPDATE_TYPE "git")
    MESSAGE("UPDATE_TYPE = '${UPDATE_TYPE}'")

    #
    # Set the initial clone command for if the local repo is missing
    #

    IF (${PROJECT_NAME}_BRANCH) 
      SET(CHECKOUT_BRANCH_ARG "-b ${${PROJECT_NAME}_BRANCH} ")
    ELSE()
      SET(CHECKOUT_BRANCH_ARG)
    ENDIF()

    SET( _CTEST_CHECKOUT_COMMAND
      "\"${GIT_EXECUTABLE}\" clone ${CHECKOUT_BRANCH_ARG}-o ${${PROJECT_NAME}_GIT_REPOSITORY_REMOTE} ${CTEST_UPDATE_ARGS} ${${PROJECT_NAME}_REPOSITORY_LOCATION}" )
    MESSAGE("CTEST_CHECKOUT_COMMAND=${_CTEST_CHECKOUT_COMMAND}")

    IF(NOT EXISTS "${CTEST_SOURCE_DIRECTORY}")
      MESSAGE("${CTEST_SOURCE_DIRECTORY} does not exist so setting up for an initial checkout")
      SET( CTEST_CHECKOUT_COMMAND "${_CTEST_CHECKOUT_COMMAND}")
      # NOTE: Just to be safe, only set CTEST_CHECKOUT_COMMAND to do a clone
      # if the repo does not already exist!
    ELSE()
      MESSAGE("${CTEST_SOURCE_DIRECTORY} exists so skipping the initial checkout.")
      SET(CREATE_VC_UPDATE_FILE TRUE)
    ENDIF()

    #
    # Set the git update command for an already cloned repo
    #

    # CTest always needs the raw git command in order to do stuff like get the
    # version of the repo before and after the update, even if you provide a
    # custom update command.
    SET(CTEST_GIT_COMMAND "${GIT_EXECUTABLE}") 
    MESSAGE("CTEST_GIT_COMMAND=${CTEST_GIT_COMMAND}")
    # NOTE: You can't put the above command "${GIT_EXECUTABLE}" in quotes like
    # "'${GIT_EXECUTABLE}'" or "\"${GIT_EXECUTABLE}\"" or it will not work and
    # ctest_update() will return failed!

    # Provide a custom command to do the update

    SET(CTEST_GIT_UPDATE_CUSTOM
      "${CMAKE_COMMAND}"
      -DGIT_EXE=${GIT_EXECUTABLE}
      -DREMOTE_NAME=${${PROJECT_NAME}_GIT_REPOSITORY_REMOTE}
      -DBRANCH=${${PROJECT_NAME}_BRANCH}
      -DUNIT_TEST_MODE=${CTEST_DEPENDENCY_HANDLING_UNIT_TESTING}
      -DOUTPUT_FILE=${CTEST_UPDATE_COMMANDS_OUTPUT_FILE}
      -P ${THIS_CMAKE_CURRENT_LIST_DIR}/tribits_ctest_update_commands_wrapper.cmake
      )
    MESSAGE("CTEST_GIT_UPDATE_CUSTOM=${CTEST_GIT_UPDATE_CUSTOM}")

  ENDIF()

  #
  # This hack is a workaround for a bug in CMake. Since we're calling
  # ctest_start() inside a function scope, CTEST_RUN_CURRENT_SCRIPT doesn't
  # get set in the root scope, and setting it manually at the root or via
  # PARENT_SCOPE isn't scalable since ctest_start() is nested inside several
  # layers of functions in some cases. So, instead, we just turn CTEST_COMMAND
  # into a no-op.
  #

  SET(CTEST_SOURCE_DIRECTORY ${CTEST_SOURCE_DIRECTORY} CACHE INTERNAL "")
  SET(CTEST_BINARY_DIRECTORY ${CTEST_BINARY_DIRECTORY} CACHE INTERNAL "")
  IF ("${CTEST_COMMAND}" STREQUAL "")
    SET(CTEST_COMMAND "${CMAKE_COMMAND} -E echo")
  ENDIF()
  SET(CTEST_COMMAND ${CTEST_COMMAND} CACHE INTERNAL "")

  #
  # Empty out the binary directory
  #

  IF (CTEST_START_WITH_EMPTY_BINARY_DIRECTORY AND NOT CTEST_DO_NEW_START)
    MESSAGE("\nSkipping calling ctest_empty_binary_directory() even though"
      "CTEST_START_WITH_EMPTY_BINARY_DIRECTORY='${CTEST_START_WITH_EMPTY_BINARY_DIRECTORY}'"
      " because CTEST_DO_NEW_START='${CTEST_DO_NEW_START}'!"
      "  You can't empty the binary directory unless you will be starting"
      " a new dashboard!")
  ELSEIF (CTEST_START_WITH_EMPTY_BINARY_DIRECTORY)
    MESSAGE("\nCleaning out binary directory '${CTEST_BINARY_DIRECTORY}' ...")
    CTEST_EMPTY_BINARY_DIRECTORY("${CTEST_BINARY_DIRECTORY}")
  ENDIF()
  # NOTE: The above command will *not* delete the build directory unless there
  # is a CMakeLists.txt file in this directory.  I think Kitware put in this
  # check to avoid accidentally deleting the wrong directory by accident.
  # Also note that you have to delete the build directory before any commands
  # are run that would write files to them (and many of the steps in this
  # process do write files to the binary directory other than just CMake).

  MESSAGE(
    "\n***"
    "\n*** Read in the set of extra repos ..."
    "\n***\n")

  TRIBITS_SETUP_EXTRAREPOS()

  # NOTE: You have to set up the set of extra repos before you can read the
  # Dependencies.cmake files since the extra repos must be cloned first.

  MESSAGE(
    "\n***"
    "\n*** Start up a new dashboard calling ctest_start(...) ..."
    "\n***\n")

  SET(CTEST_TESTING_TAG_FILE "${CTEST_BINARY_DIRECTORY}/Testing/TAG")

  PRINT_VAR(CTEST_TEST_TYPE)
  PRINT_VAR(${PROJECT_NAME}_TRACK)
  
  SET(CTEST_START_ARGS ${CTEST_TEST_TYPE})
  IF(${PROJECT_NAME}_TRACK)
    LIST(APPEND CTEST_START_ARGS TRACK ${${PROJECT_NAME}_TRACK})
  ENDIF()

  IF (CTEST_DO_NEW_START)

    MESSAGE(
      "\n***"
      "\n*** Start up a new dashboard calling ctest_start(...) ..."
      "\n***\n")

    # NOTE: If the source directory does not yet exist, then CTEST_START()
    # will clone it!
  
  ELSE()

    MESSAGE(
      "\n***"
      "\n*** Use previous dashboard calling ctest_start(... APPEND) due to CTEST_DO_NEW_START='${CTEST_DO_NEW_START}' ..."
      "\n***\n")

    IF (EXISTS "${CTEST_TESTING_TAG_FILE}")
      FILE(READ "${CTEST_TESTING_TAG_FILE}" TAG_FILE_CONTENTS_STR)
      MESSAGE(
	"\nPrevious file:"
	"\n"
	"\n  '${CTEST_TESTING_TAG_FILE}'"
	"\n"
	"\nexists with contents:\n"
	"\n"
	"${TAG_FILE_CONTENTS_STR}\n")
    ELSE()
      MESSAGE(FATAL_ERROR
	"ERROR: Previous file '${CTEST_TESTING_TAG_FILE}' does NOT exist!"
	"  A previous ctest_start() was not called.  Please call again"
	" this time setting CTEST_DO_NEW_START=TRUE")
    ENDIF()

    LIST(APPEND CTEST_START_ARGS APPEND)

  ENDIF()

  MESSAGE("\nCalling ctest_start(${CTEST_START_ARGS})... \n\n")
  CTEST_START(${CTEST_START_ARGS})

  TRIBITS_REMEMBER_IF_CONFIGURE_ATTEMPTED()

  MESSAGE(
    "\n***"
    "\n*** Update the source code repositories ..."
    "\n***\n")

  SET(UPDATE_FAILED FALSE)

  IF (CTEST_DO_UPDATES)

    IF(NOT EXISTS "${CTEST_SOURCE_DIRECTORY}")
      QUEUE_ERROR("error: source directory does not exist just prior to CTEST_UPDATE call -- initial checkout did not work")
      REPORT_QUEUED_ERRORS()
      RETURN()
    ENDIF()

    MESSAGE("\nCalling CTEST_UPDATE() to update base source repo '${CTEST_SOURCE_DIRECTORY}' ...")
    CTEST_UPDATE_WRAPPER( SOURCE "${CTEST_SOURCE_DIRECTORY}"
      RETURN_VALUE  CTEST_UPDATE_RETURN_VAL)
    MESSAGE("CTEST_UPDATE(...) returned '${CTEST_UPDATE_RETURN_VAL}' [ rtn >= 0: num files; rnt == -1: error ]")

    IF ("${CTEST_UPDATE_RETURN_VAL}" STREQUAL "-1")
      SET(UPDATE_FAILED TRUE)
    ENDIF()

    # Print the output from the git commands called in ctest_update()
    IF (EXISTS "${CTEST_UPDATE_COMMANDS_OUTPUT_FILE}")
      FILE(READ "${CTEST_UPDATE_COMMANDS_OUTPUT_FILE}" CTEST_UPDATE_COMMANDS_OUTPUT_STR)
      MESSAGE("\n------------------------------------------------------------------------")
      MESSAGE("${CTEST_UPDATE_COMMANDS_OUTPUT_STR}")
      MESSAGE("------------------------------------------------------------------------\n")
    ENDIF()

    TRIBITS_CLONE_OR_UPDATE_EXTRA_REPOS(${CTEST_UPDATE_RETURN_VAL}  LOC_UPDATE_FAILED)
    IF (LOC_UPDATE_FAILED)
      SET(UPDATE_FAILED TRUE)
    ENDIF()

    IF (CREATE_VC_UPDATE_FILE)
      TRIBITS_CREATE_REPO_UPDATES_FILE()
      # NOTE: We can only create the Updates.txt file using `gitdist
      # ... ORIG_HEAD..HEAD` when doing an update and not after the initial
      # clone.  That is because ORIG_HEAD will not exist for the base git repo
      # after the initial clone.
    ENDIF()

    IF (UPDATE_FAILED)
      MESSAGE("Update FAILED!")
    ENDIF()

  ELSE()

     MESSAGE("Skipping the update by request!")

  ENDIF()


  MESSAGE(
    "\n***"
    "\n*** Read in the set of packages and their dependencies ..."
    "\n***\n")

  # NOTE: You must read the Dependencies.cmake files *after* you have cloned
  # (or updated) all of the code!

  TRIBITS_SETUP_PACKAGES()

  SET(CDASH_SUBPROJECT_XML_FILE
    "${CTEST_BINARY_DIRECTORY}/${${PROJECT_NAME}_CDASH_SUBPROJECT_DEPS_XML_FILE_NAME}")
  PRINT_VAR(CDASH_SUBPROJECT_XML_FILE)

  MESSAGE(
    "\n***"
    "\n*** Disabling packages based on what was set in ${PROJECT_NAME}_EXCLUDE_PACKAGES ..."
    "\n***\n")

  DISABLE_EXCLUDED_PACKAGES()

  IF (NOT CTEST_ENABLE_MODIFIED_PACKAGES_ONLY)
    MESSAGE(
      "\n***"
      "\n*** Determining what packages to enable based what was set in ${PROJECT_NAME}_PACKAGES by the user ..."
      "\n***\n")
    ENABLE_USER_SELECTED_PACKAGES()
  ELSE()
    MESSAGE(
      "\n***"
      "\n*** Determining what packages to enable based on what changed (and failed last CI iteration) ..."
      "\n***\n")
    ENABLE_ONLY_MODIFIED_PACKAGES()
  ENDIF()


  MESSAGE(
    "\n***"
    "\n*** Adjust the package dependencies to enable upstream and"
    " (optionally) downstream packages ..."
    "\n***"
    )

  SET(${PROJECT_NAME}_ENABLE_TESTS ON)
  SET(${PROJECT_NAME}_ENABLE_EXAMPLES ON)
  SET(${PROJECT_NAME}_ENABLE_ALL_OPTIONAL_PACKAGES ON)
  SET(DO_PROCESS_MPI_ENABLES FALSE) # Should not be needed but CMake is messing up
  TRIBITS_ADJUST_AND_PRINT_PACKAGE_DEPENDENCIES()
  # Above sets ${PROJECT_NAME}_NUM_ENABLED_PACKAGES

  SELECT_FINAL_SET_OF_PACKAGES_TO_DIRECTLY_TEST()
  # Above sets ${PROJECT_NAME}_PACKAGES_TO_DIRECTLY_TEST

  TRIBITS_PRINT_ENABLED_PACKAGES_LIST_FROM_VAR( ${PROJECT_NAME}_PACKAGES_TO_DIRECTLY_TEST
    "\nFinal set of packages to be explicitly processed by CTest/CDash" ON FALSE)

  MESSAGE(
    "\n***"
    "\n*** Determine if to go ahead with configure, build, test ..."
    "\n***")

  IF (CTEST_ENABLE_MODIFIED_PACKAGES_ONLY
    AND ${PROJECT_NAME}_NUM_ENABLED_PACKAGES GREATER 0
    AND MODIFIED_PACKAGES_LIST
    )
    MESSAGE("\nMODIFIED_PACKAGES_LIST='${MODIFIED_PACKAGES_LIST}'"
      ":  Found modified packages, processing enabled packages!\n")
  ELSE()
    MESSAGE(
      "\nCTEST_ENABLE_MODIFIED_PACKAGES_ONLY=${CTEST_ENABLE_MODIFIED_PACKAGES_ONLY}"
      "  Running in regular mode, processing all enabled packages!\n")
  ENDIF()

  IF (${PROJECT_NAME}_NUM_ENABLED_PACKAGES GREATER 0)
    MESSAGE(
      "\n${PROJECT_NAME}_NUM_ENABLED_PACKAGES=${${PROJECT_NAME}_NUM_ENABLED_PACKAGES}:"
      "  Configuring packages!\n")
  ELSE()
    MESSAGE(
      "\n${PROJECT_NAME}_NUM_ENABLED_PACKAGES=${${PROJECT_NAME}_NUM_ENABLED_PACKAGES}:"
      "  Exiting the script!\n")
    REPORT_QUEUED_ERRORS()
    RETURN()
  ENDIF()

  #
  # Delete the CMakeCache.txt file and the CMakeFiles directory for a clean
  # reconfigure.
  #

  IF (CTEST_DO_CONFIGURE AND CTEST_WIPE_CACHE)
    SET(CACHE_FILE_NAME "${CTEST_BINARY_DIRECTORY}/CMakeCache.txt")
    IF (EXISTS "${CACHE_FILE_NAME}")
      MESSAGE("Removing existing cache file '${CACHE_FILE_NAME}' ...")
      FILE(REMOVE "${CACHE_FILE_NAME}")
    ENDIF()
    SET(CMAKE_FILES_DIR "${CTEST_BINARY_DIRECTORY}/CMakeFiles/")
    IF (EXISTS "${CMAKE_FILES_DIR}")
      MESSAGE("Removing existing '${CMAKE_FILES_DIR}' ...")
      FILE(REMOVE_RECURSE "${CMAKE_FILES_DIR}")
    ENDIF()
  ENDIF()
  # NOTE: Above, we have to delete the CMakeCache.txt file only after we are
  # sure we are going to be configuring packages.  There must be a
  # CMakeCache.txt file present in the binary directory or the
  # CTEST_EMPTY_BINARY_DIRECTORY() command will *not* actually delete the
  # build directory!  Also, with updated versions of CMake (2.8.10 and above)
  # you have to delete the CMakeFiles directory in addition to the
  # CMakeCache.txt file or it will not configure correctly (due to Fortran/C
  # linkage tests for one).

  MESSAGE(
    "\n***"
    "\n*** Uploading update, notes, and the subproject dependencies XML files ..."
    "\n***\n"
    )

  # Set up a list of notes files that don't include the CMakeCache.clean.txt
  # file which will change for every submit in the package-by-package mode.

  SET(CTEST_NOTES_FILES_WO_CACHE)

  SET(REPO_VERSION_FILE "${CTEST_BINARY_DIRECTORY}/${PROJECT_NAME}RepoVersion.txt")

  SET(MULTIREPO_GIT_UPDATES_FILE "${CTEST_BINARY_DIRECTORY}/Updates.txt" )
  IF (EXISTS "${MULTIREPO_GIT_UPDATES_FILE}")
    LIST(APPEND CTEST_NOTES_FILES_WO_CACHE "${MULTIREPO_GIT_UPDATES_FILE}")
  ENDIF()

  IF (EXISTS "${CTEST_UPDATE_COMMANDS_OUTPUT_FILE}")
    LIST(APPEND CTEST_NOTES_FILES_WO_CACHE "${CTEST_UPDATE_COMMANDS_OUTPUT_FILE}" )
  ENDIF()

  # Tack on any notes files that the client might have set to the end of these
  print_var(CTEST_NOTES_FILES_INPUT_BY_USER)
  IF (NOT "${CTEST_NOTES_FILES_INPUT_BY_USER}" STREQUAL "")
    LIST(APPEND CTEST_NOTES_FILES_WO_CACHE "${CTEST_NOTES_FILES_INPUT_BY_USER}")
  ENDIF()

  PRINT_VAR(CTEST_NOTES_FILES_WO_CACHE)

  # Note: We must only do the submit after we have decided if there are any
  # packages to enable or not and otherwise exit the script!

  IF (UPDATE_FAILED)
    MESSAGE(SEND_ERROR
      "The VC update failed so submitting update so don't perform any extra actions!")
    IF (CTEST_DO_SUBMIT)
      SET(CTEST_NOTES_FILES "${CTEST_NOTES_FILES_WO_CACHE}")
      TRIBITS_CTEST_SUBMIT( PARTS update notes )
    ENDIF()
  ENDIF()

  IF (CTEST_DO_SUBMIT AND EXISTS ${CDASH_SUBPROJECT_XML_FILE})
    TRIBITS_CTEST_SUBMIT( FILES ${CDASH_SUBPROJECT_XML_FILE})
    MESSAGE("\nSubmitted subproject dependencies XML file!")
  ELSE()
    MESSAGE("\nSkipping submitted subproject dependencies XML file on request!")
  ENDIF()

  MESSAGE(
    "\n***"
    "\n*** Configure, build, test, and submit results for ${PROJECT_NAME} packages:"
    "\n***")

  SET(CMAKE_CACHE_CLEAN_FILE "${CTEST_BINARY_DIRECTORY}/CMakeCache.clean.txt")
  SET(${PROJECT_NAME}_FAILED_PACKAGES)

  IF (UPDATE_FAILED)

    MESSAGE("\nUpdate failed so skipping any further actions!\n")

  ELSEIF(
    CTEST_DO_CONFIGURE
    OR
    CTEST_DO_BUILD
    OR
    CTEST_DO_TEST
    OR
    CTEST_DO_MEMORY_TESTING
    )

    IF (${PROJECT_NAME}_CTEST_DO_ALL_AT_ONCE)

      TRIBITS_CTEST_ALL_AT_ONCE()

    ELSE()

      TRIBITS_CTEST_PACKAGE_BY_PACKAGE()

    ENDIF()

  ELSE()

    MESSAGE("\nSkipping processing anything else since not requested to"
      " configure, build, test, or run memory tests!\n")

  ENDIF()

  IF(${PROJECT_NAME}_FAILED_PACKAGES)
    MESSAGE(
      "\nFinal set of packages that had any failures:"
        " '${${PROJECT_NAME}_FAILED_PACKAGES}'")
  ENDIF()

  # Write a file listing the packages that failed.  This will be read in on the next CI
  # iteration since these packages must be enabled
  FILE(WRITE "${FAILED_PACKAGES_FILE_NAME}" "${${PROJECT_NAME}_FAILED_PACKAGES}\n")

  REPORT_QUEUED_ERRORS()

  STRING(REPLACE "submit.php"
       "index.php" CDASH_PROJECT_LOCATION
       "${CTEST_DROP_LOCATION}")
  MULTILINE_SET( SEE_CDASH_LINK_STR
    "\nSee results for:\n"
    "  Site: ${CTEST_SITE}\n"
    "  Build Name: ${CTEST_BUILD_NAME}\n"
    "at:\n"
    "  http://${CTEST_DROP_SITE}${CDASH_PROJECT_LOCATION}&display=project\n"
    )
  # ToDo: Above: We would love to provide the buildID to point to the exact
  # URL but CTest does not currently give that to you.

  IF ((NOT UPDATE_FAILED) AND ("${${PROJECT_NAME}_FAILED_PACKAGES}" STREQUAL ""))
    MESSAGE(
      "${SEE_CDASH_LINK_STR}\n"
      "TRIBITS_CTEST_DRIVER: OVERALL: ALL PASSED\n")
  ELSE()
    # ToDo: Find out why other breaking tests don't fail when FATAL_ERROR is
    # removed!
    MESSAGE(FATAL_ERROR
      "${SEE_CDASH_LINK_STR}\n"
      "TRIBITS_CTEST_DRIVER: OVERALL: ALL FAILED\n")
    # NOTE: FATAL_ERROR is needed so that the ctest -S script returns != 0
    # Also, it is critical to display the "See results" in this
    # MESSAGE(FATAL_ERROR ...) command in order for it to be printed last.
    # Otherwise, if you run with ctest -V -S, then the output from
    # CTEST_TEST() will be printed last :-(
  ENDIF()

ENDFUNCTION()
