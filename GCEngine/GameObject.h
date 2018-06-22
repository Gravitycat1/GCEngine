#pragma once

#include <vector>

namespace engine
{
	class GameObject
	{
		std::vector<GameObject*> m_children;
		std::vector<class Component*> m_components;

	public:
		GameObject();
		virtual ~GameObject();

		virtual bool init();
		virtual void update();
		virtual void draw() const;
		virtual bool shutdown();

		void addChild(GameObject* go);
		inline std::vector<GameObject*> getChildren() const { return m_children; }

		void addComponent(class Component* c);

		template<class T>
		T* getComponent() const
		{
			for (class Component*c : m_components)
			{
				T* comp = dynamic_cast<T*>(c);

				if (comp)
					return comp;
			}

			return nullptr;
		}

		inline std::vector<class Component*> getComponents() const { return m_components; }

	};
}