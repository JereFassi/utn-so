# 🧵 pthread_menu_example.c

Este ejemplo muestra cómo utilizar **hilos (threads)** en C con la biblioteca `pthread` para crear un menú interactivo donde un hilo se encarga de leer la opción del usuario y otro ejecuta la acción correspondiente.

## 📋 Descripción

El programa crea dos hilos:

- **Hilo de entrada (input_thread):**  
  Muestra un menú simple, lee la opción del usuario y la comunica al hilo de acción usando variables compartidas y sincronización con mutex y condición.

- **Hilo de acción (action_thread):**  
  Espera a que el usuario ingrese una opción y ejecuta la acción asociada (por ahora, solo imprime un mensaje). Si el usuario elige "q", ambos hilos terminan.

## 🧩 Estructura del código

- **Variables globales:**

  - `volatile int running`: Controla si el programa sigue ejecutándose.
  - `char user_choice[MAX_CHOICE_LEN]`: Almacena la opción elegida por el usuario.
  - `pthread_mutex_t choice_mutex` y `pthread_cond_t choice_cond`: Sincronización entre hilos.

- **input_thread:**

  - Muestra el menú y lee la entrada del usuario.
  - Usa un mutex para proteger la variable compartida y una condición para notificar al hilo de acción.
  - Si el usuario ingresa "q", termina el programa.

- **action_thread:**
  - Espera la señal de que hay una nueva opción.
  - Ejecuta la acción correspondiente según la opción ingresada.
  - Si la opción es "q", imprime un mensaje y termina.

## 🚀 Compilación y ejecución

Compila el programa con:

```bash
gcc -o pthread_menu_example pthread_menu_example.c -lpthread
```

Ejecuta el programa:

```bash
./pthread_menu_example
```

## 📝 Ejemplo de uso

```
=== Menú ===
1. Acción 1
2. Acción 2
q. Salir
Elige una opción: 1
Ejecutando Acción 1...

=== Menú ===
1. Acción 1
2. Acción 2
q. Salir
Elige una opción: q
Saliendo...
```

## 💡 Notas

- Puedes agregar nuevas acciones modificando la función `action_thread`.
- Este ejemplo es una base para implementar menús interactivos multihilo en C.

---
