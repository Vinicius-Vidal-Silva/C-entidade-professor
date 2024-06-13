#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do registro
typedef struct {
    char cpf[12];
    char senha[10];
    int privilegio;
} Usuario;

// Função para ler um registro do arquivo binário
int LerUsuario(FILE *file, Usuario *usuario) {
    if (fread(usuario->cpf, sizeof(char), 12, file) != 12) {
        return 0;
    }
    if (fread(usuario->senha, sizeof(char), 10, file) != 10) {
        return 0;
    }
    if (fread(&usuario->privilegio, sizeof(int), 1, file) != 1) {
        return 0;
    }
    return 1;
}

// Função para verificar se o CPF corresponde à senha e retornar o privilégio
int VerificarCpfSenha(const char *nomeArquivo, const char *cpf, const char *senha, int *privilegio) {
    // Abre o arquivo binário para leitura
    FILE *file = fopen(nomeArquivo, "rb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    Usuario usuario;

    // Lê os registros do arquivo e verifica o CPF e a senha
    while (LerUsuario(file, &usuario)) {
        if (strcmp(usuario.cpf, cpf) == 0 && strcmp(usuario.senha, senha) == 0) {
            *privilegio = usuario.privilegio;
            fclose(file);
            return 1; // CPF e senha correspondem
        }
    }

    fclose(file);
    return 0; // CPF e senha não correspondem
}

// Função para escrever um registro no arquivo binário
void EscreverUsuario(FILE *file, Usuario *usuario) {
    fwrite(usuario->cpf, sizeof(char), 12, file);
    fwrite(usuario->senha, sizeof(char), 10, file);
    fwrite(&usuario->privilegio, sizeof(int), 1, file);
}

// Função para formatar o arquivo com alguns usuários
void FormatarArquivo(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    Usuario usuarios[3] = {
        {"47246813810", "senha1", 1},
        {"12345678901", "senha2", 2},
        {"10987654321", "senha3", 3}
    };

    for (int i = 0; i < 3; i++) {
        EscreverUsuario(file, &usuarios[i]);
    }

    fclose(file);
}

void AbrirArquivoC(const char *filename) {
    char command[256];
#ifdef _WIN32
    sprintf(command, "gcc %s -o temp.exe && temp.exe", filename);
#else
    sprintf(command, "gcc %s -o temp && ./temp", filename);
#endif
    system(command);
}

int main() {
    const char *nomeArquivo = "usuarios.bin";
    
    // Formatar o arquivo com alguns usuários
    FormatarArquivo(nomeArquivo);

    // Verificar se o CPF e a senha correspondem
    char cpf[12];
    char senha[10];
    int privilegio;
    int opcaoMenu;
    int continuaMenu = 1;
	do{
		printf("[1] - Login\n");
		printf("[2] - Sair\n");
		scanf("%d", &opcaoMenu);
		switch (opcaoMenu){
			case 1:
			    printf("Digite o CPF: ");
			    scanf("%11s", cpf);
			    printf("Digite a senha: ");
			    scanf("%9s", senha);
			    
			
			    if (VerificarCpfSenha(nomeArquivo, cpf, senha, &privilegio)) {
			        printf("CPF e senha correspondem!\n");
			        if (privilegio == 1) {
			            printf("Você é Administrador.\n");
			            AbrirArquivoC("admin.c");
			        } else if (privilegio == 2) {
			            printf("Você é Professor.\n");
			            AbrirArquivoC("professor.c");
			        } else if (privilegio == 3) {
			            printf("Você é Aluno.\n");
			            AbrirArquivoC("aluno.c");
			        } else {
			            printf("Privilégio desconhecido.\n");
			        }
			    } else {
			        printf("CPF e/ou senha incorretos.\n");
			    }
			    break;
			case 2:
				continuaMenu = 0;
				break;
			default:
				printf("Opcao invalida...");
                getchar();
                getchar();
                break;
		}
		system("cls");
	}while(continuaMenu);
    return 0;
}
