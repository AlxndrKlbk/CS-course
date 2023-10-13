find_package(Git QUIET)

macro(parse_git_tag)
  message("Git executable: ${GIT_EXECUTABLE}")
  # Get the latest Git tag
  execute_process(
    COMMAND ${GIT_EXECUTABLE} describe --abbrev=0 --tags
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_TAG
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )

  # Extract the major and minor version numbers from the Git tag
  string(REGEX MATCH "([0-9]+)\\.([0-9]+)\\.([0-9]+)" "VERSION_MATCH" "${GIT_TAG}")
  set(GAMMA_MAJOR_VERSION ${CMAKE_MATCH_1})
  set(GAMMA_MINOR_VERSION ${CMAKE_MATCH_2})
  set(GAMMA_PATCH_VERSION ${CMAKE_MATCH_3})

  # Print the major and minor version numbers
  message("Git tag: ${GIT_TAG}")
  message("Major version: ${GAMMA_MAJOR_VERSION}")
  message("Minor version: ${GAMMA_MINOR_VERSION}")
  message("Patch version: ${GAMMA_PATCH_VERSION}")
endmacro()
