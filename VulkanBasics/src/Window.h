#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace TVE // Tiny Vulkan Engine
{

class VulkanWindow
{
public:
	VulkanWindow(int w, int h, std::string name);
	~VulkanWindow();

	// remove copy constructors
	VulkanWindow(const VulkanWindow&) = delete;
	VulkanWindow& operator=(const VulkanWindow&) = delete;


	bool ShouldClose() { return glfwWindowShouldClose(window); }
	VkExtent2D GetExtent() { return { static_cast<uint32_t>(WINDOW_WITDH), static_cast<uint32_t>(WINDOW_HEIGHT) }; }

	void CreateWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

private:
	void InitWindow();

	const int WINDOW_WITDH;
	const int WINDOW_HEIGHT;

	std::string WindowName;
	GLFWwindow* window;
};

} // namespace TVE
