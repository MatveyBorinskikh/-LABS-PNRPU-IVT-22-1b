#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>
#include <QPainter>
#include <QStack>
#include <QQueue>

template<typename T> class BinarySearchTree;

template<typename T>
class Node
{
    friend class BinarySearchTree<T> ;
public:
    Node(const T &);
private:
    T data;
    int x;
    Node<T> *leftChild;
    Node<T> *rightChild;
    Node<T> *parent;
};

template<typename T>
class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();
    bool isEmpty() const;
    bool insert(const T &);
    void resetTree();
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal() const;
    QString getPreOrderTraversal() const;
    QString getInOrderTraversal() const;
    QString getPostOrderTraversal() const;
    QString getBreadthFirstSearch();
    QString getFindElement(T) const;
    int getNodeCount() const;
    int getLeafNodeCount() const;
    int getTreeHeight() const;
    bool deleteItem(T);
    bool find(T) const;
    void draw(QPainter *painter, double &scale);
    int getTotalY() const;
    int getTotalX() const;
    bool deleteAtLocation(int x, int y);
private:
    QPainter *painter;
    Node<T> *root;
    int yspace;
    int xspace;
    int nodeRadius;
    double scale;
    int max(int a, int b) const;
    void recursivePreOrder(const Node<T> *) const;
    void recursiveInOrder(const Node<T> *) const;
    void recursivePostOrder(const Node<T> *) const;
    int recursiveCountNodes(const Node<T> *) const;
    int recursiveCountLeafNodes(const Node<T> *) const;
    int recursiveComputeHeightOfTree(const Node<T> *) const;
    void recursiveDeleteNodes(const Node<T> *);
    void recursiveDraw(Node<T> *node);
    Node<T>* getLeftmostNode(Node<T> *node) const;
    int getNodeLevel(Node<T> *node);
    int getPxLocOfLeftTree(const Node<T> *node);
    int getPxLocOfAncestor(const Node<T> *node);
    void resetNodePosition(Node<T> *node);
    bool recursiveDeleteAtLocation(Node<T> *node, int x, int y);
};

template<typename T>
Node<T>::Node(const T &info) :
        data(info), x(0), leftChild(0), rightChild(0), parent(0)
{

}

template<typename T>
int BinarySearchTree<T>::max(int a, int b) const
{
    return a > b ? a : b;
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree() :
        root(0), scale(1)
{

}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    recursiveDeleteNodes(root);
    this->root = 0;
}

template<typename T>
bool BinarySearchTree<T>::recursiveDeleteAtLocation(Node<T> *node, int x, int y)
{
    if (node == 0)
        return false;


    if (recursiveDeleteAtLocation(node->leftChild, x, y) == true)
        return true;

    int level = getNodeLevel(node);
    int nodey = (level * nodeRadius * 2 + yspace * (level-1)) - nodeRadius;
    int nodex = node->x - nodeRadius;

    if (nodex <= x && x <=nodex + nodeRadius*2 )
    {
        if (nodey <= y && y <= nodey + nodeRadius*2)
        {
            deleteItem(node->data);
            return true;
        }
    }
    return recursiveDeleteAtLocation(node->rightChild, x, y);
}

template<typename T>
bool BinarySearchTree<T>::deleteAtLocation(int x, int y)
{
    return recursiveDeleteAtLocation(root, x, y);
}

template<typename T>
bool BinarySearchTree<T>::isEmpty() const
{
    return root == 0;
}

template<typename T>
bool BinarySearchTree<T>::insert(const T &item)
{

    Node<T> *newNode = new Node<T>(item);

    if (this->isEmpty())
    {
        this->root = newNode;
        return true;
    }

    Node<T> *currentNode = root;
    Node<T> *trailCurrentNode = root;

    while (currentNode != 0)
    {
        if (currentNode->data < item)
        {
            trailCurrentNode = currentNode;
            currentNode = currentNode->rightChild;
        }
        else if (currentNode->data > item)
        {
            trailCurrentNode = currentNode;
            currentNode = currentNode->leftChild;
        }
        else
        {
            std::cout << "Duplicate value: " << currentNode->data << std::endl;
            return false;
        }
    }

    if (trailCurrentNode->data < item)
        trailCurrentNode->rightChild = newNode;
    else
        trailCurrentNode->leftChild = newNode;

    newNode->parent = trailCurrentNode;

    return true;
}

template<typename T>
void BinarySearchTree<T>::resetTree()
{
    recursiveDeleteNodes(root);
    root = 0;
    return;
}

