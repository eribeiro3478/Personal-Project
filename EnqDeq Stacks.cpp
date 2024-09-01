
#include <iostream>
using namespace std; 

class Node {
  // Write Node Description here
  // Node variables are given in Assignment
private:

  int data;
  Node* nextNode;

public:
  Node(int data){
    this->data = data;
    this->nextNode = NULL;
  }
//getters and setters
 void setData(int data){
    this->data = data;
  }
  int getData() {
    return data;
  }

  void setNodeNext(Node* nextNode){
    this->nextNode = nextNode;
  }
  Node* getNodeNext() {
    return nextNode;
  }
};
class LLStack {
private:
  // Stack ADT
  //  Use Appropriate Variables
  //  Write Stack methods here
  //  Stack is implemented as a linked list
  //   Stack methods are Push(), Pop(), Peek()
  Node* top;
  int stackSize;

public:
  LLStack() {
    top = NULL;
    stackSize = 0;
  }

  int getStackSize() {
    return stackSize;
  }

  bool stackEmpty() {
    if (top == NULL) {
       return true;
    }
     
    else {
      return false;
    }
  }

  void push(int data) {
    Node* temp = new Node(data); // new node and create memory space.
    temp->setData(data); // pointer to the new allocated data in the stack
    temp->setNodeNext(top); // creates a link from the top element to the previous
    top = temp; // updates the top value of the stack
    stackSize++;
  }


  int pop() {
    Node* temp;
    
    if (stackEmpty()) {
       cout << "Cannot pop from an empty stack!" << endl;
    }
    else {
      int popped = top->getData();
      temp = top; // saves the top node to temp
      top = temp->getNodeNext(); // top now points to the next node
      delete temp; // deletes the value and memory allocation of temp
      stackSize = stackSize -1; //decrease the stack size by 1.
      return popped;
    }
  }


  int peek() {
    if(stackEmpty()) {
      cout << "Cannot peek from an Empty Stack!";
    }
    else {
      return top->getData();
    }
  }


  void print() {
    Node* temp;
    LLStack tempStack; // temp stack to push values popped from the original stack

    if (stackEmpty()) {
      cout << "This stack is empty!" << endl;
      
    }
    else { 
      cout << "Stack Displayed: ";
      while (!stackEmpty()) {
        temp = top;
        cout << temp->getData();
        cout << " " ;
        tempStack.push(pop()); // pops from the original, pushes to temp stack
        
      }
      cout << endl;

      while(!tempStack.stackEmpty()){ //returning the values to original stack.
        push(tempStack.pop()); //pops from the temp stack, pushes into the original stack
      }

      cout << endl;
    }
  }
    

  };

class StackQ {
public:
  LLStack* enQStack;
  LLStack* deQStack;

StackQ() {
  enQStack = new LLStack();
  deQStack = new LLStack();
}

  bool stackEmpty() {
    return enQStack->stackEmpty() && deQStack->stackEmpty();
  }

  void enQueue(int data) {
    enQStack->push(data);
  }

  int deQueue() {
    if (deQStack->stackEmpty()) {
      while (!enQStack->stackEmpty()) {
        deQStack->push(enQStack->pop());
        
      }
    }
      
    if (deQStack->stackEmpty()) {
      cout <<"Queue is empty, cannot dequeue!"<< endl;
      return -1;
    }
    
      return deQStack->pop();

  }

  int peek() {
     if (deQStack->stackEmpty()) {
      while (!enQStack->stackEmpty()) {
        deQStack->push(enQStack->pop());
      }
    }

     if (deQStack->stackEmpty()) {
      cout <<"Queue is empty, cannot peek!"<< endl;
      return -1;
    }

    
      return deQStack->peek();
    
  }

  void printQueue() {
    if (stackEmpty()) {
      cout << "The stack is empty!" << endl;
    }
    else {
      cout <<"Displaying the queue: " << endl;
      if (!deQStack->stackEmpty()) {
        deQStack->print();
      }
      if (!enQStack->stackEmpty()) {
        enQStack->print();
      }
      
    }
    
  }

  void printEnqDeqStacks () {
    cout << "Displaying enQStack: " << endl;
    enQStack->print();
    cout << "Displaying deQStack: " << endl;
    deQStack->print();
  }

  int queueSize() {
    return enQStack->getStackSize() + deQStack->getStackSize();
  }
  // Queue ADT
  //  This is your queue class
  //  Implement queue methods here
  //  Queue methods are given in the Assignment
  //  Queue is implemented by manipulating two stacks.
  //  You will need references to 2 stacks here
};


int main() {
  StackQ queue;
  int choice;
  int input;

  
  while(choice != 7) {
  cout << "Choose from the following options: " << endl;
  cout << "1. Enqueue in the queue" << endl;
  cout << "2. Dequeue from the queue" << endl;
  cout << "3. Peek from the Queue" << endl;
  cout << "4. Display the queue" << endl;
  cout << "5. Display enQStack and deQStack" << endl;
  cout << "6. Display size of the queue" << endl;
  cout << "7. Exit" << endl;

    cout << "Enter Choice: " << endl;
    cin >> choice;

    switch(choice) {
      case 1:
      cout << "Enter a value to enqueue: ";
      cin >> input;
      queue.enQueue(input);
      break;
      
      case 2:
      input = queue.deQueue();
        if(input!= -1)
      cout << "Value dequeued: " << input << endl;
      break;

      case 3:
      input = queue.peek();
      if (input!= -1)
        cout << "Value peeked: " << input << endl;
      break;
      
      case 4:
      queue.printQueue();
      break;
      
      case 5:
      queue.printEnqDeqStacks();
      break;
      
      case 6:
      cout << "Size of the queue: " << queue.queueSize() << endl;
      
      case 7:
      cout << "Exit" << endl;
      break;

      default:
      cout << "Please enter a number between 1-7!"<< endl;
      break;
      }
      
    }
  // Main method is written here
  // Write the options for menu
  // Implement appropriate exception Handling
}