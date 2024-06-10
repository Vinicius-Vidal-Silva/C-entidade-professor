#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "professor.h"
#include "materia.h"

// ProtÃ³tipos das funÃ§Ãµes
/*
int atualizar_aluno();                                        
int atualizar_professor();										
aluno cad_aluno();												
void* cadastrar_aluno();											
materia cad_materia();											
void* cadastrar_materia();										
professor cad_professor();										
void* cadastrar_professor();
void extende_mem_aluno(aluno **vet_cad, int *cont_cad);
void extende_mem_materia(materia **vet_cad, int *cont_cad);
void extende_mem_professor(professor **vet_cad, int *cont_cad);
int ler_alunos();
int ler_materia();
int ler_professor();
void limparBufferEntrada();
*/

atribuicao_mat(){//atribui matérias aos alunos

    int cont = 0;
    int index_prof;
    int index_mat;

    FILE *prof_data; //ponteiro para o arquivo dos professores
    FILE *mat_data;  //ponteiro para o arquivo de matérias

    professor *professor_vet; //ponteiro para array de estruturas dos professores, 'professor_vet'
    materia *materia_vet;     //ponteiro para aarray tabmém, 'materia_vet'

    int prof_data_tamanho; //variáveir para armazenar o tamanho dos arquivos
    int mat_data_tamanho;

    professor prof; // variável prof do tipo professor
    int num_mat = sizeof(prof.materias) / sizeof(prof.materias[0]); //calcula o número de matérias que um professor pode ter, dividindo o tamanho total do array materias pelo tamanho de um único elemento do array.

    
    prof_data = fopen("professor.bin", "rb+");
    if (prof_data == NULL) {
        perror("Erro ao abrir professor.bin");
        return 1;
    } //Abre o arquivo professor.bin no modo de leitura/escrita binária (rb+). Se falhar, imprime uma mensagem de erro e retorna 1.

    mat_data = fopen("materia.bin", "rb+");
    if (mat_data == NULL) {
        perror("Erro ao abrir materia.bin");
        fclose(prof_data);
        return 1;
    } //Abre o arquivo materia.bin no modo de leitura/escrita binária (rb+). Se falhar, imprime uma mensagem de erro, fecha o arquivo de professores e retorna 1.

    
    prof_data_tamanho = tamanho_arq(prof_data);
    mat_data_tamanho = tamanho_arq(mat_data);
    //Calcula o tamanho dos arquivos de professores e matérias usando a função tamanho_arq

    int num_materias = mat_data_tamanho / sizeof(materia);
    int num_professores = prof_data_tamanho / sizeof(professor);
    //Calcula o número de matérias e professores dividindo o tamanho do arquivo pelo tamanho de uma estrutura materia e professor, respectivamente.

    
    professor_vet = malloc(prof_data_tamanho);
    materia_vet = malloc(mat_data_tamanho);
	//Aloca memória suficiente para armazenar todas as estruturas de professores e matérias lidas dos arquivos.
    
    fread(professor_vet, prof_data_tamanho, 1, prof_data);
    fread(materia_vet, mat_data_tamanho, 1, mat_data);
	//Lê os dados dos arquivos professor.bin e materia.bin para os arrays professor_vet e materia_vet.
    
    for (int i = 0; i < num_materias; i++) {
        if (i == 0) {
            printf("       Matérias: %d - %s\n", (i + 1), materia_vet[i].nome);
        } else {
            printf("                 %d - %s\n", (i + 1), materia_vet[i].nome);
        }
    }//Exibe a lista de matérias disponíveis para o usuário escolher.

    printf("Selecionar matéria da lista: ");
    scanf("%d", &index_mat);

    index_mat = index_mat - 1;

    clear_screen();//Limpa a tela.

    
    printf("Matéria selecionada: %s\n\n", materia_vet[index_mat].nome);
    for (int i = 0; i < num_professores; i++) {
        if (i == 0) {
            printf("        Professores: %d - %s\n", (i + 1), professor_vet[i].nome);
        } else {
            printf("                     %d - %s\n", (i + 1), professor_vet[i].nome);
        }
    }
    //Exibe a matéria selecionada e lista os professores disponíveis.

    
    printf("\nDigite o numero do professor que ira¡ ministrar a aula: ");
    scanf("%d", &index_prof);

    index_prof = index_prof - 1;

    clear_screen();

    printf("\n MatÃ©ria  : %s\n", materia_vet[index_mat].nome);
    printf(" Professor: %s\n", professor_vet[index_prof].nome);
    printf(" \npressione ENTER para confirmar a atribuicao.");
    limparBufferEntrada(); //chama o limpador de buffer  
    getchar();

    
    strncpy(materia_vet[index_mat].professor, professor_vet[index_prof].nome, sizeof(materia_vet[index_mat].professor) - 1);
    materia_vet[index_mat].professor[sizeof(materia_vet[index_mat].professor) - 1] = '\0';
	//Copia o nome do professor para o campo professor da matéria selecionada, garantindo que a string esteja corretamente terminada com \0 (ou seja, sem \n)
    
    fseek(mat_data, 0, SEEK_SET);
    //Posiciona o ponteiro do arquivo de matérias no início da matéria selecionada e grava os dados atualizados.
    fseek(mat_data, index_mat * sizeof(materia), SEEK_SET);
	 //Avança o ponteiro para a posição do struct da matéria selecionada.
    
    fwrite(&materia_vet[index_mat], sizeof(materia), 1, mat_data);
	//grava a o struct atualizado da matéria selecionada no arquivo.
    
    int found = 0;
    for (int j = 0; j < num_mat; j++) {
        if (strcmp(professor_vet[index_prof].materias[j], "...") == 0) {
            strncpy(professor_vet[index_prof].materias[j], materia_vet[index_mat].nome, sizeof(professor_vet[index_prof].materias[j]) - 1);
            professor_vet[index_prof].materias[j][sizeof(professor_vet[index_prof].materias[j]) - 1] = '\0';
            found = 1;
            break;
        }
    }//Atualiza o array de matérias do professor, encontrando o primeiro espaço disponível (representado por "...") e copiando o nome da matéria.

    if (!found) {
        printf("Nao ha espaco para adicionar mais materias ao professor.\n");
    }//Se não houver espaço disponível para adicionar mais matérias ao professor, exibe uma mensagem de erro.

    
    fseek(prof_data, 0, SEEK_SET);
    //Posiciona o ponteiro do arquivo de professores no início do professor selecionado e grava os dados atualizados.
    fseek(prof_data, index_prof * sizeof(professor), SEEK_SET);
	//Avança o ponteiro para a posição do struct do professor selecionado. 
	
	   
    fwrite(&professor_vet[index_prof], sizeof(professor), 1, prof_data);
	// Grava o struct atualizado do professor selecionado no arquivo.
    
    fclose(prof_data);
    fclose(mat_data);
    free(professor_vet);
    free(materia_vet);
	//Fecha os arquivos de professores e matérias, e libera a memória alocada para os arrays.
	
    return;

}


