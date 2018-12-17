## Sezione critica

**Definizione**:

Porzione di codice in un processo che modifica variabili condivise.


**Criteri**:
- Mutua esclusione
- Progresso: se *a* non vuole entrare in sezione critica non puo' impedire a *b* di farlo
- Attesa limitata: no *deadlock*

### Soluzioni software

Usare *turno* per indicare chi puo' entrare.
Non c'e' **progresso**.

```c
<sezione non critica>
// i definisce il processo
while (turno != i) do no_op;
<sezione critica>
turno = j;
<sezione non critica>
```

Usare un array di booleani *flag* per indicare che vuole entrare.
Puo' causare deadlock!

```c
flag[i] = true;
while (flag[j]) do no_op;
<sezione critica>
flag[i] = false;
<sezione non critica>
```

Per evitare il deadlock ogni thread favorisce l'altro.

```c
flag[i] = true; turno = j;
while (flag[j] && turno == j) do no_op;
sezione di ingresso
<sezione critica>
flag[i] = false;
<sezione non critica>
```

Esteso a N processi si puo' usare l'**algoritmo del Fornaio**:

```c
choosing[i] = true;
ticket[i] = max_ticket + 1;
choosing[i] = false;
for (j = 0; j < N; j++) {
  while (choosing[j]) no_op;
  while (ticket[j] != 0 &&
  ticket[j] < ticket[i] ||
  ticket[j] == ticket[i] && j < i) no_op;
}
<sezione critica>
ticket[i] = 0;
<sezione non critica>
```

Queste soluzioni consumano tutte CPU inutilmente -> serve un sostegno hardware!

### Soluzioni hardware

1. Disabilitare gli interrupt e i context switch, questo pero' puo' interferire pesantemente con lo scheduling CPU
2. Utilizzare dei **lock** che si acquisiscono e rilasciano. Uso di istruzioni **atomiche** definite dall'architettura: **TestAndSet** e **Swap**.

```c
boolean TestAndSet(boolean *lock) {
   boolean valore = *lock;
   *lock = true;
   return valore;
}

while (TestAndSet(&lock));
<sezione critica>
lock = false;
```

Quando ritorna false, significa che il lock e' acquisibile ed e' gia' stato acquisito.

```
Swap(boolean *a, boolean *b) {
  boolean temp = *a;
  *a = *b;
  *b = temp;
}
chiave = true;
while (chiave) Swap(&lock, &chiave);
<sezione critica>
lock = false;
```

Non c'e' l'**attesa limitata**.

### Semafori

Variabili intere gestite dal SO. Quando un processo attende il semaforo esegue una **wait** (**P**), quando lo rilascia esegue **signal** (**V**).


```
P(S) {
  while (S <= 0) no_op;
  S--;
}

V(S) {
  S++;
}
```

Al semaforo viene associata la lista dei processi che attendono su di esso. Dopo la *wait* su un semaforo a 0 il processo viene messo in stato *waiting*. Quando il semaforo viene incrementato il SO sceglie un processo che attende sul semaforo e lo mette in coda *ready*.


### Problemi di sincronizzazione

#### Produttore/consumatore

3 semafori

**Produttore**:
```
<produci un nuovo elemento>
P(libere);
P(mutex);
<inserisci nuovo elemento>
V(mutex);
V(occupate);
```

**Consumatore**:
```
P(occupate);
P(mutex);
<estrai elemento>
V(mutex);
V(libere);
<consuma elemento>
```


#### Lettori/scrittori

- mutex: mutex per scrivere in numlettori
- scrittura: mutex di scrittura

Lettore:
```
P(mutex);
numlettori++;
if (numlettori == 1)
   P(scrittori);
V(mutex);
<legge>
P(mutex);
numlettori--­­;
if (numlettori == 0)
   V(scrittura);
V(mutex);
```

Scrittore:
```
P(scrittura);
<scrive>
V(scrittura);
```

#### Cinque filosofi

> 5 filosofi passano il tempo seduti intorno a un tavolo pensando e mangiando a fasi alterne. Per mangiare un filosofo ha bisogno di due posate ma ci sono solo cinque posate in tutto

Soluzioni semplici danno vita a **deadlock** e **starvation**.

Si possono usare degli *stati* associati alle posate.


### Transazioni

Per database etc. servono transazioni atomiche con un **logfile** per eventuali crash.
