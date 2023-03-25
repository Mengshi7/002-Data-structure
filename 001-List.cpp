//ʹ��GBK����
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
    printf("����������Ԫ�صĸ�����");
    scanf("%d", &n);
    PLNode L = Creat_List(n);
/*
    �������޸Ĳ���
    printf("�޸�ǰ");
    Output_List(L);
    printf("\n");
    ElemType x;
    while(1)
    {
        printf("�����뽫�޸ĵ�λ�ü��޸ĺ��ֵ��");
        scanf("%d%d", &n, &x);
        Modify_List(L, n, x);
        printf("�޸ĺ�");
        Output_List(L);
        printf("\n");
    }
*/
  /*
    ��������ң����ַ���������
    ElemType x;
    int j;
    while (1)
    {
        printf("��ѡ�����Ԫ�صķ�ʽ��1.Ԫ�ص�ֵ 2.Ԫ�ص�λ��\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
                printf("������Ԫ�ص�ֵ��");
                scanf("%d", &x);
                j = Locate_List(L, x);
                if (j <= 0)
                {
                    printf("�޸�Ԫ�أ�����\n");
                    break;
                }
                else
                {
                    printf("%d��ӦԪ�ص�λ��Ϊ%d\n", x, j);
                }
                break;
            case 2:
                printf("������Ԫ�ص�λ�ã�");
                scanf("%d", &n);
                PLNode q = GetElem_List(L, n);
                if (q)
                {
                    printf("��%d��λ�õ�Ԫ��Ϊ��%d\n", n, q->data);
                }
                else
                {
                    printf("�޸�Ԫ�أ�����\n");
                    break;
                }
                break;
        }
        
    }
*/
 /*
    ������ɾ������
    printf("ɾ��ǰ");
    Output_List(L);
    printf("\n");
    while(1)
    {
        printf("������Ҫɾ��Ԫ�ص�λ�ã�");
        scanf("%d", &n);
        if (Delete_List(L, n))
        {
            printf("ɾ����");
            Output_List(L);
            printf("\n");
        }
        else
            break;
    }
*/
/* 
    ���������Ԫ�ز���
    ElemType x;
    printf("����������λ�ü�Ԫ�أ�\n");
    scanf("%d%d", &n, &x);
    printf("����ǰ");
    Output_List(L);
    printf("\n");
    if (n == 0)
        printf("����ʧ�ܣ�����\n");
    else
    {
        while(n)
        {
            if (Insert_List(L, n, x))
            {
                printf("�����");
                Output_List(L);
                printf("\n");
                printf("����������λ�ü�Ԫ�أ�\n");
                scanf("%d%d", &n, &x);
            } 
            else
                break; 
        }
    }
 */     
 /*
    ͷ�巨����������� 
    printf("����������Ԫ�صĸ�����");
    scanf("%d", &n);
    PLNode L = Creat_List(n);
    Output_List(L);
*/
/*  
    ����ָ��λ��Ԫ�ز���
    Output_List(L);
    while (n)
    {
        printf("������Ҫ����Ԫ�ص�λ�ã�");
        scanf("%d", &n);
        PLNode x = GetElem_List(L, n);
        if (x)
        {
            printf("��%d��Ԫ��Ϊ��%d\n", n, x->data);
        }
        else
            printf("��λ����Ԫ�أ�\n");
    }
*/
    system("pause");
    return 0;
}

PLNode Creat_List(int n)
{  //��ͷ�巨����һ����n��Ԫ�صĵ�����,������ͷָ��
    PLNode L = new LNode;  //����һ��ͷ�ڵ㣬��ͷָ��ָ��ͷ�ڵ�
    L->pnext = NULL;

    if (!L)
    {    
        printf("����ʧ�ܣ�\n");
        exit(-1);
    }
    else
    {
        printf("�������������Ԫ��:\n");
        for (int i=n; i>0; --i)
        {
            PLNode p = new LNode;
            if (!p)
            {
                printf("����ʧ��");
                exit(-1);
            }
            else
            {
                printf("�������%d��Ԫ��:", i);
                scanf("%d", &p->data);
                p->pnext = L->pnext;
                L->pnext = p;
            }
        }
        return L;
    }
}

bool Insert_List(PLNode L, int i, ElemType e)
{  /*��i��Ԫ��ǰ����Ԫ��e*/
    PLNode p = L;
    int j = 0;

    while (p && j<i-1)
    {  /*ѭ�������˳�ʱ��pָ���i-1�����*/
        p = p->pnext;
        ++j;
    }
    if (!p || j>i-1)
    {
        printf("����ʧ��!!!\n");
        return false;
    }
    PLNode s = new LNode;
    if (!s)
    {
        printf("����ʧ��!!!\n");
        exit(-1);
    }
    s->data = e;
    s->pnext = p->pnext;
    p->pnext = s;

    return true;
}

bool Delete_List(PLNode L, int i)
{  /*ɾ����i��Ԫ��*/
    PLNode p = L;
    int j = 0;
    while((p->pnext) && j<i-1)
    {  /*ѭ������������pָ���i-1�����*/
        p = p->pnext;
        j++;
    }
    if (!(p->pnext) || (j>i-1))
    {
        printf("ɾ��ʧ��!!!");
        return false;
    }
    PLNode q = p->pnext;
    p->pnext = q->pnext;
    delete q;
    return true;
}

int Locate_List(PLNode L, ElemType e)
{  /*����ֵΪe��Ԫ�أ�������λ��*/
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
        return j;  //���ҳɹ�����λ�ã����򷵻�0
}

PLNode GetElem_List(PLNode L, int i)
{  /*���ҵ�i��Ԫ��,������ָ�����ָ��*/
    PLNode p = L->pnext;
    int j = 1;

    while (p && j<i)
    {
        p = p->pnext;
        ++j;
    }
    if (!p || j>i)
    {
        printf("����ʧ�ܣ�\n");
        return NULL;
    } 
    else
        return p;
}

bool Modify_List(PLNode L, int i, ElemType e)
{  /*����i��Ԫ�ص�ֵ����Ϊe*/
    PLNode p = L->pnext;
    int j = 1;
    while (p && j<i)
    {
        p = p->pnext;
        ++j;
    }
    if (!p || j > i)
    {
        printf("�޸Ĵ���\n");
        return false;
    }
    else
    {
        p->data = e;
        return true;
    }
}

void Output_List(PLNode L)
{  /*��������е�Ԫ��*/
    PLNode p = L->pnext;
    int i = 1;
    printf("�����Ԫ�����ݣ�\n");
    while (p)
    {
        printf("��%d��Ԫ��:%d ", i++, p->data);
        p = p->pnext;
    }
}