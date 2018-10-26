#include "Node.h"



Node::Node(GLuint shaderProgram, float _x, float _y, int _id)
{
	// The id that represents this node
	id = _id;

	// Shape variable to create cube
	Shapes shape = Shapes();

	// Create the cube
	GLfloat cube[CUBE_COUNT];
	shape.getCube(0, 0, 0, 1, 1, 1, cube);

	// Init the mesh
	myMesh = new Mesh();
	myMesh->InitWithVertexArray(cube, _countof(cube), shaderProgram);
	
	// Init the material
	myMaterial = new Material(shaderProgram);

	// The x & y coords for this node
	x = _x;
	y = _y;

	// Init the game entity
	myGameEntity = new GameEntity(
		myMesh,
		myMaterial,
		glm::vec3(x, y, 0.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(1.0f, 1.0f, 1.0f)
	);
}


Node::~Node()
{
}

void Node::Update()
{
	myGameEntity->Update();
}

void Node::Spin()
{
	myGameEntity->SetSpinning(true);
}

void Node::Reset()
{
	myGameEntity->SetSpinning(false);
}

void Node::Render(Camera* myCamera)
{
	myGameEntity->Render(myCamera);
}

void Node::setNeighbors(std::vector<Node*> _neighbors)
{
	neighbors = _neighbors;
}