int atualizar_aluno() {				//atualiza dados de um aluno no arquivo
    FILE *arquivo;					//ponteiro
    aluno aluno;					//armazena os dados de um aluno
    char nome_procurado[32];		//vetor/array para armazenar o nome do aluno a ser procurado
    int encontrado = 0;				//indica se o aluno foi encontrado

    printf("Nome do aluno: ");		//solicita o nome
    fgets(nome_procurado, sizeof(nome_procurado), stdin);
    //fgets lê uma linha de texto de um arquivo utilizando o nome_procurado, 
	//sizeof limita o tamanho máximo que pode ser lida 
	//stdin a entrada do teclado
    nome_procurado[strcspn(nome_procurado, "\n")] = 0; // Remove newline character
	// Remove o caractere (\n) de nova linha para não atrapalhar na comparaçõa
	
    arquivo = fopen("alunos.bin", "rb+");
    //abre o arquivo binário para ler e escrever
    
    if (arquivo == NULL) {//verifica se houve erro na leitura
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fread(&aluno, sizeof(aluno), 1, arquivo) == 1) {// Loop para ler cada registro de aluno no arquivo
        if (strcmp(aluno.nome, nome_procurado) == 0) { // Verifica se o nome do aluno corresponde ao procurado
            printf("Aluno encontrado:\nNome: %s\nCPF: %ld\n", aluno.nome, aluno.cpf); //imprime o nome do aluno encontrado, cpf e Id
            encontrado = 1;//marca como encontrado
            printf("Insira o nome da materia: ");
            fgets(aluno.materias[0], sizeof(aluno.materias[0]), stdin);// recebe a nova matéria
            aluno.materias[0][strcspn(aluno.materias[0], "\n")] = 0; // novamente ignora o "\n" 

            fseek(arquivo, -sizeof(aluno), SEEK_CUR);//move o ponteiro de volta a posição do ultimo registro (escrito ou lido), para sobrescrever com novos dados
            //fseek move o ponteiro
			//"arquivo" é onde a operação será realizada 
			//"-sizeof(aluno)" é o desloca o arquivo para atrás do arquivo
            //"SEEK_CUR" indica que o deslocamento deve ser feito em relação a posição atual do arquivo
            fwrite(&aluno, sizeof(aluno), 1, arquivo);//escreve os novos dados do aluno no arquivo
            break;//saindo do loop
        }
    }

    if (!encontrado) {//caso não encontrado...
        printf("Item com o nome '%s' nao encontrado.\n", nome_procurado);
    }

    fclose(arquivo);//fecha o arquivo
    return 0;//retorna 0, indicando sucesso
}

