#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
        int size,i,j;
        scanf("%d", &size);

        for (i = 0; i < size; i++) {
                char table[26];
                char str[100];
		int tmp;
                scanf("%s", str);
                for (j = 0; j < 26; j++) {
                        table[j] = '\0';
                }

                for (j = 0; j < strlen(str); j++) {
                        tmp = str[j];
			printf("tmp: %d   tmp - 'a': %d   str[j: %c\n", tmp, tmp-'a', str[j] );
			table[tmp - 'a'] = str[j];
                }

                for (j = 0; j < 26; j++) {
                        if (table[j] != '\0') {
                                printf("%c  ", table[j]);
                        }
                }

                printf("\n");
        }
}

