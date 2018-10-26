#pragma once
#include "stdafx.h"
#include "Mesh.h"
#include "Material.h"
#include "GameEntity.h"
#include "Shapes.h"
#include <vector>

class Node
{
public:
	Node(GLuint, float, float);
	~Node();
	void Update();
	void Spin();
	void Reset();
	void Render(Camera*);
private:
	Mesh* myMesh;
	Material* myMaterial;
	GameEntity* myGameEntity;
	bool visited;
	std::vector<Node*> neighbors;
	Node* nearestNeighbor;
	float x, y;
};