int atualizar_professor() {//atualiza os dados de um professor no arquivo

	//		Declarações e inicialiazações
    FILE *arquivo;				// Declara um ponteiro para o arquivo
    professor professor;		// Declara uma variável do tipo 'professor'
    char nome_procurado[48];	// Declara um vetor de caracteres para armazenar o nome procurado
    int encontrado = 0;			// variável para verificar se o professor foi encontrado

	//		Entrada do usuário
    printf("Nome do professor: ");
    fgets(nome_procurado, sizeof(nome_procurado), stdin);
    //"fgets" lê o nome digitado pelo usuário
    //"nome_procurado" é o vetor onde armazena esse dado
    //sizeof limita o tamanho para ser lido
    //"stdin" inclui o caractere de nova linha '\n' que é inserido ao pressionar Enter
    nome_procurado[strcspn(nome_procurado, "\n")] = 0; // remove nova linha gerado pelo '\n'

	//		Abertura do Arquivo
    arquivo = fopen("professor.bin", "rb+");
	//abre o arquivo professor.bin (bin de binário)
	//"rb" é para ler e escrever sem apagar
    if (arquivo == NULL) {
    	//verifica se foi possível abrir com sucesso
    	//se for NULL, significa que houve um erro
        printf("Erro ao abrir o arquivo.\n");//informa o erro
        return 1;  //retorna 1 para indicar que houve erro ao abrir o arquivo
    }

	//		Leitura e Atualização do Arquivo
    while (fread(&professor, sizeof(professor), 1, arquivo) == 1) {
    	//Enquanto 'professor', onde os dados lidos do arquivo serão armmazenados, sizeof limitando o tamanho de dados a serem lidos
    	//"Fread" usado para ler arquivos em binário
    	//1 é para o número de ítens
    	//arquivo é o ponteiro para o arquivo binário aberto, de onde os dados serão lidos
        if (strcmp(professor.nome, nome_procurado) == 0) {
        	//Compara os nomes no arquivo 'professor' com o nome procurado
            printf("Professor encontrado:\nNome: %s\nCPF: %ld\n", professor.nome, professor.cpf);
            encontrado = 1;//retorna sucesso ao encontrar
            printf("Insira o nome da materia: ");
            fgets(professor.materias[0], sizeof(professor.materias[0]), stdin);
            //lê o nome da matéria
            //"fgets" lê o nome digitado pelo usuário
    		//"professor.materias" é o vetor onde armazena esse dado
    		//sizeof limita o tamanho para ser lido
    		//"stdin" inclui o caractere de nova linha '\n' que é inserido ao pressionar Enter
            professor.materias[0][strcspn(professor.materias[0], "\n")] = 0; // Remove '\n'

            fseek(arquivo, -sizeof(professor), SEEK_CUR);//move o ponteiro para antes do registro de professor
            fwrite(&professor, sizeof(professor), 1, arquivo);//escreve os dados atualizados do professor no arquivo
            break;
        }
    }

    if (!encontrado) {//se não encontrado o professor...
        printf("Item com o nome '%s' nao encontrado.\n", nome_procurado);
    }

    fclose(arquivo);//fecha arquivo
    return 0;//retorna 0 para indicar sucesso
}

aluno cad_aluno() {		//função para cadastrar um aluno novo
    aluno _aluno_;		//variável aluno do tipo aluno
    init_aluno(&_aluno_);//inicializa a variável aluno
    //define valores iniciais para os campos da estrutura para que tenham valores válidos
    printf("Nome: ");
    fgets(_aluno_.nome, sizeof(_aluno_.nome), stdin);//lê o nome do aluno a partir da entrada padrão e armazena no campo até o tamanho definido pelo 'sizeof'
    _aluno_.nome[strcspn(_aluno_.nome, "\n")] = 0; // Remove '\n' e substitui por \0 para terminar a string
    
	//leitura do cpf
	printf("CPF: ");
    scanf("%ld", &_aluno_.cpf);
    limparBufferEntrada();//chama essa função que limpa o buffer
    //isso evita que entradas indesejadas interfiram com futuras leituras de entrada
    return _aluno_;//retorna a estrutura '_aluno_' preenchida
}

