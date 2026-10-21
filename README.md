# Sistema de Atendimento Hospitalar

## Descrição do Projeto

Este projeto consiste em uma simulação de um sistema de atendimento hospitalar, desenvolvido em C++, utilizando estruturas de dados lineares para organizar pacientes, médicos e o histórico de atendimentos.

O sistema demonstra, na prática, a utilização de filas, pilhas e listas encadeadas, trabalhando com alocação dinâmica de memória.

## Objetivo

Aplicar os conceitos de Estruturas de Dados Lineares por meio de um sistema que simula o fluxo de atendimento de pacientes em um ambiente hospitalar.

## Estruturas de Dados Utilizadas

### 1. Fila de Pacientes (FIFO)
Responsável por organizar os pacientes conforme a ordem de chegada.

- Adicionar pacientes à fila.
- Consultar o próximo paciente.
- Remover o paciente após ser chamado.
- Verificar a quantidade de pacientes aguardando.

### 2. Pilha de Histórico (LIFO)
Armazena os atendimentos realizados, permitindo consultar os registros mais recentes.

- Registrar atendimentos.
- Consultar o último atendimento.
- Exibir o histórico de atendimentos.

### 3. Lista Encadeada de Médicos
Responsável por gerenciar os médicos disponíveis para realizar os atendimentos.

- Cadastrar médicos.
- Consultar médicos disponíveis.
- Chamar um médico para atendimento.
- Recolocar o médico na lista após finalizar o atendimento.

## Funcionamento do Sistema

O programa inicia cadastrando três médicos e quatro pacientes.

Os pacientes são organizados em uma fila, enquanto os médicos são armazenados em uma lista encadeada.

Durante a simulação, o primeiro paciente da fila é encaminhado ao primeiro médico disponível.

Após cada atendimento, o registro é armazenado na pilha de histórico, e o médico retorna ao final da lista para realizar novos atendimentos.

O processo continua até que todos os pacientes sejam atendidos.

**Observação:** Embora os pacientes possuam um nível de urgência cadastrado, a ordem de atendimento segue a ordem de chegada (FIFO), sem priorização pela urgência.

## Exemplo de Saída

```text
Médicos disponíveis: Dra. Ana Lima -> Dr. Bruno Costa -> Dra. Carla Ramos

Pacientes chegando:
Próximo a ser atendido: Eduardo (urgencia=3)
Total na fila: 4

Simulação de atendimentos:
[1] Dra. Ana Lima atende Eduardo (urgencia=3)
[2] Dr. Bruno Costa atende Fernanda (urgencia=1)
[3] Dra. Carla Ramos atende Gabriel (urgencia=2)
[4] Dra. Ana Lima atende Helena (urgencia=1)

Último atendimento registrado (peek):
Dra. Ana Lima → Helena (urgencia=1)

=== Relatório de Atendimentos ===
- Dra. Ana Lima → Helena (urgencia=1)
- Dra. Carla Ramos → Gabriel (urgencia=2)
- Dr. Bruno Costa → Fernanda (urgencia=1)
- Dra. Ana Lima → Eduardo (urgencia=3)
```

## Conceitos Aplicados

- Linguagem C++.
- Estruturas de dados lineares.
- Fila (FIFO).
- Pilha (LIFO).
- Lista simplesmente encadeada.
- Ponteiros.
- Alocação dinâmica de memória (`new` e `delete`).
- Estruturas (`struct`).
- Manipulação de nós encadeados.

## Conclusão

O desenvolvimento deste projeto permitiu aplicar os conhecimentos sobre estruturas de dados lineares em uma situação prática, simulando a organização de atendimentos hospitalares.

A utilização de filas, pilhas e listas encadeadas demonstra como diferentes estruturas podem trabalhar em conjunto para organizar e manipular informações de maneira eficiente.
