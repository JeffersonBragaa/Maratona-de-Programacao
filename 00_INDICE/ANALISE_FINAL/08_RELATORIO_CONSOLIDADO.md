# Relatório consolidado

A documentação reúne inventário, catálogo e análise técnica do commit `f76157061f41d770ab8579d32c69cba4800bf040`, branch `main`, em 13/11/2026. Foram preservados os materiais originais.

## Resultado e alcance

- 179 arquivos acadêmicos inventariados, 13 PDFs processados e 152 códigos analisados sintaticamente.
- 154 unidades de problema identificadas por conteúdo; duas entradas incompletas e seis exemplos adicionais no catálogo. A identidade oficial de todos os exercícios não está comprovada; números de arquivo conflitantes impedem uma contagem definitiva de problemas de plataforma.
- 37 itens de avaliações-base agrupados em 34 problemas de avaliação; cópias de PDF e reaparições tratadas como ocorrências.
- 151 arquivos passaram na verificação sintática; `vector.cpp` não passou. Não confundir com ligação ou correção.
- 16 campanhas locais: sete passaram em casos limitados, seis divergiram e três abortaram em debug. Uma campanha abrangeu 100 casos aleatórios. Nenhum aceite de juiz foi comprovado.

A cobertura de enunciados das listas é parcial, por ausência dos textos originais e acesso oficial indisponível. Há lacunas de revisão dos microdesafios HTML, de figuras e de validação dos problemas avançados. Assim, **não se certifica uma auditoria integralmente completa ou todas as soluções corretas**. O conjunto está pronto para validação técnica/pedagógica, com pendências explícitas.

## Evidências mais relevantes

1. **Problemas de identificação**: múltiplos nomes numéricos contêm a mesma solução. A apostila faz afirmações sobre código/evolução que divergem dos arquivos atuais. Evidências detalhadas no documento 03 e hashes no manifesto.
2. **Falhas concretas além da geometria**: Figurinhas interpreta conjuntos completos em vez de subconjuntos; Os Suspeitos conta pais de DSU; B do Simulado2 ultrapassa o vetor; Tarjan inicia em 7; tradução perde o primeiro caractere. Ver entradas reproduzíveis em testes.json.
3. **Geometria requer fundamentos e invariantes**: os slides desenvolvem distâncias, divisão e conquista, orientação, fecho e varredura. Códigos adicionais incluem áreas, volumes, projeções e 3D; presença de código não comprova ensino completo ou autonomia.
4. **Avaliações misturam níveis**: contagem e simulação coexistem com conectividade, consultas e problemas avançados. A recorrência comprovada não permite estimar chance de cobrança.
5. **Resolução autônoma não determinada**: há versões didáticas e referências; comentários e arquivos existentes não demonstram autoria nem independência.

## Encaminhamento técnico

Cinco candidatos de geometria: MP1-COD-3068, MP1-COD-3152, MP1-COD-1549, BC-1982 e BC-1295. Alternativas: MP1-COD-1124, MP1-COD-1223 e BC-1576. A decisão pertence ao professor após diagnóstico; ver documento 05.

Prioridades das Listas01–06: DSU, componentes, conectividade dirigida, Dijkstra, estruturas e ordenação, conforme documento 06. Não duplicar famílias equivalentes sem necessidade.

Antes de um simulado independente, validar a familiaridade com cada reserva no documento 07. Não entregar classificações ou soluções da reserva ao estudante durante a avaliação.

## Pendências para completar a cobertura

Obter os enunciados completos e a composição original das Listas01–07; confirmar os nomes conflitantes sem renomear o acervo por inferência; obter evidências de aceites quando existirem; validar limites e figuras geométricas; catalogar microdesafios dos HTMLs se fizerem parte do escopo de exercícios; executar testes específicos para as implementações não testadas. O professor também deve determinar o que foi resolvido com ajuda e avaliar autonomia.

## Documentos

00_MANIFESTO_AUDITORIA.md — fontes, contagens, duplicação e limites.
01_CATALOGO_EXERCICIOS.csv — 162 registros, 23 campos, UTF-8.
02_MAPA_CONTEUDOS.md — exposição, pré-requisitos e inferências.
03_ANALISE_CODIGOS.md — achados e registro dos 152 arquivos.
04_CORRELACAO_AVALIACOES.md — matriz de competências e avaliações.
05_GEOMETRIA.md — os 20 códigos, candidatos e alternativas.
06_CANDIDATOS_TREINAMENTO.md — prioridades técnicas, sem cronograma.
07_RESERVA_SIMULADO.md — seleção provisória sem soluções.
08_RELATORIO_CONSOLIDADO.md — este resumo.
09_HANDOFF_CHATGPT_WEB.md — transferência autocontida.

Anexos: inventario.csv, compilacao.json, testes.json e scripts de reprodução/verificação. Não há publicação automática nem alterações em Notion.
