add_executable(decorator decorator.cpp)

target_compile_features(decorator PRIVATE cxx_std_20)
target_compile_options(decorator PRIVATE -Wall -Wextra -Wpedantic)

target_compile_options(decorator PRIVATE -fsanitize=address -fno-omit-frame-pointer)
target_link_options(decorator PRIVATE -fsanitize=address)