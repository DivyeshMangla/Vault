#ifndef CRYPTO_H
#define CRYPTO_H

#include <stddef.h>

#define KEK_SIZE 32
#define KDF_ITERS 310000 // Key Derivation Function

void generateSalt(unsigned char salt[]);
int deriveKEK(
    const char *password,
    const unsigned char *salt,
    size_t salt_len,
    unsigned char *kek
);

#endif // CRYPTO_H