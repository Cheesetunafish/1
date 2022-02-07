//
//  main.c
//  顺序栈
//
//  Created by 艾诗杰 on 2022/2/7.
//
//预编译
#include <stdio.h>
#include <stdlib.h>
//宏定义
#define bool char
#define true 1
#define false 0
//自定义变量
#define MaxSize 50 //定义栈中的元素最大个数
//数据结构
typedef int Elemtype;//自定义顺序栈的数据元素类型

typedef struct SqStack
{
    Elemtype data[MaxSize];//存数据元素的数组
    int top;    //栈顶指针
}SqStack;
//栈的初始化
bool Initstack(SqStack *s)
{
    s->top = -1;    //初始化栈顶指针
    return s->top;
}
//判定栈空
bool StackEmpty(SqStack s)
{
    if (s.top == -1) {
        return true;    //栈空
    }else
        return false;
}
//进栈
bool Push(SqStack *S,Elemtype e){
    if (S->top == MaxSize - 1) {
        return false;//栈满
    }
    S->data[++S->top] = e;//指针+1，入栈
    return true;
}
//出栈
bool Pop(SqStack *s,Elemtype *e){
    if (StackEmpty(*s)) {
        return false;//栈空
    }
    *e = s ->data[s->top--];//先出栈，指针-1
    return true;
}

//读栈顶元素
bool GetTop(SqStack S,Elemtype *e)
{
    if (StackEmpty(S)) {
        return false;//栈空
    }
    *e = S.data[S.top];
    return true;
}

int main(){
    SqStack S;//生成栈
    Initstack(&S);
    Push(&S, 1);
    Push(&S, 2);
    Push(&S, 3);
    Push(&S, 4);
    Push(&S, 5);
    Push(&S, 6);
    
    Elemtype X;//用于保存出栈和读栈顶元素返回的变量的值
    int count = S.top;
    for (int i = 0; i <= count; i++) {
        printf("i = %d\n",i);
        GetTop(S, &X);
        printf("GetTop X = %d\n",X);
        Pop(&S, &X);
        printf("GetTop X = %d\n",X);
    }
    return 0;
}

