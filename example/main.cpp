//#include <iostream>
//using namespace std;
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


// #include <stdio.h>



// int main()
// {
//     int i = 20; 
//      {
//         i=30;
//      }
//     printf("%d",i);

// }

// int main()
// {
// unsigned int length = 64;
// int input = 1; 
// int answer = 0; 
// for(int i =0;i<7;i++)
// {
// if(input/(length >> i)>=1)
// {
//     if(input<0)
//     {
//         break;
//     }   
// input = input - (length >> i); 
// answer++; 
// } 

// if(input <= 0)
//     break;
// } 
// printf("%d\n",answer);
// return 0;
// }

// #include <queue>
// using namespace std;
// int main()
// {
//     priority_queue <int, vector<int>, greater<int> > minheap;
//     priority_queue <int> maxheap;

//     int n;
//     cin >> n; 
//     int input;
//     for(int i =1;i<=n;i++)
//     {    
//         cin>>input;
//         if(maxheap.size() > minheap.size()) 
//             minheap.push(input);
//         else
//         {    
//             maxheap.push(input);
//         }

//         if(!maxheap.empty() | !minheap.empty()) 
//         {
//             int tempmintop;
//             int tempmaxtop;
//             if(maxheap.top() > minheap.top())
//             {
//                 tempmintop = minheap.top();
//                 tempmaxtop = maxheap.top();
//                 minheap.pop(); 
//                 maxheap.pop();
//                 minheap.push(tempmaxtop);
//                 maxheap.push(tempmintop);
//             }
//         }
//         cout << maxheap.top()<<endl; 
//     }
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <memory.h>

// typedef struct node
// {
//     char data;
//     struct node* next;
//     struct node* previous; 
// } NODE;

// NODE* Head = NULL;
// int Size = 0;

// NODE* initnode(char data)
// {
//     NODE* newNode = (NODE*)malloc(sizeof(NODE));
//     newNode->data = data; 
//     newNode->next = NULL; 
//     newNode->previous = NULL; 
//     return newNode;
// }

// void push(char data)
// {
//     if(Head==NULL)
//     {
//         Head = initnode(data);
//     }
//     NODE* temp = initnode(data);
//     temp->previous= Head; 
//     Head ->next = temp; 
//     Head = Head->next;
//     Size = Size +1;
// }
// char top()
// {
//     if(Head ==NULL)
//         return 0;
//     return Head->data;
// }

// void pop()
// {
//     if(Head ==NULL)
//         return;        
//     NODE* temp = Head;
//     Head = Head->previous;   
//     free(temp);
//     Size--;
// }

// int main()
// {
//     push('a');
//     push('b');
//     push('c');
//     push('d');
    
//     for(int i =0;i<4;i++)
//     {
//         cout<<top()<<endl;
//         pop();
//     }
// }

// #include <iostream>
// #include <regex>
// #include <string>
// #include <cmath>
// #include <vector>
// using namespace std;

// std::vector<std::string> split(const std::string& s){
//   std::vector<std::string> result;
//   size_t pos = 0, lastPos = 0;
//   while((pos = s.find_first_of("+-", pos)) != std::string::npos){
//     if(pos != lastPos){
//       result.push_back(s.substr(lastPos, pos - lastPos));
//     }
//     lastPos = pos++;
//   }
//   result.push_back(s.substr(lastPos));
//   return result;
// }

// std::regex r_coeff_x2("([-+]?\\d*\\.?\\d*)\\s*\\*?\\s*x\\^2");
// std::regex r_coeff_x("([-+]?\\d*\\.?\\d*)\\s*\\*?\\s*x");
// std::regex r_constant("([-+]?\\d+\\.?\\d*)");

// bool hasNumber(std::string& s){
//   return std::any_of(s.begin(), s.end(), ::isdigit);
// }
// bool containsAsterisk(const std::string& s) {
//     return s.find('*') != std::string::npos;
// }
// std::string removeSpaces(std::string s) {
//     std::string result = s;
//     result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
//     return result;
// }

// int main(){
//   double a,b,c = 0;
//   std::string x = "|-30|+log(10)*x+10*x^2  = -2 x ^ 2 + log(1 0) * x -x-10*x^2+1-2";
//   cout<<x<<endl;
//   std::string y = removeSpaces(x);





