#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "membroacad.h"

void ler_membros(){
    
    int num_membros;
    
    memb_acad *membros_cad_vet;

    FILE *arquivo_membros_cad;

    arquivo_membros_cad = fopen("membros.bin", "rb");

    if(arquivo_membros_cad == NULL){

        printf("Erro ao abrir o arquivo\n");
        return;
    
    }

    fseek(arquivo_membros_cad,0,SEEK_END);
    int tamanho_arq = ftell(arquivo_membros_cad);
    fseek(arquivo_membros_cad,0,SEEK_SET);

    num_membros = tamanho_arq / sizeof(memb_acad);

    membros_cad_vet = malloc(sizeof(memb_acad) * num_membros);

    if (membros_cad_vet == NULL){

        printf("Erro ao alocar memória\n");
        fclose(arquivo_membros_cad);
        return;
    
    }

    fread(membros_cad_vet, sizeof(memb_acad), num_membros, arquivo_membros_cad);

    for(int i = 0; i < num_membros; i++){
        printf("nome: %s\nCPF: %ld\nSenha: %s\nPriv: %d\n\n", membros_cad_vet[i].nome, membros_cad_vet[i].CPF, membros_cad_vet[i].senha, membros_cad_vet[i].priv);
    }
}

int main(){

    ler_membros();

}
