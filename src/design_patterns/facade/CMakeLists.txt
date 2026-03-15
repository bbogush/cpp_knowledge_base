add_executable(facade facade.cpp)

target_compile_features(facade PRIVATE cxx_std_20)
target_compile_options(facade PRIVATE -Wall -Wextra -Wpedantic)

target_compile_options(facade PRIVATE -fsanitize=address -fno-omit-frame-pointer)
target_link_options(facade PRIVATE -fsanitize=address)