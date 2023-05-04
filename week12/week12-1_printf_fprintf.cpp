///要開檔案的指標 fopen()
#include <stdio.h>
int main()
{///檔案指標 fout = fopen("檔名", "模式");///w:write
    FILE * fout = fopen("file.txt", "w");
    printf("Hello World\n");
    fprintf(fout, "Hello World在檔案裡\n");
}
