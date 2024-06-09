#include <stdio.h>
#include <string.h> // manipulacao de string
#include <stdlib.h> // limpar terminal e pausa no sistema

typedef struct{
    char cpf[11];
    char nome[50];
    char senha[10];
    int privilegio;
    char *materia;
}membroAcademico;

typedef struct {
    size_t tamNome;  // Usar size_t para tamanhos
    char *nome;
    float p1;
    float p2;
    float media;
    int faltas;
    char situ[10];
}Estudante;

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

// Função para escrever um registro no arquivo binário
void EscreverEstudante(FILE *file, Estudante *aluno) {
    fwrite(&aluno->tamNome, sizeof(size_t), 1, file);
    fwrite(aluno->nome, sizeof(char), aluno->tamNome, file);
    fwrite(&aluno->p1, sizeof(float), 1, file);
    fwrite(&aluno->p2, sizeof(float), 1, file);
    fwrite(&aluno->media, sizeof(float), 1, file);
    fwrite(&aluno->faltas, sizeof(int), 1, file);
    fwrite(aluno->situ, sizeof(char), 10, file);  // Tamanho fixo de 10 caracteres
}

void MostrarTodosOsAlunos(const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "rb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Estudante aluno;
    printf("Tabela de alunos registrados:\n");
    printf("-------------------------------\n");
    printf("| Nome                          |\n");
    printf("-------------------------------\n");

    while (LerArquivo(file, &aluno)) {
        printf("| %-30s |\n", aluno.nome);
        free(aluno.nome);
    }

    printf("-------------------------------\n");
    fclose(file);
}

void AtribuirNotas(char *materia) {

    char nome[50];
    int escolha;
    float novaNota;
    int encontrado = 0;

    // Mostrar todos os alunos registrados no arquivo
    MostrarTodosOsAlunos(materia);
    getchar();

    printf("Digite o nome do aluno: ");
    scanf("%s", nome);

    FILE *file = fopen(materia, "rb+");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Estudante aluno;

    while (LerArquivo(file, &aluno)) {
        if (strcmp(aluno.nome, nome) == 0) {
            encontrado = 1;
            printf("Notas atuais - P1: %.2f, P2: %.2f, Media: %.2f\n", aluno.p1, aluno.p2, aluno.media);
            printf("Escolha qual avaliacao deseja lancar/alterar a nota:\n1 - P1\n2 - P2\n");
            scanf("%d", &escolha);

            if (escolha == 1) {
                printf("Digite a nova nota para P1: ");
                scanf("%f", &novaNota);
                aluno.p1 = novaNota;
            } else if (escolha == 2) {
                printf("Digite a nova nota para P2: ");
                scanf("%f", &novaNota);
                aluno.p2 = novaNota;
            } else {
                printf("Opcaoo invalida.\n");
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

    if (!encontrado) {
        printf("Aluno '%s' nao encontrado no arquivo.\n", nome);
    }

    fclose(file);
}

void RealizarChamada(char *materia) {

    int presente;

    FILE *file = fopen(materia, "rb+");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Estudante aluno;
    long pos;

    while (fread(&aluno.tamNome, sizeof(size_t), 1, file) == 1) {
        aluno.nome = (char *)malloc(aluno.tamNome + 1);
        if (fread(aluno.nome, sizeof(char), aluno.tamNome, file) != aluno.tamNome) {
            free(aluno.nome);
            break;
        }
        aluno.nome[aluno.tamNome] = '\0';
        if (fread(&aluno.p1, sizeof(float), 1, file) != 1 ||
            fread(&aluno.p2, sizeof(float), 1, file) != 1 ||
            fread(&aluno.media, sizeof(float), 1, file) != 1 ||
            fread(&aluno.faltas, sizeof(int), 1, file) != 1 ||
            fread(aluno.situ, sizeof(char), 10, file) != 10) {
            free(aluno.nome);
            break;
        }

        printf("Nome: %s, Faltas: %d\n", aluno.nome, aluno.faltas);
        printf("O aluno este� presente? (1 para sim, 0 para nao): ");
        scanf("%d", &presente);

        if (!presente) {
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

void FechamentoMateria(){

}

void Professor(membroAcademico professor){

    int opcao;
	int sair;
	sair = 0;
	
	printf("**************************************");
	printf("\nBem vindo ao SIGA");
	printf("\n**************************************");
	printf("\n");
	
	printf("\nBem vindo(a), Prof. %s.\nO que deseja fazer hoje?", professor.nome);
	
	do{
		printf("\n1 - Atribuir notas\n2 - Realizar chamada\n3 - Fechamento da materia\n4 - Sair");
		printf("\nEntre com a opcao desejada:");
		scanf("%i", &opcao);
		fflush(stdin);
		switch (opcao){
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
				printf("Fechamento\n");
				system("echo \"Pressione qualquer tecla para continuar\"");
				getchar();
				system("cls");
				break;
			case 4:
			    while (1) {
                    printf("Deseja realmente sair?\n1 - Sim\n2 - Nao\n");
                    scanf("%i", &sair);
                    fflush(stdin);
                    if (sair == 1) {
                    	printf("Saindo...");
                        break;
                    } else if (sair == 2) {
                        sair = 0;
                        break;
                    } else {
                        printf("Opcao invalida. Tente novamente!\n");
                    }
                }
                break;
		}
	}while(sair == 0);
	
}

int main(){

    membroAcademico usuario;
    strcpy(usuario.cpf, "123456789");
    strcpy(usuario.nome, "Luciano");
    strcpy(usuario.senha, "senha1");
    usuario.privilegio = 2;
    usuario.materia = "MateriaLP.bin";

    Professor(usuario);

	
}
