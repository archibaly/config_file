#include <stdio.h>
#include <string.h>

#include "kmp.h"

#define KEY_MAX_SIZE	64
#define MAXLINE			1024

int config_file_get(const char *file_name, const char *key, char *value)
{
	FILE *fp;
	char tmp[KEY_MAX_SIZE];
	char buf[MAXLINE];
	int pos, i;

	fp = fopen(file_name, "r");

	if (fp == NULL)
		return -1;

	sprintf(tmp, "%s=", key);	/* key=value */

	while (fgets(buf, MAXLINE, fp) != NULL) {
		if (kmp(buf, tmp) == 0) {	/* found */
			pos = strlen(tmp);
			for (i = 0; *(buf + pos + i) != '\n'; i++)
				value[i] = *(buf + pos + i);
			value[i] = 0;
			fclose(fp);
			return 0;
		}
	}

	fclose(fp);
	return -1;
}

int config_file_set(const char *file_name, const char *key, const char *value)
{
	FILE *fp;
	FILE *bak;
	char tmp[KEY_MAX_SIZE];
	char buf[MAXLINE];
	int ok = 0;
	char file_name_tmp[1024];
	
	fp = fopen(file_name, "r");

	sprintf(file_name_tmp, "%s", file_name);
	strcat(file_name_tmp, ".bak");

	bak = fopen(file_name_tmp, "w");

	if (fp == NULL || bak == NULL)
		return -1;

	sprintf(tmp, "%s=", key);

	while (fgets(buf, MAXLINE, fp) != NULL) {
		if (kmp(buf, tmp) == 0) {
			ok = 1;
			sprintf(buf, "%s=%s\n", key, value);
		}
		fputs(buf, bak);
	}

	rename(file_name_tmp, file_name);
	fclose(fp);
	fclose(bak);

	if (ok)
		return 0;
	return -1;
}
