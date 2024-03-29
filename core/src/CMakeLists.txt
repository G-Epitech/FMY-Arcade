target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    Core.cpp
    Core.hpp
)

add_subdirectory(exception)
add_subdirectory(loader)
add_subdirectory(utils)
