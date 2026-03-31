## Explicacion del Ejemplo de Layout de Memoria

Este ejemplo demuestra el layout de memoria de un programa en C, mostrando como se almacenan las variables en diferentes segmentos de memoria.

### Componentes Clave

1. **Variables Globales**

   ```c
   int x;
   int y = 15;
   ```

   - `x` es una variable global no inicializada (se almacena en el segmento BSS).
   - `y` es una variable global inicializada (se almacena en el segmento Data).

2. **Asignacion Dinamica de Memoria**

   ```c
   int *values;
   values = (int *)malloc(sizeof(int) * 5);
   ```

   - Asigna memoria para un arreglo de 5 enteros en el Heap.

3. **Variables de Stack**
   ```c
   int i;
   for (i = 0; i < 5; i++)
     values[i] = i;
   ```
   - `i` es una variable local (se almacena en el Stack).
   - El bucle inicializa el arreglo asignado dinamicamente.

### Compilacion y Ejecucion

```bash
# Compilar el ejemplo
gcc src/02-procesos/unix/memory_layout_example.c -o memory_layout_example

# Ejecutar el programa
./memory_layout_example
```

### Explicacion

- **Segmento BSS:** Almacena variables globales/estaticas no inicializadas (`x`).
- **Segmento Data:** Almacena variables globales/estaticas inicializadas (`y`).
- **Heap:** Almacena memoria asignada dinamicamente (arreglo `values`).
- **Stack:** Almacena variables locales e informacion de llamadas a funciones (`i`, parametros de funcion).

Este ejemplo ayuda a visualizar como se organiza la memoria de un programa en C en tiempo de ejecucion.

---

## Explicacion del Ejemplo de Fork

Este ejemplo demuestra creacion y gestion de procesos usando fork() en C:

### Componentes Clave

1. **Creacion de Procesos**

   ```c
   pid_t pid = fork();
   ```

   Crea un nuevo proceso hijo que es una copia exacta del proceso padre.

2. **Identificacion de Procesos**

   ```c
   printf("Child process %d (PID: %d, Parent PID: %d) starting...\n",
          i + 1, getpid(), getppid());
   ```

   Muestra como identificar procesos usando:

   - `getpid()`: Obtener el ID del proceso actual
   - `getppid()`: Obtener el ID del proceso padre

3. **Sincronizacion de Procesos**
   ```c
   while ((pid = wait(&status)) > 0) {
       printf("Child process (PID: %d) finished with status %d\n",
              pid, WEXITSTATUS(status));
   }
   ```
   El proceso padre espera a que todos los procesos hijo terminen usando `wait()`.

### Compilacion y Ejecucion

```bash
# Compilar el ejemplo
gcc src/02-procesos/fork_example.c -o fork_example

# Ejecutar el programa
./fork_example
```

### Salida Esperada

```
Parent process (PID: xxxx) starting...
Child process 1 (PID: yyyy, Parent PID: xxxx) starting...
Child process 2 (PID: zzzz, Parent PID: xxxx) starting...
Child process 3 (PID: wwww, Parent PID: xxxx) starting...
Child process (PID: yyyy) finished with status 0
Child process (PID: zzzz) finished with status 0
Child process (PID: wwww) finished with status 0
```

Nota: Los PID reales seran diferentes en cada ejecucion.

---

## Explicacion del Ejemplo de Fork y Exec

Este ejemplo demuestra creacion de procesos y ejecucion de comandos usando fork() y exec() en C:

### Componentes Clave

1. **Creacion de Procesos**

   ```c
   pid_t pid = fork();
   ```

   Crea un nuevo proceso hijo que es una copia exacta del proceso padre.

2. **Ejecucion de Comandos**

   ```c
   execlp("/bin/ls", "ls", NULL);
   ```

   El proceso hijo ejecuta el comando 'ls':

   - `execlp`: Ejecuta un archivo usando la variable de entorno PATH
   - Primer argumento: Ruta al ejecutable
   - Segundo argumento: Nombre del programa
   - NULL: Finaliza la lista de argumentos

3. **Espera del Padre**
   ```c
   wait(NULL);
   printf("Child Complete \n");
   ```
   El proceso padre espera a que el hijo termine antes de continuar.

### Compilacion y Ejecucion

```bash
# Compilar el ejemplo
gcc src/02-procesos/fork2_example.c -o fork2_example

# Ejecutar el programa
./fork2_example
```

### Salida Esperada

```
[Listado del directorio generado por ls]
Child Complete
```

Nota: El listado real dependera del contenido de tu directorio actual.
