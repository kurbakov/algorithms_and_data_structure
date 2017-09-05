// Solution from HackerRank
// Binary Search Tree : Lowest Common Ancestor

#include<vector>

typedef struct Node
{
   int data;
   Node *left;
   Node *right;
}node;

bool FindPath(Node *root, std::vector<Node*>& path, int k)
{
    // base case
    if (root == nullptr) return false;
 
    // Store this node in path vector. The node will be removed if
    // not in path from root to k
    path.push_back(root);
 
    // See if the k is same as root's key
    if (root->data == k){
        return true;
    }
 
    // Check if k is found in left or right sub-tree
    if ((root->left && FindPath(root->left, path, k)) || (root->right && FindPath(root->right, path, k))){
        return true;
    }
 
    // If not present in subtree rooted with root, remove root from
    // path[] and return false
    path.pop_back();
    return false;
}


Node *lca(Node *root, int v1,int v2)
{
    // to store paths to n1 and n2 from the root
    std::vector<Node*> path1, path2;
 
    // Find paths from root to n1 and root to n1. If either n1 or n2
    // is not present, return -1
    if ( !FindPath(root, path1, v1) || !FindPath(root, path2, v2)){
          return nullptr;
    }
 
    /* Compare the paths to get the first different value */
    int i;
    for (i = 0; i < path1.size() && i < path2.size() ; i++){
        if (path1[i] != path2[i]){
            break;
        }
    }
    return path1[i-1];
}