#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/utility.hpp>


using namespace cv;
using namespace std;

#define CORPUS_NAME "/tmp/deadbeef"
#define DEST_NAME "/tmp/goodbeef"

// Read and Write a PNG file specified with const name
void pngReadWrite(void);
void write_to_testcase(const uint8_t *mem, size_t len);

void pngReadWrite() 
{
    Mat img;
    img = imread(CORPUS_NAME);
    if (img.empty()) {
        return;
    }

    imwrite(DEST_NAME, img); 
    remove(DEST_NAME);
}

void write_to_testcase(const uint8_t * mem, size_t len) 
{
    int fd = open(CORPUS_NAME, O_WRONLY | O_CREAT | O_EXCL, 0600);

    if (fd < 0) {
        cerr << "Unable to create " <<  CORPUS_NAME << "\n";
        return;
    }

    int32_t wlen = write(fd, mem, len);
    if (wlen != len) {
        cerr << "Cannot write to file!\n";
        return;
    }

    close(fd);
}

int main(int argc, char* argv[]) 
{
    Mat img;
    img = imread(argv[1]);
    if (img.empty()) {
        return 0;
    }

    return 0;
}
