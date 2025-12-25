#include "../include/vault.h"

#include <stddef.h>
#include <string.h>

VaultSession createVaultSession(void) {
    const VaultSession session = {0}; // Initialize to 0
    return session;
}

void lockVaultSession(VaultSession *session) {
    if (session == NULL) {
        return;
    }
    memset(session->key, 0, KEY_SIZE); // Wipe the key
    memset(session->salt, 0, SALT_SIZE); // Wipe the salt
    session->isUnlocked = false;
}