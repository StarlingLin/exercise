#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class CAT
{
	int* itsAge;
	public:
		CAT() : itsAge(new int(5)) {}
		CAT(const CAT& src);
		~CAT() { delete itsAge; }
		int GetAge() const { return *itsAge; }
		void SetAge(int age) { *itsAge = age; }
};

CAT::CAT(const CAT& src)
{
	itsAge = new int(*(src.itsAge));
}

int main()
{
	CAT frisky;
	cout << "Frisky's age: " << frisky.GetAge() << endl;
	cout << "Setting Frisky's age to 6...\n";
	frisky.SetAge(6);
	cout << "Creating boots from frisky\n";
	CAT boots(frisky);
	cout << "Frisky's age: " << frisky.GetAge() << endl;
	cout << "Boots's age: " << boots.GetAge() << endl;
	cout << "Setting Frisky's age to 7...\n";
	frisky.SetAge(7);
	cout << "Frisky's age: " << frisky.GetAge() << endl;
	cout << "Boots's age: " << boots.GetAge() << endl;
}