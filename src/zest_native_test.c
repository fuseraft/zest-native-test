/* The native half of fuseraft/zest-native-test: a few functions zest's end-to-end tests call. */
#include <string.h>
#include "kiwi_ext.h"

static const KiwiApi* api;

static KiwiValue add(KiwiCtx* ctx, int argc, const KiwiValue* argv) {
    (void)argc;
    return api->new_int(ctx, api->to_int(ctx, argv[0]) + api->to_int(ctx, argv[1]));
}

static KiwiValue mul(KiwiCtx* ctx, int argc, const KiwiValue* argv) {
    (void)argc;
    return api->new_int(ctx, api->to_int(ctx, argv[0]) * api->to_int(ctx, argv[1]));
}

/* The platform the binary was built for, so a test can tell which one was loaded. */
static KiwiValue platform(KiwiCtx* ctx, int argc, const KiwiValue* argv) {
    (void)argc; (void)argv;
    return api->new_string(ctx, ZNT_RID, strlen(ZNT_RID));
}

KIWI_EXPORT int kiwi_ext_init(const KiwiApi* host, KiwiCtx* ctx) {
    if (host->abi_version < KIWI_ABI_VERSION) return 1;
    api = host;
    api->define(ctx, "add", add, 2);
    api->define(ctx, "mul", mul, 2);
    api->define(ctx, "platform", platform, 0);
    return 0;
}
