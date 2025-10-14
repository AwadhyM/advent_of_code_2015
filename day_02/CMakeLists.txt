add_library(day02 STATIC src/day02.cpp)

target_include_directories(day02
    PUBLIC
        inc
		../utils/inc
)

add_executable(day02-exe main.cpp)

target_link_libraries(day02-exe PRIVATE utilities)
target_link_libraries(day02-exe PRIVATE day02)
