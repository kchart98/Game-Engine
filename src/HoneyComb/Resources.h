#include "Resource.h"

#include <list>
#include <memory>
#include <iostream>

class Resources
{

	std::list<std::shared_ptr<Resource>> resources;
	
public:

	/*Get Resorce?
	template <typename T>
	std::shared_ptr<T> getResources()
	{
		for (size_t i = 0; i < resources.size(); i++)
		{
			std::shared_ptr<T> tst = std::dynamic_pointer_cast<T>(resources.at(i));

			if (tst)
			{
				return tst;
			}
		}

		throw std::exception();
	}
	*/


	//Load Resource
	template <typename T>
	std::shared_ptr<T> load(std::string path)
	{
		
			




	}



	//Create resource
	template <typename T>
	std::shared_ptr<T> create()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(); \
		rtn->entity = self; \
		rtn->began = false; \

		resources.push_back(rtn);
		rtn->onInit();

		return rtn;

	}
	
};