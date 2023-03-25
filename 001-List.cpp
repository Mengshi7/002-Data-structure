//使用GBK编码
//Mengshi7
# include <iostream>
using namespace std;

# define ElemType int

typedef struct LNode
{
    ElemType data;
    LNode * pnext;
}LNode, * PLNode;

PLNode Creat_List(int n);
bool Insert_List(PLNode L, int i, ElemType e);
bool Delete_List(PLNode L, int i);
int Locate_List(PLNode L, ElemType e);
PLNode GetElem_List(PLNode L, int i);
bool Modify_List(PLNode L, int i, ElemType e);
void Output_List(PLNode L);

int main(void)
{
    int n;
    printf("请输入链表元素的个数：");
    scanf("%d", &n);
    PLNode L = Creat_List(n);
/*
    单链表修改测试
    printf("修改前");
    Output_List(L);
    printf("\n");
    ElemType x;
    while(1)
    {
        printf("请输入将修改的位置及修改后的值：");
        scanf("%d%d", &n, &x);
        Modify_List(L, n, x);
        printf("修改后");
        Output_List(L);
        printf("\n");
    }
*/
  /*
    单链表查找（两种方法）测试
    ElemType x;
    int j;
    while (1)
    {
        printf("请选择查找元素的方式：1.元素的值 2.元素的位置\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
                printf("请输入元素的值：");
                scanf("%d", &x);
                j = Locate_List(L, x);
                if (j <= 0)
                {
                    printf("无该元素！！！\n");
                    break;
                }
                else
                {
                    printf("%d对应元素的位置为%d\n", x, j);
                }
                break;
            case 2:
                printf("请输入元素的位置：");
                scanf("%d", &n);
                PLNode q = GetElem_List(L, n);
                if (q)
                {
                    printf("第%d个位置的元素为：%d\n", n, q->data);
                }
                else
                {
                    printf("无该元素！！！\n");
                    break;
                }
                break;
        }
        
    }
*/
 /*
    单链表删除测试
    printf("删除前");
    Output_List(L);
    printf("\n");
    while(1)
    {
        printf("请输入要删除元素的位置：");
        scanf("%d", &n);
        if (Delete_List(L, n))
        {
            printf("删除后");
            Output_List(L);
            printf("\n");
        }
        else
            break;
    }
*/
/* 
    单链表插入元素测试
    ElemType x;
    printf("请输入插入的位置及元素：\n");
    scanf("%d%d", &n, &x);
    printf("插入前");
    Output_List(L);
    printf("\n");
    if (n == 0)
        printf("插入失败！！！\n");
    else
    {
        while(n)
        {
            if (Insert_List(L, n, x))
            {
                printf("插入后");
                Output_List(L);
                printf("\n");
                printf("请输入插入的位置及元素：\n");
                scanf("%d%d", &n, &x);
            } 
            else
                break; 
        }
    }
 */     
 /*
    头插法创建链表测试 
    printf("请输入链表元素的个数：");
    scanf("%d", &n);
    PLNode L = Creat_List(n);
    Output_List(L);
*/
/*  
    查找指定位置元素测试
    Output_List(L);
    while (n)
    {
        printf("请输入要查找元素的位置：");
        scanf("%d", &n);
        PLNode x = GetElem_List(L, n);
        if (x)
        {
            printf("第%d个元素为：%d\n", n, x->data);
        }
        else
            printf("该位置无元素！\n");
    }
*/
    system("pause");
    return 0;
}

PLNode Creat_List(int n)
{  //用头插法创建一个含n个元素的单链表,并返回头指针
    PLNode L = new LNode;  //生成一个头节点，用头指针指向头节点
    L->pnext = NULL;

    if (!L)
    {    
        printf("创建失败！\n");
        exit(-1);
    }
    else
    {
        printf("请逆序输入各个元素:\n");
        for (int i=n; i>0; --i)
        {
            PLNode p = new LNode;
            if (!p)
            {
                printf("创建失败");
                exit(-1);
            }
            else
            {
                printf("请输入第%d个元素:", i);
                scanf("%d", &p->data);
                p->pnext = L->pnext;
                L->pnext = p;
            }
        }
        return L;
    }
}

bool Insert_List(PLNode L, int i, ElemType e)
{  /*在i个元素前插入元素e*/
    PLNode p = L;
    int j = 0;

    while (p && j<i-1)
    {  /*循环正常退出时，p指向第i-1个结点*/
        p = p->pnext;
        ++j;
    }
    if (!p || j>i-1)
    {
        printf("插入失败!!!\n");
        return false;
    }
    PLNode s = new LNode;
    if (!s)
    {
        printf("插入失败!!!\n");
        exit(-1);
    }
    s->data = e;
    s->pnext = p->pnext;
    p->pnext = s;

    return true;
}

bool Delete_List(PLNode L, int i)
{  /*删除第i个元素*/
    PLNode p = L;
    int j = 0;
    while((p->pnext) && j<i-1)
    {  /*循环正常结束，p指向第i-1个结点*/
        p = p->pnext;
        j++;
    }
    if (!(p->pnext) || (j>i-1))
    {
        printf("删除失败!!!");
        return false;
    }
    PLNode q = p->pnext;
    p->pnext = q->pnext;
    delete q;
    return true;
}

int Locate_List(PLNode L, ElemType e)
{  /*查找值为e的元素，返回其位置*/
    PLNode p = L->pnext;
    int j = 1;

    while (p && (p->data != e))
    {    
        p = p->pnext;
        j++;
    }
    if (!p)
    {
        return -1;
    }
    else
        return j;  //查找成功返回位置，否则返回0
}

PLNode GetElem_List(PLNode L, int i)
{  /*查找第i个元素,并返回指向其的指针*/
    PLNode p = L->pnext;
    int j = 1;

    while (p && j<i)
    {
        p = p->pnext;
        ++j;
    }
    if (!p || j>i)
    {
        printf("查找失败！\n");
        return NULL;
    } 
    else
        return p;
}

bool Modify_List(PLNode L, int i, ElemType e)
{  /*将第i个元素的值更改为e*/
    PLNode p = L->pnext;
    int j = 1;
    while (p && j<i)
    {
        p = p->pnext;
        ++j;
    }
    if (!p || j > i)
    {
        printf("修改错误\n");
        return false;
    }
    else
    {
        p->data = e;
        return true;
    }
}

void Output_List(PLNode L)
{  /*输出链表含有的元素*/
    PLNode p = L->pnext;
    int i = 1;
    printf("链表各元素内容：\n");
    while (p)
    {
        printf("第%d个元素:%d ", i++, p->data);
        p = p->pnext;
    }
}
