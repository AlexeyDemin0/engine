
set(TEST_SOURCES
  "core/math/Vector2.test.cpp"
  "core/math/Vector3.test.cpp"
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