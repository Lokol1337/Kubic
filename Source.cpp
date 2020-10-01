#include<iostream>
#include<vector>
#include <string>
using namespace std;

vector<vector<char>> KubWord;
int counterWord;
string word,bufWord;
vector<vector<int>> whereLit;
vector<vector<int>> mtrSm;
int n;

void cinWord() {
	cin >> n >> word;
	string nWord = word;
	while (nWord != "") {
		counterWord++;
		nWord.pop_back();
	}
	KubWord.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> bufWord;
		KubWord[i].resize(6);
		for (int j = 0; j < 6; j++) {
			KubWord[i][j] = bufWord[j];
		}
	}
}

void AlgWord() {
	mtrSm.resize(2 + n + counterWord);
	int length = 2 + n + counterWord;
	//cout << n << " " << counterWord;
	for (int i = 0; i < length; i++) {
		mtrSm[i].resize(length);
	}
	for (int i = 0; i < length; i++) {
		cout << i;
		if (i == 0) {
			mtrSm[0].push_back(0);
		}
		else if (i <= n) {
			mtrSm[0].push_back(1);
		}
		else {
			mtrSm[0].push_back(0);
		}
	}
	for (int i = 0; i < length; i++) {
		if (i < counterWord) {
			mtrSm[length-1].push_back(0);
		}
		else if(i>=counterWord && i<length-2){
			mtrSm[length - 1].push_back(1);
		}
		else {
			mtrSm[length-1].push_back(0);
		}
	}
}

int main() {
	cinWord();
	AlgWord();
	int length = 2 + n + counterWord;
	for (int i = 0; i < length; i++) {
		cout << endl;
		for (int j = 0; j < length; j++) {
			cout << mtrSm[i][j] << " ";
		}
	}
}