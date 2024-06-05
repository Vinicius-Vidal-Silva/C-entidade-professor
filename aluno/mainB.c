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
} Estudante;

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
        fread(&aluno->media, sizeof(float), 1, file) != 1) {
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
void Aluno() {

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
            MostrarNotas("MateriaLP.bin", "Joao");
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

    // Aqui ficaria o menu principal começando pelo Login
    // E utilizando do privilegio no switch case pra acessar as funcoes
    Aluno();

    // Fim do código
    system("Pause");
    return 0;
}