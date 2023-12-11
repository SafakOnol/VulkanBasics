#pragma once
#include "Window.h"
#include "Pipeline.h"
#include "EngineDevice.h"

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
	EngineDevice engineDevice{ window };
	Pipeline pipeline
	{
		engineDevice,
		"shaders/SimpleShader.vert.spv",
		"shaders/SimpleShader.frag.spv",
		Pipeline::DefaultPipelineConfigInfo(configInfo, APP_WIDTH, APP_HEIGHT)
	}; // path relative to the exe file


};

} // namespace TVE



