#include "SecondLab.h"

namespace
{
	std::string getFullKeyWord(const std::string& word, const std::string& key)
	{
		std::string answer{ key };
		while (word.size() > answer.size())
			answer += key;
		answer.erase(word.size()); // Also check variant where word.size() < keyword.size()
		return answer;
	}
}


SecondLab::SecondLab(const std::string& keyword) 
	: keyword(keyword), lang(EncodVectorShell().findLanguage(keyword[0])) 
{}

std::string SecondLab::getLangName() const
{
	return lang.getLangName();
}

void SecondLab::setKey(const std::string& key)
{
	keyword = key;
}

std::string SecondLab::encryption(const std::string& word)
{
	keyword = getFullKeyWord(word, keyword); // find full keyword
	
	std::string encryptedWord;
	for (size_t ind = 0; ind < word.size(); ++ind)
		encryptedWord.push_back(lang.getStartCode() + (word[ind] + keyword[ind]) % lang.size());

	return encryptedWord;
}

std::string SecondLab::decryption(const std::string& word) const
{
	std::string decryptedWord;
	for (size_t ind = 0; ind < word.size(); ++ind)
	{
		char shift = word[ind] + lang.size() - keyword[ind];
		decryptedWord.push_back(lang.getStartCode() + (shift % lang.size()));
	}

	return decryptedWord;
}