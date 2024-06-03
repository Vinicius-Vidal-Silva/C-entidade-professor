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
//função para exibir a ajuda
void exibirAjuda() {
    printf("\n**************************************\n");
    printf("Ajuda do Programa:\n");
    printf("1 - Definir avaliacoes: Permite definir os criterios de avaliacao.\n");
    printf("	1.1 - Avaliações: Define a quantida de avaliações que desejar.\n");
    printf("		1.1.1 - Peso*: Escolha o peso que deseja para as avaliacoes.\n");
    printf("	1.2 - Alterar avaliações: Altera as avaliações existentes");
	printf("	*Obs.: Por padrao os pesos sao definidos como 1.\n");
    printf("2 - Atribuir notas: Permite atribuir notas aos alunos.\n");
    printf("3 - Realizar chamada: Permite fazer a chamada dos alunos.\n");
    printf("4 - Fechamento da materia: Permite realizar o fechamento da materia.\n");
    printf("5 - Sair: Encerra o programa.\n");
    printf("A qualquer momento, digite '/ajuda' para exibir esta mensagem.\n");
	printf("**************************************\n");
	system("echo \"Pressione qualquer tecla para continuar...\"");
}

//função para editar avaliações existentes
void definirAvaliacoes(){
	//abre o arquivo de avaliações
	FILE *file = fopen("avaliacoes.txt", "r+");
	if(!file){
		//se o arquivo não existir, entra na condicional
		//e cria o arquivo
		file = fopen("avaliacoes.txt", "w+");
		if(!file){
			//caso não abra o arquivo
			//avisa ao usuário
			printf("Erro ao abrir o arquivo!");
			system("echo \"Pressione qualquer tecla para continuar...\"");
			return;
		}
	}
	//posiciona o ponteiro em um posição específica
	//nesse caso posiciona no final do arquivo
	fseek(file, 0, SEEK_END);
	
	//define a variável 'file_size' e atribui
	//o tamanho do arquivo para ela com a função
	//ftell()
	long file_size = ftell(file);
	
	//confere se o arquivo está vazio
	//se estiver vazio entra no loop
	if(file_size == 0){
		int num_avaliacoes;
        char definir_pesos;
        char entrada[100];
        
		//enquanto o usuário digitar '/ajuda' ou uma entrada
		//inválida, o loop continua    
        while (1) {
            printf("Defina o numero de avaliacoes: ");
            //função para pegar a entrada do usuário
            fgets(entrada, sizeof(entrada), stdin);
            //substitui o "\n" por um caracter nulo "\0"
            entrada[strcspn(entrada, "\n")] = 0;
			
			//compara a entrada com '/ajuda' se for igual exibe
			// a função ajuda
            if (strcmp(entrada, "/ajuda") == 0) {
                exibirAjuda();
                continue;
            }
			
			//converte a entrada em inteiro
            num_avaliacoes = atoi(entrada);
            if (num_avaliacoes > 0) break;
			
			//se o numero de avaliação for inálido ou <= a zero 
			//exibe mensagem de erro
            printf("Entrada inválida. Tente novamente.\n");
        }

		//enquanto o usuário digitar '/ajuda' ou uma entrada
		//inválida, o loop continua
        while (1) {
            printf("Deseja definir pesos para as avaliacoes? (S/N): ");
            //função para pegar a entrada do usuário
            //3 parâmetros: variável de entrada, tamanho e método
			fgets(entrada, sizeof(entrada), stdin);
            //substitui o "\n" por um caracter nulo "\0"
			entrada[strcspn(entrada, "\n")] = 0;

			//compara a entrada com '/ajuda' se for igual exibe
			// a função ajuda
            if (strcmp(entrada, "/ajuda") == 0) {
                exibirAjuda();
                continue;
            }
			
			//verifica se o usuário deseja definir peso ou não
			//definir peso assumi "s";"S";"n" ou "N"
            definir_pesos = entrada[0];
            if (definir_pesos == 'S' || definir_pesos == 's' || definir_pesos == 'N' || definir_pesos == 'n') break;

            printf("Entrada inválida. Tente novamente.\n");
        }
 
        //começa a escrever no arquivo
        fprintf(file, "%d\n", num_avaliacoes);
        //entra no loop para escrever as avaliações e pesos no arquivo
        for (int i = 1; i <= num_avaliacoes; i++) {
        	//se o usuário escolheu definir peso, entra no na condição
            if (definir_pesos == 'S' || definir_pesos == 's') {
                float peso;

                while (1) {
                    printf("Defina o peso da avaliacao %d: ", i);
                    //função para pegar a entrada do usuário
            		//3 parâmetros: variável de entrada, tamanho e método
					fgets(entrada, sizeof(entrada), stdin);
                    //substitui o "\n" por um caracter nulo "\0"
					entrada[strcspn(entrada, "\n")] = 0;

					//compara a entrada com '/ajuda' se for igual exibe
					//a função ajuda
                    if (strcmp(entrada, "/ajuda") == 0) {
                        exibirAjuda();
                        continue;
                    }
					
					//converte a entrada em inteiro
                    peso = atof(entrada);
                    if (peso > 0) break;

                    printf("Entrada inválida. Tente novamente.\n");
                }
				//exibe/grava as avalições com os pesos definidos pelo usuário
                fprintf(file, "Avaliacao %d: %.2f\n", i, peso);
            } else {
            	//exibe/grava as avaliações com peso padrão = 1
                fprintf(file, "Avaliacao %d: 1\n", i); // Peso padrão 1
            }
        }
        printf("Avaliacoes definidas com sucesso!\n");
	}else{
		// Arquivo não está vazio, exibir e perguntar se deseja alterar
        //volta o ponteiro para o início do arquivo
		rewind(file);
        char linha[100];
        //exibe as avaliações e pesos existentes no arquivo
        printf("Avaliacoes definidas:\n");
        //cria o loop para exibir todas as avaliações e pesos nos arquivo
        while (fgets(linha, sizeof(linha), file)) {
            printf("%s", linha);
        }
        
        char alterar;
        
        //pergunta se o usuário deseja alterar os dados existentes
		while (1) {
            printf("Deseja alterar as avaliacoes? (S/N): ");
            //função para pegar a entrada do usuário
            //3 parâmetros: variável de entrada, tamanho e método
			fgets(linha, sizeof(linha), stdin);
            //substitui o "\n" por um caracter nulo "\0"
			linha[strcspn(linha, "\n")] = 0;

			//compara a entrada com '/ajuda' se for igual exibe
			//a função ajuda
            if (strcmp(linha, "/ajuda") == 0) {
                exibirAjuda();
                continue;
            }

            alterar = linha[0];
            if (alterar == 'S' || alterar == 's' || alterar == 'N' || alterar == 'n') break;

            printf("Entrada inválida. Tente novamente.\n");
        }

        if (alterar == 'S' || alterar == 's') {
            freopen("avaliacoes.txt", "w+", file);
            int num_avaliacoes;
            char definir_pesos;
            char entrada[100];

            while (1) {
                printf("Defina o numero de avaliacoes: ");
                fgets(entrada, sizeof(entrada), stdin);
                entrada[strcspn(entrada, "\n")] = 0;

                if (strcmp(entrada, "/ajuda") == 0) {
                    exibirAjuda();
                    continue;
                }

                num_avaliacoes = atoi(entrada);
                if (num_avaliacoes > 0) break;

                printf("Entrada inválida. Tente novamente.\n");
            }

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

                printf("Entrada inválida. Tente novamente.\n");
            }

            fprintf(file, "%d\n", num_avaliacoes);
            for (int i = 1; i <= num_avaliacoes; i++) {
                if (definir_pesos == 'S' || definir_pesos == 's') {
                    float peso;

                    while (1) {
                        printf("Defina o peso da avaliacao %d: ", i);
                        fgets(entrada, sizeof(entrada), stdin);
                        entrada[strcspn(entrada, "\n")] = 0;

                        if (strcmp(entrada, "/ajuda") == 0) {
                            exibirAjuda();
                            continue;
                        }

                        peso = atof(entrada);
                        if (peso > 0) break;

                        printf("Entrada inválida. Tente novamente.\n");
                    }

                    fprintf(file, "Avaliacao %d: %.2f\n", i, peso);
                } else {
                    fprintf(file, "Avaliacao %d: 1\n", i); // Peso padrão 1
                }
            }
            printf("Avaliacoes redefinidas com sucesso!\n");
        } else {
            printf("Manter as avaliacoes atuais.\n");
        }
    }

    fclose(file);
	system("echo \"Pressione qualquer tecla para continuar\"");
}

