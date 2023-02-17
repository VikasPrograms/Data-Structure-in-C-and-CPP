#include<iostream>
using namespace std;

#pragma pack(1)

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

class BST
{
    public:
        PNODE Root;

        BST();

        void Insert(int No);
        void InOrder();
        void PreOrder();
        void PostOrder();
        bool Search(int No);
        int CountLeafNode();
        int CountParentNode();
        int CountCompleteParentNode();
        int CountEvenNodes();
        int CountOddNodes();
};

BST :: BST()
{
    Root = NULL;
}

void BST :: Insert(int No)
{
    PNODE newn = new NODE;

    newn -> data = No;
    newn -> lchild = NULL;
    newn -> rchild = NULL;

    PNODE temp = Root;

    if(Root == NULL)
    {
        Root = newn;
    }
    else
    {
        while(1)
        {
            if(No > temp -> data)       // 'No' ha rchild madhhe jato
            {
                if(temp -> rchild == NULL)
                {
                    temp -> rchild = newn;
                    break;
                }
                temp = temp -> rchild;
            }
            else if(No < temp -> data)      // 'No' ha lchild madhhe jato
            {
                if(temp -> lchild == NULL)
                {
                    temp -> lchild = newn;
                    break;
                }
                temp = temp -> lchild;
            }
            else if(No == temp -> data)
            {
                delete(newn);
                cout<<"Duplicate Element not allowed.d"<<"\n";
                break;
            }
        }
    }
}

void BST :: PreOrder()
{
    if(Root != NULL)
    {
        cout<<"%d\t"<<Root -> data;
        cout<<(Root -> lchild);
        cout<<(Root -> rchild);
    }
}

void BST :: InOrder()
{
    if(Root != NULL)
    {
        cout<<(Root -> lchild);
        cout<<"%d\t"<<Root -> data;        
        cout<<(Root -> rchild);
    }
}

void BST :: PostOrder()
{
    if(Root != NULL)
    {
        cout<<(Root -> lchild);
        cout<<(Root -> rchild);
        cout<<"%d\t"<<Root -> data;
    }
}

bool BST :: Search(int No)
{
    bool flag = false;

    while(Root != NULL)
    {
        if(No == Root -> data)
        {
            flag = true;
            break;
        }
        else if(No > Root -> data)
        {
            Root = Root -> rchild;
        }
        else if(No < Root -> data)
        {
            Root = Root -> lchild;
        }
    }
    return flag;

/*  
    if(Root == NULL)     // Used flag method so not need to this syntax
    {
        return false;
    }
    else
    {
        return true;
    }
*/
}

int BST :: CountLeafNode()
{
    static int Count = 0;

    if(Root != NULL)
    {
        if((Root -> lchild == NULL) && (Root -> rchild == NULL))
        {
            Count++;
        }

        cout<<(Root -> lchild);
        cout<<(Root -> rchild);
    }
    return Count;
}

int BST :: CountParentNode()
{
    static int Count = 0;

    if(Root != NULL)
    {
        if((Root -> lchild != NULL) || (Root -> rchild != NULL))
        {
            Count++;
        }

        cout<<(Root -> lchild);
        cout<<(Root -> rchild);
    }
    return Count;
}


int BST :: CountCompleteParentNode()
{
    static int Count = 0;

    if(Root != NULL)
    {
        if((Root -> lchild != NULL) && (Root -> rchild != NULL))
        {
            Count++;
        }

        cout<<(Root -> lchild);
        cout<<(Root -> rchild);
    }
    return Count;
}

int BST :: CountEvenNodes()
{
    static int EvenCount = 0;

    if(Root != NULL)
    {
        if((Root -> data) % 2 == 0)
        {
            EvenCount++;
        }

        cout<<(Root -> lchild);
        cout<<(Root -> rchild);
    }
    return EvenCount;
}

int BST :: CountOddNodes()
{
    static int OddCount = 0;

    if(Root != NULL)
    {
        if((Root -> data) % 2 != 0)
        {
            OddCount++;
        }

        cout<<(Root -> lchild);
        cout<<(Root -> rchild);
    }
    return OddCount;
}

int main()
{
    BST obj;
    PNODE Head = NULL;
    bool bRet = false;
    int iRet = 0;

    obj.Insert(10);
    obj.Insert(22);
    obj.Insert(7);
    obj.Insert(13);
    obj.Insert(58);
    obj.Insert(32);

    cout<<"\nData using Preorder traversal \n";
    obj.PreOrder();

    cout<<"\nData using Inorder traversal \n";
    obj.InOrder();

    cout<<"\nData using Postorder traversal \n";
    obj.PostOrder();

    bRet = obj.Search(51);
    if(bRet == true)
    {
        cout<<"\n\nElement is there in BST.\n";
    }
    else
    {
        cout<<"\n\nThere is no element in BST.\n";
    }

    iRet = obj.CountLeafNode();
    cout<<"Leaf Nodesvare : "<<iRet<<"\n";

    iRet = obj.CountParentNode();
    cout<<"Parent Nodes in BST are : "<<iRet<<"\n";

    iRet = obj.CountCompleteParentNode();
    cout<<"Complete Parent Nodes in BST are : "<<iRet<<"\n";

    iRet = obj.CountEvenNodes();
    cout<<"Even Nodes in BST are : "<<iRet<<"\n";

    iRet = obj.CountOddNodes();
    cout<<"Odd Nodes in BST are : "<<iRet<<"\n";


    return 0;
}