add_executable(util-tests
		util_tests.cpp
)

target_include_directories(
	util-tests
		PUBLIC
			../inc
)

target_link_libraries(
	util-tests
	utilities
	GTest::gtest_main
)
