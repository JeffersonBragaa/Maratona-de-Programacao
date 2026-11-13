# Geometria Computacional — Lista 07

Foram lidos os **20 códigos** da Lista07. A análise integral das implementações não equivale a validação integral dos enunciados: só seis IDs/títulos possuem prova visual nos slides; os demais recebem IDs internos e nomes descritivos. Referências `BC-` são comprovadas na Aula11; o campo numérico de outros arquivos é apenas candidato de plataforma.

Ordem de dependências sugerida para avaliação pelo professor: coordenadas e limites → distância e tipos → produto escalar/vetorial → área e projeções → ordenação e fecho → divisão e conquista → eventos e varredura → combinações com DP ou geometria 3D. Volume/busca binária constitui um ramo de modelagem e monotonicidade. Não é cronograma de cinco dias.

## Cobertura das implementações

### MP1-COD-1124 — Acomodação de dois círculos

Fonte: `01_LISTAS/LISTA_07/1124.cpp`; evidências de linhas no catálogo. Conceito: distância ao quadrado; encaixe. Pré-requisitos: comparação de quadrados; tangência; limites de int. Técnica: distância e restrições de retângulo. Complexidade da implementação: O(1). Dificuldade estimada: intermediária; confiança média, condicionada aos limites ausentes.

Relaciona 1015, 1039 e a geometria de encaixe de MP1-S02-F. Teste sintético passou. Relações: MP1-COD-1015 | MP1-COD-1039.

### MP1-COD-1126 — Distância entre tetraedros

Fonte: `01_LISTAS/LISTA_07/1126.cpp`; evidências de linhas no catálogo. Conceito: vetores e projeções 3D. Pré-requisitos: produto escalar; produto vetorial; projeção limitada. Técnica: projeção 3D e distâncias primitivas. Complexidade da implementação: O(1) por par fixo. Dificuldade estimada: alta; confiança média, condicionada aos limites ausentes.

Checar faces degeneradas, segmentos de comprimento zero e a hipótese de sólidos disjuntos: o código não testa explicitamente contenção nem interseção aresta-face. Sem enunciado, não afirmar falha em entrada válida. Relações: MP1-COD-1223.

### MP1-COD-1223 — Folga entre obstáculos alternados

Fonte: `01_LISTAS/LISTA_07/1223.cpp`; evidências de linhas no catálogo. Conceito: distância ponto-segmento. Pré-requisitos: vetores; projeção; distância euclidiana. Técnica: distância ponto-segmento. Complexidade da implementação: O(n). Dificuldade estimada: intermediária; confiança média, condicionada aos limites ausentes.

Divisão por comprimento ao quadrado exige segmento não degenerado. Alternância de paredes e limites do segmento são parte do modelo. Relações: MP1-COD-1126.

### MP1-COD-1291 — Áreas de regiões circulares

Fonte: `01_LISTAS/LISTA_07/1291.cpp`; evidências de linhas no catálogo. Conceito: áreas circulares. Pré-requisitos: áreas de setores; radianos; decomposição. Técnica: fórmulas geométricas. Complexidade da implementação: O(1). Dificuldade estimada: intermediária; confiança média, condicionada aos limites ausentes.

Fórmulas presentes, mas sem figura/enunciado local não se verificou a correspondência entre cada região e a ordem de saída. Relações: MP1-COD-1296 | MP1-COD-3152.

### BC-1295 — Problema dos Pares Mais Próximos

Fonte: `01_LISTAS/LISTA_07/1295.cpp`; evidências de linhas no catálogo. Conceito: par mais próximo. Pré-requisitos: ordenação; recursão; distância ao quadrado; intercalação. Técnica: divisão e conquista. Complexidade da implementação: O(n log n). Dificuldade estimada: alta; confiança média, condicionada aos limites ausentes.

100 instâncias pequenas passaram contra força bruta. Faltam limites oficiais, casos próximos do limiar INFINITY e avaliação em grande escala. Relações: BC-1982.

### MP1-COD-1296 — Área a partir de medianas

