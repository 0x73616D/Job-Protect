#include "Plugin.h"
#include <sampapi/CChat.h>
#include <RakHook/rakhook.hpp>
#include <RakNet/StringCompressor.h>
#include <memory> 

namespace samp = sampapi::v037r1;

Plugin::Plugin(HMODULE hndl) : hModule(hndl) {
    using namespace std::placeholders;
    hookCTimerUpdate.set_cb(std::bind(&Plugin::mainloop, this, _1));
    hookCTimerUpdate.install();
}
void Plugin::mainloop(const decltype(hookCTimerUpdate)& hook) {
    static bool inited = false;
    if (!inited && samp::RefChat() != nullptr && rakhook::initialize()) {
        using namespace std::placeholders;
        samp::RefChat()->AddMessage(0xFFFFFFFF, "{FF69B4}[Job Protect]{FFFFFF} Plugin Loaded — {FF69B4}0x73616D - {FFFFFF}Ty 4 your support {FF69B4}Hidend");
        StringCompressor::AddReference();
        rakhook::on_send_rpc += std::bind(&PluginRPC::onDialogResponse, &RPC, _1, _2, _3, _4, _5, _6);
        rakhook::on_send_rpc += std::bind(&PluginRPC::onSendCommand, &RPC, _1, _2, _3, _4, _5, _6);
        inited = true;
    }
    return hook.get_trampoline()();
}