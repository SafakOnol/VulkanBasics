#pragma once
#include "Window.h"
#include "Pipeline.h"

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
	Pipeline pipeline{ "shaders/SimpleShader.vert.spv", "shaders/SimpleShader.frag.spv" }; // path relative to the exe file


};

} // namespace TVE



