# Como adicionar uma nova PA resolvida:
### 1o) ADICIONAR O NUMERO DELA NA REGRA ALL NO INCIO
# all: <numPA1> <numPA2> <numPA3> <numPA4>
### 2o) ADICIONAR A REGRA DE COMPILACAO DELA
# <numPA>: <numPA>_ana_avelar.c
# gcc -g <numPA>_ana_avelar.c -o <numPA>
### 3o) ADICIONAR LINHA DELA NO CLEAN PARA LIMPAR
#	rm <numPA>

all: 1127 1276

1127: 1127_ana_avelar.c
	gcc -g 1127_ana_avelar.c -o 1127

1276: 1276_ana_avelar.c
	gcc -g 1276_ana_avelar.c -o 1276

clean:
	rm 1127
	rm 1276
