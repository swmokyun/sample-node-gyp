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
    if (args.Length() != 2)
    {
        args.GetReturnValue().Set(-1);
        return;
    }

    v8::Isolate *isolate = args.GetIsolate();
    v8::HandleScope scope(isolate);
    v8::Local<v8::Context> context = args.GetIsolate()->GetCurrentContext();

    double p1 = args[0]->NumberValue(context).FromJust();
    double p2 = args[1]->NumberValue(context).FromJust();
    args.GetReturnValue().Set(p1 + p2);
}

void init(v8::Local<v8::Object> target)
{
    NODE_SET_METHOD(target, "hello", Method);
    NODE_SET_METHOD(target, "add", Method2);
}

NODE_MODULE(binding, init);