void* cadastrar_aluno() {//função para o processo de cadastro de alunos
    //cadastra vários alunos e aramzena em binário
   
    FILE *alunos_cad;//ponteiro para o arquivo
    int cont_cad = 0;//contador para a quantidade de alunos acadastrados
    char novo_cad;//para armazenar se o usuário deseja cadastrar um novo aluno ou não 
    int tamanho_alunos_cad;
    int reg_a_ult_cad;
    int arquivo_iniciado = 0;
    
    printf("Deseja cadastrar um aluno?\nDigite 's' para continuar ou 'n' para sair.\n");
    scanf("%c", &novo_cad);
    limparBufferEntrada();
    
    aluno *vet_aluno = NULL;//ponteiro para o vetor aluno que inicialmente é NULL

    
    
    while(novo_cad != 'n'){//fazer até... o usuário digitar 'n'
        
        extende_mem_aluno(&vet_aluno, &cont_cad);
        //extende_mem_aluno expande o array vet_aluno para acomodar um novo aluno.
        vet_aluno[cont_cad - 1] = cad_aluno(); //Chama cad_aluno para cadastrar um novo aluno e armazena os dados no final do array vet_aluno.
        vet_aluno[cont_cad - 1].reg_a += cont_cad - 1; //Atualiza o campo reg_a do novo aluno.
        printf("Deseja cadastrar outro aluno?\nDigite 's' para continuar ou 'n' para sair.\n");
        scanf("%c", &novo_cad);
        limparBufferEntrada();

        while(novo_cad != 's' && novo_cad != 'n'){ //Se a entrada for inválida, pede repetidamente até que o usuário digite uma entrada válida ('s' ou 'n').
            printf("Entrada invalida.\nDigite 's' para continuar ou 'n' para sair.\n");
            scanf("%c", &novo_cad);
            limparBufferEntrada();
        }

    }//Se o usuário digitar 's', o loop recomeça. Se digitar 'n', o loop termina.



    alunos_cad = fopen("alunos.bin", "rb");
    
    if(alunos_cad == NULL){ //caso tenha erro ao abrir o arquivo
    
        // printf("Erro ao abrir arquivo"); -> apagar se não usar mais(?)
        // exit(1);-> apagar se não usar mais(?)
        
        alunos_cad = fopen("alunos.bin", "wb");//abre ou cria o arquivo de alunos cadastrados no arquivo 'alunos.bin' e lê/escreve em binário 'rb'
    }else{ //caso tenha aberto com sucesso
        alunos_cad = fopen("alunos.bin", "ab"); //abre o arquivo e adiciona os dados ao final do arquivo sem sobrescrever o que já tinha 
        tamanho_alunos_cad = tamanho_arq(alunos_cad)/sizeof(aluno); //Calcula o número de registros do tipo aluno já presentes no arquivo. A função tamanho_arq(alunos_cad) retorna o tamanho do arquivo em bytes. Dividindo pelo tamanho de um único registro aluno (sizeof(aluno)), obtemos o número de registros.
        arquivo_iniciado = 1; //Define a variável arquivo_iniciado como 1, indicando que o arquivo foi inicializado e contém registros.
        
    }

    if(arquivo_iniciado == 1){ //Verifica se arquivo_iniciado é 1, confirmando que o arquivo já contém registros.
        for(int i = 0; i < cont_cad; i++ ){ //Um laço for que percorre todos os novos registros de alunos armazenados no vetor vet_aluno.
            vet_aluno[i].reg_a += tamanho_alunos_cad;//Atualiza o valor do campo reg_a de cada novo aluno. Este campo é incrementado pelo número de registros já presentes no arquivo (tamanho_alunos_cad). Isso assegura que os registros dos novos alunos continuem a numeração dos registros já presentes no arquivo.
        }
    }

    
    fwrite(vet_aluno, sizeof(aluno), cont_cad, alunos_cad);//escreve o vetor 'vet_aluno' no arquivo 'alunos.bin'
    //'fwrite' escreve 'cont_cad' elementos, cada um com tamanho de 'sizeof(aluno)'
	printf("%d", cont_cad);


    fclose(alunos_cad);//fecha o arquivo
    free(vet_aluno);//libera memória alocada para o vetor 'vet_aluno'

    return 0;//retorna 0 demonstrando que a função foi concluída com sucesso
}

materia cad_materia() { 						//cadastra uma matério
    materia _materia_;  						//Declara uma variável local _materia_ do tipo materia. Esta variável armazenará os dados da matéria que será cadastrada.
    init_materia(&_materia_);					//Chama a função init_materia
    printf("Nome da materia: ");
    fgets(_materia_.nome, sizeof(_materia_.nome), stdin); //Usa a função fgets para ler uma linha de texto do stdin
    //sizeof(_materia_.nome) especifica o tamanho do buffer nome, garantindo que não se ultrapasse o tamanho alocado para o nome da matéria.
    _materia_.nome[strcspn(_materia_.nome, "\n")] = 0; // Remove '\n' e substitui por \0
    printf("Sigla: ");
    fgets(_materia_.sigla, sizeof(_materia_.sigla), stdin);//Usa a função fgets para ler uma linha de texto do stdin e armazena esse texto no campo sigla da estrutura _materia_.
	//sizeof(_materia_.sigla) especifica o tamanho do buffer sigla, garantindo que não se ultrapasse o tamanho alocado para a sigla da matéria.
    _materia_.sigla[strcspn(_materia_.sigla, "\n")] = 0; // Remove '\n' e substitui por \0
    return _materia_;
}

