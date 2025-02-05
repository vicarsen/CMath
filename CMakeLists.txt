cmake_minimum_required(VERSION 3.28)

project(
  CMath
  VERSION 0.0.1
  DECRIPTION "A math library written in C"
  LANGUAGES C
)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)

  include(CTest)

  find_package(Doxygen)
  if (Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()
endif()

add_subdirectory(src)

if ((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR CMATH_BUILD_TESTING) AND BUILD_TESTING)
  add_subdirectory(tests)
endif()

