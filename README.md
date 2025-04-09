# Material de Aula IOT com esp8266.

Este documento descreve os requisitos e passos para configurar o ambiente de desenvolvimento para as aulas.

## Requisitos

Para acompanhar as aulas, você precisará instalar os seguintes softwares:

* **Visual Studio Code IDE:** [https://code.visualstudio.com/](https://code.visualstudio.com/) - O editor de código que utilizaremos.
* **Extensão C/C++ para VSCode:** [https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) -  Fornece suporte para desenvolvimento em C/C++ no VSCode.
* **Extensão Clang-Format para VSCode:** [https://marketplace.visualstudio.com/items?itemName=xaver.clang-format](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format) -  Formata o código automaticamente seguindo o estilo do Clang.
* **Extensão PlatformIO para VSCode:** [https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide) -  Framework para desenvolvimento de projetos embarcados.


## Instalação

1. **Visual Studio Code:** Baixe e instale o VSCode a partir do link fornecido acima.

2. **Extensões:**
    * Abra o VSCode.
    * Clique no ícone de Extensões na barra de atividades (ou pressione `Ctrl+Shift+X`).
    * Pesquise por cada uma das extensões listadas acima (C/C++, Clang-Format, PlatformIO).
    * Clique no botão "Instalar" para cada extensão.

3. **Configuração (Opcional):**
    * Após instalar as extensões, você pode configurá-las de acordo com suas preferências.  Consulte a documentação de cada extensão para mais detalhes.


## Próximos Passos

Após instalar os requisitos, você estará pronto para começar a desenvolver! Consulte os materiais da aula para instruções específicas sobre cada projeto.


# Implementando Código no ESP8266

Este exemplo demonstra como controlar um LED conectado ao pino 2 do ESP8266.

## Adicionando o Código

No projeto, dentro da pasta `src`, localize o arquivo `main.cpp`.  Substitua o conteúdo do arquivo pelo seguinte código:

```cpp
#include <Arduino.h>

const byte LED = 2; // Define o pino do LED (D4 no NodeMCU)

void setup() {
  Serial.begin(115200); // Inicializa a comunicação serial
  pinMode(LED, OUTPUT);  // Configura o pino do LED como saída
}

void loop() {
  Serial.println("Low Voltage"); // Imprime "Low Voltage" no monitor serial
  digitalWrite(LED, LOW);       // Desliga o LED
  delay(1000);                  // Aguarda 1 segundo

  Serial.println("High Voltage"); // Imprime "High Voltage" no monitor serial
  digitalWrite(LED, HIGH);      // Liga o LED
  delay(1000);                  // Aguarda 1 segundo
}
```

## Adicionando Bibliotecas

Para adicionar as bibliotecas necessárias ao seu projeto, adicione as seguintes linhas ao seu arquivo `platformio.ini`:

```ini
lib_deps =
    knolleary/PubSubClient@^2.8
    adafruit/Adafruit GFX Library@^1.11.3
    adafruit/Adafruit SSD1306@^2.5.7