Fonte: `01_LISTAS/LISTA_07/1296.cpp`; evidências de linhas no catálogo. Conceito: área a partir de medianas. Pré-requisitos: desigualdade triangular; fórmula de Heron. Técnica: Heron e proporcionalidade. Complexidade da implementação: O(1). Dificuldade estimada: intermediária; confiança média, condicionada aos limites ausentes.

Casos equilateral e degenerado passaram no modelo geométrico. Cuidado com arredondamento e valores quase degenerados. Relações: MP1-COD-1291 | MP1-S00-C.

### MP1-COD-1315 — Partição angular com áreas

Fonte: `01_LISTAS/LISTA_07/1315.cpp`; evidências de linhas no catálogo. Conceito: partição angular e DP. Pré-requisitos: produto vetorial; ordenação polar; fecho; programação dinâmica. Técnica: fechos parciais e programação dinâmica. Complexidade da implementação: O(Bn³) tempo; O(n²+Bn) espaço. Dificuldade estimada: alta; confiança média, condicionada aos limites ausentes.

O pré-cálculo só preenche linhas i<n; a DP consulta inicio+j, que pode ser >=n. Verificar cobertura de intervalos circulares com um oráculo antes de confiar. Hipótese estática, não contraexemplo confirmado. Relações: BC-1982 | BC-2891.

### MP1-COD-1378 — Triângulos isósceles por vértice

Fonte: `01_LISTAS/LISTA_07/1378.cpp`; evidências de linhas no catálogo. Conceito: igualdade de distâncias e contagem. Pré-requisitos: distância ao quadrado; ordenação; combinação de pares. Técnica: agrupamento de distâncias ao quadrado. Complexidade da implementação: O(n² log n). Dificuldade estimada: intermediária; confiança média, condicionada aos limites ausentes.

Validar pontos repetidos, colinearidade e convenção de contagem do enunciado; produtos exigem limites compatíveis com long long. Relações: BC-1295.

### BC-1464 — Camadas de Cebola

Fonte: `01_LISTAS/LISTA_07/1464.cpp`; evidências de linhas no catálogo. Conceito: camadas convexas. Pré-requisitos: orientação; monotone chain; pertinência à borda. Técnica: remoção iterativa de fechos e bordas. Complexidade da implementação: O(n² log n) limite conservador. Dificuldade estimada: alta; confiança média, condicionada aos limites ausentes.

Código remove também pontos colineares nas arestas, não só vértices. Confirmar regra sobre camada degenerada no enunciado completo. Relações: BC-1982.

### BC-1468 — Balão

Fonte: `01_LISTAS/LISTA_07/1468.cpp`; evidências de linhas no catálogo. Conceito: varredura com ordem vertical. Pré-requisitos: eventos; set; interpolação racional; dependências. Técnica: varredura e conjunto ordenado. Complexidade da implementação: O((N+C) log(N+C)) sob invariantes geométricos. Dificuldade estimada: alta; confiança média, condicionada aos limites ausentes.

Comparador depende de atualX; validar invariância da ordem ativa, extremos coincidentes, verticais e overflow dos produtos cruzados. Não basta transportar o exemplo simplificado da aula. Relações: BC-1576.

### MP1-COD-1528 — Deslocamento e rotação simbólica

Fonte: `01_LISTAS/LISTA_07/1528.cpp`; evidências de linhas no catálogo. Conceito: transformações de vetor. Pré-requisitos: simulação de deslocamento e rotação. Técnica: simulação de vetor inteiro. Complexidade da implementação: O(L). Dificuldade estimada: intermediária; confiança média, condicionada aos limites ausentes.

Somente o modelo simbólico do código foi identificado. Correspondência entre comandos e problema oficial não determinada. Relações: MP1-COD-1124.

### MP1-COD-1549 — Dividindo a Coca; título no HTML de apoio

Fonte: `01_LISTAS/LISTA_07/1549.cpp`; evidências de linhas no catálogo. Conceito: volume e busca de altura. Pré-requisitos: volume de tronco de cone; interpolação; monotonicidade. Técnica: busca binária sobre volume. Complexidade da implementação: O(100) por caso. Dificuldade estimada: intermediária; confiança média, condicionada aos limites ausentes.

