#pragma once

#include <string>
#include <vector>

namespace TVE
{

class Pipeline
{
public:
	Pipeline(const std::string& vertFilepath, const std::string& fragFilepath);

private:
	static std::vector<char> ReadFile(const std::string& filepath);

	void CreateGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath);

};

} // namespace TVE


