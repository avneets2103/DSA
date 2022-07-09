#include<iostream>
#include<queue>
using namespace std;

// [1.] Class making
template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<int>* left;
    BinaryTreeNode<int>* right;
    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

//[2.] Printing normally

//Process:
//Here it is mandatory to chedk of root==NULL as there can be a case where root=NULL whenwe are using recursion, as the nodes can actually store NULL value.
//Also we have to chck if the root->left and root->right must not be NULL as if true then we cant print data for NULL or NULL->data is undefined thus throws an error.
//Then at the end we use recurrsion, to print the same pattern for left and right subtree.

void print_binary_tree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data<<" ";
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data<<" ";
    }
    cout<<endl;
    print_binary_tree(root->left);
    print_binary_tree(root->right);
}

//[3.] Taking input (not level wise)

//Process:
//Here we are denoting (no data to ennter in this node) or (NULL node) as user input of -1.
//For this case it returns NULL 
//Then we do the same to get another node made for the left and for the right using recursion in the same way.
//Then we link the root to its left sub-tree and right sub-tree
//We finally return root as the return value

//Problem here:
//Here the order of input will be like:
//root --> left --> right order which works with the knowledge of recursion thus we want to turn this into level wise input so tht it is easy for user to enter data.

BinaryTreeNode<int>* takeInput(){
    cout<<"Enter data:"<<endl;
    int root_data;
    cin>>root_data;
    if(root_data==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(root_data);
    BinaryTreeNode<int>* left_node=takeInput();
    BinaryTreeNode<int>* right_node=takeInput();
    
    root->left=left_node;
    root->right=right_node;
    return root;
}

//[4.] Taking input (level wise) 

//Process:
//First we make a queue for storing the nodes we add
//Once our queue gets empty the work stops
//Now we pop the top most or front element in the queue and use it first to get its childrenn first and also push them in the queue             
//Thus we take the right node in and link it and add to queue and same for right and this will repeat till the loop works fine.
//NOTE: We arent using any recursion here

BinaryTreeNode<int>* take_input_level_wise(){
    int root_data;
    cout<<"Enter data"<<endl;
    cin>>root_data;
    if(root_data==-1){
        return NULL;
    }
    queue<BinaryTreeNode<int>*> unseen_nodes;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(root_data);
    unseen_nodes.push(root);
    while(unseen_nodes.size()!=0){
        BinaryTreeNode<int>* front = unseen_nodes.front();
        unseen_nodes.pop();

        cout<<"Enter the left children of "<<front->data<<endl;
        int left_data;
        cin>>left_data;
        if(left_data!=-1){
            BinaryTreeNode<int>* left_node=new BinaryTreeNode<int>(left_data);
            front->left=left_node;
            unseen_nodes.push(left_node);
        }
        
        int right_data;
        cout<<"Enter the right children of "<<front->data<<endl;
        cin>>right_data;
        if(right_data!=-1){
            BinaryTreeNode<int>* right_node=new BinaryTreeNode<int>(right_data);
            front->right=right_node;
            unseen_nodes.push(right_node);
        }
    }
    return root;
}

//[5.] Printing Level wise

//Process:
//We again use a queue here and keep root in it, then using a while loop we traverse in the tree
//We DONT use recursion here 
//Rather we use queue to keep track of things here

void printLevelWise(BinaryTreeNode<int> *root) {
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> unprinted_children;
    unprinted_children.push(root);
    while(unprinted_children.size()!=0){
        BinaryTreeNode<int>* front = unprinted_children.front();
        unprinted_children.pop();
        cout<<front->data<<":L:";
        if(front->left==NULL){
            cout<<-1;
        }
        else{
            cout<<front->left->data;
        }
        cout<<",R:";
        if(front->right==NULL){
            cout<<-1;
        }
        else{
            cout<<front->right->data;
        }
        cout<<endl;
        if(front->left!=NULL){
            unprinted_children.push(front->left);
        }
        if(front->right!=NULL){
            unprinted_children.push(front->right);
        }
    }
}

//[6.] Counting number of nodes
int count_nodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+count_nodes(root->left)+count_nodes(root->right);
}

//[7.] Checking for presence of a specific node
bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    bool ans = false;
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        ans = true;
        return ans;
    }
    ans = isNodePresent(root->left, x) | isNodePresent(root->right, x);
    return ans;
}

//[8.] Height
int height(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int left_height=height(root->left);
    int right_height=height(root->right);
    return 1 + max(left_height,right_height);
}

//[9.] Mirror 


int main(){
    BinaryTreeNode<int>* root = take_input_level_wise();
    print_binary_tree(root);
    return 0;}
