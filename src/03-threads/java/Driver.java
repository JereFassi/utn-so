import java.util.concurrent.*;

class Summation implements Callable<Integer>
{
  private int upper;
  public Summation(int upper) {
    this.upper = upper;
  }

  /* The thread will execute in this method */
  public Integer call() 
  {
    int sum = 0;
    for (int i = 1; i <= upper; i++)
      sum += i;
    return sum;
  }
}

public class Driver
{
  public static void main(String[] args) {
    int upper = Integer.parseInt(args[0]);
    ExecutorService pool = Executors.newSingleThreadExecutor();
    Future<Integer> result = pool.submit(new Summation(upper));
    try {
      System.out.println("sum = " + result.get());
    } 
    catch (InterruptedException | ExecutionException ie) {
      System.out.println("Exception: " + ie.getMessage());
    }
    finally {
      pool.shutdown();
    }
  }
}
// The above code is a simple Java program that uses the Executor framework to create a thread pool and submit a task to calculate the sum of integers from 1 to a given upper limit.
// The program defines a class `Summation` that implements the `Callable` interface, allowing it to return a result (the sum) and handle exceptions.