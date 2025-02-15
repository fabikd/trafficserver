
/*
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

class IntConfig
{
public:
  IntConfig() = delete;
  explicit IntConfig(TSOverridableConfigKey key) : _key(key) {}

  // Implemented later in Configs.cc
  integer _get(Cript::Context *context) const;
  void _set(Cript::Context *context, integer value);

private:
  const TSOverridableConfigKey _key;
};

class FloatConfig
{
public:
  FloatConfig() = delete;
  explicit FloatConfig(TSOverridableConfigKey key) : _key(key) {}

  // Implemented later in Configs.cc
  float _get(Cript::Context *context) const;
  void _set(Cript::Context *context, float value);

private:
  const TSOverridableConfigKey _key;
};


class Proxy
{
private:
  friend class Cript::Context; // Needed to set the state

  class Config
  {
  private:
    class Body_Factory
    {
      public:
        IntConfig response_suppression_mode{TS_CONFIG_BODY_FACTORY_RESPONSE_SUPPRESSION_MODE};
    }; // End class Body_Factory

    public:
      Body_Factory body_factory;

  private:
    class Hostdb
    {
      public:
    }; // End class Hostdb

    public:
      Hostdb hostdb;

  private:
    class Http
    {
      public:
        IntConfig allow_half_open{TS_CONFIG_HTTP_ALLOW_HALF_OPEN};
        IntConfig allow_multi_range{TS_CONFIG_HTTP_ALLOW_MULTI_RANGE};
        IntConfig anonymize_remove_client_ip{TS_CONFIG_HTTP_ANONYMIZE_REMOVE_CLIENT_IP};
        IntConfig anonymize_remove_cookie{TS_CONFIG_HTTP_ANONYMIZE_REMOVE_COOKIE};
        IntConfig anonymize_remove_from{TS_CONFIG_HTTP_ANONYMIZE_REMOVE_FROM};
        IntConfig anonymize_remove_referer{TS_CONFIG_HTTP_ANONYMIZE_REMOVE_REFERER};
        IntConfig anonymize_remove_user_agent{TS_CONFIG_HTTP_ANONYMIZE_REMOVE_USER_AGENT};
        IntConfig attach_server_session_to_client{TS_CONFIG_HTTP_ATTACH_SERVER_SESSION_TO_CLIENT};
        IntConfig auth_server_session_private{TS_CONFIG_HTTP_AUTH_SERVER_SESSION_PRIVATE};
        IntConfig background_fill_active_timeout{TS_CONFIG_HTTP_BACKGROUND_FILL_ACTIVE_TIMEOUT};
        FloatConfig background_fill_completed_threshold{TS_CONFIG_HTTP_BACKGROUND_FILL_COMPLETED_THRESHOLD};
    private:
      class Cache
      {
        public:
          IntConfig cache_responses_to_cookies{TS_CONFIG_HTTP_CACHE_CACHE_RESPONSES_TO_COOKIES};
          IntConfig cache_urls_that_look_dynamic{TS_CONFIG_HTTP_CACHE_CACHE_URLS_THAT_LOOK_DYNAMIC};
          IntConfig generation{TS_CONFIG_HTTP_CACHE_GENERATION};
          IntConfig guaranteed_max_lifetime{TS_CONFIG_HTTP_CACHE_GUARANTEED_MAX_LIFETIME};
          IntConfig guaranteed_min_lifetime{TS_CONFIG_HTTP_CACHE_GUARANTEED_MIN_LIFETIME};
          FloatConfig heuristic_lm_factor{TS_CONFIG_HTTP_CACHE_HEURISTIC_LM_FACTOR};
          IntConfig heuristic_max_lifetime{TS_CONFIG_HTTP_CACHE_HEURISTIC_MAX_LIFETIME};
          IntConfig heuristic_min_lifetime{TS_CONFIG_HTTP_CACHE_HEURISTIC_MIN_LIFETIME};
          IntConfig http{TS_CONFIG_HTTP_CACHE_HTTP};
          IntConfig ignore_accept_charset_mismatch{TS_CONFIG_HTTP_CACHE_IGNORE_ACCEPT_CHARSET_MISMATCH};
          IntConfig ignore_accept_encoding_mismatch{TS_CONFIG_HTTP_CACHE_IGNORE_ACCEPT_ENCODING_MISMATCH};
          IntConfig ignore_accept_language_mismatch{TS_CONFIG_HTTP_CACHE_IGNORE_ACCEPT_LANGUAGE_MISMATCH};
          IntConfig ignore_accept_mismatch{TS_CONFIG_HTTP_CACHE_IGNORE_ACCEPT_MISMATCH};
          IntConfig ignore_authentication{TS_CONFIG_HTTP_CACHE_IGNORE_AUTHENTICATION};
          IntConfig ignore_client_cc_max_age{TS_CONFIG_HTTP_CACHE_IGNORE_CLIENT_CC_MAX_AGE};
          IntConfig ignore_client_no_cache{TS_CONFIG_HTTP_CACHE_IGNORE_CLIENT_NO_CACHE};
          IntConfig ignore_query{TS_CONFIG_HTTP_CACHE_IGNORE_QUERY};
          IntConfig ignore_server_no_cache{TS_CONFIG_HTTP_CACHE_IGNORE_SERVER_NO_CACHE};
          IntConfig ims_on_client_no_cache{TS_CONFIG_HTTP_CACHE_IMS_ON_CLIENT_NO_CACHE};
          IntConfig max_open_read_retries{TS_CONFIG_HTTP_CACHE_MAX_OPEN_READ_RETRIES};
          IntConfig max_open_write_retries{TS_CONFIG_HTTP_CACHE_MAX_OPEN_WRITE_RETRIES};
          IntConfig max_open_write_retry_timeout{TS_CONFIG_HTTP_CACHE_MAX_OPEN_WRITE_RETRY_TIMEOUT};
          IntConfig max_stale_age{TS_CONFIG_HTTP_CACHE_MAX_STALE_AGE};
          IntConfig open_read_retry_time{TS_CONFIG_HTTP_CACHE_OPEN_READ_RETRY_TIME};
          IntConfig open_write_fail_action{TS_CONFIG_HTTP_CACHE_OPEN_WRITE_FAIL_ACTION};
      private:
        class Range
        {
          public:
            IntConfig lookup{TS_CONFIG_HTTP_CACHE_RANGE_LOOKUP};
            IntConfig write{TS_CONFIG_HTTP_CACHE_RANGE_WRITE};
        }; // End class Range

        public:
          Range range;

          IntConfig required_headers{TS_CONFIG_HTTP_CACHE_REQUIRED_HEADERS};
          IntConfig when_to_revalidate{TS_CONFIG_HTTP_CACHE_WHEN_TO_REVALIDATE};
      }; // End class Cache

      public:
        Cache cache;

    private:
      class Chunking
      {
        public:
          IntConfig size{TS_CONFIG_HTTP_CHUNKING_SIZE};
      }; // End class Chunking

      public:
        Chunking chunking;

        IntConfig chunking_enabled{TS_CONFIG_HTTP_CHUNKING_ENABLED};
    private:
      class Connect
      {
      private:
        class Down
        {
          public:
            IntConfig policy{TS_CONFIG_HTTP_CONNECT_DOWN_POLICY};
        }; // End class Down

        public:
          Down down;

      }; // End class Connect

      public:
        Connect connect;

        IntConfig connect_attempts_max_retries{TS_CONFIG_HTTP_CONNECT_ATTEMPTS_MAX_RETRIES};
        IntConfig connect_attempts_max_retries_down_server{TS_CONFIG_HTTP_CONNECT_ATTEMPTS_MAX_RETRIES_DOWN_SERVER};
        IntConfig connect_attempts_rr_retries{TS_CONFIG_HTTP_CONNECT_ATTEMPTS_RR_RETRIES};
        IntConfig connect_attempts_timeout{TS_CONFIG_HTTP_CONNECT_ATTEMPTS_TIMEOUT};
        IntConfig default_buffer_size{TS_CONFIG_HTTP_DEFAULT_BUFFER_SIZE};
        IntConfig default_buffer_water_mark{TS_CONFIG_HTTP_DEFAULT_BUFFER_WATER_MARK};
        IntConfig doc_in_cache_skip_dns{TS_CONFIG_HTTP_DOC_IN_CACHE_SKIP_DNS};
    private:
      class Down_Server
      {
        public:
          IntConfig cache_time{TS_CONFIG_HTTP_DOWN_SERVER_CACHE_TIME};
      }; // End class Down_Server

      public:
        Down_Server down_server;

    private:
      class Flow_Control
      {
        public:
          IntConfig enabled{TS_CONFIG_HTTP_FLOW_CONTROL_ENABLED};
          IntConfig high_water{TS_CONFIG_HTTP_FLOW_CONTROL_HIGH_WATER_MARK};
          IntConfig low_water{TS_CONFIG_HTTP_FLOW_CONTROL_LOW_WATER_MARK};
      }; // End class Flow_Control

      public:
        Flow_Control flow_control;

    private:
      class Forward
      {
        public:
          IntConfig proxy_auth_to_parent{TS_CONFIG_HTTP_FORWARD_PROXY_AUTH_TO_PARENT};
      }; // End class Forward

      public:
        Forward forward;

        IntConfig forward_connect_method{TS_CONFIG_HTTP_FORWARD_CONNECT_METHOD};
        IntConfig insert_age_in_response{TS_CONFIG_HTTP_INSERT_AGE_IN_RESPONSE};
        IntConfig insert_client_ip{TS_CONFIG_HTTP_ANONYMIZE_INSERT_CLIENT_IP};
        IntConfig insert_request_via_str{TS_CONFIG_HTTP_INSERT_REQUEST_VIA_STR};
        IntConfig insert_response_via_str{TS_CONFIG_HTTP_INSERT_RESPONSE_VIA_STR};
        IntConfig insert_squid_x_forwarded_for{TS_CONFIG_HTTP_INSERT_SQUID_X_FORWARDED_FOR};
        IntConfig keep_alive_enabled_in{TS_CONFIG_HTTP_KEEP_ALIVE_ENABLED_IN};
        IntConfig keep_alive_enabled_out{TS_CONFIG_HTTP_KEEP_ALIVE_ENABLED_OUT};
        IntConfig keep_alive_no_activity_timeout_in{TS_CONFIG_HTTP_KEEP_ALIVE_NO_ACTIVITY_TIMEOUT_IN};
        IntConfig keep_alive_no_activity_timeout_out{TS_CONFIG_HTTP_KEEP_ALIVE_NO_ACTIVITY_TIMEOUT_OUT};
        IntConfig keep_alive_post_out{TS_CONFIG_HTTP_KEEP_ALIVE_POST_OUT};
        IntConfig max_proxy_cycles{TS_CONFIG_HTTP_MAX_PROXY_CYCLES};
        IntConfig negative_caching_enabled{TS_CONFIG_HTTP_NEGATIVE_CACHING_ENABLED};
        IntConfig negative_caching_lifetime{TS_CONFIG_HTTP_NEGATIVE_CACHING_LIFETIME};
        IntConfig negative_revalidating_enabled{TS_CONFIG_HTTP_NEGATIVE_REVALIDATING_ENABLED};
        IntConfig negative_revalidating_lifetime{TS_CONFIG_HTTP_NEGATIVE_REVALIDATING_LIFETIME};
        IntConfig no_dns_just_forward_to_parent{TS_CONFIG_HTTP_NO_DNS_JUST_FORWARD_TO_PARENT};
        IntConfig normalize_ae{TS_CONFIG_HTTP_NORMALIZE_AE};
        IntConfig number_of_redirections{TS_CONFIG_HTTP_NUMBER_OF_REDIRECTIONS};
    private:
      class Parent_Proxy
      {
        public:
          IntConfig disable_parent_markdowns{TS_CONFIG_HTTP_DISABLE_PARENT_MARKDOWNS};
          IntConfig enable_parent_timeout_markdowns{TS_CONFIG_HTTP_ENABLE_PARENT_TIMEOUT_MARKDOWNS};
          IntConfig fail_threshold{TS_CONFIG_HTTP_PARENT_PROXY_FAIL_THRESHOLD};
          IntConfig mark_down_hostdb{TS_CONFIG_PARENT_FAILURES_UPDATE_HOSTDB};
          IntConfig per_parent_connect_attempts{TS_CONFIG_HTTP_PER_PARENT_CONNECT_ATTEMPTS};
          IntConfig retry_time{TS_CONFIG_HTTP_PARENT_PROXY_RETRY_TIME};
          IntConfig total_connect_attempts{TS_CONFIG_HTTP_PARENT_PROXY_TOTAL_CONNECT_ATTEMPTS};
      }; // End class Parent_Proxy

      public:
        Parent_Proxy parent_proxy;

    private:
      class Post
      {
      private:
        class Check
        {
        private:
          class Content_Length
          {
            public:
              IntConfig enabled{TS_CONFIG_HTTP_POST_CHECK_CONTENT_LENGTH_ENABLED};
          }; // End class Content_Length

          public:
            Content_Length content_length;

        }; // End class Check

        public:
          Check check;

      }; // End class Post

      public:
        Post post;

        IntConfig proxy_protocol_out{TS_CONFIG_HTTP_PROXY_PROTOCOL_OUT};
        IntConfig redirect_use_orig_cache_key{TS_CONFIG_HTTP_REDIRECT_USE_ORIG_CACHE_KEY};
        IntConfig request_buffer_enabled{TS_CONFIG_HTTP_REQUEST_BUFFER_ENABLED};
        IntConfig request_header_max_size{TS_CONFIG_HTTP_REQUEST_HEADER_MAX_SIZE};
        IntConfig response_header_max_size{TS_CONFIG_HTTP_RESPONSE_HEADER_MAX_SIZE};
        IntConfig response_server_enabled{TS_CONFIG_HTTP_RESPONSE_SERVER_ENABLED};
        IntConfig send_http11_requests{TS_CONFIG_HTTP_SEND_HTTP11_REQUESTS};
    private:
      class Server_Session_Sharing
      {
        public:
      }; // End class Server_Session_Sharing

      public:
        Server_Session_Sharing server_session_sharing;

    private:
      class Slow
      {
      private:
        class Log
        {
          public:
            IntConfig threshold{TS_CONFIG_HTTP_SLOW_LOG_THRESHOLD};
        }; // End class Log

        public:
          Log log;

      }; // End class Slow

      public:
        Slow slow;

        IntConfig transaction_active_timeout_in{TS_CONFIG_HTTP_TRANSACTION_ACTIVE_TIMEOUT_IN};
        IntConfig transaction_active_timeout_out{TS_CONFIG_HTTP_TRANSACTION_ACTIVE_TIMEOUT_OUT};
        IntConfig transaction_no_activity_timeout_in{TS_CONFIG_HTTP_TRANSACTION_NO_ACTIVITY_TIMEOUT_IN};
        IntConfig transaction_no_activity_timeout_out{TS_CONFIG_HTTP_TRANSACTION_NO_ACTIVITY_TIMEOUT_OUT};
        IntConfig uncacheable_requests_bypass_parent{TS_CONFIG_HTTP_UNCACHEABLE_REQUESTS_BYPASS_PARENT};
    }; // End class Http

    public:
      Http http;

  private:
    class Net
    {
      public:
        IntConfig default_inactivity_timeout{TS_CONFIG_NET_DEFAULT_INACTIVITY_TIMEOUT};
        IntConfig sock_notsent_lowat{TS_CONFIG_NET_SOCK_NOTSENT_LOWAT};
        IntConfig sock_option_flag_out{TS_CONFIG_NET_SOCK_OPTION_FLAG_OUT};
        IntConfig sock_packet_mark_out{TS_CONFIG_NET_SOCK_PACKET_MARK_OUT};
        IntConfig sock_packet_tos_out{TS_CONFIG_NET_SOCK_PACKET_TOS_OUT};
        IntConfig sock_recv_buffer_size_out{TS_CONFIG_NET_SOCK_RECV_BUFFER_SIZE_OUT};
        IntConfig sock_send_buffer_size_out{TS_CONFIG_NET_SOCK_SEND_BUFFER_SIZE_OUT};
    }; // End class Net

    public:
      Net net;

  private:
    class Plugin
    {
    private:
      class Vc
      {
        public:
          IntConfig default_buffer_index{TS_CONFIG_PLUGIN_VC_DEFAULT_BUFFER_INDEX};
          IntConfig default_buffer_water_mark{TS_CONFIG_PLUGIN_VC_DEFAULT_BUFFER_WATER_MARK};
      }; // End class Vc

      public:
        Vc vc;

    }; // End class Plugin

    public:
      Plugin plugin;

    public:
      IntConfig srv_enabled{TS_CONFIG_SRV_ENABLED};
  private:
    class Ssl
    {
    private:
      class Client
      {
      private:
        class Ca
        {
        private:
          class Cert
          {
            public:
          }; // End class Cert

          public:
            Cert cert;

        }; // End class Ca

        public:
          Ca CA;

        public:
      private:
        class Cert
        {
          public:
        }; // End class Cert

        public:
          Cert cert;

      private:
        class Private_Key
        {
          public:
        }; // End class Private_Key

        public:
          Private_Key private_key;

      private:
        class Verify
        {
        private:
          class Server
          {
            public:
          }; // End class Server

          public:
            Server server;

        }; // End class Verify

        public:
          Verify verify;

      }; // End class Client

      public:
        Client client;

      public:
        IntConfig hsts_include_subdomains{TS_CONFIG_SSL_HSTS_INCLUDE_SUBDOMAINS};
        IntConfig hsts_max_age{TS_CONFIG_SSL_HSTS_MAX_AGE};
    }; // End class Ssl

    public:
      Ssl ssl;

  private:
    class Url_Remap
    {
      public:
        IntConfig pristine_host_hdr{TS_CONFIG_URL_REMAP_PRISTINE_HOST_HDR};
    }; // End class Url_Remap

    public:
      Url_Remap url_remap;

  private:
    class Websocket
    {
      public:
        IntConfig active_timeout{TS_CONFIG_WEBSOCKET_ACTIVE_TIMEOUT};
        IntConfig no_activity_timeout{TS_CONFIG_WEBSOCKET_NO_ACTIVITY_TIMEOUT};
    }; // End class Websocket

    public:
      Websocket websocket;

  }; // End class Config

  public:
    Config config;

}; // End class Proxy

