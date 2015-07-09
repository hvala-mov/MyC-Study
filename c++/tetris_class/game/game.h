#ifndef GAME_H
#define GAME_H

#include"cur.h"
#include"cubePoint.h"
#include"graph.h"
#include"rand.h"
#include"score.h"
#include<pthread.h>
#include<unistd.h>
class Game{
    private:
        struct initialism{};
        static shared_ptr<Game> instance;
        //static Context* graph;
        Context* graph;
        //shared_ptr<Context> graph;
        static const int HIGHT=24,WIDTH=18;
        bool FLAG=true;
        int GameSpace[HIGHT][WIDTH];
    private:
        int x,y;
        Score score;
        char randChar();
        Colors randColor();
        bool isAttachBottom();
        bool isAttachLeft();
        bool isAttachRight();
        bool RollRightAvailable();
        void clearRoom(const int &line,const int &top);
        void resetRoom();
        void dropGraph(const int &line,const int &top);
    public:
        explicit Game(const initialism&);
        static shared_ptr<Game> creatGame();
        //static shared_ptr<Context> graph;
        void printGameSpace();
        bool isLegal(const Control &dir);
        bool flag(){return FLAG;}
        bool isOver();
    public:
        void creatFigure();
        void moveFigure(const Control &dir);
        void rollFigure();
};


#endif

