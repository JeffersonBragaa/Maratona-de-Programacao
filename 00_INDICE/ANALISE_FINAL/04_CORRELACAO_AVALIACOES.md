# Correlação entre fontes e avaliações

Recorrência significa presença observada, não probabilidade de cobrança futura. IDs e todos os caminhos/páginas encontram-se no catálogo. S00/S01/S02 são Simulado Zero/Geral 1/Geral 2; W05/W08/W10 são warmups.

| Competência | Conteúdo | Exercícios | Evidências | Avaliações relacionadas |
|---|---|---|---|---|
| Processar sequências | laços, aritmética e sentinelas | MP1-COD-1170, MP1-COD-1161 | Lista 05/1170 e Lista 01/1161 | S00-B é o mesmo modelo de Blobs; S02-B exige sequência e limites |
| Modelar intervalos | operações acumuladas e consultas | MP1-S00-A, MP1-W05-A/B, MP1-REF-R5 | Simulado Zero p3; warmup05 p3–4; apostila seção12 | Vira Cartas reaparece em S01-A; S01-K amplia para consultas dinâmicas |
| Manter estruturas | pilha, fila e invariantes | MP1-COD-1068, MP1-COD-1340, MP1-COD-1077 | códigos das Listas03/04/06 | S01-B exige histórico de cancelamentos; sem identidade com os códigos listados |
| Ordenar e selecionar | empates, repetição, limites | MP1-COD-1258, MP1-COD-1548, MP1-COD-1023 | comparadores e agregações nos códigos | S02-K exige escolher subconjuntos, não separação de coleções inteiras |
| Contar componentes | DFS e DSU | MP1-COD-1082, MP1-COD-2631 | Aula07 p31–48; códigos das Listas05/06 | W10-C; W10-A acrescenta relações de oposição |
| Menor percurso sem peso | BFS em grade | MP1-S02-L, MP1-COD-2294 | Aula07 p49–59; SIMULADO_02/l.cpp | S02-L e W08-A repetem Fuga da Princesa; 2294 usa grade numérica e não é a mesma tarefa |
| Menor custo ponderado | relaxamento e heap | MP1-COD-1148, MP1-W08-B | DIJKSTRA/b.cpp e dijkstra-aula.cpp | W08-B; S01-F tem custos binários; S02-H/S01-M exigem incorporar o sistema de transporte |
| Conectividade dirigida e pontes | grafo reverso, low-link | MP1-COD-1128, MP1-S02-J | Lista05/1128; SIMULADO_02/j.cpp e j_completo.cpp | S02-J combina conectividade forte, conectividade sem direção e pontes |
| Modelar geometria básica | distâncias, limites, áreas | MP1-COD-1015, MP1-COD-3068, MP1-COD-3152 | Listas01/02/07 | S00-C, S02-A/F, S01-I usam relações geométricas distintas |
| Algoritmos geométricos | ordenação, fechos, varredura | BC-1295/1982/1464/1468/1576 | Aula11 p6–124 | W10-B é geometria de regiões; nenhuma evidência de equivalência direta a skyline/fecho |
| Precisão e monotonicidade | volume e busca binária | MP1-COD-1549, MP1-COD-2840 | Listas06/07; HTML Dividindo a Coca | transferência técnica; não foi encontrada cobrança idêntica nos PDFs de avaliação |

As relações de transferência não são equivalências de problemas. Exemplo: 1128 fornece parte dos fundamentos para Desvio de Rua; isoladamente não resolve as condições de reversão de arestas. Analogamente, saber BFS não basta para Transportes, e área total de polígono não resolve automaticamente a maior região recortada de W10-B.

Repetições confirmadas de enunciado: Vira Cartas (S00-A/S01-A), Transportes (S01-M/S02-H), Fuga da Princesa (W08-A/S02-L). Blobs (S00-B) tem implementação equivalente em Lista05/1170. Os títulos e as regras, não apenas os nomes dos arquivos, fundamentaram essas ligações.

A Lista07 também reaproveita os modelos de 1549 (Lista06) e 3068 (Lista02). Isso pode favorecer comparação de versões, mas impede tratar automaticamente esses problemas como inéditos.
