# Sobrecarga de trabalhos

Um projeto envolve várias tarefas que terão de ser executadas sem interrupção.
Algumas tarefas podem decorrer em paralelo mas outras não, pois existem precedências entre tarefas.
A equipa que está a realizar o projeto quer terminá-lo o mais rapidamente possível.

O projeto é representado por um grafo dirigido, segundo o modelo arco-atividade.
Cada tarefa é identificada por um ramo $(i,j)$ com um valor $d_{ij}$ , que é a sua duração.
As durações são conhecidas e exatas.
A tarefa $(i,j)$ só pode começar quando as tarefas que têm fim no nó $i$ estiverem concluídas.
Se iniciarmos a tarefa $(i,j)$ no instante $t$, ela estará a decorrer no intervalo $\left[t, t + d_{ij}\right[$.
Notar que o instante final já está fora do intervalo.

Os nós representam acontecimentos.
Assumimos que o grafo tem um único nó com grau de entrada zero e um único nó com grau de saída zero.
Esses dois nós indicam o **início** e o **fim** do projeto.
A equipa irá **começar todas as tarefas o mais cedo possível**, mas respeitará as precedências entre elas.
Queremos determinar o instante em que o projeto fica concluído, o número máximo de tarefas que podem estar a decorrer em paralelo e o primeiro instante em que tal número é atingido.
Alguém nos disse que esse instante será um em que dá início a uma ou mais tarefas.
É verdade?

## Input

A primeira linha tem o número de nós do grafo ($N$) e o número de tarefas ($T$).
Os nós são numerados de $1$ a $N$.
O nó $1$ e o nó $N$ indicam o início e o fim do projeto.
Cada uma das restantes $T$ linhas contém três inteiros positivos $i$, $j$ e $d_{ij}$, que definem uma tarefa.

## Restrições

$2 \leq N \leq 5 000 \text{\space número de nós}$\
$1 \leq r \leq 50 000 \text{\space número de ramos}$\
$1 \leq d_{ij} \leq 100 \text{\space duração de uma tarefa}$

## Output

Uma linha com três inteiros separados por um espaço: a duração mínima do projeto, o número máximo de tarefas a decorrer em paralelo, o primeiro instante em que esse pico acontece.
O instante inicial é 0 (zero).

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
```

### Output

```
21 4 3
```
