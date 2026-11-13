# Handoff técnico — MP1 / preparação de cinco dias

## Contexto e responsabilidade

Estudante de Sistemas de Informação da UNIFEI; disciplina Maratona de Programação I; C++ como linguagem principal; cinco dias disponíveis. Geometria Computacional é dificuldade declarada pelo estudante. Contato prévio com conteúdos e código existente **não garantem domínio autônomo**. Este documento transmite evidências para o professor individual do ChatGPT Web decidir diagnóstico, seleção e estratégia; nenhum treinamento ou cronograma definitivo foi iniciado.

## Repositório e estado

Raiz local: `~/Documentos/MP1/Maratora-de-Programacao`. Remoto configurado: `JeffersonBragaa/Maratora-de-Programacao`; difere da grafia `Maratona-de-Programacao` informada no pedido. Branch `main`; commit analisado `f76157061f41d770ab8579d32c69cba4800bf040`; data 13/11/2026. Árvore inicialmente limpa, um commit à frente da referência local origin/main. Os relatórios estão em `00_INDICE/ANALISE_FINAL/` e ainda não foram commitados/publicados.

Pastas 00–06 presentes; avaliações de sala em `07_AVALIACOES_EM_SALA`, não `07_EXERCICIOS_DE_SALA`; `Exercicios` ausente.

## Estado da auditoria e limites

179 arquivos acadêmicos inventariados; 152 códigos; 13 PDFs; nove HTMLs. Catálogo com 154 unidades de problema identificadas por conteúdo, duas entradas sem conteúdo suficiente e seis exemplos adicionais. Isso não significa 154 IDs oficiais comprovados: apenas seis IDs Beecrowd foram confirmados nas imagens dos slides; os demais IDs MP1 são identificadores internos estáveis. Duplicatas exatas e reaparições conhecidas foram unificadas. A identidade oficial definitiva e a composição integral das listas continuam pendentes.

Todos os códigos passaram pela verificação sintática: 151 sem erro sintático, um com erro. Isso não garante ligação nem solução correta. Em 16 campanhas locais houve sete resultados compatíveis com os casos testados, seis divergências e três abortos de debug; uma campanha incluiu 100 instâncias aleatórias. Não há evidência de aceite em juiz. Enunciados integrais das listas não estão no acervo, e consultas oficiais selecionadas não ficaram acessíveis. Microdesafios HTML não foram individualmente catalogados, nem todas as figuras/implementações foram validadas integralmente. Tratar esta entrega como auditoria documentada com pendências, não como certificação completa.

## Conteúdos efetivamente sustentados

- Aula 07: definições/representações de grafos, DFS, BFS, componentes e noções de bipartição (PDF p4–61).
- Aula 11: par mais próximo (p6–38), orientação/fecho (p39–74), interseções e varredura (p75–124), tolerância numérica (p123 em imagem).
- Códigos didáticos e avaliações: Dijkstra, Tarjan/pontes, DSU, STL, ordenação, simulações, consultas de intervalo.
- DP está prevista no cronograma e aparece em implementações; a aula correspondente não foi localizada. Não presumir domínio ou cobertura integral de DP avançada, estruturas avançadas ou geometria 3D.

Caminhos dos PDFs: `06_AULAS/MP1_-_Aula_07_-_Intro._Grafos_-_Buscas.pdf` e `06_AULAS/MP1_-_Aula_11_-_GC.pdf`.

## Cinco candidatos de geometria, sujeitos à sua decisão

| ID | Nome / identificação | Foco técnico | Tempo incerto |
|---|---|---|---|
| MP1-COD-3068 | Contagem de pontos em retângulo; nome descritivo, arquivo3068.cpp | limites e predicados | 20–45 min |
| MP1-COD-3152 | Comparação de áreas de terrenos; nome descritivo, arquivo3152.cpp | áreas e orientação | 35–70 min |
| MP1-COD-1549 | Dividindo a Coca; título no apoio local | modelagem de volume e monotonicidade | 60–100 min |
| BC-1982 | Novos Computadores; confirmado Aula 11 p74 | fecho e perímetro | 75–140 min |
| BC-1295 | Problema dos Pares Mais Próximos; confirmado Aula 11 p38 | divisão e conquista | 90–180 min |

Todos estão na Lista 07 e já têm código; 3068 também aparece na Lista 02 e 1549 na Lista 06. Os tempos não são promessa de rendimento. Confirmar enunciados/limites dos três IDs internos antes de aplicar. Alternativas: MP1-COD-1124, MP1-COD-1223 e BC-1576. Veja 05_GEOMETRIA.md para pré-requisitos, razões e análise dos 20 códigos.

