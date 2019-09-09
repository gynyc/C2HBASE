//============================================================================
// Name        : testSecond.cpp
// Author      : stephen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//#include "Poco/Poco.h"

//#include "Poco/BasicEvent.h"
//#include "Poco/Delegate.h"
#include "HTable.h"
#include <iostream>

using namespace std;
using namespace Poco;

/*
using Poco::BasicEvent;
using Poco::Delegate;


class Source
{
public:
    BasicEvent<int> theEvent;

    void fireEvent(int n)
    {
        theEvent(this, n);
    }
};

class Target
{
public:
    void onEvent(const void* pSender, int& arg)
    {
        std::cout << "onEvent: " << arg << std::endl;
    }
};
*/

int main(int argc, char** argv)
{
	HTable ht;
	/*
    Source source;
    Target target;


    source.theEvent += Delegate<Target, int>(
        &target, &Target::onEvent);

    source.fireEvent(42);

    source.theEvent -= Delegate<Target, int>(
        &target, &Target::onEvent);
*/
    std::list <Put *> puts;
    ht.put(puts);
    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
    return 0;
}



