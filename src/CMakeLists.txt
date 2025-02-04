
set(
  HEADER_LIST
  "${CMath_SOURCE_DIR}/include/cmath.h"
)

add_library(
  cmath

  cmath.c

  ${HEADER_LIST}
)

target_include_directories(cmath PUBLIC ../include)

if(MSVC)
  target_compile_options(cmath PUBLIC /ARCH:AVX2)
else()
  target_compile_options(cmath PUBLIC -mavx2)
endif()

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST}
)

