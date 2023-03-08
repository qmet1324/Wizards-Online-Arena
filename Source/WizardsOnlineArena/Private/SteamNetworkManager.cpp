


#include "SteamNetworkManager.h"

const int MAX_PLAYERS = 2;

SteamNetworkManager::SteamNetworkManager()
{
}

SteamNetworkManager::~SteamNetworkManager()
{
}

/*



void FindMatch()
{
	SteamMatchmaking()->AddRequestLobbyListFilterSlotsAvailable(1);
	uint_32 lobbies = ISteamMatchmaking::RequestLobbyList()
	
	if(lobbies == -1){
		ISteamMatchmaking::CreateLobby(public, MAX_PLAYERS);
	}else
	{
		ISteamMatchmaking::JoinLobby(ISteamMatchmaking::GetLobbyByIndex(0));
	}
}

void CreatePrivateLobby()
{
	ISteamMatchmaking::CreateLobby(private, MAX_PLAYERS);
}

void JoinPrivateLobby()
{
	int cFriends = SteamFriends()->GetFriendCount(k_EFriendFlagImmediate);
	for ( int i = 0; i < cFriends; i++ )
	{
		FriendGameInfo_t friendGameInfo;
		CSteamID steamIDFriend = SteamFriends()->GetFriendByIndex( i, k_EFriendFlagImmediate );
		if ( SteamFriends()->GetFriendGamePlayed( steamIDFriend, &friendGameInfo ) && friendGameInfo.m_steamIDLobby.IsValid() )
		{
			// friendGameInfo.m_steamIDLobby is a valid lobby, you can join it or use RequestLobbyData() get its metadata
		}
	}
}

void InviteFriend(CSteamID friendID)
{
	if(InviteUserToLobby(steamIDLobby, friendID) != 1)
	{
		Log("Friend Declined");
	}
}

void LeaveLobby()
{
	ISteamMatchmaking::LeaveLobby(CSteamID steamIDLobby);
}
*/
