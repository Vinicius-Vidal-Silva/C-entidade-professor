#include <stdio.h>
#include <string.h> // manipula??o de string
#include <stdlib.h> // limpar terminal e pausa no sistema
int materia();

int presenca();

int atribuicaoNotas();

int preencherNotas();

void exibirAjuda();

void definirAvaliacoes();

void editarAvaliacoes();

int main(){
	int opcao, sair;
	char confirmacao;
	sair = 0;
	printf("**************************************");
	printf("\nCase precise de ajuda digite: /ajuda");
	printf("\n**************************************");
	printf("\n");
	
	printf("\nBem vindo {Professor}.\nO que deseja fazer hoje?");
	
	do{
		printf("\n1 - Materias\n2 - Sair");
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
				printf("Materias\n");
				system("echo \"Pressione qualquer tecla para continuar\"");
                getchar();
				system("cls");
                materia();
				break;
			case 2:
				printf("Deseja realmente sair? (S/N): ");
				scanf(" %c", &confirmacao);
				fflush(stdin);
				if (confirmacao == 'S' || confirmacao == 's') {
					printf("Saindo...\n");
					sair = 1;
				} else {
					system("cls");
				}
				break;
		}
	}while(sair == 0);
}
int materia(){
    int opcao, sair;
    char confirmacao;
    sair = 0;
    printf("**************************************");
    printf("\nCase precise de ajuda digite: /ajuda");
    printf("\n**************************************");
    printf("\n");
    do{
        printf("\n1 - Definir Presencas\n2 - Atribuicao das notas (Forma avaliativa)\n3 - Prencher notas\n4 - Voltar");
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
                printf("Presenca\n");
                system("echo \"Pressione qualquer tecla para continuar\"");
                getchar();
                system("cls");
                presenca();
                break;
            case 2:
                printf("atribuir notas\n");
                system("echo \"Pressione qualquer tecla para continuar\"");
                getchar();
                system("cls");
                atribuicaoNotas();
                break;
            case 3:
                printf("preencher notas\n");
                system("echo \"Pressione qualquer tecla para continuar\"");
                getchar();
                system("cls");
                preencherNotas();
                break;
            case 4:
                printf("Deseja realmente sair? (S/N): ");
                scanf(" %c", &confirmacao);
                fflush(stdin);
                if (confirmacao == 'S' || confirmacao == 's') {
                    printf("Saindo...\n");
                    sair = 1;
                } else {
                    system("cls");
                }
                break;
        }
    }while(sair == 0);
    return 0;
}

