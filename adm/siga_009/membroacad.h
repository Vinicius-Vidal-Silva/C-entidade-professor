#ifndef MEMBROACAD_H
#define MEMBROACAD_H

struct _membro_acad {
    char nome[48];
    long int cpf;
    char senha[48];
    int priv;
    
};

typedef struct _membro_acad membro_acad;

#endif