#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <algorithm>

using namespace std;

static string FormatNumber(unsigned long long valeur)
{
	string s = to_string(valeur);

	int position = static_cast<int>(s.length()) - 3;

	while (position > 0)
	{
		s.insert(position, " ");
		position -= 3;
	}

	return s;
}

static bool isArmstrong(unsigned long long n)
{
	unsigned long long original = n;
	int digits = 0;
	unsigned long long sum = 0;
	// Count the number of digits
	unsigned long long temp = n;
	while (temp > 0) {
		digits++;
		temp /= 10;
	}

	// Calculate the sum of powers of digits
	temp = n;

	while (temp > 0) {
		unsigned long long digit = temp % 10;

		unsigned long long power = 1;
		for (unsigned long long i = 0; i < digits; i++)
			power *= digit;

		sum += power;
		temp /= 10;
	}

	return sum == original;
}

int main()
{
	// Les nombres Armstrong sont des nombres qui sont égaux à la somme de leurs chiffres élevés à la puissance du nombre de chiffres. Par exemple, 153 est un nombre Armstrong car 1^3 + 5^3 + 3^3 = 153.
	// 
	// les premiers nombres Armstrong sont : 1, 2, 3, 4, 5, 6, 7, 8, 9, 153, 370, 371, 407 avant 1500
	// entre 1_500 et 5_000, les nombres Armstrong sont : 1634
	// entre 5_000 et 10_000, les nombres Armstrong sont : 8208, 9474
	// entre 10_000 et 50_000, les nombres Armstrong sont : aucun
	// entre 50_000 et 100_000, les nombres Armstrong sont : 54748, 92727, 93084
	// entre 100_000 et 500_000, les nombres Armstrong sont : aucun
	// entre 500_000 et 1_000_000, les nombres Armstrong sont : 548834
	// entre 1_000_000 et 5_000_000, les nombres Armstrong sont : 1 741 725, 4 210 818
	// entre 5_000_000 et 10_000_000, les nombres Armstrong sont : 9 800 817, 9 926 315
	// entre 10_000_000 et 50_000_000, les nombres Armstrong sont : 24 678 050, 24 678 051
	// entre 50_000_000 et 100_000_000, les nombres Armstrong sont : 88 593 477
	// entre 100_000_000 et 500_000_000, les nombres Armstrong sont : 146 511 208, 472 335 975
	// entre 500_000_000 et 1_000_000_000, les nombres Armstrong sont : 534 494 836, 912 985 153
	// entre 1_000_000_000 et 5_000_000_000, les nombres Armstrong sont proposés par l'IA de VS mais pas vérifés : 1 415 851 836, 2 147 483 647, 3 215 031 751, 4 294 967 295

	//cout.imbue(locale("fr_FR.UTF-8")); // doesn't work on my desktop Windows 10 migrated to Windows 11 with C++14
	vector<string> armstrongNumbers = {  };
	int startNumber = 5000'000'000;
	int endNumber = 1'000'000'000;
	cout << "Finding Armstrong numbers between " << FormatNumber(startNumber) << " and " << FormatNumber(endNumber) << endl;
	cout << "This may take a while, please wait..." << endl;
	for (size_t n = startNumber; n <= endNumber; n++)
	{
		if (isArmstrong(n))
		{
			cout << "Is " << FormatNumber(n) << " an Armstrong number? ";
			cout << "Yes";
			cout << endl;
			armstrongNumbers.push_back(FormatNumber(n));
		}
	}

	if (armstrongNumbers.size() == 0)
	{
		cout << "Aucun nombre Armstrong n'a ete trouve entre " << FormatNumber(startNumber) << " et " << FormatNumber(endNumber) << endl;
	}
	else
	{
		cout << "Armstrong numbers between " << FormatNumber(startNumber) << " and " << FormatNumber(endNumber) << ": ";
		for (size_t i = 0; i < armstrongNumbers.size(); i++)
		{
			cout << armstrongNumbers[i] << ", ";
		}
	
		cout << endl;
	}

	cout << endl;
	cout << "Press any key to exit: ";
	cin.get();
	return 0;
}