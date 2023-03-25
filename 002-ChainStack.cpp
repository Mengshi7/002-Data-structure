# include <iostream>
using namespace std;

typedef char ElemType;
const char result[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C', 'D', 'E', 'F'};  //存储进制转换表(16进制即以下)

typedef struct StackNode
{  //链栈结点
    ElemType data;
    struct StackNode * next;
}StackNode, *LinkStack;

bool InitStack(LinkStack &S);
bool Push(LinkStack &S, ElemType e);
bool IsEmpty(LinkStack S);
bool Pop(LinkStack &S, ElemType &e);
void BaseConvert(LinkStack &S, long long x, int n);

int main(void)
{
    long long x;
    int  n;
    LinkStack S;
    InitStack(S);
    int i, j, k;
    char ch;
    printf("请选择你的操作：1.入栈、出栈测试 2.进制转换\n");
    scanf("%d", &i);
    switch (i)
    {
        case 1:
            j = 5;
            while(j--)
            {
                printf("请输入入栈元素：");
                scanf("\n%c", &ch);
                Push(S, ch);
            }
            while(!IsEmpty(S))
            {
                Pop(S, ch);
                printf("出栈元素：%c\n", ch);
            }
            break;
        case 2:
            k = 5;
            while (k--)
            {
                printf("请输入想要转换的数：");
                scanf("%lld", &x);
                printf("请输入使用的进制：");
                scanf("%d", &n);
                BaseConvert(S, x, n);
            }
            break;
    }

    system("pause");
    return 0;
}

bool InitStack(LinkStack &S)  
{ /*创建一个空栈，栈顶指针置空*/
    S = NULL;
    return true;
}

bool Push(LinkStack &S, ElemType e)
{
    LinkStack p = new StackNode;  //为新结点动态分配一块存储空间
    if (p == NULL)  //判断空间分配是否成功
    {
        printf("分配空间失败！\n");
        return false;
    }
    p->data = e;
    p->next = S;  
    S = p;  //S始终指向栈顶
    return true;
}

bool IsEmpty(LinkStack S)
{  /*如果栈空则返回true，反之返回false*/
    if (S == NULL)  
        return true;
    else
        return false;
}

bool Pop(LinkStack &S, ElemType &e)
{
    if (IsEmpty(S))  //如果栈空，则无需再出栈
    {
        printf("栈已空，无需出栈！\n");
        return false;
    }
    else
    {
        e = S->data;  //将栈顶元素赋给e
        LinkStack p = S;
        S = S->next;  //修改栈顶指针
        delete p;  //释放原栈顶元素的空间
        return true;
    }
}

void BaseConvert(LinkStack &S, long long x, int n)
{ /*通过栈S使x用n进制表示*/
    long long y = x;
    char z;
    while (y != 0)  //不断对n取余，直到商为零为止
    {
        z = result[y % n];  
        y = y / n;
        Push(S, z);  //将余数对应的结果压入栈中
    }
    printf("%lld用%d进制表示：", x, n);
    ElemType a;
    while(!IsEmpty(S))  //不断让元素出栈直到栈空
    {
        Pop(S, a);  
        printf("%c", a);
    }
    printf("\n\n");
}