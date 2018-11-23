# Normalizzazione

## Dipendenze funzionali

Correlazione tra un attributo e altri attributi. Ad esempio su uno studente:

MATR -> NomeS, IndirizzoS, CAPS, CodiceFiscaleS, DataNascitaS

**Definizione**:

Data una relazione r(A), un sottinsieme X di attributi di A (X sottoinsieme di A), un altro sottinsieme Y di attributi di A (Y sottoinsieme di A) il vincolo di dipendenza funzionale X -> Y (X determina Y) è soddisfatto se e solo se

Per qualunque t1,t2 appartenenti a r (se t1[X]=t2[X] allora t1[Y]=t2[Y])

### Attributi estranei

Un attributo A e' un attributo estraneo (e si puo' cancellare) in una dipendenza se
- B,A -> C
- B -> A

Per cui diventa:

- B -> C
- B -> A

### Chiusura

La chiusura di un insieme di attributi *A* e' l'insieme di tutti gli attributi raggiungibili tramite dipendenze dagli attributi di A in modo ricorsivo.


### Superchiave

Data una relazione r(A), un insieme di attributi K ⊆ A è superchiave quando nella relazione r vale il vincolo di dipendenza funzionale K -> A

Quindi K e' una superchiave quando la sua chiusura contiene A.

## Normalizzazione

La normalizzazione consisterà nel partire da relazioni (come ESAMI) e dividerle in schemi di relazione che minimizzino le anomalie.

## Boycr-Codd Normal Form (BCNF)

Data una relazione R(A) in 1NF abbinata a delle dipendenze funzionali F, la relazione è in BCNF se, per ogni X -> Y appartenente a F si verifica una delle seguenti condizioni:
1. Y sottoinsieme di X (X ->Y è una dipendenza riflessiva)
2. X è superchiave di R

#### Procedura

1. Parto dallo schema di basi di dati SC = {(Ri(Ai),Fi)}
2. Cerco, all'interno di SC, una (Ri(Ai),Fi) non in BCNF. Cioè, cerco in Fi almeno una d.f. X -> Y non BCNF ovvero

`(Y non e' incluso in X) AND (X non superchiave di Ri(Ai))`

3. Se non esiste una X -> Y non BCNF mi fermo (SC è già
in BCNF)
4. Se esiste una X -> Y non BCNF occorre effettuare una trasformazione dello schema

#### Modifica schema

1. Tolgo la relazione non in BCNF da SC. SC: = SC – (Ri(Ai),Fi)
2. Aggiungo ad SC due nuove relazioni con le relative dipendenze funzionali
– SC: = SC ⋃ (R1(Ai – Y), F1)
– SC: = SC ⋃ (R2(XY), F2)
dove F1 è la restrizione di Fi in R1(Ai – Y) ed F2 è la restrizione di Fi in R2(XY)
3. Torno al passo 2 della procedura

#### Esempio

STUDENTI(MATR,NS,IS,CAP,PROV)

F = {MATR -> NS,IS; IS -> CAP; IS -> PROV}

Diventa:

R1(MATR,NS,IS), R2(IS,PROV), R3(IS,CAP)

## Terza forma normale

Una relazione (R(A),F) è in 3NF (IIIa forma normale) se, per ogni ogni X => Y appartenente a F si verifica una delle seguenti condizioni

1. Y incluso in X (X -> Y è riflessiva)
2. X è superchiave
3. Y sono attributi primi

**Attributi primi**: Gli attributi Y incluso in A sono detti attributi primi, se Y incluso in K, dove K è chiave di R(A)

### Insieme di copertura minimale

Un insieme F' di dipendenze funzionali è un insieme di copertura minimale rispetto ad F quando:
1. F' ≡ F (F' è equivalente ad F)
2. ogni X -> Y appartenente a F' è in forma canonica, cioè Y è un attributo (ES: MATR,Co -> Vo; MATR,Co -> CP)
3. ogni X -> Y appartenente a F' è priva di attributi estranei
4. ogni X -> Y appartenente a F' non è ridondante
