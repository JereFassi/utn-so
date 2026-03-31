# Ejemplos de Comunicacion con Sockets en Python

Este proyecto demuestra comunicacion cliente-servidor usando programacion de sockets en Python. Incluye implementaciones basicas y mejoradas para mostrar como establecer conexiones TCP e intercambiar mensajes entre clientes y servidores.

## Estructura del Proyecto

### Implementacion Basica

- **`server.py`**: Servidor TCP basico que:

  - Escucha en localhost (127.0.0.1:65432)
  - Acepta una conexion de cliente
  - Recibe un unico mensaje
  - Responde con un acuse de recibo
  - Cierra la conexion

- **`client.py`**: Cliente TCP basico que:
  - Se conecta al servidor
  - Envia un mensaje predefinido
  - Recibe y muestra la respuesta del servidor
  - Cierra la conexion

### Implementacion Mejorada (v2)

- **`server.v2.py`**: Servidor mejorado con:

  - Reutilizacion de direccion de socket (`SO_REUSEADDR`)
  - Manejo continuo de mensajes
  - Finalizacion de conexion ordenada con 'bye'
  - Mejor manejo de errores y logging

- **`client.v2.py`**: Cliente interactivo con:
  - Entrada de mensajes por usuario
  - Comunicacion continua
  - Multiples comandos de salida ('quit', 'exit', 'bye')
  - Mejor manejo de errores
  - Manejo de seniales (Ctrl+C, Ctrl+D)

## Requisitos

- Python 3.6 o superior
- No requiere dependencias externas (usa solo la biblioteca estandar)

## Ejecucion de los Ejemplos

### Version Basica

1. Inicia el servidor:

   ```bash
   python server.py
   ```

2. En una terminal nueva, ejecuta el cliente:
   ```bash
   python client.py
   ```

### Version Mejorada (v2)

1. Inicia el servidor mejorado:

   ```bash
   python server.v2.py
   ```

2. En una terminal nueva, inicia el cliente interactivo:

   ```bash
   python client.v2.py
   ```

3. **Comandos Interactivos:**
   - Escribe cualquier mensaje y presiona Enter para enviarlo
   - Usa estos comandos para salir:
     - `bye` - cierre ordenado (notifica al servidor)
     - `quit` o `exit` - cierre local del cliente
     - `Ctrl+C` - salida forzada
   - `Ctrl+D` - cerrar flujo de entrada (sistemas tipo Unix)

## Protocolo de Comunicacion

- **Conexion**: TCP en localhost (127.0.0.1:65432)
- **Formato de Mensajes**: cadenas codificadas en UTF-8
- **Tamano de Buffer**: 1024 bytes
- **Senal de Finalizacion**: mensaje 'bye' o cierre de conexion

## Manejo de Errores

- Conexion rechazada
- Desconexiones inesperadas
- Errores de entrada/salida
- Interrupciones de teclado
- Condiciones EOF

## Notas

- Se recomienda la implementacion v2 para aprendizaje y pruebas
- Ambas versiones de servidor atienden un cliente a la vez
- El servidor libera automaticamente la direccion del socket para reinicios rapidos
- Los mensajes se devuelven con el prefijo "Server received: "

## Mejoras Futuras

- Soporte para multiples clientes usando threads
- Protocolos de mensajes personalizados
- Cifrado de datos
- Manejo de timeout de conexion
- Validacion del tamano de mensajes
