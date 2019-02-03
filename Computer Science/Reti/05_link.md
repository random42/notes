# Link layer

- error detection
- multiple access

hosts and routers = nodes

Il **frame** e' il pacchetto, incapsula il datagram.

Si usa il MAC address per determinare source e dest.

Link **half-duplex** se solo uno dei due nodi puo' trasmettere alla volta, altrimenti **full-duplex**.


# Correzione errori

![Imgur](https://i.imgur.com/ZHHBkDi.png)

## Cyclic redundancy check

Considero i dati come un numero *D*. Scelgo un numero *r* di bit e un numero *G* di r+1 bit. Ricavo un numero R di r bit tale che `DR % G = 0`. Per DR si intende l'unione delle cifre di D con quelle di R `(D * 2^r) XOR R`.

Il receiver conosce G, fa il modulo e vede se e' 0.

Questo metodo puo' trovare fino a *r* errori.

# Multiple access links, protocols

Vogliamo che quando per X users di un link e R di banda ogni utente abbia R/X di banda media. Inoltre non ci devono essere nodi esterni a gestire la cosa o clock.

![mac_protocols](https://i.imgur.com/HmsXRGQ.png)

## Channel partitioning protocols

![tdma](https://i.imgur.com/I1e16Of.png)

![fdma](https://i.imgur.com/LdDR5iz.png)

## Random access protocols

- Ogni nodo trasmette a full rate
- Bisogna trovare le collisioni e recuperare i dati persi

### Slotted ALOHA

![slotted_aloha_1](https://i.imgur.com/IFszuuw.png)
![slotted_aloha_2](https://i.imgur.com/KQwkYck.png)

Efficienza:
```
p = probabilita' che un nodo trasmetta in uno slot

prob che un nodo abbia successo: p(1-p)^(N-1)

prob che qualunque nodo abbia successo: Np(1-p)^(N-1)

con N che tende a infinito viene 1/e = 0.37 = una merda
```

### Pure (unslotted) ALOHA

Piu' semplice perche' non ci sono slot e quindi nessuna sincronizzazione.

Efficienza:
```
prob che un nodo abbia successo: p(1-p)^(2(N-1))
stessa roba di prima viene 1/2e = 0.18 = peggio ancora
```

### CSMA (carrier sense multiple access)

Se il canale non e' occupato trasmette l'intero frame altrimenti aspetta.

La collisione puo' esserci perche' dipende dal ritardo di propagazione. In quel caso si spreca tutto il tempo di trasmissione.

### CSMA/CD (collision detection)

Se il nodo trova la collisione annulla la trasmissione.

Nelle LAN a cavo e' facile trovare la collisione, compari la trasmissione con la ricezione. In quelle wireless e' difficile perche' la trasmissione sopraffa la ricezione.

A ogni collisione si aspetta esponenzialmente. Dopo *m* annulli di fila si sceglie un numero *K* tra 0 e 2^(m-1) e si aspetta K*512 bit.

Efficienza:
```
P = max prop delay between 2 nodes in LAN
T = time to transmit max-size frame

E (efficienza): 1 / (1 + 5(P/T))

Per P che tende a 0 e T che tende a infinito E tende a 1.
```

## "Taking turns" protocols

### Polling

Un master node invita gli altri a trasmettere a turno.

- polling overhead
- ritardo
- no master no party

### Token passing

Token per trasmettere che i nodi si passano in sequenza

## MAC addresse

A livello di LAN si usa il MAC address che e' unico per scheda di rete come indirizzo.

MAC address: 48 bit

I MAC address sono amministrati da IEEE, le aziende che fanno schede di rete comprano uno spazio di indirizzi per avere unicita'.

## ARP: address resolution protocol

Come faccio a sapere il MAC address se so l'indirizzo IP locale?

Ogni nodo ha una tabella `<IP, MAC, TTL>` TTL di solito e' 20 min.

Se non si ha l'indirizzo in tabella si manda un pacchetto query con broadcast dest address (tutto 1) a tutti i nodi. Quello giusto manda l'indirizzo MAC e l'altro se lo salva in tabella.

Per mandare frame in altre reti bisogna sapere l'indirizzo MAC del router di passaggio, quello sapra' quello successivo e cosi via. IP source e dest rimangono invariati mentre i MAC address source e dest cambiano ogni volta.

## Ethernet

- Tecnologia LAN piu' usata
- la prima usata
- e' semplice e costa poco
- e' veloce (fino a 10 Gbps)

### Frame structure

![ethernet_frame](https://i.imgur.com/Z9HQmtk.png)

type: network layer protocol (di solito IP)

Ethernet’s MAC protocol: unslotted CSMA/CD wth binary backoff

### Switches

Sono router con solo link layer che inoltrano i frame in modo trasparente (i nodi non sanno della sua esistenza). Sono utili perche' gli host si connettono ognuno allo switch e non c'e' collisione.

Pure loro c'hanno la loro tabella eh... Per conoscere la porta che va a un certo host aspettano che lui lo contatti e cosi lo scopre..

Se arriva un frame per cui non si conosce il MAC destinatario lo manda a tutti (flood).

Cosi facendo la rete funziona anche con switch su switch.

## VLAN

Virtual LAN. Si usa una sola LAN fisica per averne molte. Gli switch isolano set di porte che appartengono alla stessa VLAN.
