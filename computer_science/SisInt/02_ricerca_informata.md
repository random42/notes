# Strategie di ricerca informate

Si usa una **funzione di valutazione** f(n) che comprende una **funzione euristica** h(n). h(n) e' una stima del costo per arrivare a uno stato goal. Si valutano i nodi della frontiera e si espandono prima quelli con piu' probabilita' di arrivare alla soluzione.

## Ricerca greedy

f(n) = h(n)

Ha i problemi della ricerca in profondita'. Rischio di loop per vicoli ciechi.

## A*

T = insieme dei nodi obiettivo
h(n) = costo minimo per arrivare a uno dei nodi obiettivo

![Imgur](https://i.imgur.com/DgVQMYF.png)

f(n) = g(n) + h(n)

g(n) = costo minimo per raggiungere n dal nodo iniziale s

f<sup>\*</sup>(n) = g<sup>\*</sup>(n) + h<sup>*</sup>(n)

f<sup>*</sup>(n) = costo reale

L'algoritmo termina e trova una soluzione ottimale se h(n) <= h<sup>*</sup>(n) e ogni passo ha un costo maggiore di una costante piccola a piacere.

[Dimostrazioni](https://informatica.i-learn.unito.it/pluginfile.php/180252/mod_resource/content/1/3_ricerca_informata-23-73.pdf)

IDA\* e' un'algoritmo che unisce A* con iterative deepening.

## Recursive Best-First Strategy (RBFS)

Come la ricerca in profondita' ma usa un *upper-bound* per focalizzare la ricerca sul percorso piu' promettente. Complessita' spaziale bassa ma lo stesso nodo puo' essere visitato piu' volte.

![Imgur](https://i.imgur.com/Qh7TCGW.png)

## Euristiche

L'efficienza di questi algoritmi si basa sulla qualita' della funzione euristica. Bisogna usare la funzione maggiore tra quelle ammissibili (ovver quella che approssima meglio).

Un **problema rilassato** e' un problema con meno vincoli e quindi piu' azioni possibili. Il suo grafo e' un supergrafo del problema originario. Togli vincoli quando puoi astrarre una serie di azioni in un'azione unica. Tramite queste astrazioni e' possibile generare euristiche.

Dato un insieme di euristiche ammissibili in cui nessuna domina e' possibile generarne una dominante usando il massimo tra le varie euristiche.

**Apprendimento automatico**: estrae euristiche da dati statistici.
