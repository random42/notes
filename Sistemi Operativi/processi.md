## Processi

### Stato di un processo

- nuovo
- ready
- running
- waiting
- terminato

### Process control block

Contiene:
- Stato del processo
- Program counter
- Copia dei registri CPU
- Info sullo scheduling della CPU (priorita' etc.)
- Info sulla memoria assegnata
- Contabilizzazione risorse
- Stato di I/O (dispositivi assegnati, file aperti...)

### Scheduling

- **Lungo termine**: (Nei sistemi **batch**) sceglie e carica in RAM un processo dalla memoria secondaria quando un processo termina
- **Medio termine**: Quando il grado di **multiprogrammazione** e' troppo alto i processi vengono spostati a turno in memoria secondaria
- **Breve termine**: Politica di avvincendamento della CPU tra i processi in RAM
