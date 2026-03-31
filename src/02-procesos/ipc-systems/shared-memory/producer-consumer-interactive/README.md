## Explicacion del Ejemplo Productor-Consumidor

Este ejemplo demuestra comunicacion entre procesos usando memoria compartida tanto en Windows como en sistemas UNIX:

### Componentes Clave

1. **Estructura de Memoria Compartida**
   ```c
   typedef struct {
     int count;          // Number of items in buffer
     char buffer[BUFFER_SIZE];  // Shared buffer
   } shared_memory_t;
   ```
   Define la estructura compartida entre procesos:
   - `count`: Controla la sincronizacion
   - `buffer`: Almacena los datos compartidos

2. **Implementacion en Windows**
   ```c
   // Create shared memory
   hMapFile = CreateFileMapping(
     INVALID_HANDLE_VALUE,    // Use paging file
     NULL,                    // Default security
     PAGE_READWRITE,         // Read/write access
     0,                      // Maximum object size
     sizeof(shared_memory_t), // Size of shared memory
     SHARED_MEM_NAME);       // Name of mapping object
   ```
   Usa la API de Windows para memoria compartida:
   - `CreateFileMapping`: Crea el segmento de memoria compartida
   - `MapViewOfFile`: Mapea la memoria en el espacio del proceso
   - `UnmapViewOfFile`: Libera la memoria mapeada

3. **Implementacion en UNIX**
   ```c
   // Create shared memory
   shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
   ftruncate(shm_fd, sizeof(shared_memory_t));
   shared_mem = mmap(NULL, sizeof(shared_memory_t), 
                    PROT_READ | PROT_WRITE, MAP_SHARED, 
                    shm_fd, 0);
   ```
   Usa memoria compartida POSIX:
   - `shm_open`: Crea un objeto de memoria compartida
   - `mmap`: Mapea la memoria en el espacio del proceso
   - `munmap`: Desmapea la memoria compartida

### Compilacion y Ejecucion

Para Windows:
```bash
# Compilar productor y consumidor
gcc windows-producer.c -o windows-producer.exe
gcc windows-consumer.c -o windows-consumer.exe

# Ejecutar en ventanas separadas de Command Prompt
./windows-consumer.exe
./windows-producer.exe
```

Para UNIX:
```bash
# Compilar productor y consumidor
gcc unix-producer.c -o unix-producer -lrt
gcc unix-consumer.c -o unix-consumer -lrt

# Ejecutar en terminales separadas
./unix-consumer
./unix-producer
```

### Ejemplo de Uso
```
# En la ventana del consumidor:
Consumer ready. Waiting for messages...

# En la ventana del productor:
Producer ready. Enter messages (Ctrl+Z/D to exit):
Hello World!
Produced: Hello World!
```

### Notas
- La version Windows usa API de Windows (`CreateFileMapping`, `MapViewOfFile`)
- La version UNIX usa memoria compartida POSIX (`shm_open`, `mmap`)
- El productor escribe mensajes en el buffer compartido
- El consumidor verifica continuamente y muestra mensajes nuevos
- Sincronizacion basica usando la variable `count`