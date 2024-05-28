#include <stdio.h>
#include <string.h> // manipulação de string
#include <stdlib.h> // limpar terminal e pausa no sistema

int main(){
	int opcao;
	char confirmacao;
	int sair;
	sair = 0;
	
	printf("**************************************");
	printf("\nCase precise de ajuda digite: /ajuda");
	printf("\n**************************************");
	printf("\n");
	
	printf("\nBem vindo {Professor}.\nO que deseja fazer hoje?");
	
	do{
		printf("\n1 - Definir avaliacoes\n2 - Atribuir notas\n3 - Realizar chamada\n4 - Fechamento da materia\n5 - Sair");
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
				printf("Avaliacoes\n");
				system("echo \"Pressione qualquer tecla para continuar\"");
				getchar();
				system("cls");
				break;
			case 2:
				printf("Notas\n");
				system("echo \"Pressione qualquer tecla para continuar\"");
				getchar();
				system("cls");
				break;
			case 3:
				printf("Chamada\n");
				system("echo \"Pressione qualquer tecla para continuar\"");
				getchar();
				system("cls");
				break;
			case 4:
				printf("Fechamento\n");
				system("echo \"Pressione qualquer tecla para continuar\"");
				getchar();
				system("cls");
				break;
			case 5:
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
