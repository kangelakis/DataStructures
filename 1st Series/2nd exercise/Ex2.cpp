#include <iostream>
#include <random>
#include <functional>
using namespace std;


void swap(float &x,float &y){
    float temp = x;
    x = y;
    y = temp;
}

class MinHeap{
    private:

        float*harr;//pointer to array of elemnts
        int capacity;//maximum size of heap   
        int heap_size; //current heap size
        
    public:
    
        MinHeap(int cap){
            heap_size = 0;
            capacity = cap;
            harr = new float[cap];
        }
        void printArray(){
            for(int i=0;i<heap_size;i++){
                cout<<harr[i]<<endl;
            }
            
        }
        void insertKey(float k){
            if(heap_size==capacity){
                cout<<"Overflow error"<<endl;
                return;
            }
            //Insertnew key at end
            heap_size++;
            int i = heap_size - 1;
            harr[i] = k;
            while(i!=0&&harr[parent(i)]>harr[1]){
                swap(harr[i],harr[parent(i)]);
                i = parent(i);
            }
        }
        int parent(int i) {
            return (i - 1) / 2;
        }

        int left(int i) {
            return (2 * i + 1);
        }

        int right(int i) {
            return (2 * i + 2);
        }
        /*void MinHeapify(int i) {
            int l = left(i);
            int r = right(i);
            int smallest = parent(i);
            if (l < heap_size && harr[l] < harr[i])
                smallest = l;
            if (r < heap_size && harr[r] < harr[smallest])
                smallest = r;
            if (smallest != i) {
                swap(harr[i], harr[smallest]);
                MinHeapify(smallest);
            }
        }
        */
    
};

int main(){
    //rng 
    default_random_engine generator;
    chi_squared_distribution<float> my_distribution(0.5);
    auto random_num = std::bind(my_distribution, generator);

    cout << "Enter the amount of elements: ";
    int n;
    cin >> n;
    MinHeap *heap_min = new MinHeap(n);
    for (int i = 0; i < n; i++) {
        heap_min->insertKey(random_num());
    }

    heap_min->printArray();

    //system("pause");
    return 0;
};
