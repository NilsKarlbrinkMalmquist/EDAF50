#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include <cmath>
#include "word.h"
#include "dictionary.h"

using std::string;
using std::vector;

Dictionary::Dictionary() {

	std::ifstream readFile("words.txt");
	string line;

	while(std::getline(readFile, line)){
		string word;
		std::stringstream ss(line);
		ss >> word;

		if(word.length() <= SIZE){
			dictionarySet.insert(word);
			int nbrTrigrams;
			ss >> nbrTrigrams;

			vector<string> trigrams;
			string trigram;
			for(int i = 0; i < nbrTrigrams; i++){
				ss >> trigram;
				trigrams.push_back(trigram);
			}
			words[word.length() - 1].push_back(Word(word, trigrams));
		}
	}
	readFile.close();
}

bool Dictionary::contains(const string& word) const {
	return dictionarySet.count(word); //sök i word-arrayn istället
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	if(suggestions.size() > 0){//lägg i trim ist
		rank_suggestions(suggestions, word);
		//trim_suggestions(suggestions);
	}
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string> &suggestions, const string &word) const{
	int nbrLetters = word.length();
	double nbrTrigrams = word.length() - 2;
	unsigned int minMatches = round(nbrTrigrams/2.0);
	vector<string> trigrams;
	for(int i = 0; i < nbrTrigrams; i++){
		trigrams.push_back(word.substr(i, 3));
	}
	sort(trigrams.begin(), trigrams.end());

	for(int i = nbrLetters - 2; i <= nbrLetters; i++){
		for(auto &w: words[i]){
			if(w.get_matches(trigrams) >= minMatches){
				suggestions.push_back(w.get_word());
			}
		}
	}
}

void Dictionary::rank_suggestions(vector<string> &suggestions, const string &word) const{
	vector<std::pair<int,string>> rankings;
	int a = word.length();
	int track;
	for(auto &suggestion: suggestions){
		int cost[SIZE+1][SIZE+1];
		int b = suggestion.length();
		for(int i = 0; i <= a; i++){
			cost[0][i] = i;
		}
		for(int j = 0; j <= b; j++){
			cost[j][0] = j;
		}

		for(int i = 1; i <= a; i++){
			for(int j = 1; j <= b; j++){
				if (suggestion[j-1] == word[i-1]) {
					track = 0;
				}
				else{
					track = 1;
				}
				cost[i][j] = std::min({cost[i-1][j] + 1, cost[i][j-1] + 1, cost[i-1][j-1] + track});
			}
		}
		rankings.push_back(make_pair(cost[a][b], suggestion));
		sort(rankings.begin(), rankings.end());
		suggestions.clear();
		for(auto &pair: rankings){
			suggestions.push_back(pair.second);
		}
	}
}

void Dictionary::trim_suggestions(vector<string> &suggestions) const{
	suggestions.resize(5);
}
