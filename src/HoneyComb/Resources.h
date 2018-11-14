#include "Resource.h"
#include <vector>
#include <memory>
#include <string>
#include <iostream>

class Resources
{

private:

	std::vector<std::shared_ptr<Resource>> resourcesList;

public:
	template <typename T>
	std::shared_ptr<T> load(std::string path)
	{
		for (size_t i = 0; i < resourcesList.size(); i++)
		{
			if (resourcesList.at(i)->getPath() == path)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(resourcesList.at(i));

				if (!rtn)
				{
					throw std::exception();
				}

				return rtn;
			}
		}

		std::shared_ptr<T> rtn = std::make_shared<T>();
		rtn->load(path);
		resourcesList.push_back(rtn);

		return rtn;

	}

	/*
	template <typename T, typename A, typename B>
	std::shared_ptr<T> create(A a, B b)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		rtn->platform = platform;
		rtn->onCreate(a, b);
		return rtn;
	}
	*/

};
