
import java.util.concurrent.*;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.Random;

public class ProducerConsumer {
  static final int N = 100; // constant giving the buffer size
  static Producer p = new Producer(); // instantiate a new producer thread
  static Consumer c = new Consumer(); // instantiate a new consumer thread
  static OurMonitor mon = new OurMonitor(); // instantiate a new monitor

  public static void main(String[] args) {
    p.start(); // star t the producer thread
    c.start(); // star t the consumer thread
  }

  static class Producer extends Thread {
    private java.util.Random random = new java.util.Random();

    @Override
    public void run() { // run method contains the thread code
      int item;
      while (true) { // producer loop
        item = produceItem();
        mon.insert(item);
      }
    }

    private int produceItem() {
      System.out.println("producing some item...");
      return random.nextInt(100); // produce a random item
    }
  }

  static class Consumer extends Thread {
    
    @Override
    public void run() { // run method contains the thread code
      int item;
      while (true) { // consumer loop
        item = mon.remove();
        consumeItem(item);
      }
    }

    private void consumeItem(int item) { 
      System.out.println("consuming some item..." + item); 
      try {
        Thread.sleep(1000); // simulate time taken to consume the item
      } catch (InterruptedException e) {
        System.out.println("Thread interrupted: " + e.getMessage());
        Thread.currentThread().interrupt();
      }
    }
  }

  static class OurMonitor { // this is a monitor
    private int[] buffer = new int[N];
    private int count = 0; // counters and indices
    private int lo = 0;
    private int hi = 0;
    
    public synchronized void insert(int val) {
      while (count == N) goToSleep(); // if the buffer is full, go to sleep
      buffer[hi] = val; // inser t an item into the buffer
      hi = (hi + 1) % N; // slot to place next item in
      count = count + 1; // one more item in the buffer now
      if (count == 1) notifyAll(); // if consumer was sleeping, wake it up
    }

    public synchronized int remove() {
      int val;
      while (count == 0) goToSleep(); // if the buffer is empty, go to sleep
      val = buffer[lo]; // fetch an item from the buffer
      lo = (lo + 1) % N; // slot to fetch next item from
      count = count - 1; // one few items in the buffer
      if (count == N - 1) notifyAll(); // if producer was sleeping, wake it up
      return val;
    }

    private void goToSleep() {
      synchronized(this) {
        try {
          while (!canProceed()) {
            wait();
          }
        } catch (InterruptedException exc) {
          System.out.println("Thread interrupted: " + exc.getMessage());
          Thread.currentThread().interrupt();
        }
      }
    }

    // Helper method to determine if the thread can proceed
    private boolean canProceed() {
      // If called from insert, proceed if buffer is not full
      // If called from remove, proceed if buffer is not empty
      Thread current = Thread.currentThread();
      if (current instanceof Producer) {
        return count < N;
      } else if (current instanceof Consumer) {
        return count > 0;
      }
      return true;
    }
  }
}