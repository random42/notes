# Database

Schema

S = {R1, R2, ..., Rn}

## Relazione

Contiene: Schema e istanze

`<R, r>`

### Schema

R = Schema

R(A1, A2, ..., An) -> R(A)

|A| = Numero attributi, sempre >= 1

### Istanza

r = Istanza

|r| = Numero di tuple nell'istanza, >= 0

#### Tupla (record, row)

```
t = <v1, v2, ..., vn>
t[A[i]] = v[i]
```


### Superchiave

Insieme di attributi per cui ogni tupla si distingue dalle altre.

#### Chiave candidata

E' una superchiave minimale (con meno attributi possibili)

#### Chiave primaria

Una chiave candidata scelta dal progettista. Ogni attributo della chiave non deve essere *NULL*
