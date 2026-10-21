# Índice — MP1 (Maratona de Programação I)

Organizado em 2026-10-19.  
**Regra adotada:** pastas padronizadas · **nomes de arquivo preservados** · duplicatas idênticas removidas.

Raiz: `/home/j-braga/Documentos/MP1`

---

## Estrutura

```text
MP1/
├── 00_INDICE/                      ← este arquivo
├── 01_LISTAS/                      ← listas Beecrowd (ex-Exercicios/lista*)
│   ├── LISTA_01/                   15 arquivos (IDs Beecrowd)
│   ├── LISTA_02/
│   ├── LISTA_03/
│   ├── LISTA_04/
│   └── LISTA_05/
├── 02_SIMULADOS_E_PROVAS/
│   ├── PROVAS/
│   │   ├── SIMULADO_GERAL_2.pdf    ← era Exercicios/prova.pdf (14/10/2026)
│   │   └── prova-5.pdf
│   ├── SIMULADO_00/                ← era "simulado 0/"
│   └── SIMULADO_02/                ← era "simulado02/" + soltos B.cpp, K.cpp
├── 03_ALGORITMOS/
│   ├── BFS_DFS/                    ← era grafos/ (raiz)
│   ├── DIJKSTRA/                   ← era grafos/dijkstra/
│   └── TARJAN/                     ← era grafos/tarjan/
├── 04_VISUALIZACOES_HTML/
├── 05_APOSTILAS_E_REFERENCIAS/
├── 06_AULAS/                       ← era aula/ + estudos/
└── Exercicios/
    ├── AGENTS.md
    └── ecox21/                     ← agente de estudo (método/progresso)
```

---

## O que foi onde

### 01_LISTAS (nomes `.cpp` = ID Beecrowd, **não** renomeados)

| Pasta | Origem | Observação |
|-------|--------|------------|
| LISTA_01 | `Exercicios/lista 01/` | I/O, geometria básica, simulação |
| LISTA_02 | `Exercicios/lista 02/` | inclui `1105.c`, `entrada.txt`, `programa` |
| LISTA_03 | `Exercicios/lista 03/` | `1196.cpp` vazio · `saida` artefato |
| LISTA_04 | `Exercicios/lista04/` | |
| LISTA_05 | `Exercicios/lista05/` | grafos · binários soltos (1029, 1081, …) ficaram junto |

### 02_SIMULADOS_E_PROVAS

| Arquivo | Conteúdo identificado |
|---------|----------------------|
| `SIMULADO_00/Simulado_Zero.pdf` | enunciado simulado 0 |
| `SIMULADO_00/a.cpp` … `E.c` | soluções A–E do simulado 0 |
| `PROVAS/SIMULADO_GERAL_2.pdf` | prova de 14/10/2026 (problemas A–L) |
| `PROVAS/prova-5.pdf` | prova/avaliação anterior |
| `SIMULADO_02/j.cpp` | **J — Desvio de Rua** (seu código) |
| `SIMULADO_02/j_completo.cpp` | referência J (pontes tin/low) |
| `SIMULADO_02/j_visual.html` | laboratório visual do J |
| `SIMULADO_02/E.cpp` | **E — Guerra em Marte** (Ackermann) |
| `SIMULADO_02/B.cpp` | **B — 3N+1** |
| `SIMULADO_02/K.cpp` | **K — Figurinhas** |
| `SIMULADO_02/l.cpp` | **L — Fuga da Princesa** (BFS) |
| `SIMULADO_02/E`, `j`, `saida`, `out.txt` | binários/artefatos (não são fonte) |

### 03_ALGORITMOS

| Pasta | Arquivos | Assunto |
|-------|----------|---------|
| BFS_DFS | `a.cpp`, binário `a` | BFS em grade |
| DIJKSTRA | `b.cpp`, `desafio1.cpp`, `dijkstra-aula.cpp` + binários | Dijkstra |
| TARJAN | `aula.cpp` + binário | SCC / Tarjan |

### 04_VISUALIZACOES_HTML (nomes originais)

| Arquivo | Algoritmo |
|---------|-----------|
| `Desvio de Rua — laboratório didático.html` | pontes / desvio de rua (J) |
| `Laboratório de Dijkstra-primeiro-bom.html` | Dijkstra (versão mais completa) |
| `laboratorio-dijkstra.html` | Dijkstra (versão curta) |

> Três HTMLs de Dijkstra são **diferentes** (hashes distintos) — nenhum foi apagado.

### 05_APOSTILAS_E_REFERENCIAS

- `Apostila de Revisao - Maratona de Programacao 1.pdf`
- `apostila_revisao_mp1.md`

### 06_AULAS

- `MP1_-_Aula_07_-_Intro._Grafos_-_Buscas.pdf` (era `estudos/`)
- `aula03.cpp` — lista encadeada
- `vector.cpp` — rascunho STL (com erros de sintaxe, material de aula)
- `1301.cpp` — exercício comentado
- binário `aula03`

---

## Duplicatas removidas (byte a byte idênticas)

| Removido | Mantido |
|----------|---------|
| `K (1).cpp` | `02_SIMULADOS_E_PROVAS/SIMULADO_02/K.cpp` |
| `l.cpp` (raiz) | `02_SIMULADOS_E_PROVAS/SIMULADO_02/l.cpp` |

---

## Relações secundárias (não moveram de pasta)

- HTML **Desvio de Rua** ↔ `SIMULADO_02/j.cpp` / `j_completo.cpp` / `j_visual.html`
- HTMLs **Dijkstra** ↔ `03_ALGORITMOS/DIJKSTRA/*.cpp`
- `BFS_DFS/a.cpp` ↔ `SIMULADO_02/l.cpp` (mesma família BFS em grade)
- `LISTA_05` contém grafos (1081, 1082, 1128, …) — prática relacionada a `03_ALGORITMOS/`

---

## Agente ECOX21

Continua em `Exercicios/ecox21/` (método, progresso, plano, diagnóstico).  
As listas **mudaram de caminho** — ver aviso em `Exercicios/AGENTS.md`.

---

## Incertezas / artefatos

| Item | Nota |
|------|------|
| Binários ELF (`programa`, `j`, `E`, `a`, …) | **removidos** em 2026-10-19 (22 executáveis) |
| `out.txt` | saída de teste (mantida) |
| `1196.cpp` (LISTA_03) | arquivo vazio |
| `prova-5.pdf` | não aberto nesta auditoria — classificado pelo nome |
| `.vscode/` | configurações locais VS Code; mantidas junto das pastas |
