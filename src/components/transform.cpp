// Copyright 2015 Google Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "transform.h"

namespace fpl {

void TransformComponent::AddFromRawData(entity::EntityRef& entity,
                                        const void* raw_data) {
  auto component_data = static_cast<const ComponentDefInstance*>(raw_data);
  assert(component_data->data_type() == ComponentDataUnion_TransformDef);
  auto transform_def = static_cast<const TransformDef*>(component_data->data());
  auto pos = transform_def->position();
  auto transform_data = AddEntity(entity);
  // TODO: Add support for scale and orientation. b/20921057
  transform_data->position = mathfu::vec3(pos->x(), pos->y(), pos->z());
}

}  // fpl

