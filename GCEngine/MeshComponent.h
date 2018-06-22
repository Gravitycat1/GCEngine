#pragma once
#include "Component.h"
namespace engine
{
	class MeshComponent : public Component
	{
		//maybe this should be saved inside the meshdata resource
		//with shaderprogram
		unsigned int VAO, VBO, EBO;
		class MeshData* m_meshData;
		class ShaderProgram* m_shaderProgram;

	public:
		MeshComponent(class MeshData* md, class ShaderProgram* sp);
		~MeshComponent();

		bool init() override;
		void update() override;
		void draw() const override;
		bool shutdown() override;
		

	};
}