# Código para implementar fiabilidad sobre UDP

En esta carpeta, encontrarán código que les ayudará a implementar conexiones cliente-servidor bajo UDP, que espero que les sirva para la parte 2 del laboratorio 1.

Tanto la versión en C como en Python que encontrarán en esta carpeta consideran dos ejecutables (un cliente y un servidor), los cuales pueden establecer una comunicación fiable, implementando números de secuencia en cada datagrama y un sistema de retransmisión "inteligente", que considera el RTT (_round-trip time_, el tiempo desde que se envía un mensaje hasta recibir una respuesta) para reintentar cada envío.

El código que verán aquí está inspirado en el que pueden encontrar en el sección 22.5 del libro _UNIX Network Programming: The sockets networking API_ (tercera edición).