void* cadastrar_materia() {
    FILE *materias_cad; //ponteiro do arquivo
    int cont_cad = 0;   //contador de quantas matérias foram cadastradas
    char novo_cad;		//usado para armazenar a resposta se deseja ou não continuar cadastrando as respostas

    materia *vet_materia = NULL;//Declara um ponteiro vet_materia para uma estrutura do tipo materia e o inicializa como NULL. Este ponteiro será usado para armazenar dinamicamente as matérias cadastradas.

	//		Loop de Cadastro
    do { //continua executando até que novo_cad seja 'n'
        printf("Deseja cadastrar uma materia? Digite 's' para continuar ou 'n' para sair: ");
        scanf(" %c", &novo_cad);
        limparBufferEntrada();

        if (novo_cad == 's') {//Se o usuário digitar 's', a função extende_mem_materia é chamada para aumentar a memória alocada para o vetor vet_materia, permitindo armazenar mais matérias
            extende_mem_materia(&vet_materia, &cont_cad); //
            vet_materia[cont_cad - 1] = cad_materia(); //Chama a função cad_materia para cadastrar uma nova matéria e armazena a matéria no vetor vet_materia na posição cont_cad - 1
            //Incrementa cont_cad para contabilizar a nova matéria cadastrada.
        }
    } while (novo_cad != 'n');

	//		Manipulação de arquivo
    materias_cad = fopen("materia.bin", "wb");
    if (materias_cad == NULL) {
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }	//Abre (ou cria) o arquivo materia.bin no modo de escrita binária (wb). O conteúdo existente do arquivo será sobrescrito.
		//Verifica se o arquivo foi aberto com sucesso. Se não foi, imprime uma mensagem de erro e encerra o programa com exit(1).

    fwrite(vet_materia, sizeof(materia), cont_cad, materias_cad);
    printf("Total de matÃ©rias cadastradas: %d\n", cont_cad);
    //Escreve o conteúdo do vetor vet_materia no arquivo materia.bin. O fwrite escreve cont_cad elementos, cada um com o tamanho sizeof(materia).
	//Imprime o número total de matérias cadastradas.

    fclose(materias_cad);
    free(vet_materia);
    //Fecha o arquivo materia.bin.
	//Libera a memória alocada dinamicamente para o vetor vet_materia.
    
    return 0;
    //Retorna 0, indicando que a função foi executada com sucesso. Apesar da função ter sido declarada como void*, ela retorna um inteiro
}

professor cad_professor() {
    professor _professor_;
    init_professor(&_professor_);
    //A função cad_professor cria uma variável _professor_ do tipo professor e a inicializa usando a função init_professor.
    printf("Nome: ");
    fgets(_professor_.nome, sizeof(_professor_.nome), stdin);
    //A função solicita ao usuário que insira o nome do professor e armazena essa informação na variável _professor_.nome. Qualquer caractere de nova linha ('\n') no final é removido para garantir que a string seja bem formatada.
    _professor_.nome[strcspn(_professor_.nome, "\n")] = 0; // Remove newline character
    printf("CPF: ");
    scanf("%ld", &_professor_.cpf);
    //A função solicita ao usuário que insira o CPF do professor e armazena essa informação na variável _professor_.cpf. Após a entrada, o buffer do teclado é limpo para evitar interferências em futuras leituras.
    limparBufferEntrada();
    return _professor_;//A função retorna a estrutura _professor_ contendo os dados do professor recém-cadastrado.
}

