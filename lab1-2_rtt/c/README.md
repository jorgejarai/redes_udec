## Estructura de la API

La API que les ofrezco (`rudp.h`) ofrece las siguientes funciones:

- `rudp_server_recv`: Utilizada por el servidor para recibir un mensaje de cualquier cliente.
- `rudp_server_send`: Utilizada por el servidor para responder al mensaje de algún cliente en específico.
- `rudp_client_send_recv`: Utilizada por el cliente para enviar un mensaje al servidor. Se bloquea hasta recibir una respuesta o haga _timeout_.

Les recomiendo revisar el código en `src/client.c` y `src/server.c` para entender cómo utilizar estas funciones e integrarlas a su proyecto.

## Compilación

El proyecto se compila de la forma usual con CMake, con la terminal dentro de esta carpeta (`lab1-2_rtt`):

```console
$ mkdir build
$ cd build
$ cmake ..
$ make```