Versões nas Listas 06 e 07 implementam o mesmo modelo. Caso cilíndrico passou; não comprova todos os limites nem domínio autônomo. Relações: MP1-COD-2840.

### BC-1576 — O Problema da Linha do Horizonte

Fonte: `01_LISTAS/LISTA_07/1576.cpp`; evidências de linhas no catálogo. Conceito: linha do horizonte. Pré-requisitos: ordenação de eventos; multiset; agrupamento por abscissa. Técnica: eventos e multiset. Complexidade da implementação: O(n log n). Dificuldade estimada: alta; confiança média, condicionada aos limites ausentes.

Eventos de mesma abscissa são agrupados antes de emitir mudança; falta testar sobreposições e máximos em múltiplos prédios. Relações: BC-1468.

### MP1-COD-1631 — Equilíbrio de distâncias a retas

Fonte: `01_LISTAS/LISTA_07/1631.cpp`; evidências de linhas no catálogo. Conceito: distância assinada a reta. Pré-requisitos: determinante; normalização; somas de coordenadas. Técnica: produto vetorial e soma de coordenadas. Complexidade da implementação: O(n²). Dificuldade estimada: intermediária; confiança média, condicionada aos limites ausentes.

Usa soma assinada antes do módulo; confirmar que o objetivo é diferença entre lados. Arrays fixos de 100 exigem limite compatível. Relações: MP1-COD-1223.

### MP1-COD-1797 — Alcance entre quadrados

Fonte: `01_LISTAS/LISTA_07/1797.cpp`; evidências de linhas no catálogo. Conceito: distância entre quadrados. Pré-requisitos: separação por eixos; distância ao quadrado. Técnica: distância entre retângulos. Complexidade da implementação: O(n). Dificuldade estimada: intermediária; confiança média, condicionada aos limites ausentes.

Leitor personalizado não lê sinal e não trata EOF no laço de espaços. Validade depende do domínio do enunciado. Expressões em int podem transbordar antes da atribuição a long long. Relações: MP1-COD-1124.

### BC-1982 — Novos Computadores

Fonte: `01_LISTAS/LISTA_07/1982.cpp`; evidências de linhas no catálogo. Conceito: fecho convexo e perímetro. Pré-requisitos: ordenação; orientação; pilha; distância. Técnica: fecho convexo e perímetro. Complexidade da implementação: O(n log n). Dificuldade estimada: intermediária; confiança média, condicionada aos limites ausentes.

Quadrado unitário passou. Testar todos colineares, dois pontos, repetições e grande amplitude. Indicado explicitamente na Aula 11 p74. Relações: BC-1464 | BC-2891.

### MP1-COD-2840 — Quantidade por volume esférico

Fonte: `01_LISTAS/LISTA_07/2840.cpp`; evidências de linhas no catálogo. Conceito: volume da esfera. Pré-requisitos: unidades; divisão real; truncamento final. Técnica: fórmula de esfera e divisão. Complexidade da implementação: O(1). Dificuldade estimada: baixa; confiança média, condicionada aos limites ausentes.

Contraexemplo do modelo: raio 1 e volume 100 dão 25 no programa; volume real permite 23. A variável v inteira trunca antes da divisão. Enunciado oficial não acessível para certificar os limites. Relações: MP1-COD-1549.

### BC-2891 — Um Problema com Final Feliz

Fonte: `01_LISTAS/LISTA_07/2891.cpp`; evidências de linhas no catálogo. Conceito: quadrilátero convexo de cinco pontos. Pré-requisitos: enumeração; fecho; área orientada. Técnica: enumeração de subconjuntos e fecho. Complexidade da implementação: O(1) para cinco pontos. Dificuldade estimada: intermediária; confiança média, condicionada aos limites ausentes.

Cinco subconjuntos de quatro; rejeita fechos com menos de quatro vértices. Saída maior/2 é inteira: conferir garantia de paridade/saída oficial. Relações: BC-1982 | MP1-COD-3152.

### MP1-COD-3068 — Contagem de pontos em retângulo

