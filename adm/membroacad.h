// #ifndef ALUNO_H
// #define ALUNO_H

// struct _aluno {
    
//     char nome[48];
//     int CPF;
//     char senha[8];
//     int priv;
//     //adm = 1, prof = 2, aluno = 3//


// };

// typedef struct _aluno aluno;

// #endif

#ifndef MEMBROACAD_H
#define MEMBROACAD_H

struct _memb_acad {
    
    char nome[48];
    long int CPF;
    char senha[8];
    int priv;
    //adm = 1, prof = 2, aluno = 3//

};

typedef struct _memb_acad memb_acad;

#endif