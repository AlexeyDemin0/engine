
set(TEST_SOURCES
  "core/math/test_Vector2.cpp"
  "core/math/test_Vector3.cpp"
)

add_executable(EngineTest ${TEST_SOURCES})

target_link_libraries(EngineTest PRIVATE
  GTest::gtest_main
  Engine
)

target_include_directories(EngineTest PRIVATE
  ${PROJECT_SOURCE_DIR}/src
)

include(GoogleTest)
gtest_discover_tests(EngineTest)