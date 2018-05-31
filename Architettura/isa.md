# Isa

![Isa](https://i.imgur.com/0E61qtF.png)

Gli operandi byte, const, e varnum hanno dimensione di 1 byte, disp, index, e offset sono di 2 byte.



### Memoria

![Memoria](https://i.imgur.com/hkl8vU6.png)

### Stack

![Stack](https://i.imgur.com/fENxhLr.png\))

Contiene:
- puntatori di servizio, necessari per il meccanismo di all’atto della sua chiamata;
- parametri passati al programma (o al sotto
- lo spazio riservato per le variabili locali.
- Il registro **LV**, contenuto nella CPU, viene usato per puntare alla base dello stack di esecuzione della procedura correntemente in esecuzione

### Registri

Registri | Uso
-|-
PC | prossima istruzione da eseguire, *1 byte*
CPP | constant pool
LV | Stack di esecuzione
SP | Operand stack

### Esempi programmazione IJVM
```
.main
    LDCW objref
    BIPUSH -1
    BIPUSH -10
    INVOKEVIRTUAL cmp
    BIPUSH 1
    IF_ICMPEQ EQ
EQ: HALT
.end-main

.method cmp(p1,p2)
.var
temp
.end-var
    ILOAD p1
    ILOAD p2
    ISUB
    ISTORE temp
    ILOAD temp
    IFLT lt
    ILOAD temp
    IFEQ eq
gt: BIPUSH 1
    GOTO done
lt: BIPUSH -1
    GOTO done
eq: BIPUSH 0
done: IRETURN
.end-method
```
