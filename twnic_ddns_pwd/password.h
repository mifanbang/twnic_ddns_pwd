/*
 *  Copyright (C) 2014-2017 Mifan Bang <https://debug.tw>.
 *  This program is licensed under the MIT License
 */

#ifndef __PASSWORD_H__
#define __PASSWORD_H__


#include <string>


namespace twnic {
	namespace password {

		void Decode(const char* ciphertext, std::string* result);

	};  // namespace password
};  // namespace twnic


#endif  // __PASSWORD_H__
