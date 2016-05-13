#pragma once
class CRC {
private:
	int tabSize;
	int xorSize;
	int *tab;
	int *crcXor;
public:

	CRC() {
		this->xorSize = 3;
	}

	void setTabSize(int tabSize) {
		this->tabSize = tabSize;
		tab = new int[this->tabSize];
	}

	void setXor(){
		crcXor = new int[this->xorSize];
	}

};
