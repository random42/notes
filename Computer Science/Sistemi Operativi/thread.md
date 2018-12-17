## Thread

**Definizione**:

Esecuzione sequenziale di codice.

**Pro**:
- context switch rapido
- meno risorse (perche' condivise)
- comunicazione piu' veloce

### Thread a livello utente

Il processo gestisce lo scheduling, la comunicazione e sono trasparenti al SO.

**Pro**:
- Portabilita'
- Scheduling programmabile
- Esecuzione piu' rapida (no context switch o system calls)

**Contro**:
- Non adattabili in sistemi multiprocessore
- I/O bloccante per il processo intero

### Thread a livello kernel

Gestiti dal SO, quindi piu' costosi.

**Pro**:
- Piu' processori
- I/O non bloccante
- Maggiore interattivita' con l'utente
- Migliori prestazioni dei processi

**Contro**:
- Meno portabilita'
- Se i thread sono troppi si ha un sovraccarico di lavoro per il kernel

### Modelli di thread

#### Uno a uno

Usato su Linux e Windows. Ogni thread utente e' associato a uno kernel.

#### Molti a uno

Un thread kernel per molti utente. Inefficiente.

#### Molti a molti

In questo modello serve uno scheduling dei thread.

Gli **LWP** (lightweight process) sono dei processori virtuale che vengono associati ai thread utente e corrispodono ai thread kernel.

Lo scheduling della CPU e' quindi a **due** livelli:
- PCS: scheduling dei thread sugli LWP
- SCS: scheduling dei thread kernel in ready queue

Nel sistema uno a uno c'e' solo SCS. 
