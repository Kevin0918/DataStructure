//
//  main.cpp
//  YangHuiTriangle
//
//  Created by 葛旭东 on 2017/6/15.
//  Copyright © 2017年 葛旭东. All rights reserved.
//

#include <iostream>//打印杨辉三角公式
using namespace std;
typedef  int DataType;
#define MAX 100
#define  FALSE 0
#define TRUE 1
typedef struct
{
    DataType data[MAX];
    int front;
    int rear;
}CirQueue;
int InQueue(CirQueue &Q,DataType x)
{
    
    if((Q.rear+1)%MAX==Q.front)
        return FALSE;
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MAX;
    return TRUE;
}

int OutQueue(CirQueue &Q,DataType &x)
{
    if(Q.rear==Q.front)
        return FALSE;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MAX;
    return TRUE;
}
void InitQueue(CirQueue &Q)//将Q初始化为一个空的循环链表
{
    Q.front=Q.rear=0;
}
int main()
{
    CirQueue Q;
    InitQueue(Q);//一定要初始化Q
    int n;
    int s1,s2,s;
    cout<<"输入打印的行数 :";
    cin>>n;
    for(int l=0;l<n-1;l++)
        cout<<" ";
    cout<<1<<endl;
    InQueue(Q,1);
    for(int i=2;i<=n;i++)
    {
        
        for(int j=0;j<n-i;j++)
            cout<<" ";
        s1=0;
        for(int k=1;k<=i-1;k++)
        {
            OutQueue(Q,s2);
            s=s1+s2;
            cout<<s<<" ";
            InQueue(Q,s);
            s1=s2;
        }
        cout<<1;
        InQueue(Q,1);
        cout<<endl;
    }
}

