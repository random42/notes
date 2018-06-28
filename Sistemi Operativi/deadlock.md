# Deadlock

Condizioni necessarie:
- Mutua esclusione
- Possesso e attesa
- No prelazione (di risorse)
- Attesa circolare


### Grafo di assegnazione delle risorse

![grafo di assegnazione](https://i.imgur.com/yKlv0Lu.png)

Se c'e' un ciclo e le risorse sono uniche c'e' deadlock.


## Strategie di Havender

### 1 - Possesso e attesa
Un processo richiede tutte le risorse insieme e attende se non sono tutte disponibili.

**Contro**:
- Spreco di risorse


### 2 - Prelazione

Quando un processo richiede una risorsa che gli viene negata rilascia tutte le risorse in suo possesso.

**Contro**:
- Costo della perdita di risorse
- Non tutte le risorse sono preemptive (es. stampante)
- Puo' creare starvation

### 3 - Attesa circolare

A ogni risorsa e' associato un numero. I processi devono richiedere le risorse in ordine crescente cosi' da evitare attese circolari.

**Contro**:
- Poco flessibile (i programmatori devono sapere l'ordine)

## Stato sicuro

Stato per cui ogni processo termina in tempo finito

Una **sequenza sicura** di processi Pᵢ esiste se le richieste di risorse di ogni processo *i* sono soddisfacibili dalle risorse disponibili piu' quelle liberate dai processi *j<i*.

### Grafo di attesa

Grafo con i processi come vertici e ogni arco significa che un processo attende una risorsa posseduta da un altro processo. Utile per risorse con una istanza.

### Algoritmo con istanze multiple

```c
N = numero processi;
M = numero risorse;
int Diponibili[M]; // risorse disponibili
int Assegnate[N][M]; // ogni processo corrisponde a una riga
int Richieste[N][M];
boolean fine[N];
while esiste un indice i | Fine[i] == false ∧ Richieste[i] <= Disponibili {
  Disponibili = Disponibili + Assegnate[i];
  Fine[i] = true;
}

if (esiste i | Fine[i] == false) {
  // c'e' deadlock
}
```
