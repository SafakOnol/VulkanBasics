#pragma once

#include "EngineDevice.h"

#include <string>
#include <vector>

namespace TVE
{
// ############################ //




	struct PipelineConfigInfo
	{
		// set the pipeline class info as a separate class so our app can configure it and share the configuration
	};

	class Pipeline
	{
	public:
		Pipeline 
		(
			EngineDevice & device, 
			const std::string& vertFilepath, 
			const std::string& fragFilepath,
			const PipelineConfigInfo& configInfo
		);
		~Pipeline() {};
	
		// remove copy constructors
		Pipeline(const Pipeline&) = delete;
		void operator=(const Pipeline&) = delete;

		static PipelineConfigInfo DefaultPipelineConfigInfo(uint32_t width, uint32_t height);

	private:
		static std::vector<char> ReadFile(const std::string& filepath);

		void CreateGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo);

		void CreateShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

		EngineDevice& engineDevice; // careful with memory here!!! // aggregetion relationship (UML)
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;

	};
// ############################ //
} // namespace TVE



