#include <iostream>
#include <random>
#include <functional>

using namespace std;

// linked list 
struct node
{
    int data;
    int c=-1;//used counter only in histogram(-1 information used in displayList function)
    struct node *next;
};


//new node in front
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
    while (node != NULL){
        if(node->c == -1){ //if c=-1 it's list L
            if(node->next != NULL){
                cout<<node->data<<"-->";
                node = node->next; 
            }else{
                cout << node->data;
                break;
            }
        }else{ //else it's the histogram
            if(node->next != NULL){
                cout<<"["<<node->data<<"|"<<node->c<<"]"<<"-->";
                node = node->next; 
            }else{
                cout<<"["<<node->data<<"|"<<node->c<<"]";
                break;
            }
        }
          
    }
    cout<<endl;
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
node* merge(node *left, node *right)
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
node* mergeSort(node *start)


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

int counter(node*histogram,node*L){
   int cntr = 0;
   while(L!=NULL){
        if(L->data==histogram->data){
            cntr++;
        }
        L=L->next;
    }
    return cntr;
}


node* histogramCounter(node*histogram,node*L){
    node *current = histogram;
    while(current != NULL){
        int cntr=counter(current,L);
        current->c = cntr;
        current = current->next;
    }
    return histogram;
}
    

node*histogramCreation(node*histogram,node*L){
   while (L != NULL){
      int x=L->data;
      if(!search(histogram,x)){
        push(&histogram,x);
      }

      if(L->next == NULL){
        break;
      }else{
        L = L->next;
      }
   }
   return histogram;
}

//main program 
int main() {
    //Random number gen
    default_random_engine generator;
    uniform_int_distribution<int> data_element_distribution(0, 100);
    auto random_element = std::bind(data_element_distribution, generator);
    
    //Empty list L
    struct node* L = NULL;  
    int n;
    do{
        cout << "Enter the desired amount of numbers: ";
        cin >> n;
    }while(n<=0);
    for(int i=0;i<n;i++){
        push(&L, random_element ());
    } 

    //Histogram
    struct node* histogram = NULL;
    histogram=histogramCreation(histogram,L) ;
    //Display output
    cout<<"List: "<<endl;
    displayList(L); // Time consuming.. if this is commented out the algorithm will run faster
    cout<<"Histogram (1/2 Phase): "<<endl;
    histogram=mergeSort(histogram);
    displayList(histogram);
    cout<<"Histogram (2/2 Phase): "<<endl;
    histogram=histogramCounter(histogram,L);
    displayList(histogram);

    //Wait for user input before exiting
    cout<<endl<< "Press any key to exit...";
    cin.ignore();  
    cin.get(); 
    return 0;
}