#pragma once

#include <RakNet/BitStream.h>
#include <RakHook/rakhook.hpp>

class PluginRPC {
public:
    bool onDialogResponse(int& id, RakNet::BitStream* bs, PacketPriority&, PacketReliability&, char&, bool&);
    bool onSendCommand(int& id, RakNet::BitStream* bs, PacketPriority&, PacketReliability&, char&, bool&);
    bool enableCommandConfirmation{false};
};