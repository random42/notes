## Inter-process-communication


#### Memoria condivisa

- serve un lock per accedere a dati consistenti


#### Messaggi

- **diretto**: si deve fornire il pid
- **indiretto**: immagino di no

- **sincrono**: bloccante
- **asincrono**: non bloccante

#### Socket

Comunicazione tra macchine diverse
Si identifica con IP:port.

#### Pipe

- **anonima**: unidirezionale, usata da una sola coppia di processi, non sopravvive alla morte del creatore.
- **named**: puo' essere bidirezionale, FIFO, spesso e' un file, va disallocata.
