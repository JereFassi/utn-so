#include <stdbool.h>

volatile bool flag[2] = {false, false};
volatile int turn;

void process(int i)
{
  int j = 1 - i;
  while (true)
  {
    flag[i] = true;
    turn = j;
    while (flag[j] && turn == j)
    {
      // Busy wait
    }
    // Critical section
    // ...
    flag[i] = false;
    // Remainder section
    // ...
  }
}
// Peterson's solution is a classic algorithm for mutual exclusion in concurrent
// programming. It allows two processes to share a single-use resource without conflict.
