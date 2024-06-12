#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Nota {
    char professor[50];
    char materia[50];
    int notaf;
    int cpf;                        //usar cpf como id


};


void regNota() {
    struct Nota notaarquivo;
    FILE *file;
    FILE *file2;
    char mat[50];
    char primeiraLinha[50];
    FILE *existe;




    printf("Entre materia: \n");
 getchar();
    fgets(notaarquivo.materia, sizeof(notaarquivo.materia), stdin);

    sprintf(mat, "%s.bin", notaarquivo.materia); //coloca no mat o nome da materia + .bin
    file2 = fopen(mat, "rb");                    //abre o arquivo


if (file2 != NULL) {//se existir, abre o arquivo

file = fopen(mat, "ab");
printf("Entre com o cpf do aluno: \n");//se já existir, apenas adiciona o cpf e a nota
scanf("%d", &notaarquivo.cpf);


printf("Entre nota: \n");
scanf("%d", &notaarquivo.notaf);

fprintf(file, "%d - %d\n", notaarquivo.cpf, notaarquivo.notaf);

    fclose(file);
    printf("Nota registrada com ID %d!\n", notaarquivo.cpf);



    } else {//se não existir



    file = fopen(mat, "ab");
 

    printf("Entre com o nome do professor: \n");  //se nao existir, escreve no arquivo o nome da materia, o professor, e o cpf + nota.

    fgets(notaarquivo.professor, sizeof(notaarquivo.professor), stdin);

    printf("Entre com o cpf do aluno: \n");
    scanf("%d", &notaarquivo.cpf);


    printf("Entre nota: \n");
    scanf("%d", &notaarquivo.notaf);


printf("%s", notaarquivo.professor);

    fprintf(file, "Materia: %s\nProfessor: %s\nCpf do aluno - Nota\n%d - %d\n", notaarquivo.materia, notaarquivo.professor, notaarquivo.cpf, notaarquivo.notaf);

    fclose(file);
    printf("Nota registrada com ID %d!\n", notaarquivo.cpf);
}
}

void showNotas() {                  //mstra o conteudo do arquivo
    FILE *file;
    char c;
    char mat[50];
    char mat1[50];

    printf("Entre materia: \n");
     getchar();
    fgets(mat, sizeof(mat), stdin);
    printf("\n");
    sprintf(mat1, "%s.bin", mat);             //nome materia + bin




    file = fopen(mat1, "rb");                 //checa se existe o arquivo
    if (file == NULL) {
        printf("Erro, materia inexistente.\n");
        return;
    }


    while ((c = fgetc(file)) != EOF) {       //mostra o conteudo do arquivo
        putchar(c);
    }


    fclose(file);
}


void showNotaAluno(){

    FILE *file;
    char mat[50];
    char mat1[50];
    char aluno[50];

    printf("Entre materia: \n");
     getchar();
    fgets(mat, sizeof(mat), stdin);
    printf("\n");
    sprintf(mat1, "%s.bin", mat);             //nome materia + bin
    
    printf("Entre com o cpf do aluno: \n");
    scanf("%s",aluno);
    printf("\n");



    file = fopen(mat1, "rb");                 //checa se existe o arquivo
    if (file == NULL) {
        printf("Erro, materia inexistente.\n");
        return;
    }



  aluno[strcspn(aluno, "\n")] = '\0';  // Remover o caractere de fim de linha


  char linha_file[100];     // Ler o arquivo linha por linha e comparar
  while (fgets(linha_file, sizeof(linha_file), file) != NULL) {
  
    linha_file[strcspn(linha_file, "\n")] = '\0';    // Remover o caractere de fim de linha

    
    if (strncmp(linha_file, aluno, strlen(aluno)) == 0) { // Comparar o início da linha
      printf("Nota: %s\n", linha_file);
    }}

  

  fclose(file);

  

}

int menu(void) {
    int option;

    printf("\n\nNota Registrar\n\n");
    printf("1. Registrar Nota\n");
    printf("2. Mostrar Notas\n");
    printf("3. Mostrar Nota por aluno\n");
    printf("0. Sair\n");
    printf("Escolha uma escolha: \n");
    scanf("%d", &option);
    return option;
}

int main() {
    int escolha;

    printf("Bem vindo!\n");

    do {
        escolha = menu();

        switch (escolha) {
            case 1:
                regNota();
                break;
            case 2:
                showNotas();
                break;
            case 3:
                showNotaAluno();
                break;
            case 0:
                printf("Ate mais!\n");
                break;
            default:
                printf("Escolha invalida.\n");
        }
    } while (escolha != 0);

    return 0;
}
