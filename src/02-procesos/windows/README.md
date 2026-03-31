## Ejemplo de Creacion de Procesos en Windows

### Instrucciones de Configuracion en Windows

1. **Instalar el Compilador GCC**

   - Instala MSYS2: https://www.msys2.org/
   - Sigue la configuracion de MinGW-w64: https://www.mingw-w64.org/getting-started/msys2/
   - O sigue la guia de VS Code: https://code.visualstudio.com/docs/cpp/config-mingw

2. **Configurar el Entorno**

   ```powershell
   # Agrega MinGW al PATH si no lo hiciste durante la instalacion
   # Suele estar ubicado en: C:\msys64\mingw64\bin
   ```

3. **Ruta de Instalacion de Paint - Windows 10**
   ```
   "C:\\Windows\\system32\\mspaint.exe"
   ```
4. **Buscar la Ruta de Instalacion de Paint - Windows 11**

   ```powershell
   # Ejecutar en PowerShell como administrador
   Get-AppxPackage -allusers Microsoft.Paint | Select-Object -Property Name, InstallLocation
   ```

   Salida de ejemplo:

   ```
   Name              : Microsoft.Paint_11.2502.161.0_x64__8wekyb3d8bbwe
   InstallLocation   : C:\Program Files\WindowsApps\Microsoft.Paint_11.2502.161.0_x64__8wekyb3d8bbwe
   ```

5. **Actualizar el Codigo Fuente**

   - Reemplaza la ruta de Paint en tu codigo con el `InstallLocation` obtenido arriba
   - Agrega `\PaintApp\mspaint.exe` al final de la ruta

6. **Compilar y Ejecutar**

   ```bash
   # Compilar
   gcc create_process_example.c -o create_process_example.exe

   # Ejecutar
   ./create_process_example.exe
   ```

Nota: La ruta de instalacion de Paint puede variar segun la version de Windows y el tipo de instalacion.

## Ejemplo de Creacion de Procesos

Este ejemplo demuestra como crear procesos hijo en Windows usando la API de Windows:

### Componentes Clave

1. **Estructuras de Informacion del Proceso**

   ```c
   STARTUPINFO si;
   PROCESS_INFORMATION pi;
   ZeroMemory(&si, sizeof(si));
   si.cb = sizeof(si);
   ```

   Inicializa las estructuras requeridas:

   - `STARTUPINFO`: Contiene configuraciones de ventana para el nuevo proceso
   - `PROCESS_INFORMATION`: Recibe informacion de identificacion
   - `ZeroMemory`: Limpia memoria para evitar comportamiento indefinido

2. **Creacion del Proceso**

   ```c
   CreateProcess(
       NULL,    // Sin nombre de modulo (usar linea de comandos)
       "path/to/mspaint.exe",  // Linea de comandos
       NULL,    // Handle de proceso no heredable
       NULL,    // Handle de hilo no heredable
       FALSE,   // Establecer herencia de handles en FALSE
       0,       // Sin banderas de creacion
       NULL,    // Usar bloque de entorno del padre
       NULL,    // Usar directorio inicial del padre
       &si,     // Puntero a la estructura STARTUPINFO
       &pi      // Puntero a la estructura PROCESS_INFORMATION
   );
   ```

   Crea un nuevo proceso y su hilo principal.

3. **Sincronizacion de Procesos**
   ```c
   WaitForSingleObject(pi.hProcess, INFINITE);
   printf("Child Complete");
   ```
   El proceso padre espera a que el hijo termine.

### Compilacion y Ejecucion

```bash
# Compilar el ejemplo basico
gcc create_process_example.c -o create_process_example.exe

# Ejecutar el programa
./create_process_example.exe
```

### Version Extendida con Argumentos

La segunda version (`create_process2_example.c`) agrega:

- Soporte de argumentos por linea de comandos
- Manejo de ruta de imagen por defecto
- Mejores mensajes de error

```bash
# Compilar el ejemplo extendido
gcc create_process2_example.c -o create_process2_example.exe

# Ejecutar con imagen por defecto
./create_process2_example.exe default

# Ejecutar con una imagen especifica
./create_process2_example.exe "C:\path\to\image.jpg"
```

### Notas

- Requiere sistema operativo Windows
- Usa la API de Windows (`windows.h`)
- Microsoft Paint debe estar instalado
- Recuerda liberar los handles despues de usarlos
- Verifica permisos del proceso si Paint no abre
