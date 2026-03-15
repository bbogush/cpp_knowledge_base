add_executable(adapter adapter.cpp)

target_compile_features(adapter PRIVATE cxx_std_20)
target_compile_options(adapter PRIVATE -Wall -Wextra -Wpedantic)

target_compile_options(adapter PRIVATE -fsanitize=address -fno-omit-frame-pointer)
target_link_options(adapter PRIVATE -fsanitize=address)