#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "professor.h"
#include "materia.h"
#include "membroacad.h"
#include "admin.h"

// Protótipos das funções

// void alterar_arquivo();
// void atualizar_aluno();
// int atualizar_professor();
// aluno cad_aluno();
// void* cadastrar_aluno();
// materia cad_materia();
// void* cadastrar_materia();
// professor cad_professor();
// void* cadastrar_professor();
// void extende_mem_aluno(aluno **vet_cad, int *cont_cad);
// void extende_mem_materia(materia **vet_cad, int *cont_cad);
// void extende_mem_professor(professor **vet_cad, int *cont_cad);
// void ler_alunos();
// void ler_materia();
// void ler_professor();
// void limparBufferEntrada();
// void alunos_matriculados_lst();

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF){};
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


int tamanho_arq(FILE *data_set) {
    fseek(data_set, 0, SEEK_END);
    int tamanho_arq = ftell(data_set);
    fseek(data_set, 0, SEEK_SET);
    return tamanho_arq;
}

void carrega_lista_geral(char* nome_inp, long int cpf_inp, int priv_inp){ 

    FILE *membro_acad_arq;

    membro_acad *membro;

    membro_acad_arq = fopen("lista_membros.bin","ab");

    if (membro_acad_arq == NULL) {
        printf("Erro ao abrir o arquivo lista_membros.bin\n");
        return;
    }

    membro = (membro_acad*) malloc(sizeof(membro_acad));
    
    if (membro == NULL) {
        printf("Erro ao alocar memória\n");
        fclose(membro_acad_arq);
        return;
    }

    membro->cpf = cpf_inp;

    strncpy(membro->nome, nome_inp, sizeof(membro->nome) - 1);
    membro->nome[sizeof(membro->nome) - 1] = '\0';

    membro->priv = priv_inp;

    fwrite(membro, sizeof(membro_acad), 1, membro_acad_arq);

    free(membro);
    fclose(membro_acad_arq);
    
}

