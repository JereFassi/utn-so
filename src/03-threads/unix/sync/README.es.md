> 🇬🇧 [Read in English](README.md)

# 🔗 Ejemplos de Sincronización de Hilos (C)

Esta carpeta contiene ejemplos clásicos de sincronización de hilos en C, demostrando el uso de mutexes, variables de condición y algoritmos de exclusión mutua. Cada subcarpeta incluye el código fuente y un README con explicaciones.

---

## 📁 Estructura de Carpetas

```
sync/
├── mutex/
│   ├── mutex_example.c
│   └── README.md
├── peterson/
│   ├── petersons_solution_i.c
│   ├── petersons_solution_j.c
│   └── README.md
└── producer-consumer/
    ├── producer_consumer_example.c
    ├── producer_consumer_example_verbose.c
    └── README.md
```

---

## 📚 Resumen de Ejemplos

### 1. `mutex/` – Ejemplo de Mutex

- **Propósito:** Demuestra la sincronización básica de hilos usando un `pthread_mutex_t`.
- **Qué muestra:** Cómo proteger un recurso compartido (como un contador) para que solo un hilo pueda modificarlo a la vez.
- **Cómo ejecutar:**
  ```bash
  gcc mutex_example.c -o mutex_example -pthread
  ./mutex_example
  ```
- **Ver:** [`mutex/README.md`](mutex/README.md) para detalles y salida esperada.

---

### 2. `peterson/` – Algoritmo de Peterson

- **Propósito:** Muestra una solución solo de software para la exclusión mutua entre dos hilos (sin primitivas de hardware).
- **Archivos:**
  - `petersons_solution_i.c` – Código del hilo i.
  - `petersons_solution_j.c` – Código del hilo j.
- **Cómo ejecutar:** Compila y ejecuta cada archivo por separado.
- **Ver:** [`peterson/README.md`](peterson/README.md) para explicación y uso.

---

### 3. `producer-consumer/` – Problema Productor-Consumidor

- **Propósito:** Ejemplo clásico de sincronización entre hilos productor y consumidor usando mutexes y variables de condición.
- **Archivos:**
  - `producer_consumer_example.c` – Versión básica.
  - `producer_consumer_example_verbose.c` – Con mensajes detallados para seguimiento.
- **Cómo ejecutar:**
  ```bash
  gcc producer_consumer_example.c -o producer_consumer_example -lpthread
  ./producer_consumer_example
  ```
- **Ver:** [`producer-consumer/README.md`](producer-consumer/README.md) para explicación paso a paso y salida de ejemplo.

---

## 📝 Notas

- Todos los ejemplos usan hilos POSIX (`pthread`).
- Asegúrate de compilar con la opción `-pthread` o `-lpthread`.
- Cada subcarpeta contiene un README con más detalles, explicaciones y salidas esperadas.

---

## 🚀 Primeros Pasos

1. Elige una carpeta de ejemplo.
2. Lee su `README.md` para contexto.
3. Compila el/los archivo(s) `.c` usando GCC y la opción de hilos.
4. Ejecuta el binario resultante para observar la sincronización de hilos en acción.

---

¡Feliz programación! 🧵
