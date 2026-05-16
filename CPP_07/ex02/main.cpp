#include "Array.hpp"

int main() {
	//test empty:
	Array<int> m;
	std::cout << m.size() << "\n";

	//test copy constructor:
    Array<int> arr(5);
    std::cout << "size of original: " << arr.size() << "\n";
    for (size_t i = 0; i < arr.size(); i++)
    {
        arr[i] = i;
    }
	Array<int> c_arr(arr);
	std::cout << "size of copy: " << c_arr.size() << "\n";
	c_arr[0] = 9;
	std::cout << "array of original:\n";
	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << "\n";
	}
	std::cout << "array of copy:\n";
	for (size_t i = 0; i < c_arr.size(); i++)
	{
		std::cout << c_arr[i] << "\n";
	}

	//test copy assignement operator:
    Array<int> f(5);
    std::cout << "size of original: " << f.size() << "\n";
    for (size_t i = 0; i < f.size(); i++)
    {
        f[i] = i;
    }
	Array<int> n;
	n = f;
	std::cout << "size of copy: " << n.size() << "\n";
	n[0] = 9;
	std::cout << "array of original:\n";
	for (size_t i = 0; i < f.size(); i++)
	{
		std::cout << f[i] << "\n";
	}
	std::cout << "array of copy:\n";
	for (size_t i = 0; i < n.size(); i++)
	{
		std::cout << n[i] << "\n";
	}

	//test out of bands:
    Array<int> out_arr(5);
    std::cout << "size of array: " << out_arr.size() << "\n";
    for (size_t i = 0; i < out_arr.size(); i++)
    {
        out_arr[i] = i;
    }
	try
	{
		out_arr[100];
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
	}
}
