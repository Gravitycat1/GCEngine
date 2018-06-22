#include "MeshComponent.h"
#include "ShaderProgram.h"
#include "MeshData.h"

#include <GL\glew.h>

namespace engine
{
	MeshComponent::MeshComponent(MeshData * md, ShaderProgram * sp) :
		m_meshData(md), m_shaderProgram(sp)
	{

	}

	MeshComponent::~MeshComponent()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteVertexArrays(1, &VBO);
		glDeleteVertexArrays(1, &EBO);
	}

	bool MeshComponent::init()
	{
		//creating the buffer
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(m_meshData->getVertices()[0]) * m_meshData->getVertices().size(),
											m_meshData->getVertices().data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(m_meshData->getIndices()[0]) * m_meshData->getIndices().size(),
													m_meshData->getIndices().data(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		return true;
	}
	void MeshComponent::update()
	{
	}
	void MeshComponent::draw() const
	{
		//drawing square
		m_shaderProgram->use();
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
	bool MeshComponent::shutdown()
	{
		return true;
	}
}