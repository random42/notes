# Transazioni

## Storia

L'esecuzione interfogliata delle transazioni si chiama schedulazione o storia.

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
