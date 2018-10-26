#pragma once
#include "stdafx.h"

#ifndef SHAPES
#define SHAPES
enum shapes {CIRCLE_COUNT = 432, CYLINDER_COUNT = 864, SQUARE_COUNT = 18, CUBE_COUNT = 108};
#endif // !SHAPES


class Shapes
{
public:
	Shapes();
	~Shapes();
	void getRect(float, float, float, float, float, GLfloat[]);
	void getCube(float, float, float, float, float, float, GLfloat[]);
	void getCircle(float, float, float, GLfloat[]);
	void getCylinder(float, float, float, float, float, GLfloat[]);
	float degToRad(float);
};

