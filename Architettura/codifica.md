# Architettura degli elaboratori

## Codifica numeri relativi

In ogni codifica il primo bit rappresenta il segno.

\+ => 0

\- => 1

Eccetto per la notazione per eccesso

### Modulo e segno
11111111 = -127

01111111 = 127

- esiste +0 e -0
- la somma normale sbaglia risultato (-x + x)

### Complemento a uno
10 = 00001010

-10 = 11110101

Si invertono i bit e si ottiene l'opposto.

### Complemento a due

10 = 00001010

-10 = 11110110

-x = x con bit invertiti + 1

- unica rappresentazione dello 0
- un numero negativo in piu' (-128 su 8 bit)
- la somma funziona in ogni segno
- overflow facilmente riconoscibile

### Rappresentazione in eccesso 2^(n-1)

10 = 10001010

-10 = 00001010


## Codifica numeri in virgola mobile

Notazione scientifica:

n = m * 10^(e)

m = mantissa

e = esponente

**Standard IEEE 754**
- Ordine: segno, esponente, mantissa
- L'esponente si scrive in notazione per eccesso 2^(n-1)
- La mantissa e' normalizzata: la parte intera e' sempre 1,
i bit della mantissa sono dopo la virgola


Bit | Segno | Esponente | Mantissa
-|-|-|-
32 | 1 | 8 | 23
64 | 1 | 11 | 52

### Codifica caratteri
- **ASCII**: 7 bit (ma si usa 1 byte), alfabeto inglese, numeri, punteggiatura e simboli aritmetici
- **UNICODE**: 2 byte
- **UTF-8**: da 1 a piu' byte
