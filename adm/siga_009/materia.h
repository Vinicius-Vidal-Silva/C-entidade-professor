#ifndef materia_H
#define materia_H

struct _materia {
    char nome[48];
    char professor[48];
    char sigla[12];
    
};

typedef struct _materia materia;

void init_materia(materia *materia) {
    //char vazio[24] = "...";
    strcpy(materia->professor, "sem atribuição");
    //strncpy(prof->materias[0],vazio,sizeof(prof->materias[0]));
}


#endif