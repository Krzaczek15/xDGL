#include "Cube.h"

Cube::Cube() : cubePos(0.0f, 0.0f, 0.0f), cubeColor(0.5f, 0.5f, 0.5f) {
	Init();
}

void Cube::Init() {
	colorVertices = { { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f,  0.0f, -1.0f) },
					  { glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(0.0f,  0.0f, -1.0f) },
				  	  { glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.0f,  0.0f, -1.0f) },
					  { glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.0f,  0.0f, -1.0f) },
					  { glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f,  0.0f, -1.0f) },
					  { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f,  0.0f, -1.0f) },

					  { glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.0f,  0.0f,  1.0f) },
					  { glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(0.0f,  0.0f,  1.0f) },
					  { glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(0.0f,  0.0f,  1.0f) },
					  { glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(0.0f,  0.0f,  1.0f) },
					  { glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.0f,  0.0f,  1.0f) },
					  { glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.0f,  0.0f,  1.0f) }, 

					  { glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(-1.0f,  0.0f,  0.0f) },
					  { glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(-1.0f,  0.0f,  0.0f) },
					  { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f,  0.0f,  0.0f) },
					  { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f,  0.0f,  0.0f) },
					  { glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(-1.0f,  0.0f,  0.0f) },
					  { glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(-1.0f,  0.0f,  0.0f) },

					  { glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(1.0f,  0.0f,  0.0f) },
					  { glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(1.0f,  0.0f,  0.0f) },
					  { glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(1.0f,  0.0f,  0.0f) },
					  { glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(1.0f,  0.0f,  0.0f) },
					  { glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(1.0f,  0.0f,  0.0f) },
					  { glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(1.0f,  0.0f,  0.0f) }, 
						
					  { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f,  0.0f) },
					  { glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f,  0.0f) },
					  { glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(0.0f, -1.0f,  0.0f) },
					  { glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(0.0f, -1.0f,  0.0f) },
					  { glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.0f, -1.0f,  0.0f) },
					  { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f,  0.0f) },

					  { glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f,  1.0f,  0.0f) },
					  { glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.0f,  1.0f,  0.0f) },
					  { glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(0.0f,  1.0f,  0.0f) },
					  { glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(0.0f,  1.0f,  0.0f) },
					  { glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.0f,  1.0f,  0.0f) },
					  { glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f,  1.0f,  0.0f) } 
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

void Cube::Draw(Shader shader, Camera* camera, glm::vec3 lightPos) {
	shader.Use();
	
	shader.setVector3("objectColor", cubeColor);
	shader.setVector3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	shader.setVector3("lightPos", lightPos);
	shader.setVector3("viewPos", camera->cameraPos);

	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

	model = glm::translate(model, cubePos);
	//model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 65.0f), glm::vec3(0.0, 1.0f, 0.0f));
	projection = glm::perspective(glm::radians(45.0f), float(400) / float(300), 0.1f, 100.0f);

	shader.setMatrix4("model", model);
	shader.setMatrix4("view", camera->getView());
	shader.setMatrix4("projection", projection);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}

void Cube::setPosition(glm::vec3 position) {
	cubePos = position;
}

void Cube::setColor(glm::vec3 color) {
	cubeColor = color;
}