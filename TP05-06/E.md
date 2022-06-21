# Cronogramas Lda

A Ana trabalha na Cronogramas Lda, uma empresa de organização de projetos.
Para derivar um cronograma das atividades de um projeto, a Ana emprega o **modelo arco-atividade**.
A Beatriz, gerente da empresa, não está interessada em examinar cada cronograma em detalhe, mas deseja de qualquer forma ter uma noção do ritmo de conclusão das atividades.
Assumindo que se dá início ao projeto no instante 0 (zero) e todas as atividades começam o mais cedo possível, quer apenas saber quantas atividades estarão concluídas até um dado instante $t$, para alguns valores de $t$.
Podes ajudar a Ana e a Beatriz?

Tendo em conta o modelo arco-atividade, considere como habitual que:

- Um projeto é representado por um grafo dirigido acíclico.
  O grafo terá um único nó com grau de entrada zero e um único nó com grau de saída zero.
  Esses dois nós indicam o **início** e o **fim** do projeto.
  Os restantes nós também definem acontecimentos.
- Cada atividade é identificada por um arco $(i, j)$ no grafo, com uma duração
associada $d_{ij}$.
- A atividade $(i, j)$ inicia o mais cedo possível, isto é, logo que todas as atividades que têm fim no nó $i$ estiverem concluídas.
  Se começar no instante $x$, decorrerá no intervalo $\left[x, x + d_{ij}\right]$, ficando concluída no instante $x + d_{ij}$.

## Input

A primeira linha tem o número $N$ de nós do grafo e o número $A$ de atividades.
Os nós são numerados de $1$ a $N$.
O nó $1$ e o nó $N$ indicam o início e o fim do projeto.
Cada uma das $A$ linhas seguintes contém três inteiros positivos $i$, $j$ e $d_{ij}$, que definem uma atividade.
Segue-se uma linha com o número $P$ de perguntas feitas pela Beatriz, sendo todas do tipo "Quantas atividades ficam concluídas até ao instante $t$?".
Cada uma das restantes $P$ linhas indica um instante $t$ para o qual se pretende dar a resposta, sendo $t$ inteiro.

## Restrições

$2 \leq N \leq 5 000 \text{\space número de nós}$\
$1 \leq A \leq 50 000 \text{\space número de atividades}$\
$1 \leq d_{ij} \leq 100 \text{\space duração de uma atividade}$\
$1 \leq P \leq 25 \text{\space número de perguntas}$\
$0 \leq t \leq 5 000 000 \text{\space um instante}$

## Output

$P$ linhas, cada uma com dois inteiros separados por um espaço: na linha $k$ terá o instante $t$ indicado na pergunta $k$ e a resposta (isto é, o número de atividades que ficam concluídas até ao instante $t$ **inclusivé**, para $k = 1, ..., P$.

## Exemplo

### Input

```
6 9
1 3 12
1 4 6
1 2 3
2 5 9
2 3 1
3 5 5
3 6 9
5 6 2
4 3 6
10
1
0
12
11
17
21
20
3
5
22
```

### Output

```
1 0
0 0
12 6
11 3
17 7
21 9
20 8
3 1
5 2
22 9
```

### Explicação

Para o exemplo, temos o grafo seguinte:

![](images/graph.png#gh-light-mode-only)
![](images/graph-dark.png#gh-dark-mode-only)

O projeto termina no instante 21. Para cada atividade, o instante de conclusão é:

|       |       |
| :---: | :---: |
| (1,2) |   3   |
| (1,3) |  12   |
| (1,4) |   6   |
| (2,3) |   4   |
| (2,5) |  12   |
| (3,6) |  21   |
| (3,5) |  17   |
| (4,3) |  12   |
| (5,6) |  19   |
