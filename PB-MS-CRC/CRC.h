#pragma once

#define XSIZE 2
#define RESSIZE 3

class CRC {
private:
	int tabSize;
	int stop;
	int *tab;
	int crcXor[XSIZE];
	int result[RESSIZE];
	int lenght;
	int a;
	int z;
public:
	CRC() {
		this->a = 0;
		this->z = 0;
		for (int i = 0; i < XSIZE; i++) {
			crcXor[i] = i;
		}

		for (int i = 0; i < RESSIZE; i++) {
			crcXor[i] = 0;
		}
	}

	void setLenght(int lenght) {
		this->lenght = lenght;
	}

	void setTabSize(int tabSize) {
		this->tabSize = tabSize;
		tab = new int[this->tabSize];
	}


	void setTab(int number, int i) {
		this->tab[i] = number;
	}

	void setCountBits() {	
		crcXor[0] = 0;
		crcXor[1] = 1;
	}

	void setStop() {
		this->stop = this->tabSize - this->lenght;
	}

	int getTabSize() {
		return this->tabSize;
	}

	int getTab(int i) {
		return this->tab[i];
	}

	void countCRC() {
		while (this->a<this->stop)
		{
			if (tab[a] == 1) {
				tab[a] = tab[a] ^ crcXor[1];
				tab[a+1] = tab[a+1] ^ crcXor[0];
				tab[a+2] = tab[a+2] ^ crcXor[1];
				tab[a+3] = tab[a+3] ^ crcXor[1];
			}
			else if (tab[a] == 0) {
				tab[a + 1] = tab[a + 1] ^ crcXor[1];
				tab[a + 2] = tab[a + 2] ^ crcXor[0];
				tab[a + 3] = tab[a + 3] ^ crcXor[1];
				tab[a + 4] = tab[a + 4] ^ crcXor[1];
			}
			a++;
		}

		for (int i = this->tabSize - 3; i < this->tabSize; i++) {
			this->result[z] = tab[i];
			z++;
		}
	}

	int getResult(int i = 0) {
		return this->result[i];
	}

};
