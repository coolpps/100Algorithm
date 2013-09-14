//这个可以用迭代器实现

#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;

int main()
{
	string line,word;
	vector<string> vec;

	getline(cin,line);
	cout<<line<<endl;

	istringstream str(line);
	while(str>>word)
		vec.push_back(word);

	cout<<vec.size()<<endl;
	copy(vec.rbegin(),vec.rend(),ostream_iterator<string>(cout," "));
	system("pause");
}