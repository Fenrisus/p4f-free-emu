// SetItemMacro.cpp: implementation of the CSetItemMacro class.
//	GS-N	1.00.18	JPN	0x0051ECB0
//	GS-CS	1.00.18	JPN	0x0051ECB0
//////////////////////////////////////////////////////////////////////

#include "..\Header\stdafx.h"
#include "..\Header\SetItemMacro.h"

#include "..\Header\LogProc.h"
#include "..\Header\zzzitem.h"
#include "..\Header\ReadScript.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSetItemMacro::CSetItemMacro()
{

}

CSetItemMacro::~CSetItemMacro()
{

}


BOOL CSetItemMacro::Load(char * szFileName)
{
	if ( fopen_s(&SMDFile,szFileName, "r") != 0 )
	{
		LogAdd("�� For BroadCasting Server Set Item Macro Load!!");
		return FALSE;
	}
 
	SMDToken Token;
	int n = 0;
	char szName[255];
	char szLog[255];
	int iSetIndex;
	int iType;
	int iIndex;
	int iLevel;
	int iSkill;
	int iLuck;
	int iOption;
	int iExOption1;
	int iExOption2;
	int iExOption3;
	int iExOption4;
	int iExOption5;
	int iExOption6;
	int i = 0;
	int iName = 0;

	Token = GetToken();

	while ( true )
	{
		if ( Token == END )
			break;

		if ( Token == NAME )
		{
			strcpy_s(szName, sizeof(szName), TokenString);
			sprintf_s(szLog, "%d - %s\n", iName, szName);

			this->bLoadItemName[iName] = TRUE;
			strcpy_s(this->sMakeItemName[iName], sizeof(this->sMakeItemName[iName]), "Í�$");
			OutputDebugString(szLog);

			Token = GetToken();
			i = 0;

			if ( Token == END )
				break;

			do
			{
				iSetIndex = (int)TokenNumber;

				Token = GetToken();
				iType = (int)TokenNumber;

				Token = GetToken();
				iIndex = (int)TokenNumber;

				Token = GetToken();
				iLevel = (int)TokenNumber;

				Token = GetToken();
				iSkill = (int)TokenNumber;

				Token = GetToken();
				iLuck = (int)TokenNumber;

				Token = GetToken();
				iOption = (int)TokenNumber;

				Token = GetToken();
				iExOption1 = (int)TokenNumber;

				Token = GetToken();
				iExOption2 = (int)TokenNumber;

				Token = GetToken();
				iExOption3 = (int)TokenNumber;

				Token = GetToken();
				iExOption4 = (int)TokenNumber;

				Token = GetToken();
				iExOption5 = (int)TokenNumber;

				Token = GetToken();
				iExOption6 = (int)TokenNumber;
		
				this->SubItemList[iName][i].SetIndex = iSetIndex;
				this->SubItemList[iName][i].ItemIndex = ITEMGET(iType,iIndex);
				this->SubItemList[iName][i].Level = iLevel;
				this->SubItemList[iName][i].Skill = iSkill;
				this->SubItemList[iName][i].Luck = iLuck;
				this->SubItemList[iName][i].Option = iOption;
				this->SubItemList[iName][i].Ex1 = iExOption1;
				this->SubItemList[iName][i].Ex2 = iExOption2;
				this->SubItemList[iName][i].Ex3 = iExOption3;
				this->SubItemList[iName][i].Ex4 = iExOption4;
				this->SubItemList[iName][i].Ex5 = iExOption5;
				this->SubItemList[iName][i].Ex6 = iExOption6;

				wsprintf(szLog, "[%d] %s level:%d skill:%d luck:%d option:%d [%d,%d,%d,%d,%d,%d]\n",
					i, ItemAttribute[ITEMGET(iType,iIndex)].Name, iLevel,iSkill,iLuck,iOption,
					iExOption1,iExOption2,iExOption3,iExOption4,iExOption5,iExOption6);

				OutputDebugString(szLog);
				i++;

				Token = GetToken();
			}
			while ( Token == NUMBER );
	
			iName++;
		}
		else
		{
			LogAdd("�� For BroadCasting Server Set Item Macro Load!!");
			return FALSE;
		}
	}
	fclose(SMDFile);

	return TRUE;
}



BOOL CSetItemMacro::MakeItem(int aIndex, char * szSetName)
{
	BOOL bFindItem = FALSE;
	
	for( int i = 0; i<MAX_SET_ITEM_MACRO;i++)
	{
	}
	return FALSE;
}
