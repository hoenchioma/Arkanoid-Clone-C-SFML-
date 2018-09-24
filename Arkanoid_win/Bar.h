#ifndef BAR_H
#define BAR_H

#include "pch.h"
#include "Direction.h"

using namespace sf;

class Bar
{
    public:
		bool pause;

        Bar(Vector2f size, double height, double x_pos, Color color, RenderWindow& window);
        void move(Direction dir, double time);
		void setPos(double x);
        void drawTo(RenderWindow& app);
        void setVel(double v);
        double getVel();
		Vector2f topRight();
		Vector2f topLeft();
		Vector2f bottomRight();
		Vector2f bottomLeft();
		double getHeight() { return body.getSize().y; }
		double getWidth() { return body.getSize().x; }
		void speedup(double by) { vel += by; }
        ~Bar();

        bool isMoving;

		friend class Ball;

    protected:

    private:
        RectangleShape body;
        double vel;
};

#endif // BAR_H
