#include <stdio.h>
#include <stdlib.h>

int segtree [100000];

void update(int index, int value,int sz)
{
    int diff = value - segtree[index+sz-1]; 
    for(int i = index+sz-1; i!=0; i/=2)
    {
        segtree[i] += diff;
    }
}

int range(int index, int start, int end, int Rangeleft, int RangeRight)
{
    if(start >RangeRight || end<Rangeleft)
        return 0;
    if(Rangeleft <= start && RangeRight>=end)
        return segtree[index];

    int mid = (start + end)/2;
    return range(index*2, start, mid, Rangeleft,RangeRight) + range(index*2+1, mid+1,end, Rangeleft,RangeRight);
}

void printtree(int sz)
{
    printf("\n");
    for(int i = sz*2-1; i>=1;i--)
    {
        printf("%d\n",segtree[i]);    
    }
}
int main()
{
    int n;
    int sz =1; 
    scanf("%d",&n);
    while(n>sz)
    {
        sz *= 2; 
    }
    for (int i =0;i<n;i++)
    {
        scanf("%d", &segtree[sz+i]);
    }
    //initseg
    for(int i = sz-1; i>=1;i--)
    {
        segtree[i] = segtree[i*2] + segtree[i*2+1];   
    }
    printtree(sz);
    update(4,3,sz);   
    printtree(sz);
    printf("%d",range(1,1,sz,2,3)); 
}
// //https://www.acmicpc.net/problem/2042
// #include <iostream>
// using namespace std;

// using ll = long long;

// ll seg_tree[2100005];

// ll get_interval_sum(int now, int now_left, int now_right, int find_left, int find_right){
//   if(find_right < now_left || now_right < find_left){
//     return ll(0);
//   }
//   if(find_left <= now_left && now_right <= find_right){
//     return seg_tree[now];
//   }
//   int middle = (now_left + now_right) / 2;
//   return get_interval_sum(now * 2, now_left, middle, find_left, find_right) + get_interval_sum(now * 2 + 1, middle + 1, now_right, find_left, find_right);
// }

// void up(ll idx, ll val){
//     ll diff = val - seg_tree[idx];
//     while(idx != 0){
//         seg_tree[idx] += diff;
//         idx = idx >> 1;
//     }
// }

// int main(){
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   int N, M, K, sz = 1;
//   cin >> N >> M >> K;
//   while(sz < N){
//     sz = sz << 1;
//   }
//   for(int i = 0; i < N; i++){
//     cin >> seg_tree[i + sz];
//   }
//   for(int i = sz - 1; i >= 1; i--){
//     seg_tree[i] = seg_tree[i * 2] + seg_tree[i * 2 + 1];
//   }
//   for(int i = 1; i <= M + K; i++){
//     ll cs, a, b;
//     cin >> cs >> a >> b;
//     if(cs == 1){
//       up(sz + a - 1, b);
//     } else{
//       cout << get_interval_sum(1, 1, sz, a, b) << "\n";
//     }
//   }
//   return 0;
// }


