# Índice — MP1 (Maratona de Programação I)

Organização geral revisada em 13/11/2026; revisão do simulado 3 adicionada em 15/11/2026. Caminhos relativos à raiz do repositório; nomes dos PDFs e dos códigos preservados.

## Estrutura

```text
Maratora-de-Programacao/
├── 00_INDICE/
├── 01_LISTAS/
│   ├── LISTA_01/
│   ├── LISTA_02/
│   ├── LISTA_03/
│   ├── LISTA_04/
│   ├── LISTA_05/
│   ├── LISTA_06/
│   └── LISTA_07/
├── 02_SIMULADOS_E_PROVAS/
│   ├── SIMULADO_00/
│   └── SIMULADO_02/
├── 03_ALGORITMOS/
│   ├── BFS_DFS/
│   ├── DIJKSTRA/
│   ├── GEOMETRIA_COMPUTACIONAL/
│   └── TARJAN/
├── 04_VISUALIZACOES_HTML/
├── 05_APOSTILAS_E_REFERENCIAS/
├── 06_AULAS/
├── 07_AVALIACOES_EM_SALA/
│   ├── SIMULADOS/
│   ├── WARMUP_AULA_05/
│   ├── WARMUP_AULA_08/
│   └── WARMUP_AULA_10/
└── SIM_03/
    ├── DIA_01/
    └── DIA_02/
        └── VISUALIZACOES_HTML/
```

## Listas de exercícios

[Listas 01 a 07](../01_LISTAS/): fontes com o ID do problema no Beecrowd, incluindo arquivos `.c`, `.cpp` e `.CPP`. Entradas de teste, como `LISTA_02/entrada.txt`, permanecem junto dos exercícios.

## Simulados e soluções

| Pasta | Conteúdo |
|-------|----------|
| [SIMULADO_00](../02_SIMULADOS_E_PROVAS/SIMULADO_00/) | `Simulado_Zero.pdf` e soluções A–E |
| [SIMULADO_02](../02_SIMULADOS_E_PROVAS/SIMULADO_02/) | `SIMULADO_GERAL_2.pdf`, soluções e referência `j_completo.cpp` |

Os antigos warmups e suas soluções saíram de `02_SIMULADOS_E_PROVAS/PROVAS/` para a seção 07. O enunciado do Simulado Geral 2 foi reunido às soluções em `SIMULADO_02/`.

### Revisão atual do simulado 3

[SIM_03](../SIM_03/README.md) está organizada por dia e ainda em revisão. O dia 1 contém `1105.cpp`, `1548.cpp` e `2065.cpp`. O dia 2 contém `memo.cpp`, `tabu.cpp` e o [laboratório da Aula 12 sobre programação dinâmica](../SIM_03/DIA_02/VISUALIZACOES_HTML/aula_12_programacao_dinamica_bloco_1.html). O enunciado do simulado 3 ainda não está nesta pasta.

## Algoritmos

| Pasta | Conteúdo |
|-------|----------|
| [BFS_DFS](../03_ALGORITMOS/BFS_DFS/) | `a.cpp`: busca em grade |
| [DIJKSTRA](../03_ALGORITMOS/DIJKSTRA/) | `b.cpp`, `desafio1.cpp`, `dijkstra-aula.cpp` |
| [GEOMETRIA_COMPUTACIONAL](../03_ALGORITMOS/GEOMETRIA_COMPUTACIONAL/) | `01_par_mais_proximo.cpp`: exemplo dos slides da Aula 11, antes na Lista 07 |
| [TARJAN](../03_ALGORITMOS/TARJAN/) | `aula.cpp`: componentes fortemente conexas |

## Visualizações HTML

Os laboratórios da organização anterior estão em [04_VISUALIZACOES_HTML](../04_VISUALIZACOES_HTML/). O laboratório do simulado 3 fica no próprio [dia 2](../SIM_03/DIA_02/VISUALIZACOES_HTML/aula_12_programacao_dinamica_bloco_1.html), junto dos exemplos relacionados.

| Arquivo | Material relacionado |
|---------|---------------------|
| [01_par_mais_proximo.html](../04_VISUALIZACOES_HTML/01_par_mais_proximo.html) | [Código](../03_ALGORITMOS/GEOMETRIA_COMPUTACIONAL/01_par_mais_proximo.cpp) e [slides da Aula 11](../06_AULAS/MP1_-_Aula_11_-_GC.pdf) |
| [j_visual.html](../04_VISUALIZACOES_HTML/j_visual.html) | [Solução J](../02_SIMULADOS_E_PROVAS/SIMULADO_02/j.cpp) e [referência](../02_SIMULADOS_E_PROVAS/SIMULADO_02/j_completo.cpp) |
| [laboratorio-dijkstra-comcodigo.html](../04_VISUALIZACOES_HTML/laboratorio-dijkstra-comcodigo.html) | [Algoritmos de Dijkstra](../03_ALGORITMOS/DIJKSTRA/) |
| [laboratorio-tarjan.html](../04_VISUALIZACOES_HTML/laboratorio-tarjan.html) | [Algoritmo de Tarjan](../03_ALGORITMOS/TARJAN/aula.cpp) |

A pasta também reúne os laboratórios de Fibonacci, Dividindo a Coca, Desvio de Rua e outras versões de Dijkstra. Versões distintas foram preservadas.

## Apostilas e aulas

- [05_APOSTILAS_E_REFERENCIAS](../05_APOSTILAS_E_REFERENCIAS/): apostila de revisão em PDF e Markdown.
- [06_AULAS](../06_AULAS/): slides das Aulas 07 e 11, `aula03.cpp`, `vector.cpp` e `1301.cpp`.

## Avaliações em sala — seção 07

[07_AVALIACOES_EM_SALA](../07_AVALIACOES_EM_SALA/README.md) reúne os enunciados dos simulados 0, 1 e 2 e dos warmups das Aulas 05, 08 e 10, com datas, links e soluções disponíveis.

Os seis PDFs adicionados na raiz foram movidos para esta seção. Os warmups que estavam em `PROVAS/` foram agrupados por aula; as soluções `A.cpp`, `A-didatico.cpp` e `c.cpp` ficaram com o Warmup Aula 10, identificado pelos problemas Guerra e Os Suspeitos. PDFs repetidos e versões foram preservados e estão descritos no índice da seção.

## Compilação e arquivos locais

Os dez executáveis das Listas 06 e 07 que já estavam marcados como removidos continuam excluídos. Os três executáveis locais do dia 1 do simulado 3 foram preservados com extensão `.out` e são ignorados pelo Git.

Para novas compilações, use a extensão `.out`, conforme o [README](../README.md); esses executáveis e os artefatos comuns de compilação estão no `.gitignore`. Fontes, PDFs, visualizações e entradas de teste foram preservados.
