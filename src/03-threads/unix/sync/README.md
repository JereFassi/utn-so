> 🇪🇸 [Leer en español](README.es.md)

# 🔗 Thread Synchronization Examples (C)

This folder contains classic thread synchronization examples in C, demonstrating the use of mutexes, condition variables, and algorithms for mutual exclusion. Each subfolder includes source code and a README with explanations.

---

## 📁 Folder Structure

```
sync/
├── mutex/
│   ├── mutex_example.c
│   └── README.md
├── peterson/
│   ├── petersons_solution_i.c
│   ├── petersons_solution_j.c
│   └── README.md
└── producer-consumer/
    ├── producer_consumer_example.c
    ├── producer_consumer_example_verbose.c
    └── README.md
```

---

## 📚 Examples Overview

### 1. `mutex/` – Mutex Example

- **Purpose:** Demonstrates basic thread synchronization using a `pthread_mutex_t`.
- **What it shows:** How to protect a shared resource (like a counter) so only one thread can modify it at a time.
- **How to run:**
  ```bash
  gcc mutex_example.c -o mutex_example -pthread
  ./mutex_example
  ```
- **See:** [`mutex/README.md`](mutex/README.md) for details and expected output.

---

### 2. `peterson/` – Peterson's Algorithm

- **Purpose:** Shows a software-only solution for mutual exclusion between two threads (no hardware primitives).
- **Files:**
  - `petersons_solution_i.c` – Thread i's code.
  - `petersons_solution_j.c` – Thread j's code.
- **How to run:** Compile and run each file separately.
- **See:** [`peterson/README.md`](peterson/README.md) for explanation and usage.

---

### 3. `producer-consumer/` – Producer-Consumer Problem

- **Purpose:** Classic example of synchronizing producer and consumer threads using mutexes and condition variables.
- **Files:**
  - `producer_consumer_example.c` – Basic version.
  - `producer_consumer_example_verbose.c` – With detailed print statements for tracing.
- **How to run:**
  ```bash
  gcc producer_consumer_example.c -o producer_consumer_example -lpthread
  ./producer_consumer_example
  ```
- **See:** [`producer-consumer/README.md`](producer-consumer/README.md) for step-by-step explanation and sample output.

---

## 📝 Notes

- All examples use POSIX threads (`pthread`).
- Make sure to compile with the `-pthread` or `-lpthread` flag.
- Each subfolder contains a README with more details, explanations, and expected outputs.

---

## 🚀 Getting Started

1. Choose an example folder.
2. Read its `README.md` for context.
3. Compile the `.c` file(s) using GCC and the pthread flag.
4. Run the resulting executable to observe thread synchronization in action.

---

Happy coding! 🧵
