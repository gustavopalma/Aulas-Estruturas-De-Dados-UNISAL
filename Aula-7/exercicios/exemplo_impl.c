#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Musica
{
    char titulo[100];
    char artista[100];

    struct Musica *proximo;

} Musica;

/* Protótipos */

void adicionarInicio(Musica **playlist);
void adicionarFinal(Musica **playlist);

void listar(Musica *playlist);

void buscar(Musica *playlist);

void remover(Musica **playlist);

void liberar(Musica **playlist);

Musica *criarMusica();

int main()
{
    Musica *playlist = NULL;

    int opcao;

    do
    {
        printf("\n===== PLAYLIST =====\n");
        printf("1 - Adicionar no início\n");
        printf("2 - Adicionar no final\n");
        printf("3 - Listar músicas\n");
        printf("4 - Buscar música\n");
        printf("5 - Remover música\n");
        printf("0 - Sair\n");

        printf("\nOpção: ");
        scanf("%d",&opcao);

        getchar();

        switch(opcao)
        {
            case 1:

                adicionarInicio(&playlist);

                break;

            case 2:

                adicionarFinal(&playlist);

                break;

            case 3:

                listar(playlist);

                break;

            case 4:

                buscar(playlist);

                break;

            case 5:

                remover(&playlist);

                break;

        }

    }while(opcao != 0);

    liberar(&playlist);

    return 0;
}

Musica *criarMusica()
{
    Musica *nova = malloc(sizeof(Musica));

    if(nova == NULL)
    {
        printf("Erro de memória.\n");
        exit(1);
    }

    printf("Título : ");
    fgets(nova->titulo,100,stdin);

    nova->titulo[strcspn(nova->titulo,"\n")] = 0;

    printf("Artista: ");
    fgets(nova->artista,100,stdin);

    nova->artista[strcspn(nova->artista,"\n")] = 0;

    nova->proximo = NULL;

    return nova;
}

void adicionarInicio(Musica **playlist)
{
    Musica *nova = criarMusica();

    nova->proximo = *playlist;

    *playlist = nova;
}

void adicionarFinal(Musica **playlist)
{
    Musica *nova = criarMusica();

    if(*playlist == NULL)
    {
        *playlist = nova;
        return;
    }

    Musica *atual = *playlist;

    while(atual->proximo != NULL)
    {
        atual = atual->proximo;
    }

    atual->proximo = nova;
}

void listar(Musica *playlist)
{
    if(playlist == NULL)
    {
        printf("\nPlaylist vazia.\n");
        return;
    }

    printf("\nPLAYLIST\n\n");

    while(playlist != NULL)
    {
        printf("%s - %s\n",
               playlist->titulo,
               playlist->artista);

        playlist = playlist->proximo;
    }
}

void buscar(Musica *playlist)
{
    char titulo[100];

    printf("Título: ");

    fgets(titulo,100,stdin);

    titulo[strcspn(titulo,"\n")] = 0;

    while(playlist != NULL)
    {
        if(strcmp(playlist->titulo,titulo) == 0)
        {
            printf("\nEncontrada!\n");

            printf("%s\n",playlist->titulo);

            printf("%s\n",playlist->artista);

            return;
        }

        playlist = playlist->proximo;
    }

    printf("\nMúsica não encontrada.\n");
}

void remover(Musica **playlist)
{
    if(*playlist == NULL)
    {
        return;
    }

    char titulo[100];

    printf("Título: ");

    fgets(titulo,100,stdin);

    titulo[strcspn(titulo,"\n")] = 0;

    Musica *anterior = NULL;

    Musica *atual = *playlist;

    while(atual != NULL &&
          strcmp(atual->titulo,titulo) != 0)
    {
        anterior = atual;

        atual = atual->proximo;
    }

    if(atual == NULL)
    {
        printf("Música não encontrada.\n");
        return;
    }

    if(anterior == NULL)
    {
        *playlist = atual->proximo;
    }
    else
    {
        anterior->proximo = atual->proximo;
    }

    free(atual);

    printf("Música removida.\n");
}

void liberar(Musica **playlist)
{
    while(*playlist != NULL)
    {
        Musica *temp = *playlist;

        *playlist = (*playlist)->proximo;

        free(temp);
    }
}