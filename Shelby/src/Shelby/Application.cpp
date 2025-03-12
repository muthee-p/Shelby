#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Shelby {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SB_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SB_TRACE(e);
		}

		while (true);
	}
}