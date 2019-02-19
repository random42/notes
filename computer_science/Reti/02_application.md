## Application layer

- client/server (server always online, data centers to scale)
- Peer to peer (auto-scales, more users more service)

## Sockets

Sono identificati da IP:port. L'applicazione definisce il tipo di messaggio, la sintassi, le regole e il protocollo.


## Transport service requirements

- data integrity
- throughput
- timing (multiplayer games)
- security

![transport](https://i.imgur.com/4UcxWIu.png)

# Transport protocols

## TCP e UDP

TCP e UDP sono protocolli a livello di trasporto. Gli altri sono a livello di applicazione implementati su TCP o UDP.

![protocols](https://i.imgur.com/UCdNA0A.png)

## SSL

E' una libreria di applicazione per le connessioni TCP che provvede per:

- security
- data integrity
- end-point authentication

## HTTP

Significa *hypertext transfer protocol*. E' usato per connessioni client/server.
E' stateless, quindi non mantiene informazioni delle richieste precedenti.
Puo' essere persistente (quindi il server manda piu' oggetti al client) o no.

**RTT**: Response time, tempo di andata e ritorno di un pacchetto leggero.

*non-persistent* HTTP response time:
- 1 RTT per iniziare la connessione TCP
- 1 RTT per richieste e inizio risposta
- tempo di invio del file

Le connessioni HTTP persistenti rimangono aperte dopo la prima richiesta. Cosi' le richieste successive possono essere risolte in 1 RTT.

### HTTP request

![http-request](https://i.imgur.com/2yttSji.png)

### HTTP response

![http-response](https://i.imgur.com/a8QQFZI.png)

### Cookies for user-server state

Sono usati per mantenere uno stato in piu' richieste HTTP. Alla prima richiesta il server da' un cookie ID e tramite quello identifica il client nelle richieste successive.

### Web caches (proxy server)

Sono server interni alla LAN che servono a tenere in memoria le risposte HTTP per evitare di usare la linea internet ogni volta. Cosi' le richieste vengono servite piu' velocemente, il server originale ha meno traffico e cosi la linea internet.

Un altro modo per diminuire il traffico e' il **conditional GET**. Ovvero nella richiesta si mette un campo *If-modified-since:* che dice la data dell'oggetto in cache. Il server risponde con status 304 se l'oggetto e' ancora valido, altrimenti col nuovo oggetto se e' stato modificato successivamente a quel timestamp.

## FTP file transfer protocol

Utilizza la porta 21 per mandare i comandi di controllo al server. Per il trasferimento si usa la porta 20.

### Comandi

![ftp-commands](https://i.imgur.com/f2W1RmD.png)

## Mail (SMTP, POP3, IMAP)

I server contengono la mailbox (messaggi in arrivo) e la coda di messaggi da inviare. I server comunicano tramite protocollo SMTP.

POP e IMAP servono per accedere alla propria mailbox dal client.

### SMTP

Serve per inviare i messaggi.

Usa la porta 25.

Flow:
- A manda messaggio a B
- server di A riceve il messaggio e lo mette in coda
- server di A manda il messaggio al server di B
- quando B apre il client riceve il messaggio di A

### POP

![POP](https://i.imgur.com/diPcuX6.png)

Se cancelli i messaggi non puoi piu' rileggerli da altri client. E' stateless.

### IMAP

Mantiene tutto sul server. Puoi organizzare i messaggi in cartelle. Mantiene lo stato delle cartelle.

## Domain Name System

Database distribuito per mappare i nomi agli IP implementato tramite tanti *name servers*.

C'e' una gerarchia in base al dominio. I root servers tengono gli IP dei Top Level Domain servers e cosi' via.

Il mapping name-IP viene salvato nelle cache dei local DNS cosi da non over caricare i root servers.

Records format:

![dns-records](https://i.imgur.com/mC0GqIR.png)

## P2P

I trackers mantengono la lista di peers che tengono un certo file (torrent). I peers downloadano e uploadano pezzi del file.

Tit-for-tat: Mandi i chunks a chi te ne manda di piu'. Ogni tanto mandi a qualcuno a caso per non avere un gruppo di monopolio e far girare i chunks.
