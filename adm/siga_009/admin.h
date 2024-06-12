#ifndef ADMIN_H
#define ADMIN_H

struct _admin {
    
    char nome[48];
    long int cpf;
    char senha[8];
    int reg_a;
    int priv;

};

typedef struct _admin admin;

void init_admin(admin *a) {
    
    a->priv = 3;
    a->reg_a = 10;

}

#endif