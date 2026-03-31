## Explicacion del Ejemplo de Lectura de Entrada

Este ejemplo demuestra operaciones basicas de entrada/salida en C:

### Componentes Clave

1. **Declaracion del Buffer de Entrada**
   ```c
   char input[100];
   ```
   Crea un buffer de tamano fijo para almacenar la entrada del usuario (maximo 100 caracteres).

2. **Lectura de la Entrada del Usuario**
   ```c
   fgets(input, sizeof(input), stdin);
   ```
   Lee de forma segura una linea de texto desde la entrada estandar, evitando desbordamientos de buffer.

3. **Mostrar la Salida**
   ```c
   printf("You entered: %s", input);
   ```
   Imprime en consola la entrada ingresada por el usuario.

### Compilacion y Ejecucion
```bash
# Compilar el ejemplo
gcc src/01-introduccion/read_input_example.c -o read_input_example

# Ejecutar el programa
./read_input_example
```

---

## Explicacion del Ejemplo de Lectura de Archivo

Este ejemplo demuestra operaciones de manejo de archivos en C usando la biblioteca estandar de E/S:

### Componentes Clave

1. **Declaracion del Buffer**
   ```c
   #define BUFFER_SIZE 1024
   char buffer[BUFFER_SIZE];
   ```
   Crea un buffer de tamano fijo para almacenar el contenido del archivo durante la lectura.

2. **Apertura del Archivo**
   ```c
   FILE *file;
   file = fopen("src/01-introduccion/tuc.txt", "r");
   ```
   Abre el archivo en modo lectura y verifica errores:
   - Devuelve NULL si no se puede abrir el archivo
   - La bandera "r" indica modo de solo lectura

3. **Lectura del Archivo**
   ```c
   while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
       printf("%s", buffer);
   }
   ```
   Lee el archivo linea por linea hasta llegar a EOF:
   - `fgets`: Lee hasta BUFFER_SIZE-1 caracteres o hasta un salto de linea
   - Maneja automaticamente los finales de linea
   - El retorno NULL indica EOF o error

4. **Cierre del Archivo**
   ```c
   if (fclose(file) != 0) {
       perror("Error closing file");
       return 1;
   }
   ```
   Cierra correctamente el archivo y maneja posibles errores.

### Compilacion y Ejecucion
```bash
# Compilar el ejemplo
gcc src/01-introduccion/read_file_example.c -o read_file_example

# Ejecutar el programa
./read_file_example
```

### Diferencias Clave entre fgets y read
- `fgets` es una funcion con buffering de la biblioteca C, `read` es una llamada al sistema
- `fgets` es parte del estandar C, `read` es especifica de POSIX
- `fgets` trabaja con punteros FILE, `read` usa descriptores de archivo
- `fgets` lee hasta salto de linea, `read` lee una cantidad exacta de bytes