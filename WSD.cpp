#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <string>
#include <cctype>

#include "sentence.h"

using namespace std;


void tolowercase(string& word);
int disambiguate(string word, Sentence sample, list<Sentence> sense1Sentence, list<Sentence> sense2Sentence);

int main(int argc, char** argv) {
	
	if(argc != 3) {
		cout << "Incorrect number of arguments" << endl;
		return 1;
	}
	ifstream infile(argv[1]);
	int num_sentences = atoi(argv[2]);
	string word;
	string sample;
	string temp;
	list<Sentence> sense1list;
	list<Sentence> sense2list;

	infile >> word;
	infile.ignore();
	getline(infile, sample);
	Sentence sample_sentence(sample);

	cout << "Word: " << word << endl;
	cout << "Sample: " << sample << endl;

	
	infile.ignore();
	infile.ignore();

	for(int i = 0; i < num_sentences; i++) {
		getline(infile, temp);
		tolowercase(temp);
		Sentence s(temp);
		cout << s.to_string() << endl;
		sense1list.push_back(s);
	}

	infile.ignore();
	infile.ignore();

	for(int i = 0; i < num_sentences; i++) {
		getline(infile, temp);
		tolowercase(temp);
		Sentence s(temp);
		cout << s.to_string() << endl;
		sense2list.push_back(s);
	}

	infile.close();
	return 0;	
}


/**
	Returns 1 if the word is being used in the sentence in the first sense or 2 if the word is
	being used in the sentence in the second sense. 
**/
int disambiguate(string word, Sentence sample, list<Sentence> sense1Sentence,
				list<Sentence> sense2Sentence) {
	/* Process the list sentences into sets. We will use some weighting for proximity to the target word. */

	map<string, int> m1;
	map<string, int> m2;

	for(list<Sentence>::iterator it = sense1Sentence.begin(); it != sense1Sentence.end(); ++it) {
		Sentence s = *it;
		for(int i = 0; s.get_size(); i++) {
			if(m1.count(s.get_word(i)) == 1) {
				m1[s.get_word(i)] = m1[s.get_word(i)] + 1;
			}
			else {
				m1[s.get_word(i)] = 1;
			}
		}
	}

	for(list<Sentence>::iterator it = sense2Sentence.begin(); it != sense2Sentence.end(); ++it) {
		Sentence s = *it;
		for(int i = 0; s.get_size(); i++) {
			if(m2.count(s.get_word(i)) == 1) {
				m2[s.get_word(i)] = m2[s.get_word(i)] + 1;
			}
			else {
				m2[s.get_word(i)] = 1;
			}
		}
	}

	int score1 = 0;
	int score2 = 0;
	for(int i = 0; i < sample.get_size(); i++) {
		string word = sample.get_word(i);
		tolowercase(word);

		if(m1.count(word) > 0) {
			score1 += m1[word];
		}
		
		if(m2.count(word) > 0) {
			score2 += m1[word];
		}
	}

	return score1 > score1 ? 1 : 2;
}

void tolowercase(string& word) {
	for(string::iterator it = word.begin(); it != word.end(); ++it) {
		*it = tolower(*it);
	}
}
