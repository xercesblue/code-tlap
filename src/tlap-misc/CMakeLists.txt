set(SOURCES
main.cpp
)

get_filename_component(DIR ${CMAKE_CURRENT_SOURCE_DIR} NAME)
include_directories(${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/src/tlap-lib)
add_executable(${DIR} ${SOURCES})
target_link_libraries(${DIR} tlap-lib)
