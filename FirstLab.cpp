#include "FirstLab.h"
#include <iostream>

FirstLab::FirstLab(int size, const std::string& message) : k1{}, k2{}, matr(5)
{
	if (message.size() != size * size)
		std::cout << "Error\n";

	for (auto& i : matr)
		i.resize(size);

	for (int ind = 0, str = -1; ind < message.size(); ++ind)
	{
		int b = ind % size;
		if (b == 0)
			++str;

		matr[str][b] = message[ind];
	}
}

void FirstLab::setK(const std::string& k_1, const std::string& k_2)
{
	k1 = k_1;
	k2 = k_2;
}

void FirstLab::printMatrix() const
{
	for (const auto& i : matr)
	{
		for (const auto& j : i)
		{
			std::cout << " " << j;
		}
		std::cout << "\n";
	}
	std::cout << "-------------------------\n";
}

void FirstLab::printMessage() const
{
	std::cout << "Зашифрованное сообщение: ";
	for (const auto& i : matr)
	{
		for (const auto& j : i)
		{
			std::cout << j;
		}
	}
	std::cout << "\n";
}

void FirstLab::printReverseMessage() const
{
	std::cout << "Зашифрованное сообщение: ";
	for (int j = 0; j < matr.size(); ++j)
	{
		for (int i = 0; i < matr.size(); ++i)
		{
			std::cout << matr[i][j];
		}
	}
	std::cout << "\n";
}

void FirstLab::transposition()
{
	for (int i = 0; i < matr.size(); ++i)
	{
		for (int j = 0; j < i; j++)
		{
			std::swap(matr[i][j], matr[j][i]);
		}
	}
}

void FirstLab::encryption()
{
	// temp matrix
	mat tmp(matr.size());
	for (auto& i : tmp)
		i.resize(matr.size());

	const int shift = -48;

	// colum
	for (int ind = 0; ind < k1.size(); ++ind)
	{
		for (int i = 0; i < matr.size(); ++i)
		{
			tmp[i][ind] = matr[i][k1[ind] + shift - 1];
		}
	}


	// line
	for (int ind = 0; ind < k2.size(); ++ind)
	{	
		matr[ind] = tmp[k2[ind] + shift - 1];
	}
}


void FirstLab::decryption()
{
	this->transposition();
	std::cout << "Транспонирвоание\n";
	printMatrix();

	// temp matrix
	mat tmp(matr.size());
	for (auto& i : tmp)
		i.resize(matr.size());

	const int shift = -48;

	// colum
	for (int ind = 0; ind < k2.size(); ++ind)
	{
		for (int i = 0; i < matr.size(); ++i)
		{
			tmp[i][ind] = matr[i][k2[ind] + shift - 1];
		}
	}

	// line
	for (int ind = 0; ind < k1.size(); ++ind)
	{
		matr[k1[ind] + shift - 1] = tmp[ind];
	}
}