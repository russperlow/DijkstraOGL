#include "GameEntity.h"
#include "Input.h"
#include "glm/gtc/matrix_transform.hpp"

GameEntity::GameEntity(Mesh * mesh,
	Material * material,
	glm::vec3 position,
	glm::vec3 eulerAngles,
	glm::vec3 scale)
{
	this->mesh = mesh;
	this->material = material;
	this->position = position;
	this->startPosition = position;
	this->eulerAngles = eulerAngles;
	this->scale = scale;
	worldMatrix = glm::identity<glm::mat4>();
}

GameEntity::~GameEntity()
{
}

void GameEntity::SetSpinning(bool shouldSpin) {
	spinning = shouldSpin;
}

bool GameEntity::isSpinning()
{
	return spinning;
}

void GameEntity::Reset()
{
	eulerAngles = glm::vec3(0);
	position = startPosition;
	scale = glm::vec3(1);
	SetSpinning(false);
}

void GameEntity::Update()
{

	float multiplier = 1.f;

	if (spinning)
	{
		eulerAngles.z += 0.001f * multiplier;
	}

	//construction of world matrix
	worldMatrix = glm::identity<glm::mat4>();

	worldMatrix = glm::translate(worldMatrix, position);

	worldMatrix = glm::rotate(worldMatrix,
		this->eulerAngles.z, glm::vec3(0.f, 0.f, 1.f));

	worldMatrix = glm::scale(worldMatrix, scale);
}

void GameEntity::Render(Camera* camera)
{
	material->Bind(camera, worldMatrix);
	mesh->Render();
}
