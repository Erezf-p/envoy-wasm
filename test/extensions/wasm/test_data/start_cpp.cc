// NOLINT(namespace-envoy)
#include <string>

#include "proxy_wasm_intrinsics.h"

// Required Proxy-Wasm ABI version.
extern "C" PROXY_WASM_KEEPALIVE void proxy_abi_version_0_1_0() {}

extern "C" PROXY_WASM_KEEPALIVE uint32_t proxy_on_vm_start(uint32_t, uint32_t) {
  logDebug("onStart");
  return 1;
}

extern "C" PROXY_WASM_KEEPALIVE uint32_t proxy_on_configure(uint32_t, uint32_t configuration_size) {
  // Fail if we are provided a non-empty configuration.
  return configuration_size ? 0 /* failure */ : 1 /* success */;
}
