#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

typedef struct no
{
    int chave;
    struct No *esquerda, *direita;
} No;

typedef struct
{
    No *raiz;
} ArvoreBin;

ArvoreBin *criarArvore()
{
    ArvoreBin *arvore = (ArvoreBin *)malloc(sizeof(ArvoreBin));
    arvore->raiz = NULL;
    return arvore;
}

No *criarNo(int item)
{
    No *temp = (No *)malloc(sizeof(No));
    temp->chave = item;
    temp->esquerda = temp->direita = NULL;
    return temp;
}

void *busca(No *raiz, int chave)
{
    if (raiz == NULL)
    {
        return NULL;
    }
    else if (raiz->chave == chave)
    {
        return chave;
    }
    else if (chave <= raiz->chave)
    {
        return busca(raiz->esquerda, chave);
    }
    else
    {
        return busca(raiz->direita, chave);
    }
}

void *inserir(No *no, int chave)
{

    if (no == NULL)
        return criarNo(chave);

    if (chave < no->chave)
        no->esquerda = inserir(no->esquerda, chave);
    else if (chave > no->chave)
        no->direita = inserir(no->direita, chave);

    return no;
}
void emOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        emOrdem(raiz->esquerda);
        printf("Em: %d \n", raiz->chave);
        emOrdem(raiz->direita);
    }
}

void preOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        printf("Pre: %d \n", raiz->chave);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}
void posOrdem(No *raiz)
{
    if (raiz != NULL)
    {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("Pos: %d \n", raiz->chave);
    }
}
void *valorminimoNo(No *no)
{
    No *atual = no;

    while (atual->esquerda != NULL)
        atual = atual->esquerda;

    return atual;
}
void *valormaximoNo(No *no)
{
    No *atual = no;

    while (atual->direita != NULL)
        atual = atual->direita;

    return atual;
}

void *deletarNo(No *raiz, int chave)
{
    if (raiz == NULL)
        return raiz;

    if (chave < raiz->chave)
        raiz->esquerda = deletarNo(raiz->esquerda, chave);

    else if (chave > raiz->chave)
        raiz->direita = deletarNo(raiz->direita, chave);

    else
    {

        if (raiz->esquerda == NULL)
        {
            No *temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL)
        {
            No *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        No *temp = valorminimoNo(raiz->direita);

        raiz->chave = temp->chave;

        raiz->direita = deletarNo(raiz->direita, temp->chave);
    }
    return raiz;
}

int altura(No *no)
{
    if (no == NULL)
    {
        return -1;
    }

    else
    {
        return 1 + MAX(altura(no->esquerda), altura(no->direita));
    }
}

int main()
{

    /*
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    ArvoreBin *arvore = criarArvore();
    No *raiz = NULL;
    int resultado_busca, n, k, c, q;

    do
    {
        printf("\n\nOpcoes: \n1 -> Inserir novo elemento na arvore;\n2 -> Remover um elemento da arvore;\n3 -> Buscar um elemento na arvore;\n4 -> Preordem; \n5 -> Emordem;  \n6 -> Posordem; \n7 -> Altura da arvore; \n8 -> Para Sair \n:");
        scanf("%d", &q); /* Le a opcao do usuario */
        switch (q)
        {
        case 1:
            printf("Gostaria de inserir quantos elementos na arvore:\n");
            scanf("%d", &n);
            printf("Digite %d Inteiros\n", n);
            for (c = 0; c < n; c++)
            {
                scanf("%d", &k);
                raiz=inserir(raiz, k);
            }
            break;
        case 2:
            printf("Gostaria de remover quantos elementos da arvore:\n");
            scanf("%d", &n);
            printf("Digite %d Inteiros\n", n);
            for (c = 0; c < n; c++)
            {
                scanf("%d", &k);
                deletarNo(raiz, k);
            }
            break;

        case 3:
            printf("Gostaria de buscar quantos elementos da arvore:\n");
            scanf("%d", &n);
            printf("Digite os elementos a serem buscados\n", n);
            for (c = 0; c < n; c++)
            {
                scanf("%d", &k);
                resultado_busca = busca(raiz, k);
                if (resultado_busca == 0)
                {
                    printf("Numero nao encontrado\n");
                }
                else
                {
                    printf("\nNumero encontrado na arvore:%d", resultado_busca);
                }
            }
            break;

        case 4:
            preOrdem(raiz);
            break;
        case 5:
            emOrdem(raiz);
            break;
        case 6:
            posOrdem(raiz);
            break;
        case 7:
            printf("tamanho da altura: %d\n", altura(raiz));
            break;
        case 8:
            break;
        default:
            printf("\n\n Opcao nao valida");
        }
    } while (q != 8);

    system("pause");
    return 0;
}