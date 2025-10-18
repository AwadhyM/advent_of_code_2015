add_library(day03 STATIC src/day03.cpp)

target_include_directories(day03
    PUBLIC
        inc
		../utils/inc
)

add_executable(day03-exe main.cpp)

target_link_libraries(day03-exe PRIVATE utilities)
target_link_libraries(day03-exe PRIVATE day03)
