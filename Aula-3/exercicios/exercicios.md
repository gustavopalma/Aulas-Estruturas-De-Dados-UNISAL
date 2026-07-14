# Exercício Prático – Gerador de Cartelas de Bingo

## Objetivo

Desenvolver um programa em linguagem C capaz de gerar automaticamente cartelas de bingo, respeitando as regras do jogo.

Durante o desenvolvimento deste exercício deverão ser utilizados os conceitos estudados até o momento, incluindo vetores, matrizes, strings, funções e enumerações.

---

## Regras da Cartela

Cada cartela deverá possuir **5 linhas** e **5 colunas**, correspondentes às letras da palavra **BINGO**.

Cada coluna deverá conter apenas números pertencentes à sua faixa de valores.

| Coluna | Faixa de valores |
| :----: | :--------------: |
|    B   |      1 a 15      |
|    I   |      16 a 30     |
|    N   |      31 a 45     |
|    G   |      46 a 60     |
|    O   |      61 a 75     |

A posição central da cartela (linha 3, coluna 3) deverá ser considerada um espaço livre e poderá ser representada pelo valor **0**.

Nenhum número poderá se repetir dentro de uma mesma coluna.

---

## Requisitos Obrigatórios

O programa deverá:

* Gerar uma ou mais cartelas de bingo.
* Utilizar uma matriz para armazenar os números de cada cartela.
* Utilizar uma enumeração (`enum`) para representar as colunas **B**, **I**, **N**, **G** e **O**.
* Utilizar funções para dividir o programa em módulos menores.
* Exibir as cartelas de forma organizada no terminal.

---

## Organização do Programa

Sugere-se dividir o programa em funções semelhantes às apresentadas abaixo.

```c
int gerarNumero(int minimo, int maximo);

int numeroExiste(int cartela[5][5], int coluna, int numero);

void gerarCartela(int cartela[5][5]);

void imprimirCartela(int cartela[5][5]);
```

Outras funções poderão ser criadas sempre que forem consideradas necessárias.

---

## Exemplo de Saída

```text
 B    I    N    G    O

 5   18   35   50   63
10   21   40   54   66
13   24    X   58   70
14   27   42   59   72
15   30   45   60   75
```

---

## Desafios

Após concluir o exercício principal, implemente os seguintes recursos adicionais.

### Desafio 1

Permita que o usuário informe quantas cartelas deverão ser geradas.

---

### Desafio 2

Armazene todas as cartelas em uma matriz tridimensional.

```c
int cartelas[QUANTIDADE][5][5];
```

---

### Desafio 3

Utilize uma estrutura (`struct`) para representar uma cartela.

Exemplo:

```c
typedef struct
{
    int numeros[5][5];
} Cartela;
```

Nesse caso, o programa poderá armazenar um vetor de cartelas.

```c
Cartela cartelas[10];
```

---

### Desafio 4

Ordene os números de cada coluna em ordem crescente.

---

### Desafio 5

Garanta que duas cartelas geradas não sejam idênticas.

---

## Critérios de Avaliação

Serão considerados os seguintes aspectos:

* Organização do código.
* Utilização correta de funções.
* Correta utilização de vetores e matrizes.
* Utilização adequada da enumeração.
* Legibilidade do código.
* Correto funcionamento do programa.
* Criatividade na implementação dos desafios propostos.
