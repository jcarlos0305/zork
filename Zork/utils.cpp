#include "utils.h"

// compare function abstracted implementation
int Utils::stringCompare(const char *string1, const char *string2) {
	return _stricmp(string1, string2);
}