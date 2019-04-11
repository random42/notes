# Constraint Satisfaction Problems

Sono i problemi in cui la soluzione e' uno stato, non c'e' uno stato iniziale e non ci sono azioni.

![Imgur](https://i.imgur.com/PdrdOQ1.png)
![Imgur](https://i.imgur.com/PdrdOQ1.png)
![Imgur](https://i.imgur.com/m4HsgfH.png)

Lo stato e' un assegnamento di valori. Il percorso e' l'ordine in cui vengono assegnati i valori (irrilevante alla soluzione).

![Imgur](https://i.imgur.com/My0SprM.png)
![Imgur](https://i.imgur.com/e5HcruM.png)

**Criterio di preferenza**: vincolo non obbligatorio ma le soluzioni che lo soddisfano sono preferite.

## Arc consistency

Un grafo di vincoli ha variabili come vertici e archi da x a y se y e' vincolata da x.

Un grafo di vincoli è **arc consistent** quando rispetta tutti i vincoli binari.

Dato un vincolo a tre o più variabili è sempre possibile trasformarlo in un insieme di vincoli binari.

Un arco da una variabile *x* a *y* e' consistente se per ogni valore di x esiste un valore consistente di y.

Si cerca di rendere consistenti gli archi cancellando valori dai domini delle variabili.

### AC-3

Algoritmo per rendere arc-consistent un grafo. Se alla fine dell'algoritmo c'e' almeno una variabile con dominio vuoto significa che il grafo non puo' essere AC. E' incompleto perche' ci sono problemi in cui non esiste soluzione ma possono essere AC.

n variabili, d valori di dominio, max n<sup>2</sup> archi.

Costo O(n<sup>2</sup>d<sup>3</sup>).

![Imgur](https://i.imgur.com/6CuHiTh.png)

## Path consistency

Identifica i vincoli impliciti. Se ci sono archi x->y, y->z, allora verifica che per ogni assegnamento valido (x,y) esiste un valore di z valido.

## K-consistency

![Imgur](https://i.imgur.com/QweU17e.png)

Un CSP e' *fortemente* k-consistent se e' anche k-1, k-2 , k-3,... 1 consistent. (Non capisco, mi sembrava che se e' k-consistent e' per forza anche k-1 etc)

Se e' k-consistent allora e' risolvibile senza backtracking con complessita' O(nd). Il problema e' che capire se e' k-consistent ha costo esponenziale.

## Vincoli speciali

### Alldifferent(X1, …, Xn)

Tutte le variabili devono avere valori diversi. Basta guardare se il dominio ha piu' valori delle variabili.

### Atmost (N, A1, …, Ak)

N e' il numero di risorse, Ak e' il numero di risorse assegnate all'attivita' k. Se la sommatoria dei valori minimi assegnabili supera N allora il vincolo non puo' essere soddisfatto. Altrimenti si cancellano i valori massimi non consistenti con quelli minimi.

## Backjumping

Il backtracking non e' efficiente se arrivato a un vicolo cieco non capisce quale assegnamento lo ha causato.

Sia A un assegnamento parziale consistente, sia X una variabile non ancora assegnata. Se l’assegnamento A U {X=vi} risulta inconsistente per qualsiasi valore vi appartenente al dominio di X si dice che A è un conflict set di X.
