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