int presenca() {
    int opcao, sair;
    char confirmacao;
    sair = 0;
    printf("**************************************");
    printf("\nCase precise de ajuda digite: /ajuda");
    printf("\n**************************************");
    printf("\n");
    do{
        printf("\n1 - Definir Chamada\n2 - ver as faltas\n3 - alterar presencas\n4 - voltar");
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
                printf("Chamada\n");
                system("echo \"Pressione qualquer tecla para continuar\"");
                getchar();
				presenca();
                system("cls");
                break;
            case 2:
                printf("ver as faltas\n");
                system("echo \"Pressione qualquer tecla para continuar\"");
                getchar();
                system("cls");
                break;
            case 3:
                printf("alterar presencas\n");
                system("echo \"Pressione qualquer tecla para continuar\"");
                getchar();
                system("cls");
                break;
            case 4:
                printf("Deseja realmente sair? (S/N): ");
                scanf(" %c", &confirmacao);
                fflush(stdin);
                if (confirmacao == 'S' || confirmacao == 's') {
                    printf("Saindo...\n");
                    sair = 1;
                } else {
                    system("cls");
                }
                break;
        }
    }while(sair == 0);
    return 0;
}
int atribuicaoNotas(){
    int opcao, sair;
    char confirmacao;
    sair = 0;
    printf("**************************************");
    printf("\nCase precise de ajuda digite: /ajuda");
    printf("\n**************************************");
    printf("\n");
    do{
        printf("\n1 - adicionar forma avaliativa\n2 - editar forma avaliativa\n3 - voltar");
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
                printf("Forma Avaliativa\n");
                definirAvaliacoes();
				system("echo \"Pressione qualquer tecla para continuar\"");
                getchar();
				//presenca();
                system("cls");
                break;
            case 2:
                printf("editar forma avaliativa\n");
                editarAvaliacoes();
				system("echo \"Pressione qualquer tecla para continuar\"");
                getchar();
                system("cls");
                break;
            case 3:
                printf("Deseja realmente sair? (S/N): ");
                scanf(" %c", &confirmacao);
                fflush(stdin);
                if (confirmacao == 'S' || confirmacao == 's') {
                    printf("Saindo...\n");
                    sair = 1;
                } else {
                    system("cls");
                }
                break;
        }
    }while(sair == 0);
    return 0;
}
int preencherNotas(){
    int opcao, sair;
    char confirmacao;
    sair = 0;
    printf("**************************************");
    printf("\nCase precise de ajuda digite: /ajuda");
    printf("\n**************************************");
    printf("\n");
    do{
        printf("\n1 - Definir Chamada\n2 - voltar");
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
                printf("Chamada\n");
                system("echo \"Pressione qualquer tecla para continuar\"");
                getchar();
                presenca();
                system("cls");
                break;
            case 2:
                printf("Deseja realmente sair? (S/N): ");
                scanf(" %c", &confirmacao);
                fflush(stdin);
                if (confirmacao == 'S' || confirmacao == 's') {
                    printf("Saindo...\n");
                    sair = 1;
                } else {
                    system("cls");
                }
                break;
        }
    }while(sair == 0);
 return 0;
}
//fun��o para exibir a ajuda
void exibirAjuda() {
    printf("\n**************************************\n");
    printf("Ajuda do Programa:\n");
    printf("1 - Definir avaliacoes: Permite definir os criterios de avaliacao.\n");
    printf("	1.1 - Avalia��es: Define a quantida de avalia��es que desejar.\n");
    printf("		1.1.1 - Peso*: Escolha o peso que deseja para as avaliacoes.\n");
    printf("	1.2 - Alterar avalia��es: Altera as avalia��es existentes");
	printf("	*Obs.: Por padrao os pesos sao definidos como 1.\n");
    printf("2 - Atribuir notas: Permite atribuir notas aos alunos.\n");
    printf("3 - Realizar chamada: Permite fazer a chamada dos alunos.\n");
    printf("4 - Fechamento da materia: Permite realizar o fechamento da materia.\n");
    printf("5 - Sair: Encerra o programa.\n");
    printf("A qualquer momento, digite '/ajuda' para exibir esta mensagem.\n");
	printf("**************************************\n");
	system("echo \"Pressione qualquer tecla para continuar...\"");
}

