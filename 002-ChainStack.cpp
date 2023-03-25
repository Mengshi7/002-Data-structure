# include <iostream>
using namespace std;

typedef char ElemType;
const char result[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C', 'D', 'E', 'F'};  //�洢����ת����(16���Ƽ�����)

typedef struct StackNode
{  //��ջ���
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
    printf("��ѡ����Ĳ�����1.��ջ����ջ���� 2.����ת��\n");
    scanf("%d", &i);
    switch (i)
    {
        case 1:
            j = 5;
            while(j--)
            {
                printf("��������ջԪ�أ�");
                scanf("\n%c", &ch);
                Push(S, ch);
            }
            while(!IsEmpty(S))
            {
                Pop(S, ch);
                printf("��ջԪ�أ�%c\n", ch);
            }
            break;
        case 2:
            k = 5;
            while (k--)
            {
                printf("��������Ҫת��������");
                scanf("%lld", &x);
                printf("������ʹ�õĽ��ƣ�");
                scanf("%d", &n);
                BaseConvert(S, x, n);
            }
            break;
    }

    system("pause");
    return 0;
}

bool InitStack(LinkStack &S)  
{ /*����һ����ջ��ջ��ָ���ÿ�*/
    S = NULL;
    return true;
}

bool Push(LinkStack &S, ElemType e)
{
    LinkStack p = new StackNode;  //Ϊ�½�㶯̬����һ��洢�ռ�
    if (p == NULL)  //�жϿռ�����Ƿ�ɹ�
    {
        printf("����ռ�ʧ�ܣ�\n");
        return false;
    }
    p->data = e;
    p->next = S;  
    S = p;  //Sʼ��ָ��ջ��
    return true;
}

bool IsEmpty(LinkStack S)
{  /*���ջ���򷵻�true����֮����false*/
    if (S == NULL)  
        return true;
    else
        return false;
}

bool Pop(LinkStack &S, ElemType &e)
{
    if (IsEmpty(S))  //���ջ�գ��������ٳ�ջ
    {
        printf("ջ�ѿգ������ջ��\n");
        return false;
    }
    else
    {
        e = S->data;  //��ջ��Ԫ�ظ���e
        LinkStack p = S;
        S = S->next;  //�޸�ջ��ָ��
        delete p;  //�ͷ�ԭջ��Ԫ�صĿռ�
        return true;
    }
}

void BaseConvert(LinkStack &S, long long x, int n)
{ /*ͨ��ջSʹx��n���Ʊ�ʾ*/
    long long y = x;
    char z;
    while (y != 0)  //���϶�nȡ�ֱ࣬����Ϊ��Ϊֹ
    {
        z = result[y % n];  
        y = y / n;
        Push(S, z);  //��������Ӧ�Ľ��ѹ��ջ��
    }
    printf("%lld��%d���Ʊ�ʾ��", x, n);
    ElemType a;
    while(!IsEmpty(S))  //������Ԫ�س�ջֱ��ջ��
    {
        Pop(S, a);  
        printf("%c", a);
    }
    printf("\n\n");
}