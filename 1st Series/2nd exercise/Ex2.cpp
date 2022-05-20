#include <iostream>
#include <random>
#include <functional>
#include <string>

using namespace std;


class Heap{
    private:
        float *arr;
        int CurrentSize, MaxSize;
        
    public:
        Heap(int MaxSize){ //Constructor Method
            this->MaxSize = MaxSize; 
            arr = new float[MaxSize+1];
            CurrentSize = 0;
        }

        float Insert(const float &x){
                    if(CurrentSize == MaxSize){
                        cout << "Heap is full" << endl;
                        return -1;
                    }
                    int i = ++CurrentSize; //Get current size incremented by 1
                    arr[i] = x; 
                    return x;
        }

        void Initialize(string str){//String variable is used to initialize the heap into a max or min one accordingly
            for(int i = CurrentSize/2; i >= 1; i--){
                int c = 2*i;
                float y = arr[i]; 
                while(c <= CurrentSize){
                    if(str == "Min"){ //Make array into a min-heap
                        if(c < CurrentSize && arr[c] > arr[c+1]) c++;
                        if(y <= arr[c]) break; 
                    }else{ //Make array into a max-heap
                        if(c < CurrentSize && arr[c] < arr[c+1]) c++;
                        if(y >= arr[c]) break;
                    }
                    arr[c/2] = arr[c];
                    c *= 2;
                }
                arr[c/2] = y;
            }
        }

        float SumHeap(int n,string str){
            float sum=0;
            for(int j=0; j<n; j++){ //Access all the nodes
                float y = arr[CurrentSize--]; //Last element
                int i = 1, ci = 2;
                sum+=arr[1];
                if(str=="Min"){
                     while(ci <= CurrentSize){
                        if(ci < CurrentSize && arr[ci] > arr[ci+1]) ci++;
                        if (y <= arr[ci]) break;
                        arr[i] = arr[ci];
                        i = ci;
                        ci *= 2;
                    }
                }else{
                    while(ci <= CurrentSize){
                        if(ci < CurrentSize && arr[ci] < arr[ci+1]) ci++;
                        if (y >= arr[ci]) break;
                        arr[i] = arr[ci];
                        i = ci;
                        ci *= 2;
                    }
                
                }
                arr[i] = y;
            }
            return sum;            
        }

        void Display(){ //Display the heaps
            for(int i = 1; i <= CurrentSize; i++){ 
                cout << "[" << arr[i] << "] ";
            }
            cout << endl;
        }

        ~Heap(){ //Destructor Method
            cout<< "Deleting: " << this->arr <<endl;
            delete [] this->arr;
        }
};

int main(){
    //Random Number Generator
    default_random_engine generator;
    chi_squared_distribution<float> my_distribution(0.5);
    auto random_num = std::bind(my_distribution, generator);

    

    int n;
    float r;
    do{
        cout << "Enter the amount of elements: ";
        cin >> n;
    }while(n<=0);

    Heap *heap_min = new Heap(n);
    Heap *heap_max = new Heap(n);

    for (int i = 0; i < n; i++){
        r=random_num()*10000; //Both arrays get the same numbers
        heap_min->Insert(r);
        heap_max->Insert(r);
    }
    float minSum,maxSum;
    {// Initialise and sum the min heap   
        heap_min->Initialize("Min");
        minSum=heap_min->SumHeap(n,"Min");
        heap_min->Insert(minSum);
    }
    {// Initialise and sum the max heap
        heap_max->Initialize("Max");
        maxSum=heap_max->SumHeap(n,"Max");
        heap_max->Insert(maxSum);      
    }
    cout << "Min Sum: ";  heap_min->Display();
    cout << "Max Sum: ";  heap_max->Display(); 

    if(minSum>maxSum){ cout << "Min Sum is greater than Max Sum" << endl; }
    else if(minSum<maxSum){ cout << "Max Sum is greater than Min Sum" << endl; }
    else{ cout << "Min Sum and Max Sum are equal" << endl; }

    delete heap_min;
    delete heap_max; 
    
    //Wait for user input before exiting
    {
        cout<<endl<<"Press any key to exit...";
        cin.ignore();  
        cin.get(); 
    }

    return 0;
}
