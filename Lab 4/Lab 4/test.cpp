//testing.cpp
//ALL TESTS COMPLETED

#include<iostream>
#include<iomanip>

using namespace std;
#include "stringPkg.h"

int main()
{
	system("cls");
	/*
	//Testing stringLength
	char buf[12] = "Hi There";
	char buf2[10];
	cout << "buf = " << buf << endl;
	int len = stringLength(buf);
	cout << "buf length = " << len << endl;

	//Testing stringCopy
	stringCopy(buf2, 10, buf);
	cout << "buf2 = " << buf2 << endl;
	int len2 = stringLength(buf2);
	cout << "buf 2 length = " << len2 << endl;

	//Testing stringConcatenate
	char buf3[10] = "Fred";
	stringConcatenate(buf, 12, buf3);
	cout << "buf = " << buf << endl;

	//Testing stringGetchar
	char buf4[20] = "Abcdefghijklmnop";
	char test = stringGetchar(buf4, 15);
	cout << "char = " << test << endl;

	//Testing stringFindchar
	char buf5[20] = "Abcd";
	int position = stringFindchar(buf5, 'd');
	cout << "position = " << position << endl; */

	//Testing stringSubstring
	//char s[20] = "Hi There";
	//char t[20];
	//stringSubstring(t, 20, s, 0, 2);	//t should be "Hi "
	//cout << "s = " << s << endl;
	//cout << "t = " << t << endl;

	//Testing stringCompare
	char one[20] = "Fred";
	char two[20] = "Fred";
	int result = stringCompare(one, two);
	cout << "result = " << result << endl;
	return 0;
}