//fun��o para editar avalia��es existentes
void definirAvaliacoes() {
    // Abre o arquivo de avalia��es
    FILE *file = fopen("avaliacoes.txt", "r+");
    if (!file) {
        // Se o arquivo n�o existir, cria o arquivo
        file = fopen("avaliacoes.txt", "w+");
        if (!file) {
            // Caso n�o abra o arquivo, avisa ao usu�rio
            printf("Erro ao abrir o arquivo!\n");
            printf("Pressione qualquer tecla para continuar...\n");
            getchar();
            return;
        }
    }

    // Posiciona o ponteiro no final do arquivo
    fseek(file, 0, SEEK_END);

    // Define a vari�vel 'file_size' e atribui o tamanho do arquivo para ela com a fun��o ftell()
    long file_size = ftell(file);

    // Confere se o arquivo est� vazio
    if (file_size == 0) {
        char definir_pesos;
        char entrada[100];
        int num_avaliacoes = 2;
        float peso1, peso2;

        // Loop para definir os pesos das avalia��es
        
        printf("Avaliacoes P1 e P2 definidas com sucesso.\n");
        printf("Deseja definir pesos para as avaliacoes? (S/N): ");
        scanf("%c", &definir_pesos);
        /*
		while (1) {
        	printf("2 avalia��es definidas com sucesso\n");
            printf("Deseja definir pesos para as avaliacoes? (S/N): ");
            fgets(entrada, sizeof(entrada), stdin);
            entrada[strcspn(entrada, "\n")] = 0;

            if (strcmp(entrada, "/ajuda") == 0) {
                exibirAjuda();
                continue;
            }

            definir_pesos = entrada[0];
            if (definir_pesos == 'S' || definir_pesos == 's' || definir_pesos == 'N' || definir_pesos == 'n') break;

            printf("Entrada inv�lida. Tente novamente.\n");
        }
		*/
        // Come�a a escrever no arquivo
        fprintf(file, "%d\n", num_avaliacoes);
        if (definir_pesos == 'S' || definir_pesos == 's') {
            // Entrada de pesos que devem somar 1
            while (1) {
                printf("Defina o peso da avaliacao 1: ");
                fgets(entrada, sizeof(entrada), stdin);
                entrada[strcspn(entrada, "\n")] = 0;

                if (strcmp(entrada, "/ajuda") == 0) {
                    exibirAjuda();
                    continue;
                }

                peso1 = atof(entrada);
                if (peso1 > 0 && peso1 < 1) break;

                printf("Entrada inv�lida. O peso deve ser maior que 0 e menor que 1. Tente novamente.\n");
            }

            while (1) {
                printf("Defina o peso da avaliacao 2: ");
                fgets(entrada, sizeof(entrada), stdin);
                entrada[strcspn(entrada, "\n")] = 0;

                if (strcmp(entrada, "/ajuda") == 0) {
                    exibirAjuda();
                    continue;
                }

                peso2 = atof(entrada);
                if (peso2 > 0 && (peso1 + peso2 == 1)) break;

                printf("Entrada inv�lida. A soma dos pesos das avaliacoes deve ser 1. Tente novamente.\n");
            }

            fprintf(file, "Avaliacao 1: %.2f\n", peso1);
            fprintf(file, "Avaliacao 2: %.2f\n", peso2);
        } else {
            // Caso n�o deseje definir pesos, usa o peso padr�o 0.5 para cada avalia��o
            fprintf(file, "Avaliacao 1: 0.5\n");
            fprintf(file, "Avaliacao 2: 0.5\n");
        }
        printf("Avaliacoes definidas com sucesso!\n");
    } else {
        // Arquivo n�o est� vazio, exibir e perguntar se deseja alterar
        rewind(file);
        char linha[100];
        printf("Avaliacoes definidas:\n");
        while (fgets(linha, sizeof(linha), file)) {
            printf("%s", linha);
        }

        char alterar;

        while (1) {
            printf("Deseja alterar as avaliacoes? (S/N): ");
            fgets(linha, sizeof(linha), stdin);
            linha[strcspn(linha, "\n")] = 0;

            if (strcmp(linha, "/ajuda") == 0) {
                exibirAjuda();
                continue;
            }

            alterar = linha[0];
            if (alterar == 'S' || alterar == 's' || alterar == 'N' || alterar == 'n') break;

            printf("Entrada inv�lida. Tente novamente.\n");
        }

        if (alterar == 'S' || alterar == 's') {
            freopen("avaliacoes.txt", "w+", file);
            char definir_pesos;
            char entrada[100];
            int num_avaliacoes = 2;
            float peso1, peso2;

            while (1) {
                printf("Deseja definir pesos para as avaliacoes? (S/N): ");
                fgets(entrada, sizeof(entrada), stdin);
                entrada[strcspn(entrada, "\n")] = 0;

                if (strcmp(entrada, "/ajuda") == 0) {
                    exibirAjuda();
                    continue;
                }

                definir_pesos = entrada[0];
                if (definir_pesos == 'S' || definir_pesos == 's' || definir_pesos == 'N' || definir_pesos == 'n') break;

                printf("Entrada inv�lida. Tente novamente.\n");
            }

            fprintf(file, "%d\n", num_avaliacoes);
            if (definir_pesos == 'S' || definir_pesos == 's') {
                while (1) {
                    printf("Defina o peso da avaliacao 1: ");
                    fgets(entrada, sizeof(entrada), stdin);
                    entrada[strcspn(entrada, "\n")] = 0;

                    if (strcmp(entrada, "/ajuda") == 0) {
                        exibirAjuda();
                        continue;
                    }

                    peso1 = atof(entrada);
                    if (peso1 > 0 && peso1 < 1) break;

                    printf("Entrada inv�lida. O peso deve ser maior que 0 e menor que 1. Tente novamente.\n");
                }

                while (1) {
                    printf("Defina o peso da avaliacao 2: ");
                    fgets(entrada, sizeof(entrada), stdin);
                    entrada[strcspn(entrada, "\n")] = 0;

                    if (strcmp(entrada, "/ajuda") == 0) {
                        exibirAjuda();
                        continue;
                    }

                    peso2 = atof(entrada);
                    if (peso2 > 0 && (peso1 + peso2 == 1)) break;

                    printf("Entrada inv�lida. A soma dos pesos das avaliacoes deve ser 1. Tente novamente.\n");
                }

                fprintf(file, "Avaliacao 1: %.2f\n", peso1);
                fprintf(file, "Avaliacao 2: %.2f\n", peso2);
            } else {
                fprintf(file, "Avaliacao 1: 0.5\n");
                fprintf(file, "Avaliacao 2: 0.5\n");
            }
            printf("Avaliacoes redefinidas com sucesso!\n");
        } else {
            printf("Manter as avaliacoes atuais.\n");
        }
    }

    fclose(file);
    printf("Pressione qualquer tecla para continuar...");
    getchar();
}

