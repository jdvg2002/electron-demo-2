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
# @FUNCTION: ASSERT_DEFINED()
#
# Assert that a variable is defined and if not call ``MESSAGE(SEND_ERROR
# ...)``.
#
# Usage::
#
#   ASSERT_DEFINED(<varName>)
#
# This is used to get around the problem of CMake not asserting the
# dereferencing of undefined variables.  For example, how does one know if one
# did not misspell the name of a variable in an if statement like::
#
#   IF (SOME_VARBLE)
#     ...
#   ENDIF()
#
# ?
#
#  If one misspelled the variable ``SOME_VARBLE`` (which is likely in this
#  case), then the if statement will always be false!  To avoid this problem
#  when one always expects that a variable is explicitly set, instead do::
#
#   ASSERT_DEFINED(SOME_VARBLE)
#   IF (SOME_VARBLE)
#     ...
#   ENDIF()
#
# Now if one misspells this variable, then CMake will asset and stop
# processing.  This is not a perfect solution since one can misspell the
# variable name in the following if statement but typically one would always
# just copy and paste between the two statements so these names are always the
# same.  This is the best that can be done in CMake unfortunately to catch
# usage of misspelled undefined variables.
#
FUNCTION(ASSERT_DEFINED VARS)
  FOREACH(VAR ${VARS})
    IF(NOT DEFINED ${VAR})
      MESSAGE(SEND_ERROR "Error, the variable ${VAR} is not defined!")
    ENDIF()
  ENDFOREACH()
ENDFUNCTION()

# ToDo: The VARS arg This really needs to be repalced with ${ARGV}.  I fear
# that only the first arg passed in is asserted.  However, to change this now
# is breaking backward compatibility.
