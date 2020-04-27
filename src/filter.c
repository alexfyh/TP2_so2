//
// Created by alexyh on 26/4/20.
//
#include <stdio.h>
#include <unistd.h>

#include "simple_bmp.h"

int main()
{
    sbmp_image* image;
    image = calloc(1, sizeof(sbmp_image));
    char* filename = "../src/base.bmp";
    sbmp_load_bmp(filename, image);
    printf("Tamaño del archivo = %u B\n", image->type.file_size);
    printf("Altura = %u\n", image->info.image_height);
    printf("Ancho = %u\n", image->info.image_width);
    int iteraciones = 0;
    /**
     * Modifica primeras 100 filas
     */
    for (int j = 0; j < 200; ++j)
    {
        struct _sbmp_raw_data* data = (struct _sbmp_raw_data*) image->data[j];
        for (int i = 0; i < image->info.image_width; ++i)
        {
            data->green = 255;
            data->red = 0;
            data->blue = 0;
            data++;
            iteraciones++;
        }
    }
    sbmp_save_bmp("../src/base_blue.bmp", image);
    printf("Número de iteraciones = %d\n", iteraciones);
    return 0;
}

