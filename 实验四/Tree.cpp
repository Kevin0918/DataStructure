//
//  main.cpp
//  Tree
//
//  Created by 葛旭东 on 2017/6/15.
//  Copyright © 2017年 葛旭东. All rights reserved.
//

#include<stdio.h>
#include<stack>
#include<queue>
#include<locale.h>
#include<iostream>
using namespace std;
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//先序遍历
int CreateBiTree(BiTree &T)
{
    char ch;
    scanf("\n%c",&ch);
    if(ch == '$')
        T=NULL;
    else
    {
        T=new BiTNode;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return 0;
}

//visit
void visit(BiTree T)
{
    if(T->data != '#')
    {
        printf("%c",T->data);
    }
}


//先序
void PreOrder(BiTree T)
{
    stack<BiTree>stack;
    BiTree p=T;
    while(p || !stack.empty())
    {
        if(p !=NULL)
        {
            stack.push(p);
            printf("%c",p->data);
            p=p->lchild;
        }
        else
        {
            p=stack.top();
            stack.pop();
            p=p->rchild;
        }
    }
}

//中序
void InOrder(BiTree T)
{
    stack<BiTree>stack;
    BiTree p=T;
    while(p || !stack.empty())
    {
        if(p !=NULL)
        {
            stack.push(p);
            p=p->lchild;
        }
        else
        {
            p=stack.top();
            printf("%c",p->data);
            stack.pop();
            p=p->rchild;
        }
    }
}

typedef struct BiTNodePost
{
    BiTree biTree;
    char tag;
}BiTNodePost,*BiTreePost;

//后序
void PostOrder(BiTree T)
{
    stack<BiTreePost>stack;
    BiTree p=T;
    BiTreePost BT;
    while(p!=NULL || !stack.empty())
    {
        while(p !=NULL)
        {
            BT=(BiTreePost)malloc(sizeof(BiTNodePost));
            BT->biTree=p;
            BT->tag='L';
            stack.push(BT);
            p=p->lchild;
        }
        while(!stack.empty() && (stack.top())->tag=='R')
        {
            BT=stack.top();
            stack.pop();
            printf("%c",BT->biTree->data);
        }
        if(!stack.empty())
        {
            BT=stack.top();
            BT->tag='R';
            p=BT->biTree;
            p=p->rchild;
        }
    }
}

//层次序
void LevelOrder(BiTree T)
{
    if(T==NULL)
        return;
    BiTree p=T;
    queue<BiTree>queue;
    queue.push(p);
    while(!queue.empty())
    {
        p=queue.front();
        printf("%c",p->data);
        queue.pop();
        if(p->lchild != NULL)
        {
            queue.push(p->lchild);
        }
        if(p->rchild != NULL)
        {
            queue.push(p->rchild);
        }
    }
}

int main()
{
    BiTree T;
    printf("输入二叉树: ");
    CreateBiTree(T);
    
    printf("先序遍历（非递归）:  ");
    PreOrder(T);
    printf("\n");
    
    printf("中序遍历（非递归）:  ");
    InOrder(T);
    printf("\n");
    
    printf("后序遍历（非递归）:  ");
    PostOrder(T);
    printf("\n");
    
    printf("层次序遍历（非递归）:  ");
    LevelOrder(T);
    printf("\n");
    
    return 0;
}
