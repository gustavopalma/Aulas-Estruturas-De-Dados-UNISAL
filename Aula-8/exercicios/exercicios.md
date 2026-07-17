# Lista de Exercícios – Estrutura de Dados
## Aula 8 – Filas

### Exercício 1 – Conceito de Fila
Explique o significado de FIFO, diferencie fila de pilha e cite três aplicações práticas.

### Exercício 2 – Simulação Manual
Considere uma fila vazia e execute: `enqueue(10)`, `enqueue(20)`, `enqueue(30)`, `dequeue()`, `enqueue(40)`, `front()`. Informe o valor removido, o valor consultado e o estado final.

### Exercício 3 – Implementação de `enqueue`
Implemente `void enqueue(Fila *fila, int valor);`, inserindo no final e tratando corretamente o caso de fila vazia.

### Exercício 4 – Implementação de `dequeue`
Implemente `int dequeue(Fila *fila, int *valor);`, removendo o primeiro elemento, liberando o nó e atualizando `fim` quando a fila se tornar vazia.

### Exercício 5 – Operações Auxiliares
Implemente `filaVazia`, `front`, `imprimirFila` e `liberarFila`.

### Exercício 6 – Fila de Atendimento
Crie um sistema de atendimento com nome e senha. Permita entrar na fila, atender, consultar o próximo, listar e encerrar liberando a memória.

### Exercício 7 – Fila de Impressão
Cada documento deve possuir nome, quantidade de páginas e proprietário. Processe na mesma ordem de envio.

### Exercício 8 – Prioridade Simplificada
Crie uma fila prioritária e uma fila comum. Atenda primeiro a prioritária e, quando ela estiver vazia, a comum.

### Exercício 9 – Fila Circular
Explique o que é uma fila circular, qual problema ela resolve em vetores e demonstre os índices de início e fim em um vetor de cinco posições.

### Exercício 10 – Caixa de Supermercado
Modele clientes com identificador, nome e quantidade de itens. Permita adicionar, atender, calcular o total de itens aguardando e estimar o tempo de espera.

## Desafio Extra – Fila de Processos
Pesquise como sistemas operacionais organizam processos prontos para execução e implemente uma versão simplificada.
