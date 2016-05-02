#include <nan.h>
#include "entity_extractor.h"
#include "entity_trainer.h"
#include "relation_extractor.h"

void InitAll(v8::Local<v8::Object> exports) {
  EntityExtractor::Init(exports);
  EntityTrainer::Init(exports);
  RelationExtractor::Init(exports);
}

NODE_MODULE(mitie, InitAll)
