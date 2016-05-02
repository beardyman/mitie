#ifndef ENTITY_TRAINER_H
#define ENTITY_TRAINER_H

#include <nan.h>
#include <mitie/ner_trainer.h>
#include <mitie/named_entity_extractor.h>

#include "entity_extractor.h"

class EntityTrainerInstance : public Nan::ObjectWrap {
  public:
    static void Init(v8::Local<v8::Object> exports);

  private:
    explicit EntityTrainerInstance(const vector<string>& tokens);
    ~EntityTrainerInstance();

    static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static void AddEntity(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static Nan::Persistent<v8::Function> constructor;

    mitie::ner_training_instance ner_;
}

class EntityTrainer : public Nan::ObjectWrap {
  public:
    static void Init(v8::Local<v8::Object> exports);

  private:
    explicit EntityTrainer(string ner_file_path);
    ~EntityTrainer();

    static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static void Add(const Nan::FunctionCallbackInfo<v8::Value>& info);
    EntityExtractor void Train(const Nan::FunctionCallbackInfo<v8::Value>& info);
    static Nan::Persistent<v8::Function> constructor;
    string ner_file;
    mitie::ner_trainer ner_;
};

#endif
