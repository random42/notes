# DMBS

![schema](https://i.imgur.com/WwRZ3fb.png)

### Legenda

- Il gestore delle transazioni gestisce il ciclo di vita delle transazioni
- Il serializzatore e' responsabile della proprieta' di **isolamento**, ovvero fa in modo che le transazioni vengano eseguite in modo isolato
- Il gestore di ripristino e' responsabile dell'**atomicita'**. Ripristina i dati se ci sono guasti (*integrita'*) per cui le transazioni vengono eseguite interamente o per nulla.
- Il gestore del buffer e' responsabile della **durabilita'** (persistenza) dei dati.

La **consistenza** e' di competenza del gestore delle transazioni e del serializzatore.


### Pagine

Una pagina è composta da un certo numero di blocchi fisici. I blocchi fisici, a loro volta, sono composti da un certo numero di settori. In questo corso, però, confonderemo il blocco fisico con la pagina (dimensione blocco = dimensione pagina). Il dimensionamento della pagina è importante perché influisce sulle prestazioni dell'intero DBMS

![Pagine](https://i.imgur.com/8LF96Ew.png)

### RID (Record Identification)

L'architettura di RID consente al file system la possibilita' di modificare la posizione dei record a piacimento senza influenzare gli indirizzi esterni. Il gestore deve solo modificare l'offset dell'array.

### Gestore del buffer

![buffer](https://i.imgur.com/nELeVCa.png)

Comando | Descrizione
-|-
FIX | richiesta di accesso ad una pagina
USE | richiesta di utilizzo di una pagina per cui l'applicazione ha già ottenuto l'accesso
UNFIX | quando un'applicazione non ha più bisogno di una pagina, lo comunica al gestore (CP:= CP – 1)
FORCE | l'applicazione impone al gestore del buffer di trasferire la pagina dal buffer alla periferica
FLUSH | comando usato dal gestore del buffer per trasferire una pagina sulla periferica

### Comando FIX

![FIX](https://i.imgur.com/Ns6UYfI.png)

### Organizzazione per dati ordinati

Le pagine sono ordinate. Quando devo inserire un record e la pagina e' piena uso una pagina di *overflow*. Cio' determina un calo di performance.

### Cluster

![cluster](https://i.imgur.com/dCQLXih.png)

I record della stessa tabella devono pero' essere linkati tra di loro nel caso ci si debba iterare sopra.


## Ottimizzatore fisico

### Accesso sequenziale/seriale

**Sequenziale**: Tuple ordinate

**seriale**: Non ordinate

**Costo di ricerca seriale**:

 | Successo | Insuccesso
-|-|-
Chiave | (N+1)/2 | N
Non chiave | N | N

**Costo di ricerca sequenziale**:

 | Successo | Insuccesso
-|-|-
Chiave | (N+1)/2 | (N+1)/2
Non chiave | N | N

### Accesso tabellare (INDICI)

Usa gli **indici**. Per mantenere gli indici si usano **B-alberi**. Nell'indice in una basi di dati, i nodi dell'albero sono pagine e i puntatori ai livelli inferiori sono PID.

I **B+ alberi** sono uguali ma mantengono tutte le chiavi nelle foglie.

#### Indice principale
E' definito sulla chiave primaria. 0 o 1 in ogni relazione

#### Indici secondari
Tutti gli altri. 0 o piu' in ogni relazione

#### Indice denso

E' un indice con tante chiavi di ricerca quanti sono i valori distinti dell'attributo su cui è costruito

#### Indice clusterizzato

Indice per cui l'ordine delle chiavi rispecchia l'ordine dei record nella memoria. Ci puo' essere al massimo un indice clusterizzato per tabella.

#### Indice sparso

Nelle foglie dell'indice non ci sono più tutte i valori distinti della
chiave di ricerca ma solo un valore della chiave (il massimo)
Nella pagina indicata dal puntatore si trovano tutte le chiavi ≤ al valore massimo ma strettamente maggiori della chiave del nodo padre

![sparse_index](https://i.stack.imgur.com/LNBgI.png)

#### Data entry

`<k,tupla>`: il data entry è la tupla stessa

`<k,RID>`: il data entry è puntatore al record nell'area primaria

`<k,lista_di_RID>`: il data entry è una lista di puntatori a record che condividono la stessa chiave k


### Dizionario dati

Conserva statistiche sul DB:

Espressione | Significato
-|-
VAL(A,T) | Per ogni attributo A il numero dei valori distinti in una tabella T.
N_foglie(A,T) | Numero di pagine che costituiscono le foglie di un indice (denso)
CARD(T) | Numero di record in tabella
N_page(T) | Numero di pagine della tabella


### Stima dei costi
