# OpenPort
PortScanner es una herramienta de escaneo de puertos desarrollada en C++ que utiliza multithreading para mejorar la 
eficiencia del escaneo. Permite identificar qué puertos están abiertos en un host determinado.

Uso de multithreading para mejorar la velocidad de escaneo.
Uso de multiprocessing para mejorar la velocidad de escaneo de multiples IPs.

Implementación de sockets para realizar conexiones a los puertos objetivo.

## Requisitos
- Compilador C++ compatible con C++20 o superior (g++ recomendado)
- CMake (opcional, para facilitar la compilación)

## Uso 

Para ejecutar el escáner de puertos, usa el siguiente comando:
````shell
./openport 192.168.1.1 20 1000
````
Esto escaneará los puertos del 20 al 1000 en la IP 192.168.1.1.

### Ejemplo de salida

````shell
[+] Escaneando 192.168.1.1...
[+] Puerto 22 abierto.
[+] Puerto 80 abierto.
[-] Escaneo completado.
````