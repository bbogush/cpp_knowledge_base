add_executable(proxy proxy.cpp)

target_compile_features(proxy PRIVATE cxx_std_20)
target_compile_options(proxy PRIVATE -Wall -Wextra -Wpedantic)

target_compile_options(proxy PRIVATE -fsanitize=address -fno-omit-frame-pointer)
target_link_options(proxy PRIVATE -fsanitize=address)