#pragma once
#include "Window.h"

namespace TVE
{

class App01
{
public:
	static constexpr int APP_WIDTH	= 640;
	static constexpr int APP_HEIGHT = 480;

	void Run();

private:
	VulkanWindow window{ APP_WIDTH, APP_HEIGHT, "Vulkan App 01!" };

};

} // namespace TVE



