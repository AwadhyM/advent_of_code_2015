add_library(day05 STATIC src/day05.cpp)

target_include_directories(day05
    PUBLIC
        inc
		../utils/inc
)

add_executable(day05-exe main.cpp)

target_link_libraries(day05-exe PRIVATE utilities)
target_link_libraries(day05-exe PRIVATE day05)
