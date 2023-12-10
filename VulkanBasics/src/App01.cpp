#include "App01.h"

void TVE::App01::Run()
{
	while (!window.ShouldClose())
	{
		glfwPollEvents();
	}
}
