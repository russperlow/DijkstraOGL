#include "Dijkstras.h"



Dijkstras::Dijkstras()
{
}


Dijkstras::~Dijkstras()
{
}

void Dijkstras::Sort(std::vector<Node*> graph)
{
	// Init all nodes
	std::vector<Node*> nodes = graph;
	for (Node* node : nodes) {
		node->setDistance(FLT_MAX);
		node->setPrevious(NULL);
	}
	nodes[0]->setDistance(0);

	// Find the shortest path for all nodes
	while (!nodes.empty()) {

		// Get the lowest node remaining then remove it from the vector
		Node* currentNode = lowestDistance(nodes);
		nodes.erase(nodes.begin() + getIndex(nodes, currentNode));

		// Loop through current nodes neighbors
		for (Node* neighbor : currentNode->getAllNeighbors()) {
			float alt = currentNode->getDistance() + calculateDistance(currentNode, neighbor);

			// If alt is less than the neighbors current distance, we've found a shorter path to the neighbor node
			if (alt < neighbor->getDistance()) {
				neighbor->setDistance(alt);
				neighbor->setPrevious(currentNode);
			}
		}
	}

	std::cout << "Dijkstras Done!" << std::endl;

	Node* prevNode = graph[static_cast<int>(graph.size()) - 1];
	std::cout << prevNode->getId() << "->";
	float path = 0;
	while (prevNode->getPrevious() != NULL) {
		path += prevNode->getDistance();
		prevNode = prevNode->getPrevious();
		std::cout << prevNode->getId() << "->";
	}
	std::cout << "\nPath Distance: " << path << std::endl;
}

Node* Dijkstras::lowestDistance(std::vector<Node*> nodes)
{
	Node* lowestNode = nodes[0];

	for (Node* node : nodes) {
		if (node->getDistance() < lowestNode->getDistance())
			lowestNode = node;
	}

	return lowestNode;
}

int Dijkstras::getIndex(std::vector<Node*> nodes, Node* node)
{
	int index = 0;

	for (int i = 0; i < static_cast<int>(nodes.size()); i++) {
		if (nodes[i] == node) {
			index = i;
			break;
		}
	}

	return index;
}

float Dijkstras::calculateDistance(Node* node1, Node* node2)
{
	float xSq = (node2->getX() - node1->getX()) * (node2->getX() - node1->getX());
	float ySq = (node2->getY() - node1->getY()) * (node2->getY() - node1->getY());

	return sqrt(xSq + ySq);
}


