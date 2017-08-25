/*
 *  Copyright (C) 2014-2017 Mifan Bang <https://debug.tw>.
 *  This program is licensed under the MIT License
 */

#include <array>

#include <stdio.h>

#include "password.h"


const char* s_realPasswd = "gotcha!";

const std::array<const char*, 90> s_ciphertexts = { {
	"10]5^0a7b+^:].]3a4]4",
	"11^6_2b8c,_;^/^4b5^5",
	"12_7`4c9d-`<_0_5c6_6",
	"13`8a6d:e.a=`1`6d7`7",
	"14a9b8e;f/b>a2a7e8a8",
	"15b:c:f<g0c?b3b8f9b9",
	"16c;d<g=h1d@c4c9g:c:",
	"17d<e>h>i2eAd5d:h;d;",
	"18e=f@i?j3fBe6e;i<e<",
	"19f>gBj@k4gCf7f<j=f=",
	"20g@h:kAl5hDg8g=k>g>",
	"21hAi<lBm6iEh9h>l?h?",
	"22iBj>mCn7jFi:i?m@i@",
	"23jCk@nDo8kGj;j@nAjA",
	"24kDlBoEp9lHk<kAoBkB",
	"25lEmDpFq:mIl=lBpClC",
	"26mFnFqGr;nJm>mCqDmD",
	"27nGoHrHs<oKn?nDrEnE",
	"28oHpJsIt=pLo@oEsFoF",
	"29pIqLtJu>qMpApFtGpG",
	"30qKrDuKv?rNqBqGuHqH",
	"31rLsFvLw@sOrCrHvIrI",
	"32S-T(W-X!T0S$S)W*S*",
	"33T.U*X.Y\"U1T%T*X+T+",
	"34U/V,Y/Z#V2U&U+Y,U,",
	"35V0W.Z0[$W3V'V,Z-V-",
	"36W1X0[1\\%X4W(W-[.W.",
	"37X2Y2\\2]&Y5X)X.\\/X/",
	"38Y3Z4]3^'Z6Y*Y/]0Y0",
	"39Z4[6^4_([7Z+Z0^1Z1",
	"40[6\\._5`)\\8[,[1_2[2",
	"41\\7]0`6a*]9\\-\\2`3\\3",
	"42]8^2a7b+^:].]3a4]4",
	"43^9_4b8c,_;^/^4b5^5",
	"44_:`6c9d-`<_0_5c6_6",
	"45`;a8d:e.a=`1`6d7`7",
	"46a<b:e;f/b>a2a7e8a8",
	"47b=c<f<g0c?b3b8f9b9",
	"48c>d>g=h1d@c4c9g:c:",
	"49d?e@h>i2eAd5d:h;d;",
	"50eAf8i?j3fBe6e;i<e<",
	"51fBg:j@k4gCf7f<j=f=",
	"52gCh<kAl5hDg8g=k>g>",
	"53hDi>lBm6iEh9h>l?h?",
	"54iEj@mCn7jFi:i?m@i@",
	"55jFkBnDo8kGj;j@nAjA",
	"56kGlDoEp9lHk<kAoBkB",
	"57lHmFpFq:mIl=lBpClC",
	"58mInHqGr;nJm>mCqDmD",
	"59nJoJrHs<oKn?nDrEnE",
	"60oLpBsIt=pLo@oEsFoF",
	"61pMqDtJu>qMpApFtGpG",
	"62qNrFuKv?rNqBqGuHqH",
	"63rOsHvLw@sOrCrHvIrI",
	"64S0T*W-X!T0S$S)W*S*",
	"65T1U,X.Y\"U1T%T*X+T+",
	"66U2V.Y/Z#V2U&U+Y,U,",
	"67V3W0Z0[$W3V'V,Z-V-",
	"68W4X2[1\\%X4W(W-[.W.",
	"69X5Y4\\2]&Y5X)X.\\/X/",
	"70Z'Z,]3^'Z6Y*Y/]0Y0",
	"71[([.^4_([7Z+Z0^1Z1",
	"72\\)\\0_5`)\\8[,[1_2[2",
	"73]*]2`6a*]9\\-\\2`3\\3",
	"74^+^4a7b+^:].]3a4]4",
	"75_,_6b8c,_;^/^4b5^5",
	"76`-`8c9d-`<_0_5c6_6",
	"77a.a:d:e.a=`1`6d7`7",
	"78b/b<e;f/b>a2a7e8a8",
	"79c0c>f<g0c?b3b8f9b9",
	"80d2d6g=h1d@c4c9g:c:",
	"81e3e8h>i2eAd5d:h;d;",
	"82f4f:i?j3fBe6e;i<e<",
	"83g5g<j@k4gCf7f<j=f=",
	"84h6h>kAl5hDg8g=k>g>",
	"85i7i@lBm6iEh9h>l?h?",
	"86j8jBmCn7jFi:i?m@i@",
	"87k9kDnDo8kGj;j@nAjA",
	"88l:lFoEp9lHk<kAoBkB",
	"89m;mHpFq:mIl=lBpClC",
	"90n=n@qGr;nJm>mCqDmD",
	"91o>oBrHs<oKn?nDrEnE",
	"92p?pDsIt=pLo@oEsFoF",
	"93q@qFtJu>qMpApFtGpG",
	"94rArHuKv?rNqBqGuHqH",
	"95sBsJvLw@sOrCrHvIrI",
	"96T#T,W-X!T0S$S)W*S*",
	"97U$U.X.Y\"U1T%T*X+T+",
	"98V%V0Y/Z#V2U&U+Y,U,",
	"99W&W2Z0[$W3V'V,Z-V-"
} };



int main()
{
	for (const auto& ciphertext : s_ciphertexts) {
		std::string plaintext;
		twnic::password::Decode(ciphertext, &plaintext);

		printf("[%s] ciphertext %s decrypted into %s\n",
			strcmp(s_realPasswd, plaintext.c_str()) == 0 ? "PASSED" : "FAILED",
			ciphertext,
			plaintext.c_str()
		);
	}

	return 0;
}
