#include <iostream>
#include <Windows.h>
#include "FirstLab.h"
#include "SecondLab.h"

void firstLab();
void secondlab();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	secondlab();
}


void firstLab()
{
	FirstLab task(5, "шифрование_перестановкой_");
	task.printMatrix();
	task.setK("52314", "21435");

	task.encryption();
	task.printMatrix();
	task.printMessage();

	task.decryption();
	task.printMatrix();
	task.printReverseMessage();
}


void secondlab()
{
	std::string code = "ENTER";
	std::string word = "SHIFROVANIE";
	//std::string code = "мяукот";
	//std::string word = "консультация";

	SecondLab sl(code);

	std::string encryptedWord = sl.encryption(word);
	std::cout << encryptedWord << "\n";
	std::cout << sl.decryption(encryptedWord);
}