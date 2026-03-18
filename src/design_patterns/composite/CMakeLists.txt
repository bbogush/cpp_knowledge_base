add_executable(composite composite.cpp)

target_compile_features(composite PRIVATE cxx_std_20)
target_compile_options(composite PRIVATE -Wall -Wextra -Wpedantic)

target_compile_options(composite PRIVATE -fsanitize=address -fno-omit-frame-pointer)
target_link_options(composite PRIVATE -fsanitize=address)