#include <algorithm>
#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <list>
#include <iterator>

#include "VectorList.h"

//extern void RunAllTests();

int main()
{
	VectorList<int> v;

	std::vector<int> vec = { 1,3,5 };
	v.append(vec.begin(), vec.end());
	vec = { 2,4,6 };
	v.append(vec.begin(), vec.end());
	vec = { 5,7,9,0,2,3,4,5,6,7 };
	v.append(vec.begin(), vec.end());
	vec = { 6,8,101,202 };
	v.append(vec.begin(), vec.end());

	for(auto it = v.begin(); it != v.end(); it++)
	{
		std::cout<<*it<<" ";
	}
	printf("\n");



	auto eIt = v.end();
	eIt--;
	for( ; eIt != v.begin(); eIt--)
	{
		std::cout<<*eIt<<" ";
	}
	std::cout<<*eIt;
	printf("\n");

	auto rIt = v.rbegin();

	printf("End \n------------------------ \n");
}