#include <iostream>

using namespace std;

extern int g_value;
static int gs_value;

int main()
{
	cout << "This is Interview Code test" << endl;
	cout << g_value << endl;
	cout << gs_value << endl;
	return 0;
}