## Mutex Example Explanation

This example demonstrates thread synchronization using mutexes in C:

### Key Components

1. **Mutex and Shared Resource Declaration**
   ```c
   pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
   int shared_counter = 0;
   ```
   Creates a mutex for thread synchronization and a shared counter variable.

2. **Thread Function**
   ```c
   void *thread_function(void *arg) {
       pthread_mutex_lock(&mutex);
       shared_counter++;
       printf("Thread %d: counter = %d\n", thread_id, shared_counter);
       pthread_mutex_unlock(&mutex);
   }
   ```
   Shows critical section protection using:
   - `pthread_mutex_lock()`: Lock the mutex before accessing shared resource
   - `pthread_mutex_unlock()`: Release the mutex after modification

3. **Thread Creation and Management**
   ```c
   pthread_t threads[NUM_THREADS];
   for (int i = 0; i < NUM_THREADS; i++) {
       thread_ids[i] = i + 1;
       pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
   }
   ```
   Creates and manages multiple threads using pthread library.

### Compilation and Execution
```bash
# Compile the example (note the -pthread flag)
gcc src/03-threads/mutex_example.c -o mutex_example -pthread

# Run the program
./mutex_example
```

### Expected Output
```
Thread 1: counter = 1
Thread 3: counter = 2
Thread 2: counter = 3
Thread 4: counter = 4
Thread 1: counter = 5
...
```

Note: The order of thread execution may vary due to random sleep intervals.