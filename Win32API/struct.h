#pragma once

struct Vec2
{
	float x;
	float y;

public:
	Vec2() : x(0.f), y(0.f) {}
	Vec2(float _x, float _y) : x(_x), y(_y) {}
	Vec2(int _x, int _y) : x(static_cast<float>(_x)), y(static_cast<float>(_y)) {}
};