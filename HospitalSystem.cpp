#include <iostream>
#include<vector>
#include<queue>
using namespace std;
string name;
bool hard;
int n;
class Node  
{
public:
	bool h;
	string name;
};
void add(vector<queue<string>> &v)
{
	cout << "please enter name of patiant :";
	cin >> name;
	cout << "please enter 1 if dengourse injery else 0  :";
	cin >> hard;
	cout << "please enter namber of class :";
	cin >> n;
	if (v[n].size() < 5)
	{
		if (!hard)
			v[n].push(name);
		else
		{
			int count = v[n].size();
			queue<string> temp;
			temp.push(name);
			for (size_t i = 0; i < count; i++)
			{
				temp.push(v[n].front());
				v[n].pop();
			}
			count = temp.size();
			for (size_t i = 0; i < count; i++)
			{
				v[n].push(temp.front());
				temp.pop();
			}
		}
	}
}
void getNextPatiant(vector<queue<string>> &v)
{
	cout << "please enter namber of class : ";
	cin >> n;
	if (v[n].empty())
		cout << "empty class have a rest dr\n";
	else
	{
		cout << "class  " + v[n].front();
		v[n].pop();
	}
}
void print(vector<queue<string>> v)
{
	int count;
	for (size_t i = 0; i < 20; i++)
	{
		count = v[i].size();
		if (v[i].empty())
			continue;
		for (size_t j = 0; j < count; j++)
		{
			cout << "class   " + i + v[i].front();
			v[i].pop();
		}
	}
}
int main()
{
 int n;
 
 vector<queue<string>> v;
 for (size_t i = 0; i < 20; i++)
 {
	 v.push_back(queue<string>());
 }
 while (true)
 {
	 cout << "enter 1 to add a patiant\n";
	 cout << "enter 2 to get a patiant patiant\n";
	 cout << "enter 3 to print all patiant\n";
	 cout << "enter 0 to exit\n";
	 cin >> n;
	 switch (n)
	 {
	 case 1:
		 add(v);
		 break;
	 case 2:
		 getNextPatiant(v);
		 break;
	 case 3:
		 print(v);
		 break;
	 case 0:
		 return 0;
		 break;
	 default:
		 cout << "invalid number";
		 break;
	 }
 }
}