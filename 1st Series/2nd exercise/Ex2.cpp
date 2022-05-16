#include <iostream>
#include <random>
#include <functional>

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
            int i = ++CurrentSize; //Get current size incremented by 1 (new leaf)
            while(i != 1 && arr[i/2] > x){ 
                arr[i] = arr[i/2];
                i /= 2;
            }
            arr[i] = x; 
            return x;
        }

        void Display(){
            for(int i = 1; i <= CurrentSize; i++){
                cout << arr[i] << endl;
            }
            cout << endl;
        }

    
};

int main(){
    //rng 
    default_random_engine generator;
    uniform_int_distribution<int> data_element_distribution(0, 30);
    auto random_num = std::bind(data_element_distribution, generator);
    /*
    default_random_engine generator;
    chi_squared_distribution<float> my_distribution(0.5);
    auto random_num = std::bind(my_distribution, generator);*/

    cout << "Enter the amount of elements: ";
    int n;
    cin >> n;
    Heap *heap_min = new Heap(n);
    Heap *heap_max = new Heap(n);
    for (int i = 0; i < n; i++){
        heap_min->Insert(random_num());
    }
    heap_min->Display();

    //system("pause");
    return 0;
};
