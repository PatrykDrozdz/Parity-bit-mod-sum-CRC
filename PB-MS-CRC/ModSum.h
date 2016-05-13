#pragma once
class ModSum {
private:
	int mod;
	int sum;

public:

	void setMod(int mod) {
		this->mod= mod;
	}

	void setSum(int sum) {
		this->sum = sum;
	}

	int getMod() {
		return this->mod;
	}

	int getSum() {
		return this->sum;
	}

};