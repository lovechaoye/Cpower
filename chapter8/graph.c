#define VIDEO_BASE 0xB8000
#define PORT 0xB0000000
unsigned int volatile * const port = (unsigned int *)PORT;
int main(void){
	int *video = (int*)VIDEO_BASE;
	*video = 'A';
	return 0;

}
