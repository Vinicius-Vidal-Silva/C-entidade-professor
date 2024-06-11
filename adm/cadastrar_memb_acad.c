#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "membroacad.h"

/*
Lista gerada no gpt para testes.
Nem todos os membros foram cadastrados e 
alguns já tiveram seus dados alterados.

{"Ana Clara Silva", 12345678901, "senha123", 3},
{"Bruno Santos", 23456789012, "senha234", 2},
{"Carla Oliveira", 34567890123, "senha345", 1},
{"Daniel Souza", 45678901234, "senha456", 3},
{"Eduarda Lima", 56789012345, "senha567", 2},
{"Felipe Almeida", 67890123456, "senha678", 1},
{"Gabriela Rocha", 78901234567, "senha789", 3},
{"Henrique Costa", 89012345678, "senha890", 2},
{"Isabela Pereira", 90123456789, "senha901", 1},
{"João Pedro Araújo", 12345678902, "senha012", 3}
*/


memb_acad memb_acad_cadastro(){
    
    memb_acad novo_membro;

    printf("Nome:\n");
    scanf(" %[^\n]s", &novo_membro.nome);
    printf("CPF:\n");
    scanf("%s", &novo_membro.cpf);
    printf("senha provisória:\n");
    scanf("%s",&novo_membro.senha);
    printf("Privilégio:\n");
    scanf("%d", &novo_membro.priv);

    return novo_membro;

}

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void extende_mem(memb_acad **memb_acad_vet, int *cont_cadastro){

    *cont_cadastro += 1;
    memb_acad *temp = realloc(*memb_acad_vet, (*cont_cadastro) * sizeof(memb_acad));

    if (temp == NULL) {
        printf("Erro ao alocar memória\n");
        return;
    }

    *memb_acad_vet = temp;
}


void* cadastrar_membro_acad() {

    
    FILE *membros_acad_lst;

    int cont_cadastro = 0;

    char novo_cadastro;

    
    
    printf("Deseja cadastrar um novo membro?\nDigite 's' para continuar ou 'n' para sair.\n");
    scanf("%c", &novo_cadastro);
    limparBufferEntrada();

    
    
    memb_acad *memb_acad_vet = NULL;

    
    
    while( novo_cadastro == 's' && novo_cadastro != 'n' ){
        
        extende_mem(&memb_acad_vet, &cont_cadastro);
        memb_acad_vet[cont_cadastro - 1] = memb_acad_cadastro(); 
        printf("Deseja cadastrar outro membro?\nDigite 's' para continuar ou 'n' para sair.\n");
        limparBufferEntrada();
        scanf("%c", &novo_cadastro);
        limparBufferEntrada();

        while(novo_cadastro != 's' && novo_cadastro != 'n'){
            printf("Entrada inválida. Digite 's' para continuar ou 'n' para sair.\n");
            limparBufferEntrada();
            scanf("%c", &novo_cadastro);
            limparBufferEntrada();
        }

    }


    membros_acad_lst = fopen("membros.bin", "ab");
    
    
    if(membros_acad_lst == NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }


    fwrite(memb_acad_vet, sizeof(memb_acad), cont_cadastro, membros_acad_lst);
    printf("%d", cont_cadastro);


    fclose(membros_acad_lst);
    free(memb_acad_vet);


    return 0;

}



int main(){

    cadastrar_membro_acad();

}