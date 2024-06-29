#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;
    node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};
vector<vector<int>> BFS(node *root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0; i<size; i++){
            node *nd = q.front();
            q.pop();
            if(nd->left != NULL) q.push(nd->left);
            if(nd->right != NULL) q.push(nd->right);
            level.push_back(nd->data);
        }
        ans.push_back(level);
    }
    return ans;
}
vector<int> stackpreorder(node *root){
    vector<int> stpre;
    if(root == NULL) return stpre;
    stack<node*> st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        stpre.push_back(root->data);
        if(root->right != NULL){
            st.push(root->right);
        }
        if(root->left != NULL){
            st.push(root->left);
        }
    }
    return stpre;
}
void inorder(node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node *root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int maxDepth(node *root){
    if(root == NULL) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->left);
    return 1 + max(l, r);
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    root->left->right->right = new node(7);
    root->left->right->right->right = new node(8);
    cout << "Preorder Travarse\n";
    preorder(root);
    cout << "\nInorder Travarse\n";
    inorder(root);
    cout << "\nPostorder Travarse\n";
    postorder(root);
    cout << "\nBFS Travarse\n";
    vector<vector<int>> ans = BFS(root);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
    }
    cout << "\nStackInorder Travarse\n";
    vector<int> ans2 = stackpreorder(root);
    for(auto ele: ans2) cout << ele << " ";
    cout << "\nMax Depth\n";
    cout << maxDepth(root);
}