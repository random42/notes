# Memoria virtuale

Non c'e' il vincolo per cui ogni processo deve essere caricato interamente in RAM.
- Si possono eseguire programmi che chiedono piu' della RAM
- Non ci sono vincoli di memoria
- Si migliora l'uso della RAM
- Maggiore multiprogrammazione
- Meno tempo di swap

La tabella della pagine del processo contiene un *bit di validita'* per indicare se la pagina e' in RAM o meno.

Quando si richiede una pagina mancante avviene un'interruzione di **page fault**.

### Sostituzione di pagine

Si tiene un bit (**dirty bit**) per indicare se una pagina in RAM e' stata modificata dalla sua copia in memoria secondaria, cosi si evita di ricopiarla.

## Allocazione frame dei processi utente

Si cerca di avere un minimo di frame allocati per processo per diminuire i page fault.
- proporzionale
- uniforme

### Trashing

Troppi page fault perche' un processo o piu' ha piu' pagine attive dei frame allocati. Si aggrava se l'SO monitora la CPU e vedendo che viene usata di meno aumenta la multiprogrammazione.

Soluzione...

### Working set

Sarebbe le pagine attive di un processo, si basa sul principio di localita'. Viene definito un numero *PI* di ultimi accessi alla memoria da guardare per capire il working set del processo. Se PI e' troppo piccolo il working set e' errato, se e' troppo grande e' superfluo e viene sprecata RAM.


## Allocazione frame per il kernel

Al SO spesso servono aree contigue oppure molto piccole.

### Sistema buddy

Si usano segmenti di potenze di due. Risulta in un'alta frammentazione interna.

### Allocazione a slab

**slab**: Pagine fisicamente contigue
**cache**: insieme di slab
**istanza**: istanza di un tipo di dato contenuto nella cache

C'e' una cache per ogni struttura (semafori, PCB, file...). Ogni *istanza* di una cache puo' essere libera o occupata. Quando si richiede una nuova istanza non disponibile si cerca un nuovo slab e lo si assegna alla cache.


## Algoritmi di sostituzione delle pagine

### FIFO

Si sostituisce la pagina in memoria da piu' tempo. Non e' efficiente perche' una pagina potrebbe essere in memoria da molto tempo e comunque usata frequentemente.

### Algoritmo ottimale

Si sostituisce la pagina che non verrà usata per il periodo di tempo più lungo. Non e' applicabile ovviamente.

### Least-recently used

A ogni pagina si associa un marcatore temporale che corrisponde all'**istante di ultimo utilizzo**. Si sceglie la pagina usata meno di recente.

Serve un'architettura per mantenere il riferimento temporale a ogni accesso in memoria.

### Approssimazione LRU con bit di riferimento

Registro con bit a scorrimento. Il bit piu' significativo indica se la pagina e' stata utilizzata nell'ultimo periodo di tempo. Quindi la pagina usata meno recentemente negli ultimi *bit* periodi di tempo e' quella con valore minimo nel registro.
