# Mapa dos conteúdos

As referências abaixo distinguem exposição explícita, necessidade inferida de problemas e simples menção. Não representam domínio do estudante.

| Competência | Fonte verificável | Natureza e profundidade | Dependências e exercícios |
|---|---|---|---|
| Tipos, entrada, laços e condições | códigos das Listas 01–03; catálogo individual | uso explícito nas implementações | base transversal; MP1-COD-1015, MP1-COD-1105 |
| STL e ordenação | `06_AULAS/vector.cpp`; `01_LISTAS/LISTA_04/1258.cpp`; apostila seções 3–4 | exemplos explícitos; rascunho vector não compila | comparadores, chaves, iteração; MP1-COD-1340, MP1-COD-2729 |
| Modelagem e representação de grafos | Aula 07, p4–30 | ensino explícito: matriz, lista de adjacência, lista de arestas | índices, direção, pesos, densidade |
| DFS/BFS e componentes | Aula 07, p31–61 | ensino explícito com percurso e código; bipartição nas p60–61 | pilha/fila, visitados; MP1-COD-1082, MP1-COD-1128, MP1-S02-L |
| Dijkstra | `03_ALGORITMOS/DIJKSTRA/dijkstra-aula.cpp`:L16–43; Aula 11 p2 | implementação didática e menção retrospectiva | relaxamento, pesos não negativos, heap; MP1-COD-1148, MP1-W08-B |
| Tarjan e pontes | `03_ALGORITMOS/TARJAN/aula.cpp`:L14–35; `SIMULADO_02/j.cpp`:L29–47 | código didático e aplicação; SCC e pontes são conceitos diferentes | DFS, tempos, low-link; MP1-S02-J |
| DSU | Aula 11 p2; `01_LISTAS/LISTA_06/2631.cpp`:L5–29; Warmup 10 p3 e p7 | uso explícito; aula própria não localizada | representantes, união por tamanho, compressão; MP1-W10-A/C |
| Consultas de intervalo | Aula 07 p3 cita Range Query; Warmup 05 p3–4 | cobrança explícita; cobertura didática completa não localizada | prefixos, sinais, atualizações; MP1-W05-A/B; MP1-S00-A |
| Par mais próximo | Aula 11 p6–38 | desenvolvimento explícito de força bruta para divisão e conquista | distâncias, ordenação e merge; BC-1295 |
| Orientação e fecho convexo | Aula 11 p39–74 | desenvolvimento explícito, inclusive monotone chain p62–73 | determinante, ordenação, remoção de vértices; BC-1982/1464/2891 |
| Interseção e varredura | Aula 11 p75–124 | intervalos, eventos, predicados e Shamos–Hoey explícitos | set, ordem vertical, degenerações; BC-1468/1576 |
| Precisão numérica | Aula 11 p123 (imagem) | nota explícita sobre double/EPS | escala, arredondamento e colinearidade |
| Áreas, volumes e projeções | Lista 07; HTML Dividindo a Coca | necessidade observada nos códigos; nem todas as fórmulas ensinadas nos slides disponíveis | MP1-COD-3152/1549/1223/1126 |
| Programação dinâmica | Aula 07 p2 (cronograma); Lista 05/1029; Lista 07/1315 | prevista e implementada em casos; não há aula de DP disponível | estados, transições e bases; não extrapolar para domínio geral |
| Problemas avançados de avaliação | Simulado 1 D/G/K e Simulado 2 G/H | existem enunciados; solução eficiente não estabelecida nesta auditoria | combinação de otimização, geometria, consultas e estados; ver lacunas no catálogo |

Aula 07 significa `06_AULAS/MP1_-_Aula_07_-_Intro._Grafos_-_Buscas.pdf`; Aula 11 significa `06_AULAS/MP1_-_Aula_11_-_GC.pdf`. Outros enunciados e páginas constam do CSV.

Pré-requisitos transversais: interpretar formato e limites → escolher modelo → justificar complexidade → estabelecer invariantes → implementar índices e estado → confrontar com casos de fronteira. Essa é uma relação técnica, não um cronograma.

Não adicionar fluxo máximo, Kruskal ou coloração geral como conteúdos dominados: a Aula 07 menciona exemplos/aplicações, mas não oferece desenvolvimento desses algoritmos. Programação dinâmica avançada e estruturas de intervalo sofisticadas aparecem como necessidades possíveis em enunciados; isso não comprova que foram integralmente ensinadas.

A implementação de interseção geral na Aula 11 p93 trata contato e colinearidade; o trecho p115 trata apenas cruzamento próprio. Os cuidados da p113 são essenciais para interpretar o alcance do código posterior. Não usar o trecho simplificado como biblioteca geral sem explicitar hipóteses.
