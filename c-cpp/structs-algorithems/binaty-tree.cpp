#include <iostream>

template<typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insertHelper(T data, Node* node) {
        if (data < node->data) {
            if (node->left != nullptr) {
                insertHelper(data, node->left);
            } else {
                node->left = new Node(data);
            }
        } else {
            if (node->right != nullptr) {
                insertHelper(data, node->right);
            } else {
                node->right = new Node(data);
            }
        }
    }

    void inorderTraversalHelper(Node* node) {
        if (node != nullptr) {
            inorderTraversalHelper(node->left);
            std::cout << node->data << " ";
            inorderTraversalHelper(node->right);
        }
    }

    void deleteTreeHelper(Node* node) {
        if (node != nullptr) {
            deleteTreeHelper(node->left);
            deleteTreeHelper(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(T data) {
        if (root == nullptr) {
            root = new Node(data);
        } else {
            insertHelper(data, root);
        }
    }

    void inorderTraversal() {
        inorderTraversalHelper(root);
    }

    ~BinaryTree() {
        deleteTreeHelper(root);
    }
};

int main ()
{
    BinaryTree<int> tree;
    for (size_t i = 0; i < 10; i++)
    {
        tree.insert(i);
    }
    
    tree.inorderTraversal();
}