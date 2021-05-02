#include <iostream>
#include <vector>
#define MAX_QUEUE_SIZE 1000
using namespace std;

class BinaryNode{
public:
    char data;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode(char val=' ', BinaryNode* l = NULL, BinaryNode* r = NULL)
    :data(val), left(l), right(r){ }
    ~BinaryNode() {}
    
    void setData(char val) {data = val;}
    void setLeft(BinaryNode* l) {left = l;}
    void setRight(BinaryNode* r) {right = r;}
    
    char getData() {return data;}
    BinaryNode* getLeft() {return left;}
    BinaryNode* getRight() {return right;}
    
    bool isLeaf() {return left==NULL && right == NULL;} //단말노드인지
};

class CircularQueue : BinaryNode{
protected:
    int front;
    int rear;
    BinaryNode* data[MAX_QUEUE_SIZE];
public:
    CircularQueue() {front = rear = 0;}
    bool isEmpty() {return front == rear;}
    bool isFull() {return (rear+1) % MAX_QUEUE_SIZE == front;}
    int getRear() {return rear;}
    int getFront() {return front;}
    int size() {return rear - front;}
    
    void enqueue(BinaryNode* val){
        if(isFull()) {cout<<"error: 큐가 포화상태입니다."<<"\n";}
        else{
            rear = (rear+1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }
    
    BinaryNode* dequeue() {
        if(isEmpty()){
            cout<<"error: 큐가 공백상태입니다."<<"\n";
            exit(-1);
        }
        else{
            front = (front+1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }
    
    BinaryNode* peek() {
        if(isEmpty()){
            cout<<"error: 큐가 공백상태입니다."<<"\n";
            exit(-1);
        }
        else{
            return data[(front+1) % MAX_QUEUE_SIZE];
        }
    }
    
    void display(){
        cout<<"큐내용:";
        int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
        for(int i=front+1; i<=maxi; i++)
            cout<<data[i%MAX_QUEUE_SIZE]<<" ";
        cout<<"\n";
    }
    
};

class BinaryTree{
    BinaryNode* root;
public:
    BinaryTree() : root(NULL) { }
    ~BinaryTree() { }
    
    void setRoot(BinaryNode* node) {root = node;}
    BinaryNode* getRoot() {return root;}
    bool isEmpty() {return root == NULL;}
    
    //노드 개수
    int getCount() {return isEmpty() ? 0 : getCount(root);}
    //단말 노드 개수
    int getLeafCount() {return isEmpty() ? 0 : getLeafCount(root);}
    //트리의 높이
    int getHeight() {return isEmpty() ? 0 : getHeight(root);}
    //노드개수가 최대인지
    bool isMax() {
        if(getCount() == pow(2, getHeight()) - 1)   return true;
        else return false;
    }
    //full binary tree인지
    bool isFull() {
        return isEmpty() ? 0 : isFull(root) && isMax();
    }
    //데이터가 n인 노드의 레벨
    int calcLevel(char n) {return isEmpty() ? 0 :calcLevel(root, n, 1);}
    //Complete Tree
    bool isComplete(){
        bool ret = isComplete(root, 0, getCount(root));
        return ret;
    }
    //중위순회
    void inorder() {inorder(root);}
    //전위순회
    void preorder() {preorder(root);}
    //후위순회
    void postorder() {postorder(root);}
    
    //node를 루트로 하는 서브트리의 노드 개수
    int getCount(BinaryNode* node){
        if(node == NULL) return 0;
        return  1 + getCount(node -> getLeft()) + getCount(node -> getRight());
    }
    //단말 노드 개수
    int getLeafCount(BinaryNode* node){
        if(node == NULL) return 0;
        if(node -> isLeaf())    return 1;
        else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
    }
    //트리의 높이
    int getHeight(BinaryNode* node){
        if(node == NULL)    return 0;
        int hLeft = getHeight(node->getLeft());
        int hRight = getHeight(node->getRight());
        return (hLeft > hRight) ? 1+hLeft : 1+hRight;
    }
    //full binary tree인지
    bool isFull(BinaryNode* node){
        if(node == NULL)    return true;
        if(node->left == NULL && node->right == NULL) return true;
        if(node->left != NULL && node->right != NULL)   return isFull(node->left) && isFull(node->right);
        else    return false;
    }
    //데이터가 n인 노드의 레벨
    int calcLevel(BinaryNode* node, char n, int level){
        if(node == NULL) return 0;
        if(node->data == n) return level;
        int ll = calcLevel(node->left, n, level+1);
        if(ll != 0) return ll;
        ll = calcLevel(node->right, n, level+1);
        return ll;;
    }
    
    bool isComplete(BinaryNode* n, unsigned int index, unsigned int nNodes){
            if(n==NULL) return true;
            if(index >= nNodes) return false;
            return (isComplete(n->left, 2*index+1, nNodes) && isComplete(n->right, 2*index+2, nNodes));
        }
    
    void preorder(BinaryNode* node){
        if(node != NULL){
            cout<<node->getData();
            if(node->getLeft() != NULL) preorder(node->getLeft());
            if(node->getRight() != NULL) preorder(node->getRight());
            
        }
    }
    
    void inorder(BinaryNode* node){
        if(node != NULL){
            if(node->getLeft() != NULL) inorder(node->getLeft());
            cout<<node->getData();
            if(node->getRight() != NULL) inorder(node->getRight());
        }
    }
    
    void postorder(BinaryNode* node){
        if(node != NULL){
            if(node->getLeft() != NULL) postorder(node->getLeft());
            if(node->getRight() != NULL) postorder(node->getRight());
            cout<<node->getData();
        }
    }

    void levelorder(){
        if(!isEmpty()){
            CircularQueue q;
            q.enqueue(root);
            while (!q.isEmpty()) {
                BinaryNode* n = q.dequeue();
                if(n != NULL){
                    cout<<n->getData();
                    q.enqueue(n->getLeft());
                    q.enqueue(n->getRight());
                }
            }
        }
        cout<<"\n";
    }
};

struct input{
    char x;
    char y;
    char z;
};

vector<input> v;

int main(){
    BinaryTree tree;
    BinaryNode *d = new BinaryNode('D', NULL, NULL );
    BinaryNode *e = new BinaryNode('E', NULL, NULL );
    BinaryNode *b = new BinaryNode('B', d, e );
    BinaryNode *g = new BinaryNode('G', NULL, NULL );
    BinaryNode *f = new BinaryNode('F', NULL, NULL );
    BinaryNode *c = new BinaryNode('C', f, g );
    BinaryNode *a = new BinaryNode('A', b, c );
    tree.setRoot(a);

        cout << " 노드의 개수 = " << tree.getCount() << endl;
        cout << " 단말의 개수 = " << tree.getLeafCount() << endl;
        cout << " 트리의 높이 = " << tree.getHeight() << endl;
    tree.preorder();
    cout<<"\n";
    tree.inorder();
    cout<<"\n";
    tree.postorder();
    cout<<"\n";
}
