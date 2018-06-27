## Definizioni
Nome|Definizione
-|-
Multiprogrammazione | Distribuzione della CPU fra piu' processi
Dual mode | Modalita' di esecuzione dei programmi: kernel o utente. Il bit di modalita' dev'essere fornito dall'hardware.
Dump/core | Immagine di un processo creata in seguito in seguito ad un abort
PCB | Process control block
Context switch | Cambio di processo running, consiste nel salvare i registri e il program counter del processo fermato, e caricare i rispettivi del nuovo processo
Swapping (processi) | Trasferimento dei PCB da e in memoria secondaria
Prelazione | Possibilita' di togliere una risorsa a un processo che la sta utilizzando e la utilizzera' (CPU, I/O, file...)
Starvation | Processo che non ottiene CPU per bassa priorita'
Aging | Aumento di priorita' dei processi nel tempo
Fork bomb / wabbit | Processo che crea troppi processi
Thread join | Attendere la terminazione di un altro thread
Spinlock | Attesa attiva
Transazione | Sequenza di *read* e *write* che si conclude con *commit* o *abort*
Commit | Transazione conclusa con successo
Abort | Transazione fallita
Rollback | Tornare a uno stato precedente
Deadlock | Stallo dovuto a un'attesa circolare di risorse
TLB | Cache per la tabella delle pagine
PTBR | Indirizzo della tabella delle pagine in RAM
Lazy swapping | Pagina di un processo da caricare in RAM
On demand paging | Una pagina viene caricata solo se richiesta
Copiatura su scrittura | Dopo una fork i processi usano le stesse pagine, quando uno cerca di modificare dei dati avviene la copiatura
Dirty bit | Assegnato a una pagina in RAM per indicare se e' stata modificata
Anomalia di Belady | Picco di aumento di page fault aumentando i frame
