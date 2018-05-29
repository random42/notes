## Grafi

G = (V, E)
V = vertici
E = archi -> (u,v)

Cappio = arco (v,v)

orientato: archi con verso
non orientato: archi in entrambi i versi (u,v) == (v,u)
aciclico:

### Rappresentazione

Liste di adiacenza: array di vertici, a ogni vertice c'e' la lista con i vertici adiacenti
Matrice di adiacenza: m[u][v] == 1 && (u,v) appartiene a E

### Visita in ampiezza (breadth-first search)

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
    for (v in adj[]) {
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

### Visita in profondita' (depth-first search)

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
E = tutte le possibili connessioni in V, con un peso associato

Problema: trovare un sottoinsieme aciclico di E che collega tutti i vertici con peso totale minimo.

**Kruskal, Prim con heap binari: O(E lgV)**

**Prim con heap di Fibonacci: O(E + VlgV)** solitamente migliore se |V| e' molto piu' piccolo di E
Sono algoritmi greedy.

Taglio = partizione di V
Arco leggero = arco con peso minimo tra quelli che attraversano il taglio

```
MST-Kruskal(G, w) {
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
