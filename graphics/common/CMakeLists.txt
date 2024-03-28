add_subdirectory(events)
add_subdirectory(exceptions)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../..)
