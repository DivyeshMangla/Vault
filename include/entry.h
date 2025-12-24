#ifndef ENTRY_H
#define ENTRY_H

typedef struct {
    char encryptedName[64];
    char encryptedPassword[128];
} PasswordEntry;

PasswordEntry createPasswordEntry(void);

#endif //ENTRY_H