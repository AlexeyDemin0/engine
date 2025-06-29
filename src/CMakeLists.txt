set(SOURCES
  "core/Types.cpp"
  "core/math/FloatComparator.cpp"
  "core/math/Vector2.cpp"
  "core/math/Vector3.cpp"
  "core/math/Vector4.cpp"
)
  
set(HEADERS
  "core/Types.h"
  "core/math/FloatComparator.h"
  "core/math/Vector2.h"
  "core/math/Vector3.h"
  "core/math/Vector4.h"
)

add_library(Engine STATIC ${SOURCES})

target_sources(Engine PUBLIC ${HEADERS})

target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# disabling exceptions and rtti support 
if (MSVC)
  target_compile_options(Engine PRIVATE "/EHs-c-" "/GR-")
else()
  target_compile_options(Engine PRIVATE "-fno-exceptions" "-fno-rtti")
endif()