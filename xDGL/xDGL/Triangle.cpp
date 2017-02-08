#include "Triangle.h"

Triangle::Triangle() {
	Init();
}

void Triangle::Init() {
	colorVertices = {  {glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.2f, 0.3f, 0.4f)},
					   {glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec3(0.4f, 0.3f, 0.2f)},
					   {glm::vec3( 0.0f,  0.5f, 0.0f), glm::vec3(1.0f, 0.5f, 1.0f)} 
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, colorVertices.size()*sizeof(colorVertex), &colorVertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(colorVertex), (GLvoid*)0);
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(colorVertex), (GLvoid*)(offsetof(colorVertex, color)));

	glBindVertexArray(0);
}

void Triangle::Draw(Shader shader, Camera* camera) {
	shader.Use();

	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 10.0f));
	model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 65.0f), glm::vec3(0.0, 0.0f, 1.0f));
	//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	view = camera->getView();
	projection = glm::perspective(glm::radians(45.0f), (GLfloat)(400 / 300), 0.1f, 100.0f);

	shader.SetMatrix4("model", model);
	shader.SetMatrix4("view", view);
	shader.SetMatrix4("projection", projection);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}

