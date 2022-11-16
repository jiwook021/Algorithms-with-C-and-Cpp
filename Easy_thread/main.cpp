#include <iostream>
#include <thread>

void hello1()
{
  for (int i=0;i<10;i++)
  {
    std::cout<<"Hello 1 "<<i<<std::endl;
  }
}
void hello2()
{
  for (int i=0;i<10;i++)
  {
    std::cout<<"Hello 2 "<<i<<std::endl;
  }
}
void hello3()
{
  for (int i=0;i<10;i++)
  {
    std::cout<<"Hello 3 " <<i<<std::endl;
  }
}
void hello4()
{
  for (int i=0;i<10;i++)
  {
    std::cout<<"Hello 4 " <<i<<std::endl;
  }
}

void hello5()
{
  
	for (int i=0;i<10;i++)
  {
    std::cout<<"Hello 5 "<<i<<std::endl;
  }
}


void test()
{
    std::thread t1(hello1);
    std::thread t2(hello2);
    std::thread t3(hello3);
    std::thread t4(hello4);
    std::thread t5(hello5);
    std::thread t6 = std::move(t4);
    t3 = std::move(t2);
    

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    
}

struct func
{
 int& i;
 func(int& i_):i(i_){}
 void operator()()
 {
 for(unsigned j=0;j<1000000;++j)
    {
    std::cout<<j<<" ";
    }
 }
};
void oops()
{
    int some_local_state=0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    my_thread.detach();
} 


class thread_guard
{
 std::thread& t;
public:
 explicit thread_guard(std::thread& t_):
 t(t_)
 {}
 ~thread_guard()
 {
 if(t.joinable())
 {
 t.join();
 }
 }
 thread_guard(thread_guard const&)=delete;
 thread_guard& operator=(thread_guard const&)=delete;
};
struct func;
void f()
{
	int some_local_state=0;
	func my_func(some_local_state);
	std::thread t(my_func);
	thread_guard g(t);
	hello1();
}

int main()
{
  //oops();
  test();
	//f();
  return 0;
}