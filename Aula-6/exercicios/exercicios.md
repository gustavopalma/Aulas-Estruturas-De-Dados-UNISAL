# Lista de Exercícios – Estrutura de Dados

## Aula 6 – Listas Encadeadas

### Exercício 1 – Estrutura de um Nó (Teórico)

Considere a estrutura abaixo:

```c
typedef struct No
{
    int dado;
    struct No *proximo;
} No;
```

Explique:

* qual a função do campo `dado`;
* qual a função do ponteiro `proximo`;
* por que o ponteiro possui o tipo `struct No *`.

---

### Exercício 2 – Inserção no Início

Implemente uma função capaz de inserir um novo elemento no início de uma lista simplesmente encadeada.

Após cada inserção, exiba a lista completa.

---

### Exercício 3 – Inserção no Final

Implemente uma função para inserir elementos no final da lista.

Ao final, compare o algoritmo utilizado com o da inserção no início.

Qual deles percorre a lista?

---

### Exercício 4 – Busca Sequencial

Implemente uma função que receba um valor inteiro e retorne:

* o endereço do nó encontrado;
* ou `NULL`, caso o elemento não exista.

Caso o valor seja encontrado, exiba também sua posição na lista.

---

### Exercício 5 – Remoção

Implemente as seguintes funções:

```c
void removerInicio(No **inicio);

void removerFinal(No **inicio);

void removerValor(No **inicio, int valor);
```

Após cada remoção, exiba o conteúdo atualizado da lista.

---

### Exercício 6 – Estatísticas da Lista

Desenvolva funções capazes de determinar:

* quantidade de elementos;
* maior valor;
* menor valor;
* soma dos elementos;
* média dos elementos.

Todas as operações deverão percorrer a lista apenas uma vez.

---

### Exercício 7 – Lista Ordenada

Desenvolva uma função que mantenha a lista sempre ordenada em ordem crescente.

Cada novo elemento deverá ser inserido diretamente em sua posição correta, sem utilizar vetores auxiliares.

---

### Exercício 8 – Agenda Telefônica

Utilizando a estrutura abaixo:

```c
typedef struct Contato
{
    char nome[50];
    char telefone[20];

    struct Contato *proximo;
} Contato;
```

desenvolva um programa que permita:

* cadastrar contatos;
* buscar contatos pelo nome;
* remover contatos;
* listar todos os contatos.

Todos os registros deverão permanecer apenas em memória.

---

### Exercício 9 – Desafio

Desenvolva um programa capaz de unir duas listas simplesmente encadeadas.

Exemplo:

Lista 1

```text
10 → 20 → 30
```

Lista 2

```text
40 → 50 → 60
```

Resultado esperado

```text
10 → 20 → 30 → 40 → 50 → 60
```

A união deverá ocorrer apenas alterando ponteiros, sem copiar dados para uma nova lista.

---

### Exercício 10 – Projeto

Desenvolva um sistema para gerenciamento de uma lista de tarefas.

Cada tarefa deverá possuir:

```c
typedef struct Tarefa
{
    int id;
    char descricao[100];
    int concluida;

    struct Tarefa *proximo;
} Tarefa;
```

O sistema deverá permitir:

* cadastrar tarefas;
* listar tarefas;
* localizar uma tarefa pelo identificador;
* marcar uma tarefa como concluída;
* remover tarefas;
* liberar toda a memória antes de encerrar o programa.

---

## Desafio Extra

Pesquise e explique a diferença entre:

* Lista Simplesmente Encadeada;
* Lista Duplamente Encadeada;
* Lista Circular.

Apresente as vantagens e desvantagens de cada uma e indique situações em que cada estrutura pode ser utilizada.
