#ifndef CUR_H_
#define CUR_H_

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
class Cur{
    public:
        void saveCur();//保存光标位置
        void moveCur(const int &x,const int &y);//移动光标到坐标（x,y）
        void resumeCur();//恢复光标位置
};

#endif
