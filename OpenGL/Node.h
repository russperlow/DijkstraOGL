#pragma once
#include "stdafx.h"
#include "Mesh.h"
#include "Material.h"
#include "GameEntity.h"
#include "Shapes.h"
#include "stdafx.h"

class Node
{
public:
	Node(GLuint, float, float, int);
	~Node();
	void Update();
	void Spin();
	void Reset();
	void Render(Camera*);
	void setNeighbors(std::vector<Node*>);
private:
	Mesh* myMesh;
	Material* myMaterial;
	GameEntity* myGameEntity;
	bool visited;
	std::vector<Node*> neighbors;
	Node* nearestNeighbor;
	float x, y;
	int id;
};