template<typename T>
void BinarySearchTree<T>::preOrderTraversal() const
{
    recursivePreOrder(root);
    return;
}

template<typename T>
void BinarySearchTree<T>::inOrderTraversal() const
{
    recursiveInOrder(root);
    return;
}

template<typename T>
void BinarySearchTree<T>::postOrderTraversal() const
{
    recursivePostOrder(root);
    return;
}

template<typename T>
int BinarySearchTree<T>::getNodeCount() const
{
    if (this->isEmpty())
        return 0;
    return recursiveCountNodes(root);
}

template<typename T>
int BinarySearchTree<T>::getLeafNodeCount() const
{
    if (this->isEmpty())
        return 0;
    return recursiveCountLeafNodes(root);
}

template<typename T>
int BinarySearchTree<T>::getTreeHeight() const
{
    if (this->isEmpty())
        return 0;
    return recursiveComputeHeightOfTree(root);
}

template<typename T>
bool BinarySearchTree<T>::deleteItem(T item)
{
    if (this->isEmpty())
        return false;

    bool found = false;
    Node<T> *currentNode = root;
    Node<T> *trailCurrentNode = root;

    while (!found && currentNode != 0)
    {
        if (currentNode->data == item)
            found = true;
        else if (currentNode->data < item)
        {
            trailCurrentNode = currentNode;
            currentNode = currentNode->rightChild;
        }
        else
        {
            trailCurrentNode = currentNode;
            currentNode = currentNode->leftChild;
        }
    }

    if (!found)
        return found;

    if (currentNode->leftChild == 0 && currentNode->rightChild == 0)
    {
        if (currentNode == root)
        {
            delete root;
            root = 0;
        }
        else if (trailCurrentNode->data < item)
        {
            delete trailCurrentNode->rightChild;
            trailCurrentNode->rightChild = 0;
        }
        else
        {
            delete trailCurrentNode->leftChild;
            trailCurrentNode->leftChild = 0;
        }
        return found;
    }

    if (currentNode->leftChild == 0 && currentNode->rightChild != 0)
    {
        if (currentNode == root)
        {
            Node<T> *tempPtr = root;
            root->rightChild->parent = 0;
            root = root->rightChild;
            delete tempPtr;
            return found;
        }

        if (trailCurrentNode->data < item)
        {
            Node<T> *tempPtr = trailCurrentNode->rightChild;
            trailCurrentNode->rightChild = currentNode->rightChild;
            currentNode->rightChild->parent = trailCurrentNode;
            delete tempPtr;
        }
        else
        {
            Node<T> *tempPtr = trailCurrentNode->leftChild;
            trailCurrentNode->leftChild = currentNode->rightChild;
            currentNode->rightChild->parent = trailCurrentNode;
            delete tempPtr;
        }

        return found;
    }
    if (currentNode->leftChild != 0 && currentNode->rightChild == 0)
    {
        if (currentNode == root)
        {
            Node<T> *tempPtr = root;
            root = root->leftChild;
            root->parent = 0;
            delete tempPtr;
        }
        if (trailCurrentNode->data < item)
        {
            Node<T> *tempPtr = trailCurrentNode->rightChild;
            trailCurrentNode->rightChild = currentNode->leftChild;
            currentNode->leftChild->parent = trailCurrentNode;
            delete tempPtr;
        }
        else
        {
            Node<T> *tempPtr = trailCurrentNode->leftChild;
            trailCurrentNode->leftChild = currentNode->leftChild;
            currentNode->leftChild->parent = trailCurrentNode;
            delete tempPtr;
        }
        return found;
    }

    if (currentNode->leftChild != 0 && currentNode->rightChild != 0)
    {
        Node<T> *ptr = currentNode;
        trailCurrentNode = currentNode;
        ptr = ptr->leftChild;
        if(ptr->rightChild==NULL)
        {
            if(ptr->leftChild==NULL)
            {
                currentNode->data=ptr->data;
                currentNode->leftChild=NULL;
                delete ptr;
            }
            else
            {
               currentNode->data=ptr->data;
               currentNode->leftChild=ptr->leftChild;
               ptr->leftChild->parent=currentNode;
               delete ptr;

            }

        }
        else
            {

            while (ptr->rightChild!=0)
               ptr=ptr->rightChild;
            trailCurrentNode=ptr->parent;
            trailCurrentNode->rightChild=NULL;
            currentNode->data=ptr->data;
            delete ptr;
            }
   }
    return found;
}

