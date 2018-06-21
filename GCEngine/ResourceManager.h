#pragma once

#include "Singleton.h"

#include <unordered_map>


namespace engine
{

	class Resource;

	class ResourceManager : public Singleton<ResourceManager>
	{
		friend Singleton;

		std::unordered_map<std::string, Resource*> m_resources;

	protected:
		ResourceManager();

	public:
		~ResourceManager();

		void addResource(std::string key, Resource* r);
		Resource* getResource(std::string key);

	};
}