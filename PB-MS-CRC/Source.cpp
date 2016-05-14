#include<iostream>
#include<fstream>
#include<vector>
#include"PB.h"
#include"ModSum.h"
#include"CRC.h"

using namespace std;

int main() {

	fstream file;
	ParBit pb;
	ModSum ms;
	CRC crc;
	vector<int>crcFirst;

	char* buffer;
	int bits = 8;
	int mod = 10;
	int lenght = 0;
	int numbers = 0;
	int evenity = 0;
	int sum = 0;
	int controlLenght = 0;


	file.open("data2.foo", ios::binary | ios::in);

	if (file.good() == true) {

		cout << endl;
		cout << endl;

		ms.setMod(mod);

		file.seekg(0, ios::end);
		lenght = file.tellg();
		file.seekg(0, ios::beg);

		buffer = new char[lenght];

		file.read(buffer, lenght);

		crc.setLenght(lenght);

		cout << "Dlugosc pliku: " << lenght << endl;

		cout << endl;
		cout << endl;

		cout <<"Tresc pliku, binarnie: " <<endl;

		for (int i = 0; i < lenght; i++) {

			numbers = 0;

			sum = sum + buffer[i] % ms.getMod();

			for (int j = 0; j <bits; j++) {
				if ((buffer[i] & 1 << j)>0) {
					cout << "1";
					crcFirst.push_back(1);
					numbers = numbers + 1;
					controlLenght += 1;
				}
				else
				{
					crcFirst.push_back(0);
					cout << "0";
					controlLenght += 1;
				}
			}

			evenity += numbers;

			cout <<" ";

		}

		pb.setOnes(numbers);
		pb.setEvenity(evenity);
		ms.setSum(sum%ms.getMod());

		cout << endl;
		cout << endl;

		cout << "Dlugosc binarna pliku: " << controlLenght << endl;

		cout << endl;
		cout << endl;

		cout << "Liczba jedynek ostatniego bajtu: " << pb.getOnes() << endl;

		cout << endl;
		cout << endl;

		cout << "liczba jedynek w pliku: " << pb.getEvenity() << endl;

		cout << endl;
		cout << endl;

		if (pb.evenBit(evenity) == true) {
			cout << "Bit parzystosci wynosi 1" << endl;
		}
		else
		{
			cout << "Bit parzystosci wynosi 0" << endl;
		}

		cout << endl;
		cout << endl;

		cout << "Suma modulo: " << ms.getSum() << endl;

		cout << endl;
		cout << endl;

		for (int i = 0; i < 3; i++) {
			crcFirst.push_back(0);
		}

		crc.setTabSize(crcFirst.size());

		cout << "Bity na wekotrze" << endl;
		for (int i = 0; i < crc.getTabSize(); i++) {
			cout << crcFirst[i];
		}

		cout << endl;
		cout << endl;

		for (int i = 0; i < crc.getTabSize(); i++) {
			crc.setTab(crcFirst[i], i);
		}
		
		cout << "Bity z klasy" << endl;
		for (int i = 0; i < crc.getTabSize(); i++) {
			cout << crc.getTab(i);
		}
		
		cout << endl;
		cout << endl;
		
		crc.setStop();
		crc.setCountBits();

		crc.countCRC();

		cout << "CRC:" << endl;

		for (int i = 0; i < 3; i++) {
			cout << crc.getResult(i);
		}

		cout << endl;
		cout << endl;

		file.close();
	}
	else {
		cout << "Nie mozna otworzyc pliku" << endl;
	}

	system("pause");
	return 0;
}