#include <stdio.h>
#include <malloc.h> //locação dinamica de memoria, e vai precisar liberar memoria também.
// Estrutura do No
typedef struct
{
    struct No *prox;
    int chave;
} No;

// Estrutura da fila
struct fila {
    No* inicio;
    No* fim;
};
typedef struct fila FILA;   

// criar uma fila
FILA* criar() {
    FILA* f = (FILA*)malloc(sizeof(FILA));   // aloca espaço em memoria
    f->inicio = NULL;  // inicializa o inicio como NULL
    f->fim = NULL;  //// inicializa o fim como NULL
    return f;
}
void insere (FILA* f, int v) {  //metodo para inserir um novo elemento na fila
    No* novo = (No*)malloc(sizeof(No));  // aloca espaço em memoria
    novo->chave = v;  //aponta um novo elemento para uma chave
    novo->prox= NULL;  //apontando o proximo como NULL
    
    if (f->fim==NULL) {  //se o fim for = a NULL
       f->inicio = novo;  //fila é adicionada no inicio
    }
    else {
        f->fim->prox = novo; //senão o novo elemento será inserido pelo fim
        
    }
    f->fim = novo; //o novo elemento passa a ser o fim
}
void remover(FILA* f) {   //metodo para remover um novo elemento na fila
    No* t;

    if (f->inicio == NULL) {   //se o inicio da fila for null, printa fila vazia
        printf("Fila vazia\n");
        exit(1);
    }
    t = f->inicio;    //apontando o inicio para t (end memoria)
    f->inicio = t->prox; //apontando o inicio para o proximo

    if (f->inicio == NULL) {
        f->fim = NULL;    // se inicio é NULL o fim tambem será NULL
    }
    free(t);

}
// Imprime a fila
void imprime(No *fila)
{
    fila = fila->prox;  // fila aponta para o proximo
    while (fila != NULL) // enquanto o endereço for diferente de NULL imprime a chave do elemento atualizado
    {
        printf("\n%d\n", fila->chave); // printa o valor que está na fila
        fila = fila->prox;
    }
}
/* Função para liberar a fila,
essa função serve para destruir todos os elementos da fila e liberar
a memória ocupada.*/
void fila_libera(FILA* f){
    No* aux = f->inicio;
    while(aux != NULL){
        No* aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(f);
}
int main()
{
    int n, k, c, q;
    FILA *lista=criar();
    do
    {
        printf("\n\nOpcoes: \n1 -> Inserir novo elemento na Fila;\n2 -> Remover elemento na Fila;\n3 -> Imprimir Fila;\n4 -> Para limpar a Fila da memoria/apagar; \n5 -> Sair\n:");
        scanf("%d", &q); /* Le a opcao do usuario */
        switch (q)
        {
        case 1:
            printf("Gostaria de inserir quantos elementos na Fila:\n");
            scanf("%d", &n);
            printf("Digite %d Inteiros\n", n);
            for (c = 0; c < n; c++)
            {
                scanf("%d", &k);
                insere(lista, k);;
            }
            break;
        case 2:
            remover(lista);
            break;
        case 3:
            imprime(lista);
            break;
        case 4:
            fila_libera(lista);
            criar();
            break;
        case 5:
            break;
        default:
            printf("\n\n Opcao nao valida");
        }
    } while (q != 5);

    system("pause");
    return 0;
}