# Folha Prática 6 ́

## 1.

Considere a rede de fluxo seguinte, onde $c/f$ são pares capacidade/fluxo, e $s$ e $t$ são a origem e destino.

![](graph1.png#gh-light-mode-only)
![](graph1-dark.png#gh-dark-mode-only)

### a)

Indique os valores de:

$f(q, m)$

$f(m, q)$

$f(t, z)$

$|f|$

$c(q, m)$

$c(m, q)$

$c_f(q, m)$

$c_f(m, q)$

$c_f(z, x)$

$c_f(x, z)$

$c_f(p, t)$

$c_f(t, p)$

### b)

Partindo de $f$, aplique o algoritmo de Edmonds-Karp para obter um fluxo máximo (desenhe a rede residual **em cada iteração**, represente o fluxo final na rede, e explique sucintamente).

### c)

Indique um corte $\{S, T\}$ com capacidade mínima.
Qual é a essa capacidade?

### d)

Qual é a diferença principal entre o método de Ford-Fulkerson e o algoritmo de Edmonds-Karp?

## 2.

Considere a rede de fluxo seguinte, onde $c/f$ são pares capacidade/fluxo, e $s$ e $t$ são a origem e destino.

![](graph2.png#gh-light-mode-only)
![](graph2-dark.png#gh-dark-mode-only)

### a)

Indique os valores de:

$f(q, m)$

$f(p, z)$

$f(z, p)$

$|f|$

$c(q, m)$

$c(m, q)$

$cf(q, m)$

$cf(m, q)$

$cf(z, t)$

$cf(p, s)$

$cf(s, z)$

$cf(k, t)$

### b)

Partindo do fluxo $f$, aplique o algoritmo de Edmonds-Karp para obter um fluxo máximo (desenhe a rede residual em cada iteração, represente o fluxo final na rede, e explique sucintamente os passos).

### c)

Complete as frases:

A capacidade do corte $({s, q, t},{p, x, z, m, k})$ é <code title="resposta">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</code>.
<code title="resposta">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</code> é um corte $\{S,T\}$ com capacidade mínima, a qual é <code title="resposta">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</code>.

## 3.

Na figura está representada uma rede de distribuição de água (origem $1$ e destino $6$) e o grafo residual associado a um determinado fluxo $f$ nessa rede.
Os arcos da rede indicam o sentido em que a água flui, e o valor em cada arco indica a capacidade do tubo.

![](graph3.png#gh-light-mode-only)![](graph4.png#gh-light-mode-only)
![](graph3-dark.png#gh-dark-mode-only)![](graph4-dark.png#gh-dark-mode-only)

### a)

Enuncie resultados teóricos dados na disciplina que permitam justificar a não otimalidade do fluxo $f$ associado ao grafo residual representado.

### b)

Determine o fluxo máximo na rede por aplicação do algoritmo de Edmonds-Karp a partir do fluxo $f$.

## 4.

Seja $\mathcal{G} = (V, E, c, \{S, T\})$ uma rede de fluxo com origem no nó $S$ e destino no nó $T$, sendo $E$ o conjunto de ligações representadas abaixo (os pares $c/f$ designam a capacidade da ligação e $f$ o valor do fluxo atual).

|          |   $c/f$   |
| :------: | :-------: |
| $(S, C)$ | $25 / 18$ |
| $(S, D)$ |  $8 / 8$  |
| $(C, H)$ | $10 / 10$ |
| $(C, D)$ | $10 / 5$  |
| $(H, T)$ |  $4 / 4$  |
| $(B, F)$ |  $8 / 5$  |
| $(C, B)$ |  $3 / 3$  |
| $(A, F)$ |  $6 / 5$  |
| $(H, B)$ |  $5 / 4$  |
| $(H, F)$ |  $2 / 2$  |
| $(B, D)$ |  $5 / 2$  |
| $(D, A)$ | $17 / 15$ |
| $(A, T)$ | $10 / 10$ |
| $(F, T)$ | $18 / 12$ |

### a)

Apresente em pseudo-código o método de Ford-Fulkerson e explique os conceitos usados e o critério para verificação da otimalidade de um fluxo representado na rede.

### b)

Determine o fluxo máximo aplicando passo a passo o método a partir da situação representada.

### c)

Identifique um corte de capacidade mínima em $\mathcal{G}$ e diga de quanto aumentaria o fluxo máximo se as capacidades dos arcos $(H, F)$ e $(H, T)$ fossem de 10 e 12 unidades.
Explique.

## 5.

Considere o emparelhamento $M = \{(a_1, p_1), (a_2, p_3 ), (a_4, p_2), (a_6, p_4), (a_7, p_7)\}$ no grafo bipartido seguinte.
Os restantes ramos estão representados a tracejado.

![](graph5.png#gh-light-mode-only)
![](graph5-dark.png#gh-dark-mode-only)

### a)

Represente o problema como um problema de fluxo.

### b)

Determine a rede residual para o fluxo correspondente a $M$.

### c)

Por análise dessa rede, identifique um caminho para aumento de $M$ e determine o emparelhamento $M′$ que se obtém.

### d)

Averigue se $M′$ já é ótimo. Se não for, determine o ótimo.

## 6.

Os valores nos ramos do grafo representam a capacidade das ligações.
Por aplicação do algoritmo dado nas aulas, determine um caminho de capacidade máxima do nó $A$ para cada um dos restantes nós.

![](graph6.png#gh-light-mode-only)
![](graph6-dark.png#gh-dark-mode-only)
