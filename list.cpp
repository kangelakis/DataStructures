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

/*void sortList() {  
        //Node current will point to head  
        struct node *current = head, *index = NULL;  
        int temp;  
          
        if(head == NULL) {  
            return;  
        }  
        else {  
            while(current != NULL) {  
                //Node index will point to node next to current  
                index = current->next;  
                  
                while(index != NULL) {  
                    //If current node's data is greater than index's node data, swap the data between them  
                    if(current->data > index->data) {  
                        temp = current->data;  
                        current->data = index->data;  
                        index->data = temp;  
                    }  
                    index = index->next;  
                }  
                current = current->next;  
            }      
        }  
    } */
 //Check if element is in list(used in the histogram)
bool search(Node* head, int x)
{
    Node* current = head; // Initialize current
    while (current != NULL)
    {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}

// display linked list contents
void displayList(struct Node *node)
{
   while (node != NULL)
   {
      cout<<node->data<<"-->";
      node = node->next;
   }
 
}
void createHistogram(struct Node *node,struct Node *histogram)
{
   while (node != NULL)
   {
      int x=node->data;
      if(search(histogram,x)){
      node = node->next;
      }else{
         push(histogram,x);
         node = node->next;
      }
   }
 
}
//main program 
int main() { 
   // empty list L
   struct Node* L = NULL;  

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
cout<<"Final linked list: "<<endl;
displayList(L);

//histogram
struct Node* histogram = NULL;
createHistogram(&L,&histogram);
cout<<"Histogram list: "<<endl;
displayList(histogram);
return 0;


}