template<typename T>
QString BinarySearchTree<T>::getFindElement(T item) const
{
    if (this->isEmpty())
        return QString("");

    Node<T> *currentNode = root;
    while (currentNode != 0)
    {
        if (currentNode->data == item)
        {
            return QString::number(item);
        }
        else if (currentNode->data < item)
            currentNode = currentNode->rightChild;
        else
            currentNode = currentNode->leftChild;
    }

}

template<typename T>
bool BinarySearchTree<T>::find(T item) const
{
    if (this->isEmpty())
        return false;

    Node<T> *currentNode = root;
    while (currentNode != 0)
    {
        if (currentNode->data == item)
        {
            std::cout<<currentNode->data << std::endl;
            return true;
        }
        else if (currentNode->data < item)
            currentNode = currentNode->rightChild;
        else
            currentNode = currentNode->leftChild;
    }

    return false;
}

// private
template<typename T>
void BinarySearchTree<T>::recursivePreOrder(const Node<T> *node) const
{
    if (node == 0)
        return;
    std::cout << node->data << " ";
    recursivePreOrder(node->leftChild);
    recursivePreOrder(node->rightChild);

    return;
}

template<typename T>
void BinarySearchTree<T>::recursiveInOrder(const Node<T> *node) const
{
    if (node == 0)
        return;
    recursiveInOrder(node->leftChild);
    std::cout << node->data << " ";
    recursiveInOrder(node->rightChild);

    return;
}

template<typename T>
void BinarySearchTree<T>::recursivePostOrder(const Node<T> *node) const
{
    if (node == 0)
        return;
    recursivePostOrder(node->leftChild);
    recursivePostOrder(node->rightChild);
    std::cout << node->data << " ";

    return;
}

template<typename T>
QString BinarySearchTree<T>::getPreOrderTraversal() const
{
    QStack<Node<T>*> stack;
    QString traversal;
    Node<T> *root = this->root;
    while (true) {
        while (root != 0) {
            traversal.append(QString::number(root->data) + " ");
            stack.push(root);
            root = root->leftChild;
        }
        if (stack.isEmpty()) {
            return traversal;
        }
        root = stack.pop();
        root = root->rightChild;
    }
}

template<typename T>
QString BinarySearchTree<T>::getInOrderTraversal() const
{
    QStack<Node<T>*> stack;
    QString traversal;
    Node<T> *root = this->root;
    while (true) {
        while (root != 0) {
            stack.push(root);
            root = root->leftChild;
        }
        if (stack.isEmpty()) {
            return traversal;
        }
        root = stack.pop();
        traversal.append(QString::number(root->data) + " ");
        root = root->rightChild;
    }
}

template<typename T>
QString BinarySearchTree<T>::getPostOrderTraversal() const
{

    if (this->isEmpty())
            return QString("");
    QStack<Node<T>*> stack1;
    QStack<Node<T>*> stack2;
    QString traversal;
    Node<T> *root = this->root;
    stack1.push(root);
    while (!stack1.isEmpty())
    {
        Node<T> *temp = stack1.pop();
        stack2.push(temp);

        if (temp->leftChild != 0)
            stack1.push(temp->leftChild);
        if (temp->rightChild != 0)
            stack1.push(temp->rightChild);
    }

    while(!stack2.isEmpty())
        traversal.append(QString::number(stack2.pop()->data) + " ");

    return traversal;
}

template<typename T>
QString BinarySearchTree<T>::getBreadthFirstSearch()
{
    QString traversal("");

    Node<T> *traverse;

    if (this->root == 0)
        return traversal;

    QQueue<Node<T>*> ptrQueue;

    ptrQueue.enqueue(this->root);

    while (!ptrQueue.isEmpty()) {
        traverse = ptrQueue.dequeue();


        traversal.append(QString::number(traverse->data) + " ");


        if (traverse->leftChild != 0)
        ptrQueue.enqueue(traverse->leftChild);

        if (traverse->rightChild != 0)
        ptrQueue.enqueue(traverse->rightChild);
    }

    return traversal;
}


template<typename T>
int BinarySearchTree<T>::recursiveCountNodes(const Node<T> *node) const
{
    if (node == 0)
        return 0;
    return (1 + recursiveCountNodes(node->leftChild)
            + recursiveCountNodes(node->rightChild));

}

template<typename T>
int BinarySearchTree<T>::recursiveCountLeafNodes(const Node<T> *node) const
{
    if (node == 0)
        return 0;
    if (node->leftChild == 0 && node->rightChild == 0)
        return 1;

    return (recursiveCountLeafNodes(node->leftChild)
            + recursiveCountLeafNodes(node->rightChild));
}

