#pragma once
#include "Node.h"
#include "stdafx.h"
#include <math.h>

class Dijkstras
{
public:
	Dijkstras();
	~Dijkstras();
	void Sort(std::vector<Node*>);
private:
	Node* lowestDistance(std::vector<Node*>);
	int getIndex(std::vector<Node*>, Node*);
	float calculateDistance(Node*, Node*);
};

