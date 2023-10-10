#include "pch.h"
#include "Player.h"

Player::Player(Graphics* graphics, const Color& color)
	: MyRect(graphics, color)
{
}

Player::~Player()
{
}

void Player::Event()
{
}

void Player::Move()
{
	if (GetAsyncKeyState('W') & 0x8000)
	{
		position.y++;
	}
	else if (GetAsyncKeyState('S') & 0x8000)
	{
		position.y--;
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		position.x++;
	}
	else if (GetAsyncKeyState('A') & 0x8000)
	{
		position.x--;
	}
}
