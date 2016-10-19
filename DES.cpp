#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int strToInt(string s){
	int x = 0;
	for(int i=0; i<s.length(); i++) x = 2*x+(s[i]-'0');
	return x;
}
string intToStr(int x){
	string s = "";
	while(x>0){
		s = char(x%2+'0') + s;
		x/=2;
	}
	return s;
}
string sBox(string text){
	int _template[8][4][16] = {
	   	{	14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
	   		0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
	   		4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
	   		15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
	   	},
    	{	15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
    		3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
    		0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
    		13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
    	},
    	{	10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
    		13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
    		13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
    		1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
    	},
    	{	7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
    		13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
    		10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
    		3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
    	},
    	{	2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
    		14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
    		4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
    		11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
    	},
    	{	12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
    		10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
    		9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
    		4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
    	},
    	{	4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
    		13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
    		1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
    		6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
    	},
    	{	13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
    		1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
    		7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
    		2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
    	}
    };
    string x = "";
    for(int i=0; i<text.length(); i+=6){
    	string tmp = "";
		tmp = text[i]+text[i+5];
    	int row = strToInt(tmp);
    	tmp = "";
    	for(int j=i+1; j<i+5; j++) tmp+=text[j];
    	int col = strToInt(tmp);
    	x+= intToStr(_template[i][row][col]);
    }
    return x;
}
string permutation(string text){
	int _template[] = {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25};
	string x = "";
	for(int i=0; i<32; i++) x+=text[_template[i]-1];
	return x;
}
void xorTK(string &text1, string text2){
	for(int i=0; i<text1.length(); i++) text1[i] = text1[i]!=text2[i] ? '1' : '0';
}
string expansion(string text){
	int _template[] = {31, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1};
	string x = "";
	for(int i=0; i<48; i++) x+=text[_template[i]-1];
	return x;
}
string initialPermutation(string plainText){
	int _template[] = {58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};
	string x = "";
	for(int i=0; i<64; i++) x+=plainText[_template[i]-1];
	return x;
}

void leftShift(string &key, int LS){
	string tmp;
	tmp.append(key, 0, LS);
	key.insert(28, tmp);
	key.erase(0, LS);
	tmp.append(key, 28, LS);
	key+=tmp;
	key.erase(28, LS);
}
string PC2(string key){
	int _template[] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};
	string x = "";
	for(int i=0; i<48; i++) x+=key[_template[i]-1];
	return x;
}
string PC1(string externalKey){
	int _template[] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};
	string x = "";
	for(int i=0; i<56; i++) x += externalKey[_template[i]-1];
	return x;
}
string generateKey(string &key, int LS){
	leftShift(key, LS);
	return PC2(key);
}
void encryptDES(string &text, string &key, int LS){
	string key_tmp = generateKey(key, LS);
	string left, right;
	left.append(text, 0, 32);
	text.erase(0, 32);
	right = text;
	right = expansion(right);
	xorTK(right, key_tmp);
	right = permutation(sBox(right));
	xorTK(right, left);
	text += right;
}

void randomInput(string &plainText, string &externalKey){
	srand(time(NULL));
	for(int i=0; i<64; i++){
		plainText+= rand()%2+'0';
		externalKey+= rand()%2+'0';
	}
	cout<<"Plaintext = "<<plainText<<"\nExternal Key = "<<externalKey<<endl;
}
void exampleInput(string &plainText, string &externalKey){
	plainText = "1100110011001100010101010101010111001011100011000111000011100001";
	externalKey = "1010101010100011001100110011001100110011001100110011101010101010";
}
void manualInput(string &plainText, string &externalKey){
	cin>>plainText;
	cin>>externalKey;
}

int main(){
	string plainText = "";
	string externalKey = "";
	int scheduleLS[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
	exampleInput(plainText, externalKey);
	//manualInput(plainText, externalKey);
	//randomInput(plainText, externalKey);
	string key = PC1(externalKey);
	string cipherText = initialPermutation(plainText);
	for(int i=0; i<16; i++) encryptDES(cipherText, key, scheduleLS[i]);
	cout<<"Ciphertext = "<<cipherText<<endl;
}
