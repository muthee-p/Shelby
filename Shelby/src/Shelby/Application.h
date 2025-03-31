#pragma once

#include "Core.h"

#include "LayerStack.h"
#include "Events/Event.h"
#include "Shelby/Window.h"
#include "Events/ApplicationEvent.h"

namespace Shelby {

	class SHELBY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};


	//to be defined by client
	Application* CreateApplication();
}

