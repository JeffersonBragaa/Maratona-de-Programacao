# Maratona de Programação I (MP1)

Repositório de estudos da disciplina **Maratona de Programação I** — soluções de exercícios, simulados e material de apoio.

## Organização

| Pasta | Conteúdo |
|-------|----------|
| `00_INDICE/` | Índice geral do repositório |
| `01_LISTAS/` | Listas de exercícios Beecrowd (`LISTA_01` … `LISTA_05`) |
| `02_SIMULADOS_E_PROVAS/` | Simulados e provas (enunciados + soluções) |
| `03_ALGORITMOS/` | Implementações e notas (BFS/DFS, Dijkstra, Tarjan) |
| `04_VISUALIZACOES_HTML/` | Laboratórios visuais abertos no navegador |
| `05_APOSTILAS_E_REFERENCIAS/` | Apostilas e referências |
| `06_AULAS/` | Material de aula e exemplos |

## Como compilar

```sh
g++ -g -O2 -std=gnu++17 -static -lm arquivo.cpp -o arquivo
./arquivo < entrada.txt
```

Arquivos `.cpp` de listas seguem o **ID do problema** no Beecrowd (ex.: `1081.cpp`).

## Notas

- Código-fonte é a fonte da verdade; executáveis e saídas locais ficam fora do repositório.
- Materiais de apoio internos e configurações de ferramentas locais estão no `.gitignore`.
