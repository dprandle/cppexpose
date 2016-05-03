
#include "HelloWorld.h"

#include <cppexpose/cppexpose-version.h>

#include <iostream>


HelloWorld::HelloWorld(const cpplocate::ModuleInfo &)
{
}

HelloWorld::~HelloWorld()
{
}

void HelloWorld::run()
{
    std::cout << "Hello World!" << std::endl;
}


CPPEXPOSE_COMPONENT(
    HelloWorld, cppexpose::Example,
    "", // Subtype
    "", // Icon
    "", // Annotations
    "Prints 'Hello World' to the console",
    CPPEXPOSE_AUTHOR_ORGANIZATION,
    "v1.0.0"
)
