#include <bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    struct Node *left , *right;
}*root;

Node *Build_Node(int data){
    Node *node = (struct Node *)malloc(sizeof(struct Node));;
    node->data = data;
    node->left = node->right = NULL;

    return node;
}


Node *remove_node(Node *root){
    if(root == NULL || root->data == INT_MAX){
        return NULL;
    }
    root->left = remove_node(root->left);
    root->right = remove_node(root->right);

    return root;
}

Node *Insert_Node(queue<Node *>&q , int value , Node *root){
    Node *new_node = Build_Node(value);
    if(root == NULL)
        root = new_node;
    else if (q.front()->left == NULL){
        q.front()->left = new_node;
    }
    else{
        q.front()->right = new_node;
        q.pop();
    }
    if(value != INT_MAX)
        q.push(new_node);
    return root;
}

bool Search(Node *root , int target ,vector<int>&path){
    if(root == NULL) return false;

    if(root->data == target){
        path.push_back(root->data);
        return true;
    }
    bool fic = Search(root->left , target , path);
    if(fic){
        path.push_back(root->data);
        return true;
    }
    fic = Search(root->right , target , path);
    if(fic){
        path.push_back(root->data);
        return true;
    }

    return false;
}


// int depth(Node *root , int dep){
//     if(root == NULL)
//         return 0;
    
//     return max(1  +depth(root->left ,dep) , 1 + depth(root->right , dep));
// }

// void FindLeft(Node  *root, int &answer ,int &depth, int level){
//     if(root == NULL){
//         return ;
//     }
//     if(depth < level){
//         depth = level;
//         answer = root->data;
//     }
//     // if(root->left == NULL  root->right == NULL){
//     //     answer = root->data; 
//     //     return;
//     // }
//     FindLeft(root->left ,answer , depth , level + 1);
//     FindLeft(root->right , answer , depth , level + 1);

//     return ;
// }

// void Findans(Node *root){
//     if(root == NULL) return;
//     queue<Node *>q;
//     q.push(root);
//     while(!q.empty()){
//         int n = q.size();
//         vector<int>parent , current;
//         for(int i=1; i<=n; i++){
//             Node *temp = q.front();
//             q.pop();
            // if(i == n) cout<<temp->data<<" ";
//            
//             if(temp->left != NULL){
//                 q.push(temp->left);
//             } 
//             if(temp->right != NULL){
//                 q.push(temp->right);
//             } 
//         }
//     }

//     return;
// }

