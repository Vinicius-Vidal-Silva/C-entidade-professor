#include <stdio.h>  // Biblioteca padrão para entrada e saída de dados.
#include <stdlib.h> // Biblioteca padrão para funções de propósito geral, como alocação de memória.
#include <string.h> // Biblioteca padrão para manipulação de strings.

// Definição da estrutura do registro 
typedef struct
{
    char cpf[12];
    char senha[10];
    char nome[50];
    int privilegio;
    char materia[50]; // Usar array fixo para simplicidade
} membroAcademico;

typedef struct
{
    size_t tamNome; // Usar size_t para tamanhos
    char *nome;
    float p1;
    float p2;
    float media;
    int faltas;
    char situ[10];
} Estudante;

// Função para ler um registro do arquivo binário
int LerArquivo(FILE *file, Estudante *aluno)
{
    // Lê o tamanho do nome do estudante
    if (fread(&aluno->tamNome, sizeof(size_t), 1, file) != 1)
    {
        return 0; // Retorna 0 se a leitura falhar
    }

    // Aloca memória para armazenar o nome do estudante
    aluno->nome = (char *)malloc(aluno->tamNome + 1);
    if (aluno->nome == NULL)
    {
        return 0; // Retorna 0 se a alocação de memória falhar
    }

    // Lê o nome do estudante do arquivo
    if (fread(aluno->nome, sizeof(char), aluno->tamNome, file) != aluno->tamNome)
    {
        free(aluno->nome); // Libera a memória alocada se a leitura falhar
        return 0;          // Retorna 0 se a leitura falhar
    }
    aluno->nome[aluno->tamNome] = '\0'; // Adiciona o terminador nulo ao final do nome para indicar o final da string

    // Lê os demais campos do registro do estudante
    if (fread(&aluno->p1, sizeof(float), 1, file) != 1 ||
        fread(&aluno->p2, sizeof(float), 1, file) != 1 ||
        fread(&aluno->media, sizeof(float), 1, file) != 1 ||
        fread(&aluno->faltas, sizeof(int), 1, file) != 1 ||
        fread(aluno->situ, sizeof(char), 10, file) != 10)
    {
        free(aluno->nome); // Libera a memória alocada se a leitura falhar
        return 0;          // Retorna 0 se a leitura falhar
    }
    return 1; // Retorna 1 se a leitura for bem-sucedida
}

// Função para ler um registro do arquivo binário
int LerUsuario(FILE *file, membroAcademico *usuario)
{
    if (fread(usuario->cpf, sizeof(char), 12, file) != 12)
    {
        return 0;
    }
    if (fread(usuario->senha, sizeof(char), 10, file) != 10)
    {
        return 0;
    }
    if (fread(usuario->nome, sizeof(char), 50, file) != 50)
    {
        return 0;
    }
    if (fread(&usuario->privilegio, sizeof(int), 1, file) != 1)
    {
        return 0;
    }
    if (fread(usuario->materia, sizeof(char), 50, file) != 50)
    {
        return 0;
    }
    return 1;
}

// Função para pegar um registro específico do arquivo binário com base no nome e retornar os dados a partir de P1
Estudante *EncontrarDadoPorNome(const char *nomeArquivo, const char *nome)
{

    // Abre o arquivo binário para leitura (r de read e b de binário)
    FILE *file = fopen(nomeArquivo, "rb");

    // Verifica se o arquivo existe ou se tem permissão para acessá-lo
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo"); // Mensagem de erro
        return NULL;                       // Retorna a função com o valor nulo
    }

    Estudante temp;           // Variável do tipo struct Estudante para comparar na função
    Estudante *result = NULL; // Ponteiro em que será guardado o resultado da função

    // Enquanto a função LerArquivo retornar 1
    while (LerArquivo(file, &temp))
    {

        // Compara o valor da linha no arquivo binário com o nome que queremos encontrar
        if (strcmp(temp.nome, nome) == 0)
        {

            // Result recebe o endereço de blocos consecutivos na memória que malloc (memory allocation) retorna, sendo convertido para a struct do tipo Estudante
            result = (Estudante *)malloc(sizeof(Estudante));

            // Se o result for diferente de nulo
            if (result != NULL)
            {
                *result = temp; // Copiar o registro encontrado
            }
            break; // Sai do if e consequentemente sai do laço while
        }
        free(temp.nome); // Liberar o nome do registro temporário se não for o desejado
    }

    fclose(file);  // Fecha o arquivo
    return result; // Retorna dessa função o valor de result
}

