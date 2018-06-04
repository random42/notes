## Bus

- **Linee di dati**: Il numero di linee (*larghezza* del bus) determina il numero di bit trasmessi alla volta. Impatta le prestazioni.
- **Linee di indirizzo**: Segnalano la sorgente o destinazione dei dati.
- **Linee di controllo**: Controllano l'accesso degli altri due tipi di linee.

**Multiplexed bus**: utilizza le stesse linee per gli inidirizzi e i dati, sono piu' lenti.

### Tipi di dispositivi

- Master: decidono di iniziare il trasferimento
- Slave: rimangono in attesa (Memory)
- Entrambi i tipi (CPU)

### Bus sincroni

Hanno un frequenza di clock predefinita.

Esempio di richiesta di lettura in memoria dalla CPU:

1. La CPU mette l'indirizzo nelle linee.
2. Richiede la lettura (MREQ e RD).
3. La memoria attiva il segnale di attesa dati.
4. La memoria mette i dati sulle linee.
5. La CPU disattiva i segnali di richiesta.
6. La memoria rimuove i dati.

![Bus sincrono](https://i.imgur.com/kK1rNTo.png?1)
