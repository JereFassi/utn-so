> 🇪🇸 [Leer en español](README.es.md)

# Programa de Copia de Archivos en C

Este programa demuestra como copiar el contenido de un archivo a otro usando llamadas al sistema en C. Incluye manejo de errores para problemas comunes como acceso a archivos y errores de lectura/escritura.

---

## 📋 Como Funciona

1. **Argumentos de Linea de Comandos**  
   El programa espera dos argumentos:

   - `source_file`: El archivo que se desea copiar.
   - `destination_file`: El archivo donde se copiara el contenido.

   Ejemplo de uso:

   ```bash
   ./copy_file_example source.txt destination.txt
   ```

2. **Apertura de Archivos**

   - El archivo fuente se abre en modo solo lectura usando `open()`.
   - El archivo de destino se crea (o se sobrescribe si existe) usando `creat()` con permisos `0700` (lectura, escritura y ejecucion para el propietario).

3. **Copia de Datos**

   - Se usa un buffer de tamano `4096` bytes para leer bloques del archivo fuente y escribirlos en el archivo destino.
   - El programa usa un bucle para leer y escribir hasta alcanzar el final del archivo fuente.

4. **Manejo de Errores**

    - El programa verifica errores en cada paso:
       - Si no se puede abrir el archivo fuente, termina con un mensaje de error.
       - Si no se puede crear el archivo destino, termina con un mensaje de error.
       - Si falla una operacion de lectura o escritura, termina con un mensaje de error.

5. **Cierre de Archivos**

   - Tanto el archivo fuente como el destino se cierran al finalizar el proceso de copia.

6. **Mensaje de Exito**
   - Si el archivo se copia correctamente, se imprime un mensaje de exito.

---

## 🛠️ Desglose del Codigo

### Componentes Clave

1. **Buffer y Permisos**

   ```c
   #define BUF_SIZE 4096    /* Tamano del buffer para la copia */
   #define OUTPUT_MODE 0700 /* Permisos para el archivo de destino */
   ```

2. **Apertura de Archivos**

   ```c
   in_fd = open(argv[1], O_RDONLY);
   if (in_fd < 0) {
       printf("Error: cannot open source file '%s'\n", argv[1]);
       exit(2);
   }

   out_fd = creat(argv[2], OUTPUT_MODE);
   if (out_fd < 0) {
       printf("Error: cannot create destination file '%s'\n", argv[2]);
       close(in_fd);
       exit(3);
   }
   ```

3. **Bucle de Copia**

   ```c
   while (1) {
       rd_count = read(in_fd, buffer, BUF_SIZE);
       if (rd_count < 0) {
           printf("Error: reading from source file\n");
           close(in_fd);
           close(out_fd);
           exit(5);
       }
       if (rd_count == 0) {
           break; /* Fin de archivo alcanzado */
       }
       wt_count = write(out_fd, buffer, rd_count);
       if (wt_count < 0 || wt_count != rd_count) {
           printf("Error: writing to destination file\n");
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
   printf("File copied successfully.\n");
   ```

---

## 🚀 Como Compilar y Ejecutar

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
File copied successfully.
```

### Error: Archivo Fuente No Encontrado

```bash
$ ./copy_file_example nonexistent.txt destination.txt
Error: cannot open source file 'nonexistent.txt'
```

### Error: No se Puede Crear el Archivo de Destino

```bash
$ ./copy_file_example source.txt /protected/destination.txt
Error: cannot create destination file '/protected/destination.txt'
```

---

## 🔍 Notas

- El programa sobrescribe el archivo de destino si ya existe.
- El tamano del buffer (`BUF_SIZE`) se puede ajustar para optimizar rendimiento.
- Asegurate de tener los permisos necesarios para leer el archivo fuente y escribir en el archivo de destino.
