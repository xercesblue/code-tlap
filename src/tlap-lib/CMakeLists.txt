add_library(tlap-lib tlap-lib.cpp tlap-lib.h)
include_directories(${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/src/tlap-lib)
link_directories(${code-tlap_BINARY_DIR}/src/tlap-lib)
