> 🇬🇧 [Read in English](README.md)

# 🧩 Ejemplo del Algoritmo de Peterson

Esta carpeta contiene una implementación en C del **algoritmo de Peterson**, una solución clásica basada solo en software para lograr exclusión mutua entre dos hilos o procesos concurrentes.

---

## 📄 Archivos

- `petersons_solution_i.c` – Código para el proceso/hilo **i**.
- `petersons_solution_j.c` – Código para el proceso/hilo **j**.

---

## 📝 ¿Qué es el Algoritmo de Peterson?

El algoritmo de Peterson es una técnica de sincronización que permite que dos procesos compartan un recurso de uso exclusivo sin conflictos, utilizando solo memoria compartida para la comunicación. Garantiza:

- **Exclusión mutua:** Solo un proceso puede entrar a la sección crítica a la vez.
- **Progreso:** Si ningún proceso está en la sección crítica, uno de los procesos en espera podrá entrar.
- **Espera acotada:** Cada proceso eventualmente tendrá su turno.

No requiere instrucciones especiales de hardware, solo variables compartidas.

---

## 🛠️ Cómo Usar

1. **Compila** cualquiera de los archivos (son estructuralmente similares, solo cambia el rol):

   ```bash
   gcc petersons_solution_i.c -o peterson_i
   gcc petersons_solution_j.c -o peterson_j
   ```

2. **Ejecuta** el programa compilado:

   ```bash
   ./peterson_i
   # o
   ./peterson_j
   ```

> **Nota:** Estos archivos están diseñados con fines educativos y muestran la lógica del algoritmo. Para ver la exclusión mutua en acción, normalmente se integrarían ambos roles en un solo programa y se ejecutarían como hilos o procesos separados, compartiendo las variables `flag` y `turn`.

---

## 📚 Referencias

- [Algoritmo de Peterson – Wikipedia](https://es.wikipedia.org/wiki/Algoritmo_de_Peterson)
- Libros de Sistemas Operativos (por ejemplo, Silberschatz, Galvin, Gagne)

---

## 💡 Estructura de Ejemplo

```c
volatile bool flag[2] = {false, false};
volatile int turn;

void process(int i) {
  int j = 1 - i;
  while (true) {
    flag[i] = true;
    turn = j;
    while (flag[j] && turn == j) {
      // Espera ocupada
    }
    // Sección crítica
    flag[i] = false;
    // Sección restante
  }
}
```

---

¡Feliz aprendizaje!
