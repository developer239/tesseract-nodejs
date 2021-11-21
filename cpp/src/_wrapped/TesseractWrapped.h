#ifndef __KEYBOARDWRAPPED_H__
#define __KEYBOARDWRAPPED_H__

#include <napi.h>
#include "../services/Tesseract.h"

class TesseractWrapped : public Napi::ObjectWrap<TesseractWrapped> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  explicit TesseractWrapped(const Napi::CallbackInfo &info);

private:
  static Napi::FunctionReference constructor;

  Napi::Value read(const Napi::CallbackInfo &info);

  Tesseract *_actualClass_;
};

#endif
