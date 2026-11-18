# Minissimulado AC5

**Abrir somente no início da tentativa.** Leia os três enunciados juntos durante a triagem. R1 e R2 são obrigatórios. R3 é opcional dentro do mesmo orçamento.

**150 minutos totais.** Use 10 para triagem, 130 compartilhados para resolver e 10 para registrar. A ordem é livre e você pode alternar questões. Durante a tentativa, trabalhe sem códigos antigos, dicas ou soluções. Os textos abaixo são versões em português do enunciado oficial de cada problema.

## R1 — Ferris Wheel

Cada uma de `n` crianças precisa ocupar um lugar numa gôndola de roda-gigante. Uma gôndola comporta uma ou duas crianças e o peso total de seus ocupantes deve ser no máximo `x`. Dados os pesos de todas as crianças, determine a menor quantidade de gôndolas que acomoda o grupo inteiro.

### Entrada

A primeira linha contém `n` e `x`, a quantidade de crianças e o limite de peso por gôndola. A segunda contém os `n` pesos `p₁, p₂, …, pₙ`.

### Saída

Imprima um único inteiro, a menor quantidade de gôndolas necessária.

### Restrições

- `1 ≤ n ≤ 2 × 10⁵`
- `1 ≤ x ≤ 10⁹`
- `1 ≤ pᵢ ≤ x`
- Tempo de execução de 1,00 s e limite de memória de 512 MB.

### Exemplo

Entrada

```text
4 10
7 2 3 9
```

Saída

```text
3
```

Fonte oficial. [CSES 1090](https://cses.fi/problemset/task/1090)

## R2 — Building Roads

Byteland tem `n` cidades ligadas por `m` estradas de mão dupla. Quer-se acrescentar estradas até ser possível ir de qualquer cidade a qualquer outra. Determine a quantidade mínima de estradas novas e indique quais podem ser construídas.

### Entrada

A primeira linha contém `n` e `m`, a quantidade de cidades e a quantidade de estradas existentes. As cidades são numeradas de 1 a `n`. Cada uma das `m` linhas seguintes contém `a` e `b`, as cidades ligadas por uma estrada. As duas cidades de cada estrada são distintas e existe no máximo uma estrada entre cada par de cidades.

### Saída

Na primeira linha, imprima `k`, o número mínimo de estradas novas. Nas `k` linhas seguintes, imprima dois inteiros por linha, as cidades que cada nova estrada liga. Qualquer solução válida é aceita.

### Restrições

- `1 ≤ n ≤ 10⁵`
- `1 ≤ m ≤ 2 × 10⁵`
- `1 ≤ a, b ≤ n`
- Tempo de execução de 1,00 s e limite de memória de 512 MB.

### Exemplo

Entrada

```text
4 2
1 2
3 4
```

Saída

```text
1
2 3
```

Fonte oficial. [CSES 1666](https://cses.fi/problemset/task/1666)

## R3 — Playlist (opcional)

Uma rádio registrou as `n` músicas que tocou, em ordem. Qual é o comprimento do maior trecho de músicas consecutivas em que nenhuma música se repete?

### Entrada

A primeira linha contém a quantidade `n` de músicas. A segunda contém `n` inteiros `k₁, k₂, …, kₙ`, os identificadores das músicas na ordem em que foram tocadas.

### Saída

Imprima um inteiro, o comprimento do maior trecho consecutivo com músicas distintas.

### Restrições

- `1 ≤ n ≤ 2 × 10⁵`
- `1 ≤ kᵢ ≤ 10⁹`
- Tempo de execução de 1,00 s e limite de memória de 512 MB.

### Exemplo

Entrada

```text
8
1 2 1 3 2 7 4 2
```

Saída

```text
5
```

Fonte oficial. [CSES 1141](https://cses.fi/problemset/task/1141)
