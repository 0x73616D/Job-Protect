#include "PluginRPC.h"

#include <string>
#include <Windows.h>
#include <sampapi/CDialog.h>
#include <sampapi/CInput.h>

namespace samp = sampapi::v037r1;

template <typename T>
std::string readWithSize(RakNet::BitStream& bs) {
    T size;
    if (!bs.Read(size) || size <= 0)
        return {};
    std::string str(size, '\0');
    bs.Read(str.data(), size);
    return str;
}

template <typename T>
void writeWithSize(RakNet::BitStream& bs, std::string_view str) {
    T size = static_cast<T>(str.size());
    bs.Write(size);
    bs.Write(str.data(), size);
}

bool PluginRPC::onDialogResponse(int& id, RakNet::BitStream* bs, PacketPriority&, PacketReliability&, char&, bool&)
{
    if (id != 62) // RPC_onSendCommand
        return true;

    INT16 wDialogID;
    UINT8 bResponse;
    INT16 wListItem;
    UINT8 bTextLength;
    std::string text;

    bs->Read(wDialogID);
    bs->Read(bResponse);
    bs->Read(wListItem);
    bs->Read(bTextLength);
    text = readWithSize<unsigned char>(*bs);

    if (bResponse == 0) {
        return true;
    }

    if (bResponse == 1) {
        switch (wDialogID) {
        case 8701:
            enableCommandConfirmation = true;
            samp::RefInputBox()->Send("/dejar trabajo 1");
            enableCommandConfirmation = false;
            break;
        case 8702:
            enableCommandConfirmation = true;
            samp::RefInputBox()->Send("/dejar trabajo 2");
            enableCommandConfirmation = false;
            break;
        case 8703:
            enableCommandConfirmation = true;
            samp::RefInputBox()->Send("/dejar trabajo 3");
            enableCommandConfirmation = false;
            break;
        case 8704:
            enableCommandConfirmation = true;
            samp::RefInputBox()->Send("/dejar trabajo 4");
            enableCommandConfirmation = false;
            break;
        case 8706:
            enableCommandConfirmation = true;
            samp::RefInputBox()->Send("/dejar trabajo 6");
            enableCommandConfirmation = false;
            break;
        case 8707:
            enableCommandConfirmation = true;
            samp::RefInputBox()->Send("/dejar trabajo 7");
            enableCommandConfirmation = false;
            break;
        case 8708:
            enableCommandConfirmation = true;
            samp::RefInputBox()->Send("/dejar trabajo 8");
            enableCommandConfirmation = false;
            break;
        case 8709:
            enableCommandConfirmation = true;
            samp::RefInputBox()->Send("/dejar trabajo 9");
            enableCommandConfirmation = false;
            break;
        case 8711:
            enableCommandConfirmation = true;
            samp::RefInputBox()->Send("/dejar trabajo 11");
            enableCommandConfirmation = false;
            break;
        case 8712:
            enableCommandConfirmation = true;
            samp::RefInputBox()->Send("/dejar trabajo 12");
            enableCommandConfirmation = false;
            break;
        case 8714:
            enableCommandConfirmation = true;
            samp::RefInputBox()->Send("/dejar trabajo 14");
            enableCommandConfirmation = false;
            break;
        default:
            break;
        }
    }
    return true;
}

bool PluginRPC::onSendCommand(int& id, RakNet::BitStream* bs, PacketPriority&, PacketReliability&, char&, bool&) {
    if (id != 50) // RPC_onSendCommand
        return true;

    DWORD strlen{};
    char commandtext[144];

    bs->Read(strlen);
    bs->Read(commandtext, strlen);

    std::string commandString(commandtext, strlen);
    std::transform(commandString.begin(), commandString.end(), commandString.begin(), ::tolower);

    if (commandString.find("/dejar trabajo ") == 0) {
        std::string numStr = commandString.substr(15);
        std::istringstream iss(numStr);
        int trabajoNumero;
        if (iss >> trabajoNumero) {
            switch (trabajoNumero) {
            case 1:
                samp::RefDialog()->Show(8701, 0, "{DBED15}¡Atencion!", "{FFFFFF}Estas apunto de dejar el trabajo de {DBED15}Medico{FFFFFF} ¿estas seguro de que quieres hacer esto?", "Aceptar", "Cancelar", 1);
                break;
            case 2:
                samp::RefDialog()->Show(8702, 0, "{DBED15}¡Atencion!", "{FFFFFF}Estas apunto de dejar el trabajo de {DBED15}Taxista{FFFFFF} ¿estas seguro de que quieres hacer esto?", "Aceptar", "Cancelar", 1);
                break;
            case 3:
                samp::RefDialog()->Show(8703, 0, "{DBED15}¡Atencion!", "{FFFFFF}Estas apunto de dejar el trabajo de {DBED15}Guardaespaldas{FFFFFF} ¿estas seguro de que quieres hacer esto?", "Aceptar", "Cancelar", 1);
                break;
            case 4:
                samp::RefDialog()->Show(8704, 0, "{DBED15}¡Atencion!", "{FFFFFF}Estas apunto de dejar el trabajo de {DBED15}Camionero{FFFFFF} ¿estas seguro de que quieres hacer esto?", "Aceptar", "Cancelar", 1);
                break;
            case 6:
                samp::RefDialog()->Show(8706, 0, "{DBED15}¡Atencion!", "{FFFFFF}Estas apunto de dejar el trabajo de {DBED15}Fabricante de armas{FFFFFF} ¿estas seguro de que quieres hacer esto?", "Aceptar", "Cancelar", 1);
                break;
            case 7:
                samp::RefDialog()->Show(8707, 0, "{DBED15}¡Atencion!", "{FFFFFF}Estas apunto de dejar el trabajo de {DBED15}Mecanico{FFFFFF} ¿estas seguro de que quieres hacer esto?", "Aceptar", "Cancelar", 1);
                break;
            case 8:
                samp::RefDialog()->Show(8708, 0, "{DBED15}¡Atencion!", "{FFFFFF}Estas apunto de dejar el trabajo de {DBED15}Basurero{FFFFFF} ¿estas seguro de que quieres hacer esto?", "Aceptar", "Cancelar", 1);
                break;
            case 9:
                samp::RefDialog()->Show(8709, 0, "{DBED15}¡Atencion!", "{FFFFFF}Estas apunto de dejar el trabajo de {DBED15}Transportista{FFFFFF} ¿estas seguro de que quieres hacer esto?", "Aceptar", "Cancelar", 1);
                break;
            case 11:
                samp::RefDialog()->Show(8711, 0, "{DBED15}¡Atencion!", "{FFFFFF}Estas apunto de dejar el trabajo de {DBED15}Minero{FFFFFF} ¿estas seguro de que quieres hacer esto?", "Aceptar", "Cancelar", 1);
                break;
            case 12:
                samp::RefDialog()->Show(8712, 0, "{DBED15}¡Atencion!", "{FFFFFF}Estas apunto de dejar el trabajo de {DBED15}Pescador{FFFFFF} ¿estas seguro de que quieres hacer esto?", "Aceptar", "Cancelar", 1);
                break;
            case 14:
                samp::RefDialog()->Show(8714, 0, "{DBED15}¡Atencion!", "{FFFFFF}Estas apunto de dejar el trabajo de {DBED15}Prostitución{FFFFFF} ¿estas seguro de que quieres hacer esto?", "Aceptar", "Cancelar", 1);
                break;
            default:
                break;
            }
            if (enableCommandConfirmation == true) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    return true;
}
