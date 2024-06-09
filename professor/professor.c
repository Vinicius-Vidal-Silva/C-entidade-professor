#include <stdio.h>
#include <string.h> // manipula??o de string
#include <stdlib.h> // limpar terminal e pausa no sistema

int main(){
	int opcao;
	char confirmacao;
	int sair;
	sair = 0;
	
	printf("**************************************");
	printf("\nBem vindo ao SIGA");
	printf("\n**************************************");
	printf("\n");
	
	printf("\nBem vindo {Professor}.\nO que deseja fazer hoje?");
	
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
				printf("Notas\n");
				system("echo \"Pressione qualquer tecla para continuar\"");
				getchar();
				system("cls");
				break;
			case 2:
				printf("Chamada\n");
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
