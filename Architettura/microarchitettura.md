## Microarchitettura

### Mic-1

![Mic-1](https://upload.wikimedia.org/wikipedia/it/d/db/Mic-1.jpg)

### Registri

Registro | Uso
-|-
MAR | Indirizzo di memoria in cui scrivere o leggere
MDR | Parola letta o da scrivere tramite MAR
PC | Indirizzo di memoria per leggere 1 byte
MBR | Parola letta da PC, puo' essere signed o unsigned
SP | Indirizzo di cima dello stack
LV | Indirizzo di base dello stack
CPP | Indirizzo della constant pool
TOS | Parola in cima allo stack
OPC | Vario
H | Operando sinistro dell'ALU

Quando si esegue una lettura nel ciclo *k*, la parola sara' disponibile dal ciclo *k+2*

### Microistruzioni

36 bit per istruzione.

|Bit|Uso
-|-|-
Next address | 9 | Indirizzo della prossima istruzione
JAM | 3 | Serve a decidere Next address (per gli *if*)
ALU | 8 | Operazioni e shifter
Bus C | 9 | Registri di output
Memoria | 3 | read, write, fetch
Bus B | 4 | Operando destro (decoder 4 a 16)

### Determinare l'istruzione successiva

Il registro **MPC** determina l'indirizzo.

Il bit piu' significativo (Addr[8]) si calcola:

(JAMN and N) or (JAMZ and Z) or Addr[8]

Se JMPC == 1 MPC = MPC or MBR. In MBR c'e' l'*opcode* dell'istruzione. Solitamente quando JMPC == 1 MPC == 0x000 or 0x100

### MAL (Micro Assembly Language)

```
H = TOS // assegnazioni
H = TOS = MAR = H + MAR // operazione con H e altro registro, assegnazione multipla
MAR = MAR + 1; rd // incremento e lettura
MDR = TOS; wr // scrittura nel campo MDR, per poi scrivere MDR in memoria
Z = TOS
if (Z) goto L1; else goto L2 // Z/N usato come registro immaginario (per impostare JAMZ/JAMN)

// per utilizzare JMPC
goto(MBR or valore) // valore e' impostato in next_address
goto(MBR) // next_address varra' 0x000
```
