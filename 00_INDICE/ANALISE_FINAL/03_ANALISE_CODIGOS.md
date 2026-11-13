# Análise das implementações

Foram examinados 152 arquivos de código. `compilacao.json` preserva comandos e diagnósticos: 151 passaram em **verificação sintática**, um falhou (`06_AULAS/vector.cpp`). A opção `-fsyntax-only` não faz ligação: um arquivo vazio pode passar e não produzir executável. Os arquivos `.CPP` também foram incluídos.

16 programas receberam campanhas de execução, com timeout de quatro segundos e `-D_GLIBCXX_DEBUG`. Resultados: sete campanhas compatíveis com seus oráculos limitados, seis divergências e três abortos por acesso inválido. Uma campanha contém 100 casos aleatórios. Esses números contam programas/campanhas, não aceites. Nenhuma evidência de aceitação em juiz foi encontrada.

## Achados reproduzidos

| Arquivo e linhas | Evidência observada | Interpretação e confiança |
|---|---|---|
| `01_LISTAS/LISTA_04/1763.cpp`:L35–36 | `brasil` produz `--- NOT FOUND ---` | `cin.ignore()` descarta a primeira letra. Falha de leitura confirmada, alto |
| `01_LISTAS/LISTA_04/1548.cpp`:L21–28 | notas 100,100,90 produzem 2 em vez de 3 posições preservadas | chave única perde ocorrência repetida; divergência do modelo confirmada; validade do domínio oficial pendente |
| `02_SIMULADOS_E_PROVAS/SIMULADO_02/K.cpp`:L14–37 | B=[1,100,200], Z=[2,3,4], N=M=1: NO em vez de YES | exige separação global quando PDF p20 pede subconjuntos. Confirmado, alto |
| `07_AVALIACOES_EM_SALA/WARMUP_AULA_10/c.cpp`:L69–71 | três uniões conectam cinco alunos a zero, mas imprime 4 | contar pais imediatos não equivale a contar representantes. Confirmado pelo enunciado p7, alto |
| `03_ALGORITMOS/TARJAN/aula.cpp`:L59–69 | grafo 0→1→2 dá zero SCC | busca começa em 7; condição `u==n` dentro de `u<n` nunca executa. Confirmado, alto |
| `01_LISTAS/LISTA_07/2840.cpp`:L10–18 | raio 1, capacidade 100: 25 contra 23 no modelo esférico | volume truncado antes da divisão; divergência matemática confirmada; limites do juiz pendentes |
| `02_SIMULADOS_E_PROVAS/SIMULADO_02/B.cpp`:L6–19 | modo debug aborta antes de responder [1,10] | vetor tamanho 1.000.000 acessado em índice 1.000.000. Confirmado, alto |
| `01_LISTAS/LISTA_04/1340.cpp`:L29–43 | uma remoção sem inserção aborta | top/front/pop sem checar vazio. Confirmado para a entrada testada; confirmar domínio oficial |
| `01_LISTAS/LISTA_05/1029.cpp`:L6–13 | fib(0) aborta | vetor de tamanho 1 recebe índice 1; confirmar se zero é permitido no juiz |

Entradas completas, saídas, oráculos, flags e erros estão em `testes.json`. Os testes matemáticos não substituem enunciados ausentes. Reprodução: executar `python3 00_INDICE/ANALISE_FINAL/reproduzir_testes.py` a partir da raiz; requer compiladores já instalados e usa `/tmp/mp1-auditoria`.

## Achados estáticos e hipóteses

