add_executable(visitor visitor.cpp)

target_compile_features(visitor PRIVATE cxx_std_20)
target_compile_options(visitor PRIVATE -Wall -Wextra -Wpedantic)

target_compile_options(visitor PRIVATE -fsanitize=address -fno-omit-frame-pointer)
target_link_options(visitor PRIVATE -fsanitize=address)