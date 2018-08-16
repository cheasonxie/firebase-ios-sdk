/*
 * Copyright 2018 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FIRESTORE_CORE_SRC_FIREBASE_FIRESTORE_REMOTE_GRPC_OPERATION_H
#define FIRESTORE_CORE_SRC_FIREBASE_FIRESTORE_REMOTE_GRPC_OPERATION_H

#include <utility>

#include <grpcpp/support/byte_buffer.h>

namespace firebase {
namespace firestore {
namespace remote {

/* Interface for an operation submitted to GRPC completion queue. */
class GrpcOperation {
 public:
  virtual ~GrpcOperation() {
  }

  // The operation is expected to be put on the completion queue once this
  // function finishes.
  virtual void Execute() = 0;
  // Expected to be called once the operation is retrieved from the completion
  // queue. If `ok` is false, the operation has failed, and the GRPC call is
  // unrepairably broken.
  virtual void Complete(bool ok) = 0;
};

}  // namespace remote
}  // namespace firestore
}  // namespace firebase

#endif  // FIRESTORE_CORE_SRC_FIREBASE_FIRESTORE_REMOTE_GRPC_OPERATION_H
