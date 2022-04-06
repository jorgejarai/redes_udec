# Scripts para configuración de _proxy_

Ya que la red del DIICC necesita que usemos _proxies_ para mantener controlado el tráfico de red, necesitamos activarlos si queremos utilizar nuestras utilidades de terminal (como `apt`, `wget` o `git`, por nombrar algunas) dentro de ella. Para esto, tenemos estos _scripts_ que creé, los que nos van a servir para hacer más fácil el proceso de activar y desactivarlos.

Para poder usar estos comandos, necesitamos copiar estos archivos a una ubicación donde podamos ejecutarlos desde cualquier directorio, para lo cual tienen que ejecutar los siguientes comandos (sin copiar el signo `$`, por si acaso):

```console
$ mkdir -p ~/.local/bin		    # Crea el directorio donde irán los scripts
$ cp proxy_* ~/.local/bin	    # Copia los scripts dentro del directorio
$ chmod +x ~/.local/bin/proxy_*	    # Marca los scripts como ejecutables
```

## Cómo usar los _scripts_

La sintaxis que tenemos que usar es distinta a la que normalmente usamos para ejecutar comandos (no quiero aburrirlos con detalles, pero tiene que ver con configurar variables de entorno, necesarias para utilizar el _proxy_ del departamento).

Para activar el _proxy_, tienen que ejecutar:

```console
$ . proxy_on
```

Para desactivarlo:


```console
$ . proxy_off
```

Estos comandos los pueden ejecutar desde cualquier directorio, pues al dejarlos en la carpeta `~/.local/bin`, pasan a ser parte de `$PATH`, que es una lista de directorios donde se encuentran comandos de común uso; es decir, nos permite escribir `ls` en vez de su ruta completa `/usr/bin/ls`, ya que `/usr/bin` es parte de `$PATH`.
