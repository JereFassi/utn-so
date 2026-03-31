## Explicacion del Ejemplo de Memoria Compartida

Este ejemplo demuestra la gestion de memoria compartida en C usando objetos de memoria compartida POSIX:

### Componentes Clave

1. **Creacion de Memoria Compartida**
   ```c
   shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
   if (ftruncate(shm_fd, SHM_SIZE) == -1) {
       perror("ftruncate");
       exit(1);
   }
   ```
   Crea y configura un segmento de memoria compartida con:
   - `shm_open()`: Crea/abre un objeto de memoria compartida
   - `ftruncate()`: Define el tamano del segmento de memoria compartida

2. **Mapeo de Memoria**
   ```c
   shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
   ```
   Mapea el segmento de memoria compartida en el espacio de direcciones del proceso con:
   - `PROT_READ | PROT_WRITE`: Permisos de lectura y escritura
   - `MAP_SHARED`: Los cambios son visibles para otros procesos

3. **Limpieza de Memoria**
   ```c
   munmap(shm_ptr, SHM_SIZE);
   shm_unlink(SHM_NAME);
   ```
   Limpieza correcta de los recursos de memoria compartida:
   - `munmap()`: Desmapea el segmento de memoria
   - `shm_unlink()`: Elimina el objeto de memoria compartida

### Compilacion y Ejecucion
```bash
# Compilar el ejemplo (nota la bandera -lrt para extensiones POSIX de tiempo real)
gcc src/04-memoria/shared_memory.c -o shared_memory -lrt

# Ejecutar el programa
./shared_memory
```

### Salida Esperada
```
Written to shared memory: Hello from shared memory!
```

Nota: Este ejemplo requiere un sistema compatible con POSIX y soporte de memoria compartida.