#include "png2raw.h"
#include <png.h>
#include <assert.h>
#include <stdlib.h>

void* png2raw::open(const char* file)
{
        FILE* fp = NULL;
        size_t number = 8;
        unsigned char* header = NULL;
        size_t result;
        int is_png = -1;

        fp = fopen(file, "rb");
        assert(fp != NULL);

        //fseek(fp, 0, SEEK_END);
        //number = ftell(fp);
        //rewind(fp);

        header = (unsigned char*) malloc( sizeof(unsigned char) * number );
        result = fread(header, 1, number, fp);
        assert( result == number );

        is_png = !png_sig_cmp(header, 0, number);
        assert(is_png);

        png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
        assert(png_ptr != NULL);

        png_infop info_ptr = png_create_info_struct(png_ptr);
        assert(info_ptr != NULL);

        png_infop end_info = png_create_info_struct(png_ptr);
	assert(end_info != NULL);

	png_set_sig_bytes(png_ptr, number);
	png_init_io(png_ptr, fp);
	
	png_read_png(png_ptr, info_ptr, 0, NULL);



	if(setjmp(png_jmpbuf(png_ptr)))
	{
		assert(false);
	}
	
        fclose(fp);
        free(header);
}
