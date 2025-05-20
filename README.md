# Projetos-de-Estrutura-de-dados-Thales-Rafael-e-Kayran-SIlva-

# 🧬 Algoritmo Genético para Resolução de Labirintos
[![Build Status](https://img.shields.io/badge/Compiled%20with-GCC-green)](https://gcc.gnu.org/)

Um algoritmo genético implementado em C para encontrar caminhos em labirintos. Projeto desenvolvido para estudo de algoritmos evolutivos e otimização.

<p align="center">
  <img src="maze_demo.gif" alt="Demonstração do labirinto sendo resolvido">
</p>

## ✨ Funcionalidades

- **Geração de labirintos** (definidos em `maze.c`)
- **Algoritmo genético ""completo"" com:
  - Seleção por torneio
  - Crossover de um ponto
  - Mutação aleatória
  - Elitismo
- **Visualização em tempo real** do caminho do melhor indivíduo
- **Parâmetros ajustáveis** (tamanho da população, taxa de mutação, etc.)

## 🗂 Estrutura do Projeto

```plaintext
.
├── config.h         # Configurações do algoritmo
├── genetic.h        # Lógica do algoritmo genético
├── individual.h     # Definição de indivíduos e fitness
├── maze.h           # Definição do labirinto
├── main.c           # Loop principal
├── genetic.c        # Implementação do algoritmo genético
├── individual.c     # Cálculo de fitness e visualização
└── maze.c           # Labirinto e posições inicial/final