//   size_t pos = y.find('=');
//   int extracted = stoi(y.substr(0, pos));
//   string convertedExtra = extracted > 0 ? to_string(-extracted) : '+'+to_string(-extracted);
//   string s =y+convertedExtra;
//   s.erase(0,pos+1);
//   std::cout<<s<<endl;
//   std::vector<std::string> tokens = split(s);
//   for(auto& token : tokens){
//     std::cout << token << ": ";
//     if(std::regex_match(token, r_coeff_x2)){
//       std::cout << "2차항: ";
//       if(!hasNumber(token))
//       {
//         int val = token[0] == '-' ? -1 : 1;
//         b+=val;
//         std::cout << "\n";
//         continue;
//       }
//     int len = containsAsterisk(token) ? 4 : 3;
//       token.erase(token.end() - len, token.end());
//       std::cout << token << ", ";
//       std::cout << std::stoi(token);
//         a+=std::stoi(token);
//     } else if(std::regex_match(token, r_coeff_x)){
//       std::cout << "1차항: ";
//       if(!hasNumber(token))
//       {
//         int val = token[0] == '-' ? -1 : 1;
//         b+=val;
//         std::cout << "\n";
//         continue;
//         }
//         int len = containsAsterisk(token) ? 2 : 1;
//          token.erase(token.end() - len, token.end());
//         std::cout << token << ", ";
//         std::cout << std::stoi(token);
//         b+=std::stoi(token);
//     } else if(std::regex_match(token, r_constant)){
//       std::cout << "상수항: ";
//       std::cout << token << " ";
//       std::cout << std::stoi(token);
//         c+=std::stoi(token);
//     }
//     std::cout << "\n";
//   }
//   cout<< "a: "<< a<<std::endl;
//   cout<< "b: "<< b<<std::endl;
//   cout<< "c: "<< c<<std::endl;
// }

// #include <iostream>
// #include <vector>
// #include <iterator>
// template <typename T>
// typename std::vector<T>::iterator my_remove(std::vector<T>& vec, const T& value) {
//     auto it = vec.begin();
//     for (auto& elem : vec) {
//         if (elem != value) {
//             *it = std::move(elem);  // Use std::move to handle non-trivially copyable types.
//             ++it;
//         }
//     }
//     return it;
// }

// int main() {
//     std::vector<int> vec = {1, 2, 3, 4, 2, 5, 2};
//     auto new_end = my_remove(vec, 2);
//     vec.erase(new_end, vec.end());
    
//     for (int i : vec) {
//         std::cout << i << " ";
//     }
//     // Output: 1 3 4 5
// }


// #include <iostream>
// #include <regex>
// #include <string>
// #include <cmath>
// #include <vector>
// #include <sstream>
// #include <iomanip>

// using namespace std;

// struct Coefficient{
//   double a, b, c;
// };

// vector<string> splitPolynomial(string& poly){
//   vector<string> terms;
//   size_t start = 0;
//   int bracketCount = 0;
//   int absCount = 0;
//   for(size_t i = 0; i < poly.size(); ++i){
//     if(poly[i] == '('){
//       bracketCount++;
//     } else if(poly[i] == ')'){
//       bracketCount--;
//     } else if(poly[i] == '|'){
//       absCount = 1 - absCount;
//     } else if((poly[i] == '+' || poly[i] == '-') && bracketCount == 0 && absCount == 0){
//       terms.push_back(poly.substr(start, i - start));
//       start = i;
//     }
//   }
//   terms.push_back(poly.substr(start));
//   return terms;
// }

// bool hasNumber(string& s){
//   return any_of(s.begin(), s.end(), ::isdigit);
// }

// bool containsAsterisk(string& s){
//   return s.find('*') != string::npos;
// }

// string removeSpaces(string s){
//   string result = s;
//   result.erase(remove(result.begin(), result.end(), ' '), result.end());
//   return result;
// }

// string replaceLogWithValues(const string& s){
//   regex r("log\\(([^)]+)\\)");
//   smatch match;
//   string result = s;

//   while(regex_search(result, match, r)){
//     double value = stod(match[1]);
//     double logValue = log(value);
//     ostringstream os;
//     os << fixed << setprecision(3) << logValue;
//     result.replace(match.position(), match.length(), os.str());
//   }
//   return result;
// }


