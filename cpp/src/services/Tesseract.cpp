#include <allheaders.h>

#include "Tesseract.h"

Tesseract::Tesseract() {
  tesseract = new tesseract::TessBaseAPI();
}

char *Tesseract::read(const char *inputfile) {
  PIX *image = pixRead(inputfile);

  if (!image) {
    fprintf(stderr, "Cannot open input file: %s\n", inputfile);
    exit(2);
  }

  // This can be done in constructor and "End" can be replaced by "Clear"
  tesseract->Init(nullptr, nullptr, tesseract::OEM_LSTM_ONLY);

  tesseract->SetImage(image);
  char *outputText = tesseract->GetUTF8Text();
  tesseract->End();

  return outputText;
}
