#pragma once
#include <vector>
#include <string>
#include <sstream>

class Sentence {

	public : 
		Sentence(std::string sentence);
		~Sentence();	
		int get_size();
		int get_keyword_pos();
		std::string get_word(int index);
		std::string to_string();

	private :
		std::vector<std::string> m_words;
		
		std::string cull_punctuation(std::string sentence);
		int m_keywordPos;
		
};
