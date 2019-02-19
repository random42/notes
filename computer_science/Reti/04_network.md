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


## IP Internet Protocol

![ip_datagram](https://i.imgur.com/PE81bY0.png)

## DHCP Dynamic Host Configuration Protocol

![DHCP](https://i.imgur.com/oqIQjLQ.png)

## ICMP Internet Control Message Protocol

Usato dai router per mandarsi messaggi sullo stato del network. Usato sopra IP.

![ICMP](https://i.imgur.com/s8Mx5Uv.png)

## IPv6

![ipv6](https://i.imgur.com/ehlFk74.png)

Differenze con IPv4:
- No checksum
- Options outside of header (next header field)
- ICMPv6 nuovi tipi di messaggi (pacchetto troppo grande ad esempio)

Per usare IPv4 con IPv6 si usa IPv4 con data IPv6.

## Routing algorithms

Grafo G(N, E) dove N sono i router e E sono i collegamenti.

Algoritmi **globali** se ogni router conosce il grafo, **decentralizzati** se ogni router sa solo le informazioni dei router adiacenti.

Algoritmi **statici** se il grafo cambia poco, **dinamici** se cambia spesso.

### Dijkstra

### Bellman-Ford
