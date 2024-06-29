#include <bits\stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }

    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        back = prev1;
    }
};

Node* reverseDLL(Node* head){   
    if (head == NULL || head->next == NULL) {
        return head; 
    }
    Node* prev1;  
    Node* current = head;   
    while (current != NULL){
        prev1 = current->back; 
        current->back = current->next; 
        current->next = prev1;          
        current = current->back; 
    }
    return prev1->back;   
}

Node* insertAtTail(Node* head, int k){
    Node* newNode = new Node(k);
    if(head == nullptr){
        head = newNode;
    }
    Node* tail = head;
    while (tail->next != nullptr){
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->back = tail;
    return head;
}

Node* arr2LLTail(vector <int> &arr){
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, tail);
        tail->next = temp;
        tail = temp;
    }
    return tail;
}

Node* arr2LLHead(vector <int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* deleteLastNode(Node *head){
    if(head->next == nullptr){
        return nullptr;
    }
    else{
        Node* tail = head;
        while(tail->next->next != nullptr){
            tail = tail->next;
        }
        tail->next = nullptr;
    }
    return head;
}

void DLLtraverse(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void DLLreverse(Node* tail){
    Node* temp = tail;
    while(temp){
        cout << temp->data << " ";
        temp = temp->back;
    }
    cout << "\n";
}

int main(){
    vector <int> arr = {4, 3, 1, 2, 7, 9};
    Node* head = arr2LLHead(arr);
    Node* tail = arr2LLTail(arr);
    DLLtraverse(head);
    DLLreverse(tail);
    Node* newHead = insertAtTail(head, 5);
    DLLtraverse(newHead);
    Node* nHead = deleteLastNode(newHead);
    DLLtraverse(nHead);
    Node* nH = reverseDLL(nHead);
    DLLtraverse(nH);
    return 0;
}