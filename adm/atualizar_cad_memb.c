#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "membroacad.h"

void atualizar_membros(){

    FILE *arquivo_memb_cad;

    memb_acad memb_acad;

    char nome_procurado[32];

    int encontrado = 0;

    printf("Nome do membro:");
    scanf("%[^\n]s", nome_procurado);

    arquivo_memb_cad = fopen("membros.bin", "rb+");

    if (arquivo_memb_cad == NULL) {
        printf("Erro ao abrir o 'membros.bin'.");
        exit(1);
    }

    while (fread(&memb_acad, sizeof(memb_acad), 1, arquivo_memb_cad)==1){
        if (strcmp(memb_acad.nome, nome_procurado) == 0){
            printf("memb_acad encontrado:\nNome: %s\nCPF: %ld\nPrivilégio: %d\nSenha: %s\n", memb_acad.nome, memb_acad.CPF, memb_acad.priv, memb_acad.senha);
            encontrado = 1;

            printf("Insira o número do CPF:");
            scanf("%ld",&memb_acad.CPF);

            // printf("Atualizar a senha:");
            // scanf("%s",&memb_acad.senha);

            fseek(arquivo_memb_cad, -sizeof(memb_acad), SEEK_CUR);

            fwrite(&memb_acad, sizeof(memb_acad), 1, arquivo_memb_cad);
            break;
        }
    }

    if(!encontrado){
        printf("Item com o nome '%s' não encontrado.\n", nome_procurado);
    }

    fclose(arquivo_memb_cad);


}

int main(){

    atualizar_membros();
    


}