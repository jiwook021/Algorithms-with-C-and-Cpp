#include <iostream>
using namespace std;


// string solution(vector<int> numbers) {
//     string answer = "";
//     return answer;
// }

// int main() {
 
// }



// #include <string>
// #include <vector>

// using namespace std;

// vector<int> solution(vector<int> progresses, vector<int> speeds) {
//     vector<int> answer;
//     int totaldays[progresses.size()];
//     for(int i = 0; i < progresses.size(); i++)
//     {
//         totaldays[i]= (100 - progresses[i])/speed[i]; 
//         if((progresses[i] + d*speeds[i])!=100) 
//             d++;
//     }
//     std::queue<int> myqueue; 
//     myqueue.push = day[0];
//     for(int i = 1; i<progresses.size(); i++)
//     {
//         if (temp>=day[i])
//         {
//             myqueue.push = day[i];
//         }
//         else
//         {
//             int counter = 0;
//             while(!myqueue.empty())
//             {
//                 counter++;
//                 myqueue.pop();   
//             }
//             answer.push_back(counter);
//         }
//     }   
//     if(!myqueue.empty())
//         answer.push_back(myqueue.size());
//     // while (progress.front() >= 100)
//     // { 
//     //     while(progress >=100)
//     //         answer.push_back(progresses.front());
//     //         Progresses.pop()
//     // }
//     // progesses = progresses + speed; 
//     return answer;
// }