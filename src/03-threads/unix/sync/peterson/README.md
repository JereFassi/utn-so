> 🇪🇸 [Leer en español](README.es.md)

# 🧩 Ejemplo del Algoritmo de Peterson

Esta carpeta contiene una implementacion en C del **algoritmo de Peterson**, una solucion clasica basada solo en software para lograr exclusion mutua entre dos hilos o procesos concurrentes.

---

## 📄 Archivos

- `petersons_solution_i.c` - Codigo para el proceso/hilo **i**.
- `petersons_solution_j.c` - Codigo para el proceso/hilo **j**.

---

## 📝 Que es el Algoritmo de Peterson?

El algoritmo de Peterson es una tecnica de sincronizacion que permite que dos procesos compartan un recurso de uso exclusivo sin conflictos, utilizando solo memoria compartida para la comunicacion. Garantiza:

- **Exclusion mutua:** Solo un proceso puede entrar a la seccion critica a la vez.
- **Progreso:** Si ningun proceso esta en la seccion critica, uno de los procesos en espera podra entrar.
- **Espera acotada:** Cada proceso eventualmente tendra su turno.

No requiere instrucciones especiales de hardware, solo variables compartidas.

---

## 🛠️ Como Usar

1. **Compila** cualquiera de los archivos (son estructuralmente similares, solo cambia el rol):

   ```bash
   gcc petersons_solution_i.c -o peterson_i
   gcc petersons_solution_j.c -o peterson_j
   ```

2. **Ejecuta** el/los programa(s) compilado(s):

   ```bash
   ./peterson_i
   # or
   ./peterson_j
   ```

> **Nota:** Estos archivos estan disenados con fines educativos y muestran la logica del algoritmo. Para ver la exclusion mutua en accion, normalmente se integran ambos roles en un solo programa y se ejecutan como hilos o procesos separados, compartiendo las variables `flag` y `turn`.

---

## 📚 Referencias

- [Algoritmo de Peterson - Wikipedia](https://es.wikipedia.org/wiki/Algoritmo_de_Peterson)
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
    // Seccion critica
    flag[i] = false;
    // Seccion restante
  }
}
```

---

Feliz aprendizaje!
