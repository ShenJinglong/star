#include <thread>
#include "vision_mul.hpp"

int main()
{
	std::thread task0(&vision_mul);

	task0.join();
	return 0;
}