void extende_mem_admin(admin **vet_cad, int *cont_cad) {
    *cont_cad += 1;
    admin *temp = realloc(*vet_cad, (*cont_cad) * sizeof(admin));
    if (temp == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    *vet_cad = temp;
}

void extende_mem_aluno(aluno **vet_cad, int *cont_cad) {
    *cont_cad += 1;
    aluno *temp = realloc(*vet_cad, (*cont_cad) * sizeof(aluno));
    if (temp == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    *vet_cad = temp;
}

void extende_mem_materia(materia **vet_cad, int *cont_cad) {
    *cont_cad += 1;
    materia *temp = realloc(*vet_cad, (*cont_cad) * sizeof(materia));
    if (temp == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    *vet_cad = temp;
}

void extende_mem_professor(professor **vet_cad, int *cont_cad) {
    *cont_cad += 1;
    professor *temp = realloc(*vet_cad, (*cont_cad) * sizeof(professor));
    if (temp == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
    *vet_cad = temp;
}



void alterar_arquivo(char* arquivo, aluno *vetor_alunos, int num_alunos) {
    FILE *aluno_data;
    
    aluno_data = fopen(arquivo, "wb+");
    if (aluno_data == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    fwrite(vetor_alunos, sizeof(aluno), num_alunos, aluno_data);
    fclose(aluno_data);
}

void atribuicao_mat(){

    //int cont = 0;
    int index_prof;
    int index_mat;

    FILE *prof_data;
    FILE *mat_data;

    professor *professor_vet;
    materia *materia_vet;

    int prof_data_tamanho;
    int mat_data_tamanho;

    professor prof;
    int num_mat = sizeof(prof.materias) / sizeof(prof.materias[0]);

    
    prof_data = fopen("professores.bin", "rb+");
    if (prof_data == NULL) {
        perror("Erro ao abrir professores.bin");
        return;
    }

    mat_data = fopen("materias.bin", "rb+");
    if (mat_data == NULL) {
        perror("Erro ao abrir materias.bin");
        fclose(prof_data);
        return;
    }

    
    prof_data_tamanho = tamanho_arq(prof_data);
    mat_data_tamanho = tamanho_arq(mat_data);

    int num_materias = mat_data_tamanho / sizeof(materia);
    int num_professores = prof_data_tamanho / sizeof(professor);

    
    professor_vet = malloc(prof_data_tamanho);
    materia_vet = malloc(mat_data_tamanho);

    
    fread(professor_vet, prof_data_tamanho, 1, prof_data);
    fread(materia_vet, mat_data_tamanho, 1, mat_data);

    
    for (int i = 0; i < num_materias; i++) {
        if (i == 0) {
            printf("       Matérias: %d - %s\n", (i + 1), materia_vet[i].nome);
        } else {
            printf("                 %d - %s\n", (i + 1), materia_vet[i].nome);
        }
    }

    printf("Selecionar matéria da lista: ");
    scanf("%d", &index_mat);

    index_mat = index_mat - 1;

    clear_screen();

    
    printf("Matéria selecionada: %s\n\n", materia_vet[index_mat].nome);
    for (int i = 0; i < num_professores; i++) {
        if (i == 0) {
            printf("        Professores: %d - %s\n", (i + 1), professor_vet[i].nome);
        } else {
            printf("                     %d - %s\n", (i + 1), professor_vet[i].nome);
        }
    }

    
    printf("\nDigite o número do professor que irá ministrar a aula: ");
    scanf("%d", &index_prof);

    index_prof = index_prof - 1;

    clear_screen();

    printf("\n Matéria  : %s\n", materia_vet[index_mat].nome);
    printf(" Professor: %s\n", professor_vet[index_prof].nome);
    printf(" \npressione ENTER para confirmar a atribuição.");
    limparBufferEntrada();  
    getchar();

    
    strncpy(materia_vet[index_mat].professor, professor_vet[index_prof].nome, sizeof(materia_vet[index_mat].professor) - 1);
    materia_vet[index_mat].professor[sizeof(materia_vet[index_mat].professor) - 1] = '\0';

    
    
    fseek(mat_data, 0, SEEK_SET);
    fseek(mat_data, index_mat * sizeof(materia), SEEK_SET);

    
    fwrite(&materia_vet[index_mat], sizeof(materia), 1, mat_data);

    
    int found = 0;
    for (int j = 0; j < num_mat; j++) {
        if (strcmp(professor_vet[index_prof].materias[j], "...") == 0) {
            
            strncpy(professor_vet[index_prof].materias[j], materia_vet[index_mat].nome, sizeof(professor_vet[index_prof].materias[j]) - 1);
            professor_vet[index_prof].materias[j][sizeof(professor_vet[index_prof].materias[j]) - 1] = '\0';

            strncpy(professor_vet[index_prof].listas_alunos[j], materia_vet[index_mat].sigla, sizeof(professor_vet[index_prof].listas_alunos[j]) - 1);
            strcat(professor_vet[index_prof].listas_alunos[j],".bin");
            professor_vet[index_prof].listas_alunos[j][sizeof(professor_vet[index_prof].listas_alunos[j]) - 1] = '\0';
            
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Não há espaço para adicionar mais matérias ao professor.\n");
    }

    
    fseek(prof_data, 0, SEEK_SET);
    fseek(prof_data, index_prof * sizeof(professor), SEEK_SET);

    
    fwrite(&professor_vet[index_prof], sizeof(professor), 1, prof_data);

    
    fclose(prof_data);
    fclose(mat_data);
    free(professor_vet);
    free(materia_vet);

    return;

}

void ler_materia() {
    
    int num_materias;

    materia *materias_cad;

    FILE *arquivo_materias_cad;

    arquivo_materias_cad = fopen("materias.bin", "rb");


    if(arquivo_materias_cad == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }


    fseek(arquivo_materias_cad,0,SEEK_END);
    int tamanho_arq = ftell(arquivo_materias_cad);
    fseek(arquivo_materias_cad,0,SEEK_SET);


    num_materias = tamanho_arq / sizeof(materia);

    materias_cad = malloc(sizeof(materia) * num_materias);

    fread(materias_cad, sizeof(materia), num_materias, arquivo_materias_cad);


    for(int i = 0; i < num_materias; i++){
        printf("\n");
        printf(" nome: %s\n Sigla: %s\n Professor: %s\n\n", materias_cad[i].nome, materias_cad[i].sigla, materias_cad[i].professor);
    }
}


void atualizar_aluno() {

    FILE *arquivo;
    aluno aluno01;
    aluno aluno;
    char termo_procurado[48];
    int encontrado = 0;

    long int cpf_min = 10000000;
    long int cpf;
    int reg_a;
    char tipo_termo;

    int aluno_tam = 140;


    printf("Digite nome, CPF ou Reg.A.(1 a 1000): ");
    fgets(termo_procurado, sizeof(termo_procurado), stdin);
    termo_procurado[strcspn(termo_procurado, "\n")] = 0;

    if(atol(termo_procurado) == 0 ){
        printf("nome: %s\n\n", termo_procurado);
        tipo_termo = 'N';
    }else{
        if(atol(termo_procurado) > cpf_min){
            cpf = atol(termo_procurado);
            printf("CPF: %ld\n\n", cpf);
            tipo_termo = 'C';
        }else{
            reg_a = atol(termo_procurado);
            printf("Reg. A.: %i\n\n",reg_a);
            tipo_termo = 'R';
        }
    }

    arquivo = fopen("alunos.bin", "rb+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    if(tipo_termo == 'N'){

        while (fread(&aluno01, sizeof(aluno), 1, arquivo) == 1) {
            
            if (strcmp(aluno01.nome, termo_procurado) == 0) {
                printf("Aluno encontrado:\n      Nome: %s\n      CPF: %ld\n", aluno01.nome, aluno01.cpf);
                printf(" Matérias: ");
                        for(int j = 0; j < 3; j++ ){
                            if(j == 0){
                                printf("%s",aluno01.materias[j]);
                            }else{
                                printf("\n           %s",aluno01.materias[j]);
                            }
                            
                        }
                printf("\n\n");
                
                encontrado = 1;
                
                ler_materia();
                
                printf(" Insira a sigla da matéria: ");
                
                fgets(aluno01.materias[0], sizeof(aluno01.materias[0]), stdin);
                aluno01.materias[0][strcspn(aluno01.materias[0], "\n")] = 0; // Remove newline character
                

                fseek(arquivo, -aluno_tam, SEEK_CUR);
                fwrite(&aluno01, aluno_tam, 1, arquivo);
                break;
            }
        }

    } else  {

            if(tipo_termo == 'C'){

                while (fread(&aluno01, sizeof(aluno), 1, arquivo) == 1) {
            
                    if (aluno01.cpf == cpf) {
                        printf("Aluno encontrado:\n      Nome: %s\n      CPF: %li\n      Rg. A.: %d" , aluno01.nome, aluno01.cpf,aluno01.reg_a);
                        printf(" Matérias: ");
                        for(int j = 0; j < 3; j++ ){
                            if(j == 0){
                                printf("%s",aluno01.materias[j]);
                            }else{
                                printf("\n           %s",aluno01.materias[j]);
                            }
                            
                        }
                        printf("\n\n");
                        
                        encontrado = 1;
                        
                        ler_materia();
                        
                        printf(" Insira a sigla da matéria: ");

                        fseek(arquivo, -aluno_tam, SEEK_CUR);
                        fwrite(&aluno01, sizeof(aluno), 1, arquivo);
                        break;
                    }

                }


            } else {

                while (fread(&aluno01, sizeof(aluno), 1, arquivo) == 1) {
            
                    if (aluno.reg_a == reg_a) {
                        printf("Aluno encontrado:\n      Nome: %s\n      CPF: %ld\n", aluno01.nome, aluno01.cpf);
                        printf(" Matérias: ");
                        for(int j = 0; j < 3; j++ ){
                            if(j == 0){
                                printf("%s",aluno.materias[j]);
                            }else{
                                printf("\n           %s",aluno.materias[j]);
                            }
                            
                        }
                        printf("\n\n");
                        
                        encontrado = 1;
                        
                        ler_materia();
                        
                        printf(" Insira a sigla da matéria: ");
                        fgets(aluno.materias[0], sizeof(aluno.materias[0]), stdin);
                        aluno.materias[0][strcspn(aluno.materias[0], "\n")] = 0; // Remove newline character

                        fseek(arquivo, -aluno_tam, SEEK_CUR);
                        fwrite(&aluno, aluno_tam, 1, arquivo);
                        break;
                    }

                }
            }

    }

    

    if (!encontrado) {
        printf("Item com o nome '%s' não encontrado.\n", termo_procurado);
    }

    fclose(arquivo);
    return;
}


int atualizar_professor() {
    FILE *arquivo;
    professor professor;
    char nome_procurado[48];
    int encontrado = 0;

    int prof_tam = 200;

    printf("Nome do professor: ");
    fgets(nome_procurado, sizeof(nome_procurado), stdin);
    nome_procurado[strcspn(nome_procurado, "\n")] = 0; // Remove newline character

    arquivo = fopen("professores.bin", "rb+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fread(&professor, sizeof(professor), 1, arquivo) == 1) {
        if (strcmp(professor.nome, nome_procurado) == 0) {
            printf("Professor encontrado:\nNome: %s\nCPF: %ld\n", professor.nome, professor.cpf);
            encontrado = 1;
            printf("Insira o nome da matéria: ");
            fgets(professor.materias[0], sizeof(professor.materias[0]), stdin);
            professor.materias[0][strcspn(professor.materias[0], "\n")] = 0; // Remove newline character

            fseek(arquivo, -prof_tam, SEEK_CUR);
            fwrite(&professor, sizeof(professor), 1, arquivo);
            break;
        }
    }

    if (!encontrado) {
        printf("Item com o nome '%s' não encontrado.\n", nome_procurado);
    }

    fclose(arquivo);
    return 0;
}

admin cad_admin() {
    admin _admin_;
    init_admin(&_admin_);
    printf("Nome: ");
    fgets(_admin_.nome, sizeof(_admin_.nome), stdin);
    _admin_.nome[strcspn(_admin_.nome, "\n")] = 0; // Remove newline character
    printf("CPF: ");
    scanf("%ld", &_admin_.cpf);
    limparBufferEntrada();
    return _admin_;
}

aluno cad_aluno() {
    aluno _aluno_;
    init_aluno(&_aluno_);
    printf("Nome: ");
    fgets(_aluno_.nome, sizeof(_aluno_.nome), stdin);
    _aluno_.nome[strcspn(_aluno_.nome, "\n")] = 0; // Remove newline character
    printf("CPF: ");
    scanf("%ld", &_aluno_.cpf);
    limparBufferEntrada();
    return _aluno_;
}

void* cadastrar_admin() {
   
    FILE *admins_cad;

    int cont_cad = 0;

    char novo_cad;

    int tamanho_admins_cad;

    //int reg_a_ult_cad;

    int arquivo_iniciado = 0;

    
    
    printf("Deseja cadastrar um admin?\nDigite 's' para continuar ou 'n' para sair.\n");
    scanf("%c", &novo_cad);
    limparBufferEntrada();


    
    
    admin *vet_admin = NULL;

    
    
    while(novo_cad != 'n'){
        
        extende_mem_admin(&vet_admin, &cont_cad);
        vet_admin[cont_cad - 1] = cad_admin(); 
        vet_admin[cont_cad - 1].reg_a += cont_cad - 1;
        carrega_lista_geral(vet_admin[cont_cad - 1].nome,vet_admin[cont_cad - 1].cpf, vet_admin[cont_cad - 1].priv);
        printf("Deseja cadastrar outro admin?\nDigite 's' para continuar ou 'n' para sair.\n");
        scanf("%c", &novo_cad);
        limparBufferEntrada();

        while(novo_cad != 's' && novo_cad != 'n'){
            printf("Entrada inválida.\nDigite 's' para continuar ou 'n' para sair.\n");
            scanf("%c", &novo_cad);
            limparBufferEntrada();
        }

    }



    admins_cad = fopen("admins.bin", "rb");
    
    if(admins_cad == NULL){
        // printf("Erro ao abrir arquivo");
        // exit(1);
        admins_cad = fopen("admins.bin", "wb");
    }else{
        admins_cad = fopen("admins.bin", "ab");
        tamanho_admins_cad = tamanho_arq(admins_cad)/sizeof(admin);
        arquivo_iniciado = 1;
        //atribuir valor ao reg_a obtendo o valor do último cadastrado.
    }

    if(arquivo_iniciado == 1){
        for(int i = 0; i < cont_cad; i++ ){
            vet_admin[i].reg_a += tamanho_admins_cad;
        }
    }

    
    fwrite(vet_admin, sizeof(admin), cont_cad, admins_cad);
    printf("%d", cont_cad);


    fclose(admins_cad);
    free(vet_admin);


    return 0;

}

void* cadastrar_aluno() {
   
    FILE *alunos_cad;

    int cont_cad = 0;

    char novo_cad;

    int tamanho_alunos_cad;

    //int reg_a_ult_cad;

    int arquivo_iniciado = 0;

    
    
    printf("Deseja cadastrar um aluno?\nDigite 's' para continuar ou 'n' para sair.\n");
    scanf("%c", &novo_cad);
    limparBufferEntrada();


    
    
    aluno *vet_aluno = NULL;

    
    
    while(novo_cad != 'n'&& novo_cad == 's'){
        
        extende_mem_aluno(&vet_aluno, &cont_cad);
        vet_aluno[cont_cad - 1] = cad_aluno(); 
        vet_aluno[cont_cad - 1].reg_a += cont_cad - 1;
        carrega_lista_geral(vet_aluno[cont_cad - 1].nome,vet_aluno[cont_cad - 1].cpf, vet_aluno[cont_cad - 1].priv);
        printf("Deseja cadastrar outro aluno?\nDigite 's' para continuar ou 'n' para sair.\n");
        scanf("%c", &novo_cad);
        limparBufferEntrada();

        while(novo_cad != 's' && novo_cad != 'n'){
            printf("Entrada inválida.\nDigite 's' para continuar ou 'n' para sair.\n");
            scanf("%c", &novo_cad);
            limparBufferEntrada();
        }

    }



    alunos_cad = fopen("alunos.bin", "rb");
    
    if(alunos_cad == NULL){
        // printf("Erro ao abrir arquivo");
        // exit(1);
        alunos_cad = fopen("alunos.bin", "wb");
    }else{
        alunos_cad = fopen("alunos.bin", "ab");
        tamanho_alunos_cad = tamanho_arq(alunos_cad)/sizeof(aluno);
        arquivo_iniciado = 1;
        //atribuir valor ao reg_a obtendo o valor do último cadastrado.
    }

    if(arquivo_iniciado == 1){
        for(int i = 0; i < cont_cad; i++ ){
            vet_aluno[i].reg_a += tamanho_alunos_cad;
        }
    }

    
    fwrite(vet_aluno, sizeof(aluno), cont_cad, alunos_cad);
    printf("%d", cont_cad);


    fclose(alunos_cad);
    free(vet_aluno);


    return 0;

}

materia cad_materia() {
    materia _materia_;
    init_materia(&_materia_);
    printf("Nome: ");
    fgets(_materia_.nome, sizeof(_materia_.nome), stdin);
    _materia_.nome[strcspn(_materia_.nome, "\n")] = 0; // Remove newline character
    printf("Sigla: ");
    fgets(_materia_.sigla, sizeof(_materia_.sigla), stdin);
    _materia_.sigla[strcspn(_materia_.sigla, "\n")] = 0; // Remove newline character
    return _materia_;
}

void* cadastrar_materia() {
    FILE *materias_cad;
    int cont_cad = 0;
    char novo_cad;

    materia *vet_materia = NULL;

    do {
        printf("Deseja cadastrar uma matéria? Digite 's' para continuar ou 'n' para sair: ");
        scanf(" %c", &novo_cad);
        limparBufferEntrada();

        if (novo_cad == 's') {
            extende_mem_materia(&vet_materia, &cont_cad);
            vet_materia[cont_cad - 1] = cad_materia();
        }
    } while (novo_cad != 'n');

    materias_cad = fopen("materias.bin", "wb");
    if (materias_cad == NULL) {
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }

    fwrite(vet_materia, sizeof(materia), cont_cad, materias_cad);
    printf("Total de matérias cadastradas: %d\n", cont_cad);

    fclose(materias_cad);
    free(vet_materia);
    return 0;
}

professor cad_professor() {
    professor _professor_;
    init_professor(&_professor_);
    printf("Nome: ");
    fgets(_professor_.nome, sizeof(_professor_.nome), stdin);
    _professor_.nome[strcspn(_professor_.nome, "\n")] = 0; // Remove newline character
    printf("CPF: ");
    scanf("%ld", &_professor_.cpf);
    limparBufferEntrada();
    return _professor_;
}

void* cadastrar_professor() {
    
    FILE *professores_cad;

    int cont_cad = 0;

    char novo_cad;

    int tamanho_professores_cad;

    //int reg_a_ult_cad;

    int arquivo_iniciado = 0;

    
    
    printf("Deseja cadastrar um professor?\nDigite 's' para continuar ou 'n' para sair.\n");
    scanf("%c", &novo_cad);
    limparBufferEntrada();

    
    
    professor *vet_professor = NULL;

    
    
    while(novo_cad != 'n'){
        
        extende_mem_professor(&vet_professor, &cont_cad);
        vet_professor[cont_cad - 1] = cad_professor();
        vet_professor[cont_cad - 1].reg_a += cont_cad - 1;
        carrega_lista_geral(vet_professor[cont_cad - 1].nome,vet_professor[cont_cad - 1].cpf, vet_professor[cont_cad - 1].priv); 
        printf("Deseja cadastrar outro professor?\nDigite 's' para continuar ou 'n' para sair.\n");  
        scanf("%c", &novo_cad);
        limparBufferEntrada();

        while(novo_cad != 's' && novo_cad != 'n'){
            printf("Entrada inválida.\nDigite 'n' o 's' para continuar.");
            scanf("%c", &novo_cad);
            limparBufferEntrada();
        }

    }


    //professores_cad = fopen("professores.bin", "wb");

    professores_cad = fopen("professores.bin", "rb");
    
    if(professores_cad == NULL){
        // printf("Erro ao abrir arquivo");
        // exit(1);
        professores_cad = fopen("professores.bin", "wb");
    }else{
        professores_cad = fopen("professores.bin", "ab");
        tamanho_professores_cad = tamanho_arq(professores_cad)/sizeof(professor);
        arquivo_iniciado = 1;
        //atribuir valor ao reg_a obtendo o valor do último cadastrado.
    }

    if(arquivo_iniciado == 1){
        for(int i = 0; i < cont_cad; i++ ){
            vet_professor[i].reg_a += tamanho_professores_cad;
        }
    }
    
    
    if(professores_cad == NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    
    fwrite(vet_professor, sizeof(professor), cont_cad, professores_cad);
    printf("%d", cont_cad);


    fclose(professores_cad);
    free(vet_professor);


    return 0;


}

aluno* carrega_arquivo_vet(char* arquivo){

    //int index_aluno;
    
    FILE *aluno_data;
   

    aluno *alunos_vet;
    

    int aluno_data_tamanho;
    
    
    aluno_data = fopen(arquivo, "rb+");
    if (aluno_data == NULL) {
        printf("Erro ao abrir ao abrir o arquivo");
        exit(1);
    }


    
    aluno_data_tamanho = tamanho_arq(aluno_data);
    
    //int num_alunos = aluno_data_tamanho / sizeof(aluno);

    
    alunos_vet = malloc(aluno_data_tamanho);
   

    
    fread(alunos_vet, aluno_data_tamanho, 1, aluno_data);

    return alunos_vet;
   

    // for(int i = 0; i < num_alunos; i++){
    //     printf("%s\n",alunos_vet[i].nome);
    // }

}




void confirmar_mat_alunos(){

    FILE *arquivo_materias_cad;
    FILE *arquivo_alunos_cad;
    //FILE *arquivo_lista_matricula;

    
    materia *materias_cad;
    materia materia;
    aluno *alunos_cad;
    //aluno *alunos_mat;
    aluno aluno;

    int num_materias;
    int num_alunos;
    //int num_alunos_mat;

    arquivo_materias_cad = fopen("materias.bin", "rb");
    arquivo_alunos_cad = fopen("alunos.bin", "rb");



    fseek(arquivo_materias_cad,0,SEEK_END);
    int tamanho_arq_materias = ftell(arquivo_materias_cad);
    fseek(arquivo_materias_cad,0,SEEK_SET);

    fseek(arquivo_alunos_cad,0,SEEK_END);
    int tamanho_arq_alunos = ftell(arquivo_alunos_cad);
    fseek(arquivo_alunos_cad,0,SEEK_SET);


    num_materias = tamanho_arq_materias / sizeof(materia);
    num_alunos = tamanho_arq_alunos / sizeof(aluno);

    materias_cad = malloc(tamanho_arq_materias);
    alunos_cad = malloc(tamanho_arq_alunos);
    

    fread(materias_cad, tamanho_arq_materias, 1, arquivo_materias_cad);
    fread(alunos_cad, sizeof(aluno), num_alunos, arquivo_alunos_cad);


    
    //int qtd_alunos;
    int cont_alunos = 0;
    for(int k = 0; k < num_materias; k++){
        printf("Alunos matriculados em %s:\n",materias_cad[k].nome);
        alunos_cad = carrega_arquivo_vet("alunos.bin"); 
        for(int i = 0; i < num_alunos; i++){
            for(int j = 0; j < (int)sizeof(aluno.materias)/(int)sizeof(alunos_cad[0].materias[0]); j++){
                if (strcmp(alunos_cad[i].materias[j],materias_cad[k].sigla)==0){
                        alunos_cad[cont_alunos] = alunos_cad[i];
                        printf("     - %s\n",alunos_cad[cont_alunos].nome);
                        cont_alunos++;
                    }
                }
            
        }
        printf("\n");

        
        alterar_arquivo(strcat(materias_cad[k].sigla,".bin"),alunos_cad,cont_alunos);
        cont_alunos = 0;
    } 

    for(int i = 0; i < num_materias; i++){
        printf("%s\n",materias_cad[i].sigla);
    }

}

void ler_memb_acad(const char* nome_arquivo) {
    
    FILE *arquivo;
    membro_acad membro;
    
    // Abre o arquivo para leitura binária
    arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", nome_arquivo);
        return;
    }

    // Lê e imprime cada membro até o final do arquivo
    while (fread(&membro, sizeof(membro_acad), 1, arquivo) == 1) {
        printf("CPF: %ld\n", membro.cpf);
        printf("Nome: %s\n", membro.nome);
        printf("Privilegio: %d\n\n", membro.priv);
    }

    // Fecha o arquivo
    fclose(arquivo);
}

int contar_alunos(FILE *aluno_data) {
    int tamanho = tamanho_arq(aluno_data);
    return tamanho / sizeof(aluno);
}


void ler_alunos() {
    
    int num_alunos;

    aluno *alunos_cad;

    FILE *arquivo_alunos_cad;

    arquivo_alunos_cad = fopen("alunos.bin", "rb");

    if(arquivo_alunos_cad == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }

    fseek(arquivo_alunos_cad,0,SEEK_END);
    int tamanho_arq = ftell(arquivo_alunos_cad);
    fseek(arquivo_alunos_cad,0,SEEK_SET);

    num_alunos = tamanho_arq / sizeof(aluno);

    alunos_cad = malloc(sizeof(aluno) * num_alunos);

    fread(alunos_cad, sizeof(aluno), num_alunos, arquivo_alunos_cad);

    for(int i = 0; i < num_alunos; i++){
        printf("\n");
        printf(" nome: %s\n Reg.Acad.: %d\n CPF:%ld\n Privilegio: %d\n", alunos_cad[i].nome,alunos_cad[i].reg_a, alunos_cad[i].cpf,alunos_cad[i].priv);
        printf(" Materias: ");
        for(int j = 0; j < 3; j++ ){
            if(j == 0){
                printf("%s",alunos_cad[i].materias[j]);
            }else{
                printf("\n           %s",alunos_cad[i].materias[j]);
            }
            
        }
        printf("\n\n"); 
    }
}

void ler_alunos_mat() {

    int mat_escolhida;
    
    int num_alunos;
    int num_materias;

    aluno *alunos_cad;
    materia *materias_cad;

    FILE *arquivo_alunos_cad;
    FILE *arquivo_materias_cad;

    arquivo_materias_cad = fopen("materias.bin", "rb");

    if(arquivo_materias_cad == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }

    
    
    int tamanho_arq_materias = tamanho_arq(arquivo_materias_cad);

    num_materias = tamanho_arq_materias / sizeof(materia);

    materias_cad = malloc(tamanho_arq_materias);

    fread(materias_cad, tamanho_arq_materias, 1, arquivo_materias_cad);

    printf("Lista de Alunos das Materias: ");

    for(int i = 0; i < num_materias; i++){
        if(i == 0){
            printf("%d - %s\n",i + 1, materias_cad[i].nome);
        }else{
                 //"Lista de Alunos das Matérias: "
            printf("                              %d - %s\n",i + 1, materias_cad[i].nome);
        }
        
    }

    
    
    printf("\nEscolha a lista de alunos que deseja consultar: ");
    scanf("%d", &mat_escolhida);

    arquivo_alunos_cad = fopen(strcat(materias_cad[mat_escolhida - 1].sigla,".bin"), "rb");

    if(arquivo_alunos_cad == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }


    
    int tamanho_arq_alunos = tamanho_arq(arquivo_alunos_cad);
    
    num_alunos = tamanho_arq_alunos / sizeof(aluno);
    
    alunos_cad = malloc(tamanho_arq_alunos);
    
    fread(alunos_cad, tamanho_arq_alunos, 1, arquivo_alunos_cad);
    

    
    for(int i = 0; i < num_alunos; i++){
        
        printf("\n");
        printf(" nome: %s\n Reg.Acad.: %d\n", alunos_cad[i].nome,alunos_cad[i].reg_a);
   
    }
}


void ler_professor() {
    
    int num_professores;

    professor *professores_cad;

    FILE *arquivo_professores_cad;

    arquivo_professores_cad = fopen("professores.bin", "rb");

    if(arquivo_professores_cad == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }

    fseek(arquivo_professores_cad,0,SEEK_END);
    int tamanho_arq = ftell(arquivo_professores_cad);
    fseek(arquivo_professores_cad,0,SEEK_SET);

    num_professores = tamanho_arq / sizeof(professor);

    professores_cad = malloc(sizeof(professor) * num_professores);

    fread(professores_cad, sizeof(professor), num_professores, arquivo_professores_cad);

    for(int i = 0; i < num_professores; i++){
        printf(" nome: %s\n Reg. Acad.: %d\n CPF:%ld\n Privilegio: %d\n", professores_cad[i].nome,professores_cad[i].reg_a, professores_cad[i].cpf,professores_cad[i].priv);
        printf(" Materias: ");
        for(int j = 0; j < 3; j++ ){
            if(j == 0){
                printf("%s (%s)",professores_cad[i].materias[j],professores_cad[i].listas_alunos[j]);
            }else{
                printf("\n           %s (%s)",professores_cad[i].materias[j],professores_cad[i].listas_alunos[j]);
            }
            
        }
        printf("\n\n");
    }
}





int main() {
    int opcao;

    do {
        
        printf("\nSelecione uma opcao:\n");
        printf("1.  Atribuir Materia\n");
        printf("2.  Atualizar Aluno\n");
        printf("3.  Atualizar Professor\n");
        printf("4.  Cadastrar Adminstrador\n");
        printf("5.  Cadastrar Aluno\n");
        printf("6.  Cadastrar Materia\n");
        printf("7.  Cadastrar Professor\n");
        printf("8.  Confirmar Matriculas de Alunos\n");
        printf("9.  Ler Alunos\n");
        printf("10. Ler Materia\n");
        printf("11. Ler Membros Academicos\n");
        printf("12. Ler Professor\n");
        printf("13. Listas de Alunos Matriculados\n");
        printf("14. Sair\n");
        printf("\n    Digite a opcao desejada: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                atribuicao_mat();
                break;
            case 2:
                atualizar_aluno();
                break;
            case 3:
                atualizar_professor();
                break;
            case 4:
                cadastrar_admin();
                break;
            case 5:
                cadastrar_aluno();
                break;
            case 6:
                cadastrar_materia();
                break;
            case 7:
                cadastrar_professor();
                break;
            case 8:
                confirmar_mat_alunos();
                break;
            case 9:
                ler_alunos();
                break;
            case 10:
                ler_materia();
                break;
            case 11:
                ler_memb_acad("lista_membros.bin");
                break;
            case 12:
                ler_professor();
                break;
            case 13:
                ler_alunos_mat();
                break;
            case 14:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 14);

    return 0;
}
