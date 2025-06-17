#include "grafo.h"

/**
 * @brief Cria um novo grafo com uma determinada quantidade de vértices.
 *
 * Aloca memória para a estrutura do grafo e inicializa as listas de adjacência de cada vértice como vazias.
 *
 * @param num_vertices Número de vértices do grafo a ser criado.
 * @return Ponteiro para o grafo criado.
 */
Grafo* criar_grafo(int num_vertices) {
    Grafo* grafo = (Grafo*) malloc(sizeof(Grafo));
    grafo->num_vertices = num_vertices;
    grafo->adj = (Elemento**) malloc(num_vertices * sizeof(Elemento*));
    for (int i = 0; i < num_vertices; i++)
        grafo->adj[i] = NULL;

    return grafo;
}

/**
 * @brief Adiciona uma aresta do vértice de origem ao vértice de destino no grafo.
 *
 * Esta função cria um novo elemento na lista de adjacência do vértice de origem,
 * representando uma aresta direcionada para o vértice de destino.
 *
 * @param grafo Ponteiro para a estrutura do grafo onde a aresta será adicionada.
 * @param origem Índice do vértice de origem da aresta.
 * @param destino Índice do vértice de destino da aresta.
 * @return Não retorna valor.
 */
void adicionar_aresta(Grafo* grafo, int origem, int destino) {
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    novo->vertice = destino;
    novo->prox = grafo->adj[origem];
    grafo->adj[origem] = novo;
}

/**
 * @brief Imprime a representação do grafo na forma de lista de adjacência.
 *
 * Esta função percorre todos os vértices do grafo e imprime, para cada vértice,
 * a lista de vértices adjacentes a ele. Cada linha corresponde a um vértice e
 * sua respectiva lista de adjacências, terminando com "NULL".
 *
 * @param grafo Ponteiro para a estrutura do grafo a ser impresso.
 */
void imprimir_grafo(Grafo* grafo) {
    for (int v = 0; v < grafo->num_vertices; v++) {
        printf(GREEN_TEXT "%d: " RESET_TEXT, v);
        Elemento* temp = grafo->adj[v];
        while (temp) {
            printf("%d -> ", temp->vertice);
            temp = temp->prox;
        }
        printf("NULL\n");
    }
}

/**
 * @brief Cria e inicializa uma nova pilha.
 *
 * Esta função aloca dinamicamente uma estrutura do tipo Pilha,
 * inicializando o ponteiro topo como NULL para indicar que a pilha está vazia.
 *
 * @return Um ponteiro para a nova pilha criada, ou NULL em caso de falha na alocação.
 */
Pilha* criar_pilha() {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    if (pilha != NULL)
        pilha->topo = NULL;
    
    pilha->tamanho = 0; // Inicializa o tamanho da pilha como 0
    return pilha;
}

/**
 * @brief Adiciona um novo vértice ao topo da pilha.
 *
 * Esta função aloca dinamicamente um novo elemento, define o valor do vértice,
 * ajusta o ponteiro para o próximo elemento e atualiza o topo da pilha.
 * Incrementa o tamanho da pilha ao adicionar o novo elemento.
 *
 * @param pilha Ponteiro para a estrutura da pilha.
 * @param vertice Valor do vértice a ser inserido na pilha.
 * @return int Retorna 1 em caso de sucesso e 0 em caso de falha (pilha nula ou falha na alocação).
 */
int push(Pilha* pilha, int vertice) {
    if(pilha == NULL) return 0;

    Elemento* novo_elemento = (Elemento*) malloc(sizeof(Elemento));
    if (novo_elemento == NULL) return 0; //Erro na alocação

    novo_elemento->vertice = vertice;
    novo_elemento->prox = pilha->topo;
    pilha->topo = novo_elemento;
    pilha->tamanho++;

    return 1;
}

/**
 * Remove e retorna o elemento do topo da pilha.
 *
 * @param pilha Ponteiro para a estrutura da pilha.
 * @return O valor do vértice removido do topo da pilha. Retorna 0 se a pilha estiver vazia ou for nula.
 */
int pop(Pilha* pilha) {
    if (pilha == NULL || pilha->topo == NULL) return 0;

    Elemento* elemento_removido = pilha->topo;
    int vertice = elemento_removido->vertice;
    pilha->topo = pilha->topo->prox;
    free(elemento_removido);
    pilha->tamanho--;
    

    return vertice;
}

/**
 * Verifica se a pilha está vazia.
 *
 * Esta função retorna verdadeiro se a pilha fornecida for nula ou se o topo da pilha for nulo,
 * indicando que não há elementos na pilha.
 *
 * @param pilha Ponteiro para a estrutura da pilha a ser verificada.
 * @return true se a pilha estiver vazia ou nula, false caso contrário.
 */
bool pilha_vazia(Pilha* pilha) {
    return (pilha == NULL || pilha->topo == NULL);
}

/**
 * @brief Libera toda a memória alocada para a pilha.
 *
 * Esta função percorre todos os elementos da pilha, liberando a memória
 * alocada para cada nó e, ao final, libera também a estrutura da pilha.
 * Caso o ponteiro para a pilha seja NULL, nada é feito.
 *
 * @param pi Ponteiro para a pilha a ser liberada.
 */
void libera_pilha(Pilha* pi){
    if(pi != NULL){
        Elemento* no;
        while(pi->topo != NULL){
            no = pi->topo;
            pi->topo = pi->topo->prox;
            free(no);
        }
        free(pi);
    }
}

/**
 * @brief Imprime os elementos da pilha na saída padrão.
 *
 * Esta função percorre a pilha a partir do topo e imprime cada elemento
 * no formato "[ valor ]", utilizando cores se definido. Caso a pilha esteja
 * vazia ou seja nula, imprime apenas "[ ]".
 *
 * @param pilha Ponteiro para a estrutura da pilha a ser impressa.
 */
void imprime_pilha(Pilha* pilha) {
    if (pilha == NULL || pilha->topo == NULL) {
        printf("[ ]");
        return;
    }

    Elemento* atual = pilha->topo;
    while (atual != NULL) {
        printf(GREEN_TEXT "[ %d ]" RESET_TEXT, atual->vertice);
        atual = atual->prox;
    }
    printf("\n");
}

/**
 * @brief Cria e inicializa uma nova fila.
 *
 * Esta função aloca dinamicamente uma estrutura do tipo Fila,
 * inicializando seus ponteiros de início e fim como NULL.
 *
 * @return Um ponteiro para a nova fila criada, ou NULL em caso de falha na alocação.
 */
Fila* criar_fila() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if(fila != NULL) {
        fila->inicio = NULL;
        fila->fim = NULL;
    }

    fila->tamanho = 0; // Inicializa o tamanho da fila como 0
    return fila;
}

/**
 * @brief Adiciona um vértice ao final da fila.
 *
 * Esta função insere um novo elemento contendo o vértice especificado
 * ao final da fila apontada por 'fila'. Caso a fila esteja vazia, o novo
 * elemento será o primeiro da fila. Caso contrário, ele será adicionado
 * após o último elemento atual. A função também atualiza o ponteiro para
 * o fim da fila e incrementa o tamanho.
 *
 * @param fila Ponteiro para a estrutura da fila onde o vértice será inserido.
 * @param vertice Valor do vértice a ser inserido na fila.
 * @return int Retorna 1 em caso de sucesso e 0 em caso de falha (por exemplo, fila nula ou falha de alocação).
 */
int enfileira(Fila* fila, int vertice){
    if(fila == NULL) return 0;

    Elemento* novo_elemento = (Elemento*) malloc(sizeof(Elemento));
    if(novo_elemento == NULL) return 0;

    novo_elemento->vertice = vertice;
    novo_elemento->prox = NULL;

    if(fila->fim == NULL){
        fila->inicio = novo_elemento;
        fila->fim = novo_elemento;
    }
    else{
        fila->fim->prox = novo_elemento; //Aponta o ultimo elemento para o novo ultimo, sinalizando que agora ele é o penultimo
        fila->fim = novo_elemento;
    }

    fila->tamanho++;

    return 1;
}

/**
 * @brief Remove e retorna o elemento do início da fila.
 *
 * Esta função desenfileira (remove) o primeiro elemento da fila, libera a memória
 * associada a este elemento e retorna o valor do vértice armazenado. Caso a fila esteja
 * vazia ou seja nula, retorna 0.
 *
 * @param fila Ponteiro para a estrutura da fila.
 * @return int Valor do vértice removido do início da fila, ou 0 se a fila estiver vazia ou nula.
 */
int desenfileira(Fila* fila){
    if(fila == NULL || fila->inicio == NULL) return 0;

    Elemento* elemento_removido = fila->inicio;
    int vertice = elemento_removido->vertice;
    fila->inicio = fila->inicio->prox;

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }
    free(elemento_removido);
    fila->tamanho--;

    return vertice;
}

/**
 * @brief Imprime os elementos de uma fila na tela.
 *
 * Esta função percorre a fila passada como parâmetro e imprime cada elemento (vértice)
 * no formato "[ valor ]". Caso a fila esteja vazia ou seja nula, imprime "[ ]".
 *
 * @param fila Ponteiro para a estrutura Fila a ser impressa.
 */
void imprime_fila(Fila* fila) {
    if (fila == NULL || fila->inicio == NULL) {
        printf("[ ]\n");
        return;
    }

    Elemento* atual = fila->inicio;
    while (atual != NULL) {
        printf(GREEN_TEXT "[ %d ]" RESET_TEXT, atual->vertice);
        atual = atual->prox;
    }
    printf("\n");
}

