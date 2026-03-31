## Ejemplo de Comunicacion con Pipe

Este ejemplo demuestra comunicacion entre procesos usando pipes en sistemas UNIX:

### Componentes Clave

1. **Creacion del Pipe**
   ```c
   int fd[2];
   if (pipe(fd) == -1) {
       fprintf(stderr,"Pipe failed");
       return 1;
   }
   ```
   Crea un pipe con dos descriptores de archivo:
   - `fd[0]`: Extremo de lectura del pipe
   - `fd[1]`: Extremo de escritura del pipe

2. **Creacion del Proceso**
   ```c
   pid_t pid = fork();
   ```
   Crea un proceso hijo que hereda los descriptores del pipe.

3. **Proceso Padre (Escritor)**
   ```c
   if (pid > 0) {
       close(fd[READ_END]);
       write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
       close(fd[WRITE_END]);
   }
   ```
   - Cierra el extremo de lectura no usado
   - Escribe un mensaje en el pipe
   - Cierra el extremo de escritura al finalizar

4. **Proceso Hijo (Lector)**
   ```c
   else {
       close(fd[WRITE_END]);
       read(fd[READ_END], read_msg, BUFFER_SIZE);
       printf("read %s", read_msg);
       close(fd[READ_END]);
   }
   ```
   - Cierra el extremo de escritura no usado
   - Lee el mensaje desde el pipe
   - Muestra el mensaje recibido

### Compilacion y Ejecucion
```bash
# Compilar el ejemplo
gcc pipe_example.c -o pipe_example

# Ejecutar el programa
./pipe_example
```

### Salida Esperada
```
read Greetings!
```

### Notas
- Solo funciona en sistemas tipo UNIX (Linux, macOS)
- Demuestra comunicacion unidireccional
- El padre duerme para asegurar sincronizacion basica
- Limpieza adecuada cerrando extremos no usados del pipe
- Usa llamadas al sistema: `pipe()`, `fork()`, `read()`, `write()`

### Conceptos Importantes
1. Los pipes son unidireccionales
2. Los datos fluyen del extremo de escritura al de lectura
3. Los extremos no usados deben cerrarse
4. El pipe provee comunicacion sincronizada
5. El pipe existe solo mientras los procesos estan en ejecucion