// Coefficient calc(string s){
//   Coefficient result;
//   result.a = result.b = result.c = 0.0;
//   regex r_coeff_x2("([-+]?\\d*\\.?\\d*)\\s*\\*?\\s*x\\^2");
//   regex r_coeff_x("([-+]?\\d*\\.?\\d*)\\s*\\*?\\s*x");
//   regex r_constant("([-+]?\\d+\\.?\\d*)");
//   vector<string> tokens = splitPolynomial(s);
//   for(auto& token : tokens){
//     if((token[0] == '|' || token[1] == '|') && token[token.size() - 1] == '|'){
//       double sign = token[0] == '-' ? -1.0 : 1.0;
//       size_t start = token[0] == '|' ? 0 : 1;
//       double val = sign * abs(stod(token.substr(start + 1, token.size() - start - 2)));
//       result.c += val;
//     } else if(regex_match(token, r_coeff_x2)){
//       if(!hasNumber(token)){
//         int val = token[0] == '-' ? -1 : 1;
//         result.b += double(val);
//         continue;
//       }
//       int len = containsAsterisk(token) ? 4 : 3;
//       token.erase(token.end() - len, token.end());
//       result.a += double(stod(token));
//     } else if(regex_match(token, r_coeff_x)){
//       if(!hasNumber(token)){
//         int val = token[0] == '-' ? -1 : 1;
//         result.b += double(val);
//         continue;
//       }
//       int len = containsAsterisk(token) ? 2 : 1;
//       token.erase(token.end() - len, token.end());
//       result.b += stod(token);
//     } else if(regex_match(token, r_constant)){
//       result.c += stod(token);
//     }
//   }
//   return result;
// }

// Coefficient getEquation(string s){
//   string trimedS = removeSpaces(s);
//   size_t pos = trimedS.find('=');
//   string leftEquation = trimedS.substr(0, pos);
//   string rightEquation = trimedS.substr(pos + 1);
//   Coefficient leftResult = calc(replaceLogWithValues(leftEquation));
//   Coefficient rightResult = calc(replaceLogWithValues(rightEquation));
//   Coefficient result;
//   cout << leftResult.a << " " << leftResult.b << " " << leftResult.c << endl;
//   cout << rightResult.a << " " << rightResult.b << " " << rightResult.c << endl;
//   result.a = rightResult.a - leftResult.a;
//   result.b = rightResult.b - leftResult.b;
//   result.c = rightResult.c - leftResult.c;
//   return result;
// }

// int main(){
//   string s = "|-30|+log(10)*x+10*x^2  = 2 x ^ 2 + log(1 0) * x -x-10*x^2+1-2-|-log(10)|";
//   Coefficient res = getEquation(s);
//   cout << res.a << " " << res.b << " " << res.c << endl;
//   return 0;
// }

// #include <queue>
// #include <iostream>

// using namespace std; 

// int n,m,v;
   
// bool visit[10005] = false; 
// vector<int> vec[10005];

 
// void dfs(int v)
// {
//     visit[v] = true;
//     for(int i = 0; i< vec[v].size();i++)   
//     {
//         if(!v[i])
//         {
//             dfs(i);
//         }
//     }
// }

// void bfs(int v)
// {
//     queue<int> q; 



// }

// int main()
// {
//     cin >> n >> m >> v; 
   
//     while(m--)
//     {
//         int a ,b; 
//         cin >> a >> b; 
//         vec[a].push_back(b);
//         vec[b].push_back(a); 
//     }
//     dfs(v);
//     bfs(v);
// }


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

int isEmpty(Deque* deque) {
    return (deque->front == NULL);
}

void insertFront(Deque* deque, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = deque->front;

    if (isEmpty(deque)) {
        deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
    }

    deque->front = newNode;
}

void insertRear(Deque* deque, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = deque->rear;

    if (isEmpty(deque)) {
        deque->front = newNode;
    } else {
        deque->rear->next = newNode;
    }

    deque->rear = newNode;
}

void deleteFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return;
    }

    Node* temp = deque->front;
    deque->front = deque->front->next;

    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }

    free(temp);
}

void deleteRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return;
    }
    Node* temp = deque->rear;
    deque->rear = deque->rear->prev;
    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    free(temp);
}

void printDeque(Deque* deque) {
    Node* temp = deque->front;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    
    Deque* deque = createDeque();
    insertRear(deque, 5);
    insertFront(deque, 3);
    insertFront(deque, 1);
    insertRear(deque, 7);
    printf("Deque after inserts: ");
    printDeque(deque);
    deleteFront(deque);
    deleteRear(deque);
    printf("Deque after deletes: ");
    printDeque(deque);
    return 0;
}











typedef struct Node
{


}NODE; 

typedef struct deque
{


}deque











