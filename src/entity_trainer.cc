#include <nan.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>

#include "entity_trainer.h"

using namespace v8;
using namespace std;
using namespace mitie;


EntityTrainerInstance::EntityTrainerInstance (const vector<string>& tokens) {

}

EntityTrainerInstance::~EntityTrainerInstance() {
}

void EntityTrainerInstance::Init(v8::Local<v8::Object> exports) {
  Nan::HandleScope scope;

  // Prepare constructor template
  v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
  tpl->SetClassName(Nan::New("EntityTrainerInstance").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  // Prototype
  Nan::SetPrototypeMethod(tpl, "addEntity", AddEntity);

  constructor.Reset(tpl->GetFunction());
  exports->Set(Nan::New("EntityTrainerInstance").ToLocalChecked(), tpl->GetFunction());
}

void EntityTrainerInstance::New(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  if (info.IsConstructCall()) {
    // Invoked as constructor: `new EntityTrainerInstance(...)`
    v8::Array<v8::String> arg0(info[0]);
    EntityTrainerInstance* obj = new EntityTrainerInstance(ner_file_path);
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
  } else {
    // Invoked as plain function `EntityTrainerInstance(...)`, turn into construct call.
    const int argc = 1;
    v8::Local<v8::Value> argv[argc] = { info[0] };
    v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
    info.GetReturnValue().Set(cons->NewInstance(argc, argv));
  }
}

void EntityTrainerInstance::AddEntity(const Nan::FunctionCallbackInfo<v8::Value>& info) {
}

/*
  EntityTrainer
 */
EntityTrainer::EntityTrainer(string ner_file_path) {
  string classname;
  dlib::deserialize(ner_file_path) >> classname >> ner_;
};

EntityTrainer::~EntityTrainer() {
}

void EntityTrainer::Init(v8::Local<v8::Object> exports) {
  Nan::HandleScope scope;

  // Prepare constructor template
  v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
  tpl->SetClassName(Nan::New("EntityTrainer").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  // Prototype
  Nan::SetPrototypeMethod(tpl, "add", Add);
  Nan::SetPrototypeMethod(tpl, "train", Add);

  constructor.Reset(tpl->GetFunction());
  exports->Set(Nan::New("EntityTrainer").ToLocalChecked(), tpl->GetFunction());
}


void EntityTrainer::New(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  if (info.IsConstructCall()) {
    // Invoked as constructor: `new EntityTrainer(...)`
    v8::String::Utf8Value arg0(info[0]->ToString());
    string ner_file_path = std::string(*arg0);
    EntityTrainer* obj = new EntityTrainer(ner_file_path);
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
  } else {
    // Invoked as plain function `EntityTrainer(...)`, turn into construct call.
    const int argc = 1;
    v8::Local<v8::Value> argv[argc] = { info[0] };
    v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
    info.GetReturnValue().Set(cons->NewInstance(argc, argv));
  }
}

void EntityTrainer::Add(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  EntityTrainer* obj = ObjectWrap::Unwrap<EntityTrainer>(info.Holder());

  v8::String::Utf8Value arg0(info[0]);
  const std::string data = std::string(*arg0);

  // instance
  obj->ner_.add()


}
