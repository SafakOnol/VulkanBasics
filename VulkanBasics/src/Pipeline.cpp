#include "Pipeline.h"

// std
#include <fstream>
#include <stdexcept>
#include <iostream>


TVE::Pipeline::Pipeline(const std::string& vertFilepath, const std::string& fragFilepath)
{
	// constructor
	CreateGraphicsPipeline(vertFilepath, fragFilepath);
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

void TVE::Pipeline::CreateGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath)
{
	// read shaders
	auto vertCode = ReadFile(vertFilepath);
	auto fragCode = ReadFile(fragFilepath);

	std::cout << "Vertex Shader Code Size: "	<< vertCode.size() << " bytes." << std::endl;
	std::cout << "Fragment Shader Code Size: "	<< fragCode.size() << " bytes." << std::endl;
}
