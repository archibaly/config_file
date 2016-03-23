#ifndef __CONFIG_FILE_H__
#define __CONFIG_FILE_H__

int config_file_get(const char *file_name, const char *key, char *value);
int config_file_set(const char *file_name, const char *key, const char *value);

#endif /* __CONFIG_FILE_H__ */
