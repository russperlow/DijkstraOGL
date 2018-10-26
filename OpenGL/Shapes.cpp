#include "Shapes.h"



Shapes::Shapes()
{
}


Shapes::~Shapes()
{
}

/// <summary>
/// Creates a 2d rectangle
/// </summary>
/// <param name="x">Starting x location </param>
/// <param name="y">Starting y location</param>
/// <param name="z">Starting z location</param>
/// <param name="w">Width</param>
/// <param name="h">Height</param>
/// <param name="vertices">GLFloat array we are putting the rectangle in</param>
void Shapes::getRect(float x, float y, float z, float w, float h, GLfloat vertices[])
{
	vertices[0] = x - w/2;
	vertices[1] = y - h/2;
	vertices[2] = z;
	vertices[3] = x + w/2;
	vertices[4] = y - h/2;
	vertices[5] = z;	
	vertices[6] = x + w/2;
	vertices[7] = y + h/2;
	vertices[8] = z;
	vertices[9] = x - w/2;
	vertices[10] = y - h/2;
	vertices[11] = z;	
	vertices[12] = x - w/2;
	vertices[13] = y + h/2;
	vertices[14] = z;
	vertices[15] = x + w/2;
	vertices[16] = y + h/2;
	vertices[17] = z;
}

/// <summary>
/// Creates a 3d cube 
/// </summary>
/// <param name="x">Starting x location</param>
/// <param name="y">Starting y location</param>
/// <param name="z">Starting z location</param>
/// <param name="w">Width</param>
/// <param name="h">Height</param>
/// <param name="d">Depth</param>
/// <param name="vertices">GLFloat array we are putting the cube in</param>
void Shapes::getCube(float x, float y, float z, float w, float h, float d, GLfloat vertices[])
{
	// Front square
	vertices[0] = x - w / 2;
	vertices[1] = y - h / 2;
	vertices[2] = z - d / 2;
	vertices[3] = x + w / 2;
	vertices[4] = y - h / 2;
	vertices[5] = z - d / 2;
	vertices[6] = x + w / 2;
	vertices[7] = y + h / 2;
	vertices[8] = z - d / 2;
	vertices[9] = x - w / 2;
	vertices[10] = y - h / 2;
	vertices[11] = z - d / 2;
	vertices[12] = x - w / 2;
	vertices[13] = y + h / 2;
	vertices[14] = z - d / 2;
	vertices[15] = x + w / 2;
	vertices[16] = y + h / 2;
	vertices[17] = z - d / 2;

	// Back square
	vertices[18] = x - w / 2;
	vertices[19] = y - h / 2;
	vertices[20] = z + d/2;
	vertices[21] = x + w/2;
	vertices[22] = y - h / 2;
	vertices[23] = z + d/2;
	vertices[24] = x + w/2;
	vertices[25] = y + h/2;
	vertices[26] = z + d/2;
	vertices[27] = x - w / 2;
	vertices[28] = y - h / 2;
	vertices[29] = z + d/2;
	vertices[30] = x - w / 2;
	vertices[31] = y + h/2;
	vertices[32] = z + d/2;
	vertices[33] = x + w/2;
	vertices[34] = y + h/2;
	vertices[35] = z + d/2;

	// Right square
	vertices[36] = x + w/2;
	vertices[37] = y - h / 2;
	vertices[38] = z - d / 2;
	vertices[39] = x + w/2;
	vertices[40] = y - h / 2;
	vertices[41] = z + d/2;
	vertices[42] = x + w/2;
	vertices[43] = y + h/2;
	vertices[44] = z + d/2;
	vertices[45] = x + w/2;
	vertices[46] = y - h / 2;
	vertices[47] = z - d / 2;
	vertices[48] = x + w/2;
	vertices[49] = y + h/2;
	vertices[50] = z - d / 2;
	vertices[51] = x + w/2;
	vertices[52] = y + h/2;
	vertices[53] = z + d/2;

	// Left square
	vertices[54] = x - w / 2;
	vertices[55] = y - h / 2;
	vertices[56] = z - d / 2;
	vertices[57] = x - w / 2;
	vertices[58] = y - h / 2;
	vertices[59] = z + d/2;
	vertices[60] = x - w / 2;
	vertices[61] = y + h/2;
	vertices[62] = z + d/2;
	vertices[63] = x - w / 2;
	vertices[64] = y - h / 2;
	vertices[65] = z - d / 2;
	vertices[66] = x - w / 2;
	vertices[67] = y + h/2;
	vertices[68] = z - d / 2;
	vertices[69] = x - w / 2;
	vertices[70] = y + h/2;
	vertices[71] = z + d/2;

	// Top square
	vertices[72] = x - w / 2;
	vertices[73] = y + h/2;
	vertices[74] = z - d / 2;
	vertices[75] = x - w / 2;
	vertices[76] = y + h/2;
	vertices[77] = z + d/2;
	vertices[78] = x + w/2;
	vertices[79] = y + h/2;
	vertices[80] = z + d/2;
	vertices[81] = x - w / 2;
	vertices[82] = y + h/2;
	vertices[83] = z - d / 2;
	vertices[84] = x + w/2;
	vertices[85] = y + h/2;
	vertices[86] = z - d / 2;
	vertices[87] = x + w/2;
	vertices[88] = y + h/2;
	vertices[89] = z + d/2;

	// Bottom square
	vertices[90] = x - w / 2;
	vertices[91] = y - h / 2;
	vertices[92] = z - d / 2;
	vertices[93] = x - w / 2;
	vertices[94] = y - h / 2;
	vertices[95] = z + d/2;
	vertices[96] = x + w/2;
	vertices[97] = y - h / 2;
	vertices[98] = z + d/2;
	vertices[99] = x - w / 2;
	vertices[100] = y - h / 2;
	vertices[101] = z - d / 2;
	vertices[102] = x + w/2;
	vertices[103] = y - h / 2;
	vertices[104] = z - d / 2;
	vertices[105] = x + w/2;
	vertices[106] = y - h / 2;
	vertices[107] = z + d/2;

}

