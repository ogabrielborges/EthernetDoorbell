/**
 * @file main.cpp
 * @author Gabriel Borges (https://github.com/ogabrielborges)
 * @brief 
 * @version 0.1
 * @date 2023-01-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// Inclusão das bibliotecas necessárias
#include <SPI.h>
#include <Ethernet.h>

#define DORBELL_PIN 2

// Endereço MAC do shield Ethernet
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// Endereço IP do Arduino na rede
IPAddress ip(192, 168, 29, 49);

// Variável para armazenar o estado do botão
int buttonState = 0;

// Instância da biblioteca Ethernet
EthernetClient client;

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);

  // Inicializa o Ethernet Shield
  Ethernet.begin(mac, ip);

  // Configura o pino do botão como entrada
  pinMode(DORBELL_PIN, INPUT);
}

void loop() {
  // Lê o estado atual do botão
  buttonState = digitalRead(DORBELL_PIN);

  // Verifica se o botão foi pressionado
  if (buttonState == HIGH) {
    // Conecta ao servidor IFTTT
    if (client.connect("maker.ifttt.com", 80)) {
      // Envia a requisição web em método post
      client.print("POST /trigger/criado/with/key/mR00EAxO8DKGV-E8ugvcfI4kx6D82EqHDT-jUnAdcCC HTTP/1.1\r\n");
      client.print("Host: maker.ifttt.com\r\n");
      client.print("Content-Type: application/json\r\n");
      client.print("Content-Length: 0\r\n");
      client.print("Connection: close\r\n\r\n");
    }
    // Aguarda até que a requisição seja enviada
    delay(1000);

    // Fecha a conexão com o servidor
    client.stop();

    // Imprime o status da conexão
    if (client.connected()) {
     Serial.println("Erro ao acionar o Trigger IFTTT");
    } else {
     Serial.println("Trigger acionado com sucesso");
    }
  }
}
