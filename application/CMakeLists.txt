cmake_minimum_required(VERSION 3.10)

function(build_submodule PACKAGE_PATH)
  message("Start configuration for ${ELEMENT}.")
  add_subdirectory(${PACKAGE_PATH})
  message("Finish configuration for ${ELEMENT}.")
endfunction()

message(STATUS "Start configuration for submodules.")

file(GLOB ELEMENTS "*")

foreach(ELEMENT ${ELEMENTS})
  if(IS_DIRECTORY ${ELEMENT} AND EXISTS ${ELEMENT}/CMakeLists.txt)
    build_submodule(${ELEMENT})
  endif()
endforeach()

message(STATUS "Finish configuration for submodules.\n")
