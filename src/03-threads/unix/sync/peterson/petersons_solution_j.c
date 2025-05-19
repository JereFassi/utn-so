#include <stdbool.h>

volatile bool flag[2] = {false, false};
volatile int turn;

void process(int j)
{
  int i = 1 - j;
  while (true)
  {
    flag[j] = true;
    turn = i;
    while (flag[i] && turn == i)
    {
      // Busy wait
    }
    // Critical section
    // ...
    flag[j] = false;
    // Remainder section
    // ...
  }
}
