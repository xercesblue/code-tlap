set(SOURCES
main.cpp
isbn-13.cpp
isbn-13.h
)

get_filename_component(DIR ${CMAKE_CURRENT_SOURCE_DIR} NAME)
include_directories(${cpp-practice_SOURCE_DIR}/src/tlap-lib)
add_executable(${DIR} ${SOURCES}) 
target_link_libraries(${DIR} tlap-lib)