- `01_LISTAS/LISTA_02/1030.cpp`:L6 e L10: tamanho de vetor não inicializado e `scanf("%d")` sem endereço; tentativa incompleta, inadequada como solução de referência.
- `01_LISTAS/LISTA_02/1105.cpp`:L18 lê d,v,c; a versão `.c`:L18 lê d,c,v. A troca entre credor e valor altera índices/saldos; comparar com o enunciado antes de escolher a versão.
- `06_AULAS/1301.cpp`:L53 usa comparação `==` sem efeito; array de 100000 é indexado até N inclusive; atualizações não normalizam sinal; produto inteiro pode transbordar; falta quebra de linha por caso. O enunciado Warmup 05 B p4 permite N=100000. Varreduras por consulta também têm custo O(NQ), incompatível em geral com os limites máximos.
- `02_SIMULADOS_E_PROVAS/SIMULADO_00/E.c`:L12–20 usa divisão/quociente de forma incompatível com soma de dígitos e pode usar `resto` não inicializado para N≤10. Não foi executado.
- `02_SIMULADOS_E_PROVAS/SIMULADO_00/a.cpp`:L21–32: O(NT), apesar de N,T até 10^5 no PDF p3; imprime espaço final e não separa casos por nova linha. Incompatibilidade de formato e risco de tempo observados.
- `01_LISTAS/LISTA_05/2294.cpp`:L34 compara grade numérica a `'G'`, embora leia inteiros e procure 3 e 0. Forte indício de adaptação incompleta de Fuga da Princesa. O significado correto do obstáculo precisa do enunciado.
- `01_LISTAS/LISTA_04/1107.cpp`:L15 conta `a-x<c` e não acompanha variações consecutivas; a variável `anterior` está sem uso. Não confundir com W10-B, cujo enunciado descreve cortes de um polígono.
- `01_LISTAS/LISTA_01/1021.cpp`:L13–24: conversão de valor decimal para inteiro por truncamento exige investigar erros de representação; hipótese sem contraexemplo executado nesta auditoria.
- `01_LISTAS/LISTA_05/2253.cpp`:L12 usa extração por token; se senhas com espaços constituírem uma única entrada inválida, separá-las em tokens gera respostas indevidas. Enunciado necessário.
- `03_ALGORITMOS/DIJKSTRA/desafio1.cpp`:L28 converte peso long long para int; risco condicionado aos limites ausentes.
- `01_LISTAS/LISTA_04/1944.cpp`:L26 copia toda a pilha por rodada, elevando o pior caso para quadrático. Correção funcional e custo são questões distintas.
- Nas demais implementações, ausência de achado não significa correção. O catálogo registra técnica e custo observados; limites, EOF, casos degenerados, profundidade recursiva e overflow ainda dependem de validação específica.

## Identidades e confiabilidade da apostila

Duplicatas exatas estão no manifesto. Exemplos críticos: `LISTA_03/1030.cpp` contém intervalos e é idêntico a `1037.cpp`; `1041.cpp` e `1045.cpp` repetem `1039.cpp`; `1241.cpp` e `1259.cpp` repetem o balanceamento de `1068.cpp`; `1449.cpp` repete `1403.cpp`; `1893.cpp` repete `1863.cpp`. `LISTA_05/1873.cpp` repete `1536.cpp`. Não declarar resolvidos os problemas sugeridos por esses nomes.

Em `05_APOSTILAS_E_REFERENCIAS/apostila_revisao_mp1.md`, seções 2, 3 e 14, há alegações incompatíveis com o acervo atual: 1192/1457 não implementam Bubble Sort; 1985 acumula preços, não consultas prefixadas; Lista 03/1030 não implementa Josephus; Lista 03/1241 não compara sufixos; 1769 valida CPF; 2854 calcula máximo+1, não mapeia nomes em um grafo. A apostila pode ter exemplos úteis, mas suas conclusões sobre evolução e domínio não são evidência confiável.

Hipóteses técnicas para diagnóstico posterior: dificuldade em preservar invariantes após adaptar código; diferença entre entidade e representação (pais de DSU versus componentes); leitura de quantificadores (escolher subconjunto versus usar tudo); tipos/unidades e conversão prematura; limites inclusivos e casos vazios. São hipóteses apoiadas nos arquivos, não juízos sobre capacidade, autoria ou desempenho independente.

## Registro por arquivo

A técnica e a complexidade de cada unidade estão no catálogo. A tabela abaixo permite localizar todos os 152 arquivos, inclusive versões e exemplos.

