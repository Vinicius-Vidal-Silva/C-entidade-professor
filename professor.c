#include <stdio.h>
#include <string.h> // manipulação de string
#include <stdlib.h> // limpar terminal e pausa no sistema
int materia();

int presenca();

int atribuicaoNotas();

int preencherNotas();

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
                system("echo \"Pressione qualquer tecla para continuar\"");
                getchar();
                presenca();
                system("cls");
                break;
            case 2:
                printf("editar forma avaliativa\n");
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