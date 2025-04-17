#include "utils.h"

#define TAXA_JUROS 0.05
#define LIMITE_PARCELA 0.20


// Definição de macros para limpar a tela
void limpar_buffer(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

void msg_erro(char *msg){
    limpar_buffer();
    system(LIMPAR_TELA);
    printf("\n----------------Erro------------------------------\n");
    printf("%s", msg);
    printf("----------------------------------------------------\n");
    printf("\nAperte <ENTER> para voltar ao menu principal.");
    getchar();
}

//Função para validar se existem apenas letras e espaços no nome do cliente
int validar_nome(char *nome){
    for(size_t i = 0; i < strlen(nome); i++){
        if(!isalpha(nome[i]) && nome[i] != ' '){
            return 0;
        }
    }
    return 1;
}

// Função para alocar ou realocar memória para o array de clientes
Cliente* realocar_memoria_cliente(Cliente *clientes, int novo_tamanho) {
    // Realoca memória para o array de clientes
    Cliente *temp = realloc(clientes, novo_tamanho * sizeof(Cliente));
    if (temp == NULL){
        msg_erro("Erro na realocacao de memoria.");
        free(clientes);
        exit(1);
    }
    return temp;
}

// Função para alocar ou realocar memória para o array de emprestimos
Emprestimo* realocar_memoria_emprestimo(Emprestimo *emprestimos, int novo_tamanho) {
    // Realoca memória para o array de empréstimos
    Emprestimo *temp = realloc(emprestimos, novo_tamanho * sizeof(Emprestimo));
    if(temp == NULL){
        msg_erro("Erro na realocacao de memoria.");
        free(emprestimos);
        exit(1);
    }
    return temp;
}

// Cadastra um novo cliente e adiciona ao array de clientes
Cliente *cadastrar_novo_cliente(Cliente *clientes, int *num_clientes) {
    clientes = realocar_memoria_cliente(clientes, *num_clientes + 1);//realoca memoria para o cliente
    Cliente *novo_cliente = &clientes[*num_clientes]; //aponta o ponteiro novo_cliente para a ultima posicao do vetor de clientes
    
    int l = 1;
    
    while(l){
        printf("Digite o nome do cliente: ");
        if(fgets(novo_cliente->nome, MAX_NOME, stdin) != NULL){
            novo_cliente->nome[strcspn(novo_cliente->nome, "\n")] = '\0';

            if(validar_nome(novo_cliente->nome) == 1){
                printf("Nome registrado com sucesso.");
                l = 0;
            }
            else{
                msg_erro("Nome inserido invalido, utilize apenas letras e espacos.");
            }
        }
        else{
            msg_erro("Erro ao ler o nome, tente novamente.");
        }
    }

    l = 1;

    while(l){
        printf("\nDigite o ID do cliente(ATENCAO, USE APENAS NUMEROS INTEIROS): ");
        int validar_id = scanf("%d", &novo_cliente->id);

        if(validar_id == 1){
            printf("ID registrado com sucesso!\n");
            limpar_buffer();
            l = 0;
        }
        else{
            msg_erro("Valor invalido para ID de cliente.");
        }
    }

    l = 1;

    while(l){
        printf("\nDigite o salario do cliente: ");
        int validar_salario = scanf("%f", &novo_cliente->salario);

        if(validar_salario == 1){
            if(novo_cliente->salario >= 2000 && novo_cliente->salario <= 15000){
                printf("Salario registrado com sucesso!\n");
                limpar_buffer();
                l = 0;
            }
            else{
                msg_erro("O valor do salario deve estar entre 2.000 e 15.000");
            }
        }
        else{
            msg_erro("Valor invalido para o salario.");
        }
    }
    novo_cliente->historico_emprestimos = NULL; //inicializa as variáveis do novo cliente para serem nulas ou zero
    novo_cliente->num_emprestimos = 0;
    (*num_clientes)++;
    return clientes;
}

// Solicita um novo empréstimo para um cliente
void solicitar_novo_emprestimo(Cliente *clientes, int num_clientes) {
    int temp_id, l = 1;
    Cliente *cliente = NULL;
    
    while(l){
        printf("Digite o ID do cliente que deseja solicitar um emprestimo: ");
        int validar_temp_id = scanf("%d", &temp_id);

        if(validar_temp_id == 1){
            cliente = buscar_cliente_por_id(clientes, num_clientes, temp_id);
            if(cliente != NULL){
                printf("Cliente encontrado com sucesso!\n");
                limpar_buffer();
                l = 0;
            }
            else{
                msg_erro("Cliente nao encontrado.");
            }
        }
        else{
            msg_erro("Valor invalido para ID de cliente.");
        }
    }

    l = 1;

    Emprestimo novo_emp;
    novo_emp.cliente_id = temp_id;

    while(l){
        printf("Digite o valor do emprestimo: ");
        int validar_emprestimo = scanf("%f", &novo_emp.valor_emprestimo);

        if(validar_emprestimo == 1){
            if(novo_emp.valor_emprestimo >= 1000 && novo_emp.valor_emprestimo <= 200000){
                printf("Valor inserido com sucesso!\n");
                limpar_buffer();
                l = 0;
            }
            else{
                msg_erro("O valor do emprestimo deve estar entre 1.000 e 200.000");
            }
        }
        else{
            msg_erro("Tipo de dado inserido esta errado.");
        }
    }

    l = 1;

    while(l){
        printf("\nDigite o numero de vezes que deseja parcelar(ATENCAO, USE NUMERO INTEIROS): ");
        int validar_parcelas = scanf("%d", &novo_emp.num_parcelas);

        if(validar_parcelas == 1){
            if(novo_emp.num_parcelas >= 6 && novo_emp.num_parcelas <= 180){
                printf("Numero de parcelas inserido com sucesso!");
                limpar_buffer();
                l = 0;
            }
            else{
                msg_erro("O numero de parcelas deve estar entre 6 e 180");
            }
        }
        else{
            msg_erro("Tipo de dado inserido para a parcela esta errado, tente novamente.");
        }
    }
    calcular_valor_parcela(&novo_emp);
    aprovar_reprovar_emprestimo(cliente, &novo_emp);
}

// Calcula o valor da parcela do empréstimo
void calcular_valor_parcela(Emprestimo *emprestimo) {
    float total = emprestimo->valor_emprestimo * (1 + TAXA_JUROS);
    emprestimo->valor_parcela = total / emprestimo->num_parcelas;
}

// Aprova ou reprova o empréstimo com base no salário do cliente
void aprovar_reprovar_emprestimo(Cliente *cliente, Emprestimo *novo_emprestimo) {
    float soma_parcelas = novo_emprestimo->valor_parcela;

    
    for(int i = 0; i < cliente->num_emprestimos; i++){
        if(cliente->historico_emprestimos[i].ativo){
            soma_parcelas += cliente->historico_emprestimos[i].valor_parcela; //soma apenas os emprestimos ativos
        }
    }
    //Confere os valores
    if(soma_parcelas > LIMITE_PARCELA * cliente->salario){
        novo_emprestimo->aprovacao = 0;
        novo_emprestimo->ativo = 0;
        printf("\nEmprestimo reprovado!\n");
    }
    else{
        novo_emprestimo->aprovacao = 1;
        novo_emprestimo->ativo = 1;
        printf("\nEmprestimo aprovado!\n");
    }

    //Realoca memoria se necessario
    Emprestimo *temp = realocar_memoria_emprestimo(cliente->historico_emprestimos, cliente->num_emprestimos + 1);

    if(temp){
        cliente->historico_emprestimos = temp; //Aponta o ponteiro para o local correto novamente se houve mudança
        cliente->historico_emprestimos[cliente->num_emprestimos] = *novo_emprestimo; //Coloca o último empréstimo na última posição
        cliente->num_emprestimos++; //Adiciona na contagem de empréstimos realizados
    }
    else{
        printf("Erro para registrar emprestimo no historico\n.");
    }
}



// Carrega os clientes do arquivo CSV e retorna um array de clientes
// O número de clientes é retornado através do ponteiro num_clientes
// O arquivo deve ter o formato: id,nome,salario
// Exemplo: 1,João,3000.00
Cliente *carregar_clientes(const char *nome_arquivo, int *num_clientes) {
    FILE *arquivo = fopen(nome_arquivo, "r"); // Abre o arquivo para leitura
    if (!arquivo) { // Verifica se o arquivo foi aberto corretamente
        // Se não, imprime uma mensagem de erro e retorna NULL
        perror("Erro ao abrir arquivo de clientes");
        return NULL;
    }

    Cliente *clientes = NULL;   // Inicializa o ponteiro para clientes
    *num_clientes = 0;          // Inicializa o número de clientes   
    char linha[256];            // Buffer para ler cada linha do arquivo
    fgets(linha, sizeof(linha), arquivo); // Ler e descartar o cabeçalho

    while (fgets(linha, sizeof(linha), arquivo)) { // Lê cada linha do arquivo
        Cliente novo_cliente; // Inicializa um novo cliente
        // Lê os dados do cliente da linha e armazena em novo_cliente
        // O formato esperado é: id,nome,salario
        // Exemplo: 1,João,3000.00
        // O sscanf retorna o número de itens lidos com sucesso
        if (sscanf(linha, "%d,%[^,],%f", &novo_cliente.id, novo_cliente.nome, &novo_cliente.salario) == 3) {

            /* 
                ATENÇÃO: A função "realocar_memoria_cliente" deve ser implementada pelo aluno 
            */

            // Realoca memória para mais um cliente
            clientes = realocar_memoria_cliente(clientes, (*num_clientes + 1));

            // Verifica se a realocação foi bem-sucedida
            if (!clientes) {
                perror("Erro ao alocar memória para clientes");
                fclose(arquivo);
                return NULL;
            }
            // Adiciona o novo cliente ao array
            novo_cliente.historico_emprestimos = NULL; // Inicializa o histórico de empréstimos
            novo_cliente.num_emprestimos = 0; // Inicializa o número de empréstimos
            // Adiciona o novo cliente ao array de clientes
            // O ponteiro clientes é atualizado para apontar para o novo array
            clientes[*num_clientes] = novo_cliente;
            (*num_clientes)++; // Incrementa o número de clientes
        } else { // Se a leitura falhar, imprime uma mensagem de erro
            fprintf(stderr, "Erro ao ler linha do arquivo de clientes: %s", linha);
        }
    }

    fclose(arquivo);
    return clientes;
}


// Carrega os empréstimos do arquivo e associa aos clientes
// O número de empréstimos é retornado através do ponteiro num_emprestimos
// O arquivo deve ter o formato: cliente_id,valor_emprestimo,num_parcelas
// Exemplo: 1,1000.00,12
Emprestimo *carregar_emprestimos(const char *nome_arquivo, Cliente *clientes, int num_clientes) {
    FILE *arquivo = fopen(nome_arquivo, "r"); // Abre o arquivo para leitura
    if (!arquivo) { // Verifica se o arquivo foi aberto corretamente
        perror("Erro ao abrir arquivo de emprestimos");
        return NULL;
    }

    Emprestimo *todos_emprestimos = NULL;   // Inicializa o ponteiro para todos os empréstimos
    int num_emprestimos_total = 0;          // Inicializa o número total de empréstimos
    char linha[256];                        // Buffer para ler cada linha do arquivo
    fgets(linha, sizeof(linha), arquivo);   // Ler e descartar o cabeçalho

    while (fgets(linha, sizeof(linha), arquivo)) { // Lê cada linha do arquivo
        Emprestimo novo_emprestimo; // Inicializa um novo empréstimo
        // Lê os dados do empréstimo da linha e armazena em novo_emprestimo
        // O formato esperado é: cliente_id,valor_emprestimo,num_parcelas
        // Exemplo: 1,1000.00,12
        // O sscanf retorna o número de itens lidos com sucesso
        if (sscanf(linha, "%d,%f,%d", &novo_emprestimo.cliente_id, &novo_emprestimo.valor_emprestimo, &novo_emprestimo.num_parcelas) == 3) {

            /* 
                ATENÇÃO: A função "calcular_valor_parcela" deve ser implementada pelo aluno 
            */

            // Calcula o valor da parcela do empréstimo
            calcular_valor_parcela(&novo_emprestimo);   // Calcula o valor da parcela
            novo_emprestimo.ativo = 1;                  // Assume como ativo ao carregar

            // Busca o cliente correspondente ao ID do empréstimo
            // O cliente é buscado no array de clientes
            // Se o cliente for encontrado, aprova ou reprova o empréstimo
            // e adiciona ao histórico do cliente
            // Se o cliente não for encontrado, imprime uma mensagem de aviso
            // e não adiciona o empréstimo ao histórico
            Cliente *cliente = buscar_cliente_por_id(clientes, num_clientes, novo_emprestimo.cliente_id); // Busca o cliente
            // Se o cliente for encontrado, aprova ou reprova o empréstimo
            if (cliente) {

                /* 
                    ATENÇÃO: A função "aprovar_reprovar_emprestimo" deve ser implementada pelo aluno 
                */
                aprovar_reprovar_emprestimo(cliente, &novo_emprestimo);     // Aprova ou reprova o empréstimo
                adicionar_emprestimo_historico(cliente, novo_emprestimo);   // Adiciona o empréstimo ao histórico do cliente

                /* 
                    ATENÇÃO: A função "realocar_memoria_emprestimo" deve ser implementada pelo aluno 
                */
                todos_emprestimos = realocar_memoria_emprestimo(todos_emprestimos, (num_emprestimos_total + 1));

                if (!todos_emprestimos) {
                    perror("Erro ao alocar memória para todos os emprestimos");
                    fclose(arquivo);
                    return NULL;
                }
                todos_emprestimos[num_emprestimos_total] = novo_emprestimo;
                num_emprestimos_total++;
            } else {
                fprintf(stderr, "Aviso: Cliente com ID %d não encontrado para o empréstimo.\n", novo_emprestimo.cliente_id);
            }
        } else {
            fprintf(stderr, "Erro ao ler linha do arquivo de emprestimos: %s", linha);
        }
    }

    fclose(arquivo);
    return todos_emprestimos;
}


// Adiciona um novo empréstimo ao histórico do cliente
void adicionar_emprestimo_historico(Cliente *cliente, Emprestimo emprestimo) {

    /* 
        ATENÇÃO: A função "realocar_memoria_emprestimo" deve ser implementada pelo aluno
    */
    cliente->historico_emprestimos = realocar_memoria_emprestimo(cliente->historico_emprestimos, cliente->num_emprestimos + 1);

    // Verifica se a realocação foi bem-sucedida
    if (!cliente->historico_emprestimos) { // Se a realocação falhar, imprime uma mensagem de erro
        perror("Erro ao alocar memória para histórico de empréstimos");
        if (!cliente->historico_emprestimos) { // Se o histórico de empréstimos for NULL
            // Tenta alocar memória para o primeiro empréstimo
            perror("Erro ao alocar memória para histórico de empréstimos");
            if (cliente->num_emprestimos == 0) { // Se não houver empréstimos
                // Aloca memória para o primeiro empréstimo
                cliente->historico_emprestimos = malloc(sizeof(Emprestimo));
                if (!cliente->historico_emprestimos) {
                    perror("Erro crítico ao alocar memória para o primeiro empréstimo");
                    return;
                }
            } else {
                return; // Já existe memória alocada, erro ao realocar
            } 
        }       
    }
    // Adiciona o novo empréstimo ao histórico
    cliente->historico_emprestimos[cliente->num_emprestimos] = emprestimo;
    cliente->num_emprestimos++;
}

// Lista todos os clientes e seus empréstimos
void listar_clientes(const Cliente *clientes, int num_clientes) {
    system(LIMPAR_TELA);
    printf("\n--- Lista de Clientes ---\n");
    for (int i = 0; i < num_clientes; i++) { 

        printf("ID: %d, Nome: %s, Salário: %.2f, Empréstimos: %d\n",
               clientes[i].id, clientes[i].nome, clientes[i].salario, clientes[i].num_emprestimos);
        if (clientes[i].historico_emprestimos && clientes[i].num_emprestimos > 0) {
            printf("  Histórico de Empréstimos:\n");
            for (int j = 0; j < clientes[i].num_emprestimos; j++) {
                printf("    ID Cliente: %d, Valor: %.2f, Parcelas: %d, Parcela: %.2f, Status: ",
                       clientes[i].historico_emprestimos[j].cliente_id,
                       clientes[i].historico_emprestimos[j].valor_emprestimo,
                       clientes[i].historico_emprestimos[j].num_parcelas,
                       clientes[i].historico_emprestimos[j].valor_parcela);
                    
                    if (clientes[i].historico_emprestimos[j].aprovacao) {
                        printf("Aprovado");
                    } else {
                        printf(COR_VERMELHO "Reprovado" COR_RESET);
                    }

                    printf(", Ativo: %s\n", clientes[i].historico_emprestimos[j].ativo ? "Sim" : "Não");
            }
        } else {
            printf("  Sem histórico de empréstimos.\n");
        }
    }
    printf("-------------------------\n");
}

// Lista todos os empréstimos carregados
void listar_emprestimos(const Cliente *clientes, int num_clientes) {
    system(LIMPAR_TELA);
    printf("\n--- Lista de Empréstimos Carregados ---\n");
    int total_emprestimos = 0;
    for (int i = 0; i < num_clientes; i++) {
        total_emprestimos += clientes[i].num_emprestimos;
        if (clientes[i].historico_emprestimos) {
            for (int j = 0; j < clientes[i].num_emprestimos; j++) {
                printf("Cliente ID: %d, Valor: %.2f, Parcelas: %d, Parcela: %.2f, Status: ",
                       clientes[i].historico_emprestimos[j].cliente_id,
                       clientes[i].historico_emprestimos[j].valor_emprestimo,
                       clientes[i].historico_emprestimos[j].num_parcelas,
                       clientes[i].historico_emprestimos[j].valor_parcela);
                
                        if (clientes[i].historico_emprestimos[j].aprovacao) {
                            printf("Aprovado");
                        } else {
                            printf(COR_VERMELHO "Reprovado" COR_RESET);
                        }
                        printf(", Ativo: %s\n", clientes[i].historico_emprestimos[j].ativo ? "Sim" : "Não");
            }
        }
    }
    printf("Total de empréstimos carregados: %d\n", total_emprestimos);
    printf("---------------------------------------\n");
}

// Busca um cliente pelo ID
Cliente *buscar_cliente_por_id(Cliente *clientes, int num_clientes, int id) {
    for (int i = 0; i < num_clientes; i++) {
        if (clientes[i].id == id) {
            return &clientes[i];
        }
    }
    return NULL;
}

// Libera a memória alocada para os clientes e seus históricos de empréstimos
void liberar_memoria(Cliente *clientes, int num_clientes) {
    if (clientes) {
        for (int i = 0; i < num_clientes; i++) {
            free(clientes[i].historico_emprestimos);
        }
        free(clientes);
    }
}