Outros candidatos de alta prioridade técnica: MP1-COD-2631 (DSU), MP1-COD-1082 (componentes), MP1-COD-1128 (direção/conectividade), MP1-COD-1148 (caminhos ponderados), MP1-COD-1340 (estruturas) e MP1-COD-1258 (ordenação). Escolher conforme diagnóstico, sem transformar esta lista num cronograma automático.

## Evidências sobre soluções e dificuldades possíveis

- Não presumir que um arquivo numerado resolve o problema sugerido pelo nome. Na Lista 03, 1030 repete 1037; 1041/1045 repetem 1039; 1241/1259 repetem 1068; 1449 repete 1403; 1893 repete 1863. Na Lista 05, 1873 repete 1536. O manifesto contém hashes.
- `LISTA_02/1024.cpp` é esqueleto; `LISTA_03/1196.cpp` está vazio; `SIMULADO_00/c.cpp` é comentário.
- Falhas reproduzidas: K do Simulado 2 diverge do requisito de subconjuntos; c do Warmup 10 subconta conectividade; B do Simulado 2 acessa fora do vetor; exemplo Tarjan deixa vértices sem visitar; 1763 perde primeiro caractere; 2840 trunca volume precocemente no modelo testado.
- A apostila contém relatos incompatíveis com o código atual: atribui Bubble Sort a 1192/1457, prefixos a 1985 e Josephus a Lista 03/1030. Não usar essas afirmações para medir domínio.
- Hipóteses para diagnóstico: leitura do objetivo e dos quantificadores, modelagem, invariantes de estruturas, índices, casos vazios e tipos numéricos. Não são inferências sobre capacidade cognitiva nem prova de autoria.

Caminhos completos, linhas, entradas e saídas estão em 03_ANALISE_CODIGOS.md e testes.json. Nenhuma solução foi corrigida.

## Relações observadas com avaliações

Vira Cartas reaparece nos Simulados 0/1; Transportes nos Simulados 1/2; Fuga da Princesa no Warmup08 e Simulado 2. Blobs também aparece na Lista 05. DSU conecta a Lista 06 ao Warmup 10; conectividade dirigida da Lista 05 é fundamento para Desvio de Rua. As avaliações misturam tarefas básicas e avançadas. Recorrência não é estimativa de probabilidade de cobrança.

## Reserva sem revelação de soluções

Candidatos: MP1-S01-B — Zero para Cancelar; MP1-S01-E — Baralho; MP1-S01-H — Torneio de Tênis; MP1-S01-L — Tempo de Resposta; MP1-S02-F — Painel. Nenhum possui implementação vinculada no acervo analisado, mas todos são potencialmente conhecidos por integrarem avaliações anteriores. Validar ineditismo com o estudante. Detalhes de localização e dificuldade em 07_RESERVA_SIMULADO.md. Não disponibilizar o catálogo técnico durante a aplicação.

## Validação pedagógica pendente

Determinar quais códigos foram escritos independentemente, adaptados ou estudados com ajuda; solicitar demonstração de raciocínio e execução sem consulta; confirmar se os problemas reservados já foram vistos/resolvidos; obter enunciados das listas e eventuais aceites; verificar tempo diário disponível; confirmar o escopo real da aula de DP e do simulado final. Escolher então os cinco problemas e o plano de cinco dias.

## Documentos para consulta

Todos sob `00_INDICE/ANALISE_FINAL/`:00_MANIFESTO_AUDITORIA.md; 01_CATALOGO_EXERCICIOS.csv; 02_MAPA_CONTEUDOS.md; 03_ANALISE_CODIGOS.md; 04_CORRELACAO_AVALIACOES.md; 05_GEOMETRIA.md; 06_CANDIDATOS_TREINAMENTO.md; 07_RESERVA_SIMULADO.md; 08_RELATORIO_CONSOLIDADO.md; 09_HANDOFF_CHATGPT_WEB.md. Anexos: inventario.csv, compilacao.json, testes.json e scripts. O catálogo tem evidências e lacunas por registro; este handoff não substitui os documentos técnicos.

Para usar no ChatGPT Web, anexar este handoff e os relatórios, CSV e PDFs relevantes. Caminhos locais não são acessíveis ao ChatGPT Web por si sós. Não houve criação de Notion, publicação ou commit da auditoria.
