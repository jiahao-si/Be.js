
#include "util.h"

void Be::Util::Log(const char* str) { write(STDOUT_FILENO, str, strlen(str)); }

Local<String> Be::Util::newStringToLcal(Isolate* isolate, const char* str,
                                        NewStringType type) {
  return String::NewFromUtf8(isolate, str, type, strlen(str)).ToLocalChecked();
}

// 设置对象的属性，属性为函数
void Be::Util::setMethod(Isolate* isolate, Local<ObjectTemplate> recv,
                         const char* name, FunctionCallback callback) {
  recv->Set(String::NewFromUtf8(isolate, name, NewStringType::kNormal)
                .ToLocalChecked(),
            FunctionTemplate::New(isolate, callback));
}

// 设置对象模板的属性，属性为非函数
void Be::Util::setObjectTemplateValue(Isolate* isolate,
                                      Local<ObjectTemplate> recv,
                                      const char* name,
                                      // TEMPLATE OR PRIVATE
                                      Local<Data> value) {
  recv->Set(String::NewFromUtf8(isolate, name, NewStringType::kNormal)
                .ToLocalChecked(),
            value);
}

// 设置对象的属性，属性为非函数
void Be::Util::setObjectValue(Isolate* isolate, Local<Object> recv,
                              const char* name, Local<Value> value) {
  recv->Set(isolate->GetCurrentContext(),
            String::NewFromUtf8(isolate, name, NewStringType::kNormal)
                .ToLocalChecked(),
            value);
}
