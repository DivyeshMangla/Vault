cmake_minimum_required(VERSION 3.31)
project(Vault C)

set(CMAKE_C_STANDARD 11)

set(OPENSSL_ROOT_DIR "C:/Program Files/OpenSSL-Win64")
set(OPENSSL_LIBRARY_DIR "C:/Program Files/OpenSSL-Win64/lib/VC")
set(OPENSSL_USE_STATIC_LIBS ON)

find_package(OpenSSL REQUIRED)

add_executable(
        Vault
        src/main.c
        src/entry.c
        src/vault.c
        src/crypto.c
)

target_include_directories(Vault PRIVATE include)
target_link_libraries(Vault OpenSSL::SSL OpenSSL::Crypto)
