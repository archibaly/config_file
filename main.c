#include <stdio.h>
#include "config_file.h"

int main()
{
	char ssid[32];
	char authmod[32];
	char radiusip[32];

	int ret = config_file_get("config", "ssid", ssid); 
	if (ret < 0)
		return -1;

	printf("%s\n", ssid);

	ret = config_file_get("config", "authmod", authmod); 

	if (ret < 0)
		return -1;

	printf("%s\n", authmod);

	ret = config_file_get("config", "radiusip", radiusip); 
	if (ret < 0)
		return -1;

	printf("%s\n", radiusip);

	config_file_set("config", "ssid", "jackyliu");
	config_file_set("config", "seckey", "12345678");

	return 0;
}
