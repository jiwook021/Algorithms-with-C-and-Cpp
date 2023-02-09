#include <iostream>
#include <thread>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



// void hello1()
// {
//   for (int i=0;i<10;i++)
//   {
//     std::cout<<"Hello 1 "<<i<<std::endl;
//     sleep(1);
//   }
// }
// void hello2()
// {
//   for (int i=0;i<10;i++)
//   {
//     std::cout<<"Hello 2 "<<i<<std::endl;
//     sleep(1);
//   }
// }
// void hello3()
// {
//   for (int i=0;i<10;i++)
//   {
//     std::cout<<"Hello 3 " <<i<<std::endl;
//     sleep(1);
//   }
// }
// void hello4()
// {
//   for (int i=0;i<10;i++)
//   {
//     std::cout<<"Hello 4 " <<i<<std::endl;
//     sleep(1);
//   }
// }

// void hello5()
// {
  
// 	for (int i=0;i<10;i++)
//   {
//     std::cout<<"Hello 5 "<<i<<std::endl;
//     sleep(1);
//   }
// }


// void test()
// {
//     std::thread t1(hello1);
//     std::thread t2(hello2);
//     std::thread t3(hello3);
//     std::thread t4(hello4);
//     std::thread t5(hello5);
    

//     t1.join();
//     t2.join();
//     t3.join();
//     t4.join();
//     t5.join();
    
// }

// struct func
// {
//  int& i;
//  func(int& i_):i(i_){}
//  void operator()()
//  {
//  for(unsigned j=0;j<1000000;++j)
//     {
//     std::cout<<j<<" ";
//     }
//  }
// };




// int main()
// {
//    test();
// 	return 0;
// }

  
// pthread_t tid[2];
// int counter = 0;
  
// void* trythis(void* arg)
// {
//     unsigned long i = 0;
//     counter += 1;
//     printf("\n Job %d has started\n", counter);
  
//     for (i = 0; i < (0xFFFFFFFF); i++)
//         ;
//     printf("\n Job %d has finished\n", counter);
  
//     return NULL;
// }
  
// int main(void)
// {
//     int i = 0;
//     int error;
  
//     while (i < 2) {
//         error = pthread_create(&(tid[i]), NULL, &trythis, NULL);
//         if (error != 0)
//             printf("\nThread can't be created : [%s]", strerror(error));
//         i++;
        
//     }
  
//     pthread_join(tid[0], NULL);
//     pthread_join(tid[1], NULL);
  
//     return 0;
// }

pthread_t tid[2];
int counter = 0 ;
pthread_mutex_t lock;
  

  bool spinlock = false; 
void* trythis(void* arg)
{

  while(spinlock)
  {


  }
  spinlock = true; 
    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d has started\n", counter);
  
    for (i = 0; i < (0xFFFFFFFF); i++)
        ;
  
    printf("\n Job %d has finished\n", counter);
  
    
    spinlock =false; 

    return NULL;
}
  
int main(void)
{
    int i = 0;
    int error;
  
    // if (pthread_mutex_init(&lock, NULL) != 0) {
    //     printf("\n mutex init has failed\n");
    //     return 1;
    // }
  
    while (i < 2) {
        error = pthread_create(&(tid[i]),
                               NULL,
                               &trythis, NULL);
        if (error != 0)
            printf("\nThread can't be created :[%s]",
                   strerror(error));
        i++;
    }
  
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);
  
    return 0;
}

// #include <iostream>       // std::cout
// #include <atomic>         // std::atomic, std::atomic_flag, ATOMIC_FLAG_INIT
// #include <thread>         // std::thread, std::this_thread::yield
// #include <vector>         // std::vector

// std::atomic<bool> ready (false);
// std::atomic_flag winner = ATOMIC_FLAG_INIT;

// void count1m (int id) {
//   // while (!ready) 
//   // { 
//   //   std::this_thread::yield(); 
//   // }      // wait for the ready signal
//   for (volatile int i=0; i<1000000; ++i) {}          // go!, count to 1 million
//   //if (!winner.test_and_set()) 
//   { std::cout << "thread #" << id << " won!\n"; }
// };

// int main ()
// {
//   std::vector<std::thread> threads;
//   std::cout << "spawning 10 threads that count to 1 million...\n";
//   for (int i=1; i<=10; ++i) 
//     threads.push_back(std::thread(count1m,i));
//   //ready = true;
//   sleep(1);
//   for (auto& th : threads) th.join();

//   return 0;
// }