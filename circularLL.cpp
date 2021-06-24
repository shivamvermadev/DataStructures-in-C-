#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int info;
    Node *next;
};

void insertFront(Node **head, int data) {
    Node *ptr = *head;
    if(ptr == NULL) {
        ptr = new Node;
        ptr->info = data;
        ptr->next = ptr;
        *head = ptr;
        return;
    }

    Node *temp = new Node;
    temp->info = data;
    temp->next = ptr->next;
    ptr->next = temp;
    *head = ptr;
}
void insertEnd(Node **head, int data) {
    Node *ptr = *head;
    if(ptr == NULL) {
        ptr = new Node;
        ptr->info = data;
        ptr->next = ptr;
        *head = ptr;
        return;
    }

    Node *temp = new Node;
    temp->info = data;
    temp->next = ptr->next;
    ptr->next = temp;
    ptr = temp;
    *head = ptr;
}

void show(Node *head) {
    if(head == NULL) {
        return;
    }

    Node *ptr = head;
    do {
        cout<<head->info<<" ";
        head = head->next;
    } while(head != ptr);
}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node *head = NULL;
    int t,x;
    cin>>t;
    while(t--) {
        cin>>x;
        insertFront(&head, x);
    }
    cin>>t;
    while(t--) {
        cin>>x;
        insertEnd(&head, x);
    }
    show(head);
    
    

return 0;
}