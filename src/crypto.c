#include "../include/crypto.h"
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vault.h"

void generateSalt(unsigned char *salt) {
    if (!salt) {
        fprintf(stderr, "generateSalt: salt is NULL\n");
        abort();
    }

    if (RAND_bytes(salt, SALT_SIZE) != 1) {
        ERR_print_errors_fp(stderr);
        abort();
    }
}

int deriveKEK(
    const char *password,
    const unsigned char *salt,
    size_t salt_len,
    unsigned char *kek)
{
    if (!password || !salt || !kek) {
        return 0;
    }

    return PKCS5_PBKDF2_HMAC(
        password,
        strlen(password),
        salt,
        (int)salt_len,
        KDF_ITERS,
        EVP_sha256(),
        KEK_SIZE,
        kek
    ) == 1;
}