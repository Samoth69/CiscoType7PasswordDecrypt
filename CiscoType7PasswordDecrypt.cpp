//CiscoType7PasswordDecrypt.cpp Thomas Violent VS2019 08/09/2020

#include <iostream>
#include <string>
using namespace std;

const char salt[54] = "dsfd;kfoA,.iyewrkldJKDHSUBsgvca69834ncxv9873254k;fg87";

void decryptPW(string *in, string *out) {
	//salt index
	int index = stoi(in->substr(0, 2));

	//mdp hashé
	string pwHashed = in->substr(2);

	//on réserve la variable de sortie avec le bon nombre de caractère
	out->reserve(pwHashed.size() / 2);

	int counter = 0;

	for (int i = 0; i < pwHashed.size() / 2; i++) {
		int cur_index = (i + index) % 53;

		char cur_salt = salt[cur_index];
		char cur_hex = stoi(pwHashed.substr(counter, 2),0,16);

		//ceci est la ligne importante
		char clearTextChar = cur_salt ^ cur_hex;

		out->push_back(clearTextChar);

		counter+=2;
	}
}

int main()
{
	string pw, out;
	cout << "hashed passwd:";
	cin >> pw;

	decryptPW(&pw, &out);

	cout << "decrypted passwd: " << out;
}
