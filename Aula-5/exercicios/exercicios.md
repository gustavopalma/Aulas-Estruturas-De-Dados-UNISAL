# Exercício Prático – Sistema de Caixa Eletrônico

## Objetivo

Desenvolver um sistema de caixa eletrônico em linguagem C capaz de cadastrar contas correntes, realizar movimentações financeiras e armazenar os dados permanentemente em um arquivo binário.

O exercício deverá utilizar os conceitos estudados até o momento, incluindo:

* estruturas (`struct`);
* enumerações (`enum`);
* funções;
* ponteiros;
* arquivos binários;
* leitura e escrita de registros;
* busca e atualização de dados em arquivos.

---

## Estrutura da conta

Cada cliente cadastrado representará uma conta corrente.

Uma possível estrutura para representar a conta é:

```c
typedef enum
{
    CONTA_ENCERRADA,
    CONTA_ATIVA
} SituacaoConta;

typedef struct
{
    long numero;
    char titular[100];
    char cpf[15];
    double saldo;
    SituacaoConta situacao;
} Conta;
```

O número da conta deverá ser único e poderá ser gerado automaticamente pelo sistema ou informado pelo usuário, desde que não exista outra conta com o mesmo número.

O saldo inicial deverá ser igual a zero.

---

## Menu principal

O programa deverá apresentar um menu semelhante ao seguinte:

```text
1 – Cadastrar conta
2 – Consultar conta
3 – Realizar depósito
4 – Realizar saque
5 – Realizar transferência
6 – Listar contas
7 – Encerrar conta
0 – Sair
```

---

## Cadastro de conta

O sistema deverá permitir o cadastro de um novo cliente, solicitando:

* nome do titular;
* CPF;
* número da conta.

Antes de realizar o cadastro, o programa deverá verificar se o número da conta já existe.

Uma nova conta deverá ser criada com:

```text
Saldo: R$ 0,00
Situação: CONTA_ATIVA
```

Os dados deverão ser gravados em um arquivo binário.

---

## Consulta de conta

O usuário deverá informar o número da conta que deseja consultar.

Caso a conta seja encontrada, o programa deverá exibir:

* número da conta;
* nome do titular;
* CPF;
* saldo atual;
* situação da conta.

Caso a conta não exista, uma mensagem deverá ser apresentada.

---

## Depósito

O usuário deverá informar:

* número da conta;
* valor do depósito.

O depósito deverá ser realizado somente quando:

* a conta existir;
* a conta estiver ativa;
* o valor informado for maior que zero.

Após a operação, o saldo atualizado deverá ser gravado no arquivo.

---

## Saque

O usuário deverá informar:

* número da conta;
* valor do saque.

O saque deverá ser realizado somente quando:

* a conta existir;
* a conta estiver ativa;
* o valor for maior que zero;
* a conta possuir saldo suficiente.

Após a operação, o saldo atualizado deverá ser gravado no arquivo.

---

## Transferência entre contas

O usuário deverá informar:

* número da conta de origem;
* número da conta de destino;
* valor da transferência.

A transferência deverá ser realizada somente quando:

* as duas contas existirem;
* as duas contas estiverem ativas;
* as contas de origem e destino forem diferentes;
* o valor for maior que zero;
* a conta de origem possuir saldo suficiente.

A transferência deverá ser implementada utilizando as operações já existentes de saque e depósito.

Conceitualmente:

```text
Transferência
    =
Saque na conta de origem
    +
Depósito na conta de destino
```

Caso alguma etapa não possa ser concluída, nenhum saldo deverá ser alterado.

---

## Encerramento de conta

Encerrar uma conta não significa remover seu registro do arquivo.

O sistema deverá localizar a conta e alterar apenas sua situação:

```c
conta.situacao = CONTA_ENCERRADA;
```

Uma conta encerrada deverá permanecer armazenada no arquivo para preservar seu histórico.

Após o encerramento, ela não poderá:

* receber depósitos;
* realizar saques;
* enviar transferências;
* receber transferências.

Como regra adicional, o encerramento poderá ser permitido apenas quando o saldo da conta for igual a zero.

---

## Listagem de contas

O programa deverá percorrer o arquivo binário e exibir todas as contas cadastradas.

A listagem deverá informar claramente se cada conta está:

```text
ATIVA
```

ou

```text
ENCERRADA
```

Opcionalmente, o sistema poderá oferecer filtros para listar:

* todas as contas;
* somente contas ativas;
* somente contas encerradas.

---

## Persistência dos dados

As contas deverão ser armazenadas em um arquivo binário, por exemplo:

```text
contas.dat
```

A gravação de uma nova conta poderá utilizar:

```c
fwrite(&conta, sizeof(Conta), 1, arquivo);
```

A leitura poderá utilizar:

```c
fread(&conta, sizeof(Conta), 1, arquivo);
```

Para atualizar uma conta existente, o programa poderá utilizar `fseek()` para retornar ao início do registro encontrado e sobrescrevê-lo.

---

## Funções sugeridas

O programa deverá ser dividido em funções. Algumas assinaturas possíveis são:

```c
void cadastrarConta(void);

void consultarConta(void);

int depositar(long numeroConta, double valor);

int sacar(long numeroConta, double valor);

int transferir(
    long contaOrigem,
    long contaDestino,
    double valor
);

void listarContas(void);

int encerrarConta(long numeroConta);

int buscarConta(
    FILE *arquivo,
    long numeroConta,
    Conta *conta
);

int atualizarConta(
    FILE *arquivo,
    const Conta *conta
);
```

As assinaturas poderão ser modificadas de acordo com a organização adotada pelo grupo.

---

## Regras de validação

O sistema deverá impedir:

* cadastro de contas com número repetido;
* operações em contas inexistentes;
* movimentações em contas encerradas;
* depósitos, saques ou transferências com valores iguais ou menores que zero;
* saques superiores ao saldo disponível;
* transferências para a própria conta;
* encerramento de contas com saldo diferente de zero;
* corrupção dos dados caso uma operação não seja concluída.

---

## Critérios de avaliação

Serão considerados:

* utilização correta de `struct`;
* utilização adequada de `enum`;
* correta manipulação de arquivos binários;
* utilização de funções;
* organização e legibilidade do código;
* validação das operações;
* tratamento de erros na abertura e manipulação dos arquivos;
* atualização correta dos registros;
* encerramento lógico da conta por meio de uma flag;
* liberação adequada dos recursos utilizados pelo programa.

---

## Desafios adicionais

### Desafio 1 – Histórico de transações

Crie um segundo arquivo binário para armazenar todas as movimentações realizadas.

Uma possível estrutura é:

```c
typedef enum
{
    DEPOSITO,
    SAQUE,
    TRANSFERENCIA_ENVIADA,
    TRANSFERENCIA_RECEBIDA
} TipoTransacao;

typedef struct
{
    long conta;
    long contaRelacionada;
    TipoTransacao tipo;
    double valor;
} Transacao;
```

---

### Desafio 2 – Extrato bancário

Permita consultar todas as transações relacionadas a uma determinada conta.

---

### Desafio 3 – Reativação de conta

Implemente uma função para reativar uma conta encerrada.

---

### Desafio 4 – Exclusão física

Crie uma rotina administrativa capaz de remover definitivamente contas encerradas, copiando apenas os registros válidos para um arquivo temporário.

Esse recurso deverá ser diferente da operação normal de encerramento de conta.
