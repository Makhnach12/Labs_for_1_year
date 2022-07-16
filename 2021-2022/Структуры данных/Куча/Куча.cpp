#include <iostream>
#include <vector>
using namespace std;

struct heap {
    vector <int> arr;

    int sift_up(int index) {
        while (index) {
            if (arr[index / 2 - 1 + index % 2] < arr[index]) {
                swap(arr[index / 2 - 1 + index % 2], arr[index]);
                index = index / 2 - 1 + index % 2;
            }
            else
                return index;
        }
        return 0;
    }

    int sift_down(int* arr, int n, int index)
    {
        while (2 * index + 2 < n){
            if (arr[2 * index + 1] > arr[index] && arr[2 * index + 1] > arr[2 * index + 2]){
                swap(arr[index], arr[2 * index + 1]);
                index = 2 * index + 1;
            }
            if (arr[2 * index + 2] > arr[index] && arr[2 * index + 1] < arr[2 * index + 2]){
                swap(arr[index], arr[2 * index + 2]);
                index = 2 * index + 2;
            }
            if (arr[index] > arr[2 * index + 1] && arr[index] > arr[2 * index + 2]) 
                return index; 
        }
        if (arr[index] < arr[n - 1] && 2 * index + 2 == n){ 
            swap(arr[n - 1], arr[index]); 
            index = n - 1;
        }
        return index;
    }

    void show_heap() {
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << ' ';
    }

};

int main(){
    int num, num_elem, op_num, add_mem, num_in_heap;
    heap heap;
    cin >> num_elem;
    for (int j = 0; j < num_elem; ++j) {
        cin >> num;
        heap.arr.push_back(num);
    }
    cin >> op_num;
    int* new_order = new int[op_num];
    int new_idx = op_num;
    for (; op_num > 0; --op_num){
        cin >> num_in_heap >> add_mem;
        heap.arr[num_in_heap - 1] += add_mem;
        new_order[new_idx - op_num] = heap.sift_down(num_in_heap - 1);
    }
    for (int i = 0; i < new_idx; i++)
        cout << new_order[i] + 1 << "\n";
    heap.show_heap();
    return 0;
}



