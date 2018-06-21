# Grafi

G = (V, E)
V = vertici
E = archi -> (u,v)

Cappio = arco (v,v)

- orientato: archi con verso
- non orientato: archi in entrambi i versi (u,v) == (v,u)
- aciclico: puoi immaginare
- connesso: esiste un cammino tra ogni coppia di vertici

### Rappresentazione

- **Liste di adiacenza**: array di vertici, a ogni vertice c'e' la lista con i vertici adiacenti
- **Matrice di adiacenza**: m[u][v] == 1 && (u,v) appartiene a E

## Visita in ampiezza (breadth-first search)

**O(V + E)**
```
BFS(G, s) {
  // per ogni vertice
  for (u in V) {
    u.color = WHITE; // non visitato
    u.d = INFINITY;
    u.pi = NIL;
  }
  s.color = GRAY; // visitato
  s.d = 0; // distanza da s
  s.pi = NIL; // padre
  Q = {};
  enqueue(Q, s);
  while (Q.length > 0) {
    u = dequeue(Q);
    // per ogni vertice adiacente a u
    for (v in adj[u]) {
      if (v.color == WHITE) {
        v.color = GRAY;
        v.d = u.d + 1;
        v.pi = u;
        enqueue(Q, v);
      }
      u.color = BLACK;
    }
  }
}
```

Si ha la distanza minima da ogni vertice a s contenuta in d.

## Visita in profondita' (depth-first search)

**O(V + E)**

```
DFS(G) {
  for (v in V) {
    u.color = WHITE;
    u.pi = NIL;
  }
  time = 0;
  for (u in V) {
    if (u.color == WHITE) {
      DFS-Visit(G, u);
    }
  }
}

DFS-Visit(G, u) {
  time++;
  u.d = time;
  u.color = GRAY;
  for (v in Adj[u]) {
    if (v.color == WHITE) {
      v.pi = u;
      DFS-Visit(G, v);
    }
    u.color = BLACK;
    time++;
    u.f = time;
  }
}
```

Se u.d > v.d > v.f > u.f (quindi (1,4):(2,3)) allora v e' discendente di u

Data la foresta di alberi DF si definiscono 4 tipi di alberi:

Tipo | Proprieta'
-|-
Archi d'albero | (u,v) : v.pi = u
Archi all'indietro | (u,v) : u discendente di v, anche i cappi
Archi in avanti | (u,v) : v discendente di u
Archi trasversali | vertici non discendenti dello stesso albero o tra alberi diversi

### Ordinamento topologico

Ordine lineare di vertici in un **grafo orientato aciclico** per cui v[i].f > v[j].f && j > i
Usato per ordinare gli eventi.

Algoritmo: DFS, quando il vertice diventa BLACK lo si aggiunge in testa alla lista.


### Componenti fortemente connesse

Definizione:
Sottoinsieme di vertici C tale che per ogni coppia u,v in C, si puo' arrivare da u a v e viceversa

Algoritmo:
```
DFS(G)
Calcola G~t -> Grafo con archi inversi
DFS(G~t) considerando i vertici in ordine decrescente di v.f (ordinamento topologico)
Ogni componente e' un albero di DF G~t
```
## Alberi di connessione minimi

Dato un grafo non orientato.

E = tutte le possibili connessioni in V, con peso associato

Problema: trovare un sottoinsieme aciclico di E che collega tutti i vertici con peso totale minimo.

**Kruskal, Prim con heap binari: O(E lgV)**

**Prim con heap di Fibonacci: O(E + VlgV)** solitamente migliore se |V| e' molto piu' piccolo di E
Sono algoritmi greedy.

Taglio = partizione di V
Arco leggero = arco con peso minimo tra quelli che attraversano il taglio


### Kruskal

Ordina gli archi in ordine crescente per costo, e per ogni arco se i vertici non sono nello stesso *set*, li unisce nello stesso set e aggiunge l'arco al risultato.

```
MST-Kruskal(G, w = funzione peso) {
  A = [];
  for (v in G.V) {
    makeSet(v);
  }
  sort G.E in ordine crescente per peso
  for ((u,v) in G.E) {
    if (findSet(u) != findSet(v)) {
      A.push((u,v));
      union(u,v);
    }
  }
  return A;
}
```

### Prim

Algoritmo goloso. Crea un albero.

```
MST-Prim(G, w, r = radice) {
  for (u in G.V) {
    u.key = Infinity; // peso minimo di un arco che collega u a un vertice dell'albero
    u.pi = NIL; // padre
  }
  r.key = 0;
  Q = G.V; // coda di priorita' min (di key)
  while (Q.length > 0) {
    u = extractMin(Q);
    for (v in G.Adj[u]) {
      // se il peso dell'arco (u,v) e' minore del peso minimo fin'ora trovato
      // v entra nell'albero
      if (v isIn Q && w(u,v) < v.key) {
        v.pi = u;
        v.key = w(u,v);
      }
    }
  }
}
```

## Cammini minimi

Se esistono pesi negativi e ci sono cicli negativi il cammino minimo tra una sorgente e un vertice del ciclo e' -Infinity.

L'algoritmo di Dijkstra usa pesi positivi, quello di Bellman-Ford anche negativi ma segnala se ci sono cicli negativi.

Un albero di cammini minimi con sorgente *s* contiene tutti i cammini minimi tra *s* e i vertici raggiungibili da *s*. Simile alla ricerca in ampiezza ma con cammini misurati per peso.

### Rilassamento

Semplicemente si inizializza ogni vertice con il peso del cammino minimo e il predecessore

```
Initialize-Single-Source(G, s) {
  for (v in G.V) {
    v.d = Infinity; // peso del cammino da s
    v.pi = NIL; // predecessore
  }
}

Relax(u,v,w) {
  // se il peso di questo cammino e' minore del peso corrente
  if (v.d > u.d + w(u,v)) {
    v.d = u.d + w(u,v);
    v.pi = u;
  }
}
```

### Algoritmo di Bellman-Ford

```
Bellman-Ford(G, w, s) {
  Initialize-Single-Source(G, s);
  for (i = 1 to G.V.length-1) {
    for ((u,v) in G.E) {
      Relax(u,v,w);
    }
  }
  for ((u,v) in G.E) {
    if (v.d > u.d + w(u,v)) {
      return FALSE;
    }
  }
  return TRUE;
}
```

### Algoritmo di Dijkstra

```
Dijkstra(G, w, s) {
  Initialize-Single-Source(G, s);
  S = [];
  Q = G.V;
  while (Q.length > 0) {
    u = extractMin(Q);
    S.push(u);
    for (v in Adj[u]) {
      Relax(u,v,w);
    }
  }
}
```
