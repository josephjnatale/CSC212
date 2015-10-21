#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	char letters[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int runtimes;
	cout<<"enter how many inputs you want: ";
	cin>>runtimes;
	cin.ignore(numeric_limits<streamsize>::max(),'\n') ;
	string inputs[runtimes+1];
	
	for(int j=0; j<runtimes; j++)
		getline(cin, inputs[j]);

	for(int q=1; q<=runtimes; q++) {
	
		int contains[26]={0};
		transform(inputs[q].begin(), inputs[q].end(), inputs[q].begin(), ::tolower);
	
	
		for(int i=0; i<inputs[q].length(); i++) {
		
			for(int j=0; j<26; j++) {

				if(inputs[q].at(i)==letters[j])
					contains[j]++;
			
			}

		}

		for(int k=0; k<26; k++)
			cout<<contains[k]<<", ";

		cout<<endl;

		bool doublePangram=false, triplePangram=false,  pangram=false;

		for(int k=0; k<26; k++){

			if(contains[k]==0)
				break;

			if(k==25 && contains[k]>0)
				pangram=true;
		}


		if(pangram==true)
			for(int k=0; k<26; k++) {

				if(contains[k]==1)
					break;

				if(k==25 && contains[k]>1)
					doublePangram=true;

			}

		if(doublePangram==true)
			for(int k=0; k<26; k++) {

				if(contains[k]==2)
					break;

				if(k==25 && contains[k]>2)
					triplePangram=true;
			}


		if(triplePangram==true)
			cout<<"Case "<<q<<": Triple Pangram!!!"<<endl;
		else if(doublePangram==true)
			cout<<"Case "<<q<<": Double pangram!!"<<endl;
		else if(pangram==true)
			cout<<"Case "<<q<<": Pangram!"<<endl;
		else
			cout<<"Case "<<q<<": Not a pangram"<<endl;

	}

return 0;
}
