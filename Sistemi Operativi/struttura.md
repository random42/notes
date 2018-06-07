### Tecniche di modularizzazione

#### Stratificazione

Allo strato 0 c'e' l'HW, in quello piu' esterno la GUI. Ogni strato usa quello inferiore.

**Pro**:
- Semplicita' di progettazione
- Facile debug e testing
**Contro**:
- Definire gli strati
- Poca efficienza per troppe chiamate di funzioni

#### Microkernel

Il kernel e' minimale, contiene solo la gestione di processi, comunicazione e memoria.

Si installano moduli aggiuntivi che comunicano con il microkernel tramite messaggi.

**Pro**:
- Facilita' di estensione
- Maggiore sicurezza
- Adattabilita' a nuove architetture
**Contro**:
- Sovraccarichi per processi utente con funzionalita' di SO
- Colli di bottiglia dalla comunicazione indiretta


#### Moduli

Approccio migliore. Ogni modulo aggiunge system calls, e ha una interfaccia definita.

**Pro**:
- A differenza della stratificazione, ogni modulo puo usare qualsiasi altro.
- A differenza dei microkernel, la comunicazione e' diretta.
