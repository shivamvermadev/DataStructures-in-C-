#include<bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int info;
    Node *next;
};

Node* createNode(int data) {
    Node *node = new Node;
    node->info = data;
    node->next = NULL;
    return node;
}

void insertFront(Node **head,int data) {
    Node *ptr = *head;
    if(ptr == NULL) {
        ptr = createNode(data);
        *head = ptr;
        return;
    }
    Node *node = createNode(data);
    node->next = ptr;
    *head = node;
}

void insertEnd(Node **head, int data) {
    Node *ptr = *head;
    if(ptr == NULL) {
        ptr = createNode(data);
        *head = ptr;
        return;
    }
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    Node *node = createNode(data);
    ptr->next = node;
}

void show(Node *head) {
    Node *ptr = head;
    while(ptr != NULL) {
        cout<<ptr->info<<" ";
        ptr = ptr->next;
    }
}

void deleteNode(Node **head, int data) {
    Node *ptr = *head;
    if(ptr == NULL) {
        return;
    }

    Node *prev = NULL;

    while(ptr != NULL) {
        if(ptr->info == data) {
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    delete(ptr);
}

int length(Node *head) {
    if(head == NULL) {
        return 0;
    }
    return 1 + length(head->next);
}

bool loopInLL(Node *head) {
    if(head == NULL) {
        return 0;
    }
    Node *ptr1 = head, *ptr2 = head;
    while(ptr1 && ptr2 && ptr2->next) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
        if(ptr2 == ptr1) {
            break;
        }
    }
    Node *ptr = head;
    int count = 0;
    while(ptr != ptr1) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void reverseLL(Node **head) {
    Node *cur = *head, *next = NULL, *prev = NULL;
    
    while(cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

void middleOfLL(Node *head) {
    Node *p1 = head, *p2 = head;
    while(p2 != NULL && p2->next != NULL) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    cout<<p1->info<<" ";
}

void swapNodes(int x, int y, Node **head) {
    Node *prev = NULL;
    Node *prevX = NULL;
    Node *prevY = NULL;
    Node *nodeX = NULL;
    Node *nodeY = NULL;

    Node *ptr = *head;

    while(ptr != NULL) {

        if(ptr->info == x) {
            prevX = prev;
            nodeX = ptr;
        }
        if(ptr->info == y) {
            prevY = prev;
            nodeY = ptr;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    if(prevX == NULL) {
        *head = nodeY;
    }
    else{
        prevX->next = nodeY;
    }

    if(prevY == NULL) {
        *head = nodeX;
    }
    else{ 
        prevY->next = nodeX;
    }
    swap(nodeX->next, nodeY->next);
}

void intersection(Node *head1, Node *head2, vector<int> &v) {
    if(head1 == NULL || head2 == NULL) {
        return;
    }
    if(head1->info < head2->info) {
        return intersection(head1->next, head2, v);
    }
    if(head2->info < head1->info) {
        return intersection(head1, head2->next, v);
    }
    if(head2->info == head1->info) {
        v.push_back(head2->info);
        return intersection(head1->next, head2->next, v);
    }

}

int32_t main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Node *head = NULL;
    int t, x;
    
    cin>>t;
    while(t--) {
        cin>>x;
        insertFront(&head, x);
    }
    Node *head1 = NULL;
    cin>>t;
    while(t--) {
        cin>>x;
        insertFront(&head1, x);
    }

    // deleteNode(&head, 1);   
    // deleteNode(&head, 4);   
    // delete(&head);
    // free(head);
    // show(head);
    // reverseLL(&head);
    // cout<<endl;
    // show(head);
    // cout<<endl<<length(head);
    // middleOfLL(head);
    // swapNodes(1, 6, &head);
    cout<<endl;
    vector<int> v;
    intersection(head, head1, v);
    // show(head);
    for(auto i:v) {
        cout<<i<<" ";
    }
    
return 0;
}