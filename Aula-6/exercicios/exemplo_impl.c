#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *proximo;
} No;

/* Protótipos */
No *criarNo(int valor);

void inserirInicio(No **inicio, int valor);
void inserirFinal(No **inicio, int valor);

void removerInicio(No **inicio);
void removerFinal(No **inicio);
void removerPosicao(No **inicio, int posicao);
void removerValor(No **inicio, int valor);

No *buscarValor(No *inicio, int valor);

void imprimirLista(const No *inicio);
void liberarLista(No **inicio);

int main(void)
{
    No *inicio = NULL;

    int opcao;
    int valor;
    int posicao;

    do
    {
        printf("\n===== LISTA ENCADEADA =====\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no final\n");
        printf("3 - Remover do inicio\n");
        printf("4 - Remover do final\n");
        printf("5 - Remover por posicao\n");
        printf("6 - Remover por valor\n");
        printf("7 - Buscar valor\n");
        printf("8 - Imprimir lista\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1)
        {
            printf("Entrada invalida.\n");

            while (getchar() != '\n')
            {
                /* Limpa a entrada */
            }

            continue;
        }

        switch (opcao)
        {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);

                inserirInicio(&inicio, valor);
                break;

            case 2:
                printf("Digite o valor: ");
                scanf("%d", &valor);

                inserirFinal(&inicio, valor);
                break;

            case 3:
                removerInicio(&inicio);
                break;

            case 4:
                removerFinal(&inicio);
                break;

            case 5:
                printf("Digite a posicao: ");
                scanf("%d", &posicao);

                removerPosicao(&inicio, posicao);
                break;

            case 6:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);

                removerValor(&inicio, valor);
                break;

            case 7:
            {
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);

                No *resultado = buscarValor(inicio, valor);

                if (resultado != NULL)
                {
                    printf("Valor encontrado no endereco %p.\n",
                           (void *) resultado);
                }
                else
                {
                    printf("Valor nao encontrado.\n");
                }

                break;
            }

            case 8:
                imprimirLista(inicio);
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    liberarLista(&inicio);

    return 0;
}

No *criarNo(int valor)
{
    No *novo = malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        exit(EXIT_FAILURE);
    }

    novo->dado = valor;
    novo->proximo = NULL;

    return novo;
}

void inserirInicio(No **inicio, int valor)
{
    No *novo = criarNo(valor);

    novo->proximo = *inicio;
    *inicio = novo;

    printf("Valor inserido no inicio.\n");
}

void inserirFinal(No **inicio, int valor)
{
    No *novo = criarNo(valor);

    if (*inicio == NULL)
    {
        *inicio = novo;
        printf("Valor inserido no final.\n");
        return;
    }

    No *atual = *inicio;

    while (atual->proximo != NULL)
    {
        atual = atual->proximo;
    }

    atual->proximo = novo;

    printf("Valor inserido no final.\n");
}

void removerInicio(No **inicio)
{
    if (*inicio == NULL)
    {
        printf("A lista esta vazia.\n");
        return;
    }

    No *temp = *inicio;

    *inicio = (*inicio)->proximo;

    printf("Valor %d removido.\n", temp->dado);

    free(temp);
}

void removerFinal(No **inicio)
{
    if (*inicio == NULL)
    {
        printf("A lista esta vazia.\n");
        return;
    }

    if ((*inicio)->proximo == NULL)
    {
        printf("Valor %d removido.\n", (*inicio)->dado);

        free(*inicio);
        *inicio = NULL;

        return;
    }

    No *anterior = NULL;
    No *atual = *inicio;

    while (atual->proximo != NULL)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = NULL;

    printf("Valor %d removido.\n", atual->dado);

    free(atual);
}

void removerPosicao(No **inicio, int posicao)
{
    if (*inicio == NULL)
    {
        printf("A lista esta vazia.\n");
        return;
    }

    if (posicao < 0)
    {
        printf("Posicao invalida.\n");
        return;
    }

    if (posicao == 0)
    {
        removerInicio(inicio);
        return;
    }

    No *anterior = NULL;
    No *atual = *inicio;

    int indice = 0;

    while (atual != NULL && indice < posicao)
    {
        anterior = atual;
        atual = atual->proximo;

        indice++;
    }

    if (atual == NULL)
    {
        printf("Posicao inexistente.\n");
        return;
    }

    anterior->proximo = atual->proximo;

    printf("Valor %d removido da posicao %d.\n",
           atual->dado,
           posicao);

    free(atual);
}

void removerValor(No **inicio, int valor)
{
    if (*inicio == NULL)
    {
        printf("A lista esta vazia.\n");
        return;
    }

    if ((*inicio)->dado == valor)
    {
        removerInicio(inicio);
        return;
    }

    No *anterior = *inicio;
    No *atual = (*inicio)->proximo;

    while (atual != NULL && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL)
    {
        printf("Valor nao encontrado.\n");
        return;
    }

    anterior->proximo = atual->proximo;

    printf("Valor %d removido.\n", atual->dado);

    free(atual);
}

No *buscarValor(No *inicio, int valor)
{
    No *atual = inicio;

    while (atual != NULL)
    {
        if (atual->dado == valor)
        {
            return atual;
        }

        atual = atual->proximo;
    }

    return NULL;
}

void imprimirLista(const No *inicio)
{
    if (inicio == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    const No *atual = inicio;

    printf("\nInicio -> ");

    while (atual != NULL)
    {
        printf("[%d] -> ", atual->dado);
        atual = atual->proximo;
    }

    printf("NULL\n");
}

void liberarLista(No **inicio)
{
    while (*inicio != NULL)
    {
        No *temp = *inicio;

        *inicio = (*inicio)->proximo;

        free(temp);
    }

    printf("Memoria da lista liberada.\n");
}