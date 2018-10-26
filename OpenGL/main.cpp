
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

	// Init the mesh
	Shapes shapes = Shapes();

	std::vector<GLfloat*> shapeVerts;
	std::vector<Mesh*> meshes;
	std::vector<Material*> materials;
	std::vector<GameEntity*> gameEntities;
	int cubeCount = 1;

	// Create 8 cubes, meshes, materials & game entites
	for (int i = 0; i < cubeCount; i++) {
		// Cubes
		GLfloat cube[CUBE_COUNT];
		shapes.getCube(0, 0, 0, 1, 1, 1, cube);
		shapeVerts.push_back(cube);

		// Meshes
		Mesh* myMesh = new Mesh();
		myMesh->InitWithVertexArray(cube, _countof(cube), shaderProgram);
		meshes.push_back(myMesh);

		// Material
		Material* myMaterial = new Material(shaderProgram);
		materials.push_back(myMaterial);

		float x = 0;
		float y = 0;


		// Game Entity
		GameEntity* myGameEntity = new GameEntity(
			myMesh,
			myMaterial,
			glm::vec3(x, y, 0.0f),
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(1.0f, 1.0f, 1.0f)
		);
		gameEntities.push_back(myGameEntity);
	}
	
	// Our camera
	Camera* myCamera = new Camera(
		glm::vec3(0.0f, 0.0f, -5.0f), // Position of the camera
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
			for (GameEntity* gameEntity : gameEntities) {
				gameEntity->SetSpinning(true);
			}
		}

		// Gameplay update
		for (GameEntity* gameEntity : gameEntities) {
			gameEntity->Update();
		}
		myCamera->Update();
		
		// Clear color & buffer every frame
		glClearColor(0.392f, 0.584f, 0.929f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Render
		for (GameEntity* gameEntity : gameEntities) {
			gameEntity->Render(myCamera);
		}

		// Post-Render
		glBindVertexArray(0);
		glUseProgram(0);
		glfwSwapBuffers(window);
	}

	// De-allocate our meshes
	for (Mesh* mesh : meshes) {
		delete mesh;
	}
	meshes.clear();

	// De-allocate our materials
	for (Material* material : materials) {
		delete material;
	}
	materials.clear();

	// De-allocate our game entities
	for (GameEntity* gameEntity : gameEntities) {
		delete gameEntity;
	}
	gameEntities.clear();

	delete myCamera;
	Input::Release();

	//clean up
	glfwTerminate();
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif // _DEBUG

	return 0;
}