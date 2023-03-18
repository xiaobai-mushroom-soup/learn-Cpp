#include <iostream>

int main()
{
	std::cout << "请输入两个数字:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "数字" << v1 << "+" << v2 << "=" << v1 + v2 << std::endl;

	return 0;
}