# Memoria centrale

## Linking e loading

![Linking e loading](https://i.imgur.com/Y4KDciA.png)

### Swapping

Quando la RAM non basta alcuni PCB vengono tenuti in memoria secondaria. I processi in testa alla ready queue devono essere sempre in memoria centrale. Se il linking non e' dinamico bisogna utilizzare sempre la stessa area di memoria per ogni processo.

## Gestione

### Allocazione contigua

Ogni processo ha un unico segmento contiguo di memoria. Il SO mantiene una lista dei *buchi* disponibili.

I criteri per scegliere il buco adatto:
- first fit
- worst fit
- best fit

Registro di **rilocazione** (base) e registro **limite**.

Se il loading e' dinamico si puo' effettuare un **compattamento** per ridurre la **frammentazione**.

### Paginazione

Memoria divisa in pagine da tot kb.

Lo spazio di indirizzi di un processo puo' essere non contiguo e puo' variare aggiungendo e togliendo pagine.

Serve un supporto hardware -> **Tabella delle pagine**

- **Rilocazione**: da indirizzo logico (p,o) a indirizzo fisico (f,o) pagine/frame
- **PTBR**: Page table base register, tabella in RAM
- **TLB**: Translation look-aside buffer, cache con chiavi (pagina) e valori (frame) per accesso veloce, se la pagina non c'e' (TLB miss) si guarda in RAM

Quando accade TLB miss viene sostituita la pagina usata meno recentemente.

**Struttura tabella**:
- Multilivello (albero, non contigua)
- Hash table
- Invertita (indirizzi (pid,p,o) per ogni frame)

### Segmentazione

- Segmenti di dimensione varia
- Indirizzo logico: <segmento, offset>
- Tabella con indirizzo limite e base
- Si ha frammentazione esterna

Segmentazione su paginazione -> Ogni segmento e' composto da varie pagine