/// <summary>
/// Creates a 2D circle
/// </summary>
/// <param name="x">Starting x location</param>
/// <param name="y">Starting y location</param>
/// <param name="r">Radius</param>
/// <param name="vertices">GLFloat array we are putting the circle in</param>
void Shapes::getCircle(float x, float y, float r, GLfloat vertices[])
{
	// Loop through and make 48 different triangles in a circular pattern
	for (int i = 0; i < CIRCLE_COUNT; i += 9) {
	
		float angle1 = degToRad((i/9 * 7.5)); // This angle should match the last triangles angle 2
		float angle2 = degToRad(((i/9)+1) * 7.5); // This angle should match the next triangles angle 1

		// First point is always (x,y)
		vertices[i] = x;
		vertices[i + 1] = y;
		vertices[i + 2] = 0.0f;

		// Second point
		vertices[i + 3] = sin(angle1) * r;
		vertices[i + 4] = cos(angle1) * r;
		vertices[i + 5] = 0.0f;

		// Third point
		vertices[i + 6] = sin(angle2) * r;
		vertices[i + 7] = cos(angle2) * r;
		vertices[i + 8] = 0.0f;
	}
}

/// <summary>
/// Creates a 3d cylinder
/// </summary>
/// <param name="x">Starting x location</param>
/// <param name="y">Starting y location</param>
/// <param name="z">Starting z location</param>
/// <param name="h">Height</param>
/// <param name="r">Radius</param>
/// <param name="vertices">GLFloat array we are putting the cylinder in</param>
void Shapes::getCylinder(float x, float y, float z, float h, float r, GLfloat vertices[])
{
	int interval = CYLINDER_COUNT / 24;
	for (int i = 0; i < CYLINDER_COUNT; i += interval) {
		float angle1 = degToRad((i / interval * 15)); // This angle should match the last triangles angle 2
		float angle2 = degToRad(((i / interval) + 1) * 15); // This angle should match the next triangles angle 1

		// First point of the top circle is always (x,y,z)
		vertices[i] = x;
		vertices[i + 1] = y;
		vertices[i + 2] = z;

		// Second point of the top circle
		vertices[i + 3] = sin(angle1) * r;
		vertices[i + 4] = y;
		vertices[i + 5] = cos(angle1) * r;

		// Third point of the top circle
		vertices[i + 6] = sin(angle2) * r;
		vertices[i + 7] = y;
		vertices[i + 8] = cos(angle2) * r;

		// First point of the bottom circle 
		vertices[i + 9] = x;
		vertices[i + 10] = y - h;
		vertices[i + 11] = z;

		// Second point of the bottom circle
		vertices[i + 12] = sin(angle1) * r;
		vertices[i + 13] = y - h;
		vertices[i + 14] = cos(angle1) * r;

		// Third point of the bottom circle
		vertices[i + 15] = sin(angle2) * r;
		vertices[i + 16] = y - h;
		vertices[i + 17] = cos(angle2) * r;

		// Second point of top circle
		vertices[i + 18] = sin(angle1) * r;
		vertices[i + 19] = y;
		vertices[i + 20] = cos(angle1) * r;

		// Second point of bottom circle
		vertices[i + 21] = sin(angle1) * r;
		vertices[i + 22] = y - h;
		vertices[i + 23] = cos(angle1) * r;

		// Third point of top circle
		vertices[i + 24] = sin(angle2) * r;
		vertices[i + 25] = y;
		vertices[i + 26] = cos(angle2) * r;

		// Third point of the top circle
		vertices[i + 27] = sin(angle2) * r;
		vertices[i + 28] = y;
		vertices[i + 29] = cos(angle2) * r;

		// Third point of the bottom circle
		vertices[i + 30] = sin(angle2) * r;
		vertices[i + 31] = y - h;
		vertices[i + 32] = cos(angle2) * r;

		// Second point of bottom circle
		vertices[i + 33] = sin(angle1) * r;
		vertices[i + 34] = y - h;
		vertices[i + 35] = cos(angle1) * r;

	}
}

/// <summary>
/// Converts degress to radians
/// </summary>
/// <param name="degree">Angle in degrees</param>
/// <returns>Angle in radians</returns>
float Shapes::degToRad(float degree)
{
	return (degree * (3.1415926 / 180));
}
