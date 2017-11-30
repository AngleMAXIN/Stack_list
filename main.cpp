#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

typedef struct node
{
    ElementType data;
    struct node *link;
} StackNode;

struct LinkStack
{
    struct node *top;
};
void InitStack(LinkStack &S)
{
    S.top = NULL;
}
bool IsEmpty(LinkStack S)
{
    if(S.top == NULL) return true;
    return false;
}
bool Push(LinkStack &S,ElementType element)
{
    StackNode *temp;
    temp = (StackNode*)malloc(sizeof(StackNode));
    if(temp ==  NULL) return false;
    temp->data = element;
    temp->link = S.top;
    S.top = temp;
    return true;
}
bool Pop(LinkStack &S,ElementType &element)
{
    if(IsEmpty(S)) return false;
    StackNode*temp = S.top;
    element = temp->data;
    S.top = temp->link;
    free(temp);
    return true;
}
void GetTop(LinkStack S,ElementType &element)
{
    element = S.top->data;
}
void Conversion()
{
    LinkStack S;
	StackNode *temp;
	int n,N=0,e=0;
	temp = (StackNode*)malloc(sizeof(StackNode));
	S.top = temp;
	InitStack(S);
	printf("please input number:");
	scanf("%d",&N);
	printf(" please input Progressive(8 or 2): ");
	scanf("%d",&n);
	while (N){
		Push(S,N%n);
		N=N/n;
	}
	printf("After   :");
while (!IsEmpty(S)){
	Pop(S,e);
	printf("%d",e);
   	}
   	printf("\n");
}
void GetNumber(LinkStack &S)
{
    int i = 0;
    StackNode *t = S.top;
    while(t != NULL)
    {
        i++;
        t =  t->link;
    }
    printf("The Stack Number is :%d\n",i);

}
int main()
{
    LinkStack S;
    int ch,a, cont = 1;
    while(cont)
    {
        printf("1.Init,2.Push,3.Pop,4.GetNum,5.conversion,exit()\n");
        scanf("%d",&ch);
        switch(ch)
        {

        case 1:
            InitStack(S);
            printf("ok\n");
            break;
        case 2:
            printf("please Input number:");
            scanf("%d",&a);
            Push(S,a);
            break;
        case 3:
            Pop(S,a);
            printf("TOP = %d\n",a);
            break;
        case 4:
            GetNumber(S);
            break;
        case 5:
            Conversion();
            break;
        case 6:
            cont = 0;
            break;

        }

    };
}
