#ifndef VAULT_H
#define VAULT_H

#include <stdbool.h>

#define SALT_SIZE 16
#define KEK_SIZE 32 // Key Encryption Key

/*
 * Self notes ->
 * Master password is the human-readable password that the user sets.
 * Salt is the random data added before hashing to avoid rainbow tables
 * Vault Key is the derived key from the master password and salt using a key derivation function.
 */
typedef struct {
    bool isUnlocked;
    unsigned char kek[KEK_SIZE];
    unsigned char salt[SALT_SIZE];
} VaultSession;

VaultSession createVaultSession(void);
void lockVaultSession(VaultSession *session);

#endif //VAULT_H