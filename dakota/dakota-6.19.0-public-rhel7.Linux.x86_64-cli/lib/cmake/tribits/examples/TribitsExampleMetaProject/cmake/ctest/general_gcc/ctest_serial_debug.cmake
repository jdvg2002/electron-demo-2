INCLUDE("${CMAKE_CURRENT_LIST_DIR}/../TribitsExMetaProjCTestDriver.cmake")

SET(COMM_TYPE SERIAL)
SET(BUILD_TYPE DEBUG)
SET(COMPILER_VERSION GCC)
SET(BUILD_DIR_NAME ${COMM_TYPE}_${BUILD_TYPE})

SET_DEFAULT( CTEST_BUILD_FLAGS "-j1 -i" )
SET_DEFAULT( CTEST_PARALLEL_LEVEL "1" )

SET( EXTRA_CONFIGURE_OPTIONS
  "-DBUILD_SHARED_LIBS:BOOL=ON"
  "-DCMAKE_BUILD_TYPE=DEBUG"
  "-DCMAKE_C_COMPILER=gcc"
  "-DCMAKE_CXX_COMPILER=g++"
  "-DCMAKE_Fortran_COMPILER=gfortran"
  "-DTribitsExMetaProj_ENABLE_Fortran=ON"
  "-DTribitsExMetaProj_TRACE_ADD_TEST=ON"
  )

SET_DEFAULT_AND_FROM_ENV(TribitsExMetaProj_CMAKE_INSTALL_PREFIX "")
IF (TribitsExMetaProj_CMAKE_INSTALL_PREFIX)
  SET(EXTRA_CONFIGURE_OPTIONS
    "${EXTRA_CONFIGURE_OPTIONS}"
    "-DCMAKE_INSTALL_PREFIX=${TribitsExMetaProj_CMAKE_INSTALL_PREFIX}"
    )
ENDIF()

SET(CTEST_TEST_TYPE Continuous)

TRIBITSEXMETAPROJ_CTEST_DRIVER()