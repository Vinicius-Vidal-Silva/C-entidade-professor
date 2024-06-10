#ifndef materia_H
//Verifica se o identificador materia_H não está definido. Se não estiver definido, significa que este arquivo de cabeçalho ainda não foi incluído neste arquivo de código-fonte, evitando inclusões múltiplas.

#define materia_H
//Define o identificador materia_H, indicando que este arquivo de cabeçalho está sendo incluído neste ponto do código-fonte.

struct _materia {
	//Define uma estrutura de dados _materia, que contém informações sobre uma disciplina ou matéria, como nome, professor e sigla.
    char nome[48];
    char professor[48];
    char sigla[7];
    
};

typedef struct _materia materia;
//struct _materia: É como uma caixa que pode conter informações sobre uma matéria, como nome, professor e sigla.
//typedef: É uma palavra-chave que usamos em C para criar apelidos para tipos de dados existentes.
//materia: É o novo nome que estamos dando para struct _materia.


void init_materia(materia *materia) { //init_materia: É uma função que inicializa uma estrutura materia. Neste caso, define o nome do professor como "sem atribuição".
    //char vazio[24] = "..."; --> apagar se não utilizar?
    strcpy(materia->professor, "sem atribuicao");
    //strncpy(prof->materias[0],vazio,sizeof(prof->materias[0]));--> apagar se não utilizar?
}


#endif
//#endif: Indica o fim do bloco condicional #ifndef. Se o identificador materia_H já estiver definido, todo o conteúdo entre #ifndef e #endif será ignorado durante inclusões subsequentes.
