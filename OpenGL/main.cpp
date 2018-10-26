
/*
* Atlas - bit.ly/programgames
* https://github.com/IGME-RIT/Basic-OpenGL-with-GLFW-creating-a-window
*/

#define GLEW_STATIC

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"
#include "Material.h"
#include "Mesh.h"
#include "GameEntity.h"
#include "Input.h"
#include "Shapes.h"
#include "Node.h"

#include <cstdlib>
#include <ctime>

int main() {

	//init GLFW
	{
		if (glfwInit() == GLFW_FALSE)
		{
#ifdef _DEBUG
			std::cout << "GLFW failed to initialize" << std::endl;
			_CrtDumpMemoryLeaks();
			std::cin.get();
#endif
			return 1;
		}
	}
#ifdef _DEBUG
	std::cout << "GLFW successfully initialized!" << std::endl;
#endif // _DEBUG

	// Make a window
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", nullptr, nullptr);

	// Close everything if window is null
	if (window == nullptr) {
		glfwTerminate();
		return 1;
	}

	int screenWidth;
	int screenHeight;

	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	// Create window
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		glfwTerminate();
		return 1;
	}

	glViewport(0, 0, screenWidth, screenHeight);

	// Init the shader program
	GLuint shaderProgram = glCreateProgram();
	{
		// Create vertex shader and attach
		Shader *vs = new Shader();
		vs->InitFromFile("../assets/shaders/vertexShader.glsl", GL_VERTEX_SHADER);
		glAttachShader(shaderProgram, vs->GetShaderLoc());

		// Create fragment shader and attach
		Shader *fs = new Shader();
		fs->InitFromFile("../assets/shaders/fragmentShader.glsl", GL_FRAGMENT_SHADER);
		glAttachShader(shaderProgram, fs->GetShaderLoc());

		// Link everything that's attached together
		glLinkProgram(shaderProgram);

		GLint isLinked;
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &isLinked);
		
		// If it didn't link terminate
		if (!isLinked)
		{
			char infolog[1024];
			glGetProgramInfoLog(shaderProgram, 1024, NULL, infolog);
#ifdef _DEBUG
			std::cout << "Shader Program linking failed with error: " << infolog << std::endl;
			std::cin.get();
#endif

			// Delete the shader, and set the index to zero so that this object knows it doesn't have a shader.
			glDeleteProgram(shaderProgram);
			glfwTerminate();
			_CrtDumpMemoryLeaks();
			return 1;
		}

		// These are in the program so we don't need them anymore
		delete fs;
		delete vs;
	}

#ifdef _DEBUG
	std::cout << "Shaders compiled attached, and linked!" << std::endl;
#endif // _DEBUG


	std::vector<Node*> nodes;
	int cubeCount = 8;

	int w = 10;
	int h = 5;
	srand(time(NULL));

	// Create 8 cubes, meshes, materials & game entites
	for (int i = 0; i < cubeCount; i++) {
		float x = i;
		float y = i;

		// Set the x values based on their position in the list
		if (i == 0) {
			x = -w;
		}
		else if (i == cubeCount - 1) {
			x = w;
		}
		else if (i == cubeCount / 2 || i == (cubeCount / 2) - 1) {
			x = 0;
		}
		else if (i < cubeCount / 2) {
			x = -w / 2;
		}
		else {
			x = w / 2;
		}

		// Set the y values based on their position in the list
		if (i == 0 || i == (cubeCount / 2) - 1 || i == cubeCount - 1) {
			y = 0;
		}
		else if (i % 2 == 0) {
			y = -h;
		}
		else {
			y = h;
		}

		// Slight random devation so the graph isn't always the same
		float randX = (rand() % 10);
		float randY = (rand() % 10);
		randX /= 10;
		randY /= 10;
		std::cout << "RandX: " << randX << " RandY: " << randY << std::endl;
		x += randX;
		y += randY;

		Node* node = new Node(shaderProgram, x, y, i);
		nodes.push_back(node);
	}

	// Assign the children
	nodes[0]->setNeighbors(std::vector<Node*>{nodes[1], nodes[2], nodes[3]});
	nodes[1]->setNeighbors(std::vector<Node*>{nodes[0], nodes[3], nodes[5]});
	nodes[2]->setNeighbors(std::vector<Node*>{nodes[0], nodes[3], nodes[4]});
	nodes[3]->setNeighbors(std::vector<Node*>{nodes[0], nodes[1], nodes[2], nodes[4], nodes[5], nodes[6]});
	nodes[4]->setNeighbors(std::vector<Node*>{nodes[2], nodes[3], nodes[6]});
	nodes[5]->setNeighbors(std::vector<Node*>{nodes[1], nodes[3], nodes[6], nodes[7]});
	nodes[6]->setNeighbors(std::vector<Node*>{nodes[3], nodes[4], nodes[5], nodes[7]});
	nodes[7]->setNeighbors(std::vector<Node*>{nodes[5], nodes[6]});
	
	// Our camera
	Camera* myCamera = new Camera(
		glm::vec3(0.0f, 0.0f, -15.0f), // Position of the camera
		glm::vec3(0.0f, 0.0f, 1.0f), // The 'forward' of the camera
		glm::vec3(0.0f, 1.0f, 0.0f), // 'Up' for the camera
		60.0f, // The field of view in radians
		(float)screenWidth, // The window width
		(float)screenHeight, // The window height
		0.01f, // The near Z-plane
		100.0f // The far Z-plane
	);

	Input::GetInstance()->Init(window);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// Game loop
	while (!glfwWindowShouldClose(window)) {

		// Get all input
		glfwPollEvents();

		Input* input = Input::GetInstance();

		if (input->IsKeyDown(GLFW_KEY_S)) {
			for (Node* node : nodes) {
				node->Spin();
			}
		}

		// Gameplay update
		for (Node* node : nodes) {
			node->Update();
		}
		myCamera->Update();
		
		// Clear color & buffer every frame
		glClearColor(0.392f, 0.584f, 0.929f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Render
		for (Node* node : nodes) {
			node->Render(myCamera);
		}

		// Post-Render
		glBindVertexArray(0);
		glUseProgram(0);
		glfwSwapBuffers(window);
	}

	// De-allocate our nodes
	for (Node* node : nodes) {
		delete node;
	}
	nodes.clear();

	delete myCamera;
	Input::Release();

	//clean up
	glfwTerminate();
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif // _DEBUG

	return 0;
}