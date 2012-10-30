/*
 *	Lucio Mitsuru Seki	379883
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wave_header.h"

int main(int argc, char** argv){
	HeaderType *inHeader, *outHeader;
	char *data;
	char *filename;
	int i, decimacao;
	FILE *input, *output;

	if(argc < 2 || argc > 4){
		printf("Usage: main <input.wav> [output.wav [FatorDeDecimacao] ]\n");
		return 1;
	}

	// abre arquivo de entrada
	input = fopen(argv[1], "rb");
	if(!input){
		perror(argv[1]);
		return 1;
	}
	// le o cabecalho
	inHeader = malloc(sizeof(HeaderType));
	fread(inHeader, sizeof(HeaderType), 1, input);
	show_header(inHeader);
	
	// copia para arquivo de saida
	if(argc > 2){
		output = fopen(argv[2], "wb");
		if(!output){
			perror(argv[2]);
			return 1;
		}

		// escreve o cabecalho
		fwrite(inHeader, sizeof(HeaderType), 1, output);

		// copia o chunk de dados 
		data = malloc(inHeader->Subchunk2Size);
		fread(data, inHeader->Subchunk2Size, 1, input);
		fwrite(data, inHeader->Subchunk2Size, 1, output);
		fclose(output);

		// decimacao
		if(argc > 3){
			// novo arquivo
			filename = strcat(argv[3], argv[2]);
			output = fopen(filename, "wb");
			if(!output){
				perror(filename);
				return 1;
			}
	
			// cria novo header e dados de acordo com a taxa de decimacao
			decimacao = atol(argv[3]);
			decimar_header(inHeader, decimacao, output); 
			decimar_dados(data, inHeader, decimacao, output);

			fclose(output);
		}
	}
	fclose(input);

	return 0;
}
