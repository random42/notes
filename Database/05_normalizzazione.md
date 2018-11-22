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

### Terza forma normale

### Boycr-Codd Normal Form (BCNF)

Data una relazione R(A) in 1NF abbinata a delle dipendenze funzionali F, la relazione è in BCNF se, per ogni X -> Y appartenente a F si verifica una delle seguenti condizioni:
1. Y sottoinsieme di X (X ->Y è una dipendenza riflessiva)
2. X è superchiave di R
