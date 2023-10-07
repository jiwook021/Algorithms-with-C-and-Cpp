#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	stack<int> st;
	while (n--)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push")
		{
			int k;
			cin >> k;
			st.push(k);
		}
		else if (cmd == "pop")
		{
			if (st.empty())
				cout << "-1\n";
			else
			{
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (cmd == "size")
		{
			cout << st.size() << '\n';
		}
		else if (cmd == "empty")
		{
			if (st.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else
		{
			if (st.empty())
				cout << "-1\n";
			else
				cout << st.top() << '\n';
		}
	}
	return 0;
}