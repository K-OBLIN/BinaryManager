# BinaryManager
C++ Binary Reader and Write (BinaryManager) Wrapper

```cpp
#include "BinaryManager.hpp"
#include <iostream>

int main() {
    BinaryReader BR("./config.dat");

    // Control Keys
    std::uint8_t CtrlKeys[18] { 0x00 };
    for (auto i = 0; i < sizeof(CtrlKeys) / sizeof(CtrlKeys[0]); ++i) {
        CtrlKeys[i] = BR.ReadByte();
    }

    //////////////////////
    // Read
    /////////////////////

    // Mouse Sensitivity
    std::uint8_t MouseSensitivity { BR.ReadByte() };

    // FullScreen Flag
    bool FullScreenFlag { BR.ReadBoolean() };

    // Sound Flag
    bool SoundFlag { BR.ReadBoolean() };

    // Blood Flag
    bool BloodFlag { BR.ReadBoolean() };

    // Brightness
    std::uint8_t Brightness { BR.ReadByte() };

    // InvertMouse Flag
    bool InvertMouseFlag { BR.ReadBoolean() };

    // FrameSkip Flag
    bool FrameSkipFlag { BR.ReadBoolean() };

    // Another Gunsight Flag
    bool AnotherGunsightFlag { BR.ReadBoolean() };

    // PlayerName
    // std::string PlayerName { BR.ReadString() };
    auto vec = BR.ReadChars(21);
    std::string PlayerName(vec.begin(), vec.end());


    //////////////////////
    // Show
    /////////////////////

    // Control Keys
    for (auto i = 0; i < sizeof(CtrlKeys) / sizeof(CtrlKeys[i]); ++i) {
        std::cout << std::showbase << std::hex << CtrlKeys[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "Mouse Sensitivity " << MouseSensitivity << "\n\n";
    std::cout << "FullScreen Flag : " << std::boolalpha << FullScreenFlag << "\n\n";
    std::cout << "Sound Flag : " << std::boolalpha << SoundFlag << "\n\n";
    std::cout << "Blood Flag : " << std::boolalpha << BloodFlag << "\n\n";
    std::cout << "Brightness : " << Brightness << "\n\n";
    std::cout << "InvertMouse Flag : " << std::boolalpha << InvertMouseFlag << "\n\n";
    std::cout << "FrameSkip Flag : " << std::boolalpha << FrameSkipFlag << "\n\n";
    std::cout << "AnotherGunsight Flag : " << std::boolalpha << AnotherGunsightFlag << "\n\n";
    std::cout << "PlayerName : " << PlayerName << "\n\n";
    

    //////////////////////
    // Write
    /////////////////////

    BinaryWriter BW("./config2.dat");

    // All
    // BW.Write(BR.GetBuffer());

    // Control Keys
    for (auto i = 0; i < sizeof(CtrlKeys) / sizeof(CtrlKeys[0]); ++i) {
        BW.Write(CtrlKeys[i]);
    }

    BW.Write(MouseSensitivity);
    BW.Write(FullScreenFlag);
    BW.Write(SoundFlag);
    BW.Write(BloodFlag);
    BW.Write(Brightness);
    BW.Write(InvertMouseFlag);
    BW.Write(FrameSkipFlag);
    BW.Write(AnotherGunsightFlag);
    BW.Write(PlayerName);

    return EXIT_SUCCESS;
}
```
