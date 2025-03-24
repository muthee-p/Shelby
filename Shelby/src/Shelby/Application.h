#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "/dev/Shelby/Shelby/Window.h"

namespace Shelby {

	class SHELBY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};


	//to be defined by client
	Application* CreateApplication();
}

