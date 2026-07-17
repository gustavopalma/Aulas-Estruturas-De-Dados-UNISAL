#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 80

typedef struct Cliente {
    int senha;
    char nome[TAM_NOME];
    struct Cliente *proximo;
} Cliente;

typedef struct {
    Cliente *inicio;
    Cliente *fim;
    int proximaSenha;
} Fila;

void inicializarFila(Fila *fila);
int filaVazia(const Fila *fila);
void enqueue(Fila *fila, const char *nome);
int dequeue(Fila *fila, Cliente *atendido);
const Cliente *front(const Fila *fila);
void imprimirFila(const Fila *fila);
void liberarFila(Fila *fila);
void limparEntrada(void);
void removerNovaLinha(char *texto);

int main(void)
{
    Fila fila;
    int opcao = -1;
    inicializarFila(&fila);

    do {
        printf("\n========== FILA DE ATENDIMENTO ==========\n");
        printf("1 - Adicionar cliente\n");
        printf("2 - Atender proximo cliente\n");
        printf("3 - Consultar proximo cliente\n");
        printf("4 - Listar fila\n");
        printf("5 - Verificar se a fila esta vazia\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida.\n");
            limparEntrada();
            continue;
        }
        limparEntrada();

        switch (opcao) {
            case 1: {
                char nome[TAM_NOME];
                printf("Nome do cliente: ");
                if (fgets(nome, sizeof(nome), stdin) == NULL) {
                    printf("Erro ao ler o nome.\n");
                    break;
                }
                removerNovaLinha(nome);
                if (nome[0] == '\0') {
                    printf("O nome nao pode ficar vazio.\n");
                    break;
                }
                enqueue(&fila, nome);
                break;
            }
            case 2: {
                Cliente atendido;
                if (dequeue(&fila, &atendido)) {
                    printf("Atendendo senha %d - %s\n", atendido.senha, atendido.nome);
                }
                break;
            }
            case 3: {
                const Cliente *proximo = front(&fila);
                if (proximo != NULL) {
                    printf("Proximo: senha %d - %s\n", proximo->senha, proximo->nome);
                }
                break;
            }
            case 4:
                imprimirFila(&fila);
                break;
            case 5:
                printf("%s\n", filaVazia(&fila) ? "A fila esta vazia." : "A fila possui clientes.");
                break;
            case 0:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    liberarFila(&fila);
    return 0;
}

void inicializarFila(Fila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->proximaSenha = 1;
}

int filaVazia(const Fila *fila)
{
    return fila->inicio == NULL;
}

void enqueue(Fila *fila, const char *nome)
{
    Cliente *novo = malloc(sizeof(Cliente));
    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    novo->senha = fila->proximaSenha++;
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';
    novo->proximo = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }

    printf("Cliente inserido. Senha: %d\n", novo->senha);
}

int dequeue(Fila *fila, Cliente *atendido)
{
    if (filaVazia(fila)) {
        printf("A fila esta vazia.\n");
        return 0;
    }

    Cliente *removido = fila->inicio;

    if (atendido != NULL) {
        atendido->senha = removido->senha;
        strncpy(atendido->nome, removido->nome, sizeof(atendido->nome) - 1);
        atendido->nome[sizeof(atendido->nome) - 1] = '\0';
        atendido->proximo = NULL;
    }

    fila->inicio = removido->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(removido);
    return 1;
}

const Cliente *front(const Fila *fila)
{
    if (filaVazia(fila)) {
        printf("A fila esta vazia.\n");
        return NULL;
    }
    return fila->inicio;
}

void imprimirFila(const Fila *fila)
{
    if (filaVazia(fila)) {
        printf("A fila esta vazia.\n");
        return;
    }

    const Cliente *atual = fila->inicio;
    printf("\nInicio da fila\n");
    while (atual != NULL) {
        printf("Senha %d - %s\n", atual->senha, atual->nome);
        atual = atual->proximo;
    }
    printf("Fim da fila\n");
}

void liberarFila(Fila *fila)
{
    Cliente *atual = fila->inicio;
    while (atual != NULL) {
        Cliente *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
}

void limparEntrada(void)
{
    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF) { }
}

void removerNovaLinha(char *texto)
{
    texto[strcspn(texto, "\n")] = '\0';
}
