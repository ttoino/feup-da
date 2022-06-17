# Quantas depois

Dada uma sequência de palavras formadas por letras maiúsculas, que se supõe estar ordenada por ordem lexicográfica crescente, pretendemos descobrir precedências entre as letras usadas.

Para descobrir precedências, é útil começar por construir o grafo $G$ da relação formada pelos pares de letras que resultam da análise de palavras **consecutivas**.
Os nós de $G$ correspondem às letras maiúsculas que ocorrem nas palavras dadas.
Uma letra $x$ precede necessariamente outra letra $y$ na ordem procurada se e só se existir um caminho de $x$ para $y$ em $G$.

Embora se admita que a sequência de palavras está bem ordenada, o input pode não determinar de forma única a relação de ordem para as letras.
Assim, pretendemos verificar quantas letras terão de ocorrer **necessariamente** depois de uma maiúscula indicada.

## Input

Inicialmente tem a sequência de palavras, uma por linha.
A sequência termina por `#` e tem sempre pelo menos uma palavra.
Segue-se uma linha que tem uma letra maiúscula que ocorre nessas palavras.

## Output

O número de letras que ocorrem necessariamente depois da letra indicada.

## Exemplo 1

### Input

```
MPMAAC
MPAMJ
MMCAA
MMJA
CAAP
CAAJP
#
P
```

### Output

```
4
```

## Exemplo 2

### Input

```
MPMAAC
MPAMJ
MMCAA
MMJA
CAAP
CAAJP
#
M
```

### Output

```
3
```

## Exemplo 3

### Input

```
MPMAAC
MPAMJ
MMCAA
MMJA
CAAP
CAAJP
#
A
```

### Output

```
0
```

## Exemplo 4

### Input

```
B
MP
MPAB
MPAC
MMCAR
CA
KR
#
P
```

### Output

```
3
```
