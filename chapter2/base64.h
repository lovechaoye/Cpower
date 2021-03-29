#if !defined(_BASE64_)
#define _BASE64_
struct unit{
	char placeholder:2;
	char real:6; 
};
// base64 use low 6 bit to interprete a character,so 2^6 = 64,so all can have a map.
#define ENCODESIZE(size) (((size)*8)%6 == 0 ? ((size)*8)/6: ((size*8))/6 + 1)
#define DECODESIZE(size) ({ \
				int ret; \
				ret = 6*(size) % 8 == 0 ? 6*(size) / 8 : 6 * ((size) -1) / 8; \
				ret; \
		})
#undef DECODESIZE
#define DECODESIZE(size) (size * 6 / 8)
#define BITPOSITION(bit) ((bit)/8)
#define MASK(i,j) ((~(0xff00 >> (8 - (i))))&(0xff00 >> (8 -(j))))
int encode(const char * msg,int msgsz,char * new,int newsz);
int decode(const char * cypher,int cyphersz,char * plain,int plainsz);





#endif
