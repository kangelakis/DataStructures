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
    {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}
// display linked list contents
void displayList(struct Node *node){
   while (node != NULL)
   {
      cout<<node->data<<"-->";
      node = node->next;
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

//histogram
struct Node* histogram = NULL;
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
MergeSort(&histogram);
displayList(histogram);
return 0;


}
