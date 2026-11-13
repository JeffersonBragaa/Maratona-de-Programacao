# Maratona de Programação I (MP1)

Repositório de estudos da disciplina **Maratona de Programação I** — soluções de exercícios, simulados e material de apoio.

## Organização

| Pasta | Conteúdo |
|-------|----------|
| [00_INDICE/](00_INDICE/INDICE.md) | Índice geral do repositório |
| `01_LISTAS/` | Listas de exercícios Beecrowd (`LISTA_01` … `LISTA_07`) |
| `02_SIMULADOS_E_PROVAS/` | Simulados e provas (enunciados + soluções) |
| `03_ALGORITMOS/` | Implementações e notas (BFS/DFS, Dijkstra, Tarjan, geometria) |
| `04_VISUALIZACOES_HTML/` | Laboratórios visuais abertos no navegador |
| `05_APOSTILAS_E_REFERENCIAS/` | Apostilas e referências |
| `06_AULAS/` | Material de aula e exemplos |
| [07_AVALIACOES_EM_SALA/](07_AVALIACOES_EM_SALA/README.md) | Exercícios em formato de prova que valeram nota: simulados e warmups |

## Como compilar

```sh
g++ -g -O2 -std=gnu++17 -static arquivo.cpp -lm -o arquivo.out
./arquivo.out < entrada.txt
```

Arquivos `.cpp` de listas seguem o **ID do problema** no Beecrowd (ex.: `1081.cpp`).

## Notas

- Código-fonte é a fonte da verdade; executáveis e saídas locais ficam fora do repositório.
- Use a extensão `.out` nos executáveis para que sejam ignorados pelo Git.
- Materiais de apoio internos e configurações de ferramentas locais estão no `.gitignore`.
