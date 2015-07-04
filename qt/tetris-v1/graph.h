#ifndef _GRAPH_H_
#define _GRAPH_H_

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include"cur.h"
#include"cubePoint.h"
using namespace std;
const int DOWN=0;
const int LEFT=1;
const int RIGHT=2;

class Gbase{
    protected:
        int x;
        int y;//a[0][0]的位置
        int a[3][3];
    public:
        Gbase(){
            x=0;
            y=0;
            for(int i=0;i<3;++i){
                for(int j=0;j<3;++j){
                    a[i][j]=0;
                }
            }//memset?
        }
        int move(const int &dir);
        virtual int roll();
        virtual void draw(){}
        void setLocate(const int &ax,const int &ay){x=ax;y=ay;}
        void getLocate(int &ax,int &ay) const {ax=x;ay=y;}
        void printGraph(Colors &color);
        //获取数组首地址
        void* getArray() const {return (void*)a;}//?void*?
        virtual ~Gbase(){}
};
class Zgraph:public Gbase{
    public:
        void draw(){
            a[0][0]=1;
            a[0][1]=1;
            a[0][2]=0;
            a[1][0]=0;
            a[1][1]=1;
            a[1][2]=1;
            a[2][0]=0;
            a[2][1]=0;
            a[2][2]=0;
        } 
};
class Tgraph:public Gbase{
    public:
        void draw(){
            a[0][0]=1;
            a[0][1]=1;
            a[0][2]=1;
            a[1][0]=0;
            a[1][1]=1;
            a[1][2]=0;
            a[2][0]=0;
            a[2][1]=0;
            a[2][2]=0;
        }
};
class Ograph:public Gbase{
    public:
        void draw(){
            a[0][0]=1;
            a[0][1]=1;
            a[0][2]=0;
            a[1][0]=1;
            a[1][1]=1;
            a[1][2]=0;
            a[2][0]=0;
            a[2][1]=0;
            a[2][2]=0;
        }
        virtual int roll(){return 0;}
};
class Lgraph:public Gbase{
    public:
        void draw(){
            a[0][0]=0;
            a[0][1]=1;
            a[0][2]=0;
            a[1][0]=0;
            a[1][1]=1;
            a[1][2]=0;
            a[2][0]=0;
            a[2][1]=1;
            a[2][2]=1;
        }  
};
class Igraph:public Gbase{
    public:
        void draw(){
            a[0][0]=0;
            a[0][1]=1;
            a[0][2]=0;
            a[1][0]=0;
            a[1][1]=1;
            a[1][2]=0;
            a[2][0]=0;
            a[2][1]=1;
            a[2][2]=0;
        }    
};
class Context{
    private:
        Gbase *gbase;
    public:
        Context(const char &cType){
            switch(cType){
                case 'Z':
                    gbase=new Zgraph();
                    break;
                case 'T':
                    gbase=new Tgraph();
                    break;
                case 'O':
                    gbase=new Ograph();
                    break;
                case 'L':
                    gbase=new Lgraph();
                    break;
                case 'I':
                    gbase=new Igraph();
                    break;
                default:
                    cout<<"Type error!"<<endl;
                    break;
            }
        }
        ~Context(){
            delete gbase;
        }
        int move(const int &dir){return gbase->move(dir);}
        int roll(){return gbase->roll();}
        void draw(){gbase->draw();}
        void setLocate(const int &ax,const int &ay) const {gbase->setLocate(ax,ay);}
        void getLocate(int &ax,int &ay){gbase->getLocate(ax,ay);}
        void* getArray() const {return gbase->getArray();}
        void printGraph(Colors color){gbase->printGraph(color);}
};

#endif
