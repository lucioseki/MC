#include <stdio.h>
#include <string.h>
#include "wave_header.h"

int main(int argc, char** argv){
	HeaderType header;

	if(argc != 2){
		printf("Usage: main <filename.wav>\n");
		return 1;
	}

	FILE *fp = fopen(argv[1], "rb");
	fread(&header, sizeof(header), 1, fp);
	fclose(fp);

	show_header(&header);

	return 0;
}
