// star.cpp: 定义控制台应用程序的入口点。
//

#include <thread>
#include "vision_mul.hpp"

int main()
{
	std::thread task0(&vision_mul);

	task0.join();
    return 0;
}

