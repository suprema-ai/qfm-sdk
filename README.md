# QFM-SDK
## Introduction
- QFM SDK (Q-Face Module Software Development Kit) is a set of tools and libraries for developing applications for Q-Face modules manufactured by Suprema AI Inc.

## Release Notes
- https://github.com/suprema-ai/qfm-sdk/releases

## Contents of the SDK
```
.
├── README.md
├── Suprema Q-Face SDK Licensing Agreement.md
├── doc
│   ├── html (API Reference based on Doxygen)
│   └── QFM_SDK_Manual_v0.2.0.pdf
└── linux
    ├── demo
    │   ├── arm
    │   │   └── release
    │   │       ├── Q-Face_demo
    │   │       └── libQFM_SDK.so
    │   ├── arm64
    │   │   └── release
    │   │       ├── Q-Face_demo
    │   │       └── libQFM_SDK.so
    │   └── x86_64
    │       └── release
    │           ├── Q-Face_demo
    │           └── libQFM_SDK.so
    ├── include
    │   ├── QF_API.h
    │   ├── QF_Command.h
    │   ├── QF_Def.h
    │   ├── QF_Delete.h
    │   ├── QF_Enroll.h
    │   ├── QF_Error.h
    │   ├── QF_Identify.h
    │   ├── QF_Image.h
    │   ├── QF_Key.h
    │   ├── QF_Misc.h
    │   ├── QF_Module.h
    │   ├── QF_Packet.h
    │   ├── QF_Serial.h
    │   ├── QF_Socket.h
    │   ├── QF_SysParameter.h
    │   ├── QF_Template.h
    │   ├── QF_Upgrade.h
    |   ├── QF_UserFeedback.h
    │   ├── QF_Verify.h
    │   ├── QF_Version.h
    └── lib
        ├── arm
        │   └── release
        │       ├── libQFM_SDK.a
        │       └── libQFM_SDK.so
        ├── arm64
        │   └── release
        │       ├── libQFM_SDK.a
        │       └── libQFM_SDK.so
        └── x86_64
            └── release
                ├── libQFM_SDK.a
                └── libQFM_SDK.so

```
## Description of Files
- `libQFM_SDK.a` : static library file
- `libQFM_SDK.so` : dynamic library file

## Description of architecture
- `arm` : armv7
- `arm64` : armv8
- `x86_64` : x86_64 (amd64 or intel64)
