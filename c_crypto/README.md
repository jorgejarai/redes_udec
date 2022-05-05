# Ejemplo de cifrado y descifrado con `libsodium`

En esta carpeta, encontrarán un proyecto con código de referencia para el cifrado y descifrado simétrico de datos con `libsodium` usando una llave secreta. El código que actúa de _wrapper_ para `libsodium` lo pueden encontrar en `src/crypto.c` e `include/crypto.h`, donde verán implementados un conjunto de funciones que facilitan el uso de esta librería.

## Instalación y compilación

En sistemas tipo Debian (como Ubuntu y Linux Mint), necesitan instalar el paquete `libsodium-dev` para poder compilar este código. En sistemas basados en Arch ~btw~, encontrarán la librería en `libsodium`.

Para compilar este proyecto, basta con seguir los pasos habituales para un proyecto con CMake:

```cmake
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## Cómo se usa

El proyecto se descompone en tres ejecutables:

- `keygen`: Genera una llave secreta para el cifrado y descifrado.
- `encrypt`: Cifra un archivo con la llave secreta.
- `decrypt`: Descifra un archivo con la llave secreta.

Antes de empezar con el cifrado y descifrado, se debe generar una llave secreta. Esto lo pueden lograr escribiendo

```console
$ ./keygen llave.key
```

El programa generará una llave secreta aleatoria, que se guardará en el archivo `llave.key`. Esta llave debe ser compartida previamente con el otro usuario que recibirá los archivos cifrados, idealmente por un canal seguro.

Hecho esto, podemos cifrar un archivo usando el programa `encrypt`:

```console
$ ./encrypt llave.key archivo.txt archivo.txt.enc
```

Con esto, generamos un archivo `archivo.txt.enc` que contiene el cifrado del archivo `archivo.txt` usando la llave secreta que generamos.

Ahora, para descifrar el archivo, podemos usar el programa `decrypt`:

```console
$ ./decrypt llave.key archivo.txt.enc archivo.txt
```

Pueden comprobar que el archivo descifrado es el mismo que el original si calculan el _hash_ de ambos archivos:

```console
$ ./decrypt llave.key archivo.txt.enc archivo.txt.out # Desciframos el archivo con otro nombre para poder comparar los hashes
$ md5sum archivo.txt archivo.txt.out
```

Los dos archivos deben tener el mismo _hash_.

## Cómo funciona

### Generación de la llave secreta

Por medio de la función `generate_key` (que utiliza la función `crypto_secretbox_keygen` de `libsodium`), se genera una llave secreta aleatoria. Esta es guardada en bruto en un archivo binario.

### Cifrado y descifrado

Para cifrar un archivo, utilizamos `encrypt`, la cual llama a la función `crypto_secretbox_easy` de `libsodium`. Sin embargo, para evitar determinados ataques criptográficos, esta última función necesita además de la llave una sal (_salt_, aunque también puede ser llamada _nonce_, como lo hace `libsodium`), la que, en conjunto con nuestra llave secreta, se usan como llave de cifrado para el archivo. Esta sal puede "exponerse" al público, pues todavía se necesita el archivo de llave para poder descrifrar el contenido.

Cuando el programa `encrypt` logra cifrar el archivo que el entreguemos, genera un archivo binario que concatena la sal (que tiene una longitud fija) con el archivo cifrado. Esto permite que, en conjunto con la llave que tendrá el destinatario, pueda hacer el proceso inverso usando el programa `decrypt`.

