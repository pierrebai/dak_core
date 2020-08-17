
add_library(dak_core_tests SHARED
   src/any_ops_tests.cpp
   src/array_tests.cpp
   src/dict_tests.cpp
   src/var_tests.cpp
   src/name_tests.cpp
   src/stream_tests.cpp

   include/helpers.h
)

target_link_libraries(dak_core_tests PUBLIC
   dak_core
)

target_compile_features(dak_core_tests PUBLIC cxx_std_20)

target_include_directories(dak_core_tests PUBLIC
   "${PROJECT_SOURCE_DIR}/dak_core/include"
   "${PROJECT_SOURCE_DIR}/dak_core_tests/include"
)

