# Transazioni

## Storia

Esecuzione interfogliata delle transazioni si chiama schedulazione o storia.

Storia(T1 T2): r1(A),w1(A),r1(B),w1(B),r2(A),w2(A),r2(B),w2(B)

### View-equivalenza

La storia S è equivalente (view-equivalente) alla storia S' (S ≡ S') se sono soddisfatte le seguenti condizioni:

- S ed S' sono storie definite sullo stesso insieme di azioni (stesse azioni di read e write su stessi dati con gli stessi indici)
-
**Condizioni sugli input**

- Se in S avviene una ri(X) senza che X sia stato modificato, anche in S' deve avvenire lo stesso
- Se in una storia S una Tj scrive l'oggetto X e successivamente Ti legge X, anche nella storia S' deve succedere la stessa cosa

**Condizione sullo stato**

- Se in S una Ti scrive per ultima l'oggetto X, anche in S' Ti deve scrivere per ultima l'oggetto X

### Criterio di serializzabilità

Il criterio di serializzabilità dice che una storia S è corretta se è view-equivalente ad una storia seriale qualsiasi delle transazioni coinvolte da S

![storie](https://i.imgur.com/qzdsEqR.png)

### Azioni in conflitto
```
S1: ...ri(X),...,wj(X),... (conflitto)
S2: ...wi(X),...,rj(X),... (conflitto)
S3: ...wi(X),...,wj(X),... (conflitto)
S4: ...ri(X),...,rj(X),... (non c'è conflitto)
```

Sono state chiamate azioni in conflitto perché cambiando l'ordine delle due operazioni può cambiare l'attività sulla base di dati o la risposta delle transazioni

### Grafo dei conflitti

**Nodi**: Transazioni della storia

**Archi** (di conflitto):

- Ti -> Tj se Ri(X) e' prima di Wj(X)
- Ti -> Tj dopo che incontro Wi(X) ogni volta che trovo Rj(X) traccio l'arco, fin quando non trovo Wh(X) e quindi costrusco l'arco Ti -> Th

![grafo](https://i.imgur.com/LvDhn1J.png)

### Test di serializzabilita'

Condizione sufficiente di serializzabilita' di una storia S e' che il grafo dei conflitti di S sia **aciclico**.

## Metodi di gestione della concorrenza

**Ottimistici**

Le azioni vengono eseguite senza controlli e alla fine della storia si controlla la serializzabilita'. Dunque si esegue il *commit* o il *rollback*.

### Pessimistici

Prevengono la non serializzabilità della storia. Usano i **lock**.

Ci sono dei comandi per richiedere delle autorizzazioni:

- LS(X): lock shared sull'oggetto X
- LX(X): lock exclusive sull'oggetto X
- UN(X): unlock sull'oggetto X

#### Lock shared

Usato per leggere. Puo' essere condiviso quindi concesso a piu' transazioni.

#### Lock exclusive

Usato per scrivere. E' concesso a una transazione alla volta.

#### Gestione

Quando il DBMS non può concedere il lock,la transazione richiedente va in wait (stato di attesa). Quando la transazione non ha piu' bisogno di leggere/scrivere l'oggetto usa il comando di **unlock**.

Si usa la tabella dei lock.

Le code delle transazioni in attesa vengono gestite con politiche FIFO.

Il sistema dei lock non e' in grado di costruire storie serializzabili.

### Lock a due fasi (2PL)

La politica si chiama "a due fasi" perché c'è una fase di acquisizione dei lock seguita da una fase di rilascio dei lock.

Quando una transazione inizia la fase di rilascio, da quel momento in poi non può più acquisire lock.

Si può dimostrare che la politica del lock a due fasi garantisce la serializzabilità delle storie che genera

### Protocollo a due fasi stretto

La transazione Ti acquisisce lock fin quando può, quando inizia a rilasciare i lock, può solo rilasciare i lock shared (LSi(X), dove X sono oggetti letti da Ti ma non modificati da Ti).

La transazione rilascia i lock exclusive soltanto quando termina (con un commit o rollback).

Cosi' non accadono rollback a cascata perche' le altre transazioni non possono accedere agli oggetti modificati da Ti se non va in commit.

### Protocollo a due fasi forte

- La transazione Ti acquisisce lock fin quando può.
- La transazione rilascia **tutti** i lock soltanto quando termina (con un commit o rollback)

Questi ultimi due protocolli limitano il parallelismo del DBMS

### Gestione del deadlock

1. Analisi del grafo di attesa
2. Timeout
3. Timestamp

#### Grafo d'attesa

Arco da Ti a Tj se Ti e' in attesa di un rilascio da parte di Tj.

C'e' deadlock se c'e' un ciclo nel grafo.

#### Timeout

Se una transazione è in wait da molto tempo (è in timeout), il DBMS la abortisce, supponendo (non è detto che sia vero) che la transazione sia in deadlock.

Il problema dei metodi di gestione del deadlock con timeout è la scelta della soglia di timeout.

#### Timestamp

Transazione *i* arriva prima della transazione *j*.

Due possibilita':

- Se *i* e' in attesa di *j* allora la transazione *j* viene **rollbackata**.
- Se *j* e' in attesa di *i* allora *j* viene messa in stato **wait**.

Quindi ci puo' essere attesa solo da transazioni piu' recenti verso quelle piu' vecchie.
