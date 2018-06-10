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

Variabili intere gestite dal SO. Quando un processo attende il semaforo esegue una **wait**, quando lo rilascia esegue **signal**.

```
wait(S) {
  while (S <= 0) no_op;
  S--;
}

signal(S) {
  S++;
}
```

Al semaforo viene associata la lista dei processi che attendono su di esso. Quando viene incrementato viene scelto un processo e 
Dopo la *wait* il processo viene messo in stato *waiting*.
