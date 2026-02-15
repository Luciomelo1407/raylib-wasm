# Projeto Logger

## Objetivo:

Esse projeto é um sistema de logger para dados de temperatura e pressão, a ideia principal era escrever os dados em um csv, porém, acabou se tranformando em um estudo de como medir temperatura e a demonstração de que a temperatura é nada mais e nada a menos que o grau de aditação das moléculas de certa maneira a “velocidade” a qual as moléculas se movem.

## Lista de materiais:

- ESP32
- Resistor de 10k e 5K ohms
- Termistor NTC 10k
- DHT11
- LCD

siga o esqurmático na raiz do projeto para fazer a montagem

## Para rodar o projeto:

Basta carregar o esp com o main.cpp na pasta embed, usando a arduino ide, lembre de baixar as dependencias no headder.

Para abrir o projeto web basta iniciar um servidor web python na pasta frontend:

 

```bash
python -m http.server PORT
```

Caso queira alterar algo no simulador de partículas recomendo seguir a dpcumentação do raylib, https://github.com/raysan5/raylib e do emscriptem, [https://emscripten.org/docs/index.html](https://emscripten.org/docs/index.html), o arquivo run em frontend/scrits pode te ajudar.