## Circuiti

**Combinatori**: l'uscita dipende solo dall'ingresso

**Sequenziali**: l'uscita dipende anche da uno *stato* interno

### Porte logiche
![Porte logiche](https://i.imgur.com/2tkF4JM.png)

### Algebra booleana

- Ā = not A
- AB = A and B
- A + B = A or B
- A + BC = A or (B and C)

**Formula normale disgiuntiva**:

M = ABC + ĀBC

Casi in cui M == 1 uniti dall'OR

**Formula normale congiuntiva**

M = (A+B+C)(Ā+B+C)

Casi in cui M == 0 con variabili invertite unite dall'AND

## Reti combinatorie

### Confrontatore

Vero se x e y sono diversi.

`z = not (x = y)`

### Commutatore

Usato per l'indirizzamento in cui *a* con *m* bit e' l'indirizzo, *2^m* possibili indirizzi definiti da *x*.

x oppure y a seconda di a

`z = if a then x else y`

### Selezionatore

(x,0) (0,x) a seconda di a

```
z1 = if a then x else 0
z2 = if a then 0 else x
```

### Operatori aritmetici/logici

Addizione, sottrazione, shift, rotazione, incremento, decremento...

Implementati dalla ALU.

## Reti sequenziali (automi)

Un automa a stati finiti e' una macchina caratterizzata da:

- *n* variabili di ingresso -> X
- *m* variabili di uscita -> Z
- *r* variabili di stato interno -> S
- Funzione di transizione dello stato interno `f: X x S -> S`
- Funzione di uscita `g: X x S -> Z`

Dato uno stato al tempo *t*:

Lo stato successivo dipende sempre dallo stato precedente e gli input precedenti
```
S(t+1) = f(X(t), S(t))
```
Nella macchina di Mealy le uscite dipendono dallo stato e gli input.
```
Z(t) = g(X(t), S(t))
```

Nella macchina di Moore le uscite dipendono solo dallo stato.
```
Z(t) = g(S(t))
```