void* cadastrar_professor() {
	//A função cadastrar_professor manipula o arquivo de professores e usa variáveis para contar e armazenar temporariamente os professores cadastrados
    FILE *professores_cad;
    int cont_cad = 0; //conta quantos professores foram cadastrados
    char novo_cad;//aramzena a resposta se vai querer ou não continuar cadastrando o novo professor

    professor *vet_professor = NULL;
    //Declara um ponteiro vet_professor do tipo professor, inicializado com NULL. Este ponteiro será usado para armazenar dinamicamente uma lista de professores.

	//		Loop de Cadastro
    do {
        printf("Deseja cadastrar um professor? Digite 's' para continuar ou 'n' para sair: ");
        scanf(" %c", &novo_cad);
        limparBufferEntrada();
        //Exibe uma mensagem perguntando ao usuário se deseja cadastrar um novo professor. Lê a resposta do usuário e limpa o buffer de entrada para evitar problemas com entradas subsequentes.

        if (novo_cad == 's') {
            extende_mem_professor(&vet_professor, &cont_cad);
            vet_professor[cont_cad - 1] = cad_professor();
        }//Se a resposta for 's', a função extende_mem_professor é chamada para ajustar o tamanho do vetor vet_professor e incrementar cont_cad
    } while (novo_cad != 'n');
    //Em seguida, chama a função cad_professor para cadastrar um novo professor e armazena esse professor no vetor. O loop continua até que o usuário digite 'n'.

	//		Manipulação de Arquivo
    professores_cad = fopen("professor.bin", "wb");
    if (professores_cad == NULL) {
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }//Abre o arquivo professor.bin no modo "wb" (escrita binária). Se o arquivo não puder ser aberto, exibe uma mensagem de erro e termina o programa.

    fwrite(vet_professor, sizeof(professor), cont_cad, professores_cad);
    printf("Total de professores cadastrados: %d\n", cont_cad);
    //Escreve o conteúdo do vetor vet_professor no arquivo professor.bin, gravando cont_cad elementos de tamanho sizeof(professor). Em seguida, exibe o total de professores cadastrados.

    fclose(professores_cad);
    free(vet_professor);
    return 0;
    //Fecha o arquivo professores_cad para garantir que os dados sejam salvos corretamente. Libera a memória alocada para vet_professor para evitar vazamento de memória. A função retorna 0, indicando que a operação foi concluída com sucesso.
}

void clear_screen() {
    #ifdef _WIN32 //#ifdef _WIN32 verifica se o código está sendo compilado em um ambiente Windows.
        system("cls");//Se estiver no Windows (_WIN32 é definido para sistemas Windows), ele executa o comando system("cls"), que limpa a tela no prompt de comando do Windows usando o comando cls.
    #else
        system("clear");//Se não estiver no Windows, ou seja, em sistemas Unix-like, ele executa o comando system("clear"), que limpa a tela usando o comando clear.
    #endif
}

void extende_mem_aluno(aluno **vet_cad, int *cont_cad) {//estende a memória alocada dinamicamente para armazenar informações sobre os alunos
    //Ela recebe um ponteiro para ponteiro de aluno (aluno **vet_cad) e um ponteiro para inteiro (int *cont_cad).
	//O ponteiro para ponteiro de aluno (aluno **vet_cad) é usado para que as alterações feitas na alocação de memória dentro da função sejam refletidas fora dela. Isso permite que o vetor de alunos seja modificado mesmo após o retorno da função.
	*cont_cad += 1; //incrementa o contador de alunos
    aluno *temp = realloc(*vet_cad, (*cont_cad) * sizeof(aluno)); //realloc é usado para alterar o tamanho da memória previamente alocada.
    //(*cont_cad) * sizeof(aluno) calcula o novo tamanho em bytes com base no número atual de alunos.
    if (temp == NULL) {
        printf("Erro ao alocar memÃ³ria\n");
        exit(1);
    }
	//Se for bem-sucedida, atualiza o ponteiro vet_cad para apontar para a nova memória alocada (*vet_cad = temp;).
	//Se não for bem-sucedida, exibe uma mensagem de erro e encerra o programa.
    *vet_cad = temp;//atualiza o ponteiro original para que ele aponte para a nova área de memória, garantindo que o vetor de alunos seja estendido corretamente e que as alterações persistam fora da função.
}

void extende_mem_materia(materia **vet_cad, int *cont_cad) {
	//Esta função recebe dois argumentos:
	//vet_cad: Um ponteiro para um ponteiro de materia. Isso significa que vet_cad contém o endereço de memória de um vetor de materiais.
	//cont_cad: Um ponteiro para um inteiro que mantém o número atual de elementos no vetor.
    *cont_cad += 1; //aciona +1 ao contador de materias ao vetor
    materia *temp = realloc(*vet_cad, (*cont_cad) * sizeof(materia));
    //materia *temp: Declaração de um ponteiro temporário para materiais.
    //realloc(*vet_cad, (*cont_cad) * sizeof(materia)): Esta função tenta realocar memória para o vetor de materiais. Se bem-sucedida, ela aumentará o tamanho do vetor para acomodar mais um material. *vet_cad contém o endereço do vetor de materiais, e (*cont_cad) * sizeof(materia) calcula o tamanho necessário para o vetor.
    if (temp == NULL) {
        printf("Erro ao alocar memoria\n");
        exit(1);
        //Verifica se a realocação de memória foi bem-sucedida. Se temp for NULL, significa que a realocação falhou, então exibimos uma mensagem de erro e encerramos o programa.
    }
    *vet_cad = temp;
    //Atualiza o ponteiro vet_cad para apontar para a nova área de memória alocada. Se a realocação de memória for bem-sucedida, o endereço de temp é atribuído a *vet_cad, garantindo que o vetor original agora aponte para a nova área de memória.
}

