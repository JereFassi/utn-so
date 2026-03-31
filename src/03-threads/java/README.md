# Configuracion de Java para Ejemplos de Threads

Este directorio contiene ejemplos en Java relacionados con la creacion y gestion de hilos.

## Como Instalar Java en Ubuntu

Para compilar y ejecutar programas Java, necesitas tener instalado el Java Development Kit (JDK). En Ubuntu, puedes instalar OpenJDK facilmente con el siguiente comando:

```bash
sudo apt install openjdk-21-jdk
```

Este comando instala OpenJDK version 21, que incluye tanto el Java Runtime Environment (JRE) como el compilador de Java (`javac`).

### Verificar la Instalacion

Despues de la instalacion, puedes verificar que Java quedo correctamente instalado ejecutando:

```bash
java -version
javac -version
```

Ambos comandos deberian mostrar informacion de version de Java 21.

---

## Como Compilar y Ejecutar `Driver.java`

1. **Navega al directorio:**

   ```bash
   cd src/03-threads/java
   ```

2. **Compila el archivo Java:**

   ```bash
   javac Driver.java
   ```

   Esto generara `Driver.class` y posiblemente `Summation.class`.

3. **Ejecuta el programa:**

   ```bash
   java Driver 10
   ```

   Reemplaza `10` por cualquier entero para calcular la suma de 1 hasta ese numero.

---

Continua con los ejemplos de esta carpeta para aprender sobre threads en Java.
