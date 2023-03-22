#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    //destructor
    ~Node(){
        int value = this -> data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void InserAtHead(Node *&head, int data){
    // new node 
    Node *temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int data){
    // new node
    Node *temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void InsertAtPosition(Node *&tail,Node *&head,int position , int data){
    // inserting at Start Position
    if(position==1){
        InserAtHead(head,data);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    // inserting at Last Position
    if(temp -> next == NULL){
        InsertAtTail(tail,data);
        return;
    }
    //creating a Node for Data
    Node *NodeToInsert = new Node(data);
    NodeToInsert ->next = temp ->next;
    temp -> next = NodeToInsert;
}

void PrintLl(Node* &head){
    // Traversing a LinkList
    Node *temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void DeleteNode(Node *&head, int position){
    // Deleting First Node
    if(position==1){
        Node *temp = head;
        head = head ->next;
        temp -> next = NULL;
        delete temp;
    
    }else{
        Node *current = head;
        Node *prev = NULL;
        int cnt =1;
        while(cnt < position-1){
            prev = current;
            current = current -> next;
            cnt++;
        }
    
    prev -> next = current->next;
    current->next = NULL;
    delete current;
    }

}

int main(){
    Node* node1 = new Node(10);
    //cout << node1->data << endl;
    //cout << node1->next << endl;
    Node* head = node1;
    Node* tail = node1;
    PrintLl(head);
    //InserAtHead(head , 12);
    InsertAtTail(tail,12);
    PrintLl(head);
    InsertAtTail(tail,15);
    PrintLl(head);
    InsertAtPosition(tail,head,3,22);
    PrintLl(head);
    DeleteNode(head,1);
    PrintLl(head);
}