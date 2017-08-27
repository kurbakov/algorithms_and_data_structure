#include <iostream>

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
    void delete_node(Node<T>*, Node<T>*);

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
    void BinaryTree<T>::delete_node(Node<T>* parent, Node<T>* del){

        // botth are null
        if(del->left == nullptr && del->right == nullptr){
            if(parent->left == del) parent->left = nullptr;
            else parent->right = nullptr;
            delete del;
            Size--;
        }
        // only left is null
        else if(del->left == nullptr){
            if(parent->left == del) parent->left = del->right;
            else parent->right = del->right;
            delete del;
            Size--;
        }
        // only right is null
        else if(del->right == nullptr){
            if(parent->left == del) parent->left = del->left;
            else parent->right = del->left;
            delete del;
            Size--;
        }
        // non is null
        else{
            // Logic: 
            // 1. find the successor
            Node<T>* s = del->right;
            while(s->left != nullptr) s = s->left;
            
            // 2. swap the values between del and successor
            del->data = s->data;

            // 3. find the parent of successor
            Node<T>* p = del;
            if(p->right->data == s->data){
                delete_node(p, s);
                return;
            }
            p = p->right;
            while(p->left->data != s->data) p=p->left;
            
            // 4. call the delete function again
            delete_node(p, s);
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
            // need to rewrite!!!
            if(Root->left == nullptr && Root->right == nullptr){
                delete Root;
                Root = nullptr;
                Size = 0;
            }
            else if(Root->left == nullptr){
                Node<T>* del = Root;
                Root = Root->right;
                delete del;
                Size--;
            }
            else if(Root->right == nullptr){
                Node<T>* del = Root;
                Root = Root->left;
                delete del;
                Size--;
            }
            else{
                Node<T>* s = Root->right;
                while(s->left != nullptr) s = s->left;

                Root->data = s->data;
                Node<T>* p = Root;
                if(p->right->data != s->data){
                    p = p->right;
                    while(p->left != nullptr){
                        if(p->left->data == s->data) break;
                        else p = p->left;
                    }
                }
                delete_node(p, s);
            }
            return true;
        }

        Node<T>* cur = Root;
        while(cur != nullptr){
            // check kids
            if(v > cur->data && cur->right != nullptr){
                if(cur->right->data == v) break;
            }
            if(v < cur->data && cur->left != nullptr){
                if(cur->left->data == v) break;
            }

            if(v > cur->data) cur = cur->right;
            if(v < cur->data) cur = cur->left;
        }

        if(cur == nullptr) return false;

        if(cur->left->data == v){
            delete_node(cur, cur->left);
        }
        else{
            delete_node(cur, cur->right);
        }
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
    bt.insert(8);
    bt.insert(3);
    bt.insert(9);

    bt.erase(15);

    bt.print();

    return 0;
}