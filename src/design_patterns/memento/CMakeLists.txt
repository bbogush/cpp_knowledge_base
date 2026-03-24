add_executable(memento memento.cpp)

target_compile_features(memento PRIVATE cxx_std_20)
target_compile_options(memento PRIVATE -Wall -Wextra -Wpedantic)

target_compile_options(memento PRIVATE -fsanitize=address -fno-omit-frame-pointer)
target_link_options(memento PRIVATE -fsanitize=address)