void extende_mem_professor(professor **vet_cad, int *cont_cad) { //Essa função basicamente estende dinamicamente o vetor de professores para acomodar mais um professor, garantindo que não percamos os dados já existentes e que possamos adicionar novos professores ao vetor.
	//Esta função recebe dois argumentos:
	//vet_cad: Um ponteiro para um ponteiro de professor. Isso significa que vet_cad contém o endereço de memória de um vetor de professores.
	//cont_cad: Um ponteiro para um inteiro que mantém o número atual de elementos no vetor.
    *cont_cad += 1;
    //*cont_cad += 1;: Isso aumenta o valor do contador de professores em 1. Ou seja, estamos dizendo que queremos adicionar mais um professor ao vetor.
    professor *temp = realloc(*vet_cad, (*cont_cad) * sizeof(professor));
    //professor *temp: Declaração de um ponteiro temporário para professores.
    //realloc(*vet_cad, (*cont_cad) * sizeof(professor)): Esta função tenta realocar memória para o vetor de professores. Se bem-sucedida, ela aumentará o tamanho do vetor para acomodar mais um professor. *vet_cad contém o endereço do vetor de professores, e (*cont_cad) * sizeof(professor) calcula o tamanho necessário para o vetor.
    if (temp == NULL) {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }//Verifica se a realocação de memória foi bem-sucedida. Se temp for NULL, significa que a realocação falhou, então exibimos uma mensagem de erro e encerramos o programa.
    *vet_cad = temp;
    //Atualiza o ponteiro vet_cad para apontar para a nova área de memória alocada. Se a realocação de memória for bem-sucedida, o endereço de temp é atribuído a *vet_cad, garantindo que o vetor original agora aponte para a nova área de memória.
}

int ler_alunos() {
    
    int num_alunos; //armazena número total de alunos

    aluno *alunos_cad; // Ponteiro para armazenar os alunos lidos do arquiv

    FILE *arquivo_alunos_cad; // Ponteiro para o arquivo de alunos

    arquivo_alunos_cad = fopen("alunos.bin", "rb"); // Abre o arquivo de alunos para leitura binária

    if(arquivo_alunos_cad == NULL){// Verifica se houve erro na abertura do arquivo
        printf("Erro ao abrir o arquivo");
        return 1;// Retorna 1 para indicar erro
    }

    fseek(arquivo_alunos_cad,0,SEEK_END); // Move o cursor para o final do arquivo
    int tamanho_arq = ftell(arquivo_alunos_cad);// Obtém o tamanho do arquivo em bytes
    fseek(arquivo_alunos_cad,0,SEEK_SET);// Move o cursor de volta para o início do arquivo

    num_alunos = tamanho_arq / sizeof(aluno);// Calcula o número de alunos no arquivo

    alunos_cad = malloc(sizeof(aluno) * num_alunos);// Aloca memória para armazenar os alunos

    fread(alunos_cad, sizeof(aluno), num_alunos, arquivo_alunos_cad);// Lê os alunos do arquivo para a memória

    for(int i = 0; i < num_alunos; i++){// Loop para imprimir os dados de cada aluno
        printf("\n");
        printf(" nome: %s\n Reg.Acad.: %d\n CPF:%ld\n Privilegio: %d\n", alunos_cad[i].nome,alunos_cad[i].reg_a, alunos_cad[i].cpf,alunos_cad[i].priv);
        printf(" MatÃ©rias: ");
        for(int j = 0; j < 3; j++ ){// Loop para imprimir as matérias do aluno
            if(j == 0){
                printf("%s",alunos_cad[i].materias[j]);
            }else{
                printf("\n           %s",alunos_cad[i].materias[j]);
            }
            
        }
        printf("\n\n"); 
    }
}

int ler_materia() {
    
    int num_materias;// Variável para armazenar o número total de matérias

    materia *materias_cad;// Ponteiro para armazenar as matérias lidas do arquivo

    FILE *arquivo_materias_cad;// Ponteiro para o arquivo de matérias

    arquivo_materias_cad = fopen("materia.bin", "rb");// Abre o arquivo de matérias para leitura binária


    if(arquivo_materias_cad == NULL){ //// Verifica se houve erro na abertura do arquivo
        printf("Erro ao abrir o arquivo");
        return 1; // Retorna 1 para indicar erro
    }


    fseek(arquivo_materias_cad,0,SEEK_END);// Move o cursor para o final do arquivo
    int tamanho_arq = ftell(arquivo_materias_cad);// Obtém o tamanho do arquivo em bytes
    fseek(arquivo_materias_cad,0,SEEK_SET);// Move o cursor de volta para o início do arquivo


    num_materias = tamanho_arq / sizeof(materia);// Calcula o número de matérias no arquivo

    materias_cad = malloc(sizeof(materia) * num_materias);// Aloca memória para armazenar as matérias

    fread(materias_cad, sizeof(materia), num_materias, arquivo_materias_cad);// Lê as matérias do arquivo para a memória


    for(int i = 0; i < num_materias; i++){// Loop para imprimir os dados de cada matéria
        printf("\n");
        printf(" nome: %s\n Sigla: %s\n Professor: %s\n\n", materias_cad[i].nome, materias_cad[i].sigla, materias_cad[i].professor);
    }
}

