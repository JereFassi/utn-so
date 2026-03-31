> 🇪🇸 [Leer en español](README.es.md)

## Explicacion del Ejemplo de Mutex

Este ejemplo demuestra la sincronizacion de hilos usando mutexes en C:

### Componentes Clave

1. **Declaracion del Mutex y Recurso Compartido**

   ```c
   pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
   int shared_counter = 0;
   ```

   Crea un mutex para la sincronizacion de hilos y una variable contador compartida.

2. **Funcion del Hilo**

   ```c
   void *thread_function(void *arg) {
       pthread_mutex_lock(&mutex);
       shared_counter++;
       printf("Thread %d: counter = %d\n", thread_id, shared_counter);
       pthread_mutex_unlock(&mutex);
   }
   ```

   Muestra la proteccion de la seccion critica usando:

   - `pthread_mutex_lock()`: Bloquea el mutex antes de acceder al recurso compartido
   - `pthread_mutex_unlock()`: Libera el mutex despues de la modificacion

3. **Creacion y Gestion de Hilos**
   ```c
   pthread_t threads[NUM_THREADS];
   for (int i = 0; i < NUM_THREADS; i++) {
       thread_ids[i] = i + 1;
       pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
   }
   ```
   Crea y gestiona multiples hilos usando la biblioteca pthread.

### Compilacion y Ejecucion

```bash
# Compilar el ejemplo (nota la opcion -pthread)
gcc src/03-threads/mutex_example.c -o mutex_example -pthread

# Ejecutar el programa
./mutex_example
```

### Salida Esperada

```
Thread 1: counter = 1
Thread 3: counter = 2
Thread 2: counter = 3
Thread 4: counter = 4
Thread 1: counter = 5
...
```

Nota: El orden de ejecucion de los hilos puede variar debido a intervalos de espera aleatorios.
