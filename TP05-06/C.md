# Sociologia

Os alunos da cadeira de Sociologia decidiram fazer entre eles uma experiência.
Combinaram que cada um inventaria uma história sobre si próprio, a contaria aos colegas com que se relaciona melhor, e lhes contaria também todas as histórias que lhe fossem contadas.
Com base nesta experiência convencionaram considerar que o grupo de uma pessoa seria o conjunto de pessoas, incluindo a própria, cuja história ficou a conhecer e que ficaram a conhecer a sua.
Sabiam que, nessas condições, o grupo de uma pessoa é necessariamente o grupo de cada uma das pessoas do seu grupo.

Pretendiam determinar o número de grupos com quatro ou mais pessoas e o número de pessoas fora desses grupos.
Quando estavam prestes a iniciar a experiência, alguns alunos sugeriram a sua substituição por uma simulação, em computador, para vários cenários hipotéticos.

## Input

Na primeira linha é dado o número de cenários a considerar.
Seguem-se as descrições dos cenários.
A primeira linha de cada cenário contém o número de alunos (≥ 4).
A seguir aparece uma linha por aluno: o primeiro número nessa linha identifica o aluno e o seguinte é o número de alunos com que se relaciona melhor.
Os restantes números nessa linha identificam esses alunos, podendo não haver nenhum.
São usados inteiros consecutivos, a partir de 1, para numerar as pessoas.
**Admita que não tem mais do que 500 pessoas.**

## Output

Para cada cenário, terá uma linha com identificação desse caso e, na linha seguinte, dois inteiros separados por um espaço.
O primeiro é o número de grupos com quatro pessoas ou mais.
O segundo é o número de pessoas fora desses grupos.
Qualquer um dos dois números pode ser 0.

## Exemplo

### Input

```
4
4
1 3 2 4 3
4 0
2 2 1 3
3 2 2 1
6
1 2 3 5
2 2 3 4
4 1 2
3 2 2 1
6 1 5
5 2 6 1
8
1 4 6 2 4 5
3 1 2
2 2 3 4
4 1 5
6 0
5 3 4 8 7
7 1 5
8 2 5 3
10
1 4 6 2 4 5
3 2 2 1
9 0
2 2 3 4
4 2 5 9
6 1 1
5 3 4 8 7
7 1 5
8 1 5
10 1 9
```

### Output

```
Caso #1
0 4
Caso #2
1 0
Caso #3
1 2
Caso #4
2 2
```
