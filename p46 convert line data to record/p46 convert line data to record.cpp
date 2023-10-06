#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct stAccount
{
	string Number;
	string pinCode;
	string name;
	string phone;
	double balance;
};

vector <string> extractRecordInfo(string line)
{//       A150#//#1234#//#Gomaa ElSherbini#//#00925365232#//#5000.000000
	
	vector <string> vClient;
	string delim = "#//#";
	short pos = 0;
	string clientItem = "";

	while ((pos=line.find(delim)) != -1)
	{
		clientItem = line.substr(0, pos);
		if (clientItem != "")
		{
			vClient.push_back(clientItem);
		}
		line.erase(0, pos + delim.length());
	}
	if(line!="")
	{
		vClient.push_back(line);
	}

	return vClient;
}

stAccount readClientrecord(vector <string> vClient)
{
	stAccount client;
	
	client.Number = vClient[0];
	client.pinCode = vClient[1];
	client.name = vClient[2];
	client.phone = vClient[3];
	client.balance = stod(vClient[4]);

	return client;
}

void printClientRecord(stAccount client)
{
	cout << "Account Number : " << client.Number << endl;
	cout << "PinCode        : " << client.pinCode << endl;
	cout << "Name           : " << client.name << endl;
	cout << "Phone          : " << client.phone << endl;
	cout << "Balance        : " << client.balance << endl;
}

int main()
{
	string line = "A150#//#1234#//#Gomaa ElSherbini#//#00925365232#//#5000.000000";
	stAccount client = readClientrecord(extractRecordInfo(line));
	
	cout << "\n\nLine record is:\n";
	cout << line << endl;


	cout << "\n\nThe Following is the extracted client record:\n\n";
	printClientRecord(client);

	

	return 0;

}