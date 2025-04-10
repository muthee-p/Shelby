#pragma once

#include "sbpch.h"
#include "Shelby/Core.h"
#include "Shelby/Events/Event.h"

//#include <string>
//#include <functional>

namespace Shelby {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Shelby Engine",
			unsigned int width = 1200,
			unsigned int height = 700)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	class SHELBY_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}
