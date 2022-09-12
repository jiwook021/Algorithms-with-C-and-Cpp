#include <iostream>
#include <queue>
#include <list>
#include <functional>
#include <iomanip>

using namespace std;

void print_queue(std::queue<int> q)
{
   while (!q.empty())
  {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;
}

void print_queue(std::queue<int,list<int>> q)
{
   while (!q.empty())
  {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;
}


void print_priority_queue(std::priority_queue<int> q)
{
   while (!q.empty())
  {
    std::cout << q.top() << " ";
    q.pop();
  }
  std::cout << std::endl;
}

void print_priority_queue(std::priority_queue<int,vector<int>,greater<int>> q)
{
   while (!q.empty())
  {
    std::cout << q.top() << " ";
    q.pop();
  }
  std::cout << std::endl;
}



int main() {

    const uint8_t size= 10;
    time_t t;
    srand((unsigned) time(&t));


    queue<int> q1;
    queue<int,list<int> > q2; //leave space between angle brackets > >
    for(int i = 0; i<size; i++)
    {
        q1.push(rand() % 80+11);
    }
    for(int i = 0; i<size; i++)
    {
        q2.push(rand() % 80+11);
    }
    
    for(int i = 0; i<size; i++)
    {
        q1.push(q2.back());
    }
    std::cout << "Queue 1: "; 
    print_queue(q1); 
    std::cout << "Queue 2: "; 
    print_queue(q2); 
    std::cout<<std::endl; 
    
    priority_queue<int> pq1; // plus vector<int> and less<int>
    priority_queue<int,vector<int>,greater<int> > pq2;
    for(int i = 0; i<size; i++)
    {
        pq1.push(rand() % 80+11);
    }
    for(int i = 0; i<size; i++)
    {
        pq2.push(rand() % 80+11);
    }
   
    int a[size]; 
    for(int i = 0; i<size; i++)
    {
        a[i] = (rand() % 80+11);
    }
    
    priority_queue<int> pq3(a,a+size);

    std::cout<<std::endl; 


    std::cout << "priority queue 1: "; 
    print_priority_queue(pq1);
    
    std::cout << "priority queue 2: "; 
    while (!pq2.empty()) {
    cout << pq2.top() << ' '; // 1 2 3
    pq2.pop();
    }
    std::cout<<std::endl; 
    
    std::cout << "priority queue 3: ";    
    print_priority_queue(pq3);
    
    std::cout<<std::endl; 
    
    std::priority_queue<int> foo,bar;
    foo.push (15); foo.push(30); foo.push(10);
    bar.push (101); bar.push(202);

    foo.swap(bar);

    std::cout << "size of foo: " << foo.size() << '\n';
    std::cout << "size of bar: " << bar.size() << '\n';

    std::priority_queue<std::string> mypq;

    mypq.emplace("orange");
    mypq.emplace("strawberry");
    mypq.emplace("apple");
    mypq.emplace("pear");

    std::cout << "mypq contains:";
    while (!mypq.empty())
    {
      std::cout << ' ' << mypq.top();
      mypq.pop();
    }
    std::cout << '\n';
return 0;
}