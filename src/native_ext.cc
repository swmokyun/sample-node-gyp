#include <node/v8.h>
#include <node/node.h>

using namespace node;
using namespace v8;

void Method(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope scope(isolate);
    v8::Local<v8::String> result;
    v8::MaybeLocal<v8::String> temp = String::NewFromUtf8(isolate, "Hello World");
    temp.ToLocal(&result);
    args.GetReturnValue().Set(result);
}

void Method2(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope scope(isolate);
    args.GetReturnValue().Set(12.34);
}

void init(v8::Local<v8::Object> target)
{
    NODE_SET_METHOD(target, "hello", Method);
    NODE_SET_METHOD(target, "hello2", Method2);
}

NODE_MODULE(binding, init);