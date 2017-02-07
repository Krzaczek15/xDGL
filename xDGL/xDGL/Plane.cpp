#include "Plane.h"

Plane::Plane() {
	Init();
}

void Plane::Init() {
	colorVertices = { { glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.2f, 0.3f, 0.4f) },
					  { glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec3(0.4f, 0.3f, 0.2f) },
					  { glm::vec3( 0.5f,  0.5f, 0.0f), glm::vec3(1.0f, 0.5f, 1.0f) },
					  { glm::vec3(-0.5f,  0.5f, 0.0f), glm::vec3(1.0f, 0.5f, 1.0f) }
	};

	indices = {0, 1, 2,
			   2, 3, 0};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, colorVertices.size() * sizeof(colorVertex), &colorVertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(colorVertex), (GLvoid*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(colorVertex), (GLvoid*)(offsetof(colorVertex, color)));

	glBindVertexArray(0);
}

void Plane::Draw(Shader shader) {
	shader.Use();

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}