// Função para escrever um registro no arquivo binário
void EscreverEstudante(FILE *file, Estudante *aluno)
{
    fwrite(&aluno->tamNome, sizeof(size_t), 1, file);
    fwrite(aluno->nome, sizeof(char), aluno->tamNome, file);
    fwrite(&aluno->p1, sizeof(float), 1, file);
    fwrite(&aluno->p2, sizeof(float), 1, file);
    fwrite(&aluno->media, sizeof(float), 1, file);
    fwrite(&aluno->faltas, sizeof(int), 1, file);
    fwrite(aluno->situ, sizeof(char), 10, file); // Tamanho fixo de 10 caracteres
}

// Função para escrever um registro no arquivo binário
void EscreverUsuario(FILE *file, membroAcademico *usuario)
{
    fwrite(usuario->cpf, sizeof(char), 12, file);
    fwrite(usuario->senha, sizeof(char), 10, file);
    fwrite(usuario->nome, sizeof(char), 50, file);
    fwrite(&usuario->privilegio, sizeof(int), 1, file);
    fwrite(usuario->materia, sizeof(char), 50, file);
}

// Função para formatar o arquivo com alguns usuários
void FormatarArquivoLogin(const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    membroAcademico usuarios[3] = {
        {"47735823109", "senha1", "Bruno", 1, "MateriaLP.bin"},
        {"12345678901", "senha2", "Luciano", 2, "MateriaLP.bin"},
        {"10987654321", "senha3", "Joao", 3, "MateriaLP.bin"}};

    for (int i = 0; i < 3; i++)
    {
        EscreverUsuario(file, &usuarios[i]);
    }

    fclose(file);
}

// Função para adicionar registros ao arquivo binário
void FormatarArquivo(const char *filename)
{
    FILE *file = fopen(filename, "wb"); // Abre o arquivo para escrita binária
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo"); // Mensagem de erro
        exit(1);                           // Sai do programa se a abertura do arquivo falhar
    }

    // Cria um array de 10 registros de estudantes
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
        {7, "Julia", 8.0, 7.5, 7.75, 2, "Aprovado"}};

    // Escreve os 10 registros no arquivo
    for (int i = 0; i < 10; i++)
    {
        EscreverEstudante(file, &estudantes[i]);
    }

    fclose(file); // Fecha o arquivo
}

// Função para verificar se o CPF corresponde à senha e retornar o usuário encontrado
int VerificarCpfSenha(const char *nomeArquivo, const char *cpf, const char *senha, membroAcademico *usuarioEncontrado)
{
    FILE *file = fopen(nomeArquivo, "rb");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    membroAcademico usuario;

    while (LerUsuario(file, &usuario))
    {
        if (strcmp(usuario.cpf, cpf) == 0 && strcmp(usuario.senha, senha) == 0)
        {
            *usuarioEncontrado = usuario;
            fclose(file);
            return 1; // CPF e senha correspondem
        }
    }

    fclose(file);
    return 0; // CPF e senha não correspondem
}

void MostrarNotas(char *materia, char *nome)
{

    // Atribuindo a uma variável o valor da chamada da função EncontrarDadoPorNome
    Estudante *aluno = EncontrarDadoPorNome(materia, nome);

    // Verifica se foi retornado algum valor pela função
    if (aluno != NULL)
    {

        // Imprime na tela os dados encontrados a partir da P1
        printf("Dados encontrados: P1 = %.2f, P2 = %.2f, Média = %.2f\n", aluno->p1, aluno->p2, aluno->media);
        free(aluno->nome); // Libera a memória alocada para o nome
        free(aluno);       // Liberar a memória alocada para toda a variável aluno
    }
    else
    {

        // Imprime que o nome que queremos não foi encontrado
        printf("Nome '%s' não encontrado no arquivo.\n", nome);
    }
}

void MostrarFaltas(char *materia, char *nome)
{

    // Atribuindo a uma variável o valor da chamada da função EncontrarDadoPorNome
    Estudante *aluno = EncontrarDadoPorNome(materia, nome);

    // Verifica se foi retornado algum valor pela função
    if (aluno != NULL)
    {

        // Imprime na tela os dados encontrados a partir da P1
        printf("Dados encontrados: Faltas = %i, Situação = %s\n", aluno->faltas, aluno->situ);
        free(aluno->nome); // Libera a memória alocada para o nome
        free(aluno);       // Liberar a memória alocada para toda a variável aluno
    }
    else
    {

        // Imprime que o nome que queremos não foi encontrado
        printf("Nome '%s' não encontrado no arquivo.\n", nome);
    }
}

