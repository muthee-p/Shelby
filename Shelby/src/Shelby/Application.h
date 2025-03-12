#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Shelby {

	class SHELBY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//to be defined by client
	Application* CreateApplication();
}

