# Que es un Thread?

Un **thread** (hilo) es la unidad mas pequena de ejecucion dentro de un proceso. El termino "thread" viene de la analogia de un "hilo de ejecucion", que representa un camino unico y continuo a traves de las instrucciones de un programa.

## Por que se llaman Threads?

Se llaman "threads" porque actuan como hebras individuales que recorren la estructura de un proceso. Asi como varios hilos se entrelazan para formar una tela, varios hilos de ejecucion pueden correr concurrentemente dentro de un mismo proceso. Cada hilo sigue su propia secuencia de instrucciones, pero comparte los mismos recursos (como memoria) con los otros hilos del proceso.

## Puntos Clave

- **Hilo Unico:** Un programa con un solo hilo ejecuta instrucciones una tras otra en una unica secuencia.
- **Multihilo:** Un programa puede tener multiples hilos, permitiendo que distintas partes se ejecuten al mismo tiempo.
- **Comparticion de Recursos:** Los hilos dentro del mismo proceso comparten memoria y recursos, lo que hace eficiente la comunicacion entre ellos.
- **Casos de Uso:** Los hilos se usan comunmente en tareas concurrentes, como atender multiples conexiones de clientes en un servidor o realizar calculos en segundo plano mientras se mantiene responsiva una interfaz de usuario.

## Analogia

> Imagina un proceso como una pieza de tela. Cada thread es como una hebra individual que la atraviesa. Juntas, estas hebras forman la estructura completa, pero cada una puede avanzar de forma independiente dentro del entramado.

## Lectura Recomendada

- [Wikipedia: Thread (computing)](<https://en.wikipedia.org/wiki/Thread_(computing)>)
- [Operating System Concepts - Silberschatz, Galvin, Gagne]
