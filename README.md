# UTN-SO

<div align="center">

![UTN Logo](https://www.frbb.utn.edu.ar/frbb/wp-content/uploads/2025/01/logo_2025_sintexto.png)

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

## ⚙️ Requisitos Previos
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
- [Nano](https://www.nano-editor.org/) (incluido, para entornos sin interfaz gráfica)

  ```bash
  # Instalar Git en Ubuntu
  sudo apt install nano
  nano --version  # Verificar la instalación
  ```
- [Visual Studio Code](https://code.visualstudio.com/) (opcional, para entornos gráficos)

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
3. **Memoria**: Ejemplos de gestión de memoria

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
- **Autor**: Jeremías Fassi
- **Email**: jeremiasfassi@gmail.com
- **GitHub**: [@JereFassi](https://github.com/JereFassi)
- **LinkedIn**: [Jeremias Fassi](https://linkedin.com/in/jeremias-fassi)

## 🔍 Referencias y Enlaces Útiles
- [Documentación oficial de Linux](https://www.kernel.org/doc/)
- [Manual de POSIX Threads](https://computing.llnl.gov/tutorials/pthreads/)

---
<div align="center">
Desarrollado con ❤️ para UTN-TUP
</div>