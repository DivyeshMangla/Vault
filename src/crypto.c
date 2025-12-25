#include "../include/crypto.h"
#include <openssl/rand.h>
#include <openssl/err.h>
#include <stdio.h>
#include <stdlib.h>

#include "vault.h"

void generateSalt(unsigned char *salt) {
    if (!salt) {
        fprintf(stderr, "generateSalt: salt parameter cannot be NULL\n");
        abort();
    }

    if (RAND_bytes(salt, SALT_SIZE) != 1) {
        fprintf(stderr, "generateSalt: Failed to generate random bytes for salt\n");
        ERR_print_errors_fp(stderr);
        abort();
    }
}
