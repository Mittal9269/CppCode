#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

struct Node
{
	int data;
	Node *left , *right;
}*root;

struct Node *Build_Node(int data){
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = node->right = NULL;

	return node;
}

struct Node *Build_Tree(vector<int>&arr, int index){
	if(arr.size() <= index) return root;
	struct Node *temp = Build_Node(arr[index]);

	temp->left = Build_Tree(arr , index*2 + 1);
	temp->right = Build_Tree(arr , index*2 + 2);

	return temp;

}


void InsertNode(){
	vector<int>arr;
	int n; cin>>n;
	int temp;
	while(n--){
		cin>>temp;
		arr.push_back(temp);
	}
	root = Build_Tree(arr , 0);
}

void InsertSort(Node *root){
	if(root == NULL) return;
	cout<<root->data<<"\n";
	InsertSort(root->left);
	InsertSort(root->right);
}

Node *InsertOneNode(Node *root , int input){
	if(root == NULL){
		root = Build_Node(input);
		return root;
	}

	queue<Node *>q;
	q.push(root);

	while(!q.empty()){
		Node *temp = q.front();
		q.pop();

		if(temp->left != NULL){
			q.push(temp->left);
		}else{
			temp->left = Build_Node(input);
			return root;
		}
		if(temp->right != NULL){
			q.push(temp->right);
		}else{
			temp->right = Build_Node(input);
			return root;
		}
	}
}


void DeleteNow(Node *root , Node *delete_node){
	if(root == NULL) return;

	queue<Node *>q;
	q.push(root);

	Node *temp_Node;
	while(!q.empty()){
		temp_Node = q.front();
		q.pop();
		if(temp_Node == delete_node){
			temp_Node = NULL;
			delete(delete_node);
			return;
		}
		if(temp_Node->left){
			if(temp_Node->right == delete_node){
				temp_Node->right = NULL;
				delete(delete_node);
				return ;
			}
			else
				q.push(temp_Node->left);
		}
		if(temp_Node->right){
			if(temp_Node->left == delete_node){
				temp_Node->left = NULL;
				delete(delete_node);
				return;
			}
			else
				q.push(temp_Node->right);
		}
	}
}

Node *DeleteOneNode(Node *root , int data){
	if(root == NULL) return NULL;

	if(root->left == NULL && root->right == NULL){
		if(root->data == data)
			return NULL;
		else
			return root;
	}
	Node *temp =  NULL;
	Node *key_node = NULL;

	queue<Node *>q;
	q.push(root);
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(temp->data == data){
			key_node = temp;
		}
		if(temp->left != NULL)
			q.push(temp->left);

		if(temp->right != NULL)
			q.push(temp->right);
	}

	if(key_node != NULL){
		int x = temp->data;
		DeleteNow(root , temp);
		key_node->data = x;
	}

	return root;


}

int main(){
	InsertNode();
	// InsertSort(root);

	int input; cin>>input;
	root  = InsertOneNode(root ,input);
	// InsertSort(root);



	int input2; cin>>input2;
	root = DeleteOneNode(root, input2);
	InsertSort(root);

	return 0;
}