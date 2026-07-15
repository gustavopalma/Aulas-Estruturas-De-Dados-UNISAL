# Lista de Exercícios – Estrutura de Dados

## Aula 4 – Ponteiros e Alocação Dinâmica

### Exercício 1 – Primeiro Contato com Ponteiros

Escreva um programa que:

* declare uma variável inteira;
* declare um ponteiro para inteiro;
* faça o ponteiro apontar para a variável;
* exiba:

  * o valor da variável;
  * o endereço da variável;
  * o valor armazenado no ponteiro;
  * o valor acessado através do ponteiro.

---

### Exercício 2 – Alterando Valores com Ponteiros

Escreva um programa que:

* leia um número inteiro;
* faça um ponteiro apontar para essa variável;
* altere seu valor utilizando apenas o ponteiro;
* exiba o valor antes e depois da alteração.

---

### Exercício 3 – Troca de Valores

Implemente uma função capaz de trocar o conteúdo de duas variáveis inteiras utilizando passagem por referência.

A função deverá possuir a seguinte assinatura:

```c
void trocar(int *a, int *b);
```

---

### Exercício 4 – Vetor Dinâmico

Desenvolva um programa que:

* solicite ao usuário a quantidade de elementos desejada;
* aloque dinamicamente um vetor;
* leia todos os valores;
* exiba os elementos armazenados;
* libere a memória antes de encerrar o programa.

---

### Exercício 5 – Estatísticas de um Vetor Dinâmico

Utilizando um vetor alocado dinamicamente, desenvolva um programa que determine:

* maior valor;
* menor valor;
* média dos elementos;
* quantidade de números pares;
* quantidade de números ímpares.

Todas as operações deverão ser implementadas em funções.

---

### Exercício 6 – Redimensionando um Vetor

Desenvolva um programa que:

1. aloque um vetor com **N** posições;
2. permita ao usuário informar uma nova quantidade de elementos;
3. utilize `realloc()` para redimensionar o vetor;
4. preserve os dados já armazenados;
5. permita preencher as novas posições.

---

### Exercício 7 – Cadastro Dinâmico de Alunos

Utilizando a estrutura abaixo:

```c
typedef struct
{
    char nome[50];
    int idade;
    float nota;
} Aluno;
```

desenvolva um programa que:

* solicite a quantidade de alunos;
* aloque dinamicamente um vetor de estruturas;
* realize o cadastro;
* exiba todos os registros;
* libere a memória ao final.

---

### Exercício 8 – Ponteiros Genéricos

Utilizando um ponteiro do tipo `void *`, desenvolva um programa que:

* armazene o endereço de uma estrutura `Aluno`;
* realize a conversão para `Aluno *`;
* exiba os campos da estrutura utilizando o operador `->`.

---

### Exercício 9 – Ponteiros para Funções

Implemente as seguintes funções:

```c
int soma(int a, int b);

int subtracao(int a, int b);

int multiplicacao(int a, int b);

int divisao(int a, int b);
```

Em seguida:

* declare um ponteiro para função;
* permita que o usuário escolha a operação desejada;
* execute a função correspondente utilizando apenas o ponteiro.

---

### Exercício 10 – Desafio

Desenvolva um programa para gerenciamento de uma agenda de contatos.

Cada contato deverá possuir:

```c
typedef struct
{
    char nome[50];
    char telefone[20];
} Contato;
```

O programa deverá:

* alocar dinamicamente o vetor de contatos;
* permitir o cadastro de novos contatos;
* permitir aumentar a capacidade da agenda utilizando `realloc()`;
* listar todos os contatos cadastrados;
* liberar toda a memória antes de finalizar a execução.

---

## Desafio Extra

Pesquise o funcionamento da função `qsort()` da biblioteca padrão da linguagem C.

Explique:

* por que ela utiliza ponteiros genéricos (`void *`);
* por que recebe um ponteiro para função como parâmetro;
* quais vantagens essa implementação oferece em relação à criação de uma função de ordenação específica para cada tipo de dado.
