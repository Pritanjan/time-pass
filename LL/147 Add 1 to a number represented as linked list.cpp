
/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    // Node* reverse(Node* head){
    //     Node* prev, * next = NULL;
    //     while(head){
    //         next = head -> next;
    //         head -> next = prev;
    //         prev = head;
    //         head = next;
    //     }
    //     return prev;
    // }
    
    // Node* reverse(Node* head){
    //     Node* curr=head;
    //     Node* prev=NULL;
    //     Node* temp=NULL;
    //     while(curr){
    //         temp=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=temp;
    //     }
    //     return prev;
    // }
    
    Node* reverse(Node* head) {
        if(head == NULL or head -> next == NULL)
            return head; 
        
        Node * prev = NULL;
        Node * curr = head;
        
        while(curr != NULL){
            Node * fd = NULL;
            fd = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = fd;
        }
        return prev;
    }
    
    Node* addOne(Node *head) {
        head = reverse(head);
        Node *curr = head;
        
        while(curr){
            if(curr -> data  < 9){
                curr -> data += 1;
                break;
            }
            else if(curr -> next){
                curr -> data = 0;
                curr = curr -> next;
            }
            else{
                curr -> data = 0;
                curr -> next = new Node(1);
                break;
            }
        }
        
        head = reverse(head);
        
        return head;
    }
};





