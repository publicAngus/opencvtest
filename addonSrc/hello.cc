#include <node.h>
#include <iostream>
#include <string>
#include "./src/ns_test/Hodor.hpp"

namespace demo {
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Function;
using v8::Number;
using v8::FunctionTemplate;
using namespace std;

void Method(const FunctionCallbackInfo<Value>& args){

    int arr[2]{8,19};
	std::string str= "";
	for(int i : arr){
		str+= std::to_string(i);
	}

	str = "Hodor is of age : ";
	ns_test::Hodor hdr = ns_test::Hodor(1985);
	str += std::to_string(hdr.GetAge());

	string test;
	//cin >> test;

	str += test;
   
    //str = args[0]->ToString();
	//std::cout << str << "sldjfls" << std::endl;

	Isolate* isolate = args.GetIsolate();
	args.GetReturnValue().Set(String::NewFromUtf8(isolate, str.c_str()));
}

void ReturnObjectVal(const FunctionCallbackInfo<Value>& args){
	Isolate* isolate = args.GetIsolate();
	Local<Object> obj = Object::New(isolate);
    
	obj->Set(String::NewFromUtf8(isolate,"im obj"),args[0]->ToString());
	args.GetReturnValue().Set(obj);

}

void RunJsCallback(const FunctionCallbackInfo<Value>& args){
	Isolate* isolate = args.GetIsolate();
	Local<Function> cb = Local<Function>::Cast(args[0]);
	const unsigned int ind =2;
	Local<Value> argv[ind] = {String::NewFromUtf8(isolate,"arg1"),Number::New(isolate,100)};
	cb->Call(Null(isolate),ind,argv);
}

void FunctionReturn(const FunctionCallbackInfo<Value>& args){
	std::cout<<"function return called" << std::endl;
	Isolate* isolate = args.GetIsolate();
	args.GetReturnValue().Set(9001);
}

void ReturnFunctionToJs(const FunctionCallbackInfo<Value>& args){
	Isolate* isolate = args.GetIsolate();
	Local<FunctionTemplate> funcTmpl= FunctionTemplate::New(isolate,FunctionReturn);
	Local<Function> func = funcTmpl->GetFunction();  
	args.GetReturnValue().Set(func);
}


void init(Local<Object> exports){
	NODE_SET_METHOD(exports,"hello",Method);
	NODE_SET_METHOD(exports,"getObj",ReturnObjectVal);
	NODE_SET_METHOD(exports,"callmeBack",RunJsCallback);
	NODE_SET_METHOD(exports,"getJsFunc",ReturnFunctionToJs);
}

NODE_MODULE(addon,init)

}
