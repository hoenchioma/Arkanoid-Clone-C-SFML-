#ifndef BLOCKS_H
#define BLOCKS_H

#include "pch.h"
#include "Direction.h"

using namespace sf;

class Blocks
{
    public:
		bool alive;

		Blocks();
		Blocks(Vector2f size, Vector2f pos, Color color);
		void setSize(Vector2f size) { body.setSize(size); }
		void setPosition(Vector2f pos) { body.setPosition(pos); }
		void setFillColor(Color color) { body.setFillColor(color); }
		Vector2f topRight();
		Vector2f topLeft();
		Vector2f bottomRight();
		Vector2f bottomLeft();
		void dissapear();
		void drawTo(RenderWindow& app) { app.draw(this->body); }
		~Blocks() {}

		friend class Ball;

    protected:

    private:
        RectangleShape body;
};

#endif // BLOCKS_H
