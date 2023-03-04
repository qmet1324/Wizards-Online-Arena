


#include "SteamNetworkManager.h"

SteamNetworkManager::SteamNetworkManager()
{
}

SteamNetworkManager::~SteamNetworkManager()
{
}

/*

void AddRequestLobbyListFilterSlotsAvailable( int nSlotsAvailable );

void FindMatch()
{
	
	uint_32 lobbies = ISteamMatchmaking::RequestLobbyList()
	
	if(lobbies == -1){
		ISteamMatchmaking::CreateLobby(public, 2);
	}else
	{
		ISteamMatchmaking::JoinLobby(ISteamMatchmaking::GetLobbyByIndex(0));
	}
}

void CreatePrivateLobby()
{
	ISteamMatchmaking::CreateLobby(private, 2);
}

void JoinPrivateLobby()
{
	int cFriends = SteamFriends()->GetFriendCount( k_EFriendFlagImmediate );
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
*/
