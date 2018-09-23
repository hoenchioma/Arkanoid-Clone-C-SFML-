#include "pch.h"
#include "Bar.h"

using namespace sf;

Bar::Bar(Vector2f size, double height, double x_pos, Color color, RenderWindow& window)
{
    body.setSize(size);
    body.setPosition(x_pos - body.getSize().x/2, window.getSize().y - height - body.getSize().y);
    body.setFillColor(color);
    isMoving = false;
	pause = false;
}

void Bar::move(Direction dir, double time)
{
	if (pause) return;
	if (dir != R && dir != L)
    {
        std::cout << "Invalid Move" << std::endl;
        return;
    }
    isMoving = true;
    int dirInt = (dir == R? 1: -1);
    body.move(vel * dirInt * time, 0);
}

void Bar::setPos(double x)
{
	body.setPosition(x - body.getSize().x/2, body.getPosition().y);
}

void Bar::drawTo(RenderWindow& app)
{
    app.draw(this->body);
}

void Bar::setVel(double v)
{
    vel = v;
}

double Bar::getVel()
{
    return vel;
}

Vector2f Bar::topRight()
{
	return Vector2f(body.getPosition().x + body.getSize().x,
		body.getPosition().y);
}

Vector2f Bar::topLeft()
{
	return body.getPosition();
}

Vector2f Bar::bottomRight()
{
	return Vector2f(body.getPosition().x + body.getSize().x,
		body.getPosition().y + body.getSize().y);
}

Vector2f Bar::bottomLeft()
{
	return Vector2f(body.getPosition().x,
					body.getPosition().y + body.getSize().y);
}


Bar::~Bar()
{
    //dtor
}
