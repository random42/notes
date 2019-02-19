## Pacchetti

Ogni network comunica tramite *packets*.

L: Bit del pacchetto
R: Bit/s capacita' di trasmissione della linea (bandwidth)

Delay di trasmissione del pacchetto = L/R

Un pacchetto viaggia attraverso molti router e ognuno di essi deve riceverlo per intero prima di trasmetterlo al prossimo router.

### Packet switching

Se c'e' piu' di un utente nel router e i pacchetti arrivano a velocita' maggiore di quanto escono allora vengono accodati ma c'e' possibilita' di perdita del pacchetto per limiti di memoria.

### Circuit switching

Ci si divide la rete in modo equo senza perdita di pacchetti. Si puo' dividere per frequenza o per tempo.

### Packet Delay

`nodal = proc + queue + trans + prop`

proc: processing
- controlla errori sui bit
- determina l'output link
- < msec

queue: queueing delay
- tempo in coda
- dipende da quanto e' occupato il router

trans: transimission delay = L/R

prop: propagation delay = d/s
- d: lungezza del cavo
- s: velocita' di propagazione media (~2x108 m/sec)
