#pragma once
#include <string>
#include <vector>

class Encod
{
private:
	std::string languageName;
	int startCode;
	int endCode;

public:
	Encod(const std::string& name, int st, int end) : languageName(name), startCode(st), endCode(end) {}
	std::string getLangName() const { return languageName; }
	int getStartCode() const { return startCode; }
	size_t size() const { return endCode - startCode + 1; }
	bool isThisCodeBySymbol(char x) const { return static_cast<int>(x) >= startCode && static_cast<int>(x) <= endCode ? true : false; }
};

// shell-class vector of languages
class EncodVectorShell
{
public:
	EncodVectorShell() : vec{}
	{
		vec.push_back(new Encod("EngBig", 'A', 'Z'));
		vec.push_back(new Encod("EngSmall", 'a', 'z'));
		vec.push_back(new Encod("RusBig", 'À', 'ß'));
		vec.push_back(new Encod("RusSmall", 'à', 'ÿ'));
	}

	~EncodVectorShell()
	{
		for (auto& i : vec)
			delete i;
	}

	Encod findLanguage(char ch)
	{
		for (const auto& i : vec)
		{
			if (i->isThisCodeBySymbol(ch))
				return *i;
		}

		return Encod("undefinedLang", '0', '0');
	}

	EncodVectorShell(const EncodVectorShell&) = delete;
	EncodVectorShell& operator=(const EncodVectorShell&) = delete;

private:
	std::vector<Encod*> vec;
};