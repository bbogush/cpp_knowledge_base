add_executable(bridge bridge.cpp)

target_compile_features(bridge PRIVATE cxx_std_20)
target_compile_options(bridge PRIVATE -Wall -Wextra -Wpedantic)

target_compile_options(bridge PRIVATE -fsanitize=address -fno-omit-frame-pointer)
target_link_options(bridge PRIVATE -fsanitize=address)