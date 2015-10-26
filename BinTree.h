#ifndef BINTREE_H
#define BINTREE_H

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node *parent, *left, *right;
    Node(int v = 0,Node *p = NULL, Node* l = NULL, Node* r = NULL ): data(v), parent(p), left(l), right(r){}
    Node* insertAsLC( const int &e){
        return left = new Node(e, this) ;
    }
    Node* insertAsRC(const int &e){
        return right = new Node(e, this);
    }
};

class Tree{
    protected:
        Node *root;
        int _size;

		void RecursionInorder(Node *root);
		void RecursionPreorder(Node *root);
		void RecursionPostorder(Node *root);

		void StackInorder(Node *root);
		void StackPreorder(Node *root);
		void StackPostorder(Node *root);

		void MorrisReverse(Node *from, Node *to);
		void MorrisPrintReverse(Node *from, Node *to);
     public:
        Tree(Node *r = NULL, int s = 0): root(r), _size(s){}
        void buildTree(const vector<int> &L);
        void printTree();
		void printTree_level();
		//recursion traversal		
		void RecursionInorder();
		void RecursionPreorder();
		void RecursionPostorder();
		//stack iteration traversal
		void StackInorder();
		void StackPreorder();
		void StackPostorder();
		//Morris traversal
		void MorrisInorder();
		void MorrisPreorder();
		void MorrisPostorder();
};
#endif