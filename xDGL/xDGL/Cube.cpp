#include "Cube.h"

Cube::Cube() {
	Init();
}

void Cube::Init() {
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

void Cube::Draw(Shader shader) {
	shader.Use();
	
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

	model = glm::rotate(model, glm::radians((GLfloat)glfwGetTime() * 65.0f), glm::vec3(1.0, 0.3f, 0.5f));
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	projection = glm::perspective(45.0f, (GLfloat)(400 / 300), 0.1f, 100.0f);	

	GLint modelLoc = glGetUniformLocation(shader.ID, "model");
	GLint viewLoc = glGetUniformLocation(shader.ID, "view");
	GLint projLoc = glGetUniformLocation(shader.ID, "projection");

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}