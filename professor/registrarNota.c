#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Nota {
    char professor[50];
    char materia[50];
    int notaf;
    int cpf;


};

static int idprox = 1;

void regNota() {
    struct Nota notaarquivo;
    FILE *file;
    FILE *file2;
    char mat[50];
    char primeiraLinha[50];
    FILE *existe;




   printf("Entre materia: \n");
   scanf("%s", notaarquivo.materia);

    sprintf(mat, "%s.txt", notaarquivo.materia);
    file2 = fopen(mat, "r");


   // if (fgets(primeiraLinha, 50, file2) != NULL) {
    //if (file2 != NULL) {
   //    int tam = strlen(primeiraLinha);
      // if (primeiraLinha[tam - 1] == '\n') {
           //primeiraLinha[tam - 1] = '\0';
           if (file2 != NULL) {

           file = fopen(mat, "a");
           //printf("%s\n",mat);
           if (file == NULL) {
               printf("Erro.\n");
               return;
           }

           printf("Entre com o cpf do aluno: \n");
           scanf("%d", &notaarquivo.cpf);

           printf("Entre nota: \n");
           scanf("%d", &notaarquivo.notaf);

           fprintf(file, "%d, %d\n", notaarquivo.cpf, notaarquivo.notaf);

           fclose(file);
           printf("Nota registrada com ID %d!\n", notaarquivo.cpf);
//       }

       //printf("%s\n", primeiraLinha);
   } else {
       //printf("Falha abrir 1 linha!\n");


       file = fopen(mat, "a");
       //printf("%s\n",mat);
       if (file == NULL) {
           printf("Erro.\n");
           return;
       }


       printf("Entre com o nome do professor: \n");
       scanf("%s", notaarquivo.professor);



       printf("Entre com o cpf do aluno: \n");
       scanf("%d", &notaarquivo.cpf);


       printf("Entre nota: \n");
       scanf("%d", &notaarquivo.notaf);



       //    fprintf(file, "%s %s %d\n", notaarquivo.professor, notaarquivo.materia, notaarquivo.notaf);
       fprintf(file, "%s\n%s\n%d, %d\n", notaarquivo.materia, notaarquivo.professor, notaarquivo.cpf, notaarquivo.notaf);

       fclose(file);
       printf("Nota registrada com ID %d!\n", notaarquivo.cpf);
}
}

void showNotas() {
    FILE *file;
    char c;
    char mat[50];
    char mat1[50];

    printf("Entre materia: \n");
    scanf("%s",mat);
    printf("\n");
    sprintf(mat1, "%s.txt", mat);

    //printf("%s\n",mat1);


    file = fopen(mat1, "r");
    if (file == NULL) {
        printf("Erro.\n");
        return;
    }


    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }


    fclose(file);
}


int menu(void) {
    int option;

    printf("\n\nNota Registrar\n\n");
    printf("1. Registrar Nota\n");
    printf("2. Mostrar Notas\n");
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
            case 0:
                printf("Ate mais!\n");
                break;
            default:
                printf("Escolha invalida.\n");
        }
    } while (escolha != 0);

    return 0;
}