void editarAvaliacoes(){
	//abre o arquivo de avaliações
	FILE *file = fopen("avaliacoes.txt", "r+");
	if(!file){
		printf("Nenhuma avaliacao definida.\n");
		system("echo \"Pressione qualquer tecla para continuar\"");
	}	

	// Arquivo não está vazio, exibir e perguntar se deseja alterar
    //volta o ponteiro para o início do arquivo
	rewind(file);
    char linha[100];
    //exibe as avaliações e pesos existentes no arquivo
    printf("Avaliacoes definidas:\n");
    //cria o loop para exibir todas as avaliações e pesos nos arquivo
    while (fgets(linha, sizeof(linha), file)) {
        printf("%s", linha);
    }
    
    char alterar;
    
    //pergunta se o usuário deseja alterar os dados existentes
	while (1) {
    	printf("Deseja alterar as avaliacoes? (S/N): ");
        //função para pegar a entrada do usuário
        //3 parâmetros: variável de entrada, tamanho e método
		fgets(linha, sizeof(linha), stdin);
        //substitui o "\n" por um caracter nulo "\0"
		linha[strcspn(linha, "\n")] = 0;

		//compara a entrada com '/ajuda' se for igual exibe
		//a função ajuda
        if (strcmp(linha, "/ajuda") == 0) {
            exibirAjuda();
            continue;
    	}

    alterar = linha[0];
    
    if (alterar == 'S' || alterar == 's' || alterar == 'N' || alterar == 'n') break;

    printf("Entrada inválida. Tente novamente.\n");
    }

    if (alterar == 'S' || alterar == 's') {
        freopen("avaliacoes.txt", "w+", file);
        int num_avaliacoes;
        char definir_pesos;
        char entrada[100];

        while (1) {
            printf("Defina o numero de avaliacoes: ");
            fgets(entrada, sizeof(entrada), stdin);
            entrada[strcspn(entrada, "\n")] = 0;

            if (strcmp(entrada, "/ajuda") == 0) {
                exibirAjuda();
                continue;
            }

            num_avaliacoes = atoi(entrada);
            if (num_avaliacoes > 0) break;

            printf("Entrada inválida. Tente novamente.\n");
        }

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

            printf("Entrada inválida. Tente novamente.\n");
        }

        fprintf(file, "%d\n", num_avaliacoes);
        for (int i = 1; i <= num_avaliacoes; i++) {
            if (definir_pesos == 'S' || definir_pesos == 's') {
                float peso;

                while (1) {
                    printf("Defina o peso da avaliacao %d: ", i);
                    fgets(entrada, sizeof(entrada), stdin);
                    entrada[strcspn(entrada, "\n")] = 0;

                    if (strcmp(entrada, "/ajuda") == 0) {
                        exibirAjuda();
                        continue;
                    }

                    peso = atof(entrada);
                    if (peso > 0) break;

                    printf("Entrada inválida. Tente novamente.\n");
                }

                fprintf(file, "Avaliacao %d: %.2f\n", i, peso);
            } else {
                fprintf(file, "Avaliacao %d: 1\n", i); // Peso padrão 1
            }
        }
        
        printf("Avaliacoes redefinidas com sucesso!\n");
        
    } else {
        printf("Manter as avaliacoes atuais.\n");
    }
    
  	fclose(file);
	system("echo \"Pressione qualquer tecla para continuar\"");
}
