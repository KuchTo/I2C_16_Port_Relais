# I2C_16_Port_Relais
Anschließen eines 16 Fach Relais Boards an den I2C Bus 

Das in mehreren Online-Shop angebotene 16-fach Relais Modul besitzt zur Ansteuerung 16 LOW aktive TTL- kompatible Eingänge. Wenn diese direkt an einen Arduino angeschlossen werden und getrennt angesteuert werden, bleiben für weitere Peripherie nicht mehr sehr viele freie Ports übrig. Ein Ausweg aus dieser Problematik bietet diese Bibliothek in Verbindung mit zwei von den verbreiteten I2C Port Expander Bausteinen PC8574, die pro Baustein 8 parallel Ausgänge und Eingänge an dem  I2C Bus zur Verfügung stelent. Das Relais Modul kann damit komplett über den I2C Bus unter belegung von 2 IC2 Adressen angesteuert werden.
