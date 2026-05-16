#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "-----MutantStack-----\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "-----list-----\n";
    std::list<int> mystack;
    mystack.push_back(5);
    mystack.push_back(17);
    std::cout << mystack.back() << std::endl;
    mystack.pop_back();
    std::cout << mystack.size() << std::endl;
    mystack.push_back(3);
    mystack.push_back(5);
    mystack.push_back(737);

    mystack.push_back(0);
    std::list<int>::iterator itee = mystack.begin();
    std::list<int>::iterator iteee = mystack.end();
    ++itee;
    --itee;
    while (itee != iteee)
    {
        std::cout << *itee << std::endl;
        ++itee;
    }
    return 0;
}
