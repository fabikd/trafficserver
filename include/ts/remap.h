/** @file

  A brief file description

  @section license License

  Licensed to the Apache Software Foundation (ASF) under one
  or more contributor license agreements.  See the NOTICE file
  distributed with this work for additional information
  regarding copyright ownership.  The ASF licenses this file
  to you under the Apache License, Version 2.0 (the
  "License"); you may not use this file except in compliance
  with the License.  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
 */

#pragma once

namespace tsapi
{
namespace c
{

#define TSREMAP_VMAJOR  3 /* major version number */
#define TSREMAP_VMINOR  0 /* minor version number */
#define TSREMAP_VERSION ((TSREMAP_VMAJOR << 16) | TSREMAP_VMINOR)

  struct TSRemapInterface {
    unsigned long size;            /* in: sizeof(struct _tsremap_api_info) */
    unsigned long tsremap_version; /* in: TS supported version ((major << 16) | minor) */
    TSRemapPluginInfo plugin_info; /* in: Pointer to the internal RemapPluginInst */
  };

  struct TSRemapRequestInfo {
    /* Important: You should *not* release these buf pointers or TSMLocs from your plugin! */

    /* these URL mloc's are read only, use normal ts/ts.h APIs for accessing  */
    TSMLoc mapFromUrl;
    TSMLoc mapToUrl;

    /* the request URL mloc and buffer pointers are read-write. You can read and modify the
     requestUrl using normal ts/ts.h APIs, which is how you change the destination URL. */
    TSMLoc requestUrl;

    /* requestBufp and requestHdrp are the equivalent of calling TSHttpTxnClientReqGet(). */
    TSMBuffer requestBufp;
    TSMLoc requestHdrp;

    /* 0 - don't redirect, 1 - use the (new)request URL as a redirect */
    int redirect;
  };

  /* This is the type returned by the TSRemapDoRemap() callback */
  enum TSRemapStatus {
    TSREMAP_NO_REMAP       = 0, /* No remapping was done, continue with next in chain */
    TSREMAP_DID_REMAP      = 1, /* Remapping was done, continue with next in chain */
    TSREMAP_NO_REMAP_STOP  = 2, /* No remapping was done, and stop plugin chain evaluation */
    TSREMAP_DID_REMAP_STOP = 3, /* Remapping was done, but stop plugin chain evaluation */

    /* In the future, the following error codes can also be used:
       -400 to -499
       -500 to -599
       ....
       This would allow a plugin to generate an error page. Right now,
       setting the return code to any negative number is equivalent to TSREMAP_NO_REMAP */
    TSREMAP_ERROR = -1, /* Some error, that should generate an error page */
  };

  /* Status code passed to the plugin by TSRemapPostConfigReload() signaling
   * (1) if the configuration reload was successful and
   * (2) if (1) is successful show if the plugin was part of the new configuration */
  enum TSRemapReloadStatus {
    TSREMAP_CONFIG_RELOAD_FAILURE = 0, /* notify the plugin that configuration parsing failed */
    TSREMAP_CONFIG_RELOAD_SUCCESS_PLUGIN_USED =
      1, /* configuration parsing succeeded and plugin was used by the new configuration */
    TSREMAP_CONFIG_RELOAD_SUCCESS_PLUGIN_UNUSED =
      2, /* configuration parsing succeeded but plugin was NOT used by the new configuration */
  };

} // end namespace c
} // end namespace tsapi

using namespace ::tsapi::c;

/* ----------------------------------------------------------------------------------
   These are the entry points a plugin can implement. Note that TSRemapInit() and
   TSRemapDoRemap() are both required.  (These functions are called from TS using dlsym(),
   so they must be undecorated / extern "C".)
   ----------------------------------------------------------------------------------
*/

/* Plugin initialization - called first.
   Mandatory interface function.
   Return: TS_SUCCESS
           TS_ERROR - error, errbuf can include error message from plugin
*/
extern "C" TSReturnCode TSRemapInit(TSRemapInterface *api_info, char *errbuf, int errbuf_size);

/* This gets called every time before remap.config is reloaded. This is complementary
   to TSRemapInit() which gets called when the plugin is first loaded.
   It is guaranteed to be called before TSRemapInit() and TSRemapNewInstance().
   It cannot fail, or cause reload to stop here, it's merely a notification.
   Optional function.
   Params: none
   Return: none
*/
extern "C" void TSRemapPreConfigReload(void);

/* This gets called every time afterremap.config is reloaded. This is complementary
   to TSRemapInit() which gets called when the plugin is first loaded.
   It is guaranteed to be called after TSRemapInit() and TSRemapNewInstance().
   It cannot fail, or cause reload to stop here, it's merely a notification that
   the (re)load is done and provide a status of its success or failure..
   Optional function.
   Params: reloadStatus - TS_SUCCESS - (re)load was successful,
                          TS_ERROR - (re)load failed.
   Return: none
*/
extern "C" void TSRemapPostConfigReload(TSRemapReloadStatus reloadStatus);

/* Remap new request
   Mandatory interface function.
   Remap API plugin can/should use SDK API function calls inside this function!
   return: TSREMAP_NO_REMAP - No remapping was done, continue with next in chain
           TSREMAP_DID_REMAP - Remapping was done, continue with next in chain
           TSREMAP_NO_REMAP_STOP - No remapping was done, and stop plugin chain evaluation
           TSREMAP_DID_REMAP_STOP -  Remapping was done, but stop plugin chain evaluation
*/
extern "C" TSRemapStatus TSRemapDoRemap(void *ih, TSHttpTxn rh, TSRemapRequestInfo *rri);

/* Plugin shutdown, called when plugin is unloaded.
   Optional function. */
extern "C" void TSRemapDone(void);

/* Plugin new instance. Create new plugin processing entry for unique remap record.
   First two arguments in argv vector are - fromURL and toURL from remap record.
   Please keep in mind that fromURL and toURL will be converted to canonical view.
   Return: TS_SUCCESS
           TS_ERROR - instance creation error
*/
extern "C" TSReturnCode TSRemapNewInstance(int argc, char *argv[], void **ih, char *errbuf, int errbuf_size);
extern "C" void TSRemapDeleteInstance(void *);

/* Check response code from Origin Server
   os_response_type -> TSServerState
   Remap API plugin can use InkAPI function calls inside TSRemapDoRemap()
   Return: none
*/
extern "C" void TSRemapOSResponse(void *ih, TSHttpTxn rh, int os_response_type);
