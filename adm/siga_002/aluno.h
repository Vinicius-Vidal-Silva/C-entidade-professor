#ifndef ALUNO_H
#define ALUNO_H
//garantem que o conteúdo do arquivo de cabeçalho seja incluído apenas uma vez durante a compilação para evitar problemas de redefinição.

// Define a estrutura de dados para representar um aluno
struct _aluno {
    char nome[48];				// Nome do aluno
    long int cpf;				// CPF do aluno
    char senha;					// Senha do aluno (apenas um caractere?)
    int reg_a;					// Registro do aluno
    char materias[3][24];		// Matérias em que o aluno está matriculado
    int priv;					 // Privilégio do aluno
    //const int priv = 1; -> apagar se não for usar(?)
};

// Define um alias 'aluno' para 'struct _aluno'
typedef struct _aluno aluno;

// Função para inicializar um aluno com valores padrão
void init_aluno(aluno *a) {
    char vazio[24] = "...";				// String representando uma matéria vazia
    a->priv = 1;						 // Define o privilégio padrão
    a->reg_a = 100;						// Define o registro acadêmico padrão
    
    // Inicializa todas as matérias do aluno como vazio
    for(int i = 0; i < 3; i++){
        strcpy(a->materias[i],vazio);
    }
    strcpy(a->materias[0],"ies100"); // Define uma matéria padrão
}

#endif
