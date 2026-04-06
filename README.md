<div align="center">

# UTN-TUP - Arquitectura y Sistemas Operativos

</div>

<div align="center">

[![UTN Logo](https://www.frbb.utn.edu.ar/frbb/wp-content/uploads/2025/01/logo_2025_sintexto.png)](https://www.frbb.utn.edu.ar/frbb/sacad/carreras/tup/)

![GitHub last commit](https://img.shields.io/github/last-commit/JereFassi/utn-so)
![License](https://img.shields.io/github/license/JereFassi/utn-so)

</div>

## 📝 Descripción

Este repositorio contiene ejemplos prácticos relacionados con sistemas operativos. Está diseñado para ayudar a los estudiantes a comprender conceptos clave mediante ejercicios y código de ejemplo.

## 📚 Contenido

- **Ejercicios prácticos**: Código y ejemplos para aprender conceptos de sistemas operativos.
- **Documentación**: Explicaciones detalladas de cada ejemplo y su propósito.
- **Recursos adicionales**: Enlaces y materiales complementarios.

## 🗂️ Estructura del Proyecto

```
utn-so/
├── docs/                     # Documentación
├── src/                      # Ejercicios prácticos
│   ├── 01-introduccion/      # Ejemplos de introduccion
│   ├── 02-procesos/          # Ejemplos de procesos
│   ├── 03-threads/           # Ejemplos de hilos
│   └── 04-memoria/           # Gestión de memoria
├── recursos/                 # Recursos adicionales
└── README.md
```

## 🐧 Tutorial rápido: instalar WSL con Ubuntu en Windows

Si usas Windows pero quieres trabajar con un entorno Linux, puedes instalar **WSL (Windows Subsystem for Linux)** y usar **Ubuntu** dentro de Windows.

1. **Abrir PowerShell como administrador**  
   Busca `PowerShell` en el menú Inicio, haz clic derecho y selecciona **"Ejecutar como administrador"**.

2. **Instalar WSL y Ubuntu**  
   Ejecuta este comando:

   ```powershell
   wsl --install
   ```

   Esto habilita WSL e instala Ubuntu por defecto.

3. **Reiniciar la computadora**  
   Si Windows lo solicita, reinicia para completar la instalación.

4. **Abrir Ubuntu por primera vez**  
   Desde el menú Inicio, abre `Ubuntu`. La primera vez te pedirá crear:
   - un nombre de usuario
   - una contraseña

5. **Verificar que Ubuntu quedó instalada**  
   Puedes comprobarlo con:

   ```powershell
   wsl -l -v
   ```

   Deberías ver `Ubuntu` en la lista.

6. **Entrar a Ubuntu**  
   Luego puedes abrir Ubuntu desde el menú Inicio o ejecutando:

   ```powershell
   wsl
   ```

7. **Actualizar paquetes dentro de Ubuntu**  
   Ya dentro de Ubuntu, conviene ejecutar:

   ```bash
   sudo apt update
   sudo apt upgrade
   ```

8. **Clonar este repositorio desde Ubuntu**  
   Una vez dentro de la terminal de Ubuntu:

   ```bash
   git clone https://github.com/JereFassi/utn-so.git
   cd utn-so
   ```

Documentación oficial:
- [Instalar WSL](https://learn.microsoft.com/en-us/windows/wsl/install)
- [Usar VS Code con WSL](https://learn.microsoft.com/en-us/windows/wsl/tutorials/wsl-vscode)

## ⚙️ Requisitos Previos - Ubuntu

Para ejecutar los ejemplos, asegúrate de tener instalado:

- Sistema operativo compatible (Linux - Ubuntu recomendado).

  ```bash
  # Actualiza el administrador de paquetes de Ubuntu
  sudo apt update
  ```

- [GCC](https://gcc.gnu.org/) o cualquier compilador compatible

  ```bash
  # Instalar GCC en Ubuntu
  sudo apt install build-essential
  gcc --version  # Verificar la instalación
  ```

- [Git](https://git-scm.com/) para clonar el repositorio

  ```bash
  # Instalar Git en Ubuntu
  sudo apt install git
  git --version  # Verificar la instalación
  ```

- [Nano](https://www.nano-editor.org/) (opcional para entornos sin interfaz gráfica)

  ```bash
  # Instalar Git en Ubuntu
  sudo apt install nano
  nano --version  # Verificar la instalación
  ```

- [Visual Studio Code](https://code.visualstudio.com/) (opcional para entornos gráficos)

## ⚙️ Requisitos Previos - Windows

Para configurar el entorno de desarrollo en Windows, sigue estos pasos:

1. **Instalar Visual Studio Code**  
   [Guía oficial de configuración para C/C++ en VS Code](https://code.visualstudio.com/docs/cpp/config-mingw)

2. **Instalar MSYS2**  
   Descarga e instala MSYS2 desde su sitio oficial:  
   [https://www.msys2.org/](https://www.msys2.org/)

3. **Configurar GCC**  
   Una vez instalado MSYS2, abre el terminal de MSYS2 y ejecuta los siguientes comandos para instalar el compilador GCC:

   ```bash
   # Actualiza los paquetes de MSYS2
   pacman -Syu

   # Instala el compilador GCC y herramientas necesarias
   pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain

   ```

4. **Agregar GCC al PATH**  
   Agrega el directorio `bin` de MSYS2 al PATH de tu sistema para que GCC esté disponible globalmente. Sigue estos pasos:

   1. Abre el menú de inicio y busca **"Editar las variables de entorno del sistema"**.
   2. En la ventana de **Propiedades del sistema**, haz clic en el botón **"Variables de entorno"**.
   3. En la sección **Variables del sistema**, selecciona la variable `Path` y haz clic en **Editar**.
   4. Haz clic en **Nuevo** y agrega la ruta al directorio `bin` de MSYS2. Por ejemplo:
      ```
      C:\msys64\mingw64\bin
      ```
      El path que me funcionó a mí fue:
      ```
      C:\msys64\ucrt64\bin
      ```
   5. Guarda los cambios y cierra todas las ventanas.

5. **Verificar la instalación**  
   Abre una terminal y ejecuta el siguiente comando para verificar que GCC está instalado correctamente:
   ```bash
   gcc --version
   ```

## 🚀 Instalación y Uso

1. Clona este repositorio:

   ```bash
   git clone https://github.com/JereFassi/utn-so.git
   cd utn-so
   ```

2. Compila un ejemplo:

   ```bash
   gcc src/ejemplo.c -o ejemplo
   ```

3. Ejecuta el programa:
   ```bash
   ./ejemplo
   ```

## 💡 Guía de Ejercicios

1. **Procesos**: Ejemplos básicos de creación y comunicación entre procesos
2. **Threads**: Ejemplos de programación multihilo
3. **Memoria**: Ejemplos de gestión de memoria (incuidos en procesos)

## 🤝 Cómo Contribuir

1. Fork del repositorio
2. Crea una nueva rama (`git checkout -b feature/nueva-funcionalidad`)
3. Realiza tus cambios
4. Commit (`git commit -m 'Añadir nueva funcionalidad'`)
5. Push (`git push origin feature/nueva-funcionalidad`)
6. Abre un Pull Request

## 📄 Licencia

Este proyecto está bajo la licencia MIT. Ver el archivo [LICENSE](LICENSE) para más detalles.

## ✉️ Contacto

### Autores

| Nombre           | GitHub                                     | LinkedIn                                           | Email                   |
| ---------------- | ------------------------------------------ | -------------------------------------------------- | ----------------------- |
| Jeremías Fassi   | [@JereFassi](https://github.com/JereFassi) | [LinkedIn](https://linkedin.com/in/jeremias-fassi) | jeremiasfassi@gmail.com |
| Javier E. Kinter | [@JEKinter](https://github.com/JEKinter)   | -                                                  | javierekinter@gmail.com |

O contáctanos por [Issues](https://github.com/JereFassi/utn-so/issues) de GitHub.

## 🔍 Referencias y Enlaces Útiles

- [Documentación oficial de Linux](https://www.kernel.org/doc/)
- [Manual de POSIX Threads](https://computing.llnl.gov/tutorials/pthreads/)

---

<div align="center">
Con ❤️ para UTN-TUP
</div>
