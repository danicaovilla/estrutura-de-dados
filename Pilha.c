#include <stdio.h>
#include <malloc.h> //locação dinamica de memoria, e vai precisar liberar memoria também.
// Estrutura do No
typedef struct
{
    struct No *prox;
    int chave;
} No;

// Estrutura da pillha
struct pilha {
    No* topo;
};
typedef struct pilha PILHA;   

// criar uma pilha
PILHA* criar() {
    PILHA* p = (PILHA*)malloc(sizeof(PILHA));     // aloca espaço em memoria
    p->topo = NULL;   // inicializa a pilha como NULL
    return p;

}
void push (PILHA *p, int v) {    //metodo para inserir um novo elemento na pillha
    No* novo = (No*)malloc(sizeof(No));      // aloca espaço em memoria
    novo->chave = v;         //aponta um novo elemento para uma chave
    novo->prox= p->topo;//o elemento novo esta apontando para o proximo(que era o topo da pilha ate então)
    p->topo = novo;   //apontando o novo elemento adicionado ao topo
}

void pop (PILHA* p) {   //metodo para remover um novo elemento na pillha
    No* t;

    if (p->topo == NULL) {     //se o topo da pilha for null, printa pilha vazia
        printf("Pilha vazia");
        exit(1);
    }
    t = p->topo;    //apontando o topo para t (end memoria)
    p->topo = t->prox;  //apontando o topo para o proximo
    free(t);
}

// Imprime a pilha
void imprime(No *pilha)
{
    pilha = pilha->prox;  // pilha aponta para o proximo
    while (pilha != NULL) // enquanto o endereço for diferente de NULL imprime a chave do elemento atualizado
    {
        printf("\n%d\n", pilha->chave); // printa o valor que está na pilha
        pilha = pilha->prox;
    }
}

/* Função para liberar a pilha,
essa função serve para destruir todos os elementos da lista e liberar
a memória ocupada.*/
void pilha_libera(PILHA* p){
    No* aux = p->topo;
    while(aux != NULL){
        No* aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(p);
}
int main()
{
    int n, k, c, q;
    PILHA *lista=criar();
    do
    {
        printf("\n\nOpcoes: \n1 -> Inserir novo elemento na Pilha;\n2 -> Remover elemento na Pilha;\n3 -> Imprimir Pilha;\n4 -> Para limpar a pilha da memoria/apagar; \n5 -> Sair\n:");
        scanf("%d", &q); /* Le a opcao do usuario */
        switch (q)
        {
        case 1:
            printf("Gostaria de inserir quantos elementos na Pilha:\n");
            scanf("%d", &n);

            printf("Digite %d Inteiros\n", n);

            for (c = 0; c < n; c++)
            {
                scanf("%d", &k);
                push(lista, k);;
            }
            break;
        case 2:
            pop(lista);
            break;
        case 3:
            imprime(lista);
            break;
        case 4:
            pilha_libera(lista);
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