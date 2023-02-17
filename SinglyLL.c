//          Singly Linked List in C.
// Insert First & Last
// Delete First & Last
// Insert At Position & Delete At Position.

//----------------------------------------------------------------------
//
// Description   :  SINGLY LINEAR LINKED LIST USING C
// Input         :  Int
// Output        :  Int
// Author        :  Vikas Bade
// Date          :  12 Jully 2022
//
//----------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;           //  4 byte
    struct node *next;      // 4
};

typedef struct node NODE;           // NODE = 8
typedef struct node * PNODE;        // P means Pointer
typedef struct node ** PPNODE;      // PP means Pointer to Pointer

//----------------------------------------------------------------------
//
//
// Function Name    :   InsertFirst()
// Function Date    :   12 Jully 2022
// Function Author  :   Vikas Bade
// Parameters       :   PPNODE Head, int 
// Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList 
//
// Returns          :   NONE
//
//----------------------------------------------------------------------

void InsertFirst(PPNODE First, int no)       // Call by Address Under
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));       // 1 Allocate memory

    newn->data = no;
    newn->next = NULL;

    if(*First == NULL)      // If Linked list is empty
    {
        *First = newn;
    }
    else        // If Linked list contains atleast one node
    {
        newn->next = *First;
        *First = newn;
    }
}

//----------------------------------------------------------------------
//
//
// Function Name    :   InsertLast()
// Function Date    :  12 Jully 2022
// Function Author  :   Vikas Bade
// Parameters       :   PPNODE Head, int 
// Description      :   InsertLast Function Add New Node At End Of LinkedList 
//
// Returns          :   NONE
//
//----------------------------------------------------------------------

void InsertLast(PPNODE First, int no)       // Call by Address Under
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));       // 1 Allocate memory
    PNODE temp = *First;

    newn->data = no;
    newn->next = NULL;

    if(*First == NULL)      // If Linked list is empty
    {
        *First = newn;
    }
    else        // If Linked list contains atleast one node
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}

//----------------------------------------------------------------------
//
//
// Function Name    :   Display()
// Function Date    :   12 Jully 2022
// Function Author  :   Vikas Bade
// Parameters       :   PPNODE Head
// Description      :   Display Function Display The Nodes In LinkedList 
//
// Returns          :   NONE
//
//
//----------------------------------------------------------------------

void Display(PNODE First)   // Call by Value Under
{
    printf("Elements from the Linked List are : \n");

    while(First != NULL)
    {
        printf("| %d |->",First->data);
        First = First -> next;
    }
    printf("NULL \n");
}

//----------------------------------------------------------------------
//
//
// Function Name    :   Count()
// Function Date    :   12 Jully 2022
// Function Author  :   Vikas Bade
// Parameters       :   PPNODE Head
// Description      :   Count Function Count Number Of Nodes In LinkedList 
//
// Returns          :   int
//                  :   Return Number Of Nodes In LinkedList
//
//
//----------------------------------------------------------------------

int Count(PNODE First)   // Call by Value Under
{
    int iCnt = 0;

    while(First != NULL)
    {
        iCnt++;
        First = First -> next;
    }
    return iCnt;
}
//----------------------------------------------------------------------
//
//
// Function Name    :   DeleteFirst()
// Function Date    :   12 Jully 2022
// Function Author  :   Vikas Bade
// Parameters       :   PPNODE Head
// Description      :   DeleteFirst Function Remove The Node From Beginning Of The LinkedList 
//
// Returns          :   NONE
//
//
//----------------------------------------------------------------------

void DeleteFirst(PPNODE First)
{
    PNODE temp = *First;

    if(*First == NULL)      // A --- // empty LL
    {
        return;
    }
    else if((*First) -> next == NULL)       // B --- // 1 node in LL
    {
        free(*First);
        *First = NULL;
    }
    else        // C --- // more than 1 node in LL
    {
        (*First) = (*First) -> next;
        free(temp);
    }
}

//----------------------------------------------------------------------
//
//
// Function Name    :   DeleteLast()
// Function Date    :   12 Jully 2022
// Function Author  :   Vikas Bade
// Parameters       :   PPNODE Head
// Description      :   DeleteLast Function Remove The Node At End Of The LinkedList 
//
// Returns          :   NONE
//
//
//----------------------------------------------------------------------