void PostOrder(Node *root){
    if(root == NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
    
}

// void DeleteNode(Node *&root , int value){
//     if(root == NULL)
//         return ;
//     if(root->data > value){
//         DeleteNode(root->left , value);
//     }
//     else if(root->data < value)
//         DeleteNode(root->right , value);
//     else{
//         if(root->left == NULL && root->right == NULL){
//             delete root;
//             root = NULL;
//         }
//         else if(root->left && root->right){
//             Node *new_node = root->left;
//             while(new_node->right != NULL){
//                 new_node = new_node->right;
//             }
//             root->data = new_node->data;
//             DeleteNode(root->left , new_node->data);
//         }
//         else{
//             Node *child = (root->left) ? root->left : root->right;
//             Node *delete_node = root;

//             root =child;
//             delete delete_node;
//         }
//     }
// }

// int  SolveAnswer(Node *root , int &answer){
//     if(root == NULL)
//         return 0;
//     int left = SolveAnswer(root->left , answer);
//     int right = SolveAnswer(root->right , answer);

//     int temp = max(max(left , right) + root->data , root->data);
//     int ans =  max(temp , left + right + root->data);

//     answer = max(ans , answer);

//     return temp;

// }

// Node *insert_node(int temp, Node *root){
//     Node *new_node = Build_Node(temp);
//     if(root == NULL)
//         return new_node;

//     if(temp > root->data){
//         root->right = insert_node(temp , root->right);
//     }
//     else{
//         root->left = insert_node(temp , root->left);
//     }
//     return root;
// }

// void Minimum(Node *root , int &answer){
//     if(root == NULL)
//         return ;
//     if(root->left == NULL){
//         answer = root->data;
//         return;
//     }
//     Minimum(root->left , answer);
// }

// void Maximum(Node *root , int &answer){
//     if(root == NULL)
//         return;
//     if(root->right == NULL){
//         answer = root->data;
//         return ;
//     }
//     Maximum(root->right , answer);
// }


// Node *CovertFromPreorder(vector<int>preorder){
//     if(preorder.size() == 0)
//         return NULL; 
//     Node *temp = Build_Node(preorder[0]);
//     if(preorder.size() == 1)
//         return temp;
//     vector<int>v1, v2;
//     for(int i=0; i<preorder.size(); i++){
//         if(preorder[i] < temp->data)
//             v1.push_back(preorder[i]);
//         else if(preorder[i] > temp->data)
//             v2.push_back(preorder[i]);
//     }
//     temp->left = CovertFromPreorder(v1);
//     temp->right = CovertFromPreorder(v2);

//     return temp;

// }

// void FindMode(Node *root , int &max , int &max_fre, int &curr_freq, int &curr_val){
//     if(root == NULL)
//         return ;
//     FindMode(root->left , max , max_fre , curr_freq , curr_val);

//     if(curr_val == root->data)
//         curr_freq++;
//     else{
//         curr_freq = 1;
//     }

//     if(curr_freq > max_fre){
//         max_fre = curr_freq;
//         max = root->data;
//     }
//     curr_val = root->data;

//     FindMode(root->right , max, max_fre , curr_freq , curr_val);

//     return ;
// }

// void FindMode(Node *root){
//     int max, max_fre = 0, curr_freq = 0;
//     int curr_val = INT_MIN;
//     FindMode(root , max , max_fre , curr_freq , curr_val);

//     cout<<max;
// }

// void deleteTree(Node *root){
//     if(root == NULL)
//         return ;
//     deleteTree(root->left);
//     deleteTree(root->right);

//     delete root;
// }

bool checkForBST(Node *root , int min , int max){
    if(root == NULL)
        return 1;
    if(root->data != INT_MIN && root->data <= min){
        return 0;
    }
    if(root->data != INT_MAX && root->data >= max)
        return 0;

    return checkForBST(root->left , min , root->data ) && checkForBST(root->right , root->data  , max);
}

void Build_Tree(){
    // vector<int>vec; int temp;
    // while(cin>>temp){
    //     root = insert_node(temp , root);
    // }
    


    int t ; cin>>t;
    while(t--){
    root = NULL;
    // int n ,m; cin>>n>>m;
    // int temp; cin>>temp;
    queue<Node *>q; string temp;
    // int t; cin>>t;
    while(1){
        cin>>temp;
        if(temp == "-1")
            break;
        if(temp == "null")
            root = Insert_Node(q , INT_MAX , root);
        else
            root = Insert_Node(q , stoi(temp) , root);
    }
    root = remove_node(root);
    // DeleteNode(root , t);
    cout<<checkForBST(root , INT_MIN , INT_MAX)<<"\n";



    // vector<int>vec; int temp;
    // while(cin>>temp){
    //     vec.push_back(temp);
    // }
    // CovertFromPreorder(vec);
    // FindMode(root);
    // Findans(root , n , m);
    // int maxi = 0 ,mini = 0;
    // Minimum(root , mini);
    // Maximum(root , maxi);
    // cout<<mini<<" "<<maxi<<"\n";
    // vector<int>path_m , path_n;
    // int answer = INT_MIN;
    // SolveAnswer(root ,answer);
    // cout<<answer;
    // Maximum Sum Path in Binary Tree
    // PostOrder(root );
    // int dep = depth(root , 0);
    // int answer = 0;
    // cout<<dep<<"\n";
    // FindLeft(root , answer , dep , 0);
    // cout<<answer;
    // Findans(root);
    // Search(root , m , path_m);
    // for(auto it : path){
    //     cout<<it<<" ";
    // }
    // Search(root , n , path_n);
    // Search(root , m , path_m);
    // reverse(path_m.begin() , path_m.end());
    // reverse(path_n.begin() , path_n.end());
    // if(path_m.size() != path_n.size())
        // cout<<0<<"\n";
    // else
    //     (path_n[1] != path_m[1]) ?  cout<<1<<"\n" : cout<<0<<"\n"; 

    // for(int i=0; i<path_m.size(); i++){
    //     cout<<path_m[i]<<" ";
    // }
    // cout<<"\n";
    // for(int i=0; i<path_n.size(); i++){
    //     cout<<path_n[i]<<" ";
    // }
    // cout<<"\n";    

    // deleteTree(root); 
    }
    // int answer = -1;
    // for(int i=0; i<path_m.size(); i++){
    //     if(path_n[i] != path_m[i]){
    //         answer = path_n[i-1];
    //         break;
    //     }
    // }
    // if(answer == -1){
    //     cout<<path_m[path_m.size() -1];
    // }else{
    //     cout<<answer;
    // }
    
    return ;
}

// Node *Make_Tree(vector<int>&in , vector<int>&post , int start , int end , int *n){
//     // static int temp_index = 0;
//     if(start > end) return NULL;

//     Node *new_node = Build_Node(post[*n]);
//     (*n)--;
//     if(start == end) return new_node;

//     auto it = find(in.begin() , in.end() , new_node->data);
//     if(it != in.end()){
//         int index = distance(in.begin() , it);
//         new_node->right = Make_Tree(in , post , index + 1 , end , n);
//         new_node->left = Make_Tree(in , post , start , index - 1 , n);
        
//     } 

//     return new_node;
// }

// void Build_Tree(vector<int>&in , vector<int>&post){
//     int temp; 
//     while(1){
//         cin>>temp;
//         if(temp == -1)
//             break;
//         in.push_back(temp);
//     }
//     while(1){
//         cin>>temp;
//         if(temp == -1)
//             break;
//         post.push_back(temp);
//     }

//     return ;
// }

// int findAns(Node *root){
//     int height1 , height2;
//     if(root == NULL)
//         return 0;
//     if(root->left == NULL && root->right == NULL)
//         return 0;
//     height1 = findAns(root->left);
//     height2 = findAns(root->right);

//     if(root->left == NULL && root->right != NULL){
//         return max(findAns(root->right) , height2 + 1);
//     }
//     if(root->right == NULL && root->left != NULL){
//         return max(findAns(root->left) , height1 + 1);
//     }
//     return max(height2 + height1 + 2 , max(findAns(root->left) , findAns(root->right)));

// }

int main(){
    Build_Tree();
    // vector<int>in ,post;
    // Build_Tree(in ,post);
    // int Inindex = in.size() - 1;
    // for(int i =0 ; i<in.size(); i++){
    //     cout<<in[i]<<" "<<post[i]<<"\n";
    // }
    // root = Make_Tree(in , post , 0 , in.size() -1 ,&Inindex);
    // PreOrder(root);
    // cout<<findAns(root);

    return 0;
}