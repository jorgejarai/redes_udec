# Scripts para configuración de _proxy_

Ya que la red del DIICC necesita que usemos un _proxy_ para mantener controlado el tráfico de red, necesitamos activarlos si queremos utilizar nuestras utilidades de terminal (como `apt`, `wget` o `git`, por nombrar algunas) dentro de ella. Para esto, tenemos estos _scripts_ que creé, los que nos van a servir para hacer más fácil el proceso de activar y desactivarlos.

Primero, necesitan tener una copia de este repositorio en su máquina virtual. Si están usando el nuevo OVA, la carpeta ya va a estar en su escritorio. Para asegurarse de tener la última versión, ejecuten los siguientes comandos desde fuera de la red del DIICC (sin copiar el `$`, por si acaso):

```console
$ cd ~/Desktop/redes_udec
$ git pull
```

Si no tienen aquella carpeta, clónenla ejecutando:

```console
$ cd ~/Desktop
$ git clone https://github.com/jorgejarai/redes_udec
```

Si por alguna razón no pueden clonar el repositorio o actualizarlo ya que no pueden esquivar el _proxy_, les recomiendo que copien los archivos manualmente en la carpeta `~/Desktop/redes_udec`.

Luego, abramos un editor de texto:

```console
$ nano ~/.bashrc
```

Vamos a modificar la configuración de su _shell_ para incorporar los _scripts_ que necesitamos. Para esto, agreguen al final del archivo lo siguiente:

```bash
alias proxy_on="source ~/Desktop/redes_udec/proxy/proxy_on"
alias proxy_off="source ~/Desktop/redes_udec/proxy/proxy_off"
```

Para salir del editor, presionen Ctrl+O, seguido de Enter y Ctrl+X.

## Cómo usar los _scripts_

Activar el _proxy_ es un proceso bastante sencillo, pues basta con ejecutar `proxy_on` en su terminal. Para desactivarlo, ejecuten `proxy_off`.
