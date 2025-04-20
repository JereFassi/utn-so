# What is a Thread?

A **thread** is the smallest unit of execution within a process. The term "thread" comes from the analogy of a "thread of execution," representing a single, continuous path through a program's instructions.

## Why Are They Called Threads?

Threads are called "threads" because they act like individual strands running through the fabric of a process. Just as multiple threads are woven together to create fabric, multiple threads of execution can run concurrently within a single process. Each thread follows its own sequence of instructions but shares the same resources (such as memory) with other threads in the same process.

## Key Points

- **Single Thread:** A program with one thread executes instructions one after another in a single sequence.
- **Multi-threading:** A program can have multiple threads, allowing different parts of the program to run at the same time.
- **Resource Sharing:** Threads within the same process share memory and resources, making communication between them efficient.
- **Use Cases:** Threads are commonly used for tasks that can be performed concurrently, such as handling multiple client connections in a server or performing background computations while keeping a user interface responsive.

## Analogy

> Imagine a process as a piece of fabric. Each thread is like a single strand running through the fabric. Together, these threads form the complete structure, but each one can move independently through the weave.

## Further Reading

- [Wikipedia: Thread (computing)](<https://en.wikipedia.org/wiki/Thread_(computing)>)
- [Operating System Concepts – Silberschatz, Galvin, Gagne]
