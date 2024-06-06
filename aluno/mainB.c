#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do registro com nome de tamanho variável
typedef struct {
    size_t tamNome;  // Usar size_t para tamanhos
    char *nome;
    float p1;
    float p2;
    float media;
    int faltas;
    char situ[10];
}Estudante;

typedef struct{
    char cpf[11];
    char nome[50];
    char senha[10];
    int privilegio;
    char *materia;
}membroAcademico;

// Função para ler um registro do arquivo binário
int LerArquivo(FILE *file, Estudante *aluno) {

    if (fread(&aluno->tamNome, sizeof(size_t), 1, file) != 1) {
        return 0;
    }
    aluno->nome = (char *)malloc(aluno->tamNome + 1);
    if (aluno->nome == NULL) {
        return 0;
    }
    if (fread(aluno->nome, sizeof(char), aluno->tamNome, file) != aluno->tamNome) {
        free(aluno->nome);
        return 0;
    }
    aluno->nome[aluno->tamNome] = '\0';  // Adicionar o terminador nulo
    if (fread(&aluno->p1, sizeof(float), 1, file) != 1 ||
        fread(&aluno->p2, sizeof(float), 1, file) != 1 ||
        fread(&aluno->media, sizeof(float), 1, file) != 1 ||
        fread(&aluno->faltas, sizeof(int), 1, file) != 1 ||
        fread(aluno->situ, sizeof(char), 10, file) != 10) {
        free(aluno->nome);
        return 0;
    }
    return 1;
}

// Função para pegar um registro específico do arquivo binário com base no nome e retornar os dados a partir de P1
Estudante* EncontrarDadoPorNome(const char *nomeArquivo, const char *nome) {

    // Abre o arquivo binário para leitura (r de read e b de binário)
    FILE *file = fopen(nomeArquivo, "rb");

    // Verifica se o arquivo existe ou se tem permissão para acessá-lo
    if (file == NULL) {
        perror("Erro ao abrir o arquivo"); // Mensagem de erro
        return NULL; // Retorna a função com o valor nulo
    }

    Estudante temp; // Variável do tipo struct Estudante para comparar na função
    Estudante *result = NULL; // Ponteiro em que será guardado o resultado da função

    // Enquanto a função LerArquivo retornar 1
    while (LerArquivo(file, &temp)) {

        // Compara o valor da linha no arquivo binário com o nome que queremos encontrar
        if (strcmp(temp.nome, nome) == 0) {

            // Result recebe o endereço de blocos consecutivos na memória que malloc (memory allocation) retorna, sendo convertido para a struct do tipo Estudante
            result = (Estudante *)malloc(sizeof(Estudante));

            // Se o result for diferente de nulo
            if (result != NULL) {
                *result = temp;  // Copiar o registro encontrado
            }
            break; // Sai do if e consequentemente sai do laço while
        }
        free(temp.nome);  // Liberar o nome do registro temporário se não for o desejado
    }

    fclose(file); // Fecha o arquivo
    return result; // Retorna dessa função o valor de result
}

// Função para escrever um registro no arquivo binário
void EscreverNoArquivo(FILE *file, Estudante *aluno) {

    fwrite(&aluno->tamNome, sizeof(size_t), 1, file);
    fwrite(aluno->nome, sizeof(char), aluno->tamNome, file);
    fwrite(&aluno->p1, sizeof(float), 1, file);
    fwrite(&aluno->p2, sizeof(float), 1, file);
    fwrite(&aluno->media, sizeof(float), 1, file);
    fwrite(&aluno->faltas, sizeof(int), 1, file);
    fwrite(aluno->situ, sizeof(char), 10, file);  // Tamanho fixo de 10 caracteres
}

