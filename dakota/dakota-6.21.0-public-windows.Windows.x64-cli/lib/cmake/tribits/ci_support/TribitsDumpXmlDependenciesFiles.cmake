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


#
# This file gets included in the main TriBITS framework.  It is put here to
# reduce the size of the tribits/core/ directory.
#


FUNCTION(TRIBITS_WRITE_DEPS_TO_XML_STRING  PACKAGE_NAME  LIST_TYPE
  XML_VAR
  )

  SET(LOC_XML "${${XML_VAR}}")

  SET(DEPS_VAR ${PACKAGE_NAME}_${LIST_TYPE})
  ASSERT_DEFINED(DEPS_VAR)
  SET(DEPS ${${DEPS_VAR}})

  #PRINT_VAR(PACKAGE_NAME)
  #PRINT_VAR(DEPS)

  IF (NOT DEPS)

    LIST(APPEND LOC_XML
      "    <${LIST_TYPE}/>\n" )

  ELSE()

    SET(VALUE_STR "")

    FOREACH(DEP ${DEPS})

      IF(VALUE_STR)
        SET(VALUE_STR "${VALUE_STR},")
      ENDIF()

      SET(VALUE_STR "${VALUE_STR}${DEP}")

    ENDFOREACH()

    LIST(APPEND LOC_XML
      "    <${LIST_TYPE} value=\"${VALUE_STR}\"/>\n" )

  ENDIF()

  IF (LOC_XML)
    SET(${XML_VAR} "${LOC_XML}" PARENT_SCOPE)
  ENDIF()

ENDFUNCTION()


#
# Function that writes the dependency information for ${PROJECT_NAME} into
# an XML file for other tools to use.
#

FUNCTION(TRIBITS_DUMP_DEPS_XML_FILE)

  SET(DEPS_XM)

  GET_FILENAME_COMPONENT(PROJECT_BASE_DIR_NAME  "${${PROJECT_NAME}_SOURCE_DIR}"  NAME)

  LIST(APPEND DEPS_XML
    "<PackageDependencies project=\"${PROJECT_NAME}\" baseDirName=\"${PROJECT_BASE_DIR_NAME}\">\n"
     )

  SET(PACKAGE_IDX 0)
  FOREACH(TRIBITS_PACKAGE ${${PROJECT_NAME}_SE_PACKAGES})

    LIST(GET ${PROJECT_NAME}_SE_PACKAGE_DIRS ${PACKAGE_IDX} PACKAGE_DIR)

    #MESSAGE("")
    #PRINT_VAR(PACKAGE_IDX)
    #PRINT_VAR(TRIBITS_PACKAGE)
    #PRINT_VAR(PACKAGE_DIR)

    LIST(APPEND DEPS_XML
      "  <Package name=\"${TRIBITS_PACKAGE}\" dir=\"${PACKAGE_DIR}\" type=\"${${TRIBITS_PACKAGE}_TESTGROUP}\">\n")

    TRIBITS_WRITE_DEPS_TO_XML_STRING(${TRIBITS_PACKAGE} LIB_REQUIRED_DEP_PACKAGES DEPS_XML)
    TRIBITS_WRITE_DEPS_TO_XML_STRING(${TRIBITS_PACKAGE} LIB_OPTIONAL_DEP_PACKAGES DEPS_XML)
    TRIBITS_WRITE_DEPS_TO_XML_STRING(${TRIBITS_PACKAGE} TEST_REQUIRED_DEP_PACKAGES DEPS_XML)
    TRIBITS_WRITE_DEPS_TO_XML_STRING(${TRIBITS_PACKAGE} TEST_OPTIONAL_DEP_PACKAGES DEPS_XML)
    TRIBITS_WRITE_DEPS_TO_XML_STRING(${TRIBITS_PACKAGE} LIB_REQUIRED_DEP_TPLS DEPS_XML)
    TRIBITS_WRITE_DEPS_TO_XML_STRING(${TRIBITS_PACKAGE} LIB_OPTIONAL_DEP_TPLS DEPS_XML)
    TRIBITS_WRITE_DEPS_TO_XML_STRING(${TRIBITS_PACKAGE} TEST_REQUIRED_DEP_TPLS DEPS_XML)
    TRIBITS_WRITE_DEPS_TO_XML_STRING(${TRIBITS_PACKAGE} TEST_OPTIONAL_DEP_TPLS DEPS_XML)

    LIST(APPEND DEPS_XML
      "    <EmailAddresses>\n"
      "      <Regression address=\"${${TRIBITS_PACKAGE}_REGRESSION_EMAIL_LIST}\"/>\n"
      "    </EmailAddresses>\n"
      )

    LIST(APPEND DEPS_XML
      "    <ParentPackage value=\"${${TRIBITS_PACKAGE}_PARENT_PACKAGE}\"/>\n"
      )

    LIST(APPEND DEPS_XML
      "  </Package>\n" )

    MATH(EXPR PACKAGE_IDX "${PACKAGE_IDX}+1")

  ENDFOREACH()

  LIST(APPEND DEPS_XML
    "</PackageDependencies>\n" )

  #PRINT_VAR(DEPS_XML)
  STRING(REPLACE "\n;" "\n" DEPS_XML "${DEPS_XML}")
  FILE(WRITE ${${PROJECT_NAME}_DEPS_XML_OUTPUT_FILE} "${DEPS_XML}" )

