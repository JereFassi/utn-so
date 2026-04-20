# Planificacion de la CPU: observar context switches

Guia practica en Ubuntu/WSL.

Objetivo: usar comandos de terminal para observar cambios de contexto a nivel sistema y a nivel proceso.

## Preparacion

`vmstat` viene en el paquete `procps`. Si no esta disponible:

```bash
sudo apt update
sudo apt install procps
```

## 1. Ver context switches del sistema

Ejecutar:

```bash
vmstat 1 5
```

Leer la columna `cs`:

```text
procs -----------memory---------- ---swap-- -----io---- -system-- -------cpu-------
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 1  0      0 123456  12345 678901    0    0     1     2  120  350  4  2 93  1  0
 2  0      0 123000  12345 679000    0    0     0     0  400 1200 15  5 80  0  0
```

Observar:

- `cs`: context switches por segundo en todo el sistema.
- `r`: procesos listos para ejecutar.
- `us`: tiempo de CPU en codigo de usuario.
- `sy`: tiempo de CPU en codigo del sistema/kernel.
- `id`: CPU ociosa.

## 2. Ver context switches de un proceso

Ver el PID de la shell actual:

```bash
echo $$
```

Inspeccionar el proceso:

```bash
cat /proc/$$/status | grep ctxt
```

Salida esperada:

```text
voluntary_ctxt_switches:        12
nonvoluntary_ctxt_switches:      3
```

Observar:

- `voluntary_ctxt_switches`: el proceso cedio la CPU porque espero algo.
- `nonvoluntary_ctxt_switches`: el sistema operativo le quito la CPU.

Estos valores son acumulados para ese proceso. No son valores por segundo.

## 3. Proceso que espera

Ejecutar:

```bash
sleep 30 &
PID=$!
cat /proc/$PID/status | grep ctxt
```

Esperar unos segundos y repetir:

```bash
cat /proc/$PID/status | grep ctxt
```

## 4. Proceso que consume CPU

Ejecutar:

```bash
yes > /dev/null &
PID=$!
```

Mirar el sistema mientras corre:

```bash
vmstat 1 5
```

Mirar el proceso:

```bash
cat /proc/$PID/status | grep ctxt
```

Detenerlo:

```bash
kill $PID
```

Referencias:

- `yes` intenta ejecutar todo el tiempo.
- Al no quedarse esperando entrada de usuario, el planificador debe sacarlo de la CPU.
- Es esperable que aumenten los cambios no voluntarios.

## Referencia rapida

| Comando                  | Para que sirve                                                     |
| ------------------------ | ------------------------------------------------------------------ |
| `vmstat 1 5`             | Muestra estadisticas globales del sistema cada 1 segundo, 5 veces. |
| `cat /proc/<PID>/status` | Muestra informacion detallada de un proceso.                       |
| `grep ctxt`              | Filtra solo las lineas de context switches.                        |
| `echo $$`                | Muestra el PID de la shell actual.                                 |
| `$!`                     | Contiene el PID del ultimo proceso ejecutado en segundo plano.     |

## Campos importantes

| Campo                        | Significado                                                |
| ---------------------------- | ---------------------------------------------------------- |
| `cs`                         | Context switches por segundo en todo el sistema.           |
| `voluntary_ctxt_switches`    | Cambios de contexto voluntarios acumulados del proceso.    |
| `nonvoluntary_ctxt_switches` | Cambios de contexto no voluntarios acumulados del proceso. |
| `r`                          | Procesos listos para ejecutar.                             |
| `us`                         | CPU ejecutando codigo de usuario.                          |
| `sy`                         | CPU ejecutando codigo del sistema/kernel.                  |
| `id`                         | CPU ociosa.                                                |