void editarAvaliacoes() {
    //abre o arquivo de avalia��es
    FILE *file = fopen("avaliacoes.txt", "r+");
    if (!file) {
        printf("Nenhuma avaliacao definida.\n");
        system("echo \"Pressione qualquer tecla para continuar\"");
        return; // Sai da fun��o se o arquivo n�o existir
    }

    // Exibe as avalia��es existentes
    rewind(file);
    char linha[100];
    printf("Avaliacoes definidas:\n");
    while (fgets(linha, sizeof(linha), file)) {
        printf("%s", linha);
    }

    // Pergunta se o usu�rio deseja alterar os pesos
    char alterar;
    while (1) {
        printf("Deseja alterar os pesos das avaliacoes? (S/N): ");
        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = 0;

        if (strcmp(linha, "/ajuda") == 0) {
            exibirAjuda();
            continue;
        }

        alterar = linha[0];
        if (alterar == 'S' || alterar == 's' || alterar == 'N' || alterar == 'n') break;

        printf("Entrada invalida. Tente novamente.\n");
    }

    if (alterar == 'S' || alterar == 's') {
        // Usu�rio deseja alterar os pesos
        float peso1, peso2;

        // Loop para obter os pesos v�lidos do usu�rio
        while (1) {
            char entrada[100];

            // Obter o peso da primeira avalia��o
            while (1) {
                printf("Defina o peso da Avaliacao 1 (entre 0 e 1): ");
                fgets(entrada, sizeof(entrada), stdin);
                entrada[strcspn(entrada, "\n")] = 0;

                if (strcmp(entrada, "/ajuda") == 0) {
                    exibirAjuda();
                    continue;
                }

                peso1 = atof(entrada);
                if (peso1 >= 0 && peso1 <= 1) break; 

                printf("Entrada inv�lida. O peso deve estar entre 0 e 1.\n");
            }

            // Calcula o peso da segunda avalia��o
            peso2 = 1 - peso1;

            // Verifica se o peso2 � v�lido (redundante neste caso, mas �til em geral)
            if (peso2 >= 0 && peso2 <= 1) break;

            printf("A soma dos pesos deve ser igual a 1. Tente novamente.\n");
        }

        // Atualiza o arquivo com os novos pesos
        freopen("avaliacoes.txt", "w", file); // Abre para escrita, sobrescrevendo o conte�do
        fprintf(file, "2\n");                // Sempre duas avalia��es
        fprintf(file, "Avaliacao 1: %.2f\n", peso1);
        fprintf(file, "Avaliacao 2: %.2f\n", peso2);

        printf("Pesos das avaliacoes atualizados com sucesso!\n");
    } else {
        printf("Manter os pesos atuais das avaliacoes.\n");
    }

    fclose(file);
    system("echo \"Pressione qualquer tecla para continuar\"");
}
