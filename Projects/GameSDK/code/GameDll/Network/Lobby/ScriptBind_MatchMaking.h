// Copyright 2001-2019 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

//////////////////////////////////////////////////////////////////////////
// Base Class include
#include <CryScriptSystem/IScriptSystem.h>
#include <CryMemory/CrySizer.h>

//////////////////////////////////////////////////////////////////////////
// Pre-Declarations
struct ISystem;
class CMatchMakingHandler;

class CScriptBind_MatchMaking :
	public CScriptableBase
{
public:
	CScriptBind_MatchMaking( ISystem *pSystem );
	virtual ~CScriptBind_MatchMaking();

	virtual void GetMemoryUsage( ICrySizer *pSizer ) const
	{
		pSizer->AddObject( this, sizeof(*this) );
	}

	void AttachTo( CMatchMakingHandler *pMatchmaking, CGameLobbyManager *pLobbyManager );

	//////////////////////////////////////////////////////////////////////////
	// Functions to Query status
	int	IsSquadLeaderOrSolo( IFunctionHandler *pH );
	int	IsJoiningSession( IFunctionHandler *pH );
	int	IsSessionHost( IFunctionHandler *pH );
	int	IsInSession( IFunctionHandler *pH );
	int	HasGameStarted( IFunctionHandler *pH );
	int	HaveEnoughPlayersToStart( IFunctionHandler *pH );
	int	GetNumPlayersInCurrentSession( IFunctionHandler *pH );
	int	GetNumPlayersInSquad( IFunctionHandler *pH );
	int	GetMaxNumPlayers( IFunctionHandler *pH );

//	int GetMySkillScore( IFunctionHandler* pH );
	int GetAverageSkillScore( IFunctionHandler* pH /*,bool squadOnly*/ );

	int GetCurrentRegion( IFunctionHandler* pH );
	int GetCurrentLanguage( IFunctionHandler* pH );
	
	int GetCurrentMatchMakingVersionNum( IFunctionHandler* pH );

	int GetCurrentPlaylist( IFunctionHandler* pH );
	int GetCurrentVariant( IFunctionHandler* pH );
	int GetAvailableDLCs( IFunctionHandler* pH );
	int GetCurrentPing( IFunctionHandler* pH );

//	TODO - support these if required
//	int GetCurrentGameMode( IFunctionHandler* pH );
//	int GetCurrentMap( IFunctionHandler* pH );

	//////////////////////////////////////////////////////////////////////////
	// Functions to Request action
	int StartSearch( IFunctionHandler *pH, int freeSlots, int maxResults, SmartScriptTable searchParams );
	int	MergeWithServer( IFunctionHandler *pH, int sessionId );
	int	JoinServer( IFunctionHandler *pH, int sessionId );
	int	CreateServer( IFunctionHandler *pH, SmartScriptTable sessionParams );
	int	CancelSearch( IFunctionHandler *pH );
	int RequestUpdateCall( IFunctionHandler* pH, float timeToCall );

	int MMLog( IFunctionHandler *pH, const char* message, bool isError );

private:
	void RegisterMethods();
	void RegisterGlobals();

	ISystem*						m_pSystem;
	CGameLobbyManager*	m_pLobbyManager;
};