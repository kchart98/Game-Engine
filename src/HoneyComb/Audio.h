#include <memory>
#include <string>

struct AudioImpl;

class Audio
{
	std::shared_ptr<AudioImpl> impl;

public:

	Audio();
	Audio(std::string path);
	void load(std::string path);
	void play();

};