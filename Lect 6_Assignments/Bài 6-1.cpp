#include<iostream>
#include<vector>
using namespace std;

// Định nghĩa cấu trúc Node của cây nhị phân tìm kiếm (BST)
struct Node {
    int data;       // Giá trị của nút
    Node* left;     // Con trái
    Node* right;    // Con phải

    // Khởi tạo nút với giá trị x
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    // Hàm chèn một phần tử vào cây BST
    Node* insert(Node* root, int x) {
        if (root == nullptr) {
            return new Node(x); // Nếu nút gốc rỗng, tạo nút mới
        } else if (x < root->data) {
            root->left = insert(root->left, x);  // Chèn vào cây con bên trái
        } else {
            root->right = insert(root->right, x); // Chèn vào cây con bên phải
        }
        return root;
    }

    // Hàm tìm nút thay thế (nút nhỏ nhất trong cây con bên phải)
    Node* alternateNode(Node* curr) {
        curr = curr->right;
        while (curr != nullptr && curr->left != nullptr) {
            curr = curr->left; // Duyệt đến nút nhỏ nhất bên phải
        }
        return curr;
    }

    // Hàm xóa một phần tử khỏi cây BST
    Node* del(Node* root, int x) {
        if (root == nullptr) {
            return root; // Nếu cây rỗng, không có gì để xóa
        }

        // Nếu giá trị nhỏ hơn nút gốc, tìm trong cây con bên trái
        if (x < root->data) {
            root->left = del(root->left, x);
        }
        // Nếu giá trị lớn hơn nút gốc, tìm trong cây con bên phải
        else if (x > root->data) {
            root->right = del(root->right, x);
        }
        // Nếu tìm thấy nút cần xóa
        else {
            // Trường hợp 1: Nút có 1 hoặc không có con
            if (root->right == nullptr) {
                Node* tmp = root->left;
                delete root;
                return tmp;
            } else if (root->left == nullptr) {
                Node* tmp = root->right;
                delete root;
                return tmp;
            }
            // Trường hợp 2: Nút có cả hai con
            else {
                Node* tmp = alternateNode(root);  // Tìm nút thay thế
                root->data = tmp->data;  // Gán giá trị thay thế
                root->right = del(root->right, tmp->data);  // Xóa nút thay thế
            }
        }
        return root;
    }

    // Duyệt cây theo thứ tự Inorder
    void inOrder(Node* root) {
        if (root != nullptr) {
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }
    }

    // Duyệt cây theo thứ tự Preorder
    void preOrder(Node* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    // Duyệt cây theo thứ tự Postorder
    void postOrder(Node* root) {
        if (root != nullptr) {
            postOrder(root->left);
            postOrder(root->right);
            cout << root->data << " ";
        }
    }
};

int main() {
    Node* root = nullptr; // Khởi tạo cây rỗng
    BST myBST;

    cout << "Cac phan tu cua cay truoc khi chen (2, 1, 10, 6, 3, 8, 7, 13, 20):" << endl;
    vector<int> a = {2, 1, 10, 6, 3, 8, 7, 13, 20}; // Mảng chứa các phần tử của cây ban đầu
    for (int i : a) {
        root = myBST.insert(root, i); // Chèn vào cây
    }

    // In thứ tự duyệt cây
    cout << "Duyet cay theo thu tu inorder, preorder, postorder:" << endl;
    myBST.inOrder(root);
    cout << endl;
    myBST.preOrder(root);
    cout << endl;
    myBST.postOrder(root);
    cout << endl;

    cout << endl;

    cout << "Cay sau khi chen them phan tu (14, 0, 35):" << endl;
    vector<int> new_a = {14, 0, 35}; // Mảng chứa phần tử chèn thêm vào cây
    for (int i : new_a) {
        root = myBST.insert(root, i); // Chèn thêm phần tử vào cây
    }

    // In thứ tự duyệt cây
    cout << "Duyet cay theo thu tu inorder, preorder, postorder:" << endl;
    myBST.inOrder(root);
    cout << endl;
    myBST.preOrder(root);
    cout << endl;
    myBST.postOrder(root);
    cout << endl;

    cout << endl;

    cout << "Cay sau khi xoa phan tu (6, 13, 35):" << endl;
    vector<int> delete_a{6, 13, 35}; // Mảng chứa phần tử bị xóa
    for (int i : delete_a) {
        root = myBST.del(root, i); // Xóa phần tử khỏi cây
    }

    // In thứ tự duyệt cây
    cout << "Duyet cay theo thu tu inorder, preorder, postorder:" << endl;
    myBST.inOrder(root);
    cout << endl;
    myBST.preOrder(root);
    cout << endl;
    myBST.postOrder(root);
    cout << endl;

    return 0;
}
