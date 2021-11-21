#include <napi.h>
#include "_wrapped/TesseractWrapped.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  TesseractWrapped::Init(env, exports);

  return exports;
}

NODE_API_MODULE(tesseractnodejs, InitAll);
