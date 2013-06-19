set(SOURCES
main.cpp
)

get_filename_component(DIR ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_executable(${DIR} ${SOURCES}) 