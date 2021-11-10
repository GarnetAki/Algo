#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char tag[3];
    char title[30];
    char artist[30];
    char album[30];
    char year[4];
    char comment[30];
    unsigned char genre;
} mp3Info;

int main(int argc, char *argv[])
{
    FILE *file;
    file = fopen("Pf-soskuchilsya.mp3", "rb");

    mp3Info tag_in;

    if (fseek(file, 0 * sizeof(mp3Info), SEEK_SET) == -1)
    {
        fprintf(stderr, "Not able to fseek");
        return EXIT_FAILURE;
    }

    /* Read the first name "tag" 
    if ( != 1)
    {
        printf("Could not read the tag\n");
        exit(0);
    }*/
    fread(&tag_in, sizeof(mp3Info), 1, file);
    /* Compare memory areas for verification */
    memcmp(tag_in.tag, "TAG", 3);
    //if () == 0)
    //{
        /* Verify that names are where as we expect */
        printf("Title: %.30s\n", tag_in.title);
        printf("Artist: %.30s\n", tag_in.artist);
        printf("Album: %.30s\n", tag_in.album);
        printf("Year: %.4s\n", tag_in.year);

        if (tag_in.comment[28] == '\0')

        {
            printf("Comment: %.28s\n", tag_in.comment);
            printf("Track: %d\n", tag_in.comment[29]);
        }

        else
        {
            printf("Comment: %.30s\n", tag_in.comment);
        }
        printf("Genre: %d\n", tag_in.genre);
    //}

    /*else
    {
        fprintf(stderr, "The program has failed to get the Tags\n");
        return EXIT_FAILURE;
    }*/

    fclose(file);
    return 0;
}