void DeleteLast(PPNODE First)
{
    PNODE temp = *First;

    if(*First == NULL)      // A --- // empty LL
    {
        return;
    }
    else if((*First) -> next == NULL)       // B --- // 1 node in LL
    {
        free(*First);
        *First = NULL;
    }
    else        // C --- // more than 1 node in LL
    {
        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        free(temp->next);
        temp -> next = NULL;
    }
}

//----------------------------------------------------------------------
//
//
// Function Name    :   InsertAtPosition()
// Function Date    :   12 Jully 2022
// Function Author  :   Vikas Bade
// Parameters       :   PPNODE Head, int, int
// Description      :   InsertAtPosition Function Add New Node At Given Position In The LinkedList 
//
// Returns          :   NONE
//
//
//----------------------------------------------------------------------

void InsertAtPos(PPNODE First, int no, int ipos)
{
    int NodeCnt = 0, iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    NodeCnt = Count(*First);        // *First = 100

    if((ipos < 1) || (ipos > (NodeCnt + 1)))    // 1> ipos <7
    {
        printf("Invalid Position  \n");
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(First, no);
    }
    else if(ipos == NodeCnt + 1)
    {
        InsertLast(First, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        temp = *First;

        for(iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

//----------------------------------------------------------------------
//
//
// Function Name    :   DeleteAtPosition()
// Function Date    :   12 Jully 2022
// Function Author  :   Prasad Dangare
// Parameters       :   PPNODE Head, int
// Description      :   DeleteAtPosition Function Remove Existing Node At Any Position In The LinkedList 
//
// Returns          :   NONE
//
//
//----------------------------------------------------------------------

void DeleteAtPos(PPNODE First, int ipos)
{
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    int NodeCnt = 0, iCnt = 0;
    
    NodeCnt = Count(*First);        // *First = 100

    if((ipos < 1) || (ipos > NodeCnt))
    {
        printf("Invalid Position \n");
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst(First);
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast(First);
    }
    else
    {
        temp1 = *First;
        
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;        // this line indicates 500 address

        temp1->next = temp2->next;      // temp1->next = temp1->next->next;
        free(temp2);
    }
}

//----------------------------------------------------------------------
//
//
// Function Name   :   Entry Point Function
// Function Date   :   12 Jully 2022
// Function Author :   Prasad Dangare
// Brif Description :  Function Calls For Above Created Functions With Dynamic Input
//
//
//----------------------------------------------------------------------


int main()
{
    PNODE First = NULL;
    int iRet = 0, iOption = 1, iValue = 0, iPos = 0;
    
    while(iOption != 0)
    {
        printf("\n____________________________________\n");
        printf("Enter your action on Linked list : \n");
        printf("1 : Insert node at first position\n");
        printf("2 : Insert node at last position\n");
        printf("3 : Insert node at given position\n");
        printf("4 : Delete first node\n");
        printf("5 : Delete last node\n");
        printf("6 : Delete node at given position\n");
        printf("7 : Display the contents of linked list\n");
        printf("8 : Count number of nodes of linked list\n");
        printf("0 : Exit the application\n");
        printf("\n____________________________________\n");

        scanf("%d",&iOption);
        
        printf("\n____________________________________\n");
        
        switch(iOption)
        {
            case 1 :
                printf("Enter data to insert : \n");
                scanf("%d",&iValue);
                InsertFirst(&First,iValue);
                break;
                
            case 2 :
                printf("Enter data to insert : \n");
                scanf("%d",&iValue);
                InsertLast(&First,iValue);
                break;

            case 3:
                printf("Enter data to insert : \n");
                scanf("%d",&iValue);
                
                printf("Enter the position\n");
                scanf("%d",&iPos);
                InsertAtPosition(&First,iValue,iPos);
                break;


            case 4 :
                DeleteFirst(&First);
                break;

            case 5 :
                DeleteLast(&First);
                break;

            case 6:
                    printf("Enter the position\n");
                    scanf("%d",&iPos);
                    DeleteAtPosition(&First,iPos);
                    break;
                
            case 7:
                printf("Nodes of linked list are : \n");
                Display(First);
                break;

            case 8 :
                iRet = Count(First);
                printf("Number of nodes are : %d\n",iRet);
                break;
                
            case 0:
                printf("Thank you for using Marvellous Linked list application \n");
                break;
                
            default:
                printf("Please enter valid option \n");
                break;
        } 
        // End of switch
    } 
    // End of while
    return 0;
} 
// End of main
