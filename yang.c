#include <stdio.h>
#include <stdlib.h>

static void query_arri(int *src, int slen, int *dst, int dlen)
{
	int *psrc = src, *pdst = dst;	
	int i = 0, j = 0;

	for (i = 0; (slen-i+1) >= dlen; i++) {
		for (j = 0; j < dlen; j++) {
			if ( *(psrc + i +j) != dst[j] ) {
				break;
			}
		}	
		if (--j == dlen) {
			break;
		}
	}
	if (j == dlen) {
		printf("have find\n");
		exit(0);
	} else {
		printf("not find\n");
		exit(-1);
	}
}

int main()
{
	//1.0 查询一段数组是否在另一个数组中连续排列
	{
		int src[] = {1, 3, 4, 5, 6, 9, 0, 5, 8, 3, 4};
		int dst[] = {5, 6, 9};
		int slen = sizeof(src)/sizeof(src[0]);
		int dlen = sizeof(dst)/sizeof(dst[0]);
		query_arri(src, slen, dst, dlen);
	}
	return 0;
}
