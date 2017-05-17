#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false = 0, true}bool;

static void query_arri(int *src, int slen, int *dst, int dlen)
{
	int *psrc = src, *pdst = dst;	
	int i = 0, j = 0;
	bool flag = false;

	for (i = 0; (i + dlen) <= slen; i++) {
		for (j = 0; j < dlen; j++) {
			if ( *(psrc+i+j) != dst[j] ) {
				break;
			}
			if (j == dlen - 1) {
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	if (flag) {
		printf("have find\n");
	} else {
		printf("not find\n");
	}
}

static void query_location_arri(int *src, int slen, int *dst, int dlen)
{
	int *psrc = src, *pdst = dst;
	int i = 0, j = 0, n = 0;
#define LEN  32
	int loc[LEN] = {-1,};

	for (; (i+dlen) <= slen; i++) {
		for (j = 0; j < dlen; j++) {
			if ( *(psrc+i+j) != *(dst+j) ) {
				break;
			}
			if ( j == dlen-1 ) {
				loc[n++] = i;
			}
		}
	}
	if (loc[0] != -1) {
		printf("location :");
		for (i = 0; i < n; i++) {
			printf("%d, ", loc[i]);
		}
		printf("\n");
	} else {
		printf("not find\n");
	}
}

static void query_str(char *src, char *dst)
{
	char *psrc = src, *pdst = dst;
	char *loc[LEN] = {NULL,};
	int n = 0, i = 0;

	for (; (psrc + strlen(dst)) <= (src + strlen(src)); psrc++) {
		char *ppsrc = psrc;
		for (pdst = dst; *pdst != '\0'; pdst++, ppsrc++) {
			printf("(%c %c)\n", *ppsrc, *pdst);
			if (*ppsrc != *pdst) {
				break;
			}
		}
		if (*pdst == '\0') {
			loc[n++] = psrc;
		}
	}
	if (loc[0] != NULL) {
		for (i = 0; i < n; i++) {
			printf("%d =%s,", i, loc[i]);
		}
		printf("\n");
	} else {
		printf("not find\n");
	}
}

int main()
{
//1.0 查询一段数组是否在另一个数组中连续排列
	{
		int src[] = {1, 3, 2, 5, 6, 9, 0, 5, 8, 3, 4};
		int dst[] = {3, 4};
		int slen = sizeof(src)/sizeof(src[0]);
		int dlen = sizeof(dst)/sizeof(dst[0]);
		query_arri(src, slen, dst, dlen);
	}

//2.0 查询一段数组在另个集合中出现的位置，即第几个元素之后。考虑是否为子集和集合中可能多处包含这个子集
	{
		int src[] = {1, 3, 4, 5, 6, 9, 0, 5, 8, 3, 4};
		int dst[] = {3, 4};
		int slen = sizeof(src)/sizeof(src[0]);
		int dlen = sizeof(dst)/sizeof(dst[0]);

		query_location_arri(src, slen, dst, dlen);
	}
//3.0 查询字符串是否出现在另个字符串中。
	{
		char *src = "yangzhenningxiaotiqin";
		char *dst = "tiqi";

		query_str(src, dst);
	}

//3.1 查询字符串在另个字符串中出现的位置

//4.0 查询字符串数组在另一个字符串数组中是否出现

//4.1 查询字符串数组在另一个字符串数组的第几个元素出现

	return 0;
}
