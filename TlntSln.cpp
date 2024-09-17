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


int main()
{
	VectorList<int> v;

	std::vector<int> vec = { 1,3,5 };
	v.append(vec.begin(), vec.end());
	vec = { 2,4,6 };
	v.append(vec.begin(), vec.end());
	vec = { 5,7,9,0,2,3,4,5,6,7 };
	v.append(vec.begin(), vec.end());
	vec = { 6,8,0 };
	v.append(vec.begin(), vec.end());

	//std::list<std::vector<int>> l;
	//auto it = l.begin();

	auto it = v.begin();

	printf("------------------------");
}