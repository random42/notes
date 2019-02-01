# Transport layer

## Services and protocols

Comunicazione tra processi. Il network layer invece provvede alla comunicazione tra host.

Sender divide messaggio in segmenti e li passa al network layer, il receiver prende i segmenti e li passa all'app layer.

Network

## Multiplexing/demultiplexing

### Multiplexing

Il messaggio (datagramma) contiene source IP e dest IP. Ogni datagramma contiene un segmento. Il segmento contiene source port e dest port.

### Demultiplexing

L'host receiver legge IP e porta di destinazione e indirizza il messaggio al socket giusto. Un messaggio UDP (quindi senza connessione) indirizza in base all'IP e porta destinataria e basta. Una connessione TCP e' invece specifica tra due socket quindi legge sia source che dest per indirizzare al giusto socket.


## UDP

- i messaggi possono essere persi
- No handshaking, quindi non c'e' una connessione stabile
- ogni messaggio e' indipendente

Viene usato per:
- Streaming multimedia (loss tolerant, rate sensitive)
- DNS
- SNMP ?

Ovviamente si puo' ottenere la sicurezza della correttezza del messaggio tramite protocolli a livello applicativo.

Nei messaggi UDP c'e' un checksum (tipo somma di tutto il messaggio) per controllare la correttezza ma a quanto pare non basta e.e

*Pro*:
- Non bisogna stabilire la connessione
- Semplicita'
- Non c'e' congestione (?)

![udp](https://i.imgur.com/X7zng0w.png)

## RDT (Reliable data transfer)

Super importante!!1!!

pacchetto ack = acknowledged, ovvero pacchetto che e' stato confermato dal receiver

Leggi le slide per capire meglio.

Brevemente il sender mette un checksum sul pacchetto, il receiver lo controlla e se e' sbagliato manda un segnale di errore per cui il sender reinvia il pacchetto.

Nel caso ci sia perdita totale del pacchetto il sender aspetta un tot per l'ack e reinvia il pacchetto se non ha avuto risposta. Mal che vada se il pacchetto era solo in ritardo l'altro lo riceve due volte ma vede che il numero di pacchetto e' lo stesso e fottesega.

Ovviamente non invii un pacchetto alla volta aspettando risposta perche' butteresti la velocita' della linea visto che RTT (il tempo di andata e ritorno) e' molto piu' grande del tempo di trasmissione di un pacchetto. Quindi mandi i pacchetti in **pipeline**.

### Protocolli di pipeline

#### Go-back-N

Puoi avere N pacchetti inviati non ack. C'e' un timer che parte dal primo pacchetto non ack e se si azzera rimanda tutti i pacchetti non ack. Le risposte di ack sono cumulative ovvero si riferiscono a un gruppo di pacchetti ricevuti.

#### Selective repeat

Stessa roba ma il timer e la risposta di ack e' per ogni pacchetto.

## TCP

Il flusso di messaggi e' controllato per non congestionare il receiver.

![tcp](https://i.imgur.com/1vGuWaB.png)

*Sequence number*:

Per ogni segmento il sequence number e' la sommatoria delle lunghezze dei dati (quindi esclusi i campi del protocollo) trasmessi in tutti i messaggi precedenti. Per cui il receiver sa il Seq # del prossimo messaggio e se e' troppo grande capisce che sono stati persi dei messaggi nel mezzo.

*Acknowledgement number*:

E' il sequence number del messaggio di cui si vuole confermare la ricezione.

![tcp_messages](https://i.imgur.com/t2cBmFP.png)

### Retransmission timeout

Per stabilire un tempo di timeout di ack si prendono vari sample di RTT, si fa la media e si usa la formula:

`EstimatedRTT = (1 - α) * EstimatedRTT + α * SampleRTT`

Dove α e' solitamente 0.125.
Il timeout dovra' avere un margine di sicurezza per cui a EstimatedRTT si aggiunge la deviazione del sample.

`DevRTT = (1 - β) * DevRTT + β * |SampleRTT - EstimatedRTT| (typically, β = 0.25)`

`TimeoutInterval = EstimatedRTT + 4 * DevRTT`

![tcp_sender](https://i.imgur.com/Ct82QtB.png)

![tcp_receiver](https://i.imgur.com/9CsBYcm.png)
