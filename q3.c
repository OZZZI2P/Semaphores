/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
int main()
{
    int monkey_count[2] = {0,0}; 
semaphore mutex[2] = {1,1};
semaphore max_on_rope = 5; 
semaphore rope = 1; 
void WaitUntilSafeToCross(Destination dest)
{
 wait(mutex[dest]);
 monkey_count[dest]++;
 if (monkey_count[dest] == 1)
 
 wait(rope);
 signal(mutex[dest]);
 wait(max_on_rope);
}
void DoneWithCrossing(Destination dest)
{
 wait(mutex[dest]);
 signal(max_on_rope);
 monkey_count[dest]--;
 if (monkey_count[dest] == 0)
 signal(rope);
 signal(mutex[dest]);
}

    return 0;
}