template<typename T>
int BinarySearchTree<T>::recursiveComputeHeightOfTree(const Node<T> *node) const
{
    if (node == 0 || (node->leftChild == 0 && node->rightChild == 0))
        return 0;

    return 1
            + max(recursiveComputeHeightOfTree(node->leftChild),
                    recursiveComputeHeightOfTree(node->rightChild));
}

template<typename T>
void BinarySearchTree<T>::recursiveDeleteNodes(const Node<T> *node)
{
    if (node == 0)
        return;
    recursiveDeleteNodes(node->leftChild);
    recursiveDeleteNodes(node->rightChild);
    delete node;

    return;
}

template<typename T>
void BinarySearchTree<T>::resetNodePosition(Node<T> *node)
{
    if (node == 0)
        return;
    resetNodePosition(node->leftChild);
    node->x = 0;
    resetNodePosition(node->rightChild);

    return;
}


template<typename T>
void BinarySearchTree<T>::draw(QPainter *painter, double &scale)
{
    if(this->root == 0)
        return;

    this->painter = painter;
    this->painter->setFont(QFont("Times", 12 * scale, QFont::Normal));

    this->scale = scale;
    this->nodeRadius = 20 * scale;
    this->xspace = nodeRadius;
    this->yspace = nodeRadius * 5;

    resetNodePosition(root);

    Node<T> *leftmost = getLeftmostNode(root);
    leftmost->x = nodeRadius * 2;

    this->recursiveDraw(root);

    return;
}



template<typename T>
Node<T>* BinarySearchTree<T>::getLeftmostNode(Node<T> *node) const
{
    if (node->leftChild == 0)
        return node;
    return getLeftmostNode(node->leftChild);
}



template<typename T>
int BinarySearchTree<T>::getNodeLevel(Node<T> *node)
{
    int level = 1;
    Node<T> *current = node;

    while(current->parent != 0){
        current = current->parent;
        ++level;
    }
    return level;
}



template<typename T>
int BinarySearchTree<T>::getPxLocOfLeftTree(const Node<T> *node)
{
    if(node->rightChild == 0){
        return node->x;
    }
    return getPxLocOfLeftTree(node->rightChild);
}

template<typename T>
int BinarySearchTree<T>::getPxLocOfAncestor(const Node<T> *node)
{
    Node<T> *currentNode = node->parent;

    while(currentNode->x == 0)
        currentNode = currentNode->parent;

    return currentNode->x;
}

template<typename T>
int BinarySearchTree<T>::getTotalY() const
{
    int level = getTreeHeight() + 1;
    return (level * nodeRadius * 2 + yspace * (level-1)) + nodeRadius * 2;
}

template<typename T>
int BinarySearchTree<T>::getTotalX() const
{
    if (this->root == 0)
        return nodeRadius*3;

    Node<T> *current = root;
    while (current->rightChild != 0)
        current = current->rightChild;
    return current->x + nodeRadius * 3;
}

template<typename T>
void BinarySearchTree<T>::recursiveDraw(Node<T> *node)
{
    if (node == 0)
        return;

    this->recursiveDraw(node->leftChild);

    int level = getNodeLevel(node);
    int y = level * nodeRadius * 2 + yspace * (level-1);

    if (node->leftChild != 0)
    {
        node->x = getPxLocOfLeftTree(node->leftChild) + nodeRadius + xspace;

        painter->drawLine(QPoint(node->x, y + nodeRadius), QPoint(node->leftChild->x + 2,((level + 1)* nodeRadius * 2 + yspace * level) - nodeRadius));
    }

    else if (node->x == 0)
        node->x = getPxLocOfAncestor(node) + nodeRadius + xspace;

    painter->drawEllipse(QPoint(node->x, y),nodeRadius,nodeRadius);

    int textAdjuster;
    if(std::abs(node->data) < 10)
        textAdjuster = 4;
    else if (std::abs(node->data) < 100)
        textAdjuster = 7;
    else if (std::abs(node->data) < 1000)
        textAdjuster = 12;
    else
        textAdjuster = 16;

    painter->drawText(QPoint(node->x-(textAdjuster*scale), y+(5*scale)), QString::number(node->data));

    this->recursiveDraw(node->rightChild);

    if (node->rightChild != 0)
        painter->drawLine(QPoint(node->x, y + nodeRadius), QPoint(node->rightChild->x - 2,((level + 1)* nodeRadius * 2 + yspace * level) - nodeRadius));

    return;
}

#endif /* BINARYSEARCHTREE_H_ */