int ler_professor() {
    
    int num_professores;// Variável para armazenar o número total de professores

    professor *professores_cad;// Ponteiro para armazenar os professores lidos do arquivo

    FILE *arquivo_professores_cad;// Ponteiro para o arquivo de professores

    arquivo_professores_cad = fopen("professor.bin", "rb");// Abre o arquivo de professores para leitura binária

    if(arquivo_professores_cad == NULL){ //// Verifica se houve erro na abertura do arquivo
        printf("Erro ao abrir o arquivo");
        return 1;// Retorna 1 para indicar erro
    }

    fseek(arquivo_professores_cad,0,SEEK_END);// Move o cursor para o final do arquivo
    int tamanho_arq = ftell(arquivo_professores_cad);// Obtém o tamanho do arquivo em bytes
    fseek(arquivo_professores_cad,0,SEEK_SET);// Move o cursor de volta para o início do arquivo

    num_professores = tamanho_arq / sizeof(professor);// Calcula o número de professores no arquivo

    professores_cad = malloc(sizeof(professor) * num_professores);// Aloca memória para armazenar os professores

    fread(professores_cad, sizeof(professor), num_professores, arquivo_professores_cad);// Lê os professores do arquivo para a memória

    for(int i = 0; i < num_professores; i++){// Loop para imprimir os dados de cada professor
        printf("\n");
        printf(" nome: %s\n CPF:%ld\n PrivilÃ©gio: %d\n", professores_cad[i].nome, professores_cad[i].cpf,professores_cad[i].priv);
        printf(" Materias: ");
        for(int j = 0; j < 3; j++ ){
            if(j == 0){
                printf("%s",professores_cad[i].materias[j]);
            }else{
                printf("\n           %s",professores_cad[i].materias[j]);
            }
            
        }
        printf("\n\n");
    }
}

void limparBufferEntrada() {
    int c; //// Variável para armazenar cada caractere lido do buffer
    while ((c = getchar()) != '\n' && c != EOF){};// Loop para ler e descartar caracteres do buffer até encontrar '\n' (quebra de linha) ou EOF (final do arquivo)
	// Este loop continua enquanto o caractere atual não for uma quebra de linha '\n' e não for o final do arquivo EOF
	// Isso garante que o buffer seja totalmente limpo até o próximo '\n' ou EOF
}

int tamanho_arq(FILE *data_set) {

    fseek(data_set, 0, SEEK_END);
    // Move o indicador de posição do arquivo para o final do arquivo
    //Isso é feito para determinar o tamanho total do arquivo.
    
    int tamanho_arq = ftell(data_set);
    // Obtem a posição atual do indicador de posição, que é o tamanho do arquivo
    //int tamanho_arq = ftell(data_set): ftell() retorna a posição atual do indicador de posição do arquivo, que no caso de ter sido movido para o final do arquivo, é o tamanho do arquivo.
    
	fseek(data_set, 0, SEEK_SET);
    // Move o indicador de posição do arquivo de volta para o início do arquivo
    //Move o indicador de posição do arquivo de volta para o início do arquivo, para deixar o arquivo pronto para leitura ou escrita.
    
	return tamanho_arq;
    // Retorna o tamanho do arquivo em bytes
}

int main() { //main contendo os cases para chamar as funções
    int opcao;

    do {
        printf("\nSelecione uma opcao:\n");
        printf("1.Atribuir Materia\n");
        printf("2. Atualizar Aluno\n");
        printf("3. Atualizar Professor\n");
        printf("4. Cadastrar Aluno\n");
        printf("5. Cadastrar Materia\n");
        printf("6. Cadastrar Professor\n");
        printf("7. Ler Alunos\n");
        printf("8. Ler Materia\n");
        printf("9. Ler Professor\n");
        printf("10. Sair\n");
        printf("Digite a opcao desejada: ");
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
                cadastrar_aluno();
                break;
            case 5:
                cadastrar_materia();
                break;
            case 6:
                cadastrar_professor();
                break;
            case 7:
                ler_alunos();
                break;
            case 8:
                ler_materia();
                break;
            case 9:
                ler_professor();
                break;
            case 10:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 10);

    return 0;
}
