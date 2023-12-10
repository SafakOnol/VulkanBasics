#include "App01.h"

// std lib
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main()
{
	TVE::App01 App{};

	try
	{
		App.Run();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}