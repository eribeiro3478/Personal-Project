Queue Implementation Using Two Stacks in C++

Description
This project implements a queue data structure using two stacks in C++. The code consists of three main classes: Node, LLStack, and StackQ, each playing a crucial role in the creation and management of the queue. The main function provides a menu-driven interface for users to interact with the queue, allowing them to perform operations such as enqueue, dequeue, peek, and display the queue.

Components:
1. Node Class
The Node class represents an individual element within a linked list. Each node stores an integer value (data) and a pointer to the next node (nextNode). This class provides basic getters and setters to access and modify these properties.

2. LLStack Class
The LLStack class implements a stack using a linked list. This stack is used to build the queue. The key operations provided by this class include:
- push(int data): Adds a new element to the top of the stack.
- pop(): Removes and returns the top element of the stack.
- peek(): Returns the top element without removing it.
- stackEmpty(): Checks whether the stack is empty.
- print(): Displays the elements in the stack.

3. StackQ Class
The StackQ class implements a queue by using two stacks (enQStack and deQStack). The class provides the following operations:
- enQueue(int data): Adds an element to the back of the queue.
- deQueue(): Removes and returns the front element of the queue.
- peek(): Returns the front element without removing it.
- printQueue(): Displays all elements in the queue.
- printEnqDeqStacks(): Displays the contents of the enQStack and deQStack separately.
- queueSize(): Returns the total number of elements in the queue.

4. Main Function
The main() function provides a user interface for interacting with the queue. Users can choose from several options to enqueue, dequeue, peek, display the queue, or exit the program.
