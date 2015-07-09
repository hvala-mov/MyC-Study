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
        static shared_ptr<Context> graph;
        static const int HIGHT=24,WIDTH=18;
        int GameSpace[WIDTH][HIGHT];
    private:
        char randChar();
        Colors randColor();
    public:
        explicit Game(const initialism&);
        static shared_ptr<Game> creatGame();
        //static shared_ptr<Context> graph;
        void creatFigure();
        void printFigure();
        void printGameSpace();
};


#endif

