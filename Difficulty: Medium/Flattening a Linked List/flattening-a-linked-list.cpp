//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    
    Node *merge(Node *h1,Node *h2){
        Node *dummy=new Node(-1);
        Node *tmp=dummy;
        
        while(h1 != NULL && h2!=NULL){
            if(h1->data < h2->data){
                tmp->bottom=h1;
                tmp=h1;
                h1=h1->bottom;
            }
            else{
                tmp->bottom=h2;
                tmp=h2;
                h2=h2->bottom;
                
            }
            tmp->next=NULL;
        }
        
        if(h1) tmp->bottom=h1;
        if(h2) tmp->bottom=h2;
        if(dummy->bottom) dummy->bottom->next=NULL;
        return dummy->bottom;
    }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *head) {
        // Your code here
        if(head == NULL || head->next == NULL) return head;
        
        Node *mergedList = flatten(head->next);
        head = merge(head,mergedList);
        return head;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++) {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL) {
                head = temp;
                pre = temp;
            } else {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++) {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}

// } Driver Code Ends