void MostrarTodosOsAlunos(const char *nomeArquivo)
{
    FILE *file = fopen(nomeArquivo, "rb");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Estudante aluno;
    printf("Tabela de alunos registrados:\n");
    printf("-------------------------------\n");
    printf("| Nome                          |\n");
    printf("-------------------------------\n");

    while (LerArquivo(file, &aluno))
    {
        printf("| %-30s |\n", aluno.nome);
        free(aluno.nome);
    }

    printf("-------------------------------\n");
    fclose(file);
}

void AtribuirNotas(char *materia)
{

    char nome[50];
    int escolha;
    float novaNota;
    int encontrado = 0;

    // Mostrar todos os alunos registrados no arquivo
    MostrarTodosOsAlunos(materia);

    printf("Digite o nome do aluno: ");
    scanf("%s", nome);

    FILE *file = fopen(materia, "rb+");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Estudante aluno;

    while (LerArquivo(file, &aluno))
    {
        if (strcmp(aluno.nome, nome) == 0)
        {
            encontrado = 1;
            printf("Notas atuais - P1: %.2f, P2: %.2f, Média: %.2f\n", aluno.p1, aluno.p2, aluno.media);
            printf("Escolha qual avaliação deseja lançar/alterar a nota:\n1 - P1\n2 - P2\n");
            scanf("%d", &escolha);

            if (escolha == 1)
            {
                printf("Digite a nova nota para P1: ");
                scanf("%f", &novaNota);
                aluno.p1 = novaNota;
            }
            else if (escolha == 2)
            {
                printf("Digite a nova nota para P2: ");
                scanf("%f", &novaNota);
                aluno.p2 = novaNota;
            }
            else
            {
                printf("Opção inválida.\n");
                system("pause");
                free(aluno.nome);
                fclose(file);
                return;
            }

            // Atualizar a média e a situação
            aluno.media = (aluno.p1 + aluno.p2) / 2.0;
            strcpy(aluno.situ, aluno.media >= 6.0 ? "Aprovado" : "Reprovado");

            // Atualizar o registro no arquivo
            fseek(file, -((long)(sizeof(size_t) + aluno.tamNome + sizeof(float) * 3 + sizeof(int) + 10)), SEEK_CUR);
            EscreverEstudante(file, &aluno);
            printf("Notas atualizadas com sucesso!\n");
            system("pause");

            free(aluno.nome);
            break;
        }
        free(aluno.nome);
    }

    if (!encontrado)
    {
        printf("Aluno '%s' não encontrado no arquivo.\n", nome);
    }

    fclose(file);
}

void RealizarChamada(char *materia)
{

    int presente;

    FILE *file = fopen(materia, "rb+");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Estudante aluno;
    long pos;

    while (fread(&aluno.tamNome, sizeof(size_t), 1, file) == 1)
    {
        aluno.nome = (char *)malloc(aluno.tamNome + 1);
        if (fread(aluno.nome, sizeof(char), aluno.tamNome, file) != aluno.tamNome)
        {
            free(aluno.nome);
            break;
        }
        aluno.nome[aluno.tamNome] = '\0';
        if (fread(&aluno.p1, sizeof(float), 1, file) != 1 ||
            fread(&aluno.p2, sizeof(float), 1, file) != 1 ||
            fread(&aluno.media, sizeof(float), 1, file) != 1 ||
            fread(&aluno.faltas, sizeof(int), 1, file) != 1 ||
            fread(aluno.situ, sizeof(char), 10, file) != 10)
        {
            free(aluno.nome);
            break;
        }

        printf("Nome: %s, Faltas: %d\n", aluno.nome, aluno.faltas);
        printf("O aluno está presente? (1 para sim, 0 para não): ");
        scanf("%d", &presente);

        if (!presente)
        {
            aluno.faltas += 1;
        }

        pos = ftell(file);
        fseek(file, pos - ((long)(sizeof(size_t) + aluno.tamNome + sizeof(float) * 3 + sizeof(int) + 10)), SEEK_SET);
        EscreverEstudante(file, &aluno);
        fseek(file, pos, SEEK_SET);

        free(aluno.nome);
    }

    fclose(file);
    printf("Chamada realizada com sucesso!\n");
    system("pause");
}

