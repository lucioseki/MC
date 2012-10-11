#ifndef WAVE_HEADER_H
#define WAVE_HEADER_H

// long = 4 bytes
// short = 2 bytes

typedef struct HeaderType{
	long ChunkID; // RIFF (Resource Interchange File Format) = 0x52494646
	long ChunkSize; // 36 + SubChunk2Size
	long Format; // "WAVE" = 0x57415645
	long Subchunk1ID; // "fmt " (Format Chunk) = 0x666d7420
	long Subchunk1Size; // PCM = 16

	unsigned short int AudioFormat; // PCM = 1, compressao != 1
	unsigned short int NumChannels; // 1 = mono, 2 = stereo
	long SampleRate; // frequencia
	long ByteRate; // SampleRate * NumChannels * BitsPerSample/8
	unsigned short int BlockAlign; // NumChannels * BitsPerSample/8
	unsigned short int BitsPerSample;

	long Subchunk2ID; // "data" (Data Chunk) = 0x64617461
	long Subchunk2Size; // NumSamples * NumChannels * BitsPerSample/8
}HeaderType;

typedef struct WaveData{
	unsigned int Frequency, SoundLength;
	short int * Sample;
}WaveData;

void show_header(HeaderType*);
#endif
