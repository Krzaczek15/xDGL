#include "LightSource.h"

LightSource::LightSource() : lightPos(1.5f, 1.0f, 2.0f) {
	Init();
}

void LightSource::Init() {
	colorVertices = { { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.2f, 0.7f) },
	{ glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.6f, 0.9f) },
	{ glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.5f, 0.1f, 0.2f) },
	{ glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.2f, 0.2f, 0.2f) },
	{ glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 0.1f) },
	{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 0.0f) },

	{ glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.0f, 0.0f, 0.7f) },
	{ glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(0.5f, 0.0f, 0.1f) },
	{ glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 0.1f, 0.1f) },
	{ glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 0.6f, 0.2f) },
	{ glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.0f, 0.9f, 0.9f) },
	{ glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.7f) },

	{ glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.0f, 0.0f, 0.7f) },
	{ glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 0.0f, 0.7f) },
	{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 0.7f) },
	{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 0.1f) },
	{ glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.2f, 0.1f) },
	{ glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.3f, 0.4f, 0.0f) },

	{ glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(0.0f, 0.0f, 1.0f) },
	{ glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 1.0f, 1.7f) },
	{ glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 1.0f, 1.0f) },
	{ glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(0.7f, 0.7f, 0.1f) },
	{ glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(0.0f, 0.2f, 0.7f) },
	{ glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(0.0f, 0.6f, 0.0f) },

	{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.5f, 0.5f, 0.1f) },
	{ glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.7f, 0.2f) },
	{ glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(0.0f, 0.2f, 0.7f) },
	{ glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(0.0f, 0.8f, 0.7f) },
	{ glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 0.5f, 0.0f) },
	{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 0.0f, 0.0f) },

	{ glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 0.2f, 0.7f) },
	{ glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 0.1f, 0.1f) },
	{ glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 1.0f, 0.6f) },
	{ glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 0.1f, 0.9f) },
	{ glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.5f, 1.0f, 1.0f) },
	{ glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.1f, 0.2f, 0.7f) }
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, colorVertices.size() * sizeof(colorVertex), &colorVertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(colorVertex), (GLvoid*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(colorVertex), (GLvoid*)(offsetof(colorVertex, color)));

	glBindVertexArray(0);
}

void LightSource::Draw(Shader shader, Camera* camera) {
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

	//lightPos = glm::vec3(sin(glfwGetTime())*3.0f, 4.0f, cos(glfwGetTime())*3.0f);

	model = glm::translate(model, lightPos);
	model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 65.0f), glm::vec3(0.0, 1.0f, 0.0f));
	model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
	projection = glm::perspective(45.0f, float(400)/float(300), 0.1f, 100.0f);

	shader.setMatrix4("model", model);
	shader.setMatrix4("view", camera->getView());
	shader.setMatrix4("projection", projection);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}

void LightSource::setPosition(glm::vec3 lightPos) {
	this->lightPos = lightPos;
}

glm::vec3 LightSource::getPosition() {
	return lightPos;
}