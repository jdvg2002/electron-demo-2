MACRO(TRIBITS_PROJECT_DEFINE_PACKAGING)

    TRIBITS_COPY_INSTALLER_RESOURCE(TribitsExProj_README
      "${TribitsExProj_SOURCE_DIR}/README"
      "${TribitsExProj_BINARY_DIR}/README.txt")
    TRIBITS_COPY_INSTALLER_RESOURCE(TribitsExProj_LICENSE
      "${TribitsExProj_SOURCE_DIR}/LICENSE"
      "${TribitsExProj_BINARY_DIR}/LICENSE.txt")

    SET(CPACK_PACKAGE_DESCRIPTION "TribitsExampleProject just shows you how to use TriBITS.")
    SET(CPACK_PACKAGE_FILE_NAME "tribitsexproj-setup-${TribitsExProj_VERSION}")
    SET(CPACK_PACKAGE_INSTALL_DIRECTORY "TribitsExProj ${TribitsExProj_VERSION}")
    SET(CPACK_PACKAGE_REGISTRY_KEY "TribitsExProj ${TribitsExProj_VERSION}")
    SET(CPACK_PACKAGE_NAME "tribitsexproj")
    SET(CPACK_PACKAGE_VENDOR "Sandia National Laboratories")
    SET(CPACK_PACKAGE_VERSION "${TribitsExProj_VERSION}")
    SET(CPACK_RESOURCE_FILE_README "${TribitsExProj_README}")
    SET(CPACK_RESOURCE_FILE_LICENSE "${TribitsExProj_LICENSE}")
    SET(${PROJECT_NAME}_CPACK_SOURCE_GENERATOR_DEFAULT "TGZ;TBZ2")
    SET(CPACK_SOURCE_FILE_NAME "tribitsexproj-source-${TribitsExProj_VERSION}")
    SET(CPACK_COMPONENTS_ALL ${TribitsExProj_PACKAGES} Unspecified)

ENDMACRO()
