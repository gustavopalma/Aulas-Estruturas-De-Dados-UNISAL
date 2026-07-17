# Lista de Exercícios – Estrutura de Dados

## Aula 7 – Pilhas

### Exercício 1 – Conceito de Pilha

Explique com suas próprias palavras:

a) O que significa a sigla **LIFO**?

b) Por que uma pilha possui apenas uma extremidade principal de acesso?

c) Cite três situações do cotidiano ou da computação em que uma pilha pode ser utilizada.

---

### Exercício 2 – Operações Básicas

Considere uma pilha inicialmente vazia e execute mentalmente as seguintes operações:

```text
push(10)
push(20)
push(30)
pop()
push(40)
peek()
```

Informe:

* o valor removido pelo `pop()`;
* o valor retornado pelo `peek()`;
* o estado final da pilha.

---

### Exercício 3 – Implementação de `push`

Utilizando uma lista simplesmente encadeada, implemente a função:

```c
void push(No **topo, int valor);
```

A função deverá:

* alocar um novo nó;
* verificar se a alocação foi realizada com sucesso;
* inserir o novo elemento no topo da pilha.

---

### Exercício 4 – Implementação de `pop`

Implemente a função:

```c
int pop(No **topo);
```

A função deverá:

* verificar se a pilha está vazia;
* remover o elemento do topo;
* liberar a memória ocupada pelo nó;
* retornar o valor removido.

---

### Exercício 5 – Consulta do Topo

Implemente as funções:

```c
int peek(const No *topo);

int pilhaVazia(const No *topo);
```

A função `peek()` deverá retornar o valor armazenado no topo sem remover o elemento.

A função `pilhaVazia()` deverá informar se a pilha possui ou não elementos.

---

### Exercício 6 – Aplicação Completa

Desenvolva um programa com menu que permita:

```text
1 – Empilhar valor
2 – Desempilhar valor
3 – Consultar topo
4 – Exibir pilha
5 – Verificar se está vazia
0 – Sair
```

Antes de encerrar, o programa deverá liberar toda a memória utilizada.

---

### Exercício 7 – Inverter uma String

Desenvolva um programa que leia uma palavra ou frase e utilize uma pilha para exibir seus caracteres em ordem inversa.

Exemplo:

```text
Entrada:  estrutura
Saída:    aruturtse
```

Cada caractere deverá ser empilhado individualmente e depois removido com `pop()`.

---

### Exercício 8 – Verificação de Palíndromo

Utilizando uma pilha, desenvolva um programa que verifique se uma palavra é um palíndromo.

Uma palavra é considerada palíndroma quando pode ser lida da mesma forma nos dois sentidos.

Exemplos:

```text
arara
radar
osso
```

O programa deverá desconsiderar diferenças entre letras maiúsculas e minúsculas.

---

### Exercício 9 – Verificação de Delimitadores

Desenvolva um programa que utilize uma pilha para verificar se os delimitadores de uma expressão estão corretamente balanceados.

Considere:

```text
( )
[ ]
{ }
```

Exemplo válido:

```text
{ [ (10 + 5) * 2 ] }
```

Exemplo inválido:

```text
{ [ (10 + 5 ] * 2 ) }
```

Ao encontrar um símbolo de abertura, ele deverá ser empilhado. Ao encontrar um símbolo de fechamento, o programa deverá verificar se ele corresponde ao elemento armazenado no topo.

---

### Exercício 10 – Histórico de Desfazer

Desenvolva uma aplicação simples que simule um mecanismo de **desfazer operações**.

Cada operação poderá ser representada por uma string, por exemplo:

```text
"Escreveu texto"
"Removeu palavra"
"Colou conteúdo"
```

O programa deverá permitir:

* registrar uma nova operação;
* listar o histórico;
* desfazer a última operação;
* consultar qual operação será desfeita em seguida;
* liberar toda a memória antes de encerrar.

---

## Desafio Extra – Calculadora Pós-Fixa

Pesquise o funcionamento da notação pós-fixa, também conhecida como **RPN – Reverse Polish Notation**.

Implemente uma calculadora que utilize uma pilha para avaliar expressões como:

```text
5 3 + 2 *
```

Resultado:

```text
16
```

Para cada número, o programa deverá realizar um `push()`. Ao encontrar um operador, deverá remover os dois operandos do topo, executar a operação e empilhar o resultado.
