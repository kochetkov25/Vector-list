// #include "VectorList.h"
// #include <type_traits>
// #include <cassert>

// void RunAllTests()
// {
// #if 1
//     const VectorList<int> check_const_compile;
//     auto check_const_equals_compile = check_const_compile.begin();
//     check_const_equals_compile == check_const_equals_compile;
//     assert(check_const_compile.begin() == check_const_compile.end());
// #endif

// #if 1
//     VectorList<std::vector<int>> check_arrow_vl;
//     std::vector<int> vint1 = {1, 2, 3};
//     std::vector<int> vint2 = {4, 5, 6};
//     std::vector<std::vector<int>> vecs;
//     vecs.push_back(vint1);
//     vecs.push_back(vint2);
//     check_arrow_vl.append(vecs.begin(), vecs.end());
//     auto it_f = check_arrow_vl.begin();
//     assert(it_f->size() == 3);
// #endif

// #if 1
//     VectorList<char> vec_list;

//     std::vector<char> v1;
//     v1.push_back('A');
//     v1.push_back('B');
//     v1.push_back('C');
//     vec_list.append(v1.begin(), v1.end());

//     std::vector<char> v2;
//     v2.push_back('D');
//     v2.push_back('E');
//     v2.push_back('F');
//     v2.push_back('G');
//     vec_list.append(v2.begin(), v2.end());

//     assert(vec_list.size() == 7);
//     assert(std::distance(vec_list.begin(), vec_list.end()) == 7);

//     auto ra = vec_list.rbegin();
//     ++ra;
//     ++ra;
//     auto a = ra.base();
// #endif

// #if 1
//     auto it = vec_list.begin();
//     assert(*it == 'A'); ++it;
//     assert(*it == 'B'); ++it;
//     assert(*it == 'C'); ++it;
//     assert(*it == 'D'); ++it;
//     assert(*it == 'E'); ++it;
//     assert(*it == 'F'); ++it;
//     assert(*it == 'G'); ++it;
//     assert(it == vec_list.end());
// #endif

// #if 1
//     it = vec_list.begin();
//     assert(*it == 'A'); it++;
//     assert(*it == 'B'); it++;
//     assert(*it == 'C'); it++;
//     assert(*it == 'D'); it++;
//     assert(*it == 'E'); it++;
//     assert(*it == 'F'); it++;
//     assert(*it == 'G'); it++;
//     assert(it == vec_list.end());
// #endif

// #if 1
//     it = vec_list.end(); --it;
//     assert(*it == 'G'); --it;
//     assert(*it == 'F'); --it;
//     assert(*it == 'E'); --it;
//     assert(*it == 'D'); --it;
//     assert(*it == 'C'); --it;
//     assert(*it == 'B'); --it;
//     assert(*it == 'A');
//     assert(it == vec_list.begin());
// #endif
    
// #if 1
//     it = vec_list.end(); it--;
//     assert(*it == 'G'); it--;
//     assert(*it == 'F'); it--;
//     assert(*it == 'E'); it--;
//     assert(*it == 'D'); it--;
//     assert(*it == 'C'); it--;
//     assert(*it == 'B'); it--;
//     assert(*it == 'A');
// #endif

// #if 1
//     auto r_it = vec_list.rbegin();
//     assert(*r_it == 'G'); ++r_it;
//     assert(*r_it == 'F'); ++r_it;
//     assert(*r_it == 'E'); ++r_it;
//     assert(*r_it == 'D'); ++r_it;
//     assert(*r_it == 'C'); ++r_it;
//     assert(*r_it == 'B'); ++r_it;
//     assert(*r_it == 'A'); ++r_it;
//     assert(r_it == vec_list.rend());
// #endif

// #if 1
//     r_it = vec_list.rbegin();
//     assert(*r_it == 'G'); r_it++;
//     assert(*r_it == 'F'); r_it++;
//     assert(*r_it == 'E'); r_it++;
//     assert(*r_it == 'D'); r_it++;
//     assert(*r_it == 'C'); r_it++;
//     assert(*r_it == 'B'); r_it++;
//     assert(*r_it == 'A'); r_it++;
//     assert(r_it == vec_list.rend());
// #endif


// #if 1
//     r_it = vec_list.rend(); --r_it;
//     assert(*r_it == 'A'); --r_it;
//     assert(*r_it == 'B'); --r_it;
//     assert(*r_it == 'C'); --r_it;
//     assert(*r_it == 'D'); --r_it;
//     assert(*r_it == 'E'); --r_it;
//     assert(*r_it == 'F'); --r_it;
//     assert(*r_it == 'G');
// #endif

// #if 1
//     r_it = vec_list.rend(); r_it--;
//     assert(*r_it == 'A'); r_it--;
//     assert(*r_it == 'B'); r_it--;
//     assert(*r_it == 'C'); r_it--;
//     assert(*r_it == 'D'); r_it--;
//     assert(*r_it == 'E'); r_it--;
//     assert(*r_it == 'F'); r_it--;
//     assert(*r_it == 'G');
// #endif

// #if 1 //test convertations
//     it = vec_list.begin();
//     ++it;
//     ++it;
//     assert(*it == 'C');
//     r_it = it;
//     assert(*r_it == 'B');
//     auto new_it = r_it.base();
//     assert(*new_it == 'C');
// #endif

// #if 1
//     VectorList<char>::const_iterator def;
//     auto dit = vec_list.end(); --dit;
//     def = dit;

//     VectorList<char>::const_reverse_iterator rdef;
//     auto rdit = vec_list.rend(); --dit;
//     rdef = rdit;
// #endif

// #if 1
//     VectorList<int> check_empty;
//     assert(check_empty.size() == 0);
//     assert(check_empty.begin() == check_empty.end());
//     assert(check_empty.rbegin() == check_empty.rend());
// #endif

// #if 1
//     typedef VectorList<std::string> VL;
    
//     static_assert(std::is_same<std::iterator_traits<VL::const_iterator>::reference, std::string const&>::value, "Incorrect iterator value_type");
//     static_assert(std::is_same<std::iterator_traits<VL::const_iterator>::iterator_category, std::bidirectional_iterator_tag>::value, "FFF");
// #endif
// }