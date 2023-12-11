#pragma once

#include "Pipeline.h"
#include "EngineDevice.h"
#include "SwapChain.h"
#include "Window.h"

// std
#include <memory>
#include <vector>

namespace TVE
{

class App01
{
public:
	static constexpr int APP_WIDTH	= 640;
	static constexpr int APP_HEIGHT = 480;

	App01();
	~App01();

	App01(const App01&) = delete;
	App01& operator=(const App01&) = delete;

	void Run();

private:

	void CreatePipelineLayout();
	void CreatePipeline();
	void CreateCommandBuffers();
	void DrawFrame();

	VulkanWindow window{ APP_WIDTH, APP_HEIGHT, "Vulkan App 01!" };
	EngineDevice engineDevice{ window };
	SwapChain swapChain{ engineDevice, window.GetExtent() };
	std::unique_ptr<Pipeline> pipeline;
	VkPipelineLayout pipelineLayout;
	std::vector<VkCommandBuffer> commandBuffers;

};

} // namespace TVE



