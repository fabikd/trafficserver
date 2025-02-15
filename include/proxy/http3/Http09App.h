/** @file
 *
 *  A brief file description
 *
 *  @section license License
 *
 *  Licensed to the Apache Software Foundation (ASF) under one
 *  or more contributor license agreements.  See the NOTICE file
 *  distributed with this work for additional information
 *  regarding copyright ownership.  The ASF licenses this file
 *  to you under the Apache License, Version 2.0 (the
 *  "License"); you may not use this file except in compliance
 *  with the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#pragma once

#include "proxy/IPAllow.h"

#include "proxy/http/HttpSessionAccept.h"

#include "iocore/net/quic/QUICApplication.h"
#include "iocore/net/quic/QUICStreamVCAdapter.h"

class Http09Session;

/**
 * @brief A simple multi-streamed application.
 * @detail Response to simple HTTP/0.9 GETs
 * This will be removed when HTTP/0.9 over QUIC support is dropped
 *
 */
class Http09App : public QUICApplication
{
public:
  Http09App(NetVConnection *client_vc, QUICConnection *qc, IpAllow::ACL &&session_acl, const HttpSessionAccept::Options &options);
  ~Http09App();

  void on_new_stream(QUICStream &stream) override;

  int main_event_handler(int event, Event *data);

private:
  Http09Session *_ssn = nullptr;
  std::unordered_map<QUICStreamId, QUICStreamVCAdapter::IOInfo> _streams;
};
