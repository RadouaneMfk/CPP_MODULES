#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
    int arr[] = {1, 2, 3, 4 , 5, 6};
    std::vector<int> myArr(arr, arr + 6);
    try
    {
        std::vector<int>::iterator it = easyfind(myArr, 4);
        std::cout << *it << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::list<int> mylist;
    mylist.push_back(3);
    mylist.push_back(5);
    try
    {
        std::list<int>::iterator ite = easyfind(mylist, 7);
        std::cout << *ite << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
