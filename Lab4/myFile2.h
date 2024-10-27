#include <cstdlib> 
using namespace std;

class SetInt
{
public:
	SetInt() : elem(NULL), size(0) {};
	SetInt(int[], int);
	~SetInt();
	SetInt(const SetInt&);  // copy constructor
	void add(int);
	void remove(int);
	bool contains(int);
	int nbElem();
	int* tabElem();
private:
	int* elem;
	int size;
	bool containsIn(int n, int&);
};


