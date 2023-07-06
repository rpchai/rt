#include <iostream>
#include <utility>
#include <unordered_map>
using namespace std;

string get_key_string(string key){
	int x[26], i, idx, c=1;
	string ret;
	for (i = 0; i<=25; i++){
		x[i] = 0;
		key +=(char) (i+97);
	}
	cout << "Key matrix is:" << endl;
	for (i=0; i<key.size(); i++){
		if (key[i]=='j') continue;
		idx = key[i] - 97;
		if (!x[idx]){
			x[idx] = 1;
			ret += key[i];
			cout << key[i];
			if (c++%5 == 0) cout << endl;
		}
	}
	return ret;
}

auto make_matrix(string key_string){
	unordered_map<char, pair<int, int>> ret;
	for (int i=0; i<5; i++){
		for (int j=0; j<5; j++)
			ret[key_string[i*5 + j]] = make_pair(i, j);
	}
	return ret;
}

string encrypt(string key,string plain){
	int i, r1, r2, c1, c2;
	auto matrix = make_matrix(key);
	plain += 'a' * (plain.size()%2);
	string ret = plain;
	for (i = 0; i+1<plain.size(); i+=2){
		plain[i] -= 1*(plain[i]=='j');
		r1 = matrix[plain[i]].first;
		r2 = matrix[plain[i+1]].first;
		c1 = matrix[plain[i]].second;
		c2 = matrix[plain[i+1]].second;
		if (r1==r2){
			c1 = (c1+1)%5;
			c2 = (c2+1)%5;
			ret[i] = key[r1*5 +c1];
			ret[i+1] = key[r2*5 + c2];
		}
		else if (c1==c2){
			r1 = (r1+1)%5;
			r2 = (r2+1)%5;
			ret[i] = key[r1*5 +c1];
			ret[i+1] = key[r2*5 +c1];
		}
		else{
			ret[i] = key[r1*5 + c2];
			ret[i+1] = key[r2*5 + c1]; 
		}
	}
	return ret;
}


int main(){
	string plain, cipher, key;
	cout << "Key?: ";
	cin >> key;
	key = get_key_string(key);
	auto matrix = make_matrix(key);
	cout << "Plain text?:";
	cin >> plain;
	cipher = encrypt(key, plain);  
	cout << cipher << endl;
	
}
