#pragma once
#include "Resource.h"

#include <vector>

namespace engine
{
	class MeshData : public Resource
	{
		std::vector<float> m_vertices;
		std::vector<int> m_indices;

	public:
		MeshData(const std::vector<float>& vertices, const std::vector<int>& indices);
		~MeshData();

		bool init() override;
		bool shutdown() override;

		inline std::vector<float> getVertices() const { return m_vertices; }
		inline std::vector<int> getIndices() const { return m_indices; }


	};
}