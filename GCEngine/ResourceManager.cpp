#include "ResourceManager.h"

namespace engine
{

	ResourceManager::ResourceManager()
	{

	}

	ResourceManager::~ResourceManager()
	{

	}

	void ResourceManager::addResource(std::string key, Resource* r)
	{
		m_resources[key] = r;
	}

	Resource * ResourceManager::getResource(std::string key)
	{
		Resource* r = ResourceManager::GetInstance().m_resources[key];

		if (r)
		{
			return r;
		}

		return nullptr;


	}

}