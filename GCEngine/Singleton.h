#pragma once
#ifndef _SINGLETON_H
#define _SINGLETON_H

namespace engine
{
	template <class T>// templates the whole class
	class Singleton // only let there be one instance of this class
	{
	private:
		static T* m_instance;// this should  not be public

	protected:
		Singleton() {}// all constructors are private or protected


	public:
		// const T& - ask about
		static const T& GetInstance();
		
	};

	template <class T>
	//static var need to be defined outside the classw
	T* Singleton<T>::m_instance = nullptr;
}
	#endif // !_SINGLETON_H