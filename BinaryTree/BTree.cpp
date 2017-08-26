#include <iostream>
#include <iomanip>  

namespace Btree{
template <typename T>
struct Node{
    T data;
    Node* left;
    Node* right;

    Node(T value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

template <class T>
class BinaryTree{
private:
    Node<T>* Root;
    uint64_t Size;

    void pre_order(Node<T>*);
    void post_order(Node<T>*);
    void clear_tree(Node<T>*);
    void delete_node(Node<T>*, T);

public:
    BinaryTree();
    ~BinaryTree();

    bool empty();
    uint64_t get_size();

    bool insert(T);
    bool find(T);
    bool erase(T);

    void print();
};
}; // namespace


namespace Btree{
    template <class T>
    void BinaryTree<T>::pre_order(Node<T>* p)
    {
        if(p == nullptr) return;
        
        std::cout << p->data << "\n";
        pre_order(p->left);
        pre_order(p->right);
    }

    template <class T>
    void BinaryTree<T>::post_order(Node<T>* p) {
        if(p == nullptr) return;
        post_order(p->left);
        post_order(p->right);
        std::cout << p->data << "\n";
    }

    template <class T>
    void BinaryTree<T>::clear_tree(Node<T>* n){
        if(n == nullptr) return;

        clear_tree(n->left);
        clear_tree(n->right);

        delete n;
    }

    template<class T>
    void BinaryTree<T>::delete_node(Node<T>* parent, T v){
        Node<T>* del;
        if(v > parent->data){
            del = parent->right;
        }
        else{
            del = parent->left;
        }

        // botth are null
        if(del->left == nullptr && del->right == nullptr){
            if(v > parent->data) parent->right = nullptr;
            else parent->left = nullptr;
            delete del;
        }
        // only left is null
        else if(del->left == nullptr){
            if(v>parent->data) parent->right = del->right;
            else parent->left = del->right;
            delete del;
        }
        // only right is null
        else if(del->right == nullptr){
            if(v > parent->data) parent->right = del->left;
            else parent->left = del->left;
            delete del;
        }
        // non is null
        else{
            // the case with many conditions
            // I see no sense in coding this part
            // if you are interested
            // feel free to contact me or just check here:
            // http://www.algolist.net/Data_structures/Binary_search_tree/Removal
            // http://www.tech-faq.com/binary-tree-deleting-a-node.html
            // https://msdn.microsoft.com/en-us/library/ms379572(v=vs.80).aspx
        }
        return;
    }

    template <class T>
    BinaryTree<T>::BinaryTree(){
        Root = nullptr;
        Size = 0;
    }

    template <class T>
    BinaryTree<T>::~BinaryTree(){
        clear_tree(Root);
    }

    template <class T>
    bool BinaryTree<T>::empty(){
        return Size == 0;
    }

    template <class T>
    uint64_t BinaryTree<T>::get_size(){
        return Size;
    }

    template <class T>
    bool BinaryTree<T>::insert(T v){
        
        if(Root == nullptr){
            Node<T>* new_node = new Node<T>(v);
            Root = new_node;
            Size++;
            return true;
        }

        Node<T>* cur = Root;
        while(cur!=nullptr){
            if(cur->data == v){return false;}

            else if(v > cur->data){
                if(cur->right == nullptr){
                    Node<T>* new_node = new Node<T>(v);
                    cur->right = new_node;
                    return true;
                }
                else{
                    cur = cur->right;
                }
            }
            else if(v < cur->data){
                if(cur->left == nullptr){
                    Node<T>* new_node = new Node<T>(v);
                    cur->left = new_node;
                    return true;
                }
                else{
                    cur = cur->left;
                }
            }
        }

        return false;
    }

    template <class T>
    bool BinaryTree<T>::find(T v){
        if(Root == nullptr){
            return false;
        }

        Node<T>* cur = Root;
        while(cur != nullptr){
            if(cur->data == v){
                return true;
            }

            if(cur->data > v){
                cur = cur->left;
            }
            else{
                cur = cur->right;
            }
        }

        return false;
    }

    template <class T>
    bool BinaryTree<T>::erase(T v){
        if(Root->data == v){
            delete Root;
            Root = nullptr;
            Size = 0;
            return true;
        }

        Node<T>* cur = Root;
        while(cur != nullptr){
            // check kids
            if(v > cur->value && cur->right != nullptr){
                if(cur->right->data == v) break;
            }
            if(v < cur->value && cur->left != nullptr){
                if(cur->left->data == v) break;
            }

            if(v > cur->data) cur = cur->right;
            if(v < cur->data) cur = cur->left;
        }

        if(cur == nullptr) return false;

        delete_node(cur, v);
        return true;
    }

    template <class T>
    void BinaryTree<T>::print(){
        pre_order(Root);
    }

}; // namespace

int main(){
    Btree::BinaryTree<int> bt;
    bt.insert(10);
    bt.insert(15);
    bt.insert(13);
    bt.insert(17);

    bt.print();

    return 0;
}