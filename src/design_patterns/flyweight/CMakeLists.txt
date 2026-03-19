add_executable(flyweight flyweight.cpp)

target_compile_features(flyweight PRIVATE cxx_std_20)
target_compile_options(flyweight PRIVATE -Wall -Wextra -Wpedantic)

target_compile_options(flyweight PRIVATE -fsanitize=address -fno-omit-frame-pointer)
target_link_options(flyweight PRIVATE -fsanitize=address)