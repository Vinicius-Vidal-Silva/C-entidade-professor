#include <stdio.h>
#include <string.h> // manipula??o de string
#include <stdlib.h> // limpar terminal e pausa no sistema
#include <ctype.h> // inclui a função de mudar minúscula

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

//função para editar avaliações existentes
void definirAvaliacoes() {
	FILE *file = fopen("avaliacoes.txt", "r+");
    if (!file) {
        // Se o arquivo não existir, cria o arquivo
        file = fopen("avaliacoes.txt", "w+");
        if (!file) {
            // Caso não abra o arquivo, avisa ao usuário
            printf("Erro ao abrir o arquivo!\n");
            printf("Pressione qualquer tecla para continuar...\n");
            getchar();
            return;
        }
    }

    // Posiciona o ponteiro no final do arquivo
    fseek(file, 0, SEEK_END);

    // Define a variável 'file_size' e atribui o tamanho do arquivo para ela com a função ftell()
    long file_size = ftell(file);

    // Confere se o arquivo está vazio
    if (file_size == 0) {
		char escolher_peso;
		float peso1, peso2;
		float pesos = 1.0;
		
	    printf("De acordo com o Regimento interno e institucional, toda matéria deve possuir 2 notas.\n");
	    printf("Duas notas definidas com sucesso.\n");
	    
	    do{
	    	printf("Deseja definir peso para as notas? (S/N)\n");
	    	scanf("%c", &escolher_peso);
	    	fflush(stdin);
		}while(tolower(escolher_peso) != 's' && tolower(escolher_peso) != 'n');
	    
	    do{
		    if(tolower(escolher_peso) == 's'){
		    	printf("Entre com o peso da primeira nota: ");
		    	scanf("%f", &peso1);
		    	fflush(stdin);	
				
				if(peso1 > 1){
					printf("O valor do peso precisa estar entre 0 e 1.\n");
				}
				
				peso2 = pesos - peso1; 		
				
				printf("Avaliacoes definidas com sucesso!\n");
				fprintf(file, "Avaliacao 1: %.2f\n", peso1);
        		fprintf(file, "Avaliacao 2: %.2f\n", peso2);
        		
			}else{
				// Caso não deseje definir pesos, usa o peso padrão 0.5 para cada avaliação
				printf("Avaliacoes definidas com sucesso!\n");
				fprintf(file, "Avaliacao 1: 0.5\n");
    			fprintf(file, "Avaliacao 2: 0.5\n");
			}
			
		}while(peso1 > 1);
			printf("Opa");
	}else {
		// Arquivo não está vazio, exibir e perguntar se deseja alterar
	    rewind(file);
	    char alterar;
	    char linha[100];
	    float peso1, peso2;
	    printf("Avaliacoes definidas:\n");
	    //escreve a linha do arquivo na tela
		while (fgets(linha, sizeof(linha), file)) {
	    	printf("%s", linha);
   		}
		
		while(1){
			printf("Deseja alterar as avaliacoes? (S/N)\n");
			scanf("%c", &alterar);
			fflush(stdin);
		    
			if (tolower(alterar) == 's' || tolower(alterar) == 'n'){
				break;	
			} 

            printf("Entrada inválida. Tente novamente.\n");
    	}
    	//resposta para sim
    	if (tolower(alterar) == 's') {
            freopen("avaliacoes.txt", "w+", file);
            char escolher_pesos;
            char entrada[100];
            int num_avaliacoes = 2;
            int pesos = 1;
            float peso1, peso2;
    		
			do{
	    		printf("Deseja definir peso para as notas? (S/N)\n");
	    		scanf("%c", &escolher_pesos);
	    		fflush(stdin);
			}while(tolower(escolher_pesos) != 's' && tolower(escolher_pesos) != 'n');
			
			do{
			    if(tolower(escolher_pesos) == 's'){
			    	printf("Entre com o peso da primeira nota: ");
			    	scanf("%f", &peso1);
			    	fflush(stdin);	
					
					if(peso1 > 1){
						printf("O valor do peso precisa estar entre 0 e 1.\n");
					}
					
					peso2 = pesos - peso1; 		
					printf("Avaliacoes definidas com sucesso!\n");
					fprintf(file, "Avaliacao 1: %.2f\n", peso1);
	        		fprintf(file, "Avaliacao 2: %.2f\n", peso2);
	        		
				}else{
					// Caso não deseje definir pesos, usa o peso padrão 0.5 para cada avaliação
					printf("Avaliacoes definidas com sucesso!\n");
					fprintf(file, "Avaliacao 1: 0.5\n");
	    			fprintf(file, "Avaliacao 2: 0.5\n");
				}	
			}while(peso1 > 1);
    	}
	}
}

//função para editar avaliação
void editarAvaliacoes() {
	FILE *file = fopen("avaliacoes.txt", "r+");
	// altera o arquivo existente
	rewind(file);
    char alterar;
    char linha[100];
    float peso1, peso2;
    printf("Avaliacoes definidas:\n");
    //escreve a linha do arquivo na tela
	while (fgets(linha, sizeof(linha), file)) {
    	printf("%s", linha);
	}
	
	while(1){
		printf("Deseja alterar as avaliacoes? (S/N)\n");
		scanf("%c", &alterar);
		fflush(stdin);
	    
		if (tolower(alterar) == 's' || tolower(alterar) == 'n'){
			break;	
		} 

        printf("Entrada inválida. Tente novamente.\n");
	}
	//resposta para sim
	if (tolower(alterar) == 's') {
        freopen("avaliacoes.txt", "w+", file);
        char escolher_pesos;
        char entrada[100];
        int num_avaliacoes = 2;
        int pesos = 1;
        float peso1, peso2;
		
		do{
    		printf("Deseja definir peso para as notas? (S/N)\n");
    		scanf("%c", &escolher_pesos);
    		fflush(stdin);
		}while(tolower(escolher_pesos) != 's' && tolower(escolher_pesos) != 'n');
		
		do{
		    if(tolower(escolher_pesos) == 's'){
		    	printf("Entre com o peso da primeira nota: ");
		    	scanf("%f", &peso1);
		    	fflush(stdin);	
				
				if(peso1 > 1){
					printf("O valor do peso precisa estar entre 0 e 1.\n");
				}
				
				peso2 = pesos - peso1; 		
				printf("Avaliacoes definidas com sucesso!\n");
				fprintf(file, "Avaliacao 1: %.2f\n", peso1);
        		fprintf(file, "Avaliacao 2: %.2f\n", peso2);
        		
			}else{
				// Caso não deseje definir pesos, usa o peso padrão 0.5 para cada avaliação
				printf("Avaliacoes definidas com sucesso!\n");
				fprintf(file, "Avaliacao 1: 0.5\n");
    			fprintf(file, "Avaliacao 2: 0.5\n");
			}	
		}while(peso1 > 1);
	}
}
