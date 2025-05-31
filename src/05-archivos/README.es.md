> 🇬🇧 [Read in English](README.md)

# Programa de Copia de Archivos en C

Este programa demuestra cómo copiar el contenido de un archivo a otro utilizando llamadas al sistema en C. Incluye manejo de errores para problemas comunes, como acceso a archivos y errores de lectura/escritura.

---

## 📋 Cómo Funciona

1. **Argumentos de Línea de Comandos**  
   El programa espera dos argumentos:

   - `source_file`: El archivo que se desea copiar.
   - `destination_file`: El archivo donde se copiará el contenido.

   Ejemplo de uso:

   ```bash
   ./copy_file_example source.txt destination.txt
   ```

2. **Apertura de Archivos**

   - El archivo fuente se abre en modo de solo lectura utilizando `open()`.
   - El archivo de destino se crea (o se sobrescribe si ya existe) utilizando `creat()` con permisos `0700` (lectura, escritura y ejecución para el propietario).

3. **Copia de Datos**

   - Se utiliza un búfer de tamaño `4096` bytes para leer fragmentos de datos del archivo fuente y escribirlos en el archivo de destino.
   - El programa utiliza un bucle para leer y escribir hasta que se alcance el final del archivo fuente.

4. **Manejo de Errores**

   - El programa verifica errores en cada paso:
     - Si el archivo fuente no se puede abrir, muestra un mensaje de error y termina.
     - Si el archivo de destino no se puede crear, muestra un mensaje de error y termina.
     - Si ocurre un error durante la lectura o escritura, muestra un mensaje de error y termina.

5. **Cierre de Archivos**

   - Tanto el archivo fuente como el archivo de destino se cierran después de completar el proceso de copia.

6. **Mensaje de Éxito**
   - Si el archivo se copia correctamente, se imprime un mensaje de éxito.

---

## 🛠️ Desglose del Código

### Componentes Clave

1. **Búfer y Permisos**

   ```c
   #define BUF_SIZE 4096    /* Tamaño del búfer para la copia */
   #define OUTPUT_MODE 0700 /* Permisos para el archivo de destino */
   ```

2. **Apertura de Archivos**

   ```c
   in_fd = open(argv[1], O_RDONLY);
   if (in_fd < 0) {
       printf("Error: no se puede abrir el archivo fuente '%s'\n", argv[1]);
       exit(2);
   }

   out_fd = creat(argv[2], OUTPUT_MODE);
   if (out_fd < 0) {
       printf("Error: no se puede crear el archivo de destino '%s'\n", argv[2]);
       close(in_fd);
       exit(3);
   }
   ```

3. **Bucle de Copia**

   ```c
   while (1) {
       rd_count = read(in_fd, buffer, BUF_SIZE);
       if (rd_count < 0) {
           printf("Error: leyendo del archivo fuente\n");
           close(in_fd);
           close(out_fd);
           exit(5);
       }
       if (rd_count == 0) {
           break; /* Fin del archivo alcanzado */
       }
       wt_count = write(out_fd, buffer, rd_count);
       if (wt_count < 0 || wt_count != rd_count) {
           printf("Error: escribiendo en el archivo de destino\n");
           close(in_fd);
           close(out_fd);
           exit(4);
       }
   }
   ```

4. **Cierre de Archivos**
   ```c
   close(in_fd);
   close(out_fd);
   printf("Archivo copiado exitosamente.\n");
   ```

---

## 🚀 Cómo Compilar y Ejecutar

1. **Compilar el Programa**

   ```bash
   gcc copy_file_example.c -o copy_file_example
   ```

2. **Ejecutar el Programa**
   ```bash
   ./copy_file_example source.txt destination.txt
   ```

---

## 📝 Ejemplo de Salida

### Copia Exitosa

```bash
$ ./copy_file_example source.txt destination.txt
Archivo copiado exitosamente.
```

### Error: Archivo Fuente No Encontrado

```bash
$ ./copy_file_example nonexistent.txt destination.txt
Error: no se puede abrir el archivo fuente 'nonexistent.txt'
```

### Error: No Se Puede Crear el Archivo de Destino

```bash
$ ./copy_file_example source.txt /protected/destination.txt
Error: no se puede crear el archivo de destino '/protected/destination.txt'
```

---

## 🔍 Notas

- El programa sobrescribe el archivo de destino si ya existe.
- El tamaño del búfer (`BUF_SIZE`) se puede ajustar para optimizar el rendimiento.
- Asegúrate de tener los permisos necesarios para leer el archivo fuente y escribir en el archivo de destino.
