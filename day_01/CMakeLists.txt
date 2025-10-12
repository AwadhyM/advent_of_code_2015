add_library(day01 STATIC src/day01.cpp)

target_include_directories(day01
    PUBLIC
        inc
)

add_executable(day01-exe main.cpp)

target_link_libraries(day01-exe PRIVATE day01)
