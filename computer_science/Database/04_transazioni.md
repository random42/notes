## Transazione

Una transazione è una unità di programma
La terminazione dell'unità di programma è decisa dall'applicazione attraverso due comandi:
– commit work
– rollback work

Il commit work richiede che le modifiche vengano effettuate e il DBMS verifica la validita' delle modifiche fino a quel punto.

Il rollback richiede che le modifiche vengano annullate.

Una transazione deve essere:
- Atomica
- Consistente
- Isolata
- Durabile

![Automa_transazione](https://i.imgur.com/VXuwd7x.png)
