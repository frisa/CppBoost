// CTobby.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <vector>

// The 3rdParty header files
#include "boost/smart_ptr/scoped_ptr.hpp"
#include "boost/smart_ptr/shared_ptr.hpp"
#include "boost/smart_ptr/weak_ptr.hpp"

// Windows functions
#include <windows.h>

using namespace boost;

class A
{
private:
    int _a;
public:
    ~A()
    {
        std::cout << _a << ": " << __FUNCTION__ << std::endl;
    }
public:
    A() : _a(0)
    {
        std::cout << _a << ": " << __FUNCTION__ << std::endl;
    }
    A(int a)
    {
        _a=a;
        std::cout << _a << ": " << __FUNCTION__ << std::endl;
    }
    void inc()
    {
        std::cout << _a << ": " << __FUNCTION__ << std::endl;
        _a++;
    }
};

class U
{
    scoped_ptr<A> pa;
    
public:
    U(): pa(new A())
    {
        std::cout << __FUNCTION__ << std::endl;
    }
    ~U()
    {
        std::cout << __FUNCTION__ << std::endl;
    }
};

int main()
{
    /* setup the possion of the console window */
    HWND consoleWindow = GetConsoleWindow();
    SetWindowPos(consoleWindow, 0, 1920/2, 0, 0, 0,SWP_NOSIZE | SWP_NOZORDER);

    U* uu = new U();
    delete uu;
    {
        boost::shared_ptr<A> x22;
        boost::weak_ptr<A> w22(x22);
        boost::scoped_ptr<A> x11;
        /* Business Logic */
        {
            boost::scoped_ptr<A> x1(new A(1));
            x11.swap(x1);
            boost::shared_ptr<A> x2(new A(2));
            x22 = x2;
        }
    }
}