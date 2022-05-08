#include <iostream>
#include <random>
#include <functional>

using namespace std;
 
// linked list 
struct Node
{
   int data;
   struct Node *next;
};
//new  node in front
void push(struct Node** head, int node_data)
{
   struct Node* newNode = new Node;
   newNode->data = node_data;
   newNode->next = (*head);
   (*head) = newNode;
}
 //Check if element is in list(used in the histogram)
bool search(Node* head, int x)
{
    Node* current = head; // Initialize current
    while (current != NULL)
#include <iostream>
#include <random>
#include <functional>

using namespace std;
 
// linked list 
struct node
{
   int data;
   struct node *next;
   node()
    {
        data = 0;
        next = NULL;
    }
};
//new  node in front
void push(struct node** head, int node_data)
{
   struct node* newnode = new node;
   newnode->data = node_data;
   newnode->next = (*head);
   (*head) = newnode;
}
 //Check if element is in list(used in the histogram)
bool search(node* head, int x)
{
    node* current = head; // Initialize current
    while (current != NULL)
    {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}
// display linked list contents
void displayList(struct node *node){
   while (node != NULL)
   {
      cout<<node->data<<"-->";
      node = node->next;
   }
 
}
node * tortoiseAndHareApproach(node *head)
{
    node* slow = head;
    node* fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = (fast->next)->next;
    }
    // slow must be pointing at the middle element of the list
    return slow;
}

// Function to take two sorted linked lists and merge them
// to form a sorted resultant linked list
node * merge(node *left, node *right)
{

    // creating an auxiliary head node storing the 

    // the head of the linked list to be returned and 

    // another pointer to remember where the last 

    // added node was
    node *dummyHead = new node();
    node *current = dummyHead;
    
    while (left != NULL && right != NULL)
    {
        if (left->data <= right->data)
        {
            current-> next = left;
            left = left->next;
            current = current-> next;
        }
        else if (right->data < left->data)
        {
            current->next = right;
            right = right->next;
            current = current->next;
        }
    }
    while (left != NULL)
    {
        current->next = left;
        left = left->next;
        current = current->next;
    }
    while (right != NULL)
    {
        current->next = right;
        right = right->next;
        current = current->next;
    }
    return dummyHead->next;
}

// Function to recursively  divide the linked list
node * mergeSort(node *start)
{
    if (start -> next == NULL)
    {
        // only 1 element in current list
        // so return it as it is
        return start;
    }
    // finding middle of the list using
    // the tortoise and hare approach
    node *mid = tortoiseAndHareApproach(start);
    node *start_of_right = mid->next;

    // breaking the linked list into two parts
    mid->next = NULL;

    node *left = mergeSort(start);
    node *right = mergeSort(start_of_right);

    node *new_head = merge(left, right);

    return new_head;
}


//main program 
int main() {
   // empty list L
   struct node* L = NULL;  

   //Random number gen
   default_random_engine generator;
   uniform_int_distribution<int> data_element_distribution(0, 100);
   auto random_element = std::bind(data_element_distribution, generator);
   
   cout << "Enter the number of elements in the list: ";
   int n;
   cin >> n;

   for(int i=0;i<n;i++){
      push(&L, random_element ());
   } 

//histogram
struct node* histogram = NULL;
while (L != NULL)
   {
      int x=L->data;
      if(search(histogram,x)){
      L = L->next;
      }else{
         push(&histogram,x);
         L = L->next;
      }
   }
cout<<"Histogram list: "<<endl;
displayList(histogram);
cout<<"Histogram list Sorted: "<<endl;
histogram=mergeSort(histogram);
displayList(histogram);
return 0;


}
