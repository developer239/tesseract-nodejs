#ifndef __TESSERACT_H__
#define __TESSERACT_H__

#include <tesseract/baseapi.h>

class Tesseract {
public:
  Tesseract();

  char *read(const char *inputfile);

private:
  tesseract::TessBaseAPI *tesseract;
};

#endif
