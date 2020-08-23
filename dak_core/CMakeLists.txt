
add_library(dak_core
   include/dak/core/all.h
   include/dak/core/any_ops.h                   src/any_ops.cpp
   include/dak/core/any_nullary_ops.h
   include/dak/core/any_unary_ops.h
   include/dak/core/any_binary_ops.h
   include/dak/core/any_compare_op.h            src/any_compare_op.cpp
   include/dak/core/any_convert_op.h            src/any_convert_op.cpp
   include/dak/core/any_is_compatible_op.h      src/any_is_compatible_op.cpp
   include/dak/core/any_size_op.h               src/any_size_op.cpp
   include/dak/core/any_stream_op.h             src/any_stream_op.cpp
   include/dak/core/any_to_text_op.h            src/any_to_text_op.cpp
   include/dak/core/array.h                     src/array.cpp
   include/dak/core/dict.h                      src/dict.cpp
   include/dak/core/internal_names.h
   include/dak/core/name.h                      src/name.cpp
   include/dak/core/object.h                    src/object.cpp
   include/dak/core/ref.h                       src/ref_base.cpp
   include/dak/core/ref_counted.h               src/ref_counted.cpp
   include/dak/core/stream.h                    src/stream.cpp
   include/dak/core/types.h
   include/dak/core/util.h
   include/dak/core/var.h                       src/var.cpp
   include/dak/core/var_ops.h
)

target_include_directories(dak_core PUBLIC
   include
)

target_compile_features(dak_core PUBLIC cxx_std_20)

target_compile_options(dak_core PRIVATE /bigobj)

