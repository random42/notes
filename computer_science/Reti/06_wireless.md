# Wireless and mobile

### Preview

![wireless_links](https://i.imgur.com/2xBCdCw.png)

### Caratteristiche

- Il segnale diminuisce in base alla distanza e la materia in mezzo
- C'e' interferenza da altri device perche' ci sono frequenze standard
- Multipath: il segnale rimbalza sugli oggetti quindi arriva a tempi diversi
- SNR: signal-to-noise ratio, maggiore e' minore e' BER (bit error ratio)

![snr_ber](https://i.imgur.com/6GYuiay.png)

## CDMA (Code Division Multiple Access)

Ogni nodo ha un 'code'.

Codifica il segnale moltiplicando i dati per il codice.

![cdma](https://i.imgur.com/4grY5fk.png)

## IEEE 802.11 Wireless

AP = access point (stazione wireless)

AKA WiFi.

Ci sono varie versioni, la migliore e' la 802.11n che ha 200 Mbps.

Usano tutte CSMA/CA per l'accesso multiplo.

Per trasmettere l'host vede se il canale e' idle, manda RTS packet (request-to-send), l'AP risponde con CTS (clear-to-send) packet che ricevono tutti cosi l'host trasmette e gli altri sanno che devono aspettare. Se il frame arriva con successo l'AP manda ACK packet.

![rts_ctl](https://i.imgur.com/JZX1P1U.png)

### Frame

![wifi_frame_1](https://i.imgur.com/jUsRuA0.png)
![wifi_frame_2](https://i.imgur.com/idoPruH.png)

### 802.15 Personal area network

10m di raggio. E' come il bluetooth. C'e' un master e uno slave che chiede il permesso per trasmettere. Si usa per cuffie, mouse etc.

# Cellular Internet access

## Architecture

![cell_architecture](https://i.imgur.com/9NVZtk6.png)

Per l'accesso multiplo ci sono due possibilita':
- FDMA/TDMA combinati, quindi divisione sia in frequenza che in tempo
- CDMA
