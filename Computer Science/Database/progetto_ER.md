# Basi di Dati 17/18: Esercizio di progettazione

**Studenti**:
- Roberto Sero - Matricola 832887
- Paolo Peretti - Matricola 838975

## Indice
* [Progettazione concettuale](#progettazione-concettuale)
   * [Requisiti iniziali](#requisiti-iniziali)
   * [Glossario dei termini](#glossario-dei-termini)
   * [Requisiti strutturati in gruppi di frasi omogenee](#requisiti-strutturati-in-gruppi-di-frasi-omogenee)
   * [Schema ER e regole aziendali](#schema-er-e-regole-aziendali)
      * [Regole aziendali](#regole-aziendali)
         * [Vincoli d'integrita'](#vincoli-dintegrita)
         * [Concetti](#concetti)
* [Progettazione logica](#progettazione-logica)
   * [Tavola dei volumi](#tavola-dei-volumi)
   * [Tavola delle operazioni](#tavola-delle-operazioni)
   * [Analisi delle ridondanze](#analisi-delle-ridondanze)
      * [Ridondanze presenti](#ridondanze-presenti)
      * [Numero di seguiti e seguaci](#numero-di-seguiti-e-seguaci)
         * [Seguire un utente](#seguire-un-utente)
         * [Smettere di seguire un utente](#smettere-di-seguire-un-utente)
         * [Visualizzare il profilo di un utente](#visualizzare-il-profilo-di-un-utente)
         * [Costo totale](#costo-totale)
      * [Numero voti e numero letture](#numero-voti-e-numero-letture)
         * [Leggere un libro](#leggere-un-libro)
         * [Visualizzare un libro](#visualizzare-un-libro)
         * [Costo totale](#costo-totale-1)
      * [Conclusione](#conclusione)
   * [Schema relazionale](#schema-relazionale)
* [Implementazione](#implementazione)
   * [DDL](#ddl)
   * [DML](#dml)


# Progettazione concettuale

## Requisiti iniziali

Per gli utenti della piattaforma si memorizzano le informazioni richieste durante la registrazione. Come si ricava dal file screenshot.pdf nella sezione utente , per ogni utente si tiene traccia delle seguenti informazioni:
- libri scritti
- utenti seguiti
- utenti che seguono l'utente attuale
- lista dei libri attualmente in lettura
- si possono ignorare le conversazioni (requisito non richiesto)

I libri possono essere inseriti in diverse categorie:
- la lista delle categorie narrative e’ visibile cliccando sul pulsante scopri in alto a sinistra, ogni libro viene inserito in almeno una categoria narrativa
- ogni libro puo’ essere inserito anche in una delle categorie primo piano, in salita e nuovo

Ad ogni categoria narrativa vengono associati un insieme di scrittori correlati composto da tutti gli scrittori che hanno scritto almeno 2 libri nella categoria.

Nel file screenshot.pdf nella sezione libro sono visibili le informazioni associate a ciascun libro.

I libri sono suddivisi in capitoli i cui titoli sono visibili nella sezione sommario. Ogni capitol è composto da paragrafi. Gli utenti wattpad possono rilasciare commenti sui singoli paragrafi dei libri.

Nella sezione *ti piacera' anche􏰁* viene associata al libro corrente una lista di libri correlati.

Due libri sono considerati correlati se hanno almeno 3 tag in comune e sono stati entrambi votati da almeno 10 utenti.

## Glossario dei termini

| Termine | Descrizione | Sinonimi | Collegamenti
| - | - | - | -
| Utente | Persona registrata | Iscritto, scrittore, lettore | Libro, Utente
| Libro | Testo scritto da utenti | Testo | Utente, Categoria, Capitolo
| Categoria | Insieme di generi | Genere narrativo | Libro, Utente
| Capitolo | Sezione di un libro | | Libro, Paragrafo, Sommario
| Paragrafo | Sezione di un capitolo | | Capitolo, Utente
| Tag | Etichetta associata ad un libro | | Utente, Libro
| Commento | Opinione di un utente rispetto a un paragrafo | Opinione | Utente, Paragrafo
| Voto | Apprezzamento di un libro da parte di un utente | Apprezzamento | Utente, Libro

## Requisiti strutturati in gruppi di frasi omogenee

Si vuole realizzare una base di dati per una piattaforma digitale che da la possibilità di leggere o scrivere libri.

#### Utenti
Gli utenti diventano tali dopo essersi iscritti tramite un indirizzo email e dopo aver inserito un username, nome e cognome.
Bisogna rappresentare inoltre una data di iscrizione, una descrizione personale, gli utenti seguiti, i libri scritti, i libri attualmente in lettura.

#### Libri
I libri vengono identificati da un titolo e ne rapprensentiamo un'immagine di copertina, il numero di letture, il numero di apprezzamenti (like), la data dell'ultima modifica, lo stato del libro, la descrizione, i tag, le categorie di appartenenza, l'autore, i capitoli, i paragrafi ed i commenti.

#### Categorie
Le categorie vengono identificate dal nome del genere letterario (commedia, dramma, horror, etc.) e ne rappresentiamo utenti e libri appartenenti ad essi.

#### Capitoli
I capitoli vengono identificati dal numero e dal libro di appartenenza e ne rappresentiamo il titolo, i paragrafi.

#### Paragrafi
I paragrafi sono identificati dal capitolo di appartenenza e dal numero del paragrafo e ne rappresentiamo i commenti relativi ad esso.


## Schema ER e regole aziendali

![ER](https://i.imgur.com/ayanpdg.png)

### Regole aziendali

#### Vincoli d'integrita'

1. La data d'iscrizione di un utente deve essere minore o uguale alle date dell'ultimo aggiornamento dei suoi libri.

2. Il numero di seguiti o seguaci di un utente dev'essere sempre minore del numero di utenti esistenti.

3. Il numero di letture e voti di un libro dev'essere sempre minore o uguale al numero di utenti esistenti.

#### Concetti

1. Due libri sono considerati correlati se hanno almeno 3 tag in comune e sono stati votati entrambi da almeno 10 utenti.

2. Uno scrittore e' associato a una categoria narrativa se ha scritto almeno 2 libri appartenenti a quella categoria.

# Progettazione logica

## Tavola dei volumi

| Concetto | Tipo | Volume
| - | - | -
| Utente | E | 40k
| Scrittura | R | 5k * 20
| Libro | E | 100k
| Categoria | E | 40
| Associazione | R | 100k * 5
| Tag | R | 100k * 20
| Lettura | R | 40k * 50
| Commento | R | 40k * 50
| Capitolo | E | 100k * 20
| Suddivisione | R | 100k * 20
| Paragrafo | E | 100k \* 20 \* 50
| Composizione | R | 100k \* 20 \* 50
| Voto | R | (40k * 20) / 10
| Seguace | R | 40k * 50


## Tavola delle operazioni

Media giornaliera:
- Utenti attivi: 5k
- Scrittori attivi: 1k
- Letture completate: 1k
- Scritture completate: 200

| Operazione | Tipo | Frequenza Giornaliera
| - | - | -
| Inserire un libro | I | 150
| Leggere un libro | I | 4k
| Votare un libro | I | 100
| Cercare un libro | I | 10k
| Commentare un paragrafo | I | 2k
| Rimuovere un libro | I | 0.05
| Inserire un utente | I | 50
| Rimuovere un utente | I | 1
| Seguire un utente | I | 10k
| Smettere di seguire un utente | I | 1k
| Aggiornare un libro | I | 1k
| Visualizzare un profilo utente | I | 15k
| Inserire un tag | I | 140
| Associare una categoria a un libro | I | 35
| Visualizzare i commenti di un libro | I | 10k
| Associare i libri nelle categorie speciali | B | 2
| Visualizzare i libri attualmente in lettura | I | 5k
| Visualizzare un libro | I | 20k

## Analisi delle ridondanze

### Ridondanze presenti

- Utente.num_seguiti
- Utente.num_seguaci
- Libro.num_voti
- Libro.num_letture

### Numero di seguiti e seguaci

#### Seguire un utente

Frequenza = 10k

*CON* ridondanza:

Concetto | Costrutto | Accessi | Tipo
| - | - | - | -
Seguace | R | 1 | S
Utente | E | 2 | S

Costo: `10k * (3 * 2) = 60k`

*SENZA* ridondanza:

Concetto | Costrutto | Accessi | Tipo
| - | - | - | -
Seguace | R | 1 | S

Costo: `10k * (1 * 2) = 20k`

#### Smettere di seguire un utente

Frequenza = 1k

*CON* ridondanza:

Concetto | Costrutto | Accessi | Tipo
| - | - | - | -
Seguace | R | 1 | S
Utente | E | 2 | S

Costo: `1k * (3 * 2) = 6k`

*SENZA* ridondanza:

Concetto | Costrutto | Accessi | Tipo
| - | - | - | -
Seguace | R | 1 | S

Costo: `1k * (1 * 2) = 2k`

#### Visualizzare il profilo di un utente

Frequenza = 15k

*CON* ridondanza:

Concetto | Costrutto | Accessi | Tipo
| - | - | - | -
Utente | E | 1 | L

Costo: `15k * 1 = 15k`

*SENZA* ridondanza:

Concetto | Costrutto | Accessi | Tipo
| - | - | - | -
Utente | E | 1 | L
Seguace | R | 50 * 2 | L

Costo: `15k * (101) = 1515k`

#### Costo totale

*CON* ridondanza:
`60k + 6k + 15k = 81k`

*SENZA* ridondanza:
`20k + 2k + 1515k = 1537k`

### Numero voti e numero letture

Calcoliamo solo il costo delle operazioni per il numero di letture perche' *Leggere un libro* ha frequenza maggiore di *Votare un libro* e entrambe le ridondanze richiedono il costo di *Visualizzare un libro*.

Quindi se la ridondanza *num_letture* e' conveniente sicuramente lo e' anche *num_voti*.

#### Leggere un libro

Frequenza = 4k

*CON* ridondanza:

Concetto | Costrutto | Accessi | Tipo
| - | - | - | -
Libro | E | 1 | S
Lettura | R | 1 | S

Costo: `4k * (2 * 2) = 16k`

*SENZA* ridondanza:

Concetto | Costrutto | Accessi | Tipo
| - | - | - | -
Lettura | R | 1 | S

Costo: `4k * 2 = 8k`

#### Visualizzare un libro

Frequenza = 20k

*CON* ridondanza:

Concetto | Costrutto | Accessi | Tipo
| - | - | - | -
Libro | E | 1 | L

Costo: `20k * 1 = 20k`

*SENZA* ridondanza:

Concetto | Costrutto | Accessi | Tipo
| - | - | - | -
Libro | E | 1 | L
Lettura | R | 10 | L

Costo: `20k * (11) = 220k`

#### Costo totale

*CON* ridondanza:
`16k + 20k = 36k`

*SENZA* ridondanza:
`8k + 220k = 228k`

### Conclusione

Manteniamo tutte le ridondanze visti i costi di accesso minori.


## Schema relazionale

![schema_relazionale](https://i.imgur.com/eRDmOAU.png)

# Implementazione

## DDL

```sql
CREATE TABLE utente (
  username VARCHAR(100) PRIMARY KEY,
  nome VARCHAR(100),
  cognome VARCHAR(100),
  bio VARCHAR(1000),
  data_iscrizione TIMESTAMP NOT NULL,
  foto_profilo BYTEA,
  email VARCHAR(100) NOT NULL UNIQUE,
  password VARCHAR(100) NOT NULL,
  num_seguaci INT CHECK(num_seguaci >= 0) NOT NULL DEFAULT 0,
  num_seguiti INT CHECK(num_seguiti >= 0) NOT NULL DEFAULT 0
);

CREATE TABLE libro (
  titolo VARCHAR(100) PRIMARY KEY,
  copertina BYTEA,
  descrizione VARCHAR(1000),
  autore VARCHAR(100) NOT NULL,
  data_aggiornamento TIMESTAMP,
  num_voti INT CHECK(num_voti >= 0) NOT NULL DEFAULT 0,
  num_letture INT CHECK(num_letture >= 0) NOT NULL DEFAULT 0,
  FOREIGN KEY (autore) REFERENCES utente (username)
);

CREATE TABLE categoria (
  nome VARCHAR(100) PRIMARY KEY,
  descrizione VARCHAR(1000)
);

CREATE TABLE capitolo (
  id INT GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
  libro VARCHAR(100) NOT NULL,
  num INT CHECK(num >= 0) NOT NULL DEFAULT 0,
  nome VARCHAR(100) NOT NULL,
  FOREIGN KEY (libro) REFERENCES libro (titolo)
);

CREATE TABLE paragrafo (
  id INT GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
  capitolo INT NOT NULL,
  num INT CHECK(num >= 0) NOT NULL DEFAULT 0,
  testo VARCHAR NOT NULL,
  FOREIGN KEY (capitolo) REFERENCES capitolo (id)
);

CREATE TABLE commento (
  id INT GENERATED BY DEFAULT AS IDENTITY PRIMARY KEY,
  capitolo INT NOT NULL,
  utente VARCHAR(100) NOT NULL,
  data TIMESTAMP NOT NULL,
  testo VARCHAR NOT NULL,
  FOREIGN KEY (capitolo) REFERENCES capitolo (id)
);

CREATE TABLE lettura (
  utente VARCHAR(100),
  libro VARCHAR(100),
  terminata BOOLEAN,
  FOREIGN KEY (utente) REFERENCES utente (username),
  FOREIGN KEY (libro) REFERENCES libro (titolo),
  PRIMARY KEY (utente, libro)
);

CREATE TABLE voto (
  utente VARCHAR(100),
  libro VARCHAR(100),
  FOREIGN KEY (utente) REFERENCES utente (username),
  FOREIGN KEY (libro) REFERENCES libro (titolo),
  PRIMARY KEY (utente, libro)
);

CREATE TABLE seguace (
  seguace VARCHAR(100),
  seguito VARCHAR(100),
  FOREIGN KEY (seguace) REFERENCES utente (username),
  FOREIGN KEY (seguito) REFERENCES utente (username),
  PRIMARY KEY (seguace, seguito)
);

CREATE TABLE tag (
  nome VARCHAR(100),
  utente VARCHAR(100) NOT NULL,
  libro VARCHAR(100),
  FOREIGN KEY (utente) REFERENCES utente (username),
  FOREIGN KEY (libro) REFERENCES libro (titolo),
  PRIMARY KEY (nome, libro)
);

CREATE TABLE libro_categoria (
  categoria VARCHAR(100),
  libro VARCHAR(100),
  FOREIGN KEY (libro) REFERENCES libro (titolo),
  FOREIGN KEY (categoria) REFERENCES categoria (nome),
  PRIMARY KEY (categoria, libro)
);

```

## DML

```sql

INSERT INTO utente VALUES (
  'asd','Roberto','Sero','Ciao a tutti, belli e brutti','2016-06-22 19:10:25-07','foto','roberto.sero@edu.unito.it','ciaociao1234'
)

```
