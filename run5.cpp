#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int info;
    Node *next;
};

void push(Node **head, int data) {
    Node *ptr = *head;
    if(ptr == NULL) {
        ptr = new Node;
        ptr->info = data;
        ptr->next = NULL;
        *head = ptr;
        return;
    }
    Node *temp = new Node;
    temp->info = data;
    temp->next = ptr;
    ptr = temp;
    *head = ptr; 
}
void show(Node *head) {
    while(head != NULL) {
        cout<<head->info<<" ";
        head = head->next;
    }
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
        push(&head, x);
    }
    show(head);
    

return 0;
}