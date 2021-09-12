#include "Stack.h"
#include<time.h>
typedef int TYPE;

void useStack() 
{
	cout << "\t\t\tuse Stack !" << endl;
	srand((unsigned int)time(NULL));
	Stack<int> stack;

	
		
	
	for (int i = 0; i < 6; i++) { stack.enStack(rand()% 10); stack.printStack(); }
	for (int i = 0; i < 4; i++) { stack.deStack(); stack.printStack(); }
	for (int i = 0; i < 3; i++) { stack.enStack(rand() % 10); stack.printStack(); }
	for (int i = 0; i < 5; i++) { stack.deStack(); stack.printStack(); }
	for (int i = 0; i < 4; i++) { stack.enStack(rand() % 10); stack.printStack(); }
	stack.deStack(); stack.printStack();
}