ENDFUNCTION()


#
# Macro that ouptuts XML dependency files
#

MACRO(TRIBITS_WRITE_XML_DEPENDENCY_FILES)

  IF (${PROJECT_NAME}_ENABLE_CONFIGURE_TIMING)
    TIMER_GET_RAW_SECONDS(WRITE_DEPENDENCY_FILES_TIME_START_SECONDS)
  ENDIF()

  #PRINT_VAR(${PROJECT_NAME}_DEPS_XML_OUTPUT_FILE)
  IF (${PROJECT_NAME}_DEPS_XML_OUTPUT_FILE)
    IF (NOT IS_ABSOLUTE ${${PROJECT_NAME}_DEPS_XML_OUTPUT_FILE})
      SET(${PROJECT_NAME}_DEPS_XML_OUTPUT_FILE
        ${CMAKE_CURRENT_BINARY_DIR}/${${PROJECT_NAME}_DEPS_XML_OUTPUT_FILE})
    ENDIF()
    MESSAGE("" )
    MESSAGE("Dumping the XML dependencies file ${${PROJECT_NAME}_DEPS_XML_OUTPUT_FILE} ..." )
    TRIBITS_DUMP_DEPS_XML_FILE()
  ENDIF()

  #PRINT_VAR(${PROJECT_NAME}_DEPS_HTML_OUTPUT_FILE)
  IF (${PROJECT_NAME}_DEPS_HTML_OUTPUT_FILE AND ${PROJECT_NAME}_DEPS_XML_OUTPUT_FILE)
    IF (NOT IS_ABSOLUTE ${${PROJECT_NAME}_DEPS_HTML_OUTPUT_FILE})
      SET(${PROJECT_NAME}_DEPS_HTML_OUTPUT_FILE
        ${CMAKE_CURRENT_BINARY_DIR}/${${PROJECT_NAME}_DEPS_HTML_OUTPUT_FILE})
    ENDIF()
    MESSAGE("" )
    MESSAGE("Dumping the HTML dependencies webpage file ${${PROJECT_NAME}_DEPS_HTML_OUTPUT_FILE} ..." )
    EXECUTE_PROCESS(
      COMMAND ${PYTHON_EXECUTABLE}
        ${${PROJECT_NAME}_TRIBITS_DIR}/${TRIBITS_CI_SUPPORT_DIR}/dump-package-dep-table.py
        --input-xml-deps-file=${${PROJECT_NAME}_DEPS_XML_OUTPUT_FILE}
        --output-html-deps-file=${${PROJECT_NAME}_DEPS_HTML_OUTPUT_FILE} )
  ENDIF()

  #PRINT_VAR(${PROJECT_NAME}_CDASH_DEPS_XML_OUTPUT_FILE)
  IF (${PROJECT_NAME}_CDASH_DEPS_XML_OUTPUT_FILE AND ${PROJECT_NAME}_DEPS_XML_OUTPUT_FILE)
    IF (NOT IS_ABSOLUTE ${${PROJECT_NAME}_CDASH_DEPS_XML_OUTPUT_FILE})
      SET(${PROJECT_NAME}_CDASH_DEPS_XML_OUTPUT_FILE ${CMAKE_CURRENT_BINARY_DIR}/${${PROJECT_NAME}_CDASH_DEPS_XML_OUTPUT_FILE})
    ENDIF()
    MESSAGE("" )
    MESSAGE("Dumping the CDash XML dependencies file ${${PROJECT_NAME}_CDASH_DEPS_XML_OUTPUT_FILE} ..." )
    EXECUTE_PROCESS(
      COMMAND ${PYTHON_EXECUTABLE}
        ${${PROJECT_NAME}_TRIBITS_DIR}/${TRIBITS_CTEST_DRIVER_DIR}/dump-cdash-deps-xml-file.py
        --input-xml-deps-file=${${PROJECT_NAME}_DEPS_XML_OUTPUT_FILE}
        --output-cdash-deps-xml-file=${${PROJECT_NAME}_CDASH_DEPS_XML_OUTPUT_FILE} )
  ENDIF()

  IF (${PROJECT_NAME}_ENABLE_CONFIGURE_TIMING)
    TIMER_GET_RAW_SECONDS(WRITE_DEPENDENCY_FILES_TIME_STOP_SECONDS)
    IF (${PROJECT_NAME}_DEPS_XML_OUTPUT_FILE
      OR ${PROJECT_NAME}_DEPS_HTML_OUTPUT_FILE
      OR ${PROJECT_NAME}_CDASH_DEPS_XML_OUTPUT_FILE
      )
      TIMER_PRINT_REL_TIME(${WRITE_DEPENDENCY_FILES_TIME_START_SECONDS}
        ${WRITE_DEPENDENCY_FILES_TIME_STOP_SECONDS}
        "\nTotal time to write dependency files")
    ENDIF()
  ENDIF()

ENDMACRO()

