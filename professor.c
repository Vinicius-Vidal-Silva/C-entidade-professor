#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main(){
	int opcao;
	printf("**************************************");
	printf("\nCase precise de ajuda digite: /ajuda");
	printf("\n**************************************");
	printf("\n");
	
	printf("\nBem vindo {Professor}.\nO que deseja fazer hoje?");
	printf("\n1 - Definir avaliacoes\n2 - Atribuir notas\n3 - Realizar chamada\n4 - Fechamento da materia\n5 - Sair");
	printf("\nEntre com a opcao desejada:");
	scanf("%i", &opcao);
	
	switch (opcao){
		default:
			printf("Opcao invalida.\nTente novamente.");
			break;
		case 1:
			printf("Avaliacoes");
			break;
		case 2:
			printf("Notas");
			break;
		case 3:
			printf("Chamada");
			break;
		case 4:
			printf("Fechamento");
			break;
		case 5:
			char sair;
			printf("Deseja realmente sair?(S/N)");
			scanf("%c", &sair);
			
	}
	
	getchar();
}
