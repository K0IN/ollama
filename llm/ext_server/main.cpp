#include "ext_server.h"
// see https://pkg.go.dev/cmd/cgo#hdr-C_references_to_Go


extern "C"
{

  /*
  // err->id != 0 for failure, and err->msg contains error message
void llama_server_init(ext_server_params_t *sparams, ext_server_resp_t *err);

// Run the main loop, called once per init
void llama_server_start();
// Stop the main loop and free up resources allocated in init and start.  Init
// must be called again to reuse
void llama_server_stop();

// json_req null terminated string, memory managed by caller
// resp->id >= 0 on success (task ID)
// resp->id < 0 on error, and resp->msg contains error message
void llama_server_completion(const char *json_req, ext_server_resp_t *resp);

// Caller must call llama_server_release_task_result to free resp->json_resp
void llama_server_completion_next_result(const int task_id,
                                         ext_server_task_result_t *result);
void llama_server_completion_cancel(const int task_id, ext_server_resp_t *err);
void llama_server_release_task_result(ext_server_task_result_t *result);

// Caller must call llama_server_releaes_json_resp to free json_resp if err.id <
// 0
void llama_server_tokenize(const char *json_req, char **json_resp,
                           ext_server_resp_t *err);
void llama_server_detokenize(const char *json_req, char **json_resp,
                             ext_server_resp_t *err);
void llama_server_embedding(const char *json_req, char **json_resp,
                            ext_server_resp_t *err);
void llama_server_release_json_resp(char **json_resp);
*/

  void llama_server_init(ext_server_params_t *sparams, ext_server_resp_t *err)
  {
  }

  void llama_server_start()
  {
  }

  void llama_server_stop()
  {
  }

  void llama_server_completion(const char *json_req, ext_server_resp_t *resp)
  {
  }

  void llama_server_completion_next_result(const int task_id,
                                           ext_server_task_result_t *result)
  {
  }

  void llama_server_completion_cancel(const int task_id, ext_server_resp_t *err)
  {
  }

  void llama_server_release_task_result(ext_server_task_result_t *result)
  {
  }

  void llama_server_tokenize(const char *json_req, char **json_resp,
                             ext_server_resp_t *err)
  {
  }

  void llama_server_detokenize(const char *json_req, char **json_resp,
                               ext_server_resp_t *err)
  {
  }

  void llama_server_embedding(const char *json_req, char **json_resp,
                              ext_server_resp_t *err)
  {
  }

  void llama_server_release_json_resp(char **json_resp)
  {
  }
}
