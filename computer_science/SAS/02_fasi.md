## Requisiti evolutivi

Un requisito e' una capacita' o una condizione a cui il sistema, e pi`u in generale il progetto, deve essere conforme.

- **funzionali**: utili per l'utente
- **non funzionali**: utili per il sistema (performance, sicurezza...)

![Imgur](https://i.imgur.com/usATXRA.png)

![Imgur](https://i.imgur.com/N6b1AVD.png)

# Ideazione

- analizzi 10% dei casi d'uso
- requisiti non funzionali piu' critici
- studio dei costi
- prepari ambiente di sviluppo

![Imgur](https://i.imgur.com/dvsvwyh.png)

Vengono abbozzati i documenti ma il completamento avviene nell'elaborazione.

![Imgur](https://i.imgur.com/p6ZZzcP.png)

# Requisiti

Caratterizzati da:
- descrizione
- stato (es. proposto, approvato, incorporato, validato)
- costi di implementazione stimato
- priorita'
- rischio associato per la sua implementazione

# Casi d'uso

Un caso d'uso e' una maniera di utilizzare il sistema da parte di un utente.

Dai casi d'uso si ricavano i requisiti funzionali e si pianificano le iterazioni per implementare i vari casi. Mettono in evidenza il punto di vista dell'utente.

Caratteristica | Descrizione
-|-
Portata | descrive i confini del sistema in progettazione
Livello | tipicamente livello di obiettivo utente o livello di sottofunzione
Attore finale, attore primario |  l’attore finale e' l’attore che vuole raggiungere un obiettivo e questo richiede l’esecuzione dei servizi del sistema; l’attore primario e' l’attore che usa direttamente il sistema. Spesso coincidono.
Parti interessate | elenco delle parti interessate, ossia chi ha interessi nel raggiungimento dell’obiettivo espresso dal caso d’uso in oggetto
Pre-condizioni |  che deve essere sempre vero prima di iniziare uno scenario del caso d’uso; non vengono verificate all’interno del caso d’uso
Garanzie di successo (post-condizioni) | che cosa deve essere vero quando e' stato completato con successo il caso d’uso
Scenario di successo | Caso d'uso tipico, senza diramazioni
Estensioni | Casi secondari condizionali, di errori o altro

Bisogna scrivere in modo conciso ed essenziale. Si dice cosa il sistema deve fare ma non come lo fa.

Per trovare i casi d'uso bisogna listare gli attori e i loro obiettivi.

## Utilita'

### Test del capo

> “ Cosa avete fatto tutto i giorno?” “Il login!” – Chiedersi: “Il capo sara' felice?”

Se quel caso d'uso da solo non serve a niente allora non e' utile.

### Test EBP (processo di business elementare)

Se l'attivita' aggiunge un valore di business (aggiunge dei dati) allora e' utile.

### Test della dimensione

Se l'attivita' e' costituita da almeno 3 passi allora e' definibile come caso d'uso.

## Livello dei casi d'uso

**Obiettivo utente**: caso in cui l'utente arriva a un obiettivo di valore

**Sotto-funzione**: Funzionalita' ripetute in piu' casi d'uso, descritte una volta sola per risparmiare.

## Diagramma dei casi d'uso (UCD)

![Imgur](https://i.imgur.com/j3O21MN.png)

![Imgur](https://i.imgur.com/zLqFKG6.png)

# Elaborazione

- Viene scritto il nucleo del software
- Vengono scoperti e definiti la maggior parte dei requisiti
- Si attenuano i rischi maggiori

Solitamente un caso d'uso e' troppo grande per essere implementato in una sola iterazione, quindi le varie funzionalita' vengono distribuite su varie iterazioni.

## Documenti

![Imgur](https://i.imgur.com/58ICVG9.png)

## Modello di dominio

Si usa UML.
Non e' un modello software. Ma e' simile.

![Imgur](https://i.imgur.com/mS1woFN.png)

Praticamente e' uguale al modello ER lol.

Bisogna:
- trovare le classi concettuali
- disegnarle come diagramma UML
- aggiungere le associazioni
- aggiungere gli attributi

Pattern item-descriptor: differenziare con due classi un tipo di oggetto con la sua istanza (tipo item, prodotto in vendita)

Gli attributi derivati li scrivi con '/' prima.

Date le classi si possono derivare delle superclassi usando dei concetti in comune. Utile per la programmazione a oggetti.

![Imgur](https://i.imgur.com/tmA6hdJ.png)

Si possono creare delle classi di associazioni (relazioni) per aggiungere attributi all'associazione.

![Imgur](https://i.imgur.com/uBck1cS.png)

## Diagramma di sequenza di sistema (SSD)

Non e' menzionato esplicitamente in UP.

Sono diagrammi UML dei casi d'uso, quindi rappresentano gli input e gli output del sistema.

Bisogna gestire:
- eventi esterni (attori umani o sistemi informatici)
- eventi temporali
- guasti o eccezioni

![Imgur](https://i.imgur.com/YHdRKxH.png)
![Imgur](https://i.imgur.com/X1o6w2X.png)
![Imgur](https://i.imgur.com/uctAkVB.png)
![Imgur](https://i.imgur.com/sG0Y8F7.png)
![Imgur](https://i.imgur.com/6rBbaZV.png)
