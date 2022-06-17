# Folha Prática 5

## 1.

O grafo representa um projeto segundo o modelo arco-atividade.
Os valores nos ramos são as durações das atividades (em **meses**). **O projeto tem de estar concluído o mais cedo possível.**

![](graph1.png#gh-light-mode-only)
![](graph1-dark.png#gh-dark-mode-only)

### a)

Aplique os algoritmos dados nas aulas para determinar $ES[i]$ e $LF[i]$, para cada nó $i$.
Deve anotar o grafo com todos os valores **iniciais**, **intermédios** e **finais**.
Nas anotações, use uma caixa retangular em cada nó, separando claramente os dois algoritmos (ou use dois desenhos do grafo).

Indique ainda a ordem de saída dos nós da fila no cálculo de $ES$ e no cálculo de $LF$, a duração mínima do projeto, e todas as atividades críticas.

### b)

Indique uma atividade com:

1. folga total e folga livre distintas e nao nulas. Quais as suas folgas?
2. folga total e folga livre nula;(iii)
3. folga total ou folga livre nula, sendo uma das folgas nao nula. Quais são os valores dessas folgas?

### c)

Suponha que as tarefas são executadas em máquinas idênticas.
Cada tarefa requer uma máquina.
Cada máquina só pode estar a executar uma tarefa em cada instante.
No instante em que a tarefa termina, a máquina fica livre para executar outra tarefa a partir do mesmo instante, se necessário.

Quantas maquinas são necessárias se se começar todas as tarefas na sua data de início mais próxima?
Pode-se realizar o projeto (dentro do prazo) com menos máquinas?
Se sim, como?
Se não, porquê?

## 2.

Considere um projeto com $n$ tarefas, identificadas por inteiros de $1$ a $n$.
A tarefa $t$ tem duração $d_t$ e requer $k_t$ trabalhadores, para $1 \leq t \leq n$.
Todos os trabalhadores têm as mesmas habilitações.
Cada trabalhador só pode estar envolvido numa tarefa em cada instante.
O instante em que terá de iniciar a tarefa $t$ é $S_t$, sendo um dado.
Qualquer trabalhador pode iniciar uma tarefa no mesmo instante em que conclui outra.

### a)

Apresente (em **pseudocódigo**) um algoritmo para determinar quantos trabalhadores são necessários no mínimo para realizar o projeto nessas condições.
O algoritmo deve necessariamente ter complexidade temporal $O(n \log n)$ e espacial $O(n)$.
Justifique a **correção** e **complexidade** do algoritmo que propuser.

*Note que o número de trabalhadores pode variar em **eventos** de início ou fim de tarefas; a fila de eventos obtém-se dos dados.*

### b)

Implemente o algoritmo que apresentou.

## 3.

Considere um problema de escalonamento de tarefas, com precedências e sem partilha de recursos, representado por DAG segundo o modelo **arco-atividade**.
Admita que tem um único nó sem sucessores e um único nó sem precedentes.
O projeto deverá estar concluído o mais cedo possível.
Seja $D$ a sua **duração mínima**.
Admita que existem tarefas com **folga total** não nula e tarefas com **folga livre** não nula.
Admita também que existem pelo menos **dois caminhos críticos**.

Prove a veracidade ou falsidade de cada uma das afirmações seguintes:

1. Se uma atividade com folga total e folga livre não nula se atrasar de $d$ unidades de tempo, o projeto termina no instante $D + d$.

2. Se todas as tarefas que tem folga livre não nula se atrasarem sem exceder a sua folga livre, então o projeto poderá não estar concluído no instante $D$.

3. Se uma tarefa crítica se atrasar de $d$ unidades de tempo, o projeto termina no instante $D + d$.

4. Nenhuma tarefa $(i,j)$ com folga total não nula pode pertencer a um caminho $(i,j,k)$ no DAG tal que a tarefa $(j,k)$ tem folga livre não nula.

5. Existe uma tarefa com data de início mais próxima igual à data de início mais afastada que se se atrasar de $d$ unidades de tempo, não atrasará nenhuma outra tarefa, mas pode comprometer $D$.

## 4.

O grafo representa um projeto segundo o modelo arco-atividade.
Os valores nos ramos são as durações das atividades (em **meses**).
O projeto tem de estar concluído dentro de dois anos.
Se tal prazo não for cumprido, há que pagar uma indemnização de 1000 u.m. por cada **trimestre** em atraso.

![](graph2.png#gh-light-mode-only)
![](graph2-dark.png#gh-dark-mode-only)

### a)

Aplique os algoritmos dados nas aulas para deter minar $ES[i]$ e $LF[i]$ para cada nó ́$i$.
Deverá anotar os grafos com os valores iniciais, intermédios e finais, e indicar a ordem de visita dos nós.

### b)

Indique todas as atividades críticas.

### c)

Se o cenário descrito se mantiver, qual será o valor da indemnização?
Qual seria o agravamento da indemnização se a atividade que tem duração de 9 meses sofresse um atraso de três ou quatro meses?
Justifique.

## 5.

Considere um projeto constituído por várias tarefas.
É conhecida a relação $\mathcal{R}$ de precedência entre tarefas bem como a duração $d_t$ de cada tarefa (em horas).
A duração do projeto não pode exceder $H$ horas.
É possível reduzir a duração de algumas atividades com contratação de mão-de-obra extra.
O custo é proporcional à redução efetuada e é de $c_t$ u.m./hora para a tarefa $t$ se esta puder ser acelerada.
Nesse caso, a redução total da duração de $t$ não pode exceder $\alpha_t d_t$, sendo $0 < \alpha_t < 1$ uma constante, que depende da tarefa.
Assuma que $\alpha_t = 0$ se $t$ não admitir redução.
Pretendemos determinar um plano para execução das tarefas, com possível redução da duração de algumas tarefas, de forma a garantir (se possível) **a entrega no prazo** $H$ mas **com custo mínimo**.

Admita que $c_t \in \mathbb{Z}^+$, $d_t \in \mathbb{Z}^+$, $\alpha_t \in \mathbb{Q}^+_0$ e que podem ser consideradas reduções fracionárias.

Formule matematicamente o problema.
Indique claramente as variáveis de decisão, os dados, as restrições e a função objetivo, bem como a **interpretação** que tem no contexto apresentado.

## 6.

Admita que um projeto envolve várias tarefas com durações conhecidas e que não partilham recursos.
Vai ser realizado num prazo mínimo e, mesmo assim, algumas tarefas têm folga livre não nula.
Averigue a veracidade ou falsidade de cada uma das afirmações seguintes.

1. Se atrasar o início de uma tarefa usando totalmente a sua folga livre então ela terminará na sua data de conclusão mais afastada.

2. Existem tarefas com folga total não nula.

3. Em alguma fase da execução do projeto há tarefas a decorrer em simultâneo.
