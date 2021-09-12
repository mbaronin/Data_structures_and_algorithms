#include "Queue.h"
#include<time.h>
typedef int TYPE;

void useQueue() 
{
	cout << "\t\t\tuse Queue !" << endl;
	srand((unsigned int)time(NULL));
	Queue<TYPE> que1;

	
	for (int i = 0; i < 7; i++){ que1.enqueue(rand() % 10); que1.printQueue(); }
	for (int i = 0; i < 3; i++) {que1.dequeue();que1.printQueue();}
	for (int i = 0; i < 3; i++) { que1.enqueue(rand() % 10); que1.printQueue(); }
	for (int i = 0; i < 7; i++) { que1.dequeue(); que1.printQueue(); }
	for (int i = 0; i < 4; i++) { que1.enqueue(rand() % 10); que1.printQueue(); }
	que1.dequeue(); que1.printQueue();
	

}