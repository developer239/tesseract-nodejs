#include <allheaders.h>

#include "Tesseract.h"

Tesseract::Tesseract() {
  tesseract = new tesseract::TessBaseAPI();

  tesseract->Init(nullptr, nullptr, tesseract::OEM_LSTM_ONLY);
}

char *Tesseract::read(const char *inputfile) {
  PIX *image = pixRead(inputfile);

  if (!image) {
    fprintf(stderr, "Cannot open input file: %s\n", inputfile);
    exit(2);
  }

  tesseract->SetImage(image);
  char *outputText = tesseract->GetUTF8Text();
  tesseract->Clear();

  return outputText;
}
