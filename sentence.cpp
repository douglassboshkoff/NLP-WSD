#include <iostream>

#include "sentence.h"

using namespace std;

Sentence::Sentence(string sentence) {
	m_words = new vector<string>();	
	/* Split the string into tokens */
	stringstream ss;
	ss.str(cull_punctuation(sentence));
	string token;
	while(getline(ss, token, ' ')) {
		m_words->push_back(token);
	}
}

Sentence::~Sentence() {
	m_words->clear();
	delete m_words;m_words = NULL;
}

int Sentence::get_size() {
	return m_words->size();
}

string Sentence::get_word(int index) {
	return m_words->at(index);
}

string Sentence::to_string() {
	string tostring = "";
	for(int i =0; i < m_words->size(); i++) {
		tostring += m_words->at(i);	
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


