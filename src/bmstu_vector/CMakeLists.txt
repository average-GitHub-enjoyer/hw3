set(LIBRARY bmstu_vector)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true "*.hpp" "*.cpp")

add_library(${LIBRARY} ${SOURCES})

set_target_properties(bmstu_vector PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${LIBRARY} PUBLIC include)
