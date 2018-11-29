## Gestore del ripristino

Garantisce atomicita' e consistenza.

Memoria standard = contiene DB e indici

Memoria stabile = contiene log files, journal files

Il gestore del ripristino è basato su quattro approcci/algoritmi diversi.

### Politiche di gestione del buffer

![Imgur](https://i.imgur.com/iOOrkOa.png)

- **no-steal**: Si registrano i dati solo dopo il commit della transazione
- **steal**: si permette al buffer di sostituire pagine in memoria rendendo persistenti le modifiche della pagina rimpiazzata anche prima del commit/rollback
- **no-flush**: Le pagine non vengono trasferite immediatamente su disco per far si che se i dati vengono richiesti da transazioni successive essi siano gia' nel buffer.
- **flush**: Le pagine vengono trasferite immediatamente

Ci sono quindi 4 modalita' di gestione di ripristino in base alle politiche di gestione del buffer.

### Caso 1: steal/no-flush

Situazioni problematiche:

- transazione in rollback con alcune modifiche rese persistenti dalla politica steal
- crash del sistema con transazione in commit ma modifiche non ancora persistenti

Si usa un file di log.

- **\<Ti, start>**: inizio della transazione Ti
- **\<Ti, X, BS(X), AS(X)>**: Transazione, oggetto, Before-State, After-State

Il log è quindi una storia serializzabile corretta di modifiche della base di dati.

Se la transazione fallisce si avra' nella storia l'azione UNDO(Ti) che disfa le azioni precedenti. Nel log verra' memorizzato \<Ti, abort> seguito da FORCE LOG.

FORCE LOG fa si che il log venga scritto sulla memoria stabile per garantire la coerenza della storia.

#### Situazioni

##### Transazione parzialmente terminata (commit)

Se i vincoli di integrita' non vengono soddisfatti la transazione viene abortita. Altrimenti poiche' le modifiche non sono salvate (no-flush) si scrive nel log **\<Ti, commit>**

##### Algoritmo di ripristino

LA = Transazioni non terminate

LC = Transazioni terminate

Si fa

UNDO(LA): disfacimento delle transazioni non terminate per garantire la proprietà di atomicità. Scrive nel DB il before-state

REDO(LC): rifacimento delle transazioni in commit, a causa delle modifiche potenzialmente perse per via della politica no flush. Scrive nel DB l'after-state

Poiche' conta solo l'ultima modifica di ogni oggetto si fa il REDO solo dell'ultima transazione committata che modifica l'oggetto.

Stessa cosa per l'UNDO, si scrive il before-state solo della prima transazione abortita che modifica l'oggetto.

Nel ripristino le transazioni in abort vengono ignorate perche' il log di abort significa che l'UNDO e' gia' stato fatto.


#### Politica steal

Quando si scambiano due pagine bisogna eseguire:
- FORCE LOG : per gestire i crash
- FORCE pagina : trasferimento su disco della pagina rubata

#### Checkpoint

- Si sospendono tutte le transazioni
- Si scrive un record di CHECKPOINT contenente l'elenco delle transazioni attive con il puntatore allo start
- Si esegue FORCE LOG
- Si esegue FORCE pagine delle transazioni in commit
- Viene aggiunto un flag di OK nel record di checkpoint e si esegue un nuovo FORCE LOG

![checkpoint](https://i.imgur.com/j2kru3m.png)

### Caso 2 no-steal/no-flush

Siamo in politica no flush: serve l'**AS** per il REDO delle transazioni che hanno raggiunto il commit.

Siamo in politica no steal: **non** serve il **BS** perché tutte le azioni fatte dalle transazioni non committate hanno modificato solo le pagine nel buffer (in memoria centrale).

Non si esegue UNDO.


### Caso 3 steal/flush

Non abbiamo bisogno dell'after-state perche' c'e' la politica flush.

Non si esegue REDO.

### Caso 4: no-steal/flush

Teoricamente non serve il file di log.

C'e' il problema del crash durante il trasferimento di una pagina.

#### Tecnica con pagine ombra

![pagine_ombra](https://i.imgur.com/1WUbAEY.png)

La transazione prende una copia della tabella delle pagine, e cambia il puntatore al record X alla pagina di X'.

Se va in commit la sua tabella viene sostituita a quella in memoria stabile (fase 1) e poi da li' viene sostituita alla tabella originale (master) (fase 2).

Se va in rollback si rilascia il lock e non serve modificare nulla.

In caso di crash se la caduta avviene prima della fase 1 la transazione fallisce, altrimenti al ripristino si completa la fase 2.


### Tecnica dump/restore

La base dati viene copiata (dump) periodicamente su memoria stabile (ad esempio nastri) e il log è vuoto.

Le transazioni modificano lo stato della base dati e scrivono il file di log con relativi after state.

In caso di guasto:

- Copia del dump sulla nuova periferica (restore)
- Si legge tutto il log e si effettua il REDO(LC)


## Riassunto

![Imgur](https://i.imgur.com/A95rHRI.png)
