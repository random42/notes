## Interrogazione
{ T | L | F }

- Target
- Range list
- Formula

#### Esempio
Elencare i pazienti residenti a Torino.

{ p.Nome, p.Cognome | p(PAZIENTI) | p.Residenza='TO' }

### Quantificatori esistenziali e universali

Poiche' nel target non ho bisogno di attributi di RICOVERI, posso ometterlo dal
range list e usarlo nella formula.

{ p.Cognome,p.Nome | p(PAZIENTI) | E r(RICOVERI)(p.COD=r.PAZr.Reparto='A') }

A variabile(Relazione)(formula)
