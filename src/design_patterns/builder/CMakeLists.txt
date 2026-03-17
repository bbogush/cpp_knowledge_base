add_executable(builder builder.cpp)

target_compile_features(builder PRIVATE cxx_std_20)
target_compile_options(builder PRIVATE -Wall -Wextra -Wpedantic)

target_compile_options(builder PRIVATE -fsanitize=address -fno-omit-frame-pointer)
target_link_options(builder PRIVATE -fsanitize=address)