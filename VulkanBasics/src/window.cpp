#include "window.h"

TVE::VulkanWindow::VulkanWindow(int w, int h, std::string name)
	: WINDOW_WITDH(w), WINDOW_HEIGHT(h), WindowName(name)
{
	InitWindow();
}

TVE::VulkanWindow::~VulkanWindow()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void TVE::VulkanWindow::InitWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);	// Disable openGL 
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);		// Disable native window resizing

	window = glfwCreateWindow(WINDOW_WITDH, WINDOW_HEIGHT, WindowName.c_str(), nullptr, nullptr); // 4th parameter is for full screen resizing, 5th parameter is openGL related therefore null initialized

}


