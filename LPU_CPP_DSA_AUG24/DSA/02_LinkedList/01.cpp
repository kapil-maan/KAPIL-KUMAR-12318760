//Intro to singly LL
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head, int val){
    //create a new node in which data feild will have val and next pointer will be NULL
    Node* n = new Node(val);

    if(head == NULL){
        head = n;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;

}

void insertAtHead(Node* &head, int val){

    Node* n = new Node(val);

    n->next = head;
    head = n;
}

void deletion(Node* &head, int val){
    Node* temp = head;

    if(head == NULL) return;

    while(temp->next->data != val){
        temp= temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;

}

void deletionAtHead(Node* &head){
    Node* toDelete = head;
    head = head->next;
    delete toDelete;
}

bool search(Node* head, int key){
    Node* temp = head;

    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void display(Node* head){

    Node* temp = head;

    while(temp!=NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    
}
 
int main()
{
    Node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);

    insertAtHead(head, 9);
    insertAtHead(head, 100);

    // deletion(head, 2);

    if(search(head, 2)){
        cout << "Key found" << endl;
    }
    else{
        cout << "key not found" << endl;
    }


    display(head);
}