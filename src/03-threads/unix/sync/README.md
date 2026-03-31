> 🇪🇸 [Leer en español](README.es.md)

# 🔗 Ejemplos de Sincronizacion de Hilos (C)

Esta carpeta contiene ejemplos clasicos de sincronizacion de hilos en C, demostrando el uso de mutexes, variables de condicion y algoritmos de exclusion mutua. Cada subcarpeta incluye codigo fuente y un README con explicaciones.

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

### 1. `mutex/` - Ejemplo de Mutex

- **Proposito:** Demuestra la sincronizacion basica de hilos usando un `pthread_mutex_t`.
- **Que muestra:** Como proteger un recurso compartido (como un contador) para que solo un hilo pueda modificarlo a la vez.
- **Como ejecutar:**
  ```bash
  gcc mutex_example.c -o mutex_example -pthread
  ./mutex_example
  ```
- **Ver:** [`mutex/README.md`](mutex/README.md) para detalles y salida esperada.

---

### 2. `peterson/` - Algoritmo de Peterson

- **Proposito:** Muestra una solucion solo de software para exclusion mutua entre dos hilos (sin primitivas de hardware).
- **Archivos:**
  - `petersons_solution_i.c` – Thread i's code.
  - `petersons_solution_j.c` – Thread j's code.
- **Como ejecutar:** Compila y ejecuta cada archivo por separado.
- **Ver:** [`peterson/README.md`](peterson/README.md) para explicacion y uso.

---

### 3. `producer-consumer/` - Problema Productor-Consumidor

- **Proposito:** Ejemplo clasico de sincronizacion entre hilos productor y consumidor usando mutexes y variables de condicion.
- **Archivos:**
  - `producer_consumer_example.c` – Basic version.
  - `producer_consumer_example_verbose.c` – With detailed print statements for tracing.
- **Como ejecutar:**
  ```bash
  gcc producer_consumer_example.c -o producer_consumer_example -lpthread
  ./producer_consumer_example
  ```
- **Ver:** [`producer-consumer/README.md`](producer-consumer/README.md) para explicacion paso a paso y salida de ejemplo.

---

## 📝 Notas

- Todos los ejemplos usan hilos POSIX (`pthread`).
- Asegurate de compilar con la opcion `-pthread` o `-lpthread`.
- Cada subcarpeta contiene un README con mas detalles, explicaciones y salidas esperadas.

---

## 🚀 Primeros Pasos

1. Elige una carpeta de ejemplo.
2. Lee su `README.md` para contexto.
3. Compila el/los archivo(s) `.c` usando GCC y la opcion de hilos.
4. Ejecuta el binario resultante para observar la sincronizacion de hilos en accion.

---

Feliz programacion! 🧵
