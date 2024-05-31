#include <stdio.h>
#include <string.h> // manipulação de string
#include <stdlib.h> // para usar a função system

void exibir_ajuda() {
    printf("\n**************************************\n");
    printf("Ajuda do Programa:\n");
    printf("1 - Definir avaliacoes: Permite definir os criterios de avaliacao.\n");
    printf("2 - Atribuir notas: Permite atribuir notas aos alunos.\n");
    printf("3 - Realizar chamada: Permite fazer a chamada dos alunos.\n");
    printf("4 - Fechamento da materia: Permite realizar o fechamento da materia.\n");
    printf("5 - Sair: Encerra o programa.\n");
    printf("A qualquer momento, digite '/ajuda' para exibir esta mensagem.\n");
    printf("**************************************\n");
    getchar(); // Pausa para o usuário ler a mensagem
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Consome todos os caracteres restantes no buffer de entrada
}

void pausar() {
    printf("Pressione Enter para continuar...");
    getchar();
}

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    int opcao;
    int sair = 0;
    char confirmacao;
    char entrada[10];
    
    printf("**************************************");
    printf("\nCaso precise de ajuda digite: /ajuda");
    printf("\n**************************************\n");
    
    printf("\nBem vindo {Professor}.\nO que deseja fazer hoje?\n");
    
    do {
        printf("\n1 - Definir avaliacoes\n2 - Atribuir notas\n3 - Realizar chamada\n4 - Fechamento da materia\n5 - Sair");
        printf("\nEntre com a opcao desejada ou digite /ajuda: ");
        
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = 0; // Remove o caractere de nova linha

        if (strcmp(entrada, "/ajuda") == 0) {
            exibir_ajuda();
            continue;
        }

        opcao = atoi(entrada); // Converte a string para inteiro

        switch (opcao) {
            default:
                printf("Opcao invalida, tente novamente!\n");
                pausar();
                limpar_tela();
                break;
            case 1:
                printf("Avaliacoes\n");
                pausar();
                limpar_tela();
                break;
            case 2:
                printf("Notas\n");
                pausar();
                limpar_tela();
                break;
            case 3:
                printf("Chamada\n");
                pausar();
                limpar_tela();
                break;
            case 4:
                printf("Fechamento\n");
                pausar();
                limpar_tela();
                break;
            case 5:
                printf("Deseja realmente sair? (S/N): ");
                scanf(" %c", &confirmacao);
                limpar_buffer();
                if (confirmacao == 'S' || confirmacao == 's') {
                    printf("Saindo...\n");
                    sair = 1;
                } else {
                    limpar_tela();
                }
                break;
        }
    } while (sair == 0);

    return 0;
}

