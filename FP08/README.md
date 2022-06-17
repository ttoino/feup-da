# Folha Prática 8

## 1.

Recordando que Vertex Cover, na versão de decisão, é NP-completo, justifique que não ̃é possível resolver problemas de programação inteira (genéricos) em **tempo polinomial** a menos que $P = NP$.

## 2.

Supondo que $P \neq NP$, classifique o problema enunciado em cada alínea como **membro ou não** das classes de problemas P, NP e NP-completos, **justificando**.
Se for útil, na justificação pode usar conhecimentos sobre outros problemas.

### a)

Dados $n$ e uma sequência $c_1, ..., c_n$ de inteiros positivos, e ainda um valor $k$, decidir se existe $I \subseteq \{1, ..., n\}$ tal que $|I| \geq k$ e $c_i \geq c_j$, qualquer que seja $i \in I$ e $j \in \{1, ..., n\}$, sendo $|I|$ o número de elementos de $I$.

### b)

Dado um grafo não dirigido $G = (V,E)$ e dada uma função $p : V \rightarrow \mathbb{Z}^+$ que associa um peso a cada vértice de $G$ e ainda um valor $P \in \mathbb{Z}^+$, decidir se existe um conjunto de vértices $W \subseteq V$ tal que qualquer que seja a aresta $e \in E$, algum dos extremos de $e$ pertence a $W$, e $\displaystyle \sum_{v \in W} p(v) \leq P$.

### c)

Dado um grafo não dirigido $G = (V, E)$, com $V = \{v_1, v_2, ..., v_n\}$, e dada uma permutação $\pi$ de $\{1, 2, ..., n\}$, decidir se $(v_\pi(1), v_\pi(2), ..., v_\pi(n))$ é um ciclo de Hamilton em $G$.

### d)

Dada uma sequência $v_1, v_2, ..., v_n$, de $n$ inteiros, decidir se está ordenada por ordem estritamente decrescente.

### e)

Dado um sistema de equações lineares $Ax = b$, com coeficientes inteiros e termos independentes inteiros, decidir se é satisfazível no conjunto dos inteiros não negativos.

### f)

Dadas duas sequencias de inteirosˆ xey, comx= (x 1 ,...,xn)ey= (y 1 ,...,yn), com possivelmente ele-
mentos repetidos, decidir sex ́e uma permutac ̧ao de ̃ y, istoe, se existe uma permutac ̧ ́ ao ̃ πde{ 1 , 2 ,...,n},
tal quexk=yπ(k), para 1 ≤k≤n.

## 3.

Seja $\mathbf{A}$ o problema de decidir se existe um caminho de $s$ para $t$ de comprimento maior ou igual a $k$ num grafo $G = (V, E, \omega)$, dados $G$, $s$, $t$ e $k$, com $\omega(e) \in \mathbb{Z}^+$, para $e \in E$.
Seja $\mathbf{B}$ o problema de decidir se existe um caminho de $s$ para $t$ de comprimento menor ou igual a $k$ em $G$, dados $G$, $s$, $t$ e $k$.

Comente a veracidade ou falsidade da afirmação: "*Se $P \neq NP$, o problema $\mathbf{A}$ não se pode reduzir polinomialmente ao problema $\mathbf{B}$, embora o problema $\mathbf{B}$ se possa reduzir polinomialmente ao problema $\mathbf{A}$*".

## 4.

Considere o problema do caixeiro viajante (TSP) num grafo não dirigido $G = (V, E, c)$, onde os custos dos ramos são **inteiros positivos quaisquer**.
Recomendaria um algoritmo **polinomial** que resolvesse **qualquer** instância $I$ do problema com garantia de que o custo $c(\gamma)$ da solução produzida para $I$ fosse no máximo $2c(\gamma^*)$, sendo $\gamma^*$ uma solução ótima?

## 5.

No problema Bin Packing são dados $n$ itens com pesos $p_1, ..., p_n$, tais que $0 < p_i \leq 1$, para todo $i$, e há que os distribuir por latas de capacidade unitária, usando o menor número de latas possível.
Considere o algoritmo seguinte, sendo $n$ e $p$ dados do problema, e $b$ e $x$ *arrays* de $n$ elementos e $n \geq 1$.

