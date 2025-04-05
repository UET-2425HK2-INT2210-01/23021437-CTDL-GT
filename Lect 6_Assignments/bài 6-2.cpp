#include<iostream>
#include<vector>
using namespace std;

class MaxHeap {
public:
    vector<int> heap; // Mảng động để lưu trữ phần tử của heap

    // Hàm đẩy phần tử lên để duy trì tính chất Max Heap
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]); // Đổi chỗ nếu con lớn hơn cha
                index = parent;
            } else {
                break; // Dừng lại nếu đã đúng thứ tự
            }
        }
    }

    // Hàm đẩy phần tử xuống để duy trì tính chất Max Heap
    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1; // Vị trí con trái
            int right = 2 * index + 2; // Vị trí con phải
            int largest = index;

            // Kiểm tra nếu con trái lớn hơn cha
            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            // Kiểm tra nếu con phải lớn hơn cha/con trái
            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }
            // Nếu cần đổi chỗ, thực hiện swap và tiếp tục xuống dưới
            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break; // Dừng lại nếu đúng thứ tự
            }
        }
    }

    // Chèn một phần tử mới vào heap
    void insert(int value) {
        heap.push_back(value); // Thêm vào cuối
        heapifyUp(heap.size() - 1); // Sắp xếp lại heap từ dưới lên
    }

    // Xóa một phần tử khỏi heap
    void del(int value) {
        int size = heap.size();
        for (int i = 0; i < size; i++) {
            if (heap[i] == value) { // Tìm phần tử cần xóa
                heap[i] = heap.back(); // Thay thế bằng phần tử cuối cùng
                heap.pop_back(); // Xóa phần tử cuối
                heapifyDown(i); // Sắp xếp lại heap từ trên xuống
                break;
            }
        }
    }

    // In ra các phần tử trong heap dưới dạng mảng
    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap heap;

    // Mảng chứa các số ban đầu
    vector<int> nums = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int num : nums) {
        heap.insert(num); // Chèn từng số vào heap
    }

    cout << "Cay max heap ban dau: ";
    heap.printHeap();

    // Chèn thêm các giá trị vào heap
    vector<int> new_values = {14, 0, 35};
    for (int val : new_values) {
        heap.insert(val);
    }

    cout << "Cay max heap sau khi chen 14, 0, 35: ";
    heap.printHeap();

    // Xóa một số phần tử khỏi heap
    vector<int> delete_values = {6, 13, 35};
    for (int val : delete_values) {
        heap.del(val);
    }

    cout << "Cay max heap sau khi xoa 6, 13, 35: ";
    heap.printHeap();

    return 0;
}
