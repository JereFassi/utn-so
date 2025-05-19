# 🧵 Producer-Consumer Example in C (pthread)

Este ejemplo implementa el clásico problema **Productor-Consumidor** usando hilos (`pthread`), un mutex y variables de condición en C.

## 📋 Descripción - Cómo funciona

- **Productor:** Genera números del 1 a `MAX` y los coloca en un buffer compartido.
- **Consumidor:** Toma los números del buffer y los "consume" (en este caso, simplemente los elimina del buffer).
- **Sincronización:**
  - El buffer solo puede contener un valor a la vez (`buffer` es 0 o un número).
  - El productor espera si el buffer está lleno (no es 0).
  - El consumidor espera si el buffer está vacío (es 0).
  - Se utiliza un `pthread_mutex_t` para asegurar el acceso exclusivo al buffer.
  - Las variables de condición (`pthread_cond_t`) permiten que los hilos se notifiquen entre sí cuando pueden continuar.

## 🔄 Ejemplo paso a paso (con MAX = 3)

1. **Estado inicial:**

   - `buffer = 0`
   - Ambos hilos inician.

2. **Turno del productor:**

   - Bloquea el mutex.
   - Como `buffer == 0`, coloca `1` en el buffer.
   - Señala al consumidor.
   - Libera el mutex.

3. **Turno del consumidor:**

   - Bloquea el mutex.
   - Como `buffer != 0`, toma el `1` y pone `buffer = 0`.
   - Señala al productor.
   - Libera el mutex.

4. **Repite:**
   - El productor pone `2`, el consumidor lo toma, y así sucesivamente hasta `MAX`.

## 🖥️ ¿Qué verías si agregas prints?

Si agregas `printf` en el productor y consumidor, verías algo así:

```
Productor: produjo 1
Consumidor: consumió 1
Productor: produjo 2
Consumidor: consumió 2
Productor: produjo 3
Consumidor: consumió 3
```

## 📝 Resumen

- El código asegura que productor y consumidor se turnen usando el buffer.
- Nunca hay más de un valor en el buffer a la vez.
- Los hilos usan variables de condición para esperar y notificarse.
- Es un ejemplo básico de sincronización de hilos en C.

## 🚀 Compilación y ejecución

Compila con:

```bash
gcc -o producer_consumer_example producer_consumer_example.c -lpthread
```

Ejecuta con:

```bash
./producer_consumer_example
```

---

Puedes modificar el valor de `MAX` o agregar mensajes para ver el flujo de ejecución.
