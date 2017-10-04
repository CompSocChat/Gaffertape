cmake_minimum_required(VERSION 3.0)
subdirs(${PROJECT_SOURCE_DIR}/src)

# Doc stuff
find_package(Doxygen REQUIRED)

file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/doc)
file(GLOB doc ${PROJECT_SOURCE_DIR}/doc/*)
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES ${doc})

add_custom_target(doc
  ${DOXYGEN_EXECUTABLE} ${PROJECT_SOURCE_DIR}/Doxyfile
  #WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/doc
  COMMENT "Generating docs..."
)