void FechamentoMateria(char *materia) {
    int opcao;
    char nomeAluno[50];
    FILE *file;
    Estudante aluno;

    printf("Deseja exibir o relatório por:\n1 - Aluno\n2 - Disciplina\n");
    scanf("%d", &opcao);
    fflush(stdin);

    if (opcao == 1) {
        printf("Digite o nome do aluno: ");
        scanf("%49s", nomeAluno);
        fflush(stdin);

        file = fopen(materia, "rb");
        if (file == NULL) {
            perror("Erro ao abrir o arquivo");
            return;
        }

        int encontrado = 0;
        while (LerArquivo(file, &aluno)) {
            if (strcmp(aluno.nome, nomeAluno) == 0) {
                encontrado = 1;
                printf("\nAluno encontrado:\n");
                printf("Nome: %s\n", aluno.nome);
                printf("P1: %.2f\n", aluno.p1);
                printf("P2: %.2f\n", aluno.p2);
                printf("Media: %.2f\n", aluno.media);
                printf("Faltas: %d\n", aluno.faltas);
                printf("Situacao: %s\n", aluno.situ);
                free(aluno.nome);
                break;
            }
            free(aluno.nome);
        }

        if (!encontrado) {
            printf("Aluno '%s' não encontrado no arquivo.\n", nomeAluno);
        }

        fclose(file);
    } else if (opcao == 2) {
        file = fopen(materia, "rb");
        if (file == NULL) {
            perror("Erro ao abrir o arquivo");
            return;
        }

        printf("Relatório por disciplina:\n");

        while (LerArquivo(file, &aluno)) {
            printf("\nNome: %s\n", aluno.nome);
            printf("P1: %.2f\n", aluno.p1);
            printf("P2: %.2f\n", aluno.p2);
            printf("Media: %.2f\n", aluno.media);
            printf("Faltas: %d\n", aluno.faltas);
            printf("Situacao: %s\n", aluno.situ);
            free(aluno.nome);
        }

        fclose(file);
    } else {
        printf("Opção inválida.\n");
    }
}

void Aluno(membroAcademico aluno)
{
    char opcao[100];   // Opção do menu
    char escolha[100]; // Variável para armazenar a escolha de sair

    // Laço do menu
    do
    {
        // Exibe o menu
        printf("\n\n-------------- Bem vindo %s! --------------\n\n", aluno.nome);
        printf("--------- Digite a opcao desejada: --------------\n");
        printf("------------------- 1 - Aviso -------------------\n");
        printf("------------------- 2 - Notas -------------------\n");
        printf("------------------- 3 - Faltas ------------------\n");
        printf("------------------- 4 - Sair --------------------\n");
        scanf("%s", opcao);
        fflush(stdin);
        system("cls");

        // Verifica o comprimento da opção digitada
        if (strlen(opcao) > 1)
        {
            opcao[0] = '5'; // Se o comprimento for maior que 1 define '5' para retornar uma opção inválida
        }

        // Trata a opção escolhida
        switch (opcao[0])
        {
        case '1':
            printf("Aviso será mostrado aqui!");
            printf("\nPressione enter para continuar. . .");
            fflush(stdin); // Limpa o buffer de entrada do teclado
            getchar();     // Aguarda uma tecla ser pressionada antes de continuar
            break;
        case '2':
            MostrarNotas(aluno.materia, aluno.nome); // Mostra as notas do aluno
            printf("\nPressione enter para continuar. . .");
            fflush(stdin); // Limpa o buffer de entrada do teclado
            getchar();     // Aguarda uma tecla ser pressionada antes de continuar
            break;
        case '3':
            MostrarFaltas(aluno.materia, aluno.nome); // Mostra as faltas do aluno
            printf("\nPressione enter para continuar. . .");
            fflush(stdin); // Limpa o buffer de entrada do teclado
            getchar();     // Aguarda uma tecla ser pressionada antes de continuar
            break;
        case '4':
            do
            {
                // Pergunta se deseja realmente sair
                printf("Deseja realmente sair?\n1- Sim\n2- Nao\n");
                scanf("%s", escolha);
                fflush(stdin);
                // Verifica o comprimento da escolha de saída
                if (strlen(escolha) > 1)
                {
                    escolha[0] = '3'; // Se o comprimento for maior que 1, define '3' para retornar uma opção inválida
                }
                if (escolha[0] == '1')
                {
                    printf("\nSaindo. . .");
                    fflush(stdin);  // Limpa o buffer de entrada do teclado
                    getchar();      // Aguarda uma tecla ser pressionada antes de continuar
                    opcao[0] = '4'; // Sai do menu
                    break;
                }
                else if (escolha[0] == '2')
                {
                    opcao[0] = '5';
                }
                else
                {
                    printf("Opcao invalida\n");
                    printf("Pressione enter para continuar. . .\n");
                    fflush(stdin); // Limpa o buffer de entrada do teclado
                    getchar();     // Aguarda uma tecla ser pressionada antes de continuar
                }
            } while (escolha[0] != '1' && escolha[0] != '2');
            break;
        default:
            printf("Opcao Invalida\n");
            printf("Pressione enter para continuar. . .\n");
            fflush(stdin); // Limpa o buffer de entrada do teclado
            getchar();     // Aguarda uma tecla ser pressionada antes de continuar
            break;
        }

        if (opcao[0] != '4')
        {
            printf("Voltando ao menu...\n");
            fflush(stdin); // Limpa o buffer de entrada do teclado
            getchar();     // Aguarda uma tecla ser pressionada antes de continuar
        }
        system("cls"); // Limpa a tela (no Windows)
    } while (opcao[0] != '4');
}

