#include<iostream>
#include<cstdlib>

using namespace std;

struct Node{
  int data;
  struct Node* NextNode;
};

class Queue{

  private:
    Node* rear;
    Node* front;
  public:
    Queue();
    void enQueue();
    void deQueue();
    void display();

};

Queue::Queue(){
  rear = NULL;
  front = NULL;
}

void Queue::enQueue(){
  int data_en;
  Node* newNode = new Node;
  cout << "Enter data to enqueue: ";
  cin >> data_en;
  newNode->data = data_en;
  newNode->NextNode = NULL;

  if(front == NULL){
    front = newNode;
  }
  else{
    rear->NextNode = newNode;
  }
  rear = newNode;
}
void Queue::deQueue(){
  Node* temp = new Node;
  if(front == NULL){
    cout << "This Queue is empty";
  }else{
    temp = front;
    front = front->NextNode;
    cout << "This data is deQueued" << temp->data;
    delete temp;
  }
}
void Queue::display(){
  Node* temp = new Node;
  if(front == NULL){
    cout << "Nothing to display";
  }
  else{
    temp = front;
    while(temp!=NULL){
      cout << temp->data << " ";
      temp = temp->NextNode;
    }
  }
}

int main(){
  Queue queue;
  int choice;
  while(true){
    cout << "\n1.Enqueue\n2. Dequeue\n3. Display\n 4.Quit";
    cout << "\nYour choice:";
    cin >> choice;

    switch (choice) {
      case 1:
        queue.enQueue();
        break;
      case 2:
        queue.deQueue();
        break;
      case 3:
        queue.display();
        break;
      case 4:
        exit(0);
        break;
    }
  }
  return 0;
}