| Código | ID | Sintaxe | Execução nesta auditoria | Observação |
|---|---|---|---|---|
| `06_AULAS/1301.cpp` | MP1-W05-B | passou | não executado | 1 aviso(s); ver compilacao.json |
| `06_AULAS/aula03.cpp` | MP1-EXEMPLO-06_AULAS-AULA03 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `06_AULAS/vector.cpp` | MP1-EXEMPLO-06_AULAS-VECTOR | falhou | não executado | 1 aviso(s); ver compilacao.json |
| `02_SIMULADOS_E_PROVAS/SIMULADO_00/b.cpp` | MP1-COD-1170 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `02_SIMULADOS_E_PROVAS/SIMULADO_00/d.cpp` | MP1-S00-D | passou | não executado | 0 aviso(s); ver compilacao.json |
| `02_SIMULADOS_E_PROVAS/SIMULADO_00/a.cpp` | MP1-S00-A | passou | não executado | 0 aviso(s); ver compilacao.json |
| `02_SIMULADOS_E_PROVAS/SIMULADO_00/E.c` | MP1-S00-E | passou | não executado | 0 aviso(s); ver compilacao.json |
| `02_SIMULADOS_E_PROVAS/SIMULADO_00/c.cpp` | MP1-S00-C | passou | não executado | 0 aviso(s); ver compilacao.json |
| `02_SIMULADOS_E_PROVAS/SIMULADO_02/j_completo.cpp` | MP1-S02-J | passou | não executado | 2 aviso(s); ver compilacao.json |
| `02_SIMULADOS_E_PROVAS/SIMULADO_02/E.cpp` | MP1-S02-E | passou | não executado | 3 aviso(s); ver compilacao.json |
| `02_SIMULADOS_E_PROVAS/SIMULADO_02/j.cpp` | MP1-S02-J | passou | não executado | 0 aviso(s); ver compilacao.json |
| `02_SIMULADOS_E_PROVAS/SIMULADO_02/K.cpp` | MP1-S02-K | passou | divergiu | 0 aviso(s); ver compilacao.json |
| `02_SIMULADOS_E_PROVAS/SIMULADO_02/B.cpp` | MP1-S02-B | passou | abortou em debug | 0 aviso(s); ver compilacao.json |
| `02_SIMULADOS_E_PROVAS/SIMULADO_02/l.cpp` | MP1-S02-L | passou | não executado | 0 aviso(s); ver compilacao.json |
| `03_ALGORITMOS/GEOMETRIA_COMPUTACIONAL/01_par_mais_proximo.cpp` | MP1-EXEMPLO-GEOMETRIA_COMPUTACIONAL-01_PAR_MAIS_PROXIMO | passou | não executado | 0 aviso(s); ver compilacao.json |
| `03_ALGORITMOS/BFS_DFS/a.cpp` | MP1-S02-L | passou | não executado | 0 aviso(s); ver compilacao.json |
| `03_ALGORITMOS/TARJAN/aula.cpp` | MP1-EXEMPLO-TARJAN-AULA | passou | divergiu | 0 aviso(s); ver compilacao.json |
| `03_ALGORITMOS/DIJKSTRA/b.cpp` | MP1-W08-B | passou | não executado | 0 aviso(s); ver compilacao.json |
| `03_ALGORITMOS/DIJKSTRA/dijkstra-aula.cpp` | MP1-EXEMPLO-DIJKSTRA-DIJKSTRA-AULA | passou | não executado | 0 aviso(s); ver compilacao.json |
| `03_ALGORITMOS/DIJKSTRA/desafio1.cpp` | MP1-EXEMPLO-DIJKSTRA-DESAFIO1 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/2294.cpp` | MP1-COD-2294 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1212.cpp` | MP1-COD-1212 | passou | não executado | 2 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1211.cpp` | MP1-COD-1211 | passou | não executado | 4 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1170.cpp` | MP1-COD-1170 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1136.cpp` | MP1-COD-1136 | passou | não executado | 2 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1022.cpp` | MP1-COD-1022 | passou | não executado | 4 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1536.cpp` | MP1-COD-1536 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1125.cpp` | MP1-COD-1125 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1267.cpp` | MP1-COD-1267 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/2653.cpp` | MP1-COD-2653 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/2374.cpp` | MP1-COD-2374 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/2460.cpp` | MP1-COD-2460 | passou | não executado | 1 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1128.cpp` | MP1-COD-1128 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1103.cpp` | MP1-COD-1103 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1081.cpp` | MP1-COD-1081 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/2424.cpp` | MP1-COD-2424 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1221.cpp` | MP1-COD-1221 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1873.cpp` | MP1-COD-1536 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1082.cpp` | MP1-COD-1082 | passou | não executado | 3 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1148.cpp` | MP1-COD-1148 | passou | não executado | 1 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/2253.cpp` | MP1-COD-2253 | passou | não executado | 1 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1244.cpp` | MP1-COD-1244 | passou | não executado | 2 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1943.cpp` | MP1-COD-1943 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1029.cpp` | MP1-COD-1029 | passou | abortou em debug | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_05/1193.cpp` | MP1-COD-1193 | passou | não executado | 1 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_06/2174.CPP` | MP1-COD-2174 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_06/2631.cpp` | MP1-COD-2631 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_06/3358.CPP` | MP1-COD-3358 | passou | não executado | 1 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_06/2091.cpp` | MP1-COD-2091 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_06/1549.cpp` | MP1-COD-1549 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_06/1938.cpp` | MP1-COD-1938 | passou | não executado | 1 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_06/2136.cpp` | MP1-COD-2136 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_06/3036.cpp` | MP1-COD-3036 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_06/1023.cpp` | MP1-COD-1023 | passou | não executado | 2 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_06/1077.cpp` | MP1-COD-1077 | passou | não executado | 1 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_06/2242.cpp` | MP1-COD-2242 | passou | não executado | 1 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_06/1722.cpp` | MP1-COD-1722 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/2747.cpp` | MP1-COD-2747 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/1107.cpp` | MP1-COD-1107 | passou | não executado | 1 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/2065.cpp` | MP1-COD-2065 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/2049.cpp` | MP1-COD-2049 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/1195.cpp` | MP1-COD-1195 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/1340.cpp` | MP1-COD-1340 | passou | abortou em debug | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/1258.cpp` | MP1-COD-1258 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/1548.cpp` | MP1-COD-1548 | passou | divergiu | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/1110.cpp` | MP1-COD-1110 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/1272.cpp` | MP1-COD-1272 | passou | não executado | 2 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/1129.cpp` | MP1-COD-1129 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/3257.cpp` | MP1-COD-3257 | passou | não executado | 2 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/1165.cpp` | MP1-COD-1165 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/2880.cpp` | MP1-COD-2880 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/1049.cpp` | MP1-COD-1049 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/1250.cpp` | MP1-COD-1250 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/1225.cpp` | MP1-COD-1225 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/1147.cpp` | MP1-COD-1147 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/1944.cpp` | MP1-COD-1944 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_04/1763.cpp` | MP1-COD-1763 | passou | divergiu | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_02/1257.cpp` | MP1-COD-1257 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_02/1105.cpp` | MP1-COD-1105 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_02/3301.cpp` | MP1-COD-3301 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_02/1105.c` | MP1-COD-1105 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_02/2854.cpp` | MP1-COD-2854 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_02/1457.cpp` | MP1-COD-1457 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_02/1026.cpp` | MP1-COD-1026 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_02/1192.cpp` | MP1-COD-1192 | passou | não executado | 2 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_02/1030.cpp` | MP1-COD-1030 | passou | não executado | 1 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_02/3068.cpp` | MP1-COD-3068 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_02/1241.cpp` | MP1-COD-1241 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_02/1142.cpp` | MP1-COD-1142 | passou | não executado | 1 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_02/1024.cpp` | MP1-COD-1024 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_02/1168.cpp` | MP1-COD-1168 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_02/1985.cpp` | MP1-COD-1985 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/1039.cpp` | MP1-COD-1039 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/1403.cpp` | MP1-COD-1403 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/3344.cpp` | MP1-COD-3344 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/2729.cpp` | MP1-COD-2729 | passou | não executado | 1 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/2286.cpp` | MP1-COD-2286 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/1962.cpp` | MP1-COD-1962 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/1259.cpp` | MP1-COD-1068 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/2309.cpp` | MP1-COD-2309 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/1037.cpp` | MP1-COD-1037 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/1030.cpp` | MP1-COD-1037 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/1041.cpp` | MP1-COD-1039 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/1045.cpp` | MP1-COD-1039 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/1020.cpp` | MP1-COD-1020 | passou | não executado | 1 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/1863.cpp` | MP1-COD-1863 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/1241.cpp` | MP1-COD-1068 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/3137.cpp` | MP1-COD-3137 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/1555.cpp` | MP1-COD-1555 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/1769.cpp` | MP1-COD-1769 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/1449.cpp` | MP1-COD-1403 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/1196.cpp` | MP1-COD-1196 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/1893.cpp` | MP1-COD-1863 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_03/1068.cpp` | MP1-COD-1068 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/1982.cpp` | BC-1982 | passou | passou em casos limitados | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/1124.cpp` | MP1-COD-1124 | passou | passou em casos limitados | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/2840.cpp` | MP1-COD-2840 | passou | divergiu | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/1291.cpp` | MP1-COD-1291 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/1468.cpp` | BC-1468 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/1549.cpp` | MP1-COD-1549 | passou | passou em casos limitados | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/1126.cpp` | MP1-COD-1126 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/1464.cpp` | BC-1464 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/1378.cpp` | MP1-COD-1378 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/2891.cpp` | BC-2891 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/3068.cpp` | MP1-COD-3068 | passou | passou em casos limitados | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/1315.cpp` | MP1-COD-1315 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/1296.cpp` | MP1-COD-1296 | passou | passou em casos limitados | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/1797.cpp` | MP1-COD-1797 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/1223.cpp` | MP1-COD-1223 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/1576.cpp` | BC-1576 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/1631.cpp` | MP1-COD-1631 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/1295.cpp` | BC-1295 | passou | passou em casos limitados | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/3152.cpp` | MP1-COD-3152 | passou | passou em casos limitados | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_07/1528.cpp` | MP1-COD-1528 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_01/3106.cpp` | MP1-COD-3106 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_01/1163.cpp` | MP1-COD-1163 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_01/1046.cpp` | MP1-COD-1046 | passou | não executado | 1 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_01/1318.cpp` | MP1-COD-1318 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_01/1410.cpp` | MP1-COD-1410 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_01/1017.cpp` | MP1-COD-1017 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_01/1144.cpp` | MP1-COD-1144 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_01/1015.cpp` | MP1-COD-1015 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_01/1367.cpp` | MP1-COD-1367 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_01/1087.cpp` | MP1-COD-1087 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_01/1021.cpp` | MP1-COD-1021 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_01/1581.cpp` | MP1-COD-1581 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_01/1161.cpp` | MP1-COD-1161 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_01/1091.cpp` | MP1-COD-1091 | passou | não executado | 0 aviso(s); ver compilacao.json |
| `01_LISTAS/LISTA_01/1140.cpp` | MP1-COD-1140 | passou | não executado | 1 aviso(s); ver compilacao.json |
| `07_AVALIACOES_EM_SALA/WARMUP_AULA_10/A-didatico.cpp` | MP1-W10-A | passou | não executado | 0 aviso(s); ver compilacao.json |
| `07_AVALIACOES_EM_SALA/WARMUP_AULA_10/A.cpp` | MP1-W10-A | passou | não executado | 0 aviso(s); ver compilacao.json |
| `07_AVALIACOES_EM_SALA/WARMUP_AULA_10/c.cpp` | MP1-W10-C | passou | divergiu | 0 aviso(s); ver compilacao.json |
