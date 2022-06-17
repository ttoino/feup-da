# Sob pressão

Avesso Industry Co. Ltd. depara-se com um novo problema (ou com dois, já que o funcionário experiente se reformou).
É necessário distribuir um certo número de tarefas por igual número de trabalhadores.
Estes têm exatamente as mesmas habilitações.
Cada trabalhador indicou as suas preferências, ordenando as tarefas por ordem de preferência estritamente decrescente.
A empresa pretende uma solução (i.e., afetação dos trabalhadores às tarefas) que possa ser razoável, tendo em conta as preferências dos trabalhadores.
Em particular, deverá ser *Pareto-ótima*, ou seja, não se conseguirá fazer uma troca que melhore o nível de satisfação de algum trabalhador sem piorar o de algum dos restantes.

Pretende-se um programa para ajudar a escolher a solução menos impopular num conjunto de propostas.
O índice de impopularidade da solução $S$, denotado por $u(S)$, é o valor máximo de $\varphi(S', S)/\varphi(S, S')$ quando consideradas todas as alternativas $S'$, sendo $\varphi(S', S)$ o número dos trabalhadores que preferem estritamente $S'$ a $S$ e $\varphi(S, S')$ o número dos trabalhadores que preferem estritamente $S$ a $S'$.
Os indiferentes não contam.

O valor do **índice de impopularidade** $u(S)$ pode ser obtido facilmente.
R. M. McCutchen, em <http://dx.doi.org/10.1007/978-3-540-78773-0_51>, provou que, se $S$ for Pareto-ótima, $u(S)$ é igual ao comprimento do caminho máximo no grafo acíclico $G_S = (T, E_S)$ assim definido: $T$ corresponde ao conjunto das tarefas e $E_S$ é o conjunto dos pares $(i, j)$ tais que o trabalhador que, segundo $S$, desempenhará a tarefa $i$ preferia $j$ a $i$, para $i$, $j$ pertencentes a $T$.
Se $G_S$ tiver ciclos, $S$ não é Pareto-ótima.

## Input

A primeira linha tem um inteiro $n$ que representa o número de trabalhadores (ou tarefas).
Segue-se uma tabela de $n$ linhas: a linha $k$ contem a lista de preferências do trabalhador $k$, para $k = 1, ..., n$.
Depois tem o número de propostas, seguindo-se igual número de linhas.
Cada linha representa uma proposta: $k$-ésimo elemento identifica a tarefa que o trabalhador $k$ executará segundo essa proposta.
Assume-se que as tarefas são numeradas de $1$ a $n$.
Pode assumir que $n$ não excede 100.

## Output

Os índices de impopularidade das propostas.
Caso a proposta não seja Pareto-ótima, escreverá `Indeterminado (nao Pareto-optima)`.

## Exemplo

### Input

```
7
1 2 3 6 7 5 4
1 2 3 5 6 7 4
4 1 2 3 5 7 6
3 1 2 5 7 6 4
1 2 3 6 4 5 7
1 2 3 6 7 4 5
2 1 3 4 5 6 7
6
1 5 4 3 2 6 7
2 3 7 1 6 5 4
1 5 4 3 6 7 2
1 5 4 3 2 7 6
2 3 5 7 4 1 6
6 1 4 3 5 7 2
```

### Output

```
3
Indeterminado (nao Pareto-optima)
2
4
Indeterminado (nao Pareto-optima)
2
```
