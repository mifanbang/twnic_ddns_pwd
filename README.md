# twnic\_ddns\_pwd
TWNIC動態DNS傳輸協定之密碼解密工具組 - Password decryption toolkit for TWNIC dynamic DNS protocol


## To Non-Chinese Speakers
The target users of this software are assumed to be speakers of Chinese languages. Thus this document is written mainly in Mandarin. If any non-speaker would like to know more details, please submit an issue to the project page.


## 免責聲明 Disclaimers

這套軟體的發佈並不附帶作者的任何擔保或保證；並且按照使用者的目的或使用方式，使用這套軟體將有可能導致觸犯國內法或國際法。作者不會對任何使用者的行為負責，請謹慎評估後再自行負責使用。

In addition to the lack of warranty as this software is distributed, the use of this software may lead to violation of domestic and/or international laws depending on the purpose and action taken. Please be aware of that you are at your own risk.


## 簡介 Introduction

TWNIC 的 DDNS 服務使用了一個自行研發的通訊協定，在此通訊協定中包含了使用者帳號與密碼驗證的機制。本軟體提供了與該通訊協定完全相容的密碼解密 API 函數\*。更多細節可以在 https://blog.debug.tw/twnic-ddns-client-uses-plaintext-passwd/ 獲得。

\*：最後確認相容之版本是 TWNIC 提供的 DDNS Client 1.6b 版


## 建構 Build

Visual Studio 2017 的使用者可以直接使用 .sln 進行專案建構。而其他平台或工具的使用者可以直接編譯 main.cpp 與 password.cpp 兩個檔案並連結其 .obj 檔，例如：

`> g++ -std=c++11 -o a.out twnic_ddns_pwd/*.cpp`


## API

password.h 在 namespace twnic::password 中宣告了下列函數：

**void Decode(const char\* ciphertext, std::string\* result)**

* ciphertext：密文密碼
* result：用來存放解密結果的 std::string 物件位置

若需使用實例可以參考 main.cpp 的內容。


## 著作權聲明 Copyright

Copyright (C) 2014-2017 Mifan Bang <https://debug.tw>

本軟體使用 [MIT License](LICENSE) 進行授權。

This software is licensed under the [MIT Lcense](LICENSE).

