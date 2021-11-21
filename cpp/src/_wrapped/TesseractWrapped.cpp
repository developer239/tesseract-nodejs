#include "TesseractWrapped.h"

Napi::FunctionReference TesseractWrapped::constructor;

Napi::Object TesseractWrapped::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Tesseract", {
    InstanceMethod("read", &TesseractWrapped::read),
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Tesseract", func);
  return exports;
}

TesseractWrapped::TesseractWrapped(const Napi::CallbackInfo &info) : Napi::ObjectWrap<TesseractWrapped>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->_actualClass_ = new Tesseract();
}

Napi::Value TesseractWrapped::read(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() != 1) {
    Napi::TypeError::New(env, "Argument expected.").ThrowAsJavaScriptException();
  }

  if (info.Length() != 1 || !info[0].IsString()) {
    Napi::TypeError::New(env, "Argument is not a string.").ThrowAsJavaScriptException();
  }

  std::string inputFile = info[0].As<Napi::String>().Utf8Value();
  const char *inputFileChar = inputFile.c_str();

  char *outputText = this->_actualClass_->read(inputFileChar);
  Napi::String result = Napi::String::New(env, std::string(outputText));

  return result;
}
