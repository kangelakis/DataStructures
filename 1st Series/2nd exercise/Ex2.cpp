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


        void Initialize(string str){//max array size
            for(int i = CurrentSize/2; i >= 1; i--){
                float p = arr[i];
                int c = 2*i;
                while(c <= CurrentSize){
                    if(str == "Min"){
                        if(c < CurrentSize && arr[c] > arr[c+1]) c++;
                        if(p <= arr[c]) break;
                    }else{
                        if(c < CurrentSize && arr[c] < arr[c+1]) c++;
                        if(p >= arr[c]) break;
                    }
                    arr[c/2] = arr[c];
                    c *= 2;
                }
                arr[c/2] = p;
            }
        }

  
        float Insert(const float &x){
            if(CurrentSize == MaxSize){
                cout << "Heap is full" << endl;
                return -1;
            }
            int i = ++CurrentSize; //Get current size incremented by 1 (new leaf)
           
            arr[i] = x; 
            return x;
        }


        float SumHeap(int n,string str){//max heap
            if(CurrentSize==0){
                cout << "Heap is empty" << endl;
                return -1;
            }
            float sum=0;
            for(int j=0; j<n; j++){
            float y = arr[CurrentSize--];
            int i = 1, ci = 2;
            sum=sum+arr[1];
            if(str=="Max"){
                while(ci <= CurrentSize){
                    if(ci < CurrentSize && arr[ci] < arr[ci+1]) ci++;
                    if (y >= arr[ci]) break;
                    arr[i] = arr[ci];
                    i = ci;
                    ci *= 2;
                }
            }else{
                while(ci <= CurrentSize){
                    if(ci < CurrentSize && arr[ci] > arr[ci+1]) ci++;
                    if (y <= arr[ci]) break;
                    arr[i] = arr[ci];
                    i = ci;
                    ci *= 2;
                }
            
            }
            arr[i] = y;
            }
            return sum;            
        }


        void Display(){
            for(int i = 1; i <= CurrentSize; i++){
                cout << arr[i] << endl;
            }
            cout << endl;
        }
        ~Heap(){
            delete [] arr;
        };
};

int main(){
    //rng 
    /*
    default_random_engine generator;
    uniform_int_distribution<int> data_element_distribution(0, 100);
    auto random_num = std::bind(data_element_distribution, generator);
    */
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
        r=random_num()*10000;
        heap_min->Insert(r);
        heap_max->Insert(r);
    }
    heap_min->Initialize("Min");
    heap_max->Initialize("Max");
    float maxSum=heap_max->SumHeap(n,"Max");
    float minSum=heap_min->SumHeap(n,"Min");
    heap_min->Insert(minSum);
    cout << "Min Sum: ";
    heap_min->Display();
    heap_max->Insert(maxSum);
    cout <<"Max Sum: ";
    heap_max->Display();
    if(minSum>maxSum){
        cout << "Min Sum is greater than Max Sum" << endl;
    }else if(minSum<maxSum){
        cout << "Max Sum is greater than Min Sum" << endl;
    }else{
        cout << "Min Sum and Max Sum are equal" << endl;
    }
    delete heap_min;
    delete heap_max;
    system("pause");
    
    return 0;
}
