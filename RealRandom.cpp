#include <sys/timeb.h>


// Works with millisecond, instead of using seconds
int getMilliCount() {
	timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}

int GenRandom (int minValue, int maxValue) {
	int tempValue = 0;
	
	if(minValue > maxValue) {
		tempValue = maxValue;
		maxValue = minValue;
		minValue = tempValue;
	} else if (minValue == maxValue) {
		return maxValue;
	}
	
	// Now it Starts
	tempValue = maxValue - minValue;
	
	
	// generate anyValue bettween 0 to tempValue;
	tempValue = getMilliCount() % (tempValue + 1);
		
	
	return minValue + tempValue;
}