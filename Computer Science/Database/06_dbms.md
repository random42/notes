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

| | Successo | Insuccesso|
|-|-|-|
|Chiave | (N+1)/2 | N|
|Non chiave | N | N|

**Costo di ricerca sequenziale**:

|| Successo | Insuccesso|
|-|-|-|
|Chiave | (N+1)/2 | (N+1)/2|
|Non chiave | N | N|

## Accesso tabellare (indici)

Usa gli **indici**. Per mantenere gli indici si usano **B-alberi**. Nell'indice in una basi di dati, i nodi dell'albero sono pagine e i puntatori ai livelli inferiori sono PID.

I **B+ alberi** sono uguali ma mantengono tutte le chiavi nelle foglie.

![B-tree](https://www.geeksforgeeks.org/wp-content/uploads/BTreeIntro1.png)

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
CARD(T) | Numero di tuple nella tabella T
N_page(T) | Numero di pagine della tabella T


## Stima dei costi

Per costi si intende il numero di accessi alla memoria secondaria, poiche' molto piu' lenta della RAM.

### Fattore di selettivita'

![fattore](https://i.imgur.com/f3YQTFd.png)

### Costo di selezione

```
Costo di accesso
C_a = C_i + C_d

f_p = fattore selettivita'

C_i = costo di accesso per arrivare alla foglia dell'indice

C_i = f_p * N_foglie(A,T)

C_d = costo di accesso alla pagina dati tramite RID

E_reg = fp * CARD(T) // numero di tuple considerate dalla selezione

C_d = E_reg

Stima in eccesso perche' piu' RID possono essere nella stessa pagina e inoltre
potrei considerare piu' accessi di quante pagine abbia la tabella.

Infatti..

Formula di Cardenas:

C_d = F(E_reg, N_page(T)) = min{E_reg, N_page(T)}

```


![Costi](https://i.imgur.com/i7u99Ex.png)

## Accesso diretto

Accesso con costo O(1)

Bucket = pagina

Si usa una funzione *h* di hashing per determinare il bucket e l'offset di un record tramite una chiave.

La funzione *h* dev'essere suriettiva. Quando ci sono due chiavi uguale si usano le **liste di overflow**.

Solitamente

`h(k)= k mod m`

Dove m e' un numero primo o prodotto di numeri primi.

**Accesso procedurale statico**:

Bisogna avere (m * c) < N spazi in tabella.

**Accesso procedurale dinamico**:

I bucket sono dinamici, possono aumentare o diminuire a seconda dello spazio necessario.

### Indici hash

Sono basati sulle tabelle hash di prima. Sono poco usati perche' ammettono soltanto la ricerca puntuale, non quella di range.

## Ottimizzare le selezioni

```
STUDENTI(MATR*,Nome*,DataNascita*,Genere,Indirizzo)
Nome='Piero' ^ DataNascita>'1990' ^ Indirizzo='TO'(T)
```

**Prima strategia**:

Uso tutti gli indici possibili e calcolo l'intersezione degli insiemi di RID.

**Seconda strategia**:

Calcolo i costi di accesso e uso solo l'indice con costo minore, porto i risultati in memoria e calcolo gli altri predicati


### Algoritmi di join

#### Nested loop

```
per ogni pagina R[i] di R
  per ogni pagina S[h] di S
    Calcola il join di R[i] ⋈Θ S[h]
```
`Costo = Npage(R) + Npage(R) * Npage(S)`

### Nested block join

Anziché caricare una pagina di R e poi eseguire il loop interno, si caricano blocchi di B – 1 pagine di R, e per ogni blocco eseguo un loop completo su S

Costo = Npage(R) + (Npage(R)/(B – 1)) * Npage(S)

### Nested loop con indice

```
per ogni pagina Ri di R
  per ogni tupla t  Ri
    calcola S'= σB Θ t[A](S)
    se |S'| > 0 allora
      restituisce t  S'
```

`Costo = Npage(R) + CARD(R)(CI(S')+ CD(S'))`


### Costo selezione

`Cσ = C_i1+ C_d(MATR,STUDENTI)`

C_i1 = 1 / CARD(STUDENTI) * N_foglie(i1)

C_d = min{E_reg, N_page(STUDENTI)}

E_reg = CARD(STUDENTI) * 1/CARD(STUDENTI) = 1
