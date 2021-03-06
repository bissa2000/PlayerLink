/*
 * Copyright (C) 2020 Deranged Senators
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef PLAYERLINK_SERVER_PLAYER_H
#define PLAYERLINK_SERVER_PLAYER_H
typedef struct Player {
	Player(){}
	Player(std::string id, std::string userName, std::string ip) {
		mID = id;
		mUserName = userName;
		mIP = ip;
	}
	std::string mID, mUserName, mIP;
}Player;
#endif