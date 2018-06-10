## Scheduling CPU

Sarebbe lo scheduling a **breve termine**.

### Criteri

- **throughput** (produttivita'): numero di processi completati nell'unità di tempo
- **turnaround time**: tempo di completamento di un processo, è la somma non solo del tempo di esecuzione e dei vari I/O ma anche di tutti i tempi di attesa legati allo scheduling (attesa di ingresso in main memory, attesa nella coda ready)
- **tempo di attesa**: visto che l'algo. di scheduling della CPU non influisce sui tempi legati all'esecuzione del processo si può considerare anche il solo tempo di attesa trascorso in ready queue
- **tempo di risposta**: nei sistemi interattivi è importante ridurre il tempo che intercorre fra la sottomissione di una richiesta (da parte dell'utente) e la risposta

### Algoritmi

#### FCFS (First come first served)

PCB organizzati in coda FIFO.
**Pro**: ... lel

**Contro**:
- Time-sharing non possibile (piu' utenti)
- Tempi di attesa alti

#### Shortest job first

**Pro**:
- Tempo di attesa ottimale
**Contro**:
- Bisogna prevedere il tempo di CPU in base ai tempi precedenti

Con **prelazione** se quando un nuovo processo ready ha tempo minore del processo running avviene il context switch fra i due.

#### Priorita'

Definita'
**internamente**: caratteristiche del processo
**esternamente**: dall'utente

**Starvation** -> **Aging**

#### Round-robin

Ideato per sistemi *time-sharing*. Coda FCFS ma con un **quanto** di tempo assegnato a ogni processo.

### Code multilivello

La ready queue e' suddivisa in piu' code a seconda delle caratteristiche dei processi (es. *foreground*, *background*). Ogni coda ha una priorita' e un proprio algoritmo di scheduling.
