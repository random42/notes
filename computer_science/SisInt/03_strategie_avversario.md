# Strategie di ricerca con avversario

Ci sono piu' agenti con obiettivi conflittuali. Questi problemi di ricerca sono detti giochi e.e

![Imgur](https://i.imgur.com/fkmdCBQ.png)

Un gioco a somma zero e' un gioco in cui un guadagno di un agente significa una perdita di un altro agente.

Gli stati terminali hanno un valore di utilita', per indicare win/loss/draw.

## Minimax

Se il gioco e' a due agenti si usa MiniMax.

![Imgur](https://i.imgur.com/GAwhF3C.png)

## Alfa-beta

Poiche' minimax e' una visita' in profondita' completa bisogna potare i rami inutili.

![Imgur](https://i.imgur.com/I6ORUmG.png)

Se si espandono i nodi piu' promettenti per primi si ha complessita' O(b<sup>m/2</sup>) perche' il branching factor diventa la radice quadrata dell'originale. Se i nodi non possono essere ordinati si ha complessita' O(b<sup>3m/4</sup>).

Bisogna tenere una **tabella delle trasposizioni** per gli stati raggiungibili con percorsi diversi, cosi' da non visitarli piu' di una volta.

Poiche' non sempre si arriva a uno stato terminale serve una funzione di valutazione per capire la probabilita' di vittoria/pareggio/sconfitta di uno stato. Si valutano diverse proprieta' ognuna associata a un parametro di importanza e si valuta la posizione.
