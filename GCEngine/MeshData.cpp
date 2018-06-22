#include "MeshData.h"

namespace engine
{
	MeshData::MeshData(const std::vector<float>& vertices, const std::vector<int>& indices) :
		m_vertices(vertices), m_indices(indices)
	{
		//empty
	}

	MeshData::~MeshData()
	{
		m_indices.clear();
		m_vertices.clear();
	}

	bool MeshData::init()
	{
		return true;
	}

	bool MeshData::shutdown()
	{
		return true;
	}

}