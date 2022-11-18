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
   Semaphore mutex = 1
Semaphore writer = 0
Semaphore reader = 0
 
int nReader = 0
int nWriter = 0
int wReader = 0
int wWriter = 0
 

while (1) {
 
P(mutex);
if (nReader + wWriter + nWriter == 0) {
	nWriter++;
	V(mutex);
} else {
	wWriter++;
	V(mutex);
	P(writer);
}
 

 
P(mutex);
NWriter = 0;
If (wReaders > 0) {
	 for i = 1 to min(wReaders,5) {
		V(readers)
		nReaders++;
		wReaders--;
	}
else if (wWriters > 0) {
	wWriters--;
	nWriters++;
	V(writer);
}
V(mutex);
}
 
while (1) {
 
P(mutex)
if (nWriters + wWriter == 0 & nReader < 5) {
	nReaders++;
	V(mutex);
} else {
	wReaders++;
	V(mutex);
	P(reader);
}
 
P(mutex);
nReaders--;
if (wWriters > 0 & nReaders == 0) {
	wWriters--; 
nWriters++;
	V(writer);
} else if (wReaders > 0 & wWriters == 0) {
	nReaders++; 
	wReaders--;
	V(reader);
}
V(mutex);

    return 0;
}
