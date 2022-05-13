#pragma once

#include <memory>

namespace Engine
{
	template <typename T>
	class Singleton
	{
	private:
		static std::shared_ptr<T> _instance;

	public:
		static std::shared_ptr<T> getInstance()
		{
			if (_instance == nullptr)
			{
				_instance = std::make_shared<T>();
			}

			return _instance;
		}

		static void setInstance(std::shared_ptr<T> instance)
		{
			_instance = instance;
		}

		static void destroyInstance()
		{
			if (_instance)
			{
				delete _instance;
			}
		}
	};

	template <typename T> std::shared_ptr<T> Singleton<T>::_instance = nullptr;
}