/*
 *  Copyright (C) 2014-2017 Mifan Bang <https://debug.tw>.
 *  This program is licensed under the MIT License
 */

#include <algorithm>
#include <cassert>
#include <functional>
#include <string>
#include <vector>

#include "password.h"



struct DualChar {
	char ch[2];

	DualChar(short s = 0) {
		*reinterpret_cast<short*>(&ch) = s;
	}

	DualChar operator+ (int offset) const {
		DualChar result;
		result.ch[0] = ch[0] + offset;
		result.ch[1] = ch[1] + offset;
		return result;
	};
};

struct SaltedString {
	char salt;
	std::string string;
};


static std::vector<DualChar> ConvertStringToDualCharList(const std::string& str) {
	std::vector<DualChar> result;
	result.emplace_back(static_cast<short>(0));  // make room for the first character

	unsigned char resultCharIdx = 0;
	for (char chr : str) {
		result.back().ch[resultCharIdx] = chr;
		if (resultCharIdx > 0)
			result.emplace_back(static_cast<short>(0));
		resultCharIdx ^= 1;
	}

	return result;
}

static int GetOffsetFromSalt(int salt) {
	return salt & 0x1F;
}


static bool CheckSaltedString(const std::string& str)
{
	bool isSizeValid = str.size() > 2;  // must contain salt and plaintext
	bool isSaltPresent = isdigit(str[0]) && isdigit(str[1]);  // must contain a 2-digit salt

	return isSizeValid && isSaltPresent;
}

static SaltedString SplitEncodedResult(const std::string& str) {
	assert(CheckSaltedString(str));
	assert(str.size() % 2 == 0);

	SaltedString result;
	result.salt = atoi(str.substr(0, 2).c_str());
	result.string = str.substr(2);

	return result;
}

static std::string DecodePhase1(int offset, const std::vector<DualChar>& str) {
	auto decodeOpt1 = [](const DualChar& dc) -> char {
		char ch;
		ch = (dc.ch[0] - 0x4D) << 4;
		ch += dc.ch[1] - 0x21;
		return ch;
	};

	std::vector<DualChar> strCopy = str;
	std::string result;
	result.resize(strCopy.size());

	strCopy.pop_back();  // remove NULL character
	std::transform(strCopy.begin(), strCopy.end(), strCopy.begin(), [offset](const DualChar& dc) -> DualChar { return dc + (-offset); });
	std::transform(strCopy.begin(), strCopy.end(), result.begin(), decodeOpt1);

	return result;
}

static std::string DecodePhase2(const std::string& str) {
	auto decodeOpt2 = [](const char& lhs, const char& rhs) -> char {
		return (lhs != 0 ? (lhs - rhs + (char)0x2F) : 0);
	};

	const std::string url("http://www.twnic.net.tw/List/List_Regi.htm");

	std::string strCopy = str;
	assert(strCopy.size() <= url.size());

	std::string result;
	result.resize(strCopy.size());
	std::transform(strCopy.begin(), strCopy.end(), url.begin(), result.begin(), decodeOpt2);

	assert(CheckSaltedString(result));
	result.erase(0, 2);  // remove salt

	return result;
}


void twnic::password::Decode(const char* ciphertext, std::string* result) {
	std::string decodedStr = ciphertext;
	assert(CheckSaltedString(decodedStr));

	SaltedString saltedCipher = SplitEncodedResult(decodedStr);
	std::vector<DualChar> encodedStr = ConvertStringToDualCharList(saltedCipher.string);

	std::string intermediateStr1 = DecodePhase1(GetOffsetFromSalt(saltedCipher.salt), encodedStr);
	*result = DecodePhase2(intermediateStr1);
}
