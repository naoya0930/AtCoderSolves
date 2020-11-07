#include<stdio.h>
#include<vector>
#include<string.h>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<stdexcept>

using namespace std;
using ll = long long int;

const string startTMessage = "開始時間を入力してください：";
const string endTMessage = "終了時間を入力してください：";
const string judgeTMessage = "判定する時間を入力してください；";
const string errStrMessage = "時間は半角数字(0～23)で入力してください\n";
const string errNumMessage = "時間は半角数字(0～23)で入力してください\n";

//string st,en,jd;
//int stNum,enNum,jdNum;

class T{
	public:
		std::vector<string> message;
		std::vector<int> time;

		T(){
			message.push_back(startTMessage);
			message.push_back(endTMessage);
			message.push_back(judgeTMessage);
			time.reserve(3);
		}
};


int numCheck(string s){
	int num;
	try{
		num = std::stoi(s);
	}catch(std::invalid_argument e){
		std::cout << errStrMessage;
		return -1;
	}catch(std::out_of_range e){
		std::cout << errNumMessage;
		return -1;
	}
	return num;
}

int userInput(string message){
	string inputNum;
	cout <<message;
	cin >>inputNum;
	return numCheck(inputNum);
}


int main(void){

	T cla;
	for(int i=0;i<cla.message.size();i++){
		cla.time[i]=userInput(cla.message[i]);
		if(cla.time[i]==-1){
			i=0;continue;
		}
	}
	return 0;
}
