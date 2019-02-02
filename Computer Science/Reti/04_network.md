# Network layer

Collega due host, mentre il *transport* layer collega due processi.

### Cosa fa

- inoltro dei pacchetti
- instradamento: decidere la strada dei pacchetti
- frammentazione e assemblaggio dei pacchetti
- connessione: ci sono protocolli per stabilire la connessione (ATM, x.25)

## Service models

![network_services](https://i.imgur.com/XcUaeCA.png)

## Virtual circuits

Usato per telefoni.

Servizio di connessione tra host.

- I pacchetti sono identificati dal VC
- Ogni router nel percorso mantiene lo stato della connessione
- Si possono allocare risorse dedicate

Un VC consiste in:
- path
- VC numbers, numero per ogni link sulla path
- record nella forwarding table di ogni router della path

## Datagram networks

Usato per internet.

Non c'e' uno stato di connessione, i pacchetti vengono mandati in base all'indirizzo del destinitario.

![datagram_forwarding_table](https://i.imgur.com/pj1olMU.png)

## IP protocol

![ip_datagram](https://i.imgur.com/PE81bY0.png)
