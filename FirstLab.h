#pragma once
#include <vector>
#include <string>

class FirstLab
{
	using mat = std::vector<std::vector<char>>;
public:
	FirstLab(int size, const std::string& message);
	void setK(const std::string& k1, const std::string& k2);
	void printMatrix() const;
	void printMessage() const;
	void printReverseMessage() const;
	
	void encryption();
	void decryption();

private:
	std::string k1;
	std::string k2;
	mat matr;

	void transposition();
};