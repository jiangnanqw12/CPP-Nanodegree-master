#include <assert.h>
#include <string>
#include <iostream>
// TODO: Define class Person
class Person
{

public:
  // TODO: Define a public constructor with an initialization list
  Person (std::string s) : name(s){}
  // TODO: Define a public member variable: name
  std::string name;
};

// Test
int main()
{
  Person alice("alice");
  Person bob("bob");
  assert(alice.name != bob.name);
  std::cout<<alice.name;
  return 0;
}
