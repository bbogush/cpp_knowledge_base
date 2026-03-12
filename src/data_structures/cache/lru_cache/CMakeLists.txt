add_executable(lru_cache lru_cache.cpp)

target_compile_features(lru_cache PRIVATE cxx_std_20)
target_compile_options(lru_cache PRIVATE -Wall -Wextra -Wpedantic)

target_compile_options(lru_cache PRIVATE -fsanitize=address -fno-omit-frame-pointer)
target_link_options(lru_cache PRIVATE -fsanitize=address)