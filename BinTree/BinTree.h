/*******************************
 *Binary Node
 *Binary Tree
 *Traversal
 * *****************************/
#define BinNodePosi(T) BinNode<T>*
template <typename T> struct BinNode{
    BinNodePosi(T) parent, lc, rc;//parental node, left child, right child
    T data;
    int height;//height of tree
    //constructor
    BinNode(T d = 0, BinNOdePosi(T) pa = NULL, BinNodePosi(T) l = NULL, BinNodePosi(T) r = NULL )
        : data(d), parent(pa), lc(l), rc(r){ }
    int size();//scale of subtree
    BinNodePosi(T) insertAsLC(const T &e);//insert a node as left child
    BinNodePosi(T) insertAsRC(const T &e);//insert a child as right child
    BinNodePosi(T) succ();//direct succssor in inorder traversal
    template <typename VST> void travLevel(VST &);//level traversal
    template <typename VST> void travPre(VST &);//preorder traversal
    template <typename VST> void travIn(VST &);//inorder traversal
    template <typename VST> void travPost(VST &);//postorder traversal

}; 

template <typename T> BinNodePosi(T) BinNode<T> :: insertAsLC(const T &e){
    return lc = new BinNode(e, this);
}
template <typename T> BinNodePosi(T) BinNode<T> :: insertAsRC(const T &e){
    return rc = new BinNode(e, this);
}
template <typename T> int BinNode<T> :: size(){
    int s = 1;
    if(lc) 
        s += lc->size();
    if(rc)
        s += rc->size();
    return s;
}

template <typename T> class BinTree{
    protected:
        int _size;
        BineNodePosi(T) _root;
        virtual int updateHeight(BinNodePosi(T) x);
        void updateHeightAbove(BinNodePosi(T) x);
    public:
        int size() const{
            return _size;
        }
        bool empty() const{
            return !_root;
        }
        BinNodePosi(T) root() const{
            return _root;
        }
        BinNodePosi(T) insertAsRC(BinNodePosi(T) x, const T &e);
        BinNodePosi(T) insertAsLC(BinNodePosi(T) x, const T &e);
        BinNodePosi(T) attachsRC(BinNodePosi(T) x, BinTree<T>* &S);
        BinNodePosi(T) attachsLC(BinNodePosi(T) x, BinTree<T>* &S);
        int remove(BinNodePosi(T) x);
        BinTree<T>* seced(BinNodePosi(T));
};

#define stature(p) ((p) ? (p)->height : -1)
inline int max(int a, int b){
    return (a > b ? a : b);
}
template <typename T> int BinTree<T> :: updateHeight(BinNodePosi(T) x){
    return x->height = 1 + max(stature(x->lc), stature(x->rc));
}
template <typename T> void BinTree<T> :: updateHeightAbove(BinNodePosi(T)){
    while(x){
        updateHeight(x);
        x = x->parent;
    }
}
template <typename T> BinNodePosi(T) BinTree<T> :: insertAsRC(BinNodePosi(T) x, const T &e){
    ++_size;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rc;
}
template <typename T> BinNodePosi(T) BinTree<T> :: insertAsLC(BinNodePosi(T) x, const T &e){
    ++_size;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lc;
}
template <typename T> BinNodePosi(T) BinTree<T> :: attachsLC(BinNodePosi(T) x, BinTree<T>* &S){
    if(x->rc = S->_root)
        x->rc->parent = x;
    _size += S->_size;
    updateHeightAbove(x);
    S->_root = NULL;
    S->_size = 0;
    release(S);
    S = NULL;
    return x;
}

template <typename T> BinNodePosi(T) BinTree<T> :: attachsLC(BinNodePosi(T) x, BinTree<T>* &S){
    if(x->lc = S->_root)
        x->lc->parent = x;
    _size += S->_size;
    updateHeightAbove(x);
    S->_root = NULL;
    S->_size = 0;
    release(S);
    S = NULL;
    return x;
}
template <typename T> int BinTree :: remove(BinNodePosi(T) x){
    FromParentTo(*x) = NULL;
    updateHeightAbove(x->parent);
    int n = removeAt(x);
    _size -= n;
    return n;
}
template <typename T> static int removeAt(BinNodePosi(T) x){
    if(!x)
        return 0;
    int n = 1 + removeAt(x->lc) + removeAt(x->rc);
    release(x->data);
    release(x);
    return n;
}

template <typename T> BinTree<T>* BinTree :: secede(BinNodePosi(T) x){
    FromParentTo(*x) = NULL;
    updateHeightAbove(x->parent);
    BinTree<T> *S = new BinTree<T>;
    S->_root = x;
    x->parent = NULL;
    S->_size = x->size();
    _size -= S->_size;
    return S;
}
/***************************************
 *
 *Traversal: preorder, inorder, postorder
 *
 *
 * *************************************/

//preorder traversal
template <typename T, typename VST>
static void visitAlongLeftBranch( BinNodePosi(T) x, VST &visit, Stack<BinNodePosi(T)> &S){
    while(x){
        visit(x->data);
        S.push(x->rc);
        x = x-lc;
    }
}
template <typename T, typename VST>
void travPre(BinNodePosi(T) x, VST &visit){
    Stack<BinNodePosi(T)> S;
    while(true){
        visitAlongLeftBranch(x, visit, S);
        if(SA.empty())
            break;
        x = S.pop();
    }
}

//inorder traversal
template <typename T> 
static void goAlongLeftBranch(BinNOdePosi(T) x, Stack<NodePosi(T)> &S){
    while(x){
        S.push(x);
        x = x->lc;
    }
}
template <typename T, typename VST>
void travIn(BinNBodePosi(T) x, VST &visit){
    Stack<BinNOdePosi(T)> S;
    while(true){
        goAlongLeftBranch(x,S);
        if(S.empty())
            break;
        x = S.pop();
        visit(x->data);
        x = x->rc;
    }
}

//dierect successor
template <typename T>
BinNodePosi(T) BinTree::succ(){
    BinNOdePosi(T) S = this;
    if(rc){
        S = rc;
        while(HasChild(*S))
            S = S->lc;
    }else{
        while(IsChild(*S))
            S = S->parent;
        S = S->parent;
    }
    return S;
}

//posterorder traversal
template <typename T> 
static void gotoHLVFL(Stack<BinNodePosi(T)> &S){
    while(BinNodePosi(T) x = S.top())
        if(HasLChild(* x)){
            if(HasRChild(*x))
                S.push(x->rc);
            S.push(x->rc);
        }else{
            S.push(x->rc);
        }
    S.pop();
}
template <typename T, typename VST>
void travPost(BinNodePosi(T) x, VST &visit){
    Stack<BinNodePosi(T)> S;
    if(x)
        S.push(x);
    while(!S.empty()){
        if(S.top() != x->parent)
            gotoHLVFL(S);
        x = S.pop();
        visit(x->data);
    }
}

//Level traversal
template <typename T, typename VST>
void BinNode<T> :: travLevel(VST &visit){
    Queue<BinNOdePosi(T)> Q;
    Q.enqueue(this);
    while(!Q.empty()){
        BinNOdePosi(T) x =Q;.dequeue();
        visit(x->data);
        if(HasLChild(*x))
            Q.enqueue(x->lc);
        if(HasRChild(*x))
            Q.enqueue(x->rc);
    }
}
