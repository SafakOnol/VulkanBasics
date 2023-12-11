#include "App01.h"

// std
#include <stdexcept>

TVE::App01::App01()
{
	CreatePipelineLayout();
	CreatePipeline();
	CreateCommandBuffers();
}

TVE::App01::~App01()
{
	vkDestroyPipelineLayout(engineDevice.Device(), pipelineLayout, nullptr);
}

void TVE::App01::Run()
{
	while (!window.ShouldClose())
	{
		glfwPollEvents();
		//
	}
}

void TVE::App01::CreatePipelineLayout()
{
	VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
	pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
	pipelineLayoutInfo.setLayoutCount = 0;
	pipelineLayoutInfo.pSetLayouts = nullptr;
	pipelineLayoutInfo.pushConstantRangeCount = 0;
	pipelineLayoutInfo.pPushConstantRanges = nullptr;

	if (vkCreatePipelineLayout(engineDevice.Device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) 
		!= VK_SUCCESS)
	{
		throw std::runtime_error("failed to create pipeline layout!");
	}
}

void TVE::App01::CreatePipeline()
{
	auto pipelineConfig = Pipeline::DefaultPipelineConfigInfo(swapChain.Width(), swapChain.Height());
	pipelineConfig.renderPass = swapChain.GetRenderPass();
	pipelineConfig.pipelineLayout = pipelineLayout;
	pipeline = std::make_unique<Pipeline>
		(
			engineDevice,
			"shaders/SimpleShader.vert.spv",
			"shaders/SimpleShader.frag.spv",
			pipelineConfig
		);
}

void TVE::App01::CreateCommandBuffers()
{

}

void TVE::App01::DrawFrame()
{

}
