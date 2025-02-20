# OpenPort
PortScanner es una herramienta de escaneo de puertos desarrollada en C++ que utiliza multithreading para mejorar la 
eficiencia del escaneo. Permite identificar qué puertos están abiertos en un host determinado.

Uso de multithreading para mejorar la velocidad de escaneo.
Uso de multiprocessing para mejorar la velocidad de escaneo de multiples IPs.

Implementación de sockets para realizar conexiones a los puertos objetivo.

## Requisitos
- Compilador C++ compatible con C++20 o superior (g++ recomendado)
- CMake (opcional, para facilitar la compilación)
- Windows
## Uso 

Para ejecutar el escáner de puertos, usa el siguiente comando:
````shell
./OpenPort.exe 192.168.1.1 20 1000 192.168.1.2 1000 10000
````
Esto escaneará los puertos del 20 al 1000 en la IP 192.168.1.1.

### Ejemplo de salida

````shell
Proceso creado para IP: 192.168.1.1 de 20 hasta 1000 (PID: 39408)
Proceso creado para IP: 192.168.1.2 de 1000 hasta 20000 (PID: 39200)
[-] Escaneando 192.168.1.1 del puerto 20 hasta el puerto 1000...
[-] Escaneo a 192.168.1.1 completado.
[-] Escaneando 192.168.1.2 del puerto 1000 hasta el puerto 10000...
[+] Puerto 5040 abierto.
[+] Puerto 5432 abierto.
[+] Puerto 7680 abierto.
[-] Escaneo a 192.168.1.2 completado.
````
