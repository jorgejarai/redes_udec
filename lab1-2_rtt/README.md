# Código para implementar fiabilidad sobre UDP

En esta carpeta, encontrarán código que les ayudará a implementar conexiones cliente-servidor bajo UDP, que espero que les sirva para la parte 2 del laboratorio 1.

Este proyecto genera dos ejecutables (`client` y `server`), los cuales pueden establecer una comunicación fiable, implementando números de secuencia en cada datagrama y un sistema de retransmisión "inteligente", que considera el RTT (_round-trip time_, el tiempo desde que se envía un mensaje hasta recibir una respuesta) para reintentar cada envío.

El código que verán aquí está inspirado en el que pueden encontrar en el sección 22.5 del libro _UNIX Network Programming: The sockets networking API_ (tercera edición). Es posible portarlo a otros lenguajes, ya que la rutina que calcula el _timeout_ está basada en fórmulas matemáticas simples, pero la forma en que se alerta al sistema que pasó el tiempo utiliza señales, un concepto que verán el próximo semestre en Sistemas Operativos. Además, con tal de ofrecer una API transparente, las funciones que les ofrezco utilizan las funciones `sendmsg(3)` y `recvmsg(3)` de la API POSIX, que no son necesariamente muy intuitivas. Si de verdad desean utilizar otro lenguaje, les recomiendo que me hablen para consultar dudas de implementación.

## Estructura de la API

La API que les ofrezco (`rudp.h`) ofrece las siguientes funciones:

-`rudp_server_recv`: Utilizada por el servidor para recibir un mensaje de cualquier cliente.
-`rudp_server_send`: Utilizada por el servidor para responder al mensaje de algún cliente en específico.
-`rudp_client_send_recv`: Utilizada por el cliente para enviar un mensaje al servidor. Se bloquea hasta recibir una respuesta o haga _timeout_.

Les recomiendo revisar el código en `src/client.c` y `src/server.c` para entender cómo utilizar estas funciones e integrarlas a su proyecto.

## Compilación

El proyecto se compila de la forma usual con CMake, con la terminal dentro de esta carpeta (`lab1-2_rtt`):

```console
$ mkdir build
$ cd build
$ cmake ..
$ make```