Fonte: `01_LISTAS/LISTA_07/3068.cpp`; evidências de linhas no catálogo. Conceito: ponto em retângulo. Pré-requisitos: ordem dos limites; comparações inclusivas. Técnica: comparação de coordenadas. Complexidade da implementação: O(n). Dificuldade estimada: baixa; confiança média, condicionada aos limites ausentes.

Versão da Lista 02 normaliza extremos; Lista 07 assume orientação específica dos cantos. Mesmo modelo, requisitos de entrada precisam ser confirmados. Relações: MP1-COD-2424 | MP1-COD-1091.

### MP1-COD-3152 — Comparação de áreas de terrenos

Fonte: `01_LISTAS/LISTA_07/3152.cpp`; evidências de linhas no catálogo. Conceito: área de polígono. Pré-requisitos: determinante; sequência cíclica; valor absoluto. Técnica: área orientada de polígono. Complexidade da implementação: O(1) para dois quadriláteros. Dificuldade estimada: baixa; confiança média, condicionada aos limites ausentes.

Teste com áreas 4 e 1 passou. Empates favorecem B no código; validar regra oficial. Ordem dos vértices é pré-condição. Relações: BC-2891 | MP1-COD-1291.

## Cinco candidatos para decisão do ChatGPT Web

Tempos são estimativas de uma sessão de estudo/resolução com fundamentos disponíveis, não previsão de desempenho individual. Podem crescer substancialmente se o diagnóstico revelar lacunas. Todos têm código disponível: não presumir ineditismo nem autonomia.

| ID / nome | Conceito e competência | Pré-requisitos | Dificuldade | Faixa incerta | Justificativa e evidência |
|---|---|---|---|---|---|
| MP1-COD-3068 — Contagem de pontos em retângulo | converter limites geométricos em predicados | comparações e ordem dos cantos | baixa | 20–45 min | base para testes de fronteira; duas versões Listas02/07; teste local passou |
| MP1-COD-3152 — Comparação de áreas de terrenos | área orientada e ordem cíclica | determinante e tipos inteiros | baixa/intermediária | 35–70 min | introduz produto vetorial com aplicação concreta; Lista07/3152; prepara BC-2891 |
| MP1-COD-1549 — Dividindo a Coca | modelar volume e localizar altura | fórmula, interpolação e monotonicidade | intermediária | 60–100 min | transferência entre matemática e busca; Listas06/07 e laboratório visual; caso cilíndrico passou |
| BC-1982 — Novos Computadores | construir fronteira convexa e medir perímetro | ordenação, orientação, pilha | intermediária | 75–140 min | indicação direta Aula11 p74; aplicação mais simples que camadas; prepara BC-1464 |
| BC-1295 — Problema dos Pares Mais Próximos | justificar e implementar divisão e conquista | distâncias, recursão, merge | alta | 90–180 min | núcleo desenvolvido Aula11 p6–38; 100 casos pequenos passaram; não substitui prova do custo |

Os três primeiros títulos são descritivos ou obtidos do apoio local; pedir o enunciado oficial para confirmar correspondência e limites. Os cinco IDs são distintos. Seleção prioriza diversidade e progressão, não os mais difíceis. Não é decisão pedagógica definitiva.

## Até três alternativas

- **MP1-COD-1124 — Acomodação de dois círculos**: alternativa de modelagem métrica (40–80 min), relacionada a 1015/1039. Boa para limites e tangência; enunciado oficial pendente.
- **MP1-COD-1223 — Folga entre obstáculos alternados**: projeção/distância ponto-segmento (70–130 min), amplia vetores; substituir busca de volume se projeção for prioridade diagnóstica.
- **BC-1576 — O Problema da Linha do Horizonte**: eventos e conjunto de alturas (90–160 min), cobre varredura explícita na Aula11 p124; mais exigente em empates e sobreposições.

BC-1468, MP1-COD-1126 e MP1-COD-1315 não entram automaticamente: acumulam pré-requisitos e apresentam hipóteses ainda não validadas. BC-1464 é extensão natural do fecho, mas seria redundante com BC-1982 dentro de um conjunto pequeno.
