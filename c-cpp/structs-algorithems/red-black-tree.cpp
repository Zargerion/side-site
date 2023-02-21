#include <iostream>

enum Color { RED, BLACK };

template <typename T>
struct Node
{
    T data;
    Color color;
    Node<T> *left, *right, *parent;

    Node(T data)
    {
        this->data = data;
        color = RED;
        left = right = parent = nullptr;
    }
};

template <typename T>
class RedBlackTree
{
private:
    Node<T> *root;

    void insertFixup(Node<T> *node)
    {
        while (node != root && node->parent->color == RED)
        {
            if (node->parent == node->parent->parent->left)
            {
                Node<T> *uncle = node->parent->parent->right;
                if (uncle != nullptr && uncle->color == RED)
                {
                    node->parent->color = BLACK;
                    uncle->color = BLACK;
                    node->parent->parent->color = RED;
                    node = node->parent->parent;
                }
                else
                {
                    if (node == node->parent->right)
                    {
                        node = node->parent;
                        rotateLeft(node);
                    }
                    node->parent->color = BLACK;
                    node->parent->parent->color = RED;
                    rotateRight(node->parent->parent);
                }
            }
            else
            {
                Node<T> *uncle = node->parent->parent->left;
                if (uncle != nullptr && uncle->color == RED)
                {
                    node->parent->color = BLACK;
                    uncle->color = BLACK;
                    node->parent->parent->color = RED;
                    node = node->parent->parent;
                }
                else
                {
                    if (node == node->parent->left)
                    {
                        node = node->parent;
                        rotateRight(node);
                    }
                    node->parent->color = BLACK;
                    node->parent->parent->color = RED;
                    rotateLeft(node->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void removeFixup(Node<T> *node, Node<T> *parent)
    {
        while (node != root && (node == nullptr || node->color == BLACK))
        {
            if (node == parent->left)
            {
                Node<T> *sibling = parent->right;
                if (sibling->color == RED)
                {
                    sibling->color = BLACK;
                    parent->color = RED;
                    rotateLeft(parent);
                    sibling = parent->right;
                }
                if ((sibling->left == nullptr || sibling->left->color == BLACK) &&
                    (sibling->right == nullptr || sibling->right->color == BLACK))
                {
                    sibling->color = RED;
                    node = parent;
                    parent = node->parent;
                }
                else
                {
                    if (sibling->right == nullptr || sibling->right->color == BLACK)
                    {
                        sibling->left->color = BLACK;
                        sibling->color = RED;
                        rotateRight(sibling);
                        sibling = parent->right;
                    }
                    sibling->color = parent->color;
                    parent->color = BLACK;
                    sibling->right->color = BLACK;
                    rotateLeft(parent);
                    node = root;
                    break;
                }
            }
            else
            {
                Node<T> *sibling = parent->left;
                if (sibling->color == RED)
                {
                    sibling->color = BLACK;
                    parent->color = RED;
                    rotateRight(parent);
                    sibling = parent->left;
                }
                if ((sibling->right == nullptr || sibling->right->color == BLACK) &&
                    (sibling->left == nullptr || sibling->left->color == BLACK))
                {
                    sibling->color = RED;
                    node = parent;
                    parent = node->parent;
                }
                else
                {
                    if (sibling->left == nullptr || sibling->left->color == BLACK)
                    {
                        sibling->right->color = BLACK;
                        sibling->color = RED;
                        rotateLeft(sibling);
                        sibling = parent->left;
                    }
                    sibling->color = parent->color;
                    parent->color = BLACK;
                    sibling->left->color = BLACK;
                    rotateRight(parent);
                    node = root;
                    break;
                }
            }
        }
        if (node != nullptr)
        {
            node->color = BLACK;
        }
    }

    void rotateLeft(Node<T> *node)
    {
        Node<T> *right = node->right;
        node->right = right->left;
        if (right->left != nullptr)
        {
            right->left->parent = node;
        }
        right->parent = node->parent;
        if (node->parent == nullptr)
        {
            root = right;
        }
        else if (node == node->parent->left)
        {
            node->parent->left = right;
        }
        else
        {
            node->parent->right = right;
        }
        right->left = node;
        node->parent = right;
    }

    void rotateRight(Node<T> *node)
    {
        Node<T> *left = node->left;
        node->left = left->right;
        if (left->right != nullptr)
        {
            left->right->parent = node;
        }
        left->parent = node->parent;
        if (node->parent == nullptr)
        {
            root = left;
        }
        else if (node == node->parent->right)
        {
            node->parent->right = left;
        }
        else
        {
            node->parent->left = left;
        }
        left->right = node;
        node->parent = left;
    }

    Node<T>* findSuccessor(Node<T> *node)
    {
        if (node->right != nullptr)
        {
            Node<T> *successor =node->right;
            while (successor->left != nullptr)
            {
                successor = successor->left;
            }
            return successor;
        }

        Node<T> *parent = node->parent;
        while (parent != nullptr && node == parent->right)
        {
            node = parent;
            parent = parent->parent;
        }
        return parent;
    }

    void inorderTraversal(Node<T> *node)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    void deleteTree(Node<T> *node)
    {
        if (node != nullptr)
        {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    RedBlackTree()
    {
        root = nullptr;
    }

    Node<T>* search(T data)
    {
        Node<T> *node = root;
        while (node != nullptr)
        {
            if (data == node->data)
            {
                return node;
            }
            if (data < node->data)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        return nullptr;
    }

    void insert(T data)
    {
        Node<T> *node = new Node<T>(data);
        Node<T> *parent = nullptr;
        Node<T> *current = root;
        while (current != nullptr)
        {
            parent = current;
            if (node->data < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        node->parent = parent;
        if (parent == nullptr)
        {
            root = node;
        }
        else if (node->data < parent->data)
        {
            parent->left = node;
        }
        else
        {
            parent->right = node;
        }
        insertFixup(node);
    }

    void remove(T data)
    {
        Node<T> *node = search(data);
        if (node == nullptr)
        {
            return;
        }
        Node<T> *deleted;
        if (node->left == nullptr || node->right == nullptr)
        {
            deleted = node;
        }
        else
        {
            deleted = findSuccessor(node);
        }
        Node<T> *subtree = deleted->left != nullptr ? deleted->left : deleted->right;
        if (subtree != nullptr)
        {
            subtree->parent = deleted->parent;
        }
        if (deleted->parent == nullptr)
        {
            root = subtree;
        }
        else if (deleted == deleted->parent->left)
        {
            deleted->parent->left = subtree;
        }
        else
        {
            deleted->parent->right = subtree;
        }
        if (deleted != node)
        {
            node->data = deleted->data;
        }
        if (deleted->color == BLACK)
        {
            removeFixup(subtree, deleted->parent);
        }
        delete deleted;
    }

    void inorder()
    {
        inorderTraversal(root);
    }

    ~RedBlackTree()
    {
        deleteTree(root);
    }
};

int main()
{
    RedBlackTree<int> RBTree;
    RBTree.insert(10);
    RBTree.insert(9);
    RBTree.insert(11);
    RBTree.insert(12);
    RBTree.insert(13);
    RBTree.insert(14);
    RBTree.insert(15);
    RBTree.remove(9);
    RBTree.remove(12);
    RBTree.inorder();

}