void Professor(membroAcademico professor)
{

    int opcao;
    int sair;
    sair = 0;

    printf("\nBem vindo(a), Prof. %s.\nO que deseja fazer hoje?", professor.nome);

    do
    {
        printf("\n1 - Atribuir notas\n2 - Realizar chamada\n3 - Fechamento da materia\n4 - Sair");
        printf("\nEntre com a opcao desejada:");
        scanf("%i", &opcao);
        fflush(stdin);
        switch (opcao)
        {
        default:
            printf("Opcao invalida, tente novamente!\n");
            system("echo \"Pressione qualquer tecla para continuar\"");
            getchar();
            system("cls");
            break;
        case 1:
            AtribuirNotas(professor.materia);
            system("echo \"Pressione qualquer tecla para continuar\"");
            getchar();
            system("cls");
            break;
        case 2:
            RealizarChamada(professor.materia);
            system("echo \"Pressione qualquer tecla para continuar\"");
            getchar();
            system("cls");
            break;
        case 3:
            FechamentoMateria(professor.materia);
            system("echo \"Pressione qualquer tecla para continuar\"");
            getchar();
            system("cls");
            break;
        case 4:
            while (1)
            {
                printf("Deseja realmente sair?\n1 - Sim\n2 - Nao\n");
                scanf("%i", &sair);
                fflush(stdin);
                if (sair == 1)
                {
                    printf("Saindo...");
                    break;
                }
                else if (sair == 2)
                {
                    sair = 0;
                    break;
                }
                else
                {
                    printf("Opcao invalida. Tente novamente!\n");
                }
            }
            break;
        }
    } while (sair == 0);
}

int main()
{
    const char *nomeArquivo = "login.bin";

    // Descomente essa linha se quiser criar o arquivo binário de Login do zero (comente o resto da main até o system pause)
    // FormatarArquivoLogin(nomeArquivo);

    // Variáveis para armazenar o CPF, senha e privilégio do usuário
    char cpf[12];
    char senha[10];
    membroAcademico usuarioEncontrado;

    printf("\n**************************************\n");
    printf("          Bem vindo ao SIGA!            ");
    printf("\n**************************************\n");

    printf("Digite o CPF: ");
    scanf("%11s", cpf);
    printf("Digite a senha: ");
    scanf("%9s", senha);

    // Verificar se o CPF e a senha correspondem
    if (VerificarCpfSenha(nomeArquivo, cpf, senha, &usuarioEncontrado))
    {
        switch (usuarioEncontrado.privilegio)
        {
        case 1:
            printf("Você é Administrador.\n");
            break;
        case 2:
            printf("Você é Professor.\n");
            Professor(usuarioEncontrado);
            break;
        case 3:
            printf("Você é Aluno.\n");
            Aluno(usuarioEncontrado);
            break;
        default:
            printf("Privilégio desconhecido.\n");
            break;
        }
    }
    else
    {
        printf("CPF e/ou senha incorretos.\n");
    }

    system("pause");
    return 0;
}
