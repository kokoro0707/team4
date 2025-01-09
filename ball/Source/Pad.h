#pragma once
class Pad
{
	void Updata();
	bool IsPress(int button);
	bool IsTrigger(int button);
	bool IsRelase(int button);
	int GetJoypadAnalogInput(int* XBuf, int* YBuf, int InputType);
	int GetJoypadInputState(int InputType);

};