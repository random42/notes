## DML
Linguaggio di manipolazione dei dati.

INSERT, DELETE, UPDATE, SELECT

### Operatori di base

#### Selezione
σ_p(r(A))

σ_Residenza='TO'(pazienti)

p = predicato

r(A) = Argomento dell'operatore
#### Proiezione

∏_Ai, Aj, ... Ak_(r(A))

∏_COD,Cognome(pazienti)

#### Prodotto cartesiano
r1(A) x r2(B)

#### Unione
r1 U r2

#### Differenza
r1 - r2

#### Ridenominazione
ρ_Bi,Bj,...,B <- Ai,Aj,...Ak_(r)

ρ_MATR <- Primario_(reparti)

**Dot-notation**

∏COD,AnnoNascita,medici.Cognome,medici.Nome

### Operatori derivati

#### Intersezione
r1(A) ⋂ r2(A)

#### Join
**Theta-join** = ⋈Θ

Θ = condizione di join

r1(A) ⋈Θ r2(B) = σΘ (r1(A) x r2(B))

reparti ⋈_Primario=MATR_ medici

**Equi-join** = Join con solo condizioni di uguaglianza

**Natural-join** = Join di uguaglianza su insiemi comuni (chiavi esterne) oppure prodotto cartesiano se gli insiemi sono diversi

⋉ **Semi-join** = Seleziona solo gli attributi della prima relazione

r1(A) ⋉Θ r2(B) = ∏A( r1(A) ⋈Θ r2(B) )

⟕ **Left join** = Si mantengono tutte le tuple della prima relazione. Se una tupla non fa join con la seconda relazione vengono inseriti valori null negli attributi della seconda tabella.

⟖ **Right join** = Stessa cosa di left ma al contrario

⟗ **Full-join** = Unione di left-join con right-join

### Quantificazione

#### Esistenziale
*Esiste* un paziente ricoverato nel reparto x

#### Universale

"Tutti, ogni, sempre"

Elencare le matricole abbinate a tutti i corsi di studio.

- Individuare universo di riferimento
- Prendere tutte le combinazioni possibili matricola corsi ∏MATR(e) x p
- Trovo la differenza con lo schema originale
- Il risultato sara' il complemento di cio' che devo trovare
- Sottraggo il risultato all'universo di partenza ∏MATR(e) – ∏MATR((∏MATR(e) x p) - e)

L'operazione fatta e' il **quoziente**.

#### Quoziente
