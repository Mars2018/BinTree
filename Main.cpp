#include<iostream>
#include<vector>
#include"BinTree.h"
using namespace std;
int main(){

    vector<int> v;
    for(int i = 0; i < 21; ++i)
        v.push_back(i + 1);
     
    Tree tree;
    tree.buildTree(v);
    tree.printTree();
    tree.printTree_level();
	std::cout << "\n\n";
	std::cout << "\n-------------Recursion Traversal-----------------";
	std::cout << "\nRecursion Inorder: " << endl;
	tree.RecursionInorder();
	std::cout << "\nRecursion Preorder: " << endl;
	tree.RecursionPreorder();
	std::cout << "\nRecursion Postorder: " << endl;
	tree.RecursionPostorder();
	std::cout << "\n-------------Stack Iteration Traversal------------";
	std::cout << "\nIteration Inorder: " << endl;
	tree.StackInorder();
	std::cout << "\nIteration Preorder: " << endl;
	tree.StackPreorder();
	std::cout << "\nIteration Postorder: " << endl;
	tree.StackPostorder();
	std::cout << "\n-------------Morris Traversal-------------------";
	std::cout << "\nMorris Inorder: " << endl;
	tree.MorrisInorder();
	std::cout << "\nMorris Preorder: " << endl;
	tree.MorrisPreorder();
	std::cout << "\nMorris Postorder: " << endl;
	tree.MorrisPostorder();
	std::cout << endl;
    return 0;  

    
}
