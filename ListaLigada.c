#include <stdio.h>
#include <malloc.h> //locação dinamica de memoria, e vai precisar liberar memoria também.
// Estrutura do No
typedef struct
{
    struct No *prox;
    int chave;
} No;

// Estrutura da Lista vazia
typedef struct
{
    No *ini;
    No* fim;
    int tam;
} LISTA;

// Cria uma lista
LISTA *criaLista()
{
    LISTA *lista = (LISTA *)malloc(sizeof(LISTA)); // aloca espaço em memoria
    lista->ini = NULL;                             // inicializa a lista como NULL
    lista->fim = NULL;                              // inicializa a lista como NULL
    lista->tam = 0;                                // define o tam da lista como 0
    return lista;
}
// Cria um No
No *criaNo(int chave)
{
    No *no = (No *)malloc(sizeof(No)); // aloca espaço em memoria
    no->prox = NULL;
    no->chave = chave;

    return no;
}
// Imprime a lista
void imprime(No *lista)
{
    lista = lista->prox;  // lista aponta para o proximo
    while (lista != NULL) // enquanto o endereço for diferente de NULL imprime a chave do elemento atualizado
    {
        printf("\n%d\n", lista->chave); // printa o valor que está na lista
        lista = lista->prox;
    }
}
int tamanho(LISTA *l)
{
    printf("Tamanho da lista: %d\n", l->tam);
    return l->tam;
}
void removerInicio(LISTA* lista) {   //metodo para remover um novo elemento na lista
    No* t;

    if (lista->ini == NULL) {   //se o inicio da fila for null, printa lista vazia
        printf("Lista vazia\n");
        exit(1);
    }
    t = lista->ini;    //apontando o inicio para t (end memoria)
    lista->ini= t->prox; //apontando o inicio para o proximo

    if (lista->ini == NULL) {
        lista->fim = NULL;    // se inicio é NULL o fim tambem será NULL
    }
    free(t);
    lista->tam--;
}
void removerFim(LISTA *lista){ //metodo para remover um elemento no fim da lista
    if(lista->ini != NULL){    //inicio for diferente de NULL
        No* aux = lista->ini;  //inicio da lista
        No* ant;    
        while (aux->prox != NULL){ //enquanto o prox for diferente de NULL
            ant = aux;  //atribui o valor do auxiliar no anterior
            aux = aux->prox;  //prox vai ser atribuido ao auxiliar
        }
        ant->prox = NULL;  //anterior aponta o prox pra NULL
        free(aux);
        lista->tam--;
    }
}

void *remover(LISTA *l, int valor)
{
    No *anterior = NULL; // ponteiro para o elemento anterior
    No *aux = l;         // ponteiro para percorrer a lista
    // procura o elemento na lista, guardando o elemento anterior
    while (aux != NULL && aux->chave != valor)
    {
        anterior = aux;
        aux = aux->prox;
    }
    // verifica se achou o elemento
    if (aux == NULL)
        return l; // não achou, retorna a lista original
                  // retira elemento
    if (anterior == NULL)
    {
        l = aux->prox; // caso 1
    }
    else
    {
        anterior->prox = aux->prox; // caso 2
    }
    free(aux); // liberar espaço da memoria
    l->tam--;
}
void InserirInicio(LISTA *lista, int chave) // inserir elemento no inicio da lista
{
    if (lista != NULL) // se o endereço for diferente de NULL imprime a chave do elemento atualizado
    {
        No *novo = criaNo(chave); // cria um novo no
        novo->prox = lista->ini;  // lista aponta para inicio, que atribui isso para o novo que aponta para o proximo
        lista->ini = novo;        // novo no atribui para inicio
        lista->tam++;
    }
}
void InserirFim (LISTA* lista, int v) {  //metodo para inserir um novo elemento na lista
    No* novo = (No*)malloc(sizeof(No));  // aloca espaço em memoria
    novo->chave = v;  //aponta um novo elemento para uma chave
    novo->prox= NULL;  //apontando o proximo como NULL
    
    if (lista->fim==NULL) {  //se o fim for = a NULL
       lista->ini = novo;  //lista é adicionada no inicio
    }
    else {
        lista->fim->prox = novo; //senão o novo elemento será inserido pelo fim
        
    }
    lista->fim = novo; //o novo elemento passa a ser o fim
    lista->tam++;
}
/* Função para liberar a lista,
essa função serve para destruir todos os elementos da lista e liberar
a memória ocupada.*/
void liberar(LISTA *l)
{
    No *aux = l;

    while (aux != NULL)
    {
        No *proximo = aux->prox;
        free(aux); // liberar espaço da memoria
        aux = proximo;
    }
    l->ini= NULL;
    l->fim= NULL; 
}
int main()
{
    int n, k, c, q;
    LISTA *lista = criaLista();

    // printf("Tamanho da lista: %d\n\n", tamanho(lista));
    do
    {
        printf("\n\nOpcoes: \n1 -> Inserir novo No no inicio da Lista;\n2 -> Inserir novo No no final da Lista;\n3 -> Para remover os elementos da lista;\n4 -> Remover No no inicio da Lista; \n5 -> Remover No no Final da Lista;  \n6 -> Para limpar a lista da memoria/apagar; \n7 -> Para exibir lista \n8 -> Para exibir o tamanho da lista; \n9 -> Para Sair \n:");
        scanf("%d", &q); /* Le a opcao do usuario */
        switch (q)
        {
        case 1:
            printf("Gostaria de inserir quantos elementos na lista:\n");
            scanf("%d", &n);
            printf("Digite %d Inteiros\n", n);
            for (c = 0; c < n; c++)
            {
                scanf("%d", &k);
                InserirInicio(lista, k);
            }
            break;
        case 2:
            printf("Gostaria de inserir quantos elementos na lista:\n");
            scanf("%d", &n);
            printf("Digite %d Inteiros\n", n);
            for (c = 0; c < n; c++)
            {
                scanf("%d", &k);
                InserirFim(lista, k);
            }
            break;
        case 3:
            printf("Gostaria de remover quantos elementos na lista:\n");
            scanf("%d", &n);
            printf("Digite os elementos a serem removidos:\n");
            for (c = 0; c < n; c++)
            {
                scanf("%d", &k);
                remover(lista,k);
            }
            break;
        case 4:
            removerInicio(lista);
            break;
        case 5:
            removerFim(lista);
            break;
        case 6:
            liberar(lista);
            break;
        case 7:
            imprime(lista);
            break;
        case 8:
            tamanho(lista);
            break;
        case 9:
            break;
        default:
            printf("\n\n Opcao nao valida");
        }
    } while (q != 9);

    system("pause");
    return 0;
}