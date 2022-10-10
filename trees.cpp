#include <bits/stdc++.h>
using namespace std;

//Creatring a tree using user defined datatype (struct)
struct TreeNode{
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val){
		data = val;
		left=right=NULL;
	}
};

//Tree traversal techniques
//bfs and dfs = post,pre,inorder


//Inorder (left,root,right)
//in order to apply this technique go to extreme left and then exterme right
//just like we traverse in dfs

void Inorder(TreeNode* root){
	if(root==NULL) return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

//Preorder(root,left,right)

void Preorder(TreeNode* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);
}

//Postorder(left,right,root)

void Postorder(TreeNode* root){
	if(root==NULL) return;
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->data<<" ";
}



//bfs (level order traversal)
void bfs(TreeNode* root){
	if(root==NULL) return;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()){
		TreeNode* p = q.front();
		q.pop();
		cout<<p->data<<" ";
		if(p->left) q.push(p->left);
		if(p->right) q.push(p->right);
	}
}


//Pre In Post order in one function
void PreInPost(TreeNode* root){
	if(root==NULL) return;
	stack<pair<TreeNode*,int>> s;
	s.push({root,1});
	vector<int> pre,in,post;
	while(!s.empty()){
		auto node = s.top();
		s.pop();
		if(node.second==1){
			pre.push_back(node.first->data);
			node.second++;
			s.push(node);
			if(node.first->left) s.push({node.first->left,1});
		}
		else if(node.second==2){
			in.push_back(node.first->data);
			node.second++;
			s.push(node);
			if(node.first->right) s.push({node.first->right,1});
		}
		else{
			post.push_back(node.first->data);
		}
	}
	cout<<"Preorder: ";
	for(auto c: pre) cout<<c<<" ";
	cout<<"\n";
    cout<<"Inorder: ";
    for(auto c: in) cout<<c<<" ";
    	cout<<"\n";
    cout<<"Postorder: ";
    for(auto c: post) cout<<c<<" ";
}


//Maximum depth in binary tree

int Maxdepth(TreeNode* root){
	if(root==NULL) return 0;
	if(root->left==NULL and root->right==NULL) return 0;
	return 1+max(Maxdepth(root->left),Maxdepth(root->right));
}



//check wether a tree is balanced binary tree
//condition - for every node -> height(left)-height(right)<=1

//make some changes in find height of tree when it gives -1 then return
//-1 which means it is not balanced..

int balanced_Tree(TreeNode* root){
	if(root==NULL) return 0;
	int lh = balanced_Tree(root->left);
	int rh = balanced_Tree(root->right);
	if(lh==-1 or rh==-1) return -1;//this will check if the left or right subtree are balanced or not at 
	//any point of time
	if(abs(lh-rh)>1) return -1;
	return max(lh,rh)+1; //if balanced(root)==-1 then it's not balanced
}



//diameter of a tree - is the longest path b/w two nodes
//just made some changes in find the height of tree

int diameter(TreeNode* root, int& ans){
	if(!root) return 0;
	int lh = diameter(root->left,ans);
	int rh = diameter(root->right,ans);
	ans = max(ans,lh+rh);
	return max(lh,rh)+1;
}



//maximum path sum of binary tree

int Maxpathsum(TreeNode* root, int& ans){
	if(!root) return 0;
	int leftsum = max(0,Maxpathsum(root->left,ans)); //taking max with 0 because we don't want to consider the negative path it's better we dont take it so that's why 0
	int rightsum = max(0,Maxpathsum(root->right,ans));
	ans = max(ans,leftsum+rightsum+root->data);
	return max(leftsum,rightsum)+root->data;
}



//check two trees are identical or not

bool two_trees_identical(TreeNode* root1, TreeNode* root2){
	if(root1==NULL or root2==NULL) return root1==root2;
	return (root1->data==root2->data and two_trees_identical(root1->left,root2->left) and two_trees_identical(root1->right,root2->right));
}



//print zig-zag sequence

vector<vector<int>> zigzag(TreeNode* root){
	vector<vector<int>> ans;
	if(root==NULL) return ans;
	queue<TreeNode*> q;
	q.push(root);
	int lefttoright=1;
	while(!q.empty()){
		int s = q.size();
		vector<int> res;
		for(int i=0; i<s; ++i){
			TreeNode* node = q.front();
			q.pop();
			int ind = (lefttoright? i: s-i-1);
			res[ind] = node->data;
			if(node->left) q.push(node->left);
			if(node->right) q.push(node->right);
		}
		lefttoright= !lefttoright;
		ans.push_back(res);
	}
	return ans;
}


//print the boundary of binary tree
//first comes the left nodes
//second all the leaf nodes
//third all the right nodes but in reverse order
bool isleaf(TreeNode* root){
    return root->left==NULL and root->right==NULL;
}


void leftboundary(TreeNode* root, vector<int>& ans){
    TreeNode* node = root->left;
    while(node){
        if(!isleaf(node)) ans.push_back(node->data);
        if(node->left) node = node->left;
        else node = node->right;
    }
}


void rightboundary(TreeNode* root, vector<int>& ans){
    TreeNode* node = root->right;
    vector<int> temp;
    while(node){
        if(!isleaf(node)) temp.push_back(node->data);
        if(node->right) node = node->right;
        else node = node->left;
    }
    for(int i=temp.size()-1; i>=0; --i) ans.push_back(temp[i]);
}

void leaf(TreeNode* root, vector<int>& ans){
    if(isleaf(root)) {
        ans.push_back(root->data);
        return;
    }
    if(root->left) leaf(root->left,ans);
    if(root->right) leaf(root->right,ans);
}

vector<int> boundary(TreeNode* root){
    vector<int> ans;
    if(root==NULL) return ans;
    if(!isleaf(root)) ans.push_back(root->data);
    leftboundary(root,ans);
    leaf(root,ans);
    rightboundary(root,ans);
    return ans;
}





































int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left=new TreeNode(5);
	root->left->left->right=new TreeNode(6);
	// PreInPost(root);
	//cout<<Maxdepth(root);
	int arr[5] = {1,2};
	for(int x: arr) cout<<x<<" ";
	

}