/**
 * @brief Verifica se uma fila está vazia.
 *
 * Esta função retorna verdadeiro se a fila fornecida for nula ou se o ponteiro para o início da fila for nulo,
 * indicando que não há elementos na fila.
 *
 * @param fila Ponteiro para a estrutura da fila a ser verificada.
 * @return true se a fila estiver vazia ou nula, false caso contrário.
 */
bool fila_vazia(Fila* fila) {
    return (fila == NULL || fila->inicio == NULL);
}

/**
 * @brief Libera toda a memória alocada para uma fila.
 *
 * Esta função percorre todos os elementos da fila, liberando a memória
 * alocada para cada nó, e por fim libera a estrutura da fila em si.
 * Caso o ponteiro passado seja NULL, nada é feito.
 *
 * @param fila Ponteiro para a estrutura da fila a ser liberada.
 */
void libera_fila(Fila* fila){
    if(fila != NULL){
        Elemento *aux;
        while(fila->inicio != NULL){
            aux = fila->inicio;
            fila->inicio = fila->inicio->prox;
            free(aux);
        }
        free(fila);
    }
}

/**
 * @brief Realiza a busca em profundidade (DFS) em um grafo a partir de um vértice inicial.
 *
 * Esta função executa o algoritmo de busca em profundidade (Depth-First Search) utilizando uma pilha
 * para percorrer os vértices do grafo representado por lista de adjacência. Ela imprime a ordem em que
 * os vértices são visitados a partir do vértice inicial fornecido.
 *
 * @param grafo Ponteiro para a estrutura do grafo.
 * @param vertice_inicial Índice do vértice a partir do qual a busca será iniciada.
 *
 * @note A função aloca memória dinamicamente para o vetor de visitados e para a pilha, 
 * liberando-os ao final.
 */
void DFS(Grafo* grafo, int vertice_inicial) {
    bool* visitado = (bool*) malloc(grafo->num_vertices * sizeof(bool));
    for (int i = 0; i < grafo->num_vertices; i++) {
        visitado[i] = false;
    }

    Pilha* pilha = criar_pilha(grafo->num_vertices);

    printf(BLUE_TEXT "\nBusca em Profundidade (DFS) a partir do vértice %d:\n" RESET_TEXT, vertice_inicial);

    push(pilha, vertice_inicial);
    imprime_pilha(pilha);
    visitado[vertice_inicial] = true;

    while (!pilha_vazia(pilha)) {
        int vertice_atual = pop(pilha);
        printf("Vertice atual: %d\n", vertice_atual);
        imprime_pilha(pilha);

        Elemento* vizinho = grafo->adj[vertice_atual];
        while (vizinho) {
            if (!visitado[vizinho->vertice]) {
                visitado[vizinho->vertice] = true;
                push(pilha, vizinho->vertice);
                imprime_pilha(pilha);
            }
            vizinho = vizinho->prox;
        }
    }
    printf("\n");

    libera_pilha(pilha);
    free(visitado);
}

/**
 * @brief Realiza a busca em largura (BFS) em um grafo a partir de um vértice inicial.
 *
 * Esta função percorre todos os vértices alcançáveis a partir do vértice inicial
 * utilizando o algoritmo de busca em largura (BFS). Durante o percurso, imprime
 * a ordem em que os vértices são visitados.
 *
 * @param grafo Ponteiro para a estrutura do grafo.
 * @param vertice_inicial Índice do vértice a partir do qual a busca será iniciada.
 *
 * @note A função assume que as funções auxiliares criar_fila, enfileira, desenfileira,
 * fila_vazia, libera_fila e as estruturas Grafo, Fila e Elemento estão corretamente implementadas.
 */
void BFS(Grafo* grafo, int vertice_inicial) {
    bool* visitado = (bool*) malloc(grafo->num_vertices * sizeof(bool));
    for (int i = 0; i < grafo->num_vertices; i++) {
        visitado[i] = false;
    }

    Fila* fila = criar_fila(grafo->num_vertices);

    printf(BLUE_TEXT "\n\nBusca em Largura (BFS) a partir do vértice %d:\n" RESET_TEXT, vertice_inicial);

    enfileira(fila, vertice_inicial);
    imprime_fila(fila);
    visitado[vertice_inicial] = true;

    while (!fila_vazia(fila)) {
        int vertice_atual = desenfileira(fila);
        printf("Vertice atual: %d\n", vertice_atual);
        imprime_fila(fila);

        Elemento* vizinho = grafo->adj[vertice_atual];
        while (vizinho) {
            if (!visitado[vizinho->vertice]) {
                visitado[vizinho->vertice] = true;
                enfileira(fila, vizinho->vertice);
                imprime_fila(fila);
            }
            vizinho = vizinho->prox;
        }
    }
    printf("\n");

    libera_fila(fila);
    free(visitado);
}