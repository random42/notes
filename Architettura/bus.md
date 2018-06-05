## Bus

- **Linee di dati**: Il numero di linee (*larghezza* del bus) determina il numero di bit trasmessi alla volta. Impatta le prestazioni.
- **Linee di indirizzo**: Segnalano la sorgente o destinazione dei dati.
- **Linee di controllo**: Controllano l'accesso degli altri due tipi di linee.

**Multiplexed bus**: utilizza le stesse linee per gli inidirizzi e i dati, sono piu' lenti.

### Tipi di dispositivi

- Master: decidono di iniziare il trasferimento
- Slave: rimangono in attesa (Memory)
- Entrambi i tipi (CPU)

### Bus sincrono

Hanno un frequenza di clock predefinita.

Esempio di richiesta di lettura in memoria dalla CPU:

1. La CPU mette l'indirizzo nelle linee.
2. Richiede la lettura (MREQ e RD).
3. La memoria attiva il segnale di attesa dati.
4. La memoria mette i dati sulle linee.
5. La CPU disattiva i segnali di richiesta.
6. La memoria rimuove i dati.

![Bus sincrono](https://i.imgur.com/kK1rNTo.png?1)


### Bus asincrono

Non c'e' un clock. Il master attiva MSYN, lo slave esegue il lavoro e al termine attiva SSYN. Quando il master disattiva MSYN lo slave disattiva SSYN (*full handshake*) e la comunicazione termina.


### Arbitraggio del bus

#### Centralizzato

![Arbitro centralizzato](https://i.imgur.com/QESNYNi.png)

Quando l'arbitro vede una request trasmette il *grant* sulla linea e il primo dispositivo che lo accetta prende controllo del bus.

Ci possono essere piu' livelli di priorita' e quindi (2 * livelli) bus.

### Decentralizzato

- Tante linee quanti dispositivi, ognuno dei quali osserva le linee prima di effettuare la richiesta
- **Tre** linee: bus request, busy, linea di arbitraggio.

![Arbitraggio a tre linee](https://i.imgur.com/XlIYxzC.png)

### Interrupt

![Interrupt](https://i.imgur.com/2tIjNbi.png)

Quando un device vuole chiedere un interrupt attiva la sua linea di input
- Il controller attiva la linea INT quando riceve uno o più segnali dai device
- Quando la CPU è in grado di servire l’interrupt attiva la linea INTA
- Il controller specifica quale device ha mandato il segnale sulla linea D0-D7
- La CPU usa questo numero come indirizzo in una tabella (interrupt vector) per trovare l’indirizzo della procedura per gestire quel tipo di interrupt
