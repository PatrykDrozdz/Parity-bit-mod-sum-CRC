#pragma once
class ParBit {
private:
	int ones;
	int even;
	int evenity;

public:

	ParBit() {
		this->even = 2;
	}

	void setOnes(int ones) {
		this->ones = ones;
	}

	void setEvenity(int evenity) {
		this->evenity = evenity;
	}

	int getOnes() {
		return this->ones;
	}

	int getEven() {
		return this->even;
	}

	int getEvenity() {
		return this->evenity;
	}

	bool evenBit(int evenity) {
		if (evenity % even == 0) {
			return false;
		}
		else
		{
			return true;
		}

	}

};