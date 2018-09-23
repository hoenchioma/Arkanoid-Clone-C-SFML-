#ifndef BALL_H
#define BALL_H

#include "pch.h"
#include "Direction.h"
#include "Bar.h"
#include "Blocks.h"
#include "Game_Control.h"

using namespace sf;

class Ball
{
    public:
		bool pause;
		
		Ball(double rad, Vector2f pos, Color color);
        void move(double time, Bar& bar);
		int collision(Bar & bar, std::vector<Blocks> & grid, RenderWindow & app, Game_Control & game);
        void setVel(double xv, double yv) {dx = xv; dy = yv;}
        inline double DX() {return dx;}
        inline double DY() {return dy;}
		inline Vector2f centrePos();
        void drawTo(RenderWindow& app) {app.draw(body);}
        ~Ball();

        friend class Bar;

    protected:

    private:
        CircleShape body;
        double dx;
        double dy;
};

#endif // BALL_H
