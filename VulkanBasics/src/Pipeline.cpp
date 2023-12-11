#include "Pipeline.h"

// std
#include <fstream>
#include <stdexcept>
#include <iostream>


TVE::Pipeline::Pipeline(
	EngineDevice& device,
	const std::string& vertFilepath,
	const std::string& fragFilepath,
	const PipelineConfigInfo& configInfo)
	: engineDevice{device}
{
	// constructor
	CreateGraphicsPipeline(vertFilepath, fragFilepath, configInfo);
}

std::vector<char> TVE::Pipeline::ReadFile(const std::string& filepath)
{
	/* BIT FLAGS */
	// ate sets the initial position of the file pointer to the end of the file (opens "at end" mode)
	// binary disallows any special character processing, important for working with non-text files such as vertices and textures
	std::ifstream file{ filepath, std::ios::ate | std::ios::binary };

	if (!file.is_open())
	{
		throw std::runtime_error("failed to open file: " + filepath);
	}

	size_t fileSize = static_cast<size_t>(file.tellg());	// tellg because of the ate bit flag, we're at the end of the file,
															// in this case tellg give us the final position, which is the file size
	std::vector<char> buffer(fileSize); // initialize the buffer with filesize

	file.seekg(0); // seek the start of the file (since we now want to read it)
	file.read(buffer.data(), fileSize); // read it into buffer.data , read about fileSize
	file.close(); // close the file and return buffer

	return buffer;

}

void TVE::Pipeline::CreateGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo)
{
	// read shaders
	auto vertCode = ReadFile(vertFilepath);
	auto fragCode = ReadFile(fragFilepath);

	std::cout << "Vertex Shader Code Size: "	<< vertCode.size() << " bytes." << std::endl;
	std::cout << "Fragment Shader Code Size: "	<< fragCode.size() << " bytes." << std::endl;
}

void TVE::Pipeline::CreateShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule)
{
	VkShaderModuleCreateInfo createInfo{};
	createInfo.sType	= VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
	createInfo.codeSize = code.size();
	createInfo.pCode	= reinterpret_cast<const uint32_t*>(code.data());

	if (vkCreateShaderModule(engineDevice.Device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS)
	{
		throw std::runtime_error("failed to create Shader Module!");
	};
}

TVE::PipelineConfigInfo TVE::Pipeline::DefaultPipelineConfigInfo(uint32_t width, uint32_t height)
{
	PipelineConfigInfo configInfo{};

	return configInfo;
}