$$
\begin{align*}
& \text{FirstFit}(p, b, n, x) \\
& \quad t = 1; \space b[1] = p[1]; \space x[1] = 1 \\
& \quad \bold{for} \space j = 2 \space \bold{to} \space n \space \bold{do}  \space b[j] = 0 \\
& \quad \bold{for} \space i = 2 \space \bold{to} \space n \space \bold{do} \\
& \qquad j = 1 \\
& \qquad \bold{while} \space (j \leq t \space \bold{and} \space p[i] + b[j] > 1) \space \bold{do} \space j = j + 1 \\
& \qquad \bold{if} \space (j > t) \space \bold{then} \space t= t + 1 \\
& \qquad b[j] =b[j] + p[i]; \space x[i] = j \\
& \quad \bold{return} \space t
\end{align*}
$$

### a)

Para a instância $n = 7$ e $p = [0.9 , 0.4 , 0.8 , 0.3 , 0.6 , 0.5 , 0.2]$, qual é o valor final de $x$, $b$ e $t$?
Conclua que FirstFit não determina a solução ótima de Bin Packing.

### b)

Justifique que FirstFit determina em $x$ uma distribuição admissível dos itens pelas latas (i.e., que não excede a capacidade das latas, podendo não ser ótima).
Para tal, indique os invariantes de ciclo que nos permitem chegar a essa conclusão e verifique que são preservados em cada iteração do ciclo correspondente.

### c)

Determine a complexidade temporal assintótica de FirstFit no melhor caso e no pior caso, para instâncias de $n$ items.
Caracterize instâncias de pior caso e de melhor caso.

### d)

rove que FirstFit produz uma solução aproximada, com fator de aproximação 2.
Para isso, justifique que:

- Na solução obtida por FirstFit, podemos ter no máximo uma lata que está com metade ou menos de metade da sua capacidade preenchida. Essa condição verifica-se ao longo da aplicação do algoritmo.

- Consequentemente, $\sum^n_{k = 1} p_k > \frac{1}{2}(t - 1)$, sendo $t$ o número de latas na solução obtida por FirstFit.

- Para o número de latas ótimo $t^*$, tem-se $t^* \geq \lceil \sum^n_{k=1} p_k \rceil$.

## 6.

No problema Partition, são dados $n$ inteiros positivos $a_1, a_2, ..., a_n$, e há que decidir se existe uma partição $\{S,T\}$ do conjunto de índices $\{1, 2, ..., n\}$ tal que $\sum_{i \in S} a_i = \sum_{i \in T} a_i$.
Sabe-se que Partition é um problema **NP-completo**.

### a)

Justifique que as instâncias de Partition com $a_j > \sum_{j \neq i} a_i$, para algum $j$, são trivialmente decidíveis.

### b)

Dada uma instância de Partition, com $a_j \leq \sum_{j \neq i} a_i$, para todo $j$, definimos uma instância de Bin Packing com $p_j= 2a_j / \sum^n_{i = 1} a_i$, para todo $j$.

Justifique que tal instância de BinPacking se obtém em tempo polinomial e que requer pelo menos duas latas, sendo o ótimo igual a 2 se e só se a resposta para Partition for True.
Justifique que, usando essa redução polinomial se pode decidir Partition em tempo polinomial se algum dos algoritmos seguintes existir, e conclua que **não podem existir a menos que P = NP**:

1. um algoritmo polinomial que calcule uma solução ótima para Bin Packing;

2. um algoritmo de aproximação polinomial de razão $c$ para Bin Packing, com $c < 3 / 2$.

## 7.

Considere uma variante de Bin Packing, em que os pesos $p_1, ..., p_n$, são inteiros positivos e dispõe de $m$ latas com capacidades possivelmente distintas, sendo $c_k$ a capacidade da lata $k$, para $1 \leq k \leq m$

### a)

Justifique que o problema da minimização do número de latas é **NP-hard**.

### b)

Recorde os problemas tratados no 1º Trabalho Pratico.
Considerando estes resultados, como classifica a sua complexidade computacional?
