# Manifesto da auditoria

Data: 13/11/2026. Raiz efetiva: `~/Documentos/MP1/Maratora-de-Programacao`.
Branch: `main`. HEAD analisado: `f76157061f41d770ab8579d32c69cba4800bf040`.
Estado inicial: árvore limpa; branch um commit à frente de `origin/main` segundo a referência local. Não houve fetch nem comparação atualizada com o servidor.
Remoto configurado: `git@github.com:JeffersonBragaa/Maratora-de-Programacao.git`. O pedido cita `Maratona-de-Programacao`; há divergência de grafia, não corrigida nesta auditoria.

## Completude e unidade de contagem

Inventário do acervo acadêmico concluído: **179 arquivos**, incluindo **152 códigos**, **13 PDFs** e **9 HTMLs**. Configurações ocultas, objetos Git e esta própria auditoria não entram nessa contagem. Nenhum material acadêmico enumerado foi inacessível ao sistema de arquivos.

Catálogo: **154 unidades de problema identificadas por conteúdo**, mais **2 registros incompletos sem identidade determinada** e **6 exemplos de implementação**; total **162 linhas de dados**. São unidades internas deduplicadas, não 154 IDs oficiais comprovados. Apenas seis IDs Beecrowd estão diretamente comprovados nas imagens dos slides. A quantidade definitiva de exercícios oficiais distintos permanece **não determinada** onde faltam enunciados ou há nomes conflitantes.

Os 37 itens das seis avaliações-base resultam em **34 problemas distintos de avaliação**: Vira Cartas, Transportes e Fuga da Princesa reaparecem. Blobs também está na Lista 05 e tem um único registro. Cópias dos mesmos PDFs não acrescentam problemas. As cinco propostas R1–R5 da apostila entram no catálogo. Microdesafios interativos dos HTMLs foram mapeados como materiais de apoio, mas não individualizados como exercícios: essa parte permanece pendente.

**Auditoria técnica com cobertura documental ampla, porém não integralmente validada.** Todos os códigos foram submetidos a verificação sintática e classificados; foram executadas 16 campanhas locais, incluindo 100 instâncias aleatórias de par mais próximo. Enunciados integrais das listas não estão disponíveis no repositório. Não houve prova formal nem teste exaustivo de todas as implementações, validação completa dos JavaScripts dos laboratórios ou inspeção de todas as figuras. A documentação não deve ser apresentada como certificação de correção nem como diagnóstico de domínio.

## Organização esperada versus encontrada

| Item | Situação |
|---|---|
| `00_INDICE`, `01_LISTAS`, `02_SIMULADOS_E_PROVAS`, `03_ALGORITMOS`, `04_VISUALIZACOES_HTML`, `05_APOSTILAS_E_REFERENCIAS`, `06_AULAS`, `README.md` | presentes |
| `07_EXERCICIOS_DE_SALA` | ausente; conteúdo equivalente em `07_AVALIACOES_EM_SALA` |
| `Exercicios` | ausente |
| Listas 01–07 | pastas e códigos presentes; sem documento completo dos enunciados de cada lista |
| Aula de programação dinâmica | não localizada; cronograma cita o assunto, mas não prova realização |
| Histórico de submissões/aceites | não localizado |

## Arquivos por diretório

| Diretório | Quantidade |
|---|---:|
| `00_INDICE` | 1 |
| `01_LISTAS` | 130 |
| `02_SIMULADOS_E_PROVAS` | 13 |
| `03_ALGORITMOS` | 6 |
| `04_VISUALIZACOES_HTML` | 9 |
| `05_APOSTILAS_E_REFERENCIAS` | 2 |
| `06_AULAS` | 5 |
| `07_AVALIACOES_EM_SALA` | 12 |
| `README.md` | 1 |

Inventário individual, categoria, tamanho e SHA-256: `inventario.csv`. Nomes e caminhos são relativos à raiz do repositório.

## Duplicatas exatas

A igualdade abaixo foi verificada por SHA-256. Códigos idênticos foram agrupados pelo comportamento, mas isso não comprova a identidade da tarefa que deveria ocupar um nome incorreto.

- `02_SIMULADOS_E_PROVAS/SIMULADO_02/SIMULADO_GERAL_2.pdf` ↔ `07_AVALIACOES_EM_SALA/SIMULADOS/sim2.pdf`
- `01_LISTAS/LISTA_05/1536.cpp` ↔ `01_LISTAS/LISTA_05/1873.cpp`
- `01_LISTAS/LISTA_03/1039.cpp` ↔ `01_LISTAS/LISTA_03/1041.cpp` ↔ `01_LISTAS/LISTA_03/1045.cpp`
- `01_LISTAS/LISTA_03/1403.cpp` ↔ `01_LISTAS/LISTA_03/1449.cpp`
- `01_LISTAS/LISTA_03/1259.cpp` ↔ `01_LISTAS/LISTA_03/1241.cpp` ↔ `01_LISTAS/LISTA_03/1068.cpp`
- `01_LISTAS/LISTA_03/1037.cpp` ↔ `01_LISTAS/LISTA_03/1030.cpp`
- `01_LISTAS/LISTA_03/1863.cpp` ↔ `01_LISTAS/LISTA_03/1893.cpp`
- `07_AVALIACOES_EM_SALA/WARMUP_AULA_05/warmup.pdf` ↔ `07_AVALIACOES_EM_SALA/WARMUP_AULA_05/warmup (1).pdf`

## Versões e limitações de leitura

- `07_AVALIACOES_EM_SALA/WARMUP_AULA_10/prova-3.pdf` e `warmupunite.pdf`: mesmo warmup, arquivos diferentes. O primeiro apresenta caracteres corrompidos na extração; a versão legível sustenta a análise. Páginas físicas foram usadas, sem confundir com a numeração impressa.
- Slides `06_AULAS/MP1_-_Aula_11_-_GC.pdf`: 125 páginas. Inspeção visual dirigida das páginas 38, 74, 123 e 124 recuperou IDs/títulos e a nota sobre tolerância numérica que não estavam no texto extraído. Outras figuras não foram todas auditadas visualmente.
- `06_AULAS/MP1_-_Aula_07_-_Intro._Grafos_-_Buscas.pdf`: 63 páginas, conteúdo textual acessível; figuras usadas como apoio, não como prova de todas as arestas.
- Apostila PDF e Markdown: versões de referência, não evidência de desempenho. Divergências com os códigos estão em `03_ANALISE_CODIGOS.md`.
- HTMLs: texto e estrutura examinados para relacionar temas; não testados integralmente no navegador e microdesafios não catalogados individualmente.
- Páginas oficiais tentadas: [3068](https://judge.beecrowd.com/pt/problems/view/3068) e [3152](https://judge.beecrowd.com/pt/problems/view/3152) redirecionaram para login; [1549](https://judge.beecrowd.com/pt/problems/view/1549) e [2840](https://judge.beecrowd.com/pt/problems/view/2840) não ficaram acessíveis. Não se inferiu título/limite oficial a partir desses endereços.
- `01_LISTAS/LISTA_02/1024.cpp`: apenas esqueleto. `01_LISTAS/LISTA_03/1196.cpp`: vazio. `SIMULADO_00/c.cpp`: comentário, sem solução.
- Sem edição dos originais, exclusão, instalação, commit ou push. Artefatos de execução ficaram em `/tmp/mp1-auditoria`.
