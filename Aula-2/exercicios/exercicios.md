# Lista de Exercícios – Estrutura de Dados

## Aula 2 – Vetores, Matrizes, Strings e Funções

### Exercício 1 – Vetores (Básico)

Escreva um programa que leia 10 números inteiros e:

* armazene-os em um vetor;
* exiba os valores na ordem em que foram digitados;
* exiba os valores na ordem inversa.

---

### Exercício 2 – Estatísticas de um Vetor

Escreva um programa que leia 20 números inteiros e determine:

* o maior valor;
* o menor valor;
* a média dos elementos;
* a quantidade de números pares;
* a quantidade de números ímpares.

Utilize um único vetor para armazenar os dados.

---

### Exercício 3 – Busca em Vetores

Escreva um programa que:

1. leia um vetor com 15 números inteiros;
2. solicite ao usuário um número para pesquisa;
3. informe se o número foi encontrado;
4. caso exista, informe sua posição no vetor.

---

### Exercício 4 – Soma de Matrizes

Escreva um programa que leia duas matrizes 3 × 3 e gere uma terceira matriz contendo a soma dos elementos correspondentes.

Ao final, exiba as três matrizes.

---

### Exercício 5 – Maior Elemento da Matriz

Escreva um programa que leia uma matriz 5 × 5 e determine:

* o maior elemento;
* sua linha;
* sua coluna.

---

### Exercício 6 – Manipulação de Strings

Escreva um programa que leia o nome completo de uma pessoa utilizando `fgets()`.

Em seguida, informe:

* quantidade de caracteres (`strlen()`);
* quantidade de vogais;
* quantidade de consoantes;
* quantidade de espaços em branco.

---

### Exercício 7 – Comparação de Strings

Escreva um programa que leia dois nomes e utilize `strncmp()` para verificar se são iguais.

Caso sejam diferentes, informe qual deles é alfabeticamente maior.

---

### Exercício 8 – Funções

Implemente as seguintes funções:

```c
int maior(int a, int b);

int menor(int a, int b);

float media(float a, float b);

int fatorial(int n);
```

Em seguida, desenvolva um programa que utilize todas essas funções.

---

### Exercício 9 – Modularizando um Programa

Escreva um programa para cadastrar as notas de uma turma utilizando um vetor.

Separe a solução nas seguintes funções:

* lerNotas();
* calcularMedia();
* encontrarMaiorNota();
* encontrarMenorNota();
* imprimirRelatorio();

A função `main()` deverá apenas coordenar a execução dessas funções.

---

### Exercício 10 – Desafio

Desenvolva um programa que simule um jogo da velha.

O programa deverá:

* utilizar uma matriz 3 × 3;
* armazenar os símbolos `'X'` e `'O'`;
* impedir jogadas em posições ocupadas;
* exibir o tabuleiro após cada jogada;
* verificar se algum jogador venceu ou se ocorreu empate.

Organize o programa utilizando funções para separar as diferentes responsabilidades da aplicação.
