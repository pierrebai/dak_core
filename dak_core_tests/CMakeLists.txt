
add_library(dak_core_tests SHARED
   src/any_convert_op_tests.cpp
   src/any_is_compatible_op_tests.cpp
   src/any_size_op_tests.cpp
   src/any_stream_op_tests.cpp
   src/any_to_text_op_tests.cpp
   src/array_tests.cpp
   src/dict_tests.cpp
   src/var_tests.cpp
   src/name_tests.cpp
   src/stream_tests.cpp

   include/tests_helpers.h
)

target_link_libraries(dak_core_tests PUBLIC
   dak_core
)

target_compile_features(dak_core_tests PUBLIC cxx_std_20)

target_include_directories(dak_core_tests PUBLIC
   "${PROJECT_SOURCE_DIR}/dak_core/include"
   "${PROJECT_SOURCE_DIR}/dak_core_tests/include"
)

