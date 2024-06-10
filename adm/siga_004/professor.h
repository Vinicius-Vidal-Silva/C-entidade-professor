#ifndef professor_H
#define professor_H

struct _professor {
    char nome[48];
    long int cpf;
    char senha;
    int reg_a;
    char materias[3][32];
    char listas_alunos[3][12];
    int priv;
};

typedef struct _professor professor;

void init_professor(professor *prof) {
    char vazio[24] = "...";
    prof->priv = 2;
    prof->reg_a = 10;
    for(int i = 0; i < 3; i++){
        strcpy(prof->materias[i],vazio);
        strcpy(prof->listas_alunos[i],vazio);
    }
    //strncpy(prof->materias[0],vazio,sizeof(prof->materias[0]));
}


#endif