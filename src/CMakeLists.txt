set(BINARY ${CMAKE_PROJECT_NAME})
set(LIBRARY bmstu_vector)

file(GLOB SOURCES LIST_DIRECTORIES false "*.hpp" "*.cpp")

add_subdirectory(${LIBRARY})

add_executable(${BINARY} ${SOURCES})
target_link_libraries(${BINARY} LINK_PUBLIC ${LIBRARY})
