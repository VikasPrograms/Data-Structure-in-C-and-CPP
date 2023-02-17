// Binary Search Tree

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void Insert(PPNODE Root, int No)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = No;
    newn -> lchild = NULL;
    newn -> rchild = NULL;

    PNODE temp = *Root;

    if(*Root == NULL)
    {
        *Root = newn;
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
                free(newn);
                printf("Duplicate Element not allowed.\n");
                break;
            }
        }
    }
}

void Preorder(PNODE Root)
{
    if(Root != NULL)
    {
        printf("%d\t", Root -> data);
        Preorder(Root -> lchild);
        Preorder(Root -> rchild);
    }
}

void Inorder(PNODE Root)
{
    if(Root != NULL)
    {
        Inorder(Root -> lchild);
        printf("%d\t", Root -> data);
        Inorder(Root -> rchild);
    }
}

void Postorder(PNODE Root)
{
    if(Root != NULL)
    {
        Postorder(Root -> lchild);
        Postorder(Root -> rchild);
        printf("%d\t", Root -> data);
    }
}

bool Search(PNODE Root, int No)
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

int CountLeafNode(PNODE Root)
{
    static int Count = 0;

    if(Root != NULL)
    {
        if((Root -> lchild == NULL) && (Root -> rchild == NULL))
        {
            Count++;
        }

        CountLeafNode(Root -> lchild);
        CountLeafNode(Root -> rchild);
    }
    return Count;
}

int CountParentNode(PNODE Root)
{
    static int Count = 0;

    if(Root != NULL)
    {
        if((Root -> lchild != NULL) || (Root -> rchild != NULL))
        {
            Count++;
        }

        CountParentNode(Root -> lchild);
        CountParentNode(Root -> rchild);
    }
    return Count;
}


int CountCompleteParentNode(PNODE Root)
{
    static int Count = 0;

    if(Root != NULL)
    {
        if((Root -> lchild != NULL) && (Root -> rchild != NULL))
        {
            Count++;
        }

        CountCompleteParentNode(Root -> lchild);
        CountCompleteParentNode(Root -> rchild);
    }
    return Count;
}

int CountEvenNodes(PNODE Root)
{
    static int EvenCount = 0;

    if(Root != NULL)
    {
        if((Root -> data) % 2 == 0)
        {
            EvenCount++;
        }

        CountEvenNodes(Root -> lchild);
        CountEvenNodes(Root -> rchild);
    }
    return EvenCount;
}

int CountOddNodes(PNODE Root)
{
    static int OddCount = 0;

    if(Root != NULL)
    {
        if((Root -> data) % 2 != 0)
        {
            OddCount++;
        }

        CountOddNodes(Root -> lchild);
        CountOddNodes(Root -> rchild);
    }
    return OddCount;
}

int main()
{
    PNODE Head = NULL;
    bool bRet = false;
    int iRet = 0;

    Insert(&Head, 10);      // &Head madhhe janar mhanun function madhhe PPNODE ghyave lagale
    Insert(&Head, 22);
    Insert(&Head, 7);
    Insert(&Head, 13);
    Insert(&Head, 58);
    Insert(&Head, 32);

    printf("\nData using Preorder traversal \n");
    Preorder(Head);

    printf("\nData using Inorder traversal \n");
    Inorder(Head);

    printf("\nData using Postorder traversal \n");
    Postorder(Head);

    bRet = Search(Head, 51);
    if(bRet == true)
    {
        printf("\n\nElement is there in BST.\n");
    }
    else
    {
        printf("\n\nThere is no element in BST.\n");
    }

    iRet = CountLeafNode(Head);
    printf("Leaf Nodesvare : %d\n",iRet);

    iRet = CountParentNode(Head);
    printf("Parent Nodes in BST are : %d\n",iRet);

    iRet = CountCompleteParentNode(Head);
    printf("Complete Parent Nodes in BST are : %d\n",iRet);

    iRet = CountEvenNodes(Head);
    printf("Even Nodes in BST are : %d\n",iRet);

    iRet = CountOddNodes(Head);
    printf("Odd Nodes in BST are : %d\n",iRet);

    return 0;
}