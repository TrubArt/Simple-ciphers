#pragma once
#include "Encodings.h"
#include <string>

class SecondLab
{
public:
	SecondLab(const std::string&);
	std::string getLangName() const;
	void setKey(const std::string&);

	std::string encryption(const std::string&);
	std::string decryption(const std::string&) const;

private:
	std::string keyword;
	Encod lang;
};
