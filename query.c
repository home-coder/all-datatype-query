#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void query_same(const char *src, const char *dst)
{
	const char *ps = src, *pd = dst;

	for (; *(ps + strlen(dst)-1) != '\0'; ps++) {
			if (*ps == *pd) {
				pd++;	
			} else {
				pd = dst;
				ps = src++;
				continue;
			}
			if (*pd == '\0') {
				printf("pd in head of ps: %s\n", ps - strlen(dst) + 1);
			}
		}
}

int main()
{
	char *src = "helloworldhehehe77he110w0r1d";
	char *dst = "hehe";

	query_same(src, dst);

	return 0;
}
