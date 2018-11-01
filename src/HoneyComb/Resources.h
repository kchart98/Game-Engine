#include "Resource.h"

#include <list>
#include <memory>
#include <iostream>
#include <stb_image/stb_image.h>

class Resources
{
	std::list<std::shared_ptr<Resource>> resources;
	
public:

	//Load Resource
	template <typename T>
	std::shared_ptr<T> load(std::string path)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(); 
		rtn->load(path);
		return rtn;
	}


	//Create resource
	template <typename T>
	std::shared_ptr<T> create()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(); 


		resources.push_back(rtn);
		return rtn;

	}

	template <typename T, typename A, typename B>
	std::shared_ptr<T> create(A a, B b)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(); 


		resources.push_back(rtn);
		return rtn;
	}
	
};