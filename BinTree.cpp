#include"BinTree.h"
#include<stack>
using namespace std;

//build a binary tree;
void Tree::buildTree(const std::vector<int> &L){
    if(L.empty())
        return ;
    std::queue<Node*> parentQueue;
    std::queue<Node*> childQueue;

    root = new Node(L[0]);
	++_size;
    parentQueue.push(root);

    std::size_t times = 1;
    while(times < L.size()){
        Node *parent = parentQueue.front();
        parentQueue.pop();
        
        parent->insertAsLC(L[times++]);
		++_size;
        childQueue.push(parent->left);
        
        if(times == L.size())
            break;

        parent->insertAsRC(L[times++]);
		++_size;
        childQueue.push(parent->right);
        
        if(parentQueue.empty()){
            parentQueue = childQueue;
            std::queue<Node*> empty;
            std::swap(childQueue, empty);
        }
       
    }    
}

void Tree::printTree(){

    Node *node = root;
    std::queue<Node*> temp1;
    std::queue<Node*> temp2;

    temp1.push(node);

    while(!temp1.empty()){
        node = temp1.front();
        if(node->left != NULL)
            temp2.push(node->left);
        if(node->right != NULL)
            temp2.push(node->right);

        temp1.pop();

        std::cout << node->data << " ";
        if(temp1.empty()){
            std::cout << std::endl;
            temp1 = temp2;
            std::queue<Node*> empty;
            std::swap(temp2, empty);
        }
    }

}

//level traversal
void Tree::printTree_level(){
	queue<Node*> Q;
	Q.push(root);
	
	while(!Q.empty()){
		Node *node = Q.front();
		if(node == NULL)
			return;
		Q.pop();
		std::cout << node->data << " ";
		if(node->left != NULL)
			Q.push(node->left);
		if(node->right != NULL)
			Q.push(node->right);
	}
}
//recursion traversal
void Tree::RecursionInorder(Node *root){
	if(root == NULL)
		return;
	RecursionInorder(root->left);
	cout << root->data << " ";
	RecursionInorder(root->right);
}
void Tree::RecursionPreorder(Node *root){
	if(root == NULL)
		return;
	cout << root->data << " ";
	RecursionPreorder(root->left);	
	RecursionPreorder(root->right);
}
void Tree::RecursionPostorder(Node *root){
	if(root == NULL)
		return;	
	RecursionPostorder(root->left);	
	RecursionPostorder(root->right);
	cout << root->data << " ";
}
void Tree::RecursionInorder(){
	RecursionInorder(root);
}
void Tree::RecursionPreorder(){
	RecursionPreorder(root);
}
void Tree::RecursionPostorder(){
	RecursionPostorder(root);
}

//Iteration traversal by stack
void Tree::StackInorder(Node *root){
	stack<Node*> parentStack;
	if(root == NULL)
		return;
	Node* cur = root;
	while(cur != NULL || !parentStack.empty()){
		if(cur != NULL){
			parentStack.push(cur);
			cur = cur->left;
		}else{
			cur = parentStack.top();
			parentStack.pop();
			cout << cur->data << " ";
			cur = cur->right;
		}
	}	
}
void Tree::StackPreorder(Node *root){
	stack<Node*> childStack;
	if(root == NULL)
		return;
	Node* cur = root;
	childStack.push(cur);
	while(!childStack.empty()){
		cur = childStack.top();
		childStack.pop();
		cout << cur->data << " ";
		if(cur->right != NULL)
			childStack.push(cur->right);
		if(cur->left != NULL)
			childStack.push(cur->left);
	}
}
void Tree::StackPostorder(Node *root){
	stack<Node*> inStack, outStack;	
	if(root == NULL)
		return;
	Node *cur = root;
	inStack.push(cur);
	while(!inStack.empty()){
		cur = inStack.top();
		inStack.pop();
		outStack.push(cur);
		if(cur->left != NULL)
			inStack.push(cur->left);
		if(cur->right != NULL)
			inStack.push(cur->right);
	}
	while(!outStack.empty()){
		cout << outStack.top()->data << " ";
		outStack.pop();
	}

}
void Tree::StackInorder(){
	StackInorder(root);
}
void Tree::StackPreorder(){
	StackPreorder(root);
}
void Tree::StackPostorder(){
	StackPostorder(root);
}

//Morris traversal
void Tree::MorrisInorder(){
	Node *cur, *pre;
	for(cur = root; cur != NULL; ){
		if(cur->left == NULL){
			std::cout << cur->data << " ";
			cur = cur->right;
			continue;
		}
		for(pre = cur->left; pre->right != NULL && pre->right != cur; pre = pre->right){}
		if(pre->right == NULL){
			pre->right = cur;
			cur = cur->left;
		}else{
			pre->right = NULL;
			std::cout << cur->data << " ";
			cur = cur->right;
		}
	}
}
void Tree::MorrisPreorder(){
	Node *cur, *pre;
	for(cur = root; cur != NULL; ){
		if(cur->left == NULL){
			std::cout << cur->data << " ";
			cur = cur->right;
			continue;
		}
		for(pre = cur->left; pre->right != NULL && pre->right != cur; pre = pre->right){}
		if(pre->right == NULL){
			pre->right = cur;
			std::cout << cur->data << " ";
			cur = cur->left;
		}else{
			pre->right = NULL;			
			cur = cur->right;
		}
	}
}

void Tree::MorrisReverse(Node *from, Node *to){
	if(from == to)
		return;
	Node *x = from, *y = from->right, *z;
	while(true){
		z = y->right;
		y->right = x;
		x = y;
		y = z;
		if(x == to)
			break;
	}
}
void Tree::MorrisPrintReverse(Node *from, Node *to){
	MorrisReverse(from, to);
	for(Node *p = to; ; p = p->right){
		cout << p->data << " ";
		if(p == from)
			break;
	}
	MorrisReverse(to, from);
}

void Tree::MorrisPostorder(){
	Node dummy(0, NULL, root);
	Node *cur = &dummy, *pre;
	for(; cur != NULL; ){
		if(cur->left == NULL){
			cur = cur->right;
			continue;
		}
		for(pre = cur->left; pre->right != NULL && pre->right != cur; pre = pre->right){}
		if(pre->right == NULL){
			pre->right = cur;
			cur = cur->left;
		}else{
			pre->right = NULL;
			MorrisPrintReverse(cur->left, pre);
			cur = cur->right;
		}
	}
}

