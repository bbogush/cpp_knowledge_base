add_executable(subsets subsets.cpp)

target_compile_features(subsets PRIVATE cxx_std_20)
target_compile_options(subsets PRIVATE -Wall -Wextra -Wpedantic)

target_compile_options(subsets PRIVATE -fsanitize=address -fno-omit-frame-pointer)
target_link_options(subsets PRIVATE -fsanitize=address)