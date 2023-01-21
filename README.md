EthernetDoorbell é um código muito rápido que envia para o IFTTT uma requisição web em método POST após um botão ser pressionado!
Foi criado apenas para alimentar uma idéia de utilizar hardwares que eu ja tinha em meu alcance, para fazer uma campainha em um lugar remoto que tem um ponto de internet via cabo mas não tem uma rede wifi com um bom sinal para um ESP8266 se conectar!

Via IFTTT voce pode escolher qual ação vai ser executada ao pressionar o botão (Utilizei um [Webhook IFTTT](https://ifttt.com/maker_webhooks))


Note que o projeto utiliza um Arduino Uno R3 Italiano e um Ethernet Shield W5100 Acoplado

Dependencias:
- [SPI](https://github.com/arduino/ArduinoCore-avr/tree/master/libraries/SPI "Biblioteca SPI padrão da Arduino")
- [Ethernet](https://github.com/arduino-libraries/Ethernet "Biblioteca Ethernet  padrão da Arduino")

Materiais para a montagem do esquema:
- Arduino Uno
- Ethernet Shield (Compatível com a biblioteca Ethernet da Arduino)
- Resistor 2k
- Botão Tactil
- Alguns jumpers

O esquema de montagem ficará dessa forma:

![image](https://user-images.githubusercontent.com/36484705/213842532-14f0b8f1-7725-47f7-bddb-042d97129471.png)
