#include "fun_scan_key.h"


unsigned char keyCount;
unsigned char fun_scan_key(void){
	KEYC=0;
	if (KEY==0)
	{
		keyCount++;
		if(keyCount==5)
		{
			return 1;
		}
	}
	else
	{
		keyCount=0;
		return 0;
	}	
}




#endif