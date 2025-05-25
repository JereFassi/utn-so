> 🇪🇸 [Leer en español](README.es.md)

# 🧩 Peterson's Algorithm Example

This folder contains a C implementation of **Peterson's algorithm**, a classic software-only solution for achieving mutual exclusion between two concurrent threads or processes.

---

## 📄 Files

- `petersons_solution_i.c` – Code for process/thread **i**.
- `petersons_solution_j.c` – Code for process/thread **j**.

---

## 📝 What is Peterson's Algorithm?

Peterson's algorithm is a synchronization technique that allows two processes to share a single-use resource without conflicts, using only shared memory for communication. It guarantees:

- **Mutual exclusion:** Only one process can enter the critical section at a time.
- **Progress:** If no process is in the critical section, one of the waiting processes can enter.
- **Bounded waiting:** Each process will eventually get its turn.

It does **not** require special hardware instructions—just shared variables.

---

## 🛠️ How to Use

1. **Compile** either file (they are structurally similar, just with roles reversed):

   ```bash
   gcc petersons_solution_i.c -o peterson_i
   gcc petersons_solution_j.c -o peterson_j
   ```

2. **Run** the compiled program(s):

   ```bash
   ./peterson_i
   # or
   ./peterson_j
   ```

> **Note:** These files are designed for educational purposes and illustrate the algorithm's logic. To see the mutual exclusion in action, you would typically integrate both roles into a single program and run them as separate threads or processes, sharing the `flag` and `turn` variables.

---

## 📚 References

- [Peterson's Algorithm – Wikipedia](https://en.wikipedia.org/wiki/Peterson%27s_algorithm)
- Operating Systems textbooks (e.g., Silberschatz, Galvin, Gagne)

---

## 💡 Example Structure

```c
volatile bool flag[2] = {false, false};
volatile int turn;

void process(int i) {
  int j = 1 - i;
  while (true) {
    flag[i] = true;
    turn = j;
    while (flag[j] && turn == j) {
      // Busy wait
    }
    // Critical section
    flag[i] = false;
    // Remainder section
  }
}
```

---

Happy learning!
