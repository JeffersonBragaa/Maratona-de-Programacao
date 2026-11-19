# Simulado 3 oficial — C03

Simulado Geral 3, realizado em 18/11/2026. Prazo informado pelo aluno: domingo, **22/11/2026**. O primeiro exercício a retomar é **B**; a prioridade dos demais será definida pelo aluno.

## Material e divergências de origem

- `SIMULADO_GERAL_3.pdf`: cópia integral, sem alterações, de `Downloads/simula03oficial.pdf` (14 páginas). O documento identifica a disciplina ECOX21 e o Simulado Geral 3 de 18/11/2026.
- `CODIGOS_SIMULADO_03.zip`: cópia integral de `Downloads/codigos sim03.zip`. Contém códigos e anotações; **não contém PDF**. Não foi encontrado outro ZIP identificado como “Código C03”, nem subpasta de PDFs nos Downloads. Assim, a correspondência do PDF avulso com um PDF dentro do ZIP solicitado ainda não pôde ser verificada.
- A atividade foi informada como tendo **sete exercícios**, mas o PDF encontrado declara e apresenta **oito, de A a H**. A organização abaixo adianta A–G; a inclusão de H no escopo da entrega depende de confirmação. Nenhum enunciado foi removido do PDF.

## Exercícios organizados

| Letra | Título no PDF | Arquivo | Estado |
|---|---|---|---|
| A | Dividindo a Turma | `A.cpp` | Pendente; arquivo vazio |
| B | Papel Furado | `B.cpp` | Pendente; arquivo vazio; primeira tarefa |
| C | Árvore Lagarta | `C.cpp` | Pendente; arquivo vazio |
| D | Cobras no Plano | `D.cpp` | Pendente; arquivo vazio |
| E | Fichas do Fliperama | `E.cpp` | Concluído, conforme confirmação do aluno |
| F | Rosas | `F.cpp` | Pendente; arquivo vazio |
| G | Fusões | `G.cpp` | Concluído, conforme confirmação do aluno |

O PDF também contém **H — Balanceamento de Delimitadores** (página física 14), cujo escopo precisa ser esclarecido.

## Confirmação e preservação dos códigos

O ZIP contém a anotação `E e G feito` em `out.txt`. Ao ser questionado sobre os dois códigos aceitos, o aluno confirmou nesta organização: “G e E foram feitos”. O status de E e G se baseia nessa confirmação explícita do aluno; não foi localizado relatório de submissão do juiz. Não foram usados testes de exemplo como prova de aceite.

`E.cpp` e `G.cpp` são cópias byte a byte de `e.cpp` e `g.cpp` do ZIP; somente os nomes foram padronizados pelas letras do enunciado. Nenhuma solução foi alterada ou implementada.

A tentativa de Papel Furado está preservada, byte a byte, em `TENTATIVAS/B.cpp`, extraída de `b.cpp` do ZIP. O arquivo principal `B.cpp` começa vazio. Também foram preservados `TENTATIVAS/k.cpp` e `TENTATIVAS/Documento_sem_titulo_1.txt`, com os nomes de origem registrados aqui; são rascunhos sobre delimitadores, tema de H no PDF, e não foram tratados como soluções aceitas. Todos os originais continuam disponíveis no ZIP e nos Downloads.

## Dificuldade estimada, sem dicas de solução

Ranking provisório de A–G, considerando o uso de STL, os estudos de grafos, geometria, Union-Find e programação dinâmica já presentes no repositório. Não representa ordem de execução.

| Posição | Letra | Justificativa |
|---|---|---|
| 1 | B | Um único valor, N até 15; pouco código e cuidado com a contagem e os limites numéricos. |
| 2 | G | Tema já praticado; até 100 mil bancos e operações exigem eficiência e reinicialização por caso. |
| 3 | E | Próximo da prática recente; até 100 casos, 20 valores e alvo 10 mil, incluindo casos impossíveis. |
| 4 | A | Até mil alunos e mil réguas; interpretação espacial e desempate exigem atenção. |
| 5 | F | Até um milhão de vasos por caso e limite de 1 s; desempenho e limites dos lotes pesam. |
| 6 | C | Até 100 vértices e 300 arestas; a entrada pode conter ciclos e desconexões e exige validar toda a definição. |
| 7 | D | Grades até 200 × 200; definição de maximalidade e configurações especiais aumentam o cuidado de interpretação. |

O texto de D menciona prolongamento por células de valor 0, apesar de definir cobras com células de valor 1. Essa inconsistência foi preservada no PDF e merece esclarecimento antes da implementação.

## Verificação da organização

Na raiz desta pasta: dois códigos concluídos preservados (`E.cpp`, `G.cpp`) e cinco arquivos `.cpp` com zero bytes (`A.cpp`, `B.cpp`, `C.cpp`, `D.cpp`, `F.cpp`). As tentativas ficam em subpasta, fora dessa contagem. Esta estrutura atende aos sete arquivos A–G, mas não resolve a divergência com os oito problemas do PDF nem a ausência do ZIP oficial com enunciado.