// Função para adicionar registros ao arquivo binário
void FormatarArquivo(const char *filename) {

    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    Estudante estudantes[10] = {
        {4, "Joao", 7.5, 8.0, 7.75, 2, "Aprovado"},
        {5, "Maria", 8.0, 9.0, 8.5, 0, "Aprovado"},
        {4, "Jose", 6.5, 7.0, 6.75, 3, "Reprovado"},
        {6, "Pedro", 9.0, 8.5, 8.75, 1, "Aprovado"},
        {7, "Ana", 7.0, 7.5, 7.25, 0, "Aprovado"},
        {5, "Luis", 8.5, 8.0, 8.25, 2, "Aprovado"},
        {4, "Rita", 6.0, 7.0, 6.5, 4, "Reprovado"},
        {8, "Paula", 9.5, 9.0, 9.25, 0, "Aprovado"},
        {5, "Carlos", 7.5, 8.5, 8.0, 1, "Aprovado"},
        {7, "Julia", 8.0, 7.5, 7.75, 2, "Aprovado"}
    };

    for (int i = 0; i < 10; i++) {
        EscreverNoArquivo(file, &estudantes[i]);
    }

    fclose(file);
}

void MostrarNotas(char *materia, char *nome){

    // Atribuindo a uma variável o valor da chamada da função EncontrarDadoPorNome
    Estudante *aluno = EncontrarDadoPorNome(materia, nome);

    // Verifica se foi retornado algum valor pela função
    if (aluno != NULL) {

        // Imprime na tela os dados encontrados a partir da P1
        printf("Dados encontrados: P1 = %.2f, P2 = %.2f, Média = %.2f\n", aluno->p1, aluno->p2, aluno->media);
        free(aluno->nome); // Libera a memória alocada para o nome
        free(aluno);  // Liberar a memória alocada para toda a variável aluno
    } else {

        // Imprime que o nome que queremos não foi encontrado
        printf("Nome '%s' não encontrado no arquivo.\n", nome);
    }
}

void MostrarFaltas(char *materia, char *nome){

    // Atribuindo a uma variável o valor da chamada da função EncontrarDadoPorNome
    Estudante *aluno = EncontrarDadoPorNome(materia, nome);

    // Verifica se foi retornado algum valor pela função
    if (aluno != NULL) {

        // Imprime na tela os dados encontrados a partir da P1
        printf("Dados encontrados: Faltas = %i, Situação = %s\n", aluno->faltas, aluno->situ);
        free(aluno->nome); // Libera a memória alocada para o nome
        free(aluno);  // Liberar a memória alocada para toda a variável aluno
    } else {

        // Imprime que o nome que queremos não foi encontrado
        printf("Nome '%s' não encontrado no arquivo.\n", nome);
    }
}

void Aluno(membroAcademico aluno) {

    int opcao = 0;

    printf("\n\n--------- Bem vindo ao perfil de Aluno! ---------\n\n");

    do
    {
        printf("--------- Digite a opcao desejada: --------------\n");
        printf("------------------- 1 - Aviso -------------------\n");
        printf("------------------- 2 - Notas -------------------\n");
        printf("------------------- 3 - Faltas ------------------\n");
        printf("------------------- 4 - Sair --------------------\n");
        scanf("%i",&opcao);

        switch (opcao)
        {
        case 1:
            printf("Aviso será mostrado aqui!");
            getchar();
            getchar();
            break;
        case 2:
            MostrarNotas(aluno.materia, aluno.nome);
            getchar();
            getchar();
            break;
        case 3:
            MostrarFaltas(aluno.materia, aluno.nome);
            getchar();
            getchar();
            break;
        case 4:
            break;
        default:
            printf("Opcao Invalida");
            break;
        }

    } while (opcao != 4);

}

int main() {

    membroAcademico usuario;
    strcpy(usuario.cpf, "47246813810");
    strcpy(usuario.nome, "Joao");
    strcpy(usuario.senha, "senha1");
    usuario.privilegio = 3;
    usuario.materia = "MateriaLP.bin";

    // Aqui ficaria o menu principal começando pelo Login
    // E utilizando do privilegio no switch case pra acessar as funcoes
    Aluno(usuario);

    //FormatarArquivo("MateriaLP.bin");

    // Fim do código
    system("Pause");
    return 0;
}