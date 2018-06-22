#include "GameObject.h"
#include "Component.h"

namespace engine
{
	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
	}

	bool GameObject::init()
	{
		return true;
	}

	void GameObject::update()
	{
		for (Component* c : m_components)
		{
			c->update();
		}

		for (GameObject* go : m_children)
		{
			go->update();
		}
	}

	void GameObject::draw() const
	{
		for (Component* c : m_components)
		{
			c->draw();
		}

		for (GameObject* go : m_children)
		{
			go->draw();
		}
	}

	bool GameObject::shutdown()
	{
		return true;
	}

	void GameObject::addChild(GameObject* go)
	{
		m_children.push_back(go);
	}

	void GameObject::addComponent(Component * c)
	{
		m_components.push_back(c);
	}

}