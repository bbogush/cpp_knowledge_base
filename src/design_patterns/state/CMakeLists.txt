add_executable(state state.cpp)

target_compile_features(state PRIVATE cxx_std_20)
target_compile_options(state PRIVATE -Wall -Wextra -Wpedantic)

target_compile_options(state PRIVATE -fsanitize=address -fno-omit-frame-pointer)
target_link_options(state PRIVATE -fsanitize=address)