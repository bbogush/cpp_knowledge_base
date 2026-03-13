add_executable(factory_method factory_method.cpp)

target_compile_features(factory_method PRIVATE cxx_std_20)
target_compile_options(factory_method PRIVATE -Wall -Wextra -Wpedantic)

target_compile_options(factory_method PRIVATE -fsanitize=address -fno-omit-frame-pointer)
target_link_options(factory_method PRIVATE -fsanitize=address)