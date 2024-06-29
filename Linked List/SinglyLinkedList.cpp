#include <bits\stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* insertAtFirst(Node* list, int newValue) {
    Node* head = new Node(newValue);
    head->next = list;
    return head;
}

Node* deleteLast(Node* list){
    Node* temp = list;
    while (temp->next->next){
        temp = temp->next;
    }
    temp->next = NULL;
    return list;
}

Node* arr2LL(vector <int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int searchInLinkedList(Node* head, int k) {
    Node* temp = head;
    while(temp){
        if(temp->data == k){
            return 1;
        } 
        temp = temp->next;
    }
    return 0;
}

void LLtraverse(Node* temp){
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int lengthOfLL(Node* temp){
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main(){
    vector <int> arr = {5, 4, 1, 3, 2, 9, 7};
    Node* head = arr2LL(arr);
    Node* temp = head;
    cout << "LL traversal: ";
    LLtraverse(temp);
    cout << "Length of LL: " << lengthOfLL(temp) << "\n";
    int newValue = 8;
    Node* newheah = insertAtFirst(temp, newValue);
    cout << "LL traversal: ";
    LLtraverse(newheah);
    cout << "Length of LL: " << lengthOfLL(newheah) << "\n";
    newheah = deleteLast(newheah);cout << "LL traversal: ";
    LLtraverse(newheah);
    cout << "Length of LL: " << lengthOfLL(newheah) << "\n";
    cout << "LL traversal: ";
    LLtraverse(newheah);
    cout << "Length of LL: " << lengthOfLL(newheah) << "\n";
    int k = 14;
    if(searchInLinkedList(newheah, k) == 1) cout << "Found\n";
    else cout << "Not Found\n";
    return 0;
}