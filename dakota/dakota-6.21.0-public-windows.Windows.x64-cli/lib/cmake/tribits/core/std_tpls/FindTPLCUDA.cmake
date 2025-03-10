# @HEADER
# ************************************************************************
#
#            Trilinos: An Object-Oriented Solver Framework
#                 Copyright (2001) Sandia Corporation
#
#
# Copyright (2001) Sandia Corporation. Under the terms of Contract
# DE-AC04-94AL85000, there is a non-exclusive license for use of this
# work by or on behalf of the U.S. Government.  Export of this program
# may require a license from the United States Government.
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
# NOTICE:  The United States Government is granted for itself and others
# acting on its behalf a paid-up, nonexclusive, irrevocable worldwide
# license in this data to reproduce, prepare derivative works, and
# perform publicly and display publicly.  Beginning five (5) years from
# July 25, 2001, the United States Government is granted for itself and
# others acting on its behalf a paid-up, nonexclusive, irrevocable
# worldwide license in this data to reproduce, prepare derivative works,
# distribute copies to the public, perform publicly and display
# publicly, and to permit others to do so.
#
# NEITHER THE UNITED STATES GOVERNMENT, NOR THE UNITED STATES DEPARTMENT
# OF ENERGY, NOR SANDIA CORPORATION, NOR ANY OF THEIR EMPLOYEES, MAKES
# ANY WARRANTY, EXPRESS OR IMPLIED, OR ASSUMES ANY LEGAL LIABILITY OR
# RESPONSIBILITY FOR THE ACCURACY, COMPLETENESS, OR USEFULNESS OF ANY
# INFORMATION, APPARATUS, PRODUCT, OR PROCESS DISCLOSED, OR REPRESENTS
# THAT ITS USE WOULD NOT INFRINGE PRIVATELY OWNED RIGHTS.
#
# ************************************************************************
# @HEADER

# Check for CUDA support

SET(_CUDA_FAILURE OFF)

# Have CMake find CUDA
IF(NOT _CUDA_FAILURE)
  FIND_PACKAGE(CUDA REQUIRED)
  IF (NOT CUDA_FOUND)
    SET(_CUDA_FAILURE ON)
  ENDIF()
ENDIF()

# # Test that CUDA compiler works
# IF(NOT _CUDA_FAILURE)
#   INCLUDE(TrilinosCUDASupport)
#   SET(SRC "
#     #include <cuda_runtime.h>
#     __global__ void vecAdd(const float* a, const float* b, float* c, int N)
#     {
#         int i = blockDim.x * blockIdx.x + threadIdx.x;
#         if (i < N) c[i] = a[i] + b[i];
#     }
#     __global__ void vecInit(float* x, float val, int N)
#     {
#         int i = blockDim.x * blockIdx.x + threadIdx.x;
#         if (i < N) x[i] = val;
#     }
#     int main() {
#         const int N               = 2048;
#         const int threadsPerBlock = 256;
#         const int blocksPerGrid   = 8;
#         float* a = NULL;
#         float* b = NULL;
#         float* c = NULL;
#         cudaMalloc((void**)&a, N);
#         cudaMalloc((void**)&b, N);
#         cudaMalloc((void**)&c, N);
#         // init
#         vecInit<<<blocksPerGrid, threadsPerBlock>>>(a,1.0f,N);
#         vecInit<<<blocksPerGrid, threadsPerBlock>>>(b,2.0f,N);
#         vecInit<<<blocksPerGrid, threadsPerBlock>>>(c,0.0f,N);
#         // run
#         vecAdd<<<blocksPerGrid, threadsPerBlock>>>(a, b, c, N);
#     }
#   ")
#   CHECK_CUDA_SOURCE_COMPILES(${SRC} _NVCC_SUCCESS)
#   IF(NOT _NVCC_SUCCESS)
#     SET(_CUDA_FAILURE ON)
#   ENDIF()
# ENDIF()

IF(NOT _CUDA_FAILURE)
  # if we haven't met failure
  macro(PACKAGE_ADD_CUDA_LIBRARY cuda_target)
    TRIBITS_ADD_LIBRARY(${cuda_target} ${ARGN} CUDALIBRARY)
  endmacro()
  GLOBAL_SET(TPL_CUDA_LIBRARY_DIRS)
  GLOBAL_SET(TPL_CUDA_INCLUDE_DIRS ${CUDA_TOOLKIT_INCLUDE})
  GLOBAL_SET(TPL_CUDA_LIBRARIES ${CUDA_CUDART_LIBRARY} ${CUDA_cublas_LIBRARY}
     ${CUDA_cufft_LIBRARY})
ELSE()
  SET(TPL_ENABLE_CUDA OFF PARENT_SCOPE)
  MESSAGE(FATAL_ERROR "\nDid not find acceptable version of CUDA compiler")
ENDIF()
