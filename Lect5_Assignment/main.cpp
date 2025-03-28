#include <iostream>
using namespace std;

// Định nghĩa cấu trúc một node trong cây
struct node {
    int data;      // Giá trị của node
    node* pLeft;   // Con trỏ trỏ đến node con bên trái
    node* pRight;  // Con trỏ trỏ đến node con bên phải
};

// Hàm tạo một node mới
node* makeNode(int x) {
    node* newNode = new node(); // Cấp phát bộ nhớ cho node mới
    newNode->data = x;          // Gán giá trị cho node
    newNode->pLeft = NULL;      // Ban đầu node con trái trỏ đến NULL
    newNode->pRight = NULL;     // Ban đầu node con phải trỏ đến NULL
    return newNode;             // Trả về node vừa tạo
}

// Định nghĩa lớp cây nhị phân
class tree {
public:
    node* root = NULL; // Khởi tạo cây với node gốc là NULL

    // Hàm tìm kiếm node có giá trị x trong cây
    node* find(node* root, int x) {
        if (root == NULL) return root; // Nếu cây rỗng, trả về NULL
        if (root->data == x) return root; // Nếu tìm thấy giá trị, trả về địa chỉ node đó

        node* findInLeft = find(root->pLeft, x); // Tìm giá trị trong cây con bên trái
        if (findInLeft != NULL) return findInLeft; // Nếu tìm thấy trong cây con trái, trả về node đó

        return find(root->pRight, x); // Nếu chưa tìm thấy, tiếp tục tìm trong cây con phải
    }

    // Hàm thêm node con vào cây
    void addChild(int parent, int child) {
        node* parentNode = find(root, parent); // Tìm node cha trong cây
        if (parentNode == NULL) { // Nếu cây rỗng, đặt node cha làm node gốc
            root = makeNode(parent);
            parentNode = root;
        }

        if (parentNode->pLeft == NULL) { // Nếu node con trái trống, thêm vào
            parentNode->pLeft = makeNode(child);
        } else if (parentNode->pRight == NULL) { // Nếu node con phải trống, thêm vào
            parentNode->pRight = makeNode(child);
        } else {
            cout << "Nút cha đã có đủ 2 con" << endl; // Nếu node cha đã có đủ 2 con, in thông báo
        }
    }

    // Hàm tính chiều cao của cây
    int height(node* root) {
        if (root == NULL) return -1; // Nếu cây rỗng, chiều cao là -1

        int leftHeight = height(root->pLeft);  // Chiều cao của cây con trái
        int rightHeight = height(root->pRight); // Chiều cao của cây con phải

        return max(leftHeight, rightHeight) + 1; // Chiều cao của cây là max của hai cây con +1
    }

    // Duyệt cây theo thứ tự trước (PreOrder)
    void printPreOrder(node* root) {
        if (root == nullptr) return; // Nếu cây rỗng, kết thúc
        cout << root->data << " "; // In giá trị node hiện tại
        printPreOrder(root->pLeft); // Đệ quy duyệt cây con trái
        printPreOrder(root->pRight); // Đệ quy duyệt cây con phải
    }

    // Duyệt cây theo thứ tự sau (PostOrder)
    void printPostOrder(node* root) {
        if (root == nullptr) return; // Nếu cây rỗng, kết thúc
        printPostOrder(root->pLeft); // Đệ quy duyệt cây con trái
        printPostOrder(root->pRight); // Đệ quy duyệt cây con phải
        cout << root->data << " "; // In giá trị node sau khi duyệt các node con
    }

    // Hàm kiểm tra xem cây có phải cây nhị phân hợp lệ không
    bool isBinaryTree(node* root) {
        if (root == nullptr) return true; // Nếu cây rỗng, mặc định là cây nhị phân

        int childCount = 0; // Biến đếm số node con
        if (root->pLeft) childCount++; // Nếu có node con trái, tăng biến đếm
        if (root->pRight) childCount++; // Nếu có node con phải, tăng biến đếm

        if (childCount > 2) return false; // Nếu có hơn 2 node con, không phải cây nhị phân

        return isBinaryTree(root->pLeft) && isBinaryTree(root->pRight); // Kiểm tra đệ quy cây con
    }

    // Duyệt cây theo thứ tự trung tố (InOrder)
    void printInOrder(node* root) {
        if (root == nullptr) return; // Nếu cây rỗng, kết thúc

        if (!isBinaryTree(root)) { // Nếu không phải cây nhị phân, thông báo lỗi
            cout << "NOT BINARY TREE" << endl;
            return;
        }
        printInOrder(root->pLeft); // Đệ quy duyệt cây con trái
        cout << root->data << " "; // In giá trị node
        printInOrder(root->pRight); // Đệ quy duyệt cây con phải
    }
};

int main() {
    tree tree; // Khởi tạo một cây nhị phân
    int M, N;
    cin >> M >> N; // Nhập số lượng node và số lượng quan hệ cha - con

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b; // Nhập cặp giá trị cha - con
        tree.addChild(a, b); // Thêm vào cây
    }

    cout << tree.height(tree.root) << endl; // In ra chiều cao của cây
    tree.printPreOrder(tree.root); // In ra kết quả duyệt PreOrder
    cout << endl;
    tree.printPostOrder(tree.root); // In ra kết quả duyệt PostOrder
    cout << endl;
    tree.printInOrder(tree.root); // In ra kết quả duyệt InOrder
    return 0;
}
