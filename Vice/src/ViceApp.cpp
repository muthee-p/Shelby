#include "Shelby.h"

class Vice : public Shelby::Application
{
public:
	Vice()
	{

	}
	~Vice()
	{

	}
};

Shelby::Application* Shelby::CreateApplication()
{
	return new Vice();
}