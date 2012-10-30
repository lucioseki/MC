/*
 *	Lucio Mitsuru Seki	379883
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wave_header.h"

int main(int argc, char** argv){
	HeaderType inHeader, outHeader;
	char* data;
	char* filename;
	int i, decimacao, lim;
	FILE *input, *output;

	if(argc < 2 || argc > 4){
		printf("Usage: main <input.wav> [output.wav [FatorDeDecimacao] ]\n");
		return 1;
	}

	input = fopen(argv[1], "rb"); // Abre arquivo de entrada
	if(!input){
		perror(argv[1]);
		return 1;
	}

	fread(&inHeader, sizeof(inHeader), 1, input); // Le o cabecalho
	show_header(&inHeader);
	
	if(argc > 2){ // Copia para arquivo de saida

		output = fopen(argv[2], "wb");
		if(!output){
			perror(argv[2]);
			return 1;
		}
		fwrite(&inHeader, sizeof(inHeader), 1, output); // Escreve cabecalho

		data = malloc(inHeader.Subchunk2Size);
		fread(data, inHeader.Subchunk2Size, 1, input);
		fwrite(data, inHeader.Subchunk2Size, 1, output); // Escreve chunk de dados 
		fclose(output);

		if(argc > 3){ // Decimacao
			filename = strcat(argv[3], argv[2]);
			output = fopen(filename, "wb");
			
			if(!output){
				perror(filename);
				return 1;
			}

			decimacao = atol(argv[3]);
			outHeader = *decimar_header(inHeader, decimacao); // altera o header de acordo com a taxa de amostragem dada pela decimacao
			show_header(&outHeader);
			fwrite(&outHeader, sizeof(outHeader), 1, output);
			
			lim = inHeader.Subchunk2Size / (inHeader.BlockAlign * decimacao); // quantidade de iteracoes para realizar
			for(i = 0; i < lim; i++){
				fwrite(data + inHeader.BlockAlign * inHeader.NumChannels * i * decimacao / 2, inHeader.BlockAlign, 1, output); // pega amostras pulando intervalos de decimacao e escreve no arquivo
			}

			fclose(output);
		}

	}
	fclose(input);

	return 0;
}
