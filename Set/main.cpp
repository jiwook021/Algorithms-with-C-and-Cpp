#include <iostream>
#include <set>
#include <iterator>

using namespace std;

template<class T>
void Union(const set<T>& st1, const set<T>& st2, set<T>& st3) 
{
  set<T> tmp(st2);
	if (&st1 != &st2)
  {
      for (typename std::set<T>::iterator i = st1.begin(); i != st1.end(); i++)
        {
          tmp.insert(*i);
        }
  }
	 tmp.swap(st3);
}

int main() {
  
  ostream_iterator<int> out(cout," ");
  int a[] = {1,2,3,4,5};
  set<int> st1;
  set<int,greater<int> > st2;
  
  st1.insert(6); st1.insert(7); st1.insert(8); // st1 = (6 7 8)
  st2.insert(6); st2.insert(7); st2.insert(8); // st2 = (8 7 6)
  set<int> st3(a,a+5); // st3 = (1 2 3 4 5)
  set<int> st4(st3); // st4 = (1 2 3 4 5)
  
  pair<set<int>::iterator,bool> pr;
  pr = st1.insert(7); // st1 = (6 7 8), pr = (7 false)
  pr = st1.insert(9); // st1 = (6 7 8 9), pr = (9 true)
  
  set<int>::iterator i1 = st1.begin(), i2 = st1.begin();
  bool b1 = st1.key_comp()(*i1,*i1); // b1 = false
  bool b2 = st1.key_comp()(*i1,*++i2); // b2 = true
  bool b3 = st2.key_comp()(*i1,*i1); // b3 = false
  bool b4 = st2.key_comp()(*i1,*i2); // b4 = false
  
  st1.insert(2); st1.insert(4);	
  Union(st1,st3,st4); // st1 = (2 4 6 7 8 9) and st3 = (1 2 3 4 5) =>
  // st4 = (1 2 3 4 5 6 7 8 9)
  
  multiset<int> mst1;
  multiset<int,greater<int> > mst2;
  mst1.insert(6); mst1.insert(7); mst1.insert(8); // mst1 = (6 7 8)
  mst2.insert(6); mst2.insert(7); mst2.insert(8); // mst2 = (8 7 6)
  
  multiset<int> mst3(a,a+5); // mst3 = (1 2 3 4 5)
  multiset<int> mst4(mst3); // mst4 = (1 2 3 4 5)
  
  multiset<int>::iterator mpr = mst1.insert(7); // mst1 = (6 7 7 8)
  cout << *mpr << ' '; // 7
  mpr = mst1.insert(9); // mst1 = (6 7 7 8 9)
  cout << *mpr << ' '; // 9
  multiset<int>::iterator i5 = mst1.begin(), i6 = mst1.begin();
  i5++; i6++; i6++; // *i5 = 7, *i6 = 7
  b1 = mst1.key_comp()(*i5,*i6); // b1 = false
  std::cout<< std::endl;
 
  return 0;
}