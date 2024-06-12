#ifndef ALUNO_H
#define ALUNO_H

struct _aluno {
    char nome[48];
    long int cpf;
    char senha[8];
    int reg_a;
    char materias[3][24];
    int priv;
    //const int priv = 1;
};

typedef struct _aluno aluno;

void init_aluno(aluno *a) {
    char vazio[24] = "...";
    a->priv = 1;
    a->reg_a = 1000;
    for(int i = 0; i < 3; i++){
        strcpy(a->materias[i],vazio);
    }
    strcpy(a->materias[0],"ies100"); 
}

#endif