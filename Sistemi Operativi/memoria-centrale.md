## Memoria centrale

### Linking e loading

![Linking e loading](https://i.imgur.com/Y4KDciA.png)

### Gestione

#### Allocazione contigua

Ogni processo ha un unico segmento contiguo di memoria. Il SO mantiene una lista dei *buchi* disponibili.

I criteri per scegliere il buco adatto:
- first fit
- worst fit
- best fit

Registro di **rilocazione** (base) e registro **limite**.

Se il loading e' dinamico si puo' effettuare un **compattamento** per ridurre la **frammentazione**.
