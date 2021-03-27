#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	string inputString;
	cout << "Enter your string: ";
	getline(cin, inputString);

	cout << "Enter size of encrypted string: ";
	int size;
	do {

		cin >> size;
		if (size <= inputString.size())
			cout << "Размер зашифрованной строки должен превышать размер исходной строки\n";

	} while (size <= inputString.size());

	vector<bool> encryptMask(size);
	for (auto i = 0; i < inputString.size(); i++)
	{
		while (true)
		{
			int rand_index = rand() % size;
			if (!encryptMask[rand_index])
			{
				encryptMask[rand_index] = true;
				break;
			}
		}
	}

	string encryptedString;
	encryptedString.resize(size);
	for (auto i = 0, j = 0; i < size; i++)
	{
		if (encryptMask[i])
		{
			encryptedString[i] = inputString[j];
			j++;
		}
		else
			encryptedString[i] = inputString[rand() % (inputString.size())];
	}

	cout << "Зашифрованная строка: " << encryptedString << endl;

	string decryptedString;

	for (auto i = 0, j = 0; i < size; i++)
	{
		if (encryptMask[i])
		{
			decryptedString.push_back(encryptedString[i]);
		}
	}

	cout << "Расшифрованная строка: " << decryptedString << endl;

	return 0;
}