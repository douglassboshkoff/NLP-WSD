#include <iostream>

#include "sentence.h"

using namespace std;

Sentence::Sentence(string sentence, string keyword) {
	/* Split the string into tokens */
	stringstream ss;
	ss.str(cull_punctuation(sentence));
	string token;
	int tokencount = -1;
	while(getline(ss, token, ' ')) {
		if(token == keyword) {
			m_keywordPos = tokencount; 
		}
		m_words.push_back(token);
	}

	if(tokencount == -1) {
		cout << "ERROR: sentence 
	}
}

Sentence::~Sentence() {
}

int Sentence::get_size() {
	return m_words.size();
}

string Sentence::get_word(int index) {
	return m_words.at(index);
}

string Sentence::to_string() {
	string tostring = "";
	for(int i =0; i < m_words.size(); i++) {
		tostring += m_words.at(i);	
	}
	return tostring;
}

string Sentence::cull_punctuation(string sentence) {
	for(string::iterator it = sentence.begin(); it != sentence.end(); ++it) {
		if(*it == ',' || *it == '.' || *it == '?' || *it == '!' || *it == '\'' || *it == ';' || *it == '\"') {
			sentence.erase(it, it+1);
			it--;
		}
	}
	return sentence;
}


