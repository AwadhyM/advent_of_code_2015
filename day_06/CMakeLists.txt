add_library(day06 STATIC src/day06.cpp)

target_include_directories(day06
    PUBLIC
        inc
		../utils/inc
)

add_executable(day06-exe main.cpp)

target_link_libraries(day06-exe PRIVATE utilities)
target_link_libraries(day06-exe PRIVATE day06)
