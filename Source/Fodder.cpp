/*
 *  Cannon Fodder
 *  ------------------------
 *
 *  Copyright (C) 2008-2015 Robert Crossfield
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "stdafx.hpp"
#include "SpriteData.hpp"
#include "IntroData.hpp"
#include "Recruits.hpp"
#include "UnknownData.hpp"
#include "MissionNames.hpp"

const char* mBinTable[] = { "rjnull.bin", 
							"rjnull.bin", 
							"player.bin", 
							"player.bin", 
							"player.bin", 
							"player.bin" };

const uint16 mMissionPhaseTable[] = {	01, 02, 01, 04, 03, 02, 03, 04,
										02, 05, 03, 06, 01, 03, 03, 02,
										01, 05, 01, 04, 01, 04, 05, 06 };

std::string mMapTypes[] = {
	"jun",
	"des",
	"ice",
	"mor",
	"int",
	"hid"
};

cFodder::cFodder() {

	mResources = new cResources();
	mWindow = new cWindow();

	mTicksDiff = 0;
	mTicks = 0;

	mIntroDone = 0;
	mErrorCode = 0;
	word_427D4 = -1;

	mMouseButtons = 0;

	mouse_Button_Status = 0;
	mouse_Pos_Column = 0;
	mouse_Pos_Row = 0;

	mButtonPressLeft = mButtonPressRight = 0;
	word_39EF8 = word_39F02 = 0;
	word_39EF6 = word_39EFA = 0;
	word_39EFC = word_39F04 = 0;
	word_39FF4 = 0;
	
	word_39FF2 = 0;
	word_39FF4 = 0;
	word_39FF6 = 0;
	word_39FF8 = 0;
	word_39FFA = 0;

	word_3AA43 = 0;
	word_3ABA7 = 0;
	word_3ABE9 = 0;
	word_3ABEB = 0;
	word_3A9B2 = 0;
	word_3B15D = 0;
	word_3B173 = 0;
	word_3B4F5 = 0;
	word_3E1B7 = 0;
	
	word_40054 = 0;
	word_42062 = 0;
	word_42066 = 0;
	mDrawSpritePositionX = 0;
	mDrawSpritePositionY = 0;
	word_4206C = 0;
	word_4206E = 0;
	byte_42070 = 0;
	byte_42071 = 0;
	word_42074 = 0;
	word_42076 = 0;
	mKeyCode = 0;

	mSurfacePlayfield = 0;
	mSurfaceMapOverview = 0;
	mouseData0 = new sMouseData();
	mouseData1 = new sMouseData();

	mMap = 0;

	word_3A3BB = 0;
	word_3A3BD = 0;
	word_3FA1F = -1;

	word_42072 = 0;

	word_44A2E = 0;
	word_44A30 = 0;
	word_44A32 = 0;
	word_44A34 = 0;

	for (unsigned int x = 0; x < 60; ++x)
		word_3A3FD[x] = 0;

	for (unsigned int x = 0; x < 60; ++x)
		word_3A475[x] = 0;

	for (unsigned int x = 0; x < 60; ++x)
		word_3A4ED[x] = 0;

	for (unsigned int x = 0; x < 60; ++x)
		word_3A565[x] = 0;

	for (unsigned int x = 0; x < 60; ++x)
		word_3A5DD[x] = 0;

	for (unsigned int x = 0; x < 60; ++x)
		word_3A655[x] = 0;

	for (unsigned int x = 0; x < 60; ++x)
		word_3A6CD[x] = 0;
	 
	for (unsigned int x = 0; x < 60; ++x)
		word_3A745[x] = 0;

	for (unsigned int x = 0; x < 60; ++x)
		word_3A7BD[x] = 0;

	for (unsigned int x = 0; x < 60; ++x)
		word_3A835[x] = 0;

	for (unsigned int x = 0; x < 0x18; ++x) {
		word_3E0E5[x] = 0;
	}
}

cFodder::~cFodder() {
	
	delete mSurfaceMapOverview;
	delete mSurfacePlayfield;
}

void cFodder::sub_10BBC() {
	word_390A4 = 0;
	word_390A6 = 0;
	word_390AE = 0;
	word_390B8 = 0;
	mMapNumber = 0;
	mMissionNumber = 0;
	mMissionPhase = 0;
	word_39096 = 0;
	word_390CE = 0;
	word_390D0 = 0;
	word_390D2 = 0;
	word_390D4 = 0;

	for (unsigned int x = 0; x < 8; ++x) {
		word_390D6[x] = 0;
	}

	word_390E8 = 0;
	word_390EA = 0;
	mMissionPhaseRemain = 0;
	mMissionPhases = 0;
	word_390F4 = 0;

	for (unsigned int x = 0; x < 8; ++x) {
		mSquad[x].mRecruitID = 0;
		mSquad[x].mRank = 0;
		mSquad[x].field_3 = 0;
		mSquad[x].field_4 = 0;
		mSquad[x].field_6 = 0;
		mSquad[x].field_8 = 0;
		mSquad[x].mNumberOfKills = 0;
	}

	word_3915A = 0;
	word_3915E = 0;

	for (unsigned int x = 0; x < 361; ++x)
		word_391D2[x] = 0;

	dword_394A4 = 0;
	dword_394A8 = 0;

	for (unsigned int x = 0; x < 361; ++x)
		word_394AC[x] = 0;

	dword_3977E = 0;

	for (unsigned int x = 0; x < 5; ++x) {
		mHeroes[x].mRecruitID = 0;
		mHeroes[x].field_1 = 0;
		mHeroes[x].mKills = 0;
	}
	word_397AC = 0;
	word_397AE = 0;
	word_397D2 = 0;
	word_397D4 = 0;
	mTroopsAvailable = 0;
}

void cFodder::Troops_Clear() {
	word_3915E = -1;
	word_3915A = -1;

	for (unsigned int x = 0; x < 8; ++x) {
		mSquad[x].field_4 = -1;
		mSquad[x].mRecruitID = -1;
		mSquad[x].mRank = 0;
		mSquad[x].field_3 = 0;
	}
}

void cFodder::Heroes_Clear() {
	
	for (unsigned int x = 0; x < 5; ++x) {
		mHeroes[x].mRecruitID = -1;
		mHeroes[x].field_1 = -1;
		mHeroes[x].mKills = -1;
	}
}

void cFodder::sub_10CE7() {
	
}

void cFodder::sub_10D61() {
	// Clear memory 2454 to 3B58
	mButtonPressLeft = 0;
	mButtonPressRight = 0;
	word_39EF8 = 0;
	word_39EFA = 0;
	word_39EFC = 0;
	word_39F02 = 0;
	word_39F04 = 0;
	//word_39F06 = 0;

	dword_39F98 = 0;
	dword_39F9C = 0;
	word_39FCE = 0 ;
	
	dword_3A000 = 0;
	dword_3A004 = 0;
	dword_3A008 = 0;
	word_3A00C = 0;
	word_3A00E = 0;
	word_3A010 = 0;
	word_3A016 = 0;
	word_3A01A = 0;
	dword_3A391 = 0;
	dword_3A395 = 0;
	word_3A399 = 0;
	word_3A8CF = 0;
	word_3A9B2 = 0;
	word_3A9B4 = 0;
	word_3A9C6 = 0;
	word_3A9CE = 0;
	word_3A9D0 = 0;
	word_3A9E6 = 0;
	word_3A9F7 = 0;

	for (uint16 x = 0; x < 3; ++x) {
		word_3AA05[x] = 0;
		word_3AA0B[x] = 0;
		word_3AA11[x] = 0;
	}

	word_3AA17 = 0;
	word_3AA19 = 0;
	word_3AA4D = 0;
	word_3AA4F = 0;
	word_3AA51 = 0;
	word_3AA55 = 0;
	word_3AA67 = 0;
	word_3AA71 = 0;
	word_3AAC7 = 0;
	dword_3AAC9 = 0;
	word_3AACD = 0;
	word_3AACF = 0;
	word_3ABB1 = 0;
	word_3AAD1 = 0;
	word_3AB39 = 0;
	word_3ABAD = 0;
	word_3ABAF = 0;
	word_3AC19 = 0;
	word_3AC21 = 0;
	word_3AC2B = 0;
	word_3AC3F[0] = 0;
	word_3AC3F[1] = 0;
	word_3AC3F[2] = 0;
	word_3AC3F[3] = 0;
	word_3AC3F[4] = 0;
	word_3AC3F[5] = 0;
	dword_3B1CB = 0;

	for (uint16 x = 0; x < 0x0F; ++x ) 
		word_3B1CF[x] = 0;

	word_3B1EF = 0;
	word_3B1F1 = 0;
	dword_3B1FB = 0;
	
	dword_3B20B = 0;

	word_3B25B = 0;
	word_3B2CB = 0;
	word_3B2CD = 0;
	word_3B2CF = 0;
	word_3B2F3 = 0;
	word_3B2FD = 0;
	word_3B2FF = 0;

	word_3B301 = 0;
	word_3B303 = 0;
	word_3B305 = 0;
	word_3B307 = 0;
	word_3B447 = 0;
	for (uint16 x = 0; x < 3; ++x)
		word_3B461[x] = 0;

	for (uint16 x = 0; x < 7; ++x)
		mMapGoals[x] = 0;

	word_3B4DB = 0;
	word_3B4F1 = 0;
	word_3B4F3 = 0;
}

void cFodder::sub_10D9F() {
	word_3BDE7 = 1;
	word_3BDE9 = 1;
	word_3BDEB = 5;
	// -1
	off_3BDEF[0] = dword_3BE03;
	off_3BDEF[1] = dword_3BE27;
	off_3BDEF[2] = dword_3BE4B;
	off_3BDEF[3] = dword_3BE6F;
	off_3BDEF[4] = dword_3BE93;
	
	for (unsigned int x = 0; x < 9; ++x) {
		dword_3BE03[x] = (sSprite_0*) -1;
	}
	for (unsigned int x = 0; x < 9; ++x) {
		dword_3BE27[x] = (sSprite_0*) -1;
	}
	for (unsigned int x = 0; x < 9; ++x) {
		dword_3BE4B[x] = (sSprite_0*) -1;
	}
	for (unsigned int x = 0; x < 9; ++x) {
		dword_3BE6F[x] = (sSprite_0*) -1;
	}
	for (unsigned int x = 0; x < 9; ++x) {
		dword_3BE93[x] = (sSprite_0*) -1;
	}
	word_3BEB9 = 1;
	word_3BEBB = 1;
	word_3BEBD = 1;
	word_3BEC1 = 0x1A;
	word_3BEC3 = 0x12;
	word_3BEC9 = 0xC8;
	word_3BED5[0] = 2;
	word_3BED5[1] = 2;
	word_3BED5[2] = 2;
	word_3BED5[3] = 2;
	word_3BED5[4] = 2;
	word_3BEDF[0] = 1;
	word_3BEDF[1] = 1;
	word_3BEDF[2] = 1;
	word_3BEDF[3] = 1;
	word_3BEDF[4] = 1;
	word_3BEDF[5] = 0;
	word_3BEDF[6] = 0;
	word_3BEDF[7] = 0;
	word_3BEDF[8] = 0;
	word_3BEDF[9] = 0;

	off_3BEF3[0] = word_3A3FD;
	off_3BEF3[1] = word_3A475;
	off_3BEF3[2] = word_3A4ED;
	off_3BEF3[3] = word_3A565;
	off_3BEF3[4] = word_3A5DD;
	off_3BEF3[5] = word_3A655;
	off_3BEF3[6] = word_3A6CD;
	off_3BEF3[7] = word_3A745;
	off_3BEF3[8] = word_3A7BD;
	off_3BEF3[9] = word_3A835;

	byte_3BF1B[0] = -1;
	byte_3BF1B[1] = -1;
	byte_3BF1B[2] = -1;

	word_3BF1E[0] = 0;
	word_3BF1E[1] = 0;
	word_3BF1E[2] = 0;
	word_3BF1E[3] = 0;
	word_3BF1E[4] = 0;
	word_3BF1E[5] = 0;
}

void cFodder::sub_10DEC() {
	word_39FD4 = 0;
	word_3A054 = 0;
	dword_3A39D = 0;
	word_39FD0 = 0;
	word_3A9A6[0] = 0;
	word_3A9A6[1] = 0;
	word_3A9AA = 0;
	word_3A9AC = 0;
	dword_39F7C = 0;
	word_3A9F7 = 0x23;

	byte_3A05A[0] = 0;
	byte_3A05A[1] = 0;
	byte_3A05A[2] = 0;
	byte_3A05A[3] = 0;

	byte_3A05E = 0;
	word_3A8D5 = 0;
	word_3A8D7 = 0;
	word_3A8D9 = 0;
	dword_3A8DB = 0;
	
	for (uint16 x = 0; x < 200; ++x )
		byte_3A8DE[x] = 0;

	word_3A06B = -1;
	word_3A28D = 0x0C;
	word_3A3FD[0] = -1;
	word_3A475[0] = -1;
	word_3A4ED[0] = -1;
	word_3A565[0] = -1;
	word_3A5DD[0] = -1;
	word_3A655[0] = -1;
	word_3A6CD[0] = -1;
	word_3A745[0] = -1;
	word_3A7BD[0] = -1;
	word_3A835[0] = -1;
}

void cFodder::sub_10EA4() {
	dword_39F98 = 0;
	dword_39F9C = 0;
	mMapSpt_Loaded[0] = -32768;
	word_39FCE = 0;
}

void cFodder::sub_10EC3() {
	sub_10EE3();
	dword_3A000 = 0;
	dword_3A004 = 0;
	dword_3A008 = 0;

}

void cFodder::sub_10EE3() {

	int16* Data = mMapSpt_Loaded;
	for( int16 count = 0x2C; count >= 0; --count ) {
		
		for( int16 count2 = 0x3A; count2 >= 0; --count2 ) {
			*Data++ = 0;
		}
		*(Data - 0x3B) = -32768;
	}
	*(Data - 0x3B) = -1;
}

void cFodder::map_Load_Spt() {
	
	std::string Filename_Spt = map_Filename_SptGet();

	mMapSptSize = g_Resource.fileLoadTo( Filename_Spt, (uint8*) mMapSptPtr );
	tool_EndianSwap( (uint8*) mMapSptPtr, mMapSptSize );

	word_3AA17 = 0;
	word_3AA19 = 0;
	
	uint16* dword_37AC0 = mMapSptPtr;
	int16* dword_37AC4 = mMapSpt_Loaded;
	
	uint16* dword_37AC8 = dword_37AC0 + (mMapSptSize / 2);
	int16 dword_37ABC = 0x0A;

	for(uint16 mTmpCount = 0; dword_37AC0 != dword_37AC8; dword_37AC4 += 0x3B ) {
		++dword_37AC0;

		int16* si = dword_37AC4;
		si[0x04] = 0x7C;
		
		uint16 ax = mTmpCount / 8;

		si[0x19] = ax;
		++dword_37AC0;
		ax = dword_37AC0[0];
		++dword_37AC0;
		
		ax += 0x10;
		si[0x00] = ax;
		si[0x13] = ax;
		
		ax = dword_37AC0[0];
		++dword_37AC0;
		si[0x02] = ax;
		si[0x14] = ax;
		
		ax = dword_37AC0[0];
		++dword_37AC0;
		si[0x0C] = ax;
		
		if( si[0x0C] == 0x6A || si[0x0C] == 0x48 ) {
				
			++word_3AA19;
		}
		
		if( si[0x0C] != 0 ) {
			//10EE
			if( si[0x0C] == 0x24 ) {
				si[0x11] = 1;
				++word_3AA17;
				
			} else {
				if( si[0x0C] == 5 )
					++word_3AA17;
			}
			
			dword_37ABC += 0x0A;
			if( si[0x31] > 4 )
				dword_37ABC = 0;
			
			si[0x25] = dword_37ABC;
			
		} else {
			// 113C
			++mTmpCount;
			si[0x25] = 0;
		}
		
		// 114B
	}
}

std::string cFodder::map_Filename_Get() {
	std::stringstream	filename;
	
	filename << "mapm";
	filename << (mMapNumber + 1);

	return filename.str();
}

std::string cFodder::map_Filename_MapGet() {
	std::string	filename = map_Filename_Get();

	filename.append(".map");

	return filename;
}

std::string cFodder::map_Filename_SptGet() {
	std::string	filename = map_Filename_Get();

	filename.append(".spt");

	return filename;
}

void cFodder::map_Troops_Prepare() {
	word_397D2 = 0;
	int16* dword_37AC0 = mMapSpt_Loaded;
	
	for( int16 mTmpCount = 0x1D; mTmpCount > 0; --mTmpCount ) {
		int16* si = dword_37AC0;
		if( *si != -32768 ) {
			
			if( si[0x0C] == 0 )
				++word_397D2;
		}
		dword_37AC0 += 0x3B;
	}
	
	word_397D4 = 0;
	
	for( int16 x = 7; x >= 0; --x ) {
		
		if( mSquad[x].mRecruitID != -1 ) {
			--word_397D2;
			++word_397D4;
		}
	}
	
	int16 ax = word_397D2;
	
	if( word_397D2 >= 0 ) {

		if( ax > word_390CE )
			ax = word_390CE;
		
		word_397D2 = ax;
		word_390CE -= ax;
	}
	
	ax += word_397D4;
	mTroopsAvailable = ax;
}

void cFodder::map_Load_Players() {

	for (int16 Data1c = 7; Data1c >= 0; --Data1c) {
		sSquad_Member* Data20 = mSquad;

		for (int16 Data0 = 7; Data0 >= 0; --Data0, ++Data20) {

			if (Data20->mRecruitID == -1) {

				sSquad_Member* Data24 = Data20 + 1;
				sSquad_Member* Data28 = Data20;

				*Data28 = *Data24;
				Data28->mRecruitID = -1;
				Data28->mRank = 0;
			}
		}
	}
	
	sSquad_Member* Data20 = mSquad;

	//seg000:1347
	for (int16 Data1c = 7; Data1c >= 0; --Data1c, ++Data20) {
		sSquad_Member* Data24 = mSquad;

		for (int16 Data18 = 7; Data18 >= 0; --Data18, ++Data24) {

			if (Data20 == Data24)
				continue;

			if (Data20->mRecruitID == -1 || Data24->mRecruitID == -1)
				continue;

			if (Data20->mRank != Data24->mRank)
				continue;

			if (Data20->mNumberOfKills <= Data24->mNumberOfKills)
				continue;

			sSquad_Member Spare = *Data20;

			*Data20 = *Data24;
			*Data24 = Spare;
		}
	}
}

void cFodder::sub_1142D() {
	sub_301F7();

	if (!word_3ABA7) {

		if (word_390D4) {
			sSquad_Member* Data20 = mSquad;
			uint16* Data24 = word_390D6;

			for (int16 Data0 = 7; Data0 >= 0; --Data0, ++Data20) {
				Data20->field_4 = *Data24++;
			}
		}

		//seg000:1481                loc_11481:
		word_390D4 = -1;
		sSquad_Member* Data20 = mSquad;
		uint16* Data24 = word_390D6;
		for (int16 Data0 = 7; Data0 >= 0; --Data0, ++Data20) {
			*Data24++ = Data20->field_4;
		}

	}
	//seg000:14C6                loc_114C6:
	int16 Data1C = word_397D2 - 1;
	while (Data1C >= 0) {
		sub_1152F();
		--Data1C;
	}

	if (word_3ABA7)
		return;

	Data1C = mTroopsAvailable;
	sSquad_Member* Data20 = mSquad;
	for (int16 Data0 = 7; Data0 >= 0; --Data0, ++Data20) {

		if (Data20->field_4 == -1)
			continue;

		if (Data1C)
			--Data1C;
		else
			Data20->field_4 = -1;
	}

}

void cFodder::sub_1152F() {
	sSquad_Member* Data20 = mSquad;

	for (int16 Data0 = 7; Data0 >= 0; --Data0) {

		if (Data20->mRecruitID == -1) {

			if (word_390F4 >= 360)
				return;

			Data20->mRecruitID = word_390F4;

			sRecruit* Data24 = mRecruits;
			Data24 += word_390F4;

			Data20->mRank =  (mMissionNumber - 1) / 3;
			Data20->field_8 = 0;
			Data20->field_6 = 3;
			++word_390F4;

			return;
		}

		++Data20;
	}
}

void cFodder::sub_115F7() {

	word_3A016 = mTroopsAvailable;
	int16* Data20 = mMapSpt_Loaded;
	sSquad_Member* Troop = mSquad;

	for (int16 Data18 = 0x1D; Data18 >= 0; --Data18, Data20 += 0x3B ) {

		if (*Data20 == -32768)
			continue;

		if (Data20[0x0C])
			continue;

		--word_3A016;
		if (word_3A016 < 0) {
			Troop->field_4 = -1;
			Data20[0] = -32768;
			Data20[0x0C] = 4;
			Data20[0x08] = 0x7C;
			++Troop;
		}
		else {
			// loc_1166B
			*((uint32*)&Data20[0x23]) = (uint32)Troop;

			int16 Data24 = (int16)(Data20 - &mMapSpt_Loaded[0]);

			Troop->field_4 = Data24;
			Data20[0x08] = 0x40;
			Data20[0x11] = 0;

			++Troop;
		}
	}
}

void cFodder::map_Load_TileSet() {
	std::string MapName = map_Filename_MapGet();

	size_t Size = g_Resource.fileLoadTo( MapName, mMap );
	tool_EndianSwap( mMap + 0x60, Size - 0x60 );

	std::string BaseName,SubName, BaseBase, BaseSub, BaseBaseSet, BaseSubSet;
	BaseName.append( mMap, mMap + 11 );
	SubName.append( mMap + 0x10, mMap + 0x10 + 11 );

	BaseBaseSet.append( mMap, mMap + 3 );
	BaseSubSet.append( mMap + 0x10, mMap + 0x10 + 3 );

	BaseBase.append( mMap, mMap + 7 );
	BaseSub.append( mMap + 0x10, mMap + 0x10 + 7 );


	g_Resource.fileLoadTo( BaseName, mDataBaseBlk );
	paletteLoad( mDataBaseBlk + 0xFA00, 0x80, 0x00 );

	g_Resource.fileLoadTo( SubName, mDataSubBlk );

	mMapWidth = readBEWord( &mMap[0x54] );
	writeLEWord( &mMap[0x54], mMapWidth );

	mMapHeight = readBEWord( &mMap[0x56] );
	writeLEWord( &mMap[0x56], mMapHeight );

	delete mSurfaceMapOverview;
	mSurfaceMapOverview = new cSurface( mMapWidth * 16, mMapHeight * 16 );

	std::string JunCopt = sub_12AA1( BaseBaseSet, "copt.dat" );
	std::string JunBaseSwp = sub_12AA1( BaseBase, ".swp" );
	std::string JunBaseHit = sub_12AA1( BaseBase, ".hit" );
	std::string JunBaseBht = sub_12AA1( BaseBase, ".bht" );
	std::string JunArmy = sub_12AA1( BaseSubSet, "army.dat" );
	std::string JunSubSwp = sub_12AA1( BaseSub, ".swp" );
	std::string JunSubHit = sub_12AA1( BaseSub, ".hit" );
	std::string JunSubBht = sub_12AA1( BaseSub, ".bht" );

	g_Resource.fileLoadTo( JunCopt, mDataHillBits );
	paletteLoad( mDataHillBits + 0xD2A0, 0x40, 0xB0 );
	paletteLoad( mDataHillBits + 0xD360, 0x10, 0x90 );
	g_Resource.fileLoadTo( JunArmy, mDataArmy );
	paletteLoad( mDataArmy + 0xD200, 0x10, 0xA0 );

	Size = g_Resource.fileLoadTo( JunBaseSwp, (uint8*) &word_3D03D[0] );
	tool_EndianSwap( (uint8*)&word_3D03D[0], Size );
	
	Size = g_Resource.fileLoadTo( JunSubSwp, (uint8*) &word_3D21D[0] );
	tool_EndianSwap( (uint8*)&word_3D21D[0], Size );

	Size = g_Resource.fileLoadTo( JunBaseHit, (uint8*) &word_3C09D[0] );
	tool_EndianSwap( (uint8*)&word_3C09D[0], Size );
	
	Size = g_Resource.fileLoadTo( JunSubHit, (uint8*) &graphicsSub0[0] );
	tool_EndianSwap( (uint8*)&graphicsSub0[0], Size );
	
	Size = g_Resource.fileLoadTo( JunBaseBht, (uint8*) &graphicsBaseBht[0] );
	tool_EndianSwap( (uint8*)&graphicsBaseBht[0], Size );

	Size = g_Resource.fileLoadTo( JunSubBht, (uint8*) &graphicsSub0Bht[0] );
	tool_EndianSwap( (uint8*)&graphicsSub0Bht[0], Size );
	
	Sprite_SetDataPtrToBase( off_32C0C );
}

void cFodder::sub_12083() {
	dword_39F18 = 0;
	dword_39F1C = 0;
	dword_39F20 = 0;
	dword_39F24 = 0;
	dword_39F28 = 0;
	dword_39F2C = 0;
	dword_39F30 = 0;
	word_39F34 = 0;
	word_39F38 = 0;
	word_39F4C = 0;
	word_39F50 = 0;
	dword_39F42 = 0;
	dword_39F46 = 0;
	dword_39F56 = 0;
}

void cFodder::sub_126DD() {
	const int8* Data20 = off_3D5F1[mMapNumber];

	for (; *Data20 != -1; ++Data20) {

		int8 Data0 = *Data20;
		
		mMapGoals[Data0-1] = -1;
	}
}

std::string	cFodder::sub_12AA1( std::string pBase, const char* pFinish ) {
	std::string Final;

	Final.append( pBase );
	Final.append( pFinish );

	return Final;
}

void cFodder::Map_Overview_Prepare() {
	if (mMapNumber == word_3FA1F)
		return;

	word_3FA1F = mMapNumber;

	for (int16 cx = 0x45; cx >= 0; --cx) {
		dword_3E9A3[cx] = 0;
	}

	int16* Di = (int16*) (mMap + 0x60);

	int16 Data8;
	int16 DataC;

	if (readLEWord( &mMap[0x56] ) <= readLEWord( &mMap[0x54] ) ) {
		int32 eax = 0x1100000;
		int32 ebx = readLEWord( &mMap[0x54] );
		ebx &= 0xFFFF;

		eax /= ebx;
		dword_3F946 = eax;
		eax >>= 0x10;
		Data8 = eax;

		eax = 0x0C80000;
		ebx = readLEWord( &mMap[0x54] );
		ebx &= 0xFFFF;
		eax /= ebx;
		dword_3F94A = eax;
		eax >>= 0x10;
		DataC = eax;
	}
	else {
		//loc_12FDD
		int32 eax = 0x1100000;
		int32 ebx = readLEWord( &mMap[0x56] );
		ebx &= 0xFFFF;

		eax /= ebx;
		dword_3F946 = eax;
		eax >>= 0x10;
		Data8 = eax;

		eax = 0x0C80000;
		ebx = readLEWord( &mMap[0x56] );
		ebx &= 0xFFFF;
		eax /= ebx;
		dword_3F94A = eax;
		eax >>= 0x10;
		DataC = eax;
	}

	int32 eax = dword_3F946;
	int32 ebx = readLEWord( &mMap[0x54] ) & 0xFFFF;
	eax *= ebx;
	eax >>= 0x11;
	eax -= 0x88;
	eax = -eax;
	word_3F94E = eax;

	eax = dword_3F94A;
	ebx = readLEWord( &mMap[0x56] ) & 0xFFFF;
	eax *= ebx;
	eax >>= 0x11;
	eax -= 0x64;
	eax = -eax;
	word_3F950 = eax;
	int16 Data0 = 0x10;
	int16 Data4 = 0x10;

	eax = Data8 + 1;
	eax <<= 0x10;
	eax /= Data0;
	dword_44A42 = eax;

	eax = DataC + 1;
	eax >>= 0x10;
	eax /= Data4;
	dword_44A46 = eax;

	//uint16 dx = readLEWord( &mMap[0x56] );
	//int32 Data14 = 0;
	//int16 Data16 = word_3F950;

	for (uint16 dx = 0; dx < mMapHeight; ++dx) {
		//uint16 cx = readLEWord( &mMap[0x54] );

		//int32 Data10 = 0;
		//int16 Data12 = word_3F94E;

		for (uint16 cx = 0; cx < mMapWidth; ++cx) {

			sub_2B04B( (uint8*) mGraphicBlkPtrs[ *Di & 0x1FF], cx, dx );

			++Di;
			//Data10 += dword_3F946;
		}

		//Data14 += dword_3F94A;
	}

}

void cFodder::map_SetTileType() {

	char Type[3];

	Type[0] = mMap[0];
	Type[1] = mMap[1];
	Type[2] = mMap[2];

	for (unsigned int x = 0; x < 6; ++x) {
		if (mMapTypes[x][0] != Type[0])
			continue;
	
		if (mMapTypes[x][1] != Type[1])
			continue;

		if (mMapTypes[x][2] != Type[2])
			continue;

		mMap_TileSet = x;
		return;
	}

	mMap_TileSet = 0;
}

void cFodder::sub_12AB1() {
	
	word_3E75B = -1;
}

void cFodder::Load_PlayerBin() {
	
}

bool cFodder::EventAdd( cEvent pEvent ) {
	
	mEvents.push_back( pEvent );

	return true;
}

void cFodder::Load_File( const std::string& pFilename ) {
	size_t FileSize = 0;

	uint8* Buffer = local_FileRead( pFilename, "", FileSize );

	word_3E7ED = readLEWord( Buffer );
	mEffectDriver = readLEWord( Buffer + 2 );
	mMusicDriver = readLEWord( Buffer + 4 );

	delete Buffer;
}

void cFodder::memory_XMS_Detect() {

	word_427D4 = 1;
	mErrorCode = 0;
}

void cFodder::eventProcess() {
	g_Window.EventCheck();

	for (std::vector<cEvent>::iterator EventIT = mEvents.begin(); EventIT != mEvents.end(); ++EventIT) {

		switch (EventIT->mType) {
			case eEvent_KeyDown:
				keyProcess( EventIT->mButton, false );
				break;

			case eEvent_KeyUp:
				keyProcess( EventIT->mButton, true );
				break;

			case eEvent_MouseLeftDown:
				mMousePosition = EventIT->mPosition;
				mMouseButtons |= 1;
				break;

			case eEvent_MouseRightDown:
				mMousePosition = EventIT->mPosition;
				mMouseButtons |= 2;
				break;

			case eEvent_MouseLeftUp:
				mMousePosition = EventIT->mPosition;
				mMouseButtons &= ~1;
				break;

			case eEvent_MouseRightUp:
				mMousePosition = EventIT->mPosition;
				mMouseButtons &= ~2;
				break;

			case eEvent_MouseMove:
				mMousePosition = EventIT->mPosition;
				break;

			case eEvent_Quit:

				break;
		}

	}

	mEvents.clear();
}

void cFodder::keyProcess( uint8 pKeyCode, bool pPressed ) {
	
	if (pKeyCode == SDL_SCANCODE_LCTRL || pKeyCode == SDL_SCANCODE_RCTRL) {
		if (pPressed)
			mKeyControlPressed = -1;
		else
			mKeyControlPressed = 0;
	}
	
	if (pKeyCode == SDL_SCANCODE_P)
		word_3A9D0 = !word_3A9D0;
	
	if (pKeyCode == SDL_SCANCODE_ESCAPE)
		word_3A9B2 = -1;

	if (pKeyCode == SDL_SCANCODE_SPACE)
		++word_3A9B4;

	if (pKeyCode == SDL_SCANCODE_M) {
		if (word_3B4F1 == 0)
			word_3B4DB = -1;
	}

	if (pKeyCode == SDL_SCANCODE_1)
		mKeyNumberPressed = 2;
	
	if (pKeyCode == SDL_SCANCODE_2)
		mKeyNumberPressed = 3;

	if (pKeyCode == SDL_SCANCODE_3)
		mKeyNumberPressed = 4;
}

void cFodder::mouse_Setup() {
	
	word_3BDAF = 0x7F;
	word_3BDB1 = 0x67;
	word_3BDB3 = 0;
	word_3BDB5 = 0;

	mouseData1->anonymous_0 = 0;
	mouseData1->anonymous_1 = 0;
	mouseData1->anonymous_2 = 2;
	mouseData1->mColumn = 160;
	mouseData1->mRow = 100;
	mouseData1->anonymous_5 = 0x10;
	mouseData1->anonymous_6 = 0x10;
	mouseData1->anonymous_7 = 0x10;
	mouseData1->anonymous_8 = 0x10;
	mouseData1->anonymous_9 = 0x30;
	mouseData1->anonymous_10 = 0xC8;

	mouseData0->anonymous_0 = 0;
	mouseData0->anonymous_1 = 0;
	mouseData0->anonymous_2 = 2;
	mouseData0->mColumn = 160;
	mouseData0->mRow = 100;
	mouseData0->anonymous_5 = 0x10;
	mouseData0->anonymous_6 = 0x10;
	mouseData0->anonymous_7 = 0x10;
	mouseData0->anonymous_8 = 0x10;
	mouseData0->anonymous_9 = 0x30;
	mouseData0->anonymous_10 = 0xC8;

	g_Window.SetMousePosition( cPosition( 160, 100 ) );
}

void cFodder::mouse_GetData() {
	eventProcess();

	mouse_Pos_Column = (int16) mMousePosition.mX;
	mouse_Pos_Row = (int16) mMousePosition.mY;
	mouse_Button_Status = mMouseButtons;
}

void cFodder::mouse_Handle() {
	
	mouse_GetData();
	mouse_ButtonCheck();

	//g_Window.SetMousePosition( cPosition( 160, 100 ) );

	int16 dword_37AA4 = mouse_Pos_Column - 0x70;
	word_3BDB3 = dword_37AA4;

	dword_37AA4 += word_3BDAF;

	if ((word_3A024 == 0 && dword_37AA4 < -32 ) || dword_37AA4 < -16) {
		//loc_13B41
		if (word_3A024)
			dword_37AA4 = -16;
		else
			dword_37AA4 = -32;
	} else {
		//loc_13B58
		if (dword_37AA4 > 287)
			dword_37AA4 = 287;
	}

	//loc_13B66
	word_3BDAF = dword_37AA4;
	dword_37AA0 = mouse_Pos_Row - 88;

	word_3BDB5 = dword_37AA0;
	dword_37AA0 += word_3BDB1;

	if (dword_37AA0 < 4)
		dword_37AA0 = 4;
	else {

		if (dword_37AA0 > 203)
			dword_37AA0 = 203;
	}

	word_3BDB1 = dword_37AA0;
}

void cFodder::mouse_ButtonCheck() {

	mButtonPressLeft = 0;
	if (mouse_Button_Status & 1) {
		mButtonPressLeft -= 1;
		if (word_39EF8 == 0) {
			word_39EF8 = -1;
			word_39F02 = -1;

			if (word_39EF6) {
				word_39EFC = -1;
				word_3AA43 = -1;
			}
		}

	} else {
		word_3AA43 = 0;
		word_39EF8 = 0;
	}

	mButtonPressRight = 0;
	if (mouse_Button_Status & 2) {
		mButtonPressRight -= 1;
		if (word_39EFA == 0) {
			word_39F04 = -1;
			word_39EFA = -1;
		}
	} else {
		word_39EFA = 0;
	}

}

void cFodder::Prepare() {

	mWindow->InitWindow( "Open Fodder" );

	mDataPStuff = new uint8[0xA03 * 16];
	mDataBaseBlk = new uint8[0xFD0 * 16];
	mMap = new uint8[0x346 * 16];
	mDataSubBlk = new uint8[0xFD0 * 16];
	mDataHillBits = new uint8[0xD5A * 16];
	mDataArmy = new uint8[0xD50 * 16];
	word_3BDAD = (int16*) new uint8[0x258 * 16];
	mMapSptPtr = (uint16*) new uint8[0x258 * 16];

	Load_File("setup.dat");
	sub_12AB1();
	//Resource_Data_Open();
	//Load_EffectDriver();
	//Load_MusicDriver();
	memory_XMS_Detect();
}

void cFodder::sub_13800() {

	videoSleep();
}

void cFodder::paletteLoad( uint8* pBuffer, uint16 pColors, uint16 pColorID ) {
		size_t colorStartID = pColorID;

	if( pColors >= g_MaxColors )
		pColors = g_MaxColors-1;

	for(; pColorID < pColors + colorStartID; pColorID++) {
		
		// Get the next color values
		mPalette[ pColorID ].mRed =		*pBuffer++;
		mPalette[ pColorID ].mGreen =	*pBuffer++;
		mPalette[ pColorID ].mBlue =	*pBuffer++;
	}
}

void cFodder::sub_13C1C( cSurface* pImage, int32 pParam00, int32 pParam0C, int32 pParam04, int32 pParam08 ) {

	uint16 bx = mSpriteDataPtr[pParam00][pParam04].field_0;

	word_42062 = GetSpriteData( mSpriteDataPtr[pParam00][pParam04].field_2 ) + bx;

	mDrawSpritePositionX = (pParam08 + 0x10) - 16;
	mDrawSpritePositionY = pParam0C + 0x10;
	word_4206C = mSpriteDataPtr[pParam00][pParam04].mColCount;
	word_4206E = mSpriteDataPtr[pParam00][pParam04].mRowCount;
	if (word_3B307 > pParam00) 
		word_3B307 = pParam00;
	
	byte_42070 = (uint8) mSpriteDataPtr[pParam00][pParam04].field_C;
	
	if (sub_1429B() )
		video_Draw_Sprite_( pImage );

}

void cFodder::sub_13C8A( cSurface* pImage, int16 pData0, int16 pData4, int16 pPosX, int16 pPosY ) {
	uint16 bx = mSpriteDataPtr[pData0][pData4].field_0;

	word_42062 = GetSpriteData( mSpriteDataPtr[pData0][pData4].field_2 ) + bx;
	
	mDrawSpritePositionX = (pPosX + 0x10) - 16;
	mDrawSpritePositionY = pPosY + 0x10;
	word_4206C = mSpriteDataPtr[pData0][pData4].mColCount;
	word_4206E = mSpriteDataPtr[pData0][pData4].mRowCount;
	byte_42070 = mSpriteDataPtr[pData0][pData4].field_C;
	word_42078 = 0x140;

	if (sub_1429B())
		video_Draw_Linear_To_Planar( pImage );
}

void cFodder::video_Draw_Sprite_( cSurface* pImage ) {
	uint8*	di = pImage->GetSurfaceBuffer();
	uint8* 	si = word_42062;
	int16	ax, cx;
	
	di += 320 * mDrawSpritePositionY;

	ax = mDrawSpritePositionX;
	ax += word_40054;
	//ax >>= 2;
	
	di += ax;
	word_42066 = di;
	cx = mDrawSpritePositionX;
	cx += word_40054;
	cx &= 3;

	uint8 Plane = 0;

	byte_42071 = 1 << cx;
	byte bl = byte_42070;
	
	word_4206C >>= 1;
	word_42074 = 0xA0 - word_4206C;
	word_4206C >>= 1;
	
	word_42076 = 320 - (word_4206C*4);
	
	di += Plane;
	for( int16 dx = word_4206E; dx > 0; --dx ) {
		
		for( cx = 0; cx < word_4206C; ++cx ) {
			byte al = (*si) >> 4;
			if(al)
				*di = al | bl;
			
			si += 2;
			di+=4;
		}
		
		si += word_42074;
		di += word_42076;
	}

	++Plane;
	if (Plane == 4) {
		Plane = 0;
		++word_42066;
	}

	si = word_42062;
	di = word_42066;
	di += Plane;
	for( int16 dx = word_4206E; dx > 0; --dx ) {
		
		for( cx = word_4206C; cx > 0; --cx ) {
			byte al = (*si) & 0x0F;
			if( al )
				*di = al | bl;
			
			si += 2;
			di+=4;
		}
		
		si += word_42074;
		di += word_42076;
	}

	++Plane;
	if (Plane == 4) {
		Plane = 0;
		++word_42066;
	}
	
	++word_42062;
	si = word_42062;
	di = word_42066;
	di += Plane;
	for( int16 dx = word_4206E; dx > 0; --dx ) {
		
		for( cx = word_4206C; cx > 0; --cx ) {
			
			byte al = (*si) >> 4;
			if( al )
				*di = al | bl;
			
			si += 2;
			di+=4;
			
		}
		si += word_42074;
		di += word_42076;
	}

	++Plane;
	if (Plane == 4) {
		Plane = 0;
		++word_42066;
	}

	si = word_42062;
	di = word_42066;
	di += Plane;
	for( int16 dx = word_4206E; dx > 0; --dx ) {
		
		for( cx = word_4206C; cx > 0; --cx ) {
			
			byte al = (*si) & 0x0F;
			if( al ) 
				*di = al | bl;
			
			si += 2;
			di+=4;
		}
		
		si += word_42074;
		di += word_42076;
	}

	pImage->draw();
}

void cFodder::video_Draw_Linear_To_Planar( cSurface* pImage ) {
	uint8*	di = pImage->GetSurfaceBuffer();
	uint8* 	si = word_42062;
	int16	ax, cx;
	
	di += 320 * mDrawSpritePositionY;

	ax = mDrawSpritePositionX;
	ax += word_40054;
	//ax >>= 2;
	
	di += ax;
	word_42066 = di;
	cx = mDrawSpritePositionX;
	cx += word_40054;
	cx &= 3;

	uint8 Plane = 0;

	byte_42071 = 1 << cx;
	word_42074 = word_42078 - word_4206C;
		                 
	//word_4206C >>= 1;
	word_42076 = 320 - word_4206C;

	di += Plane;
	for( int16 dx = word_4206E; dx > 0; --dx ) {
		
		for( cx = word_4206C; cx > 0; --cx ) {
			byte al = *si;
			if(al)
				*di = al;
			
			si ++;
			di ++;
		}

		si += word_42074;
		di += word_42076;
	}

	pImage->draw();
	return;
	/*
	++Plane;
	if (Plane == 4) {
		Plane = 0;
		++word_42066;
	}
	
	++word_42062;
	si = word_42062;
	di = word_42066;
	
	di += Plane;
	for( int16 dx = word_4206E; dx > 0; --dx ) {
		
		for( cx = 0; cx < word_4206C; ++cx ) {
			byte al = *si;
			if(al)
				*di = al;
			
			si += 3;
			di ++;
		}
		
		si += word_42074;
		di += word_42076;
	}

	++Plane;
	if (Plane == 4) {
		Plane = 0;
		++word_42066;
	}
	
	++word_42062;
	si = word_42062;
	di = word_42066;
	di += Plane;
	for( int16 dx = word_4206E; dx > 0; --dx ) {
		
		for( cx = 0; cx < word_4206C; ++cx ) {
			byte al = *si;
			if(al)
				*di = al;
			
			si += 3;
			di ++;
		}
		
		si += word_42074;
		di += word_42076;
	}

	++Plane;
	if (Plane == 4) {
		Plane = 0;
		++word_42066;
	}
	
	++word_42062;
	si = word_42062;
	di = word_42066;
	di += Plane;
	for( int16 dx = word_4206E; dx > 0; --dx ) {
		
		for( cx = 0; cx < word_4206C; ++cx ) {
			byte al = *si;
			if(al)
				*di = al;
			
			si += 3;
			di ++;
		}
		
		si += word_42074;
		di += word_42076;
	}
	
	pImage->draw();*/
}

bool cFodder::sub_1429B() {
	int16 ax;
	
	if( mDrawSpritePositionY < 0 ) {
		ax = mDrawSpritePositionY + word_4206E;
		--ax;
		if( ax < 0 )
			return false;
		
		ax -= 0;
		ax -= word_4206E;
		++ax;
		ax = -ax;
		mDrawSpritePositionY += ax;
		word_4206E -= ax;
		ax *= 0xA0;
		word_42062 += ax;
	}
	
	ax = mDrawSpritePositionY + word_4206E;
	--ax;
	if( ax > 0xE7 ) {
		if( mDrawSpritePositionY > 0xE7 )
			return false;
		
		ax -= 0xE7;
		word_4206E -= ax;
		
	}

	if( mDrawSpritePositionX < 0 ) {
		ax = mDrawSpritePositionX + word_4206C;
		--ax;
		if( ax < 0 )
			return false;
		
		ax -= 0;
		ax -= word_4206C;
		++ax;
		ax = -ax;
		--ax;
		
		while( ax & 3 )
			++ax;
		
		mDrawSpritePositionX += ax;
		word_4206C -= ax;
		ax >>= 1;
		word_42062 += ax;
	}

	ax = mDrawSpritePositionX + word_4206C;
	--ax;
	
	if( ax > 320 ) {
		if( mDrawSpritePositionX > 320 )
			return false;
		
		ax -= 320;
		--ax;
		
		do {
			++ax;
		} while (ax & 3);
		
		word_4206C -= ax;
	}

	if( word_4206C <= 0 )
		return false;
	
	if( word_4206E <= 0 )
		return false;
	
	return true;
}

void cFodder::sub_144A2( cSurface* pImage ) {
	
	uint8*	Buffer = pImage->GetSurfaceBuffer();
	uint8* 	si = (uint8*) mMapSptPtr;

	Buffer += 16 * 320; // 0x584
	byte_42071 = 1 << word_40054;

	word_42066 = Buffer;
	for (unsigned int Plane = 0; Plane < 4; Plane++) {

		Buffer = word_42066;

		for (unsigned int Y = 0; Y < 200; ++Y) {

			for (unsigned int X = Plane; X < 0x30; X += 4) {

				Buffer[X] = *si++;
			}
			
			Buffer += 320;
		}
	}

	pImage->draw();
}

void cFodder::sub_145AF( int16 pData0, int16 pData8, int16 pDataC ) {
	const struct_2* str2 = &stru_44B50[pData0];
	
	int16 cx = str2->field_4;
	int16 dx = str2->field_6;
	word_4206C = cx;
	word_4206E = dx;
	
	uint16 ax = 0xA0 * str2->field_2;
	uint16 bx = str2->field_0 >> 1;
	ax += bx;
	
	word_42062 = mDataPStuff + ax;
	
	byte_42070 = 0xF0;
	
	uint16 w42066 = 0x0C * pDataC;
	w42066 += pData8 >> 2;
	
	ax = pData8 & 3;
	ax *= 0x960;
	w42066 += ax;
	
	uint8* di = ((uint8*)mMapSptPtr) + w42066;
	uint8* si = word_42062;
	
	byte bl = byte_42070;
	word_4206C >>= 1;
	
	word_42074 = 0xA0 - word_4206C;
	word_4206C >>= 1;
	word_42076 = 0x0C - word_4206C;
	
	for( uint16 dx = word_4206E; dx > 0; --dx ) {
		
		for( uint16 cx = word_4206C; cx > 0; --cx ) {
			
			uint8 al = (*si) >> 4;
			if( al )
				*di = al | bl;
			
			si += 2;
			++di;
		}
			
		si += word_42074;
		di += word_42076;
	}

	w42066 += 0x960;
	if( w42066 >= 0x2580 )
		w42066 -= 0x257F;
	
	si = word_42062;
	di =  ((uint8*)mMapSptPtr) + w42066;
	
	for( uint16 dx = word_4206E; dx > 0; --dx ) {
		
		for( uint16 cx = word_4206C; cx > 0; --cx ) {
			uint8 al = (*si) & 0x0F;
			if( al )
				*di = al | bl;
			
			si += 2;
			++di;
		}
		
		si += word_42074;
		di += word_42076;
	}
		
	w42066 += 0x960;
	if( w42066 >= 0x2580 )
		w42066 -= 0x257F;
	
	++word_42062;
	si = word_42062;
	di =  ((uint8*)mMapSptPtr) + w42066;
	
	for( uint16 dx = word_4206E; dx > 0; --dx ) {
		
		for( uint16 cx = word_4206C; cx > 0; --cx ) {
			
			uint8 al = (*si) >> 4;
			if( al )
				*di = al | bl;
			
			si += 2;
			++di;
		}
			
		si += word_42074;
		di += word_42076;
	}

	w42066 += 0x960;
	if( w42066 >= 0x2580 )
		w42066 -= 0x257F;

	si = word_42062;
	di =  ((uint8*)mMapSptPtr) + w42066;
	
	for( uint16 dx = word_4206E; dx > 0; --dx ) {
		
		for( uint16 cx = word_4206C; cx > 0; --cx ) {
			uint8 al = (*si) & 0x0F;
			if( al )
				*di = al | bl;
			
			si += 2;
			++di;
		}
		
		si += word_42074;
		di += word_42076;
	}

}

void cFodder::Briefing_Intro_Jungle( cSurface* pImage ) {
	
	int16 word_4286F = 0;
	int16 word_42871 = 0;
	int16 word_42873 = 0;
	int16 word_42875 = 0;

	word_42062 = (uint8*) word_4286B;

	byte_42070 = 0xE0;


	sub_1590B();

	paletteLoad( (word_42861 + word_4286D) - 0x300, 0x100, 0 );

	pImage->paletteSet( mPalette );

	int16 Faded = -1;

	do {
		if (word_428D6 == -1)
			sub_159A6();

		if( Faded == -1 )
			Faded = pImage->paletteFade();

		// Clouds
		word_42859 = 0x30;
		word_4285B = 320 * 36;// 0x0C64;
		sub_15B86( pImage, word_42867, word_42875 );

		word_42859 = 0x38;
		word_4285B = 320 * 46; //80;	//0x102C
		sub_15A36( pImage, word_42865, word_42873 );

		word_42859 = 0x12;
		word_4285B = 320 * 85; //96;	//0x1D3C
		sub_15A36( pImage, word_42863 , word_42871 );

		// Trees (Main)
		word_42859 = 0x5C;
		word_4285B = 320 * 103;	// 0x236C
		sub_15B86( pImage, word_42869, word_42871 );

		word_42062 = ((uint8*) word_4286B) + word_428CE[word_428CC / 2];

		mDrawSpritePositionX = mHelicopterPosX >> 16;		// X
		mDrawSpritePositionY = mHelicopterPosY >> 16;		// Y 
		word_4206C = 0x40;
		word_4206E = 0x18;
		if (sub_1429B())
			video_Draw_Sprite_( pImage );

		word_42859 = 0x2D;
		word_4285B = 320 * 151; //0x33EC
		sub_15A36( pImage, word_42861, word_4286F );

		word_4286F += 8;
		if (word_4286F > 0x140)
			word_4286F = 0;

		word_42871 += 4;
		if (word_42871 > 0x140)
			word_42871 = 0;

		word_42873 += 2;
		if (word_42873 > 0x140)
			word_42873 = 0;

		++word_42875;
		if (word_42875 > 0x140)
			word_42875 = 0;

		videoSleep();
		g_Window.RenderAt( pImage, cPosition() );
		g_Window.FrameEnd();

		mouse_GetData();
		if (mouse_Button_Status) {
			word_428D8 = 0;
			pImage->paletteFadeOut();
			Faded = -1;
		}
	} while (word_428D8 != 0 || Faded == -1);
}

void cFodder::sub_1590B() {
	mHelicopterPosX = 0x01500000;
	mHelicopterPosY = 0x00260000;

	word_428C6 = word_428DC[0];
	word_428C4 = word_428DC[1];
	word_428C8 = word_428DC[2];
	word_428CA = &word_428DC[3];
	word_428CC = 0;
	word_428D6 = -1;
	word_428D8 = -1;

	sub_1594F();
}

void cFodder::sub_159A6() {
	word_428B6 &= 0x1FE;
	uint16 bx = word_428B6;

	int32 ax = word_3EABF[ (bx / 2) & 0xFF ];

	ax >>= 2;

	mHelicopterPosX += ax* word_428B8;

	bx += 0x80;
	bx &= 0x1FE;

	ax = word_3EABF[ (bx / 2) & 0xFF];
	ax >>= 2;
	mHelicopterPosY += ax * word_428B8;

	bx = word_428C6 - word_428B6;
	bx >>= 5;
	--bx;
	bx ^= 0x0F;
	bx &= 0x0F;

	int16 al = byte_3E98F[bx];
	al <<= 2;
	word_428B6 += al;
	word_428B6 &= 0x1FE;

	if (word_428C4 != word_428B8) {
		if (word_428B8 >= word_428C4)
			word_428B8 -= 4;
		else
			word_428B8 += 4;
	}

	word_428CC += 2;
	if (word_428CC == 8)
		word_428CC = 0;

	--word_428BA;
	if (word_428BA <= 0)
		sub_1594F();

}

void cFodder::sub_1594F() {

	word_428B6 = word_428C6;
	word_428B8 = word_428C4;
	word_428BA = word_428C8;
	word_428C6 = *word_428CA++;
	word_428C4 = *word_428CA++;
	word_428C8 = *word_428CA++;

	if (word_428B6 == -1) {
		word_428D6 = 0;
		word_428D8 = 0;

		paletteLoad( (word_42861 + word_4286D) - 0x300, 0x100, 0 );
	}

}

void cFodder::sub_15A36( cSurface* pImage, uint8* pDs, int16 pCx ) {
	int16 ax = pCx >> 2;
	int16 dx = ax;

	ax -= 0x50;
	word_4285F = -ax;

	word_4285D = pImage->GetSurfaceBuffer() + word_4285B + (dx*4) + 4;
	pCx &= 3;
	int8 ah = 1;
	ah << pCx;

	++dx;
	
	uint8* di = word_4285D;

	
	for (uint8 Plane = 0; Plane < 4; ++Plane) {
		di = word_4285D + Plane;

		for (int16 bx = word_42859; bx > 0; --bx) {
			int16 cx;
			for (cx = word_4285F; cx > 0; --cx) {
				uint8 al = *pDs++;
				if (al)
					*di = al;

				di += 4;
			}

			di -= 0x51 * 4;
			--pDs;
			for (cx = dx; cx > 0; --cx) {
				uint8 al = *pDs++;
				if (al)
					*di = al;

				di += 4;
			}

			di += 0x50 * 4;
		}
	}

	pImage->draw();
}

void cFodder::sub_15B86( cSurface* pImage, uint8* pDs, int16 pCx ) {

	if (word_3E75B != 0)
		sub_15B98( pImage, pDs, pCx );
	else
		sub_15CE8( pImage, pDs, pCx );
}

void cFodder::sub_15B98( cSurface* pImage, uint8* pDsSi, int16 pCx ) {
	int16 ax = pCx >> 2;
	int16 dx = ax;

	ax -= 0x50;
	word_4285F = -ax;

	word_4285D = pImage->GetSurfaceBuffer() + word_4285B + (dx*4);
	pCx &= 3;
	int8 ah = 1;
	ah << pCx;

	++dx;
	
	uint8* di = word_4285D;

	for (uint8 Plane = 0; Plane < 4; ++Plane) {
		di = word_4285D + Plane;

		for (int16 bx = word_42859; bx > 0; --bx) {
			int16 cx = word_4285F;

			if (cx & 1) {
				*di = *pDsSi++;
				di += 4;
			}

			cx >>= 1;
			while (cx > 0) {
				*di = *pDsSi++;
				di += 4;

				*di = *pDsSi++;
				di += 4;

				--cx;
			}

			cx = dx;
			di -= 0x51 * 4;
			--pDsSi;
			if (cx & 1) {
				*di = *pDsSi++;
				di += 4;
			}

			cx >>= 1;
			while (cx > 0) {
				*di = *pDsSi++;
				di += 4;

				*di = *pDsSi++;
				di += 4;

				--cx;
			}
			di += 0x50 * 4;
		}
	}
	
	pImage->draw();
}

void cFodder::sub_15CE8( cSurface* pImage, uint8* pDs, int16 pCx ) {
	//todo
}

void cFodder::Mission_Brief() {

	map_Load_Resources();
	Sprite_SetDataPtrToBase( off_42918 );
	//video_Draw_unk_0();

	cSurface* Image = new cSurface( 320, 230 );

	sub_15DF0( Image );
	//video_unk_0_1();
	sub_15DF0( Image );

	switch (mMap_TileSet) {
	case 0:
		Briefing_Intro_Jungle( Image );
		break;

	case 1:
		//sub_15397();
		break;

	case 2:
		//sub_151C6();
		break;

	case 3:
		//sub_15568();
		break;

	case 4:
		//sub_15739();
		break;
	}

	delete Image;
	g_Resource.fileLoadTo( "pstuff.dat", mDataPStuff );
}

void cFodder::map_Load_Resources() {
	std::string MapName = map_Filename_MapGet();
	std::string JunData1 = "p1.dat";
	std::string JunData2 = "p2.dat";
	std::string JunData3 = "p3.dat";
	std::string JunData4 = "p4.dat";
	std::string JunData5 = "p5.dat";

	g_Resource.fileLoadTo( MapName, mMap );

	map_SetTileType();

	JunData1.insert( 0, mMapTypes[mMap_TileSet] );
	JunData2.insert( 0, mMapTypes[mMap_TileSet] );
	JunData3.insert( 0, mMapTypes[mMap_TileSet] );
	JunData4.insert( 0, mMapTypes[mMap_TileSet] );
	JunData5.insert( 0, mMapTypes[mMap_TileSet] );

	size_t DataBaseBlkSize = g_Resource.fileLoadTo( JunData1, mDataBaseBlk );
	word_42861 = mDataBaseBlk;
	word_4286D = DataBaseBlkSize;

	g_Resource.fileLoadTo( JunData2, mDataSubBlk );
	word_42863 = mDataSubBlk;
	
	g_Resource.fileLoadTo( JunData3, mDataHillBits );
	word_42865 = mDataHillBits;

	g_Resource.fileLoadTo( JunData4, mDataArmy );
	word_42867 = mDataArmy;

	g_Resource.fileLoadTo( JunData5, mDataPStuff );
	word_42869 = mDataPStuff;

	g_Resource.fileLoadTo( "paraheli.dat", (uint8*) mMapSptPtr );
	word_4286B = mMapSptPtr;

	uint8* si = ((uint8*)mMapSptPtr) + 0xF00;
	si += 0x30 * mMap_TileSet;

	memcpy( (word_42861 + DataBaseBlkSize) - 0x60, si, 0x30 );
	memcpy( (word_42861 + DataBaseBlkSize) - 0x30, mDataPStuff + 0xA000, 0x30 );
}

void cFodder::sub_15DF0( cSurface* pImage ) {

	word_3A01A = 0xB5;
	Briefing_Draw_MissionName( pImage );
}

void cFodder::Briefing_Draw_MissionName( cSurface* pImage ) {
	
	std::stringstream Mission;
	Mission << "MISSION ";

	word_3AC19 = 0x25;
	Mission << tool_StripLeadingZero( tool_NumToString( mMissionNumber ) );

	String_CalculateWidth( 0x140, byte_4382F, Mission.str().c_str() );
	String_Print( pImage, byte_4382F, 1, word_3B301, 0, Mission.str().c_str() );
	
	int16 Data0 = mMissionNumber;
	const char** Data20 = mMapNames;

	if (word_3A01A != 0xB5) {
		Data20 = mMapPhaseNames;
		Data0 = mMapNumber + 1;
	}

	Data0 -= 1;
	Data20 += Data0;

	String_CalculateWidth( 0x140, byte_4382F, *Data20 );
	Data0 = mMissionNumber;
	Data20 = mMapNames; 
	if (word_3A01A != 0xB5) {
		Data20 = mMapPhaseNames;
		Data0 = mMapNumber + 1;
	}
	Data0 -= 1;
	Data20 += Data0;
	String_Print( pImage, byte_4382F, 1, word_3B301, word_3A01A, *Data20 );
}

void cFodder::Recruit_Show() {
	
	mouse_Setup();
	map_ClearSpt();
	
	cSurface* ImageHill = new cSurface(320,230);
	
	word_3E1B7 = mDataBaseBlk;
	g_Resource.fileLoadTo( "hill.dat", mDataBaseBlk );
	paletteLoad( word_3E1B7 + 0xFA00, 0x50, 0x00 );

	g_Resource.fileLoadTo( "hillbits.dat", mDataHillBits );
	paletteLoad( mDataHillBits + 0x6900, 0x10, 0xB0 );

	dword_3B1FB = stru_373BA;
	word_3AAD1 = -1;
	word_3AB39 = -1;
	
	Sprite_SetDataPtrToBase( mHillBitsSpriteSheetPtr );

	sub_16BC3();
	sub_16C6C();
	Recruit_Render_LeftMenu( ImageHill );
	Recruit_Draw_Hill( ImageHill );
	
	sub_17B64();
	
	Sprite_SetDataPtrToBase( off_35E42 );
	
	sub_17CD3( ImageHill );

	ImageHill->Save();
	ImageHill->paletteSet( mPalette );

	word_3BEC1 = 0;
	word_3BEC3 = 0x1D;
	//word_39020 = 0;
	
	sub_17368();
	
	dword_3AAC9 = mDataSubBlk;
	
	for (int16 ax = word_397D4 - 1; ax >= 0;--ax )
		sub_17429();
	
	word_3AA51 = -1;
	word_3A016 = 0;
	word_3AA67 = 0;
	word_3AA71 = word_397D2;
	
	sub_1787C();

	Recruit_Draw_Actors( ImageHill );
	Recruit_Draw_Actors( ImageHill );
	
	word_39F02 = 0;
	
	for( ;; ) {
		if( word_39F02 ) {
			word_39F02 = 0;
			
			if( sub_18C7A() )
				break;
		}

		Recruit_Draw( ImageHill );
	}
	
	word_3A9F7 = 0x23;
	word_3AA51 = 0;
	
	ImageHill->paletteFadeOut();
	
	while( ImageHill->GetFaded() == false ) {
		Recruit_Draw( ImageHill );
	}
	
	delete ImageHill;
}

void cFodder::Recruit_Draw_Hill( cSurface* pImage ) {
	word_42062 = word_3E1B7 + 0xA00;
	
	mDrawSpritePositionX = 0x30;
	mDrawSpritePositionY = 0x28;
	word_4206C = 0x110;
	word_4206E = 0xB0;
	word_42078 = 0x140;
	
	video_Draw_Linear_To_Planar( pImage );
	
	for( uint32 x = 0; x < 0xA000; ++x) {
		word_3E1B7[x] = 0;
	}
}

void cFodder::Recruit_Draw_HomeAway( cSurface* pImage ) {
	const char* strHomeAndAway = "HOME                AWAY";
	
	Sprite_SetDataPtrToBase( mHillBitsSpriteSheetPtr );
	
	sub_13C1C( pImage, 0x18, 0, 0, 0 );
	
	int16 Data4 = word_3E0E5[ (mMissionNumber - 1) ];

	sub_13C1C( pImage, 0x19, 0, Data4, 0x130 );
	
	String_CalculateWidth( 320, mUnkStringModifier_Recruit, strHomeAndAway );
	String_Print( pImage, mUnkStringModifier_Recruit, 0x0D, word_3B301, 0x0A, strHomeAndAway );
	
	sub_13C1C( pImage, 0x0E, 0x0A, 0, 0x9B );
	
	std::string Home = tool_StripLeadingZero(tool_NumToString( word_397AE ));
	sub_16B55( pImage, 0x0D, 0x9A - (Home.length() * 0x0C), 0x0A, Home );

	std::string Away = tool_StripLeadingZero(tool_NumToString( word_397AC ));
	sub_16B55( pImage, 0x0D, 0xAA, 0x0A, Away );

	Sprite_SetDataPtrToBase( off_35E42 );
}

void cFodder::sub_16B55( cSurface* pImage, int16 pParam0, int16 pParam8, int16 pParamC, const std::string& pString ) {

	for ( std::string::const_iterator Text = pString.begin(); Text != pString.end(); ++Text, pParam8 += 0x0C) {
		char NextChar = *Text;

		if (NextChar == 0x20)
			continue;

		if (NextChar <= 0x39) {
			NextChar -= 0x30;
			NextChar += 0x1A;
		}
		else
			NextChar -= 0x41;

		sub_13C1C( pImage, pParam0, pParamC, NextChar, pParam8 );
	}
}

void cFodder::sub_16BC3() {
	int16* di = word_3BDAD;	// 20h
	int16  ax = word_397D2;
	int16  count;
	
	if( ax > 0 ) {
		
		sub_16C45( &di, word_3E115 );
		count = word_397D2;
		count -= 2;

		while( count >= 0 ) {
			sub_16C45( &di, word_3E135 );
			--count;
		}
		
		sub_16C45( &di, word_3E12B );
		sub_16C45( &di, word_3E15D );
	}

	*di++ = 0;
	*di = -1;
}

void cFodder::sub_16C45( int16** pDi, int16* pSource ) {
	int16 ax;
	
	for(;;) {
		ax = *pSource++;
		
		if( ax < 0 )
			break;
		
		**pDi = ax;
		(*pDi)++;
	}	
}

void cFodder::sub_16C6C() {
	int16 *si = word_391D2;
	
	while( *si != -1 ) {
		uint8* si1 = (uint8*) si;
		
		*(si1+1) += 1;
		++si;
	}
}

void cFodder::sub_17C91( cSurface *pImage, int16 pData0, int16 pData8, int16 pDataC ) {
	pData0 >>= 1;
	if (pData0 > 8)
		pData0 = 0;

	int16 Data4 = pDataC;
	Data4 -= 0x14;
	Data4 >>= 5;
	if (Data4 >= 5)
		Data4 = 4;

	pDataC -= 8;
	sub_13C1C( pImage, pData0, pDataC, Data4, pData8 );
}

void cFodder::sub_17CD3( cSurface* pImage ) {
	int16 Data0 = 1440;
	int32 Data1C = -1;
	int16* Data24 = word_391D2;

	for(; *Data24 >= 0 ; ++Data24) {
		Data0 -= 4;
		Data1C++;
	}

	if (Data24 == word_391D2)
		return;

	--Data24;
	int16* Data20 = word_3E1B9 + (Data0 / 2);

	do {
		Data0 = *Data24;
		if (Data0 < 0)
			return;

		--Data24;
		int16 Data8 = *Data20++;
		int16 DataC = *Data20++;

		sub_17C91( pImage, Data0, Data8, DataC );

		--Data1C;
	} while (Data1C >= 0);

}

void cFodder::Recruit_Render_LeftMenu( cSurface *pImage ) {
	int16 Data0 = 0xAD;
	int16 Data8 = 0;
	int16 DataC	= 0x18;
	
	// Draw Heroes Heading
	sub_145AF( Data0, Data8, DataC );
	
	sHero* Data20 = mHeroes;
	int16 Data14 = 0x0E;
	Data0 = 4;
	
	for( sHero* Data20 = mHeroes; Data0 >= 0; --Data0, ++Data20  ) {
		if( Data20->mRecruitID == -1 )
			break;
		
		Data14 += 0x0C;
	}

	// Draw Empty Hero Slots
	DataC = 0x0E;
	do {
		
		Data0 = 0xA9;
		if( DataC >= Data14 )
			Data0 = 0xAB;
		
		Data8 = 0;
		sub_145AF( Data0, Data8, DataC + 0x18 );
		DataC += 0x0C;
		
	} while( DataC < 0x4A );

	//seg003:1E89

	// Draw Squad Heading
	Data0 = 0xAE;
	Data8 = 0;
	DataC = 0x4A + 0x18;
	sub_145AF( Data0, Data8, DataC );
	
	Data14 = word_397D2 + word_397D4;
	Data14 /= 0x0C;
	DataC = 0x58;
	Data14 += DataC;

	// Draw Used Slot into Temporary Area
	do {
		Data0 = 0xA9;
		if( DataC >= Data14 )
			Data0 = 0xAB;

		Data8 = 0;
		sub_145AF( Data0, Data8, DataC + 0x18 );
		DataC += 0x0C;
		
	} while( DataC < 0xA0 );

	word_3BEC9 = 0xB8;
	word_3AA55 = 0x0F;
	word_3AAC7 = -1;

	Recruit_Render_Squad_RankKills();
	Recruit_Render_Squad_Names();
	
	word_3AAC7 = 0;
	word_3AA55 = -59;
	
	Recruit_Render_HeroList();
	word_3AA55 = 0;
}

void cFodder::Recruit_Render_Squad_Names() {

	word_3A3BB = 7;
	word_3A3BD = 0;
	
	for( uint16 x = 0; x < 8; ++x, --word_3A3BB ) {
		sSquad_Member* Data2C = &mSquad[x];
		
		int16 Data0 = Data2C->field_4;
		
		if( Data0 == -1 )
			continue;
		
		int16* Data20 = mMapSpt_Loaded;

		int16* si = Data20 + Data0;
		if( word_39FD0 != si[0x19])
			continue;

		sRecruit* Data28 = &mRecruits[Data2C->mRecruitID];
		int16 Data14;

		for( Data14 = 0; Data14 <= 5; ++Data14 ) {
			
			if( Data28->mName[Data14] == 0x20 )
				break;
			
		} 
		
		Data0 = Data14;
		Data14 <<= 2;
		int16 word_3A05F = (0x30 - Data14) >> 1;

		if( word_3AAC7 )
			word_3A05F -= 1;
		
		// Draw Troop name to list
		for( Data14 = 0; Data14 <= 5; ++Data14 ) {
			
			if( Data28->mName[Data14] != 0x20 ) {
				Data0 = Data28->mName[Data14];
				Data0 -= 0x41;
				Data0 += 0x29;
				
				int16 Data8 = Data14;
				Data8 <<= 2;
				Data8 += word_3A05F;
				int16 DataC = 0x4B;
				DataC += word_3A3BD;
				DataC += word_3AA55;

				sub_145AF( Data0, Data8, DataC + 0x19 );
			}
		}

		word_3A3BD += 0x0C;
	}

}

void cFodder::Recruit_Render_Squad_RankKills() {
	int16 Data0;
	int16* Data34 = mMapSpt_Loaded;

	int16 word_3A061 = 7;
	word_3A3BD = 0;
	
	int16 Data4;
	
	for( uint16 x = 0; x < 8; ++x, --word_3A061 ) {
		sSquad_Member* Data38 = &mSquad[x];

		if( Data38->field_4 == -1 )
			continue;
		
		Data4 = word_39FD0;
		int16* si = Data34 + Data38->field_4;
		
		if( Data4 != si[0x19]  )
			continue;
		
		int16 Data8 = 0;
		int16 DataC = word_3A3BD;
		DataC += 0x4A;
		DataC += word_3AA55;
		
		if( !word_3AAC7 ) {
			Data0 = 0;
			Data0 = Data38->mRank;
			Data0 += 9;
			Data8 = 0x23;
			DataC = word_3A3BD;
			DataC -= 1;
			DataC += 0x4A;
			DataC += word_3AA55;
			DataC += 0x19;
			
			sub_145AF( Data0, Data8, DataC );
			
			DataC -= 0x19;
			
		} else {
			// Draw Kills
			sub_170A4( Data38->mNumberOfKills, 0x43 );
			
		}
		
		//Draw Rank
		Data0 = Data38->mRank + 9;
		DataC = word_3A3BD - 1;

		DataC += 0x4A;
		DataC += word_3AA55;
		DataC += 0x19;
		sub_145AF( Data0, 0, DataC );
		DataC -= 0x19;
		word_3A3BD += 0x0C;
	}
}

void cFodder::sub_170A4( int16 pData4, int16 pData10 ) {
	
	pData10 -= 0x30;
	std::string Data20 = tool_StripLeadingZero(tool_NumToString( pData4 ));
	uint16 Data0 = (uint16) Data20.length() * 4;

	int16 Data8 = 0x30 - Data0;
	int16 DataC = 0x4B + word_3A3BD + word_3AA55;

	for (std::string::iterator CharIT = Data20.begin(); CharIT != Data20.end(); ++CharIT) {

		Data0 = (*CharIT & 0xFF) + pData10;
		sub_145AF( Data0, Data8, DataC + 0x19 );
		Data8 += 4;
	}
}

void cFodder::Recruit_Render_HeroList() {
	const sHero* Hero = mHeroes;

	word_3A3BB = 4;
	word_3A3BD = 0;

	for (word_3A3BB = 4; word_3A3BB >= 0; --word_3A3BB, ++Hero) {

		if (Hero->mRecruitID < 0)
			continue;

		int16 Data8 = 0;
		int16 DataC = word_3A3BD - 1;
		DataC += 0x4A + word_3AA55+ 0x19;

		sub_145AF( Hero->mRecruitID + 9, Data8, DataC );

		sRecruit* Troop = &mRecruits[ Hero->mRecruitID ];

		int16 Position;
		for( Position = 0; Position <= 5; ++Position ) {
			
			if( Troop->mName[Position] == 0x20 )
				break;
		} 

		Position <<= 2;
		word_3A05F = (0x30 - Position) >> 1;
		--word_3A05F;

		for (Position = 0; Position <= 5; ++Position) {

			uint8 Character = Troop->mName[Position];
			if (Character == 0x20)
				continue;

			Character -= 0x41;
			Character += 0x29;
			Data8 = Position;
			Data8 <<= 2;
			Data8 += word_3A05F;
			DataC += 0x4B;
			DataC += word_3A3BD + word_3AA55;

			sub_145AF( Character, Data8, DataC  + 0x19 );
		}

		sub_170A4( Hero->mKills, 0x67 );
		word_3A3BD += 0x0C;
	}
}

void cFodder::sub_17368() {
	uint32* Data20 = (uint32*) mDataArmy;

	uint16* Data24 = (uint16*) mDataSubBlk;

	for ( int16 Data0 = 0x58; Data0 < 0xA0; Data0 += 0x0C) {
		*((uint32*)Data24) = (uint32) Data20;
		Data24 += 2;

		*Data24++ = Data0;

		sub_17480( Data0, 0x0C, 0, Data20 );
	}

	//seg003:2532
	*Data24 = -1;
	int16 DataC = 0x58;

	for (int16 Data4 = 5; Data4 >= 0; --Data4) {
		sub_145AF( 0xAC, 0, DataC + 0x18 );

		DataC += 0x0C;
	}
}

void cFodder::sub_17429() {
	uint8* Data24 = dword_3AAC9;

	if (*((uint32*)Data24) < 0)
		return;

	uint8* Data20 = (uint8*) *((uint32*)Data24);
	Data24 += 4;

	uint16 Data0 = *((uint16*)Data24);
	Data24 += 2;

	dword_3AAC9 = Data24;
	uint32* Dataa20 =  (uint32*) Data20;
	sub_17480( Data0, 0x0C, -1, Dataa20 );
}

void cFodder::sub_17480( uint16 pData0, int16 pData4, int16 pData8, uint32*& pData20 ) {
	pData0 += 0x18;

	uint8* SptPtr = (uint8*)mMapSptPtr;

	if (pData8 == 0) {
		uint32* esi = (uint32*)(SptPtr + (0x0C * pData0));

		for (int16 cx = pData4; cx > 0; --cx) {
			*pData20++ = *esi;
			*pData20++ = *(esi + 0x258);
			*pData20++ = *(esi + 0x4B0);
			*pData20++ = *(esi + 0x708);
			++esi;

			*pData20++ = *esi;
			*pData20++ = *(esi + 0x258);
			*pData20++ = *(esi + 0x4B0);
			*pData20++ = *(esi + 0x708);
			++esi;

			*pData20++ = *esi;
			*pData20++ = *(esi + 0x258);
			*pData20++ = *(esi + 0x4B0);
			*pData20++ = *(esi + 0x708);
			++esi;
		}
	}
	else {
		uint32* edi = (uint32*)(SptPtr + (0x0C * pData0));

		for (int16 cx = pData4; cx > 0; --cx) {
			*edi = *pData20++;
			*(edi+0x258) = *pData20++;
			*(edi+0x4B0) = *pData20++;
			*(edi+0x708) = *pData20++;
			++edi;
			*edi = *pData20++;
			*(edi+0x258) = *pData20++;
			*(edi+0x4B0) = *pData20++;
			*(edi+0x708) = *pData20++;
			++edi;
			*edi = *pData20++;
			*(edi+0x258) = *pData20++;
			*(edi+0x4B0) = *pData20++;
			*(edi+0x708) = *pData20++;
			++edi;
		}
	}
}

void cFodder::Recruit_Draw_Actors( cSurface* pImage ) {
	sMouseData* bp = mouseData1 + 1;

	word_42072 = 2;

	Recruit_Draw_Truck( pImage );
	Recruit_Draw_Troops( pImage );

	bp = mouseData1;
	bp->anonymous_0 = 0;
	bp->anonymous_2 = word_42072;
}

void cFodder::sub_175C0() {
	struct_4* Data20 = 0;

	if (word_3B1F1 > 0) {

		struct_4* Data20 = &stru_373BA[293];
		do {
			if (Data20 == &stru_373BA[0])
				return;

			--Data20;

		} while (Data20->field_4 == 0 || Data20->field_4 < 4);

		int16 Data0 = Data20->field_4;
		Data20->field_4 = 0;
		Data0 ^= 1;

		if ((Data20 + 1)->field_0 >= 0) {
			(Data20 + 1)->field_4 = Data0;
		} else {
			--word_3B1F1;
			sub_17429();
		}
	}
	//loc_17652

	uint16 aa = ~(dword_3B1CB >> 16);

	dword_3B1CB = (aa << 16) | (dword_3B1CB & 0xFFFF);

	Data20 = &stru_373BA[293];
	struct_4* Data28 = &stru_373BA[271];

loc_17686:;
	for (; Data20 != &stru_373BA[0];) {
		--Data20;

		if (Data20->field_4 == 0)
			continue;

		if (Data20->field_4 < 4)
			continue;

		if (Data20 >= Data28)
			continue;

		int16 Data8 = 3;
		struct_4* Data30 = Data20;
		//loc_176CE

		do {
			++Data30;
			if (Data30->field_4) {
				if (Data30->field_4 > 3)
					goto loc_17686;

				++Data30;
			}
			--Data8;
		} while (Data8 >= 0);

		int16 Data0 = Data20->field_4;
		Data20->field_4 = 0;
		if ((dword_3B1CB >> 16) < 0)
			Data0 ^= 1;

		if ((Data20 + 1)->field_4) {
			(Data20 + 2)->field_4 = Data0;
		}
		else {
			(Data20 + 1)->field_4 = Data0;
		}
	}

}

void cFodder::Recruit_Draw_Troops( cSurface *pImage ) {

	if (word_3B1EF) {
		sub_175C0();
	}
	else {
		sub_178DD();
		sub_17911();
	}

	struct_4* Data20 = stru_373BA;
	struct_4* dword_3B1C7;

	for ( ; ;Data20 = dword_3B1C7) {

		dword_3B1C7 = Data20;

		if (Data20->field_0 < 0)
			break;

		int16 Data0;
		int16 Data8 = Data20->field_0;
		int16 DataC = Data20->field_2;
		int16 Data4 = Data20->field_4;
		++Data20;
		dword_3B1C7 = Data20;
		if (Data4 == 0)
			continue;

		--Data4;
		if (Data4 >= 3) {
			//loc_177E3
			Data4 -= 3;
			Data0 = 0x0A;
			Data0 += Data4;

			if (DataC >= 0xB7)
				Data0 += 4;
			else if (DataC > 0x7C )
				Data0 += 2;

			Data4 = 0;

			if (Data20 > &stru_373BA[0x46]) {
				Data4 = 1;

				if (Data20 > &stru_373BA[0x7A])
					Data4 = 2;
			}
		}
		else
			Data0 = 9;

		//loc_1784C
		DataC -= 8;
		if (Data0 != 9)
			sub_13C1C( pImage, Data0, DataC, Data4, Data8 );
		else {
			++Data8;
			--DataC;
			sub_13C8A( pImage, Data0, Data4, Data8, DataC );
		}
	}
}

void cFodder::sub_1787C() {
	
	if (word_390B8)
		return;
	
	word_3B1F1 = word_397D2;
	word_3B1EF = 0;

	int16 Data0 = 0xB4;
	int16* Data20 = word_3B1CF;
	const int16* Data24 = word_3E177;

	for ( int16 Data4 = 0x0E; Data4 >= 0; --Data4 ) {

		*Data20++ = Data0;
		Data0 -= *Data24++;

	}
}

void cFodder::sub_178DD() {
	struct_4* Data20 = stru_373BA;

	for (; Data20->field_0 >= 0; ++Data20) {
		
		if (Data20->field_4 >= 4)
			Data20->field_4 = 0;
	}
}

void cFodder::sub_17911() {
	struct_4* Data24 = stru_373BA;
	int16*    Data2C = word_3E197;

	uint32 Data8 = (uint32) dword_394A4;
	int16 Data0;

	Data8 -= (uint32) word_391D2;
	Data8 >>= 1;
	Data8 &= 0x1E;

	if (word_390B8)
		Data0 = word_390CE;
	else {
		Data0 = word_390E8;
		if (!Data0)
			goto loc_179B2;
	}

	// loc_1795E
	--Data0;
	int16 Data4 = 0x660;

	//loc_17968
	for (; Data0 >= 0; --Data0) {

		if (Data4 >= 0) {
			if ((Data24 + (Data4/6))->field_4)
				Data4 -= 6;

			(Data24 + (Data4/6))->field_4 = *(Data2C + (Data8/2));
		}

		Data8 += 2;
		Data8 &= 0x1F;
		Data4 -= 0x18;
	}

loc_179B2:;
	if (word_390B8)
		return;

	word_3B1ED = 0;
	Data0 = word_3B1CF[0];
	Data8 = 5;

	for ( ; ; Data0+=6 ) {

		Data4 = (Data24 + (Data0/6))->field_4;
		if (Data4) {
			if (Data4 > 3) {
				word_3B1ED = -1;
				break;
			}
			else
				continue;
		}
		else {
			if (Data0 == 0x660) {
				word_3B1ED = -1;
				break;
			}
			--Data8;
			if (!Data8)
				break;
		}
	}
	//seg003:2B6D
	if (!word_3B1ED) {
		dword_3B1CB += 0x8000;
		dword_3B1CB &= 0x1FFFF;
	}
	else
		dword_3B1CB = 0x10000;

	int16* Data20 = word_3B1CF;

	for (int16 DData8 = 0x0E; DData8 >= 0; --DData8) {

		Data0 = *Data20;
		if (Data0 >= 0) {
			Data4 = (dword_3B1CB >> 16);

			Data4 += *Data2C++;
			if ((Data24 + (Data0/6))->field_0 < 0)
				Data0 = 0;

			if ((Data24 + (Data0/6))->field_4)
				Data0 += 6;

			(Data24 + (Data0/6))->field_4 = Data4;
		}
		// 17A9D

		if (!word_3B1ED)
			Data0 += 6;

		//loc_17AA9
		*Data20 = Data0;
		++Data20;
	}

	if (word_3B1ED)
		word_3B1EF = -1;
}

void cFodder::Recruit_Draw_Truck( cSurface* pImage ) {
	int16 Data0 = 0x22;
	int16 Data4 = word_3AACD;
	int16 Data8 = 0x31;
	int16 DataC = 0xB6;

	sub_13C1C( pImage, Data0, DataC, Data4, Data8 );

	if (!word_3B1EF)
		return;

	int16* Data20 = word_3BDAD;

	Data0 = *(Data20 + word_3AACF);
	if (Data0 < 0)
		return;

	++word_3AACF;
	word_3AACD = Data0;
}

void cFodder::sub_17B64() {

	const struct_3* stru = stru_35C70;

	for (; stru->field_0 != -1;) {
		int16 word_3B19F = stru->field_0;
		int16 word_3B1A1 = stru->field_2;
		int16 word_3B1A3 = stru->field_4;
		int16 word_3B1A5 = stru->field_6;
		int16* Data34 = stru->field_8;

		for (;;) {
			int16 Data0 = word_3B19F;
			int16 Data4 = word_3B1A1;
			int16 Data8 = word_3B1A3;
			int16 DataC = word_3B1A5;

			uint8* Data20 = sub_2AE81( &Data0, &Data4 );

			Data8 = *Data34++;
			if (Data8 < 0) {
				++stru;
				break;
			}

			sub_2AEB6( Data0, Data4, &Data8, &DataC );
			int16 Data10 = word_3B1A3 + 0x08;
			int16 Data14 = word_3B1A5;
			sub_2AF19( Data0, Data4, Data8, Data10, Data14, DataC, Data20 );
			word_3B1A3 += 0x10;
		}
	}

}

void cFodder::Recruit_Draw( cSurface *pImage ) {
	eventProcess();
	mouse_Handle();

	Recruit_Draw_Actors( pImage );
	sub_144A2( pImage );
	Recruit_Draw_HomeAway( pImage );
	//Mouse_DrawCursor();
	sub_13800();

	if (pImage->GetFaded() == false )
		pImage->paletteFade();

	mDrawSpritePositionX = 0x40;
	mDrawSpritePositionY = 0x28;
	word_4206C = 0x110;
	word_4206E = 0xB0;

	//sub_14367();

	g_Window.RenderAt( pImage, cPosition() );
	g_Window.FrameEnd();
	pImage->Restore();
}

uint8* cFodder::GetSpriteData( uint16 pSegment ) {
	
	switch ( pSegment ) {
		case 0x4307:
			return mDataPStuff;
			break;

		case 0x4309:
			return mDataHillBits;
			break;

		case 0x6717:
			return word_3E1B7;
			break;

		default:
			std::cout << "Invalid Sprite\n";
			break;
	}
	return 0;
}

bool cFodder::sub_18C7A() {
	word_3B2FD = 0;
	word_3B2FF = 0;

	if (word_3BDAF <= -16 && word_3BDB1 <= 26) {
		word_3B2FD = -1;
		return true;
	}

	if (word_3BDAF >= 0x10F) {
		if (word_3BDB1 > 0x1A)
			return true;

		if (word_3E0E5[mMissionNumber-1])
			return true;

		return false;
	}

	if (word_3BDB1 < 0x1A)
		return false;

	return true;
}

void cFodder::sub_22B71( sSprite_0* pSprite ) {
	
	if (!pSprite->field_66)
		return;

	int16* Data28 = (int16*)pSprite->field_66;
	
	int16 Data0 = *(Data28);
	Data0 += 0x10;

	if (*(Data28 + 0x37) || *(Data28 + 0x37) == 1)
		Data0 -= 0x0C;

	int16 Data4 = *(Data28 + 2);
	Data4 -= 9;
	int16 Data8 = pSprite->field_0;
	Data8 += 4;
	int16 DataC = pSprite->field_4;

	int16 Data10 = 0x1F;
	sub_2A74F( Data0, Data4, Data8, Data10, DataC );
	
	if (Data0 >= 0x0D)
		return;

	pSprite->field_6A = (int32) Data28;
	pSprite->field_6E = -1;
	sub_305D5();

	sSprite_0** Data24 = off_3BDEF[pSprite->field_32];
	sSprite_0* eax = Data24[0];

	if (eax != pSprite)
		return;

	word_3B461[pSprite->field_32] = 0x190;
}

void cFodder::sub_29E30( int16& pData0, int16& pData4, int16& pData8, int16& pDataC ) {
	const int16* Data24 = word_3ECC0;

	pData8 -= pData0;
	if (pData8 < 0)
		pData8 = -pData8;

	if (pData8 >= 0x140)
		goto loc_29EBB;

	pDataC -= pData4;
	if (pDataC < 0)
		pDataC = -pDataC;

	if (pDataC >= 0x140)
		goto loc_29EBB;

	int16 Data10 = 0;
	for (;;) {
		if (pData8 <= 0x1F)
			if (pDataC <= 0x1F)
				break;

		pData8 >>= 1;
		pDataC >>= 1;
		++Data10;
	}
	//loc_29E8C
	pDataC <<= 5;
	pDataC |= pData8;
	pData0 = 0;

	pData0 = Data24[pDataC];
	pData0 <<= Data10;
	return;

loc_29EBB:;
	pData0 = 0x3E8;
}

int16 cFodder::sub_2A030() {
	int16 Data0 = word_44A2E;
	int16 Data2 = word_44A30;
	int16 Data4 = word_44A32;
	int16 Data6 = word_44A34;
	
	uint32 Dat4 = Data4 | (Data6 << 16);

	uint8 CF = Data4 & 1;
	int32 Data8 = Data0 | (Data2 << 16);

	Data8 >>= 1;
	uint8 CF2 = Data8 & 1;

	Data8 >>= 1;
	if (CF)
		Data8 |= 0x80000000;

	Dat4 += CF2;
	Data4 = Dat4 & 0xFFFF;
	Data6 = Dat4 >> 16;

	for (uint16 cx = 0x0C; cx > 0; --cx) {
		CF = 0;

		if (Data0 & 0x8000)
			CF = 1;
		Data0 <<= 1;
		Data2 <<= 1;
		if (CF)
			Data2 |= 1;
	}

	int16 DataA = Data8 >> 16;

	//seg007:0575
	Data0 ^= Data8;
	Data2 ^= DataA;
	Data8 = Data0;
	DataA = Data2;

	//seg007:058F
	int16 ax = Data8;
	int16 bx = DataA;
	Data8 = bx;
	DataA = ax;

	Data8 >>= 4;
	Data0 ^= Data8;

	word_44A2E = Data0;
	word_44A30 = Data2;
	word_44A32 = Data4;
	word_44A34 = Data6;

	Data2 = 0;
	return Data0;
}

void cFodder::sub_2A0FA( sSprite_0* pSprite ) {
	word_3B173 = 0;
	if (!pSprite->field_36)
		return;

	//loc_2A10D
	const int16* Data24 = word_3EABF;
	pSprite->field_10 &= 0x1FE;
	int16 Data4 = pSprite->field_10;

	int16 Data8 = *(Data24 + Data4);

	Data4 += 0x80;
	Data4 *= 0x1FE;
	int16 DataC = *(Data24 + Data4);
	Data8 >>= 2;
	DataC >>= 2;
	//seg007:064F

	int32 DataaC = (int32)DataC;
	int32 Dataa8 = (int32)Data8;

	Data4 = pSprite->field_36;
	Dataa8 *= Data4;

	DataaC *= Data4;

	int32 tmp = pSprite->field_0 | pSprite->field_2 << 16;
	tmp += Dataa8;
	if (tmp < 0) {
		tmp = 0;
		word_3B173 = -1;
	}
	pSprite->field_0 = tmp & 0xFFFF;
	pSprite->field_2 = tmp >> 16;

	tmp = pSprite->field_4 | pSprite->field_6 << 16;
	tmp += DataaC;
	if (tmp < 0) {
		tmp = 0;
		word_3B173 = -1;
	}
	pSprite->field_4 = tmp & 0xFFFF;
	pSprite->field_6 = tmp >> 16;
}

int16 cFodder::sub_2A1F0( sSprite_0* pSprite, int16& pData0, int16& pData4 ) {
	const int16 *Data24 = word_3F0C1;

	pData0 -= pSprite->field_0;
	pData4 -= pSprite->field_4;

	int16 Data10 = 0;
	if (pData0 < 0)
		Data10 = 1;
	Data10 = -Data10;

	if (pData0 < 0)
		pData0 = -pData0;

	int16 Data14 = 0;
	if (pData4 < 0)
		Data14 = 1;
	Data14 = -Data14;

	if (pData4 < 0)
		pData4 = -pData4;

	word_3A8D5 = pData0;
	word_3A8D7 = pData4;
	int16 Data8 = 0x1F;
	int16 DataC = 0;
	if (pData0 <= Data8)
		if (pData4 <= Data8)
			goto loc_2A2F5;

	//seg007:0755
	++DataC;
	Data8 <<= 1;
	++Data8;

	//loc_2A283
	for (;;) {
		if (pData0 <= Data8)
			if (pData4 <= Data8)
				break;
		++DataC;
		Data8 <<= 1;
		++Data8;
		if (pData0 <= Data8)
			if (pData4 <= Data8)
				break;

		++DataC;
		Data8 <<= 1;
		++Data8;
		if (pData0 <= Data8)
			if (pData4 <= Data8)
				break;

		++DataC;
		Data8 <<= 1;
		++Data8;
	}
	//loc_2A2E5
	pData0 >>= DataC;
	pData4 >>= DataC;

loc_2A2F5:;
	pData4 <<= 5;
	pData4 |= pData0;
	//pData4 <<= 1;
	pData4 = Data24[pData4];
	if (pData4 < 0) {
		word_3B25B = -1;
		return -1;
	}

	pData4 <<= 1;
	if (Data10 < 0) {
		//loc_2A376
		if (Data14 >= 0) {
			pData4 += 0x180;
			pData4 &= 0x1FE;
			pSprite->field_10 = pData4;

		}
		else {
			//loc_2A39F
			pData0 = 0x180;
			pData0 -= pData4;
			pData0 &= 0x1FE;
			pSprite->field_10 = pData0;
		}

		word_3B25B = 0;
		return 0;
	}

	//seg007:0804
	if (Data14 >= 0) {
		pData0 = 0x80;
		pData0 -= pData4;
		pData0 &= 0x1FE;
		pSprite->field_10 = pData0;
		word_3B25B = 0;
		return 0;
	}

	//loc_2A354
	pData4 += 0x80;
	pData4 &= 0x1FE;
	pSprite->field_10 = pData4;
	word_3B25B = 0;
	return 0;
}

void cFodder::sub_2A3D4( sSprite_0* pSprite ) {
	
	word_3A8CF = 0;
	pSprite->field_3E -= 1;
	if (pSprite->field_3E >= 0)
		return;

	pSprite->field_3E = 1;
	int16 Data8 = pSprite->field_3C;
	int16 Data0 = pSprite->field_10;

	Data0 >>= 5;
	Data0 -= 1;
	Data0 ^= 0x0F;
	Data0 &= 0x0E;
	int16 Data4 = Data0;
	Data4 &= 0x0F;
	
	int16 DataC = Data8;
	DataC -= Data4;
	DataC &= 0x0F;
	//seg007:0920
	DataC = (int16) byte_3E98F[DataC];
	DataC <<= 1;

	word_3A8CF = DataC;
}

int16 cFodder::sub_2A4A2( int16& pData0, int16& pData4, int16& pData8, int16& pDataC ) {
	pData0 >>= 4;
	pData4 >>= 4;
	pData8 >>= 4;
	pDataC >>= 4;

	int16 Data18 = 2;

	uint8* es = mMap;

	int16 Data1C = readLEWord( &mMap[0x54] );
	Data1C <<= 1;

	word_3A9A6[0] = pData0;
	word_3A9A6[1] = pData4;

	sub_2A4FD( pData0, pData4, pData8, pDataC, Data18, Data1C );
	
	return sub_2A622( pData0 );
}

void cFodder::sub_2A4FD( int16& pData0, int16&  pData4, int16& pData8, int16& pDataC, int16& pData18, int16& pData1C ) {
	uint8* Data20 = byte_3A8DE;

	int16 Data10 = pData8;
	Data10 -= pData0;

	int16 Data14 = pDataC;
	Data14 -= pData4;
	
	int16 Data28 = pData8;
	int16 Data2C = pDataC;

	int16 Data24, Data38;

	if (Data10 < 0) {
		pData18 = -pData18;
		Data24 = pData18;
		Data10 = -Data10;
		pData18 = -1;
	}
	else {
		Data24 = pData18;
		pData18 = 1;
	}
	//loc_2A56A

	if (Data14 < 0) {
		pData1C = -pData1C;
		Data38 = pData1C;
		Data14 = -Data14;
		pData1C = -1;
	}
	else {
		Data38 = pData1C;
		pData1C = 1;
	}
	//loc_2A59D
	pData8 = 0;
	if (Data14 == 0)
		pData8 = 1;
	else
		pData8 = 0;

	pData8 = -pData8;

loc_2A5BA:;
	if (Data28 == pData0 && Data2C == pData4){
		Data20[0] = -1;
		Data20[1] = -1;
		Data20[2] = -1;
		Data20[3] = -1;
		return;
	}

	if (pData8 >= 0) {
		pData4 += pData1C;
		pData8 -= Data10;
		writeLEWord( Data20, Data38 );
		Data20 += 2;
		goto loc_2A5BA;
	}
	//loc_2A601
	pData0 += pData18;
	pData8 += Data14;
	writeLEWord( Data20, Data24 );
	Data20 += 2;
	goto loc_2A5BA;
}

int16 cFodder::sub_2A622( int16& pData0 ) {
	
	pData0 = word_3A9A6[0];
	int32 Data4 = word_3A9A6[1];

	uint8* Data20 = &mMap[0x60];

	Data4 *= readLEWord( &mMap[0x54] );
	Data4 += pData0;
	Data4 <<= 1;

	Data20 += Data4;
	//seg007:0B48

	uint8* Data28 = byte_3A8DE;
	int16 *Data2C = word_3C09D;
	uint8* Data30 = byte_3D4A5;
	word_3B2CB = -1;

	for (;;) {
		if (word_3B2CB) {
			word_3B2CB = 0;
			goto loc_2A6D7;
		}
		//loc_2A6A1
		pData0 = readLEWord( Data20 );
		pData0 = readLEWord( Data20 + pData0 );
		if (pData0 >= 0) {
			pData0 &= 0x0F;

			if (Data30[pData0]) {
				pData0 = -1;
				return -1;
			}
		}

	loc_2A6D7:;
		if (readLEDWord( Data28 ) == -1) {
			pData0 = 0;
			return 0;
		}
		pData0 = readLEWord( Data28 );
		Data28 += 2;
		if (pData0 == 0)
			goto loc_2A728;

		if (readLEDWord( Data28 ) == 0)
			goto loc_2A728;

		if (readLEWord( Data28 ) == 0)
			goto loc_2A728;

		Data20 += pData0;
		pData0 = readLEWord( Data28 );
		Data28 += 2;

	loc_2A728:;
		Data20 += pData0;

	}
}

void cFodder::sub_2A74F( int16& pData0, int16& pData4, int16& pData8, int16& pData10, int16& pDataC ) {
	const int16* Data24 = word_3ECC0;

	pData8 -= pData0;
	if (pData8 < 0)
		pData8 = -pData8;

	if (pData8 >= pData10)
		goto loc_2A7DB;

	pDataC -= pData4;
	if (pDataC < 0)
		pDataC = -pDataC;

	if (pDataC >= pData10)
		goto loc_2A7DB;

	pData10 = 0;
	for (;;) {
		if (pData8 <= 0x1F)
			if (pDataC <= 0x1F)
				break;

		pData8 >>= 1;
		pDataC >>= 1;
		++pData10;
	}
	//loc_2A7AD
	pDataC <<= 5;
	pDataC |= pData8;
	pData0 = 0;

	// TODO: Verify the /2
	pData0 = Data24[pDataC / 2];
	pData0 <<= pData10;

	return;

loc_2A7DB:;
	pData0 = 0x3E8;
}

int16 cFodder::sub_2A7E2( int16& pData0, int16& pData4 ) {
	int16 Data10 = pData0;
	int16 Data14 = pData4;

	return sub_2A839( pData0, pData4, Data10, Data14 );
}

int16 cFodder::sub_2A7F7( sSprite_0* pSprite, int16& pData0, int16& pData4 ) {

	pData0 += pSprite->field_4;
	if (pData0 >= 0) {
		
		int16 Data14 = pData0;
		pData4 += pSprite->field_0;
		if (pData4 >= 0) {
			int16 Data10 = pData4;

			return sub_2A839( pData0, pData4, Data10, Data14 );
		}
	}

	pData0 = -1;
	pData4 = 0;
		
	return 0;
}

int16 cFodder::sub_2A839( int16& pData0, int16& pData4, int16& pData10, int16& pData14 ) {
	pData0 >>= 4;

	uint8* es = mMap;

	uint32 Data0 = pData0 * readLEWord( &es[0x54] );
	pData4 >>= 4;

	Data0 += pData4;
	Data0 <<= 1;

	Data0 = es[0x60 + Data0] & 0x1FF;
	//Data0 <<= 1;

	int16* Data24 = word_3C09D;
	Data24 += Data0;

	int16 Data4 = *Data24;
	if (Data4 < 0) {
		//loc_2A8D9
		pData10 >>= 1;
		pData10 &= 0x07;

		int16 Data8 = 7;
		Data8 -= pData10;

		pData14 >>= 1;
		pData14 &= 0x07;

		Data0 <<= 2;
		int8* Data28 = (int8*) graphicsBaseBht;
		pData4 += Data0;

		byte al = 1 << Data8;
		Data28 += pData14;
		if (*Data28 & al)
			pData4 >>= 4;
	}

	Data4 &= 0x0F;
	pData0 = byte_3D4A5[Data4];

	return pData0;
}

uint8* cFodder::sub_2AE81( int16 *pData0, int16 *pData4 ) {
	const sSpriteSheet* Sheet = &mSpriteDataPtr[*pData0][*pData4];

	*pData0 = Sheet->mColCount;
	*pData4 = Sheet->mRowCount;

	return GetSpriteData( Sheet->field_2 ) + Sheet->field_0;
}
 
void cFodder::sub_2AF19( int16 pData0, int16 pData4, int16 pData8, int16 pData10, int16 pData14, int16 pDataC, uint8* pData20 ) {
	pData0 &= 0xFFFF;
	pData4 &= 0xFFFF;

	uint8 *si = pData20;
	uint8* es = word_3E1B7;

	dword_44A36 = (pData10 - (pData8 >> 1)) << 16;
	dword_44A3E = dword_44A36;

	dword_44A3A = (pData14 - (pDataC >> 1)) << 16;
	int32 eax = (pData8 << 0x10);
	if (eax <= 0)
		return;

	dword_44A42 = eax / pData0;
	eax = pDataC << 0x10;
	if (eax <= 0)
		return;

	dword_44A46 = eax / pData4;
	for (int16 bx = 0; bx != pData4; ++bx) {
		dword_44A36 = dword_44A3E;

		for (int16 cx = 0; cx != pData0; ++cx) {
			uint8 al = sub_2AFF5( si, bx, cx );
			sub_2B016( es, al );
			dword_44A36 += dword_44A42;
		}

		dword_44A3A += dword_44A46;
   	}

}

uint8 cFodder::sub_2AFF5( uint8* pSi, int16 pBx, int16 pCx ) {

	pSi += 0xA0 * pBx;
	pSi += (pCx >> 1);
	if (pCx & 1)
		return (*pSi) & 0x0F;

	return (*pSi) >> 4;
}

void cFodder::sub_2AEB6( int16 pData0, int16 pData4, int16* pData8, int16* pDataC ) {
	int32	Data = pData0 * *pData8;
	pData0 = (int16) Data / 0x64;
	
	int16 Final8 = pData0;
	
	Data = pData4 * *pData8;
	*pDataC = (int16) Data / 0x64;

	*pData8 = Final8;
}

void cFodder::sub_2B016( uint8* pDi, uint8 pAl ) {
	
	pDi += 0xA0 * (dword_44A3A >> 16); 
	pDi += (dword_44A36 >> 16) >> 1;

	if ((dword_44A36 >> 16) & 1) {
		*pDi &= 0xF0;
		*pDi |= pAl & 0x0F;
		return;
	}

	*pDi &= 0x0F;
	*pDi |= pAl << 4;
}

void cFodder::sub_2B04B( uint8* pTileGraphicPtr, uint16 pDestX, uint16 pDestY ) {
	uint8* Target = mSurfaceMapOverview->GetSurfaceBuffer();

	pDestX *= 16;

	Target += (pDestY * 16) * (mMapWidth*16);
	Target += pDestX;

	for (uint16 i = 0; i < 16; ++i) {

		memcpy( Target, pTileGraphicPtr, 16 );
		pTileGraphicPtr += 0x140;
		Target += (mMapWidth*16);
	}
}

void cFodder::sub_2D06C() {
	int16** Data34 = dword_3B48B;
	int8* Data24 = byte_3A05A;

	Data24[0] = 0;
	Data24[1] = 0;
	Data24[2] = 0;
	Data24[3] = 0;
	byte_3A05E = 0;

	int16 Data14 = 0;

	sSprite_0*** Data28 = off_3BDEF;
	sSquad_Member* Data2C = mSquad;
	int16 Data0 = -32768;
	sSprite_0* Data4 = (sSprite_0*) -1;

	dword_3BE03[0] = (sSprite_0*) -1;
	dword_3BE27[0] = (sSprite_0*) -1;
	dword_3BE4B[0] = (sSprite_0*) -1;
	dword_3BE6F[0] = (sSprite_0*) -1;
	dword_3BE93[0] = (sSprite_0*) -1;

	for (int8 Data1C = 8; Data1C >= 0; --Data1C, ++Data2C) {

		if (Data2C->field_4 < 0)
			continue;

		// This will need fixing (field_4, prob needs / 2)
		int16* Data20 = &mMapSpt_Loaded[ Data2C->field_4 ];

		sSprite_0* Sprite = (sSprite_0*)Data20;
		if (!(Sprite->field_75 & 2)) {
			if (Sprite->field_38 < 32) {
				if (Sprite->field_38) {
					if (!Sprite->field_6E)
						continue;

					Sprite->field_38 = 0;
				}
			}
		}
		//loc_2D165

		uint8 Data10 = Data24[ Sprite->field_32 ] & 0xFF;
		Data24[ Sprite->field_32 ] += 1;
		++Data14;

		sSprite_0** Data30 = Data28[ Sprite->field_32 ];
		//seg009:0151
		Data30[Data10] = Sprite;
		Data30[Data10 + 1] = Data4;
		*Data34 = (int16*)Sprite;
		++Data34;
	}
	//seg009:019E

	if (!Data14)
		word_3A9AA = -1;

	dword_3A8DB = byte_3A05A;
	byte_3A8DE[1] = byte_3A05E;

	Data0 = 2;
	int8* Data2CC = byte_3A05A;
	int8* Data30 = byte_3BF1B;

	do {

		int8 al = Data2CC[Data0];
		if (al)
			continue;

		Data30[Data0] = -1;
	} while (Data0 >= 0);

	Data34[0] = (int16*) -1;
	Data34[1] = (int16*) -1;
}

int16 cFodder::sub_2D91E( sSprite_0* pSprite ) {

	int16* Data24 = off_3BEF3[ pSprite->field_32 ];

	int16 Data0 = Data24[pSprite->field_40];

	if (Data0 >= 0) {
		int16 Data4 = Data24[pSprite->field_40 + 2];
		pSprite->field_26 = Data0;
		pSprite->field_28 = Data4;
		pSprite->field_40 += 4;
		pSprite->field_42 = -1;
	loc_2D9AB:;
		return 0;

	loc_2D9B4:;
		Data0 = -1;
		return -1;
	}

	//loc_2D9C0
	if (!pSprite->field_42)
		goto loc_2D9B4;

	pSprite->field_42 = 0;

loc_2D9D5:;
	int16 Data14 = pSprite->field_32;

	int16 Data18 = byte_3BF1B[Data14];
	if (Data18 < 0)
		goto loc_2D9B4;

	Data18 &= 0xFF;
	int8* Data2C = byte_3A05A + Data14;

	if (*Data2C > 8)
		goto loc_2D9B4;

	uint8* Dataa24 = (uint8*) pSprite->field_46;
	*(Dataa24 + 9) &= 0xFE;

	Data24 = off_3BEF3[Data18];
	Data0 = 0;

	for (;;) {

		int16 eax = *Data24;
		++Data24;
		if (eax < 0)
			break;

		Data0+=4;
	}
	//loc_2DA86
	pSprite->field_40 = Data0;
	pSprite->field_32 = Data18;
	sub_2D06C();

	word_3BEDF[Data14] = 0;
	word_39FD0 = Data18;
		
	word_3AA05[Data18] += word_3AA05[Data14];

	//seg010:0232
	word_3AA05[Data0] = 0;

	word_3AA0B[Data18] += word_3AA0B[Data0];
	word_3AA0B[Data0] = 0;
	sub_305D5();
	word_3AC2B = 0;
	word_3A8D9 = 0;
	goto loc_2D9B4;
}

void cFodder::video_Draw_Unk_2( cSurface* pImage ) {
	
}

void cFodder::map_ClearSpt() {
	
	for (uint16 cx = 0; cx < 4800; ++cx )
		mMapSptPtr[cx] = 0;
}

void cFodder::Briefing_Show( cSurface* pImage ) {
	const char* Brief = "BRIEFING";

	word_3AC19 = 0x25;

	String_CalculateWidth( 320, byte_4382F, Brief );
	String_Print( pImage, byte_4382F, 0x03, word_3B301, 0x4E, Brief );
	
	Briefing_DrawBox( pImage, 1, 0x47, 0x13B, 0x6B, 0xF3 );
	Briefing_DrawBox( pImage, 0, 0x46, 0x13D, 0x6B, 0xF2 );
	
	word_3AC19 = 0;

	std::stringstream Phase;

	Phase << "PHASE " << tool_StripLeadingZero( tool_NumToString( mMissionPhase + 1 ) );
	Phase << " OF " << tool_StripLeadingZero( tool_NumToString( mMissionPhases ));

	String_CalculateWidth( 320, byte_4388F, Phase.str().c_str() );
	String_Print( pImage, byte_4388F, 0, word_3B301, 0x1D, Phase.str().c_str() );
	
	sub_126DD();

	int16 DataC = 0x84;
	const char* Data20 = 0;
	const char** Data28 = mMissionGoals;
	int16* Data24 = mMapGoals;

	for (int16 Data0 = 7 ;Data0>=0; ++Data28, --Data0 ) {
		if (*Data24++) {

			Data20 = *Data28;
			String_CalculateWidth( 0x140, byte_4388F, Data20 );
			String_Print( pImage, byte_4388F, 0, word_3B301, DataC - 0x12, Data20 );
			DataC += 0x0C;
		}
	}
}

void cFodder::sub_18908() {
	cSurface* Image = new cSurface( 320, 230 );
	Image->paletteSet( mPalette );

	//video_Draw_unk_0();
	Sprite_SetDataPtrToBase( off_42918 );
	word_3A01A = 0x2C;

	Briefing_Draw_MissionName( Image );
	Briefing_Show( Image );

	do {
		g_Window.RenderAt( Image, cPosition() );
		g_Window.FrameEnd();
	} while (Image->paletteFade() == -1);

	delete Image;
}

void cFodder::Briefing_Wait() {
	cSurface* Image = new cSurface( 320, 230 );
	Image->paletteSet( mPalette, 0, true );

	Sprite_SetDataPtrToBase( off_42918 );

	word_3A01A = 0x2C;
	Briefing_Draw_MissionName( Image );
	Briefing_Show( Image );
	Briefing_Draw_With( Image );

	g_Window.RenderAt( Image, cPosition() );
	g_Window.FrameEnd();

	do {
		eventProcess();
		mouse_Handle();

		if (word_3A9B2 == -1) {
			word_3B4F5 = -1;
			break;
		}

	} while (!word_39F02);

	word_39F02 = 0;

	do {
		g_Window.RenderAt( Image, cPosition() );
		g_Window.FrameEnd();
	} while (Image->paletteFade() == -1);

	while (!mouse_Button_Status) {
		mouse_GetData();
	}

	mouse_Setup();
	delete Image;
}

void cFodder::Briefing_Draw_With( cSurface* pImage ) {
	std::stringstream With;
	
	With << "WITH ";
	With << tool_StripLeadingZero( tool_NumToString( mTroopsAvailable ) );

	if (mTroopsAvailable == 1) {
		With << " SOLDIER YOU MUST";
	}
	else {
		With << " SOLDIERS YOU MUST";
	}

	String_CalculateWidth( 0x140, byte_4388F, With.str().c_str() );
	String_Print( pImage, byte_4388F, 0, word_3B301, 0x64, With.str().c_str() );
	With.str("");

	if (!word_390CE) {
		With << "THIS IS YOUR LAST CHANCE";
	}
	else {
		With << word_390CE;
		if (word_390CE == 1)
			With << " RECRUIT REMAINING";
		else
			With << " RECRUITS REMAINING";
	}

	String_CalculateWidth( 0x140, byte_4388F, With.str().c_str() );
	String_Print( pImage, byte_4388F, 0, word_3B301, 0xA8, With.str().c_str() );
	
	String_CalculateWidth( 0x140, byte_4382F, "GO FOR IT" );
	String_Print( pImage, byte_4382F, 3, word_3B301, 0xB8, "GO FOR IT" );
}

void cFodder::Briefing_DrawBox( cSurface* pImage, int16 pData0, int16 pData4, int16 pData8, int16 pDataC, int16 pData10 ) {
	//pData0 += 0x10;
	pData4 += 0x10;

	int16 bx = pData0;
	int16 cx = pData4;

	int16 dx = bx + pData8;
	int16 si = pData10;

	// Top and Bottom
	Brief_Draw_Horizontal_Line( pImage, pData0, pData0 + pData8, pData4, pData10 );

	Brief_Draw_Horizontal_Line( pImage, pData0, pData0 + pData8, pData4 + pDataC, pData10 );

	// Sides of box
	Brief_Draw_Vertical_Line( pImage, pData0 * 4, pData4 + pDataC, pData4, pData10 );
	
	Brief_Draw_Vertical_Line( pImage, (pData0 + pData8 + 2) * 4, pData4 + pDataC, pData4, pData10 );
}

void cFodder::sub_18BDF( cSurface* pImage, int16 pBx, int16 pCx, uint8 pSi ) {
	uint8* di = pImage->GetSurfaceBuffer();

	di += 320 * pCx;
	di += pBx >> 2;
	pBx &= 3;

	di += pBx;
	*di = pSi;
}

void cFodder::Brief_Draw_Horizontal_Line( cSurface* pImage, int16 pBx, int16 pDx, int16 pCx, uint8 pSi ) {
	
	do {
		sub_18BDF( pImage, pBx, pCx, pSi );
		++pBx;
	} while ( pBx <= pDx * 4 );
}

void cFodder::sub_18C45( cSurface* pImage, int32 pPosY,  const sIntroString* pString ) {

	String_CalculateWidth( 320, mFontWidths, pString->mText );
	String_Print( pImage, mFontWidths, 0, word_3B301, pPosY, pString->mText );
}

void cFodder::Brief_Draw_Vertical_Line( cSurface* pImage, int16 pBx, int16 pDx, int16 pCx, uint8 pSi ) {
	
	do {
		sub_18BDF( pImage, pBx, pCx, pSi );
		++pCx;
	} while (pCx <= pDx );
}

void cFodder::sub_18D5E() {
	word_39FF4 -= 1;
	if (word_39FF4 < 0) {
		word_39FF4 = 3;

		word_39FF2 += word_3BEB9;
		if (word_39FF2 == 0 || word_39FF2 == 2)
			word_3BEB9 ^= -2;

		word_39FF6 += word_3BEBB;
		if (word_3BEBB == 0 || word_3BEBB == 2)
			word_3BEBB ^= -2;
	}

	//loc_18DA7
	word_39FF8 -= 1;
	if (word_39FF8 < 0) {
		word_39FF8 = 1;

		word_39FFA += word_3BEBD;
		if (word_39FFA == 0 || word_39FFA == 2)
			word_3BEBD ^= -2;
	}
}

void cFodder::sub_18DD3() {
	int16* Data20 = mMapSpt_Loaded;

	for (int16 Data1C = 0x2B; Data1C > 0; --Data1C, Data20 += 0x3B ) {
		
		if (*Data20 == -32768)
			continue;

		word_44A20 = *(Data20 + 0xC);
		int16 Data4 = *(Data20 + 0xC);

		switch (Data4) {
		case 0:
			sub_18E2E( Data20 );
			break;

		default:
			std::cout << "Function not implemented: " << Data4 << "\n";
			break;
		}
	}
}

void cFodder::sub_18E2E( int16 *pData20 ) {
	sSprite_0* Sprite = (sSprite_0*)pData20;

	if (Sprite->field_6E) {
		sub_22AA9( Sprite );
		return;
	}

	if (Sprite->field_75 & 2) {

		if (Sprite->field_38 <= 0x32)
			Sprite->field_38 = 0;

		Sprite->field_5B = 0;
		Sprite->field_64 = 0;
	}

	if (sub_1E05A( Sprite ))
		return;

	if (Sprite->field_38)
		return;

	if (sub_1F21E( Sprite ))
		return;

	//loc_18E8D
	sub_22B71( Sprite );
	word_3AA41 = 0;

	word_3AA1D = word_3BED5[Sprite->field_32];
	//seg004:0183

	if (byte_3BF1B[Sprite->field_32] < 0 && Sprite->field_32 != word_39FD0 ) {
		//loc_18F12
		//seg004:01C2
		word_3AA41 = -1;
		//Data0 <<= 1;   UNUSED?

		int16* Data28 = &mMapSpt_Loaded[ Sprite->field_5E / 2 ];
		
		if( *Data28 != -32768 ) {
			
			if( *(Data28 + 0x0C ) == 0x05 ) {
				if( *(Data28 + 0x1C ) == 0x00 ) {
				
					//seg004:021A 
					if( Sprite->field_4F == 0 ) {
						//seg004:0228
						int16 Data0 = Sprite->field_0;
						int16 Data4 = Sprite->field_4;
						
						int16 Data8 = *(Data28);
						int16 DataC = *(Data28 + 2);
						
						sub_29E30( Data0, Data4, Data8, DataC );
						if (Data0 < 0xD2) {

							if (Data0 <= 0x28)
								goto loc_1904A;

							//seg004:0270
							word_3AA4B = Data0;
							Data0 = Sprite->field_0;
							Data4 = Sprite->field_4;
							Data8 = *(Data28);
							DataC = *(Data28 + 2);

							if (sub_2A4A2( Data0, Data4, Data8, DataC ) == 0) {
								Data0 = word_3AA4B;
								goto loc_1904A;
							}
							if (word_3AA4B < 0x40)
								goto loc_1904A;
						}
					}
				}
			}
		}

	loc_1901C:;
		Sprite->field_4A = 0;
		Sprite->field_5E += 0x76;
		if (Sprite->field_5E < 0x13D2)
			goto loc_191C3;

		Sprite->field_5E = 0;
		goto loc_191C3;

	loc_1904A:;
		int16 Data0 = sub_2A030() & 0x1F;

		if (Data0 == 5)
			goto loc_1901C;

		Sprite->field_5A = -1;
		word_3A00C = 0;
		word_3A00E = 0;
		word_3A010 = 0;

		Sprite->field_2E = *(Data28);

		// WHAT THE?
		//seg004:0337
		Sprite->field_30 += 0x07;

		Sprite->field_30 = *(Data28 + 2);
		Sprite->field_30 -= 0x0E;

		if (Sprite->field_4A <= 0) {
			//loc_190B9
			sub_2A030();
			Data0 &= 0x0F;
			++Data0;
			Sprite->field_4A = Data0;
			sub_2A030();
			Data0 &= 0x3F;
			if (Data0 == 0x2A)
				goto loc_1918C;
		}
		
	loc_190E8:;
		word_3A00C = 0;
		word_3A00E = 0;
		word_3A010 = 0;

		if (Sprite->field_4F) {
			word_3A010 = -1;
			word_3A00E = -1;
			word_3A00C = -1;
		}
		else {
			//loc_19118
			int8* TmpData0 = (int8*) Sprite;
			TmpData0 -= 0x40;
			if (TmpData0 == word_39FCE && word_39EFC != 0) {

				Data0 = word_3AC3F[ Sprite->field_32 ];
				if (Data0 == 3) {
					word_3A00C = -1;
					word_3A00E = -1;
				} else {
					if (Data0 == 1) {
						word_3A010 = -1;
						word_3A00E = -1;
					}
					else
						goto loc_19198;
				}
			loc_1918C:;
				Sprite->field_4A = 1;
				goto loc_191BF;
			}

		loc_19198:;
			word_3A00C = -1;
			word_3A010 = -1;

			uint16* eax = (uint16*) Sprite->field_46;
			Data0 = *(eax + 3);

		loc_191BF:;
			sub_1F429();
		}
	}
	else {

		if (word_3A9CE) {
			goto loc_190E8;
			
		}
	}

loc_191C3:;
	if (Sprite->field_22)
		goto loc_1921E;

	//TODO: Check this
	// seg004:047F
	int16* Data30 = off_3BEF3[Sprite->field_32];
	int16*  Dat30 = &Data30[Sprite->field_40];
	int32   eax = readLEDWord( (Dat30 + 1) );

	//seg004:04CC
	if (eax < 0) {
	loc_1921E:;
		if (word_3AA41) {

			if (Sprite->field_0 == Sprite->field_26 &&
				 Sprite->field_4 == Sprite->field_28)
				 goto loc_1931E;
		}
	}
	//loc_1925C
	if (Sprite->field_54 != 2 && Sprite->field_54 != 1)
		goto loc_19338;

	//loc_19274
	if (word_3AA1D != 2)
		goto loc_1931E;

	word_3A399 = Sprite->field_A;
	Sprite->field_5A = 0;

	if (word_3AA41)
		sub_1F5A0( Sprite );
	else
		sub_1F5CA( Sprite );

	int16 Data0 = Sprite->field_26;
	if( Data0 < 0 )
		goto loc_1946D;
	
	int16 Data4 = Sprite->field_28;
	if( Data4 < 0 )
		goto loc_1946D;
	
	sub_1F623( Sprite );
	
	if( sub_2A1F0( Sprite, Data0, Data4 ) >= 0 ) {
		sub_1F66F( Sprite );
		sub_1F6F4();
	}
		
	Data0 = Sprite->field_0;
	if( Data0 == Sprite->field_26 ) {
		Data0 = Sprite->field_4;
		
		if( Data0 == Sprite->field_28 )
			sub_2D91E( Sprite );
	}
	//loc_19314
	if( word_3ABAD == 0 )
		return;
	
	loc_1931E:;
	
	if( Sprite->field_5A )
		goto loc_19403;
	
	sub_1F5CA( Sprite );
	sub_1F762( Sprite );
	return;
	
	loc_19338:;
	Sprite->field_43 = 0;
	word_3A399 = Sprite->field_A;
	word_3A9C6 = 0;
	
	sub_1FCF2();
	Data0 = Sprite->field_26;
	if( Data0 < 0 )
		goto loc_1946D;
	Data4 = Sprite->field_28;
	if( Data4 < 0 )
		goto loc_1946D;
	
	if( Sprite->field_44 ) {
		Sprite->field_44 -= 1;
		goto loc_193D6;
		
	} 
	
	//loc_19392
	if( sub_2A1F0( Sprite, Data0, Data4 ) >= 0 )
		goto loc_193D6;
	

	if( Sprite->field_0 == Sprite->field_26 ) {
		if( Sprite->field_4 == Sprite->field_28 )
			sub_2D91E( Sprite );
	}
	//loc_193D3
	goto loc_1946D;
	
loc_193D6:;
	sub_1F623( Sprite );
	sub_2A3D4( Sprite );
	
	if( !Sprite->field_5A ) {
		if( !Sprite->field_45 )
			goto loc_19424;
		
		Sprite->field_45 -= 1;
		return;
	}
	
loc_19403:;
	Sprite->field_5A = 0;
	sub_1FDE7( Sprite );
	return;
	
loc_19414:;
	Sprite->field_5A = 0;
	sub_1F5CA( Sprite );
	return;
	
loc_19424:;
	sub_1F6F4();
	
	if( Sprite->field_0 == Sprite->field_26 ) {
		
		if( Sprite->field_4 == Sprite->field_28 )
			sub_2D91E( Sprite );
		
	}
	//loc_19463
	if( word_3ABAD )
		goto loc_19414;
	
	goto loc_1957A;
	
loc_1946D:;
	if( Sprite->field_5A )
		goto loc_19403;
	
	if( !Sprite->field_45 )
		goto loc_194A0;
	
	Sprite->field_45 -= 1;
	goto loc_19414;

loc_19490:;
	Sprite->field_5A = 0;
	sub_1F5CA( Sprite );
	return;

loc_194A0:;
	Sprite->field_43 = -1;
	
	if( !word_3AA1D ) {
		word_3A8CF = 0;
		sub_1F762( Sprite );
		Sprite->field_A = 0;
		return;
		
	}
	//loc_194CB
	
	if( word_39FD0 == Sprite->field_32 )
		goto loc_19490;
	
	sub_1F5CA( Sprite );
	return;

loc_1957A:;
	Sprite->field_3A = 0;
	sub_1F762( Sprite );

}

int16 cFodder::sub_1E05A( sSprite_0* pSprite ) {

	if (pSprite->field_38 == 3)
		goto loc_1E831;

	if (pSprite->field_38 == 6)
		goto loc_1EA48;

	if (pSprite->field_38 == 2)
		goto loc_1EB87;

	int16 Data0 = pSprite->field_4;
	if (Data0 >= word_3AA4F)
		pSprite->field_4 = word_3AA4F;

	//loc_1E0A4
	if (pSprite->field_56)
		goto loc_1E831;

	if (pSprite->field_5B == 1)
		goto loc_1E74C;

	if (pSprite->field_38 == 0x0A)
		goto loc_1E2F4;

	if (pSprite->field_38 == 0x32)
		goto loc_1ECA6;

	if (pSprite->field_38 == 0x33)
		goto loc_1ED5B;

	if (pSprite->field_38 == 0x34)
		goto loc_1EE59;

	if (pSprite->field_38 == 0x5A)
		goto loc_1EEEC;

	if (pSprite->field_38 == 0x5B)
		goto loc_1EF28;

	//seg004:53BD
	if (!pSprite->field_38)
		goto loc_1EA3F;

	if (!pSprite->field_64)
		goto loc_1E3D2;

	pSprite->field_64 = 0;
	if (word_3A9AA)
		pSprite->field_40 = 0x9876;

	if (!pSprite->field_58) {
		sub_1FE35( pSprite );
		pSprite->field_58 = -1;
	}

	//loc_1E15D
	int16 Data8 = pSprite->field_10;
	Data8 >>= 5;
	Data8 -= 1;
	Data8 ^= 0x0F;
	Data8 &= 0x0E;
	Data0 = pSprite->field_22;

	//Data0 <<= 2;
	int16* Data28 = off_32AE4[Data0];
	pSprite->field_8 = Data28[(Data8 + 0x20) / 2];

	if (pSprite->field_59)
		pSprite->field_8 = Data28[(Data8 + 0x10) / 2];

	//loc_1E1E9
	pSprite->field_A = 0;
	pSprite->field_2A = 0;

	if (pSprite->field_1A < 0x0B0000) {
		Data0 = sub_2A030() & 0x07;
		Data0 += 2;
		Data0 = (Data0 << 16);

		pSprite->field_1A = Data0;
	}
	//loc_1E232
	pSprite->field_12 = 2;
	Data0 = sub_2A030();
	int16 Data4 = 0;
	Data0 &= 7;
	Data4 = byte_3D477[Data0];
	//seg004:5508
	Data8 = 0x14;
	sub_14B84();

	if (pSprite->field_36 < 0x1E)
		pSprite->field_36 += 0x0F;

	pSprite->field_3E = pSprite->field_10;
	pSprite->field_3A = -1;
	Data0 = sub_2A030() & 0x01;
	if (!Data0)
		pSprite->field_3A = pSprite->field_10;

	sub_1FF1A(pSprite);
	pSprite->field_26 = -1;
	if (pSprite->field_38 != 9)
		goto loc_1E3D2;

	pSprite->field_36 = 0;
	pSprite->field_38 = 0x0A;
loc_1E2F4:;
	pSprite->field_3A -= 1;
	if (pSprite->field_3A < 0) {
		pSprite->field_38 = 1;
		goto loc_1E737;
	}
	//loc_1E30C
	Data0 = 0x21;
	if (pSprite->field_22)
		Data0 = 0x63;

	pSprite->field_8 = Data0;
	Data0 = pSprite->field_2A & 7;
	//seg004:55F3 

	if (!Data0) {
		sub_1FF1A(pSprite);

		if (pSprite->field_A)
			pSprite->field_A = 0;
		else
			pSprite->field_A = 1;
	}
	//loc_1E36C

	pSprite->field_2A -= 1;
	if (pSprite->field_2A >= 0)
		goto loc_1E737;

	Data0 = sub_2A030() & 7;
	Data0 += 8;
	pSprite->field_2A = Data0;
	Data0 = sub_2A030() & 7;

	Data4 = byte_3D477[Data0];
	Data8 = 0;
	sub_14B84();
	goto loc_1E737;

loc_1E3D2:;

	if (pSprite->field_40 == 0x9876) {
		pSprite->field_28 += 1;
		sub_1FF1A(pSprite);

		if (!(pSprite->field_28 & 7)) {
			Data0 = sub_2A030() & 7;
			Data4 = byte_3D477[Data0];
			Data8 = 0x14;
			sub_14B84();
		}
	}
	//loc_1E437

	if (pSprite->field_3A >= 0) {
		pSprite->field_3E = pSprite->field_3A;

		Data0 = pSprite->field_36 << 2;
		pSprite->field_3A += Data0;
		//seg004:5724
		pSprite->field_3A &= 0x1FE;
		Data8 = pSprite->field_3A;

		Data8 >>= 5;
		Data8 -= 1;
		Data8 ^= 0x0F;
		Data8 &= 0x0E;

		Data28 = off_32AE4[pSprite->field_22];
		pSprite->field_8 = Data28[Data8 + 0x20];

		if (pSprite->field_59) {

			pSprite->field_8 = Data28[Data8 + 0x10];
		}

	}
	//loc_1E50A
	sub_1F623( pSprite );
	word_3A399 = pSprite->field_A;
	sub_2A0FA( pSprite );

	if (pSprite->field_20 < 0x0C) {

		int16 Field10 = pSprite->field_10;
		sub_1FFC6( pSprite );
		pSprite->field_10 = Field10;
	}
	else {
		//loc_1E542
		int16 Field0 = pSprite->field_0;
		int16 Field4 = pSprite->field_4;
		int16 Field10 = pSprite->field_10;

		sub_1FFC6( pSprite );

		pSprite->field_10 = Field10;
		pSprite->field_4 = Field4;
		pSprite->field_0 = Field0;
	}

	//loc_1E579
	if (!pSprite->field_20) {
		if (pSprite->field_4F || pSprite->field_50) {
			pSprite->field_52 = 6;
		}
	}
	//loc_1E5A7
	Data4 = pSprite->field_1A;

	// Probably going to be issues here
	pSprite->field_1E += pSprite->field_1A;
	if (pSprite->field_1E < 0) {
		pSprite->field_1E = 0;
		Data4 = -Data4;
		Data4 >>= 2;

		if (pSprite->field_52) {
			pSprite->field_36 = 0;
			Data4 = 0;
		}
	}
	//loc_1E619
	Data4 -= 0x18000;
	pSprite->field_1A = Data4;
	if (pSprite->field_36) {
		pSprite->field_36 -= 2;

		if (pSprite->field_36 < 0)
			pSprite->field_36 = 0;
	}
	//loc_1E653
	if (pSprite->field_26) {

		if (!pSprite->field_20) {
			sub_1FF1A(pSprite);
			pSprite->field_26 = 0;
		}
	}
	//loc_1E67A
	pSprite->field_12 -= 1;
	if (!pSprite->field_12) {

		pSprite->field_12 = 6;
		if (pSprite->field_A < 1)
			pSprite->field_A += 1;
	}
	//loc_1E6A3
	if (pSprite->field_2A <= 0x14) {

		pSprite->field_2A++;
		goto loc_1EB5D;
	}
	//loc_1E6BA
	if (pSprite->field_20)
		goto loc_1EB5D;

	//seg004:5978
	if (!pSprite->field_52) {
		if (!pSprite->field_50) {

			Data0 = sub_2A030() & 0x7F;
			if (!Data0) {

				pSprite->field_3A = 0x1F4;
				pSprite->field_38 = 0x0A;
				word_3AC2B = 0;
				goto loc_1E737;
			}
		}
	}
	//loc_1E708
	pSprite->field_38 = 6;
	pSprite->field_10 = pSprite->field_3E;
	pSprite->field_12 = 0;
	pSprite->field_45 = 1;

loc_1E737:;
	Data0 = -1;
	return -1;

loc_1E743:;
	Data0 = 0;
	return 0;

loc_1E74C:;
	if (pSprite->field_52 < 5) {
		pSprite->field_52 = 5;
		Data4 = 0x0E;
		Data8 = 0x0A;

		sub_14B84();
		pSprite->field_8 = 0x38;
		if (pSprite->field_22)
			pSprite->field_8 = 0x7A;

		pSprite->field_A = 0;
		pSprite->field_12 = 0x0A;

		return 1;
	}
	//loc_1E7AC
	pSprite->field_12 -= 1;
	if (!pSprite->field_12) {

		pSprite->field_52 += 1;
		if (pSprite->field_52 >= 0x0D) {

			pSprite->field_38 = 6;
			pSprite->field_10 = pSprite->field_3E;
			pSprite->field_12 = 0;
			pSprite->field_45 = 1;

			goto loc_1E825;
		}
		else {
			pSprite->field_12 = 0x0A;
		}
	}
	//loc_1E806
	if (!(pSprite->field_12 & 2) && pSprite->field_A < 5)
		pSprite->field_A += 1;
loc_1E825:;
	Data0 = -1;
	return -1;

loc_1E831:;
	if (pSprite->field_56 == 1) {
		pSprite->field_12 = 1;
		pSprite->field_28 += 2;
	}
	Data0 = pSprite->field_12;
	pSprite->field_12 += 1;

	if (pSprite->field_38 == 3) {
		pSprite->field_52 += Data0;

		if (pSprite->field_52 < 0x0E)
			goto loc_1E737;

		pSprite->field_52 = 0x0E;
		pSprite->field_12 = 0x14;
		Data0 = sub_2A030() & 0x07;
		Data4 = byte_3D477[Data0];
		Data8 = 0x0A;
		sub_14B84();
		goto loc_1E9EC;
	}
	//loc_1E8D6
	pSprite->field_4 += Data0;
	Data0 = pSprite->field_4;
	if (Data0 >= word_3AA4F)
		pSprite->field_38 = 2;

	dword_3A395 = pSprite->field_4;
	Data0 = 8;
	Data0 += pSprite->field_26;
	Data4 = -3.;
	Data4 += pSprite->field_28;

	sub_2A7E2( Data0, Data4 );

	if (Data4 == 9 || Data4 == 0x0A) {
		Data0 = pSprite->field_12;
		pSprite->field_28 += Data0;
		Data8 = pSprite->field_28;

		int16* Data30 = off_3BEF3[pSprite->field_32];
		//seg004:5C49
		Data0 = pSprite->field_40;
		if (Data30[Data0] >= 0)
			Data30[Data0 + 1] = Data8;
	}
	//loc_1E9CD;
	sub_1FFC6( pSprite );
	if (pSprite->field_12 > 5)
		sub_223B2( pSprite );

	if (Data4 == 9)
		goto loc_1E737;

loc_1E9EC:;
	if (pSprite->field_12 < 0x0C) {
		pSprite->field_3E = 0;
		pSprite->field_56 = 0;

		goto loc_1E743;
	}
	
	pSprite->field_38 = 6;
	pSprite->field_10 = pSprite->field_3E;
	pSprite->field_12 = 0;
	pSprite->field_45 = 1;
	goto loc_1E737;

loc_1EA3F:;
	Data0 = 0;
	return 0;

loc_1EA48:;
	pSprite->field_12 += 1;
	if (pSprite->field_12 >= 0x0F)
		return sub_1EF47(pSprite);

	if (pSprite->field_12 >= 0x07 && pSprite->field_8 != 0x7C) {
		pSprite->field_8 = 0x7C;
		goto loc_1EB0E;
	}

loc_1EA82:;
	Data8 = pSprite->field_10;
	Data8 >>= 5;
	Data8 -= 1;
	Data8 ^= 0x0F;
	Data8 &= 0x0E;

	Data28 = off_32AE4[pSprite->field_22];
	pSprite->field_8 = Data28[Data8 + 0x20];

	if (pSprite->field_59)
		pSprite->field_8 = Data28[Data8 + 0x10];
	
loc_1EB0E:;
	int16 Field_52 = pSprite->field_52;
	int16 Field_0 = pSprite->field_0;
	int16 Field_4 = pSprite->field_4;
	sub_1FFC6( pSprite );
	pSprite->field_4 = Field_4;
	pSprite->field_0 = Field_0;
	pSprite->field_52 = Field_52;

	if ( pSprite->field_4F || pSprite->field_50 ) {

	loc_1EB5D:;
		if (pSprite->field_52 >= 0x0D)
			pSprite->field_52 = 0x0B;

		pSprite->field_52 += 2;
	}
	//loc_1EB7B
	Data0 = -1;
	return -1;

loc_1EB87:;
	pSprite->field_12 += 1;
	if (pSprite->field_12 >= 0x0F)
		return sub_1EF47( pSprite );

	if (pSprite->field_12 < 0x07)
		goto loc_1EA82;

	if (pSprite->field_8 != 0x7C) {
		pSprite->field_8 = 0x7C;
		goto loc_1EB0E;
	}

	Data8 = pSprite->field_10;
	Data8 >>= 5;
	Data8 -= 1;
	Data8 ^= 0x0F;
	Data8 &= 0x0E;

	Data28 = off_32AE4[pSprite->field_22];
	pSprite->field_8 = Data28[Data8 + 0x20 ];

	if (pSprite->field_59)
		pSprite->field_8 = Data28[Data8 + 0x10];
	
	//loc_1EC4F
	Field_52 = pSprite->field_52;
	sub_1FFC6( pSprite );
	pSprite->field_52 = Field_52;

	if (!pSprite->field_4F || pSprite->field_50) {
		if (pSprite->field_52 >= 0x0D)
			pSprite->field_52 = 0x0B;
		pSprite->field_52 += 2;
	}
	//loc_1EC9A
	Data0 = -1;
	return -1;

loc_1ECA6:;
	if (pSprite->field_60 <= 0x06 && pSprite->field_60 >= 0x04) {
		pSprite->field_38 = 0;
		goto loc_1E743;
	}

	pSprite->field_38 = 0x33;
	pSprite->field_36 = 0x24;

	Data0 = sub_2A030() & 6;
	Data0 = byte_3D47F[Data0];

	Data0 += pSprite->field_10;
	Data0 &= 0x1FE;
	pSprite->field_10 = Data0;
	pSprite->field_8 = 0xA4;

	if (pSprite->field_22)
		pSprite->field_8 = 0xA7;

	sub_20456( pSprite, Data8 );
	Data8 >>= 1;
	pSprite->field_A = Data8;
	goto loc_1E737;

loc_1ED5B:;
	sub_1F623( pSprite );
	word_3A399 = pSprite->field_A;

	sub_2A0FA( pSprite );
	sub_20478( pSprite );
	sub_1FFC6( pSprite );

	if (pSprite->field_38 != 0x33)
		goto loc_1EE3E;

	if (pSprite->field_60 > 6 || pSprite->field_60 < 4) {
		pSprite->field_36 -= 5;
		if (pSprite->field_36) {
			if (pSprite->field_36 >= 0)
				goto loc_1EE31;

			pSprite->field_36 = 0;
		}
	}
	sub_20456( pSprite, Data8 );

	//seg004:606C
	Data28 = off_32AE4[pSprite->field_22];
	Data0 = Data28[0x60 + Data8];

	if (Data0 != pSprite->field_8) {
		pSprite->field_8 = Data28[0x60 + Data8];
		pSprite->field_A = 0;

	loc_1EE31:;
		goto loc_1E737;
	}
	//loc_1EE34
	pSprite->field_38 = 0;

loc_1EE3E:;
	pSprite->field_43 = 0;
	sub_305D5();
	goto loc_1E737;

loc_1EE59:;
	if (pSprite->field_60 <= 6 && pSprite->field_60 >= 4 ) {
		pSprite->field_38 = 0;
		goto loc_1E743;
	}

	pSprite->field_38 = 0x33;
	pSprite->field_36 = 0x2E;

	Data0 = sub_2A030() & 0x1F;

	pSprite->field_10 += Data0;
	pSprite->field_8 = 0xA4;
	if (pSprite->field_22)
		pSprite->field_8 = 0xA7;

	sub_20456( pSprite, Data8 );
	Data8 >>= 1;
	pSprite->field_A = Data8;
	goto loc_1E737;

loc_1EEEC:;

	if (!pSprite->field_66) {
		pSprite->field_38 = 0;
		goto loc_1E743;
	}

loc_1EF07:;
	pSprite->field_38 = 0x5B;
	pSprite->field_8 = 0xCC;
	pSprite->field_A = 4;
	goto loc_1E737;

loc_1EF28:;
	pSprite->field_A -= 1;
	if (pSprite->field_A < 0)
		goto loc_1F043;

	pSprite->field_36 = 0x30;
	sub_1F6F4();
	goto loc_1E737;

}

int16 cFodder::sub_1F21E( sSprite_0* pSprite ) {

	if( !word_3A9B2 )
		if( !word_3A9AC )
			return 0;
		
	int16 Data0 = -1;
	int16 Data4 = 8;
	
	sub_2A7F7( pSprite, Data0, Data4 );
	
	if( Data4 == 6 ) {
		Data0 = pSprite->field_20;
		Data0 -= 8;
		
		if( Data0 >= 0 ) {
			Data0 = 0;
		} else {
			Data0 = -Data0;
			if( Data0 > 8 )
				Data0 = 8;
		}
		
		pSprite->field_52 = Data0;
	}
	//loc_1F283
	
	if( pSprite->field_8 == 0x41 )
		goto loc_1F3C4;
	
	if( pSprite->field_8 == 0x9F )
		goto loc_1F340;
	
	if( pSprite->field_8 == 0x38 )
		goto loc_1F3A2;
	
	pSprite->field_A = 0;
	pSprite->field_36 = 0;
	
	if( !word_3A9B2 ) {
		
		sub_2A030();
		Data0 &= 1;
		if(Data0 == 0)
			goto loc_1F32C;
	
		if( !pSprite->field_52 ) {
			sub_2A030();
			Data0 &= 1;
			
			if( !Data0 ) {
				//loc_1F2F9
				pSprite->field_8 = 0x41;
				sub_2A030();
				Data0 &= 3;
				pSprite->field_A = Data0;
				pSprite->field_2A = 1;
				sub_1FE35( pSprite );
				goto loc_1F3C4;
			}
		}
	}
	
	//loc_1F2EC
	pSprite->field_8 = 0x38;
	goto loc_1F3A2;

	loc_1F32C:;
	pSprite->field_8 = 0x9F;
	pSprite->field_2A = 0;
	
	loc_1F340:;
	
	Data0 = pSprite->field_2A;
	
	pSprite->field_A = word_3D487[ Data0 ];
	pSprite->field_36 ^= -32768;
	if(pSprite->field_36 < 0)
		goto loc_1F41D;
	
	pSprite->field_2A += 1;
	if( pSprite->field_2A < 7)
		goto loc_1F41D;
	
	pSprite->field_2A = 3;
	goto loc_1F41D;
	
	loc_1F3A2:;
	pSprite->field_36 ^= -32768;
	if( pSprite->field_36 < 0 )
		goto loc_1F3C2;
	
	if( pSprite->field_A >= 5 )
		goto loc_1F41D;
	
	pSprite->field_A += 1;
	loc_1F3C2:;
	goto loc_1F41D;
	
	loc_1F3C4:;

	pSprite->field_A += pSprite->field_2A;
	if( !pSprite->field_A )
		goto loc_1F3E9;
	
	if( pSprite->field_A != 5 )
		goto loc_1F3F1;
	
	loc_1F3E9:;
	pSprite->field_2A = -pSprite->field_2A;
	
	loc_1F3F1:;
	Data0 = pSprite->field_A;
	Data0 -= 1;
	if( Data0 < 0)
		Data0 = 0;
	
	Data0 <<= 3;
	pSprite->field_20 = Data0;
	
	loc_1F41D:;
	Data0 = -1;
	
	return -1;
}

void cFodder::sub_1F5A0( sSprite_0* pSprite ) {

	int16 Data0 = pSprite->field_2E;
	int16 Data4 = pSprite->field_30;

	sub_2A1F0( pSprite, Data0, Data4 );
	sub_20E5C( pSprite );
	sub_1F762( pSprite );
}

void cFodder::sub_1F5CA( sSprite_0* pSprite ) {

	int16 Data0 = word_3BDAF;
	Data0 += dword_39F2C;

	Data0 -= 0x18;
	int16 Data4 = word_3BDB1;
	Data4 += dword_39F30;

	sub_2A1F0( pSprite, Data0, Data4 );
	sub_20E5C( pSprite );

	word_3ABAF = pSprite->field_A;
	sub_1F762( pSprite );

	if (pSprite->field_43)
		return;

	pSprite->field_A = word_3ABAF;
}

void cFodder::sub_1F623( sSprite_0* pSprite ) {
	word_3ABAD = 0;
	
	dword_3A391 = pSprite->field_0 | pSprite->field_2 << 16;
	dword_3A395 = pSprite->field_4 | pSprite->field_6 << 16;
}

void cFodder::sub_1F66F( sSprite_0* pSprite ) {
	sub_1FCF2( pSprite );

	if (pSprite->field_4F)
		return;

	if (pSprite->field_50)
		return;

	int16 Data0 = pSprite->field_10;
	Data0 >>= 5;
	Data0 -= 1;
	Data0 ^= 0x0F;

	int16 Data4 = 0;
	for (Data4 = 0; Data4 < 0x0E; Data4 += 2) {
		if (Data0 == pSprite->field_3C)
			break;

		Data0 += 2;
		Data0 &= 0x0E;
	}

	pSprite->field_36 = word_3D495[Data4 / 2];;
}

void cFodder::sub_1F762( sSprite_0* pSprite ) {
	if (!pSprite->field_22)
		goto loc_1F7CE;

	if (!pSprite->field_70)
		goto loc_1F7CE;

	int16 Data0 = pSprite->field_0;
	if (Data0 != pSprite->field_26)
		goto loc_1F7CE;

	Data0 = pSprite->field_4;
	if (Data0 != pSprite->field_28)
		goto loc_1F7CE;

	pSprite->field_8 = 0xDC;
	pSprite->field_A = 0;
	word_3ABB1 = -1;
	return;

loc_1F7CE:;
	if (word_3AA1D == 2)
		goto loc_1F7FF;

	if (pSprite->field_5A)
		goto loc_1F7F9;

	if (!pSprite->field_43)
		goto loc_1F7FF;

	if (pSprite->field_4F)
		goto loc_1F7FF;

loc_1F7F9:;
	word_3A9C6 = -1;

loc_1F7FF:;
	int16 Data8 = pSprite->field_3C;
	Data8 += word_3A8CF;
	Data8 &= 0x0E;

	pSprite->field_3C = Data8;
	Data0 = pSprite->field_22;

	int16* Data28 = off_32AE4[pSprite->field_22];
	if (!word_3AA41)
		goto loc_1F9C0;

	if (pSprite->field_22)
		goto loc_1F98B;

	int16* Data30 = off_3BEF3[pSprite->field_32];
	if (Data30[pSprite->field_40] >= 0)
		goto loc_1F9C0;

	//seg005:01CC
	sSprite_0* Dataa30 = off_3BDEF[pSprite->field_32][0];

	// TODO: Does this work
	if (Dataa30 < 0)
		goto loc_1F9C0;

	//seg005:020C
	if (Dataa30 != pSprite )
		goto loc_1F94F;

	Data0 = pSprite->field_0;
	if (Data0 != pSprite->field_26)
		goto loc_1F9C0;

	//seg005:0246
	Data0 = pSprite->field_4;
	if (Data0 != pSprite->field_28)
		goto loc_1F9C0;

	goto loc_1F98B;

loc_1F94F:;
	Data0 = Dataa30->field_0;

	if (Data0 != Dataa30->field_26)
		goto loc_1F9C0;

	Data0 = Dataa30->field_28;
	if (Data0 != Dataa30->field_28)
		goto loc_1F9C0;

	if (!word_3B2F3)
		goto loc_1F9C0;

loc_1F98B:;
	if (pSprite->field_60 == 6)
		goto loc_1F9C0;

	//seg005:02A6
	//TODO: This will need fixing
	pSprite->field_8 = *(Data28 + Data8 + 0x30);
	pSprite->field_A = 0;
	word_3ABAF = 0;
	return;

loc_1F9C0:;
	if (pSprite->field_54 != 2)
		goto loc_1FA39;

	if (word_3AA1D) {
		if (word_3AA1D == 2) {
			pSprite->field_8 = *(Data28 + Data8);
			pSprite->field_A = word_39FFA;
		}
		else {
			//loc_1F9FF
			pSprite->field_8 = *(Data28 + Data8);
			pSprite->field_A = 0;
		}
	}
	//loc_1FA20
	--pSprite->field_57;
	pSprite->field_54 = 0;
	goto loc_1FB00;

loc_1FA39:;
	if (pSprite->field_54 != 1)
		goto loc_1FB00;

	Data0 = pSprite->field_50;
	//TODO: Fix?
	if (Data0 != *(Data28 + Data8 + 4)) {
		pSprite->field_8 = *(Data28 + Data8 + 0x28);
		pSprite->field_55 = 0;
		pSprite->field_A = 0;
		return;
	}
	//loc_1FA93
	pSprite->field_55++;
	if (pSprite->field_50 != 2)
		return;
	pSprite->field_50 = 0;
	pSprite->field_A++;
	word_3ABAF = pSprite->field_A;

	if (pSprite->field_A < 3)
		return;
	word_3ABAF = 0;
	pSprite->field_A = 0;
	pSprite->field_54 = 0;
	pSprite->field_5A = 0;
	pSprite->field_55 = 0;

loc_1FB00:;
	if (pSprite->field_54 != 3)
		goto loc_1FBA4;

	Data0 = *(Data28 + Data8 + 0x38);
	if (Data0 != pSprite->field_8) {
		pSprite->field_8 = Data0;
		pSprite->field_55 = 0;
		pSprite->field_A = 0;
		return;
	}
	//loc_1FB5A
	pSprite->field_55++;
	if (pSprite->field_55 != 7)
		return;

	pSprite->field_55 = 0;
	pSprite->field_A = 0;
	pSprite->field_54 = 0;
	pSprite->field_5A = 0;
	pSprite->field_55 = 0;
loc_1FBA4:;
	if (pSprite->field_4F) {
	
		pSprite->field_8 = *(Data28 + Data8 + 0x20);
		Data0 = word_39FF2;
		if (pSprite->field_43) {
			Data0 = word_39FF6;
		}
		Data0 &= 1;
		pSprite->field_A = Data0;
		goto loc_1FCD7;
	}
	//loc_1FBF8
	Data0 = word_3AA1D;
	if (!Data0) {
		pSprite->field_8 = *(Data28 + Data8 + 0x18);
		pSprite->field_A = word_39FF6;
		goto loc_1FCD7;
	}
	//loc_1FC29
	Data0 = pSprite->field_8;
	if (Data0 == *(Data28 + Data8 + 0x18) && pSprite->field_A) {
		pSprite->field_A = 0;
		goto loc_1FCD7;
	}
	//loc_1FC61
	//TODO: This is broken
	int32* Data24 = (int32*) pSprite->field_46;
	Data0 = *(Data24 + 6);

	if (Data0 == 3)
		pSprite->field_8 = *(Data28 + Data8 + 0);
	else
		pSprite->field_8 = *(Data28 + Data8);

	//loc_1FCB4
	if (Data0 != 2)
		pSprite->field_A = word_39FF2;
	else
		pSprite->field_A = word_39FFA;

loc_1FCD7:;
	if (!word_3A9C6)
		return;

	pSprite->field_A = word_3A399;
	word_3A9C6 = 0;
}

void cFodder::sub_1FDE7( sSprite_0* pSprite ) {
	
	int16 Data0 = pSprite->field_2E;
	int16 Data4 = pSprite->field_30;

	sub_2A1F0( pSprite, Data0, Data4 );
	sub_20E5C( pSprite );

	word_3ABAF = pSprite->field_A;

	sub_1F762( pSprite );
	if (!pSprite->field_43)
		return;

	pSprite->field_A = word_3ABAF;
}

void cFodder::sub_1FE35( sSprite_0* pSprite ) {
	int16 Data0 = 0;

	sSprite_0* Data2C, *Data30;

	if (pSprite->field_5C == 0)
		return;


	sub_211BA( pSprite, Data0, Data2C, Data30 );
	if (Data0)
		return;

	Data2C->field_1A = (int32) pSprite;
	Data2C->field_6A = (int32) pSprite;

	Data2C->field_0 = pSprite->field_0;
	Data2C->field_4 = pSprite->field_4;
	Data2C->field_4 += 4;
	Data2C->field_8 = 0x8D;
	Data2C->field_A = 2;
	Data2C->field_2 = pSprite->field_2;
	Data2C->field_6 = pSprite->field_6;
	Data2C->field_62 = pSprite->field_18;
	Data2C->field_20 = 0;
	Data2C->field_32 = -1;
	Data2C->field_2C = -1;
	Data2C->field_52 = 0;
}

void cFodder::sub_1FF1A( sSprite_0* pSprite ) {
	int16 Data0;
	sSprite_0* Data2C, *Data30 = 0;

	Data0 = 1;
	
	sub_211BA( pSprite, Data0, Data2C, Data30 );

	if (!Data0) {
		Data2C->field_0 = pSprite->field_0;
		Data2C->field_2 = pSprite->field_2;
		Data2C->field_4 = pSprite->field_4;
		Data2C->field_6 = pSprite->field_6;

		Data2C->field_0 += 3;
		Data2C->field_4 -= 8;
		Data2C->field_8 = 0x96;
		Data2C->field_A = 0;
		Data2C->field_18 = 0x17;
		Data2C->field_20 = pSprite->field_20;
		Data2C->field_32 = -1;
		Data2C->field_2C = 1;
		Data2C->field_52 = 0;
		Data2C->field_12 = 1;
		Data0 = 0;

	}
}

void cFodder::sub_1FFC6( sSprite_0* pSprite ) {
	int16 Data0 = -3;
	int16 Data4 = 8;

	if (sub_2A7F7( pSprite, Data0, Data4 ))
		goto loc_20236;

	pSprite->field_60 = Data4;
	pSprite->field_50 = 0;
	pSprite->field_4F = 0;

	if (Data4 == 0x0A) {
		if (pSprite->field_18 == 5)
			goto loc_20251;

		if (pSprite->field_22 == 2)
			goto loc_20251;

		if (!pSprite->field_38 || pSprite->field_38 >= 0x32) {
			pSprite->field_38 = 3;
			return;
		}
	}

	//loc_20044
	if (Data4 == 9) {

		if (pSprite->field_18 == 5)
			goto loc_20251;

		if (pSprite->field_22 == 2)
			goto loc_20251;

		++pSprite->field_56;
		return;
	}

	//loc_20072
	pSprite->field_56 = 0;
	if (Data4 == 8)
		goto loc_201CC;

	if (Data4 == 1)
		goto loc_20108;

	if (Data4 == 2)
		goto loc_2014D;

	if (!pSprite->field_61)
		goto loc_200C0;

	pSprite->field_20 -= 3;
	if (!pSprite->field_20)
		goto loc_200B7;
	if (pSprite->field_20 >= 0)
		goto loc_200C0;

	pSprite->field_20 = 0;
loc_200B7:;
	pSprite->field_61 = 0;

loc_200C0:;
	if (Data4 == 4)
		goto loc_2019E;

	if (Data4 == 5)
		goto loc_201AB;

	if (Data4 == 6)
		goto loc_201B8;

	if (pSprite->field_22 == 2)
		goto loc_20251;
	
	pSprite->field_4F = -1;
	pSprite->field_50 = 0;
	pSprite->field_52 = 0;
	return;

loc_20108:;
	pSprite->field_52 = 0;
	if (pSprite->field_61) {
		pSprite->field_20 = 2;
		return;
	}
	if (!pSprite->field_20) {
		pSprite->field_61 = -1;
		pSprite->field_20 = 1;
	}
	return;

loc_2014D:;
	pSprite->field_52 = 0;
	if (!pSprite->field_61) {
		if (pSprite->field_20 >= 6)
			return;

		pSprite->field_20 += 2;
		return;
	}
//loc_2017C
	if (pSprite->field_20)
		return;
	pSprite->field_61 = -1;
	pSprite->field_20 = 1;
	return;

loc_2019E:;
	pSprite->field_50 = 3;
	return;

loc_201AB:;
	pSprite->field_50 = 6;
	return;

loc_201B8:;
	if (Data4 == 0x0B)
		goto loc_2022C;

	pSprite->field_52 = 0;
	return;

loc_201CC:;
	if (pSprite->field_38)
		return;
	if (!pSprite->field_36)
		return;
	if (pSprite->field_52)
		return;
	if (pSprite->field_20)
		return;

	Data0 = sub_2A030() & 0x3F;
	if (Data0)
		return;

	if (pSprite->field_22 == 2)
		return;

	pSprite->field_38 = 0x32;
	return;

loc_2022C:;
	pSprite->field_5B = 1;
	return;

loc_20236:;
	if (Data4 == 9 || Data4 == 0x0A) {
		pSprite->field_38 = 2;
		return;
	}

loc_20251:;
	pSprite->field_43 = 1;
	word_3ABAD = -1;
	if (!pSprite->field_22)
		goto loc_2035C;

	// TODO: Check
	pSprite->field_0 = dword_3A391;

	Data0 = -3;
	Data4 = 8;
	if (sub_2A7F7( pSprite, Data0, Data4 ))
		goto loc_202E5;

	if (Data4 == 9)
		goto loc_202E5;

	if (Data4 == 0x0A)
		goto loc_202E5;

	if (pSprite->field_22 == 2 && Data4 == 6)
		goto loc_202E5;

	Data0 = pSprite->field_10;
	if (Data0 <= 0x80 || Data0 > 0x180) {
		pSprite->field_10 = 0;
		goto loc_20307;
	}

	pSprite->field_10 = 0x100;
	goto loc_20307;

loc_202E5:;
	if (pSprite->field_10 > 0x100) {
		pSprite->field_10 = 0x180;
		goto loc_20307;
	}

	pSprite->field_10 = 0x80;
loc_20307:;

	Data0 = word_390AE;
	Data0 >>= 2;
	Data0 &= 0x3F;
	Data0 -= 0x20;
	Data0 &= 0x1FE;
	pSprite->field_10 = Data0;
	pSprite->field_4 = dword_3A395;

	Data0 = word_390AE;
	Data0 &= 0x1F;
	Data0 += 0x0C;
	pSprite->field_4 = Data0;
	return;

loc_2035C:;

	word_3A9E6 = pSprite->field_0;
	pSprite->field_0 = dword_3A391;

	Data0 = -3;
	Data4 = 8;
	if (!sub_2A7F7( pSprite, Data0, Data4 ))
		return;

	pSprite->field_0 = word_3A9E6;
	pSprite->field_4 = dword_3A395;

	Data0 = -3;
	Data4 = 8;
	if (!sub_2A7F7( pSprite, Data0, Data4 ))
		return;

	//loc_203BA
	pSprite->field_A = word_3A399;
	sub_1F649();
	pSprite->field_26 = pSprite->field_0;
	pSprite->field_28 = pSprite->field_4;

	int16* Data30 = off_3BEF3[ pSprite->field_32 ];
	Data4 = 0;

	for (;;) {
		int16 eax = *Data30;
		Data30 += 2;

		if (eax < 0)
			break;

		Data4 += 4;
	}

	pSprite->field_40 = Data4;
	pSprite->field_4C = -1;
}

void cFodder::String_Print( cSurface* pImage, uint8* pWidths, int32 pParam0, int32 pParam08, int32 pParamC, const char* pText ) {

	word_3B305 = pParamC;
	word_3B307 = 0;

	for (;;) {
	loc_29C7A:;
		uint8 NextChar = *pText++;
		uint8 NextChar10;

		//seg007:0170
		if (NextChar == 0xFD) {
			//sub_29DE2(0x10);

		} else if (NextChar == 0xFE) {
			//sub_29DE2(0x0F);

		} else if (NextChar == 0x00)
			break;

		else {
			//seg007:01A1
			NextChar10 = NextChar;

			if (!(NextChar & 0x80)) {

				//01AB
				if (word_3AC19) {
					if (NextChar == 0x20) {
						NextChar = (uint8) word_3AC19;
						goto loc_29D71;
					}
				} else {
				//1C4
					if (NextChar == 0x20)
						goto loc_29DC7;
				}
				//1CD
				if (NextChar <= 0x39) {
					if (NextChar >= 0x30) {
						NextChar -= 0x30;
						NextChar += 0x1A;
						goto loc_29D71;
					}
				}
				else {
					//loc_29D07
					if (NextChar > 0x5A) {
						NextChar -= 0x61;
						NextChar += 0x39;
						goto loc_29D71;
					}
					else {
						if (NextChar >= 0x41) {
							NextChar -= 0x41;
							goto loc_29D71;
						}
					}
				}
			}

			// 20D
			//loc_29D2D
			int32 unk14 = -1;
			uint8 al;
			uint8* ptr = mUnkStringModifier;
			do {
				if (*ptr == 0xFF)
					goto loc_29C7A;
				++unk14;

				al = *ptr++;

			} while(al != NextChar);

			NextChar = unk14;
			NextChar += 0x24;

			loc_29D71:;

			if (word_3AC21) {
				sub_145AF( pParam0 + NextChar, pParam08, pParamC );
			}
			else			         //0	// C     // 4	   // 8
				sub_13C1C( pImage, pParam0, pParamC, NextChar, pParam08 );

		}
		loc_29DC7:;
		//seg007:02A7
		NextChar10 = pWidths[NextChar10];

		pParam08 += NextChar10;
	}
}

void cFodder::String_CalculateWidth( int32 pPosX, uint8* pWidths, const char* pString ) {
	int32 PositionX = 0;

	for (const char* Text = pString; *Text; ++Text) {

		PositionX += pWidths[*Text];
	}

	pPosX -= PositionX;
	if (pPosX < 0) {
		pPosX = 0;
		PositionX = 318;
	}

	pPosX >>= 1;
	word_3B301 = pPosX;
	word_3B303 = PositionX;
}

int16 cFodder::introPlayText() {
	cSurface* CurrentImage = 0;

	Sprite_SetDataPtrToBase( mFontSpriteSheetPtr );

	for ( word_3B2CF = 0; mIntroText[word_3B2CF].mImageNumber != 0; ++word_3B2CF) {

		word_3B447 = 0x288;
		
		delete CurrentImage;
		if (mIntroText[word_3B2CF].mImageNumber != 0xFF) {

			std::stringstream ImageName;
			size_t ImageSize = 0;
			ImageName << mIntroText[word_3B2CF].mImageNumber;
			ImageName << ".dat";

			CurrentImage = g_Resource.image4PlaneLoad( ImageName.str(), 0xD0 );
			CurrentImage->paletteSet( mPalette, 0xD0 );
		}
		else {
			CurrentImage = new cSurface( 320, 230 );
			CurrentImage->paletteSet( mPalette, 0xD0 );
			word_3B447 = 0xAF;
			
		}

		const sIntroString* IntroString = mIntroText[word_3B2CF].mText;
		while (IntroString->mPosition) {

			sub_18C45( CurrentImage, IntroString->mPosition - 0x19, IntroString );
			++IntroString;
		}
		//loc_16710
		
		int16 Duration = word_3B447;
		int16 Fade = -1;
		bool DoBreak = false;

		while( Fade == -1 || DoBreak == false  ) {
			--Duration;

			if (Duration) {
				if (Fade)
					Fade = CurrentImage->paletteFade();

				mouse_GetData();
				if (mouse_Button_Status) {
					word_3B2CF = 15;
					word_3B4F3 = -1;
					CurrentImage->paletteFadeOut();
					Fade = -1;
					DoBreak = true;
				}
			}
			else {
				CurrentImage->paletteFadeOut();
				Fade = -1;
				DoBreak = true;
			}

			g_Window.RenderAt( CurrentImage, cPosition() );
			g_Window.FrameEnd();
		}
	}

	delete CurrentImage;
	return word_3B4F3;
}

void cFodder::Sprite_SetDataPtrToBase( const sSpriteSheet** pSpriteSheet ) {

	mSpriteDataPtr = pSpriteSheet;
}

void cFodder::Load_Sprite_Font() {
	
	g_Resource.fileLoadTo( "font.dat", mDataPStuff );

	paletteLoad( mDataPStuff + 0xA000, 0x10, 0xD0 );
	Sprite_SetDataPtrToBase( mFontSpriteSheetPtr );
}

void cFodder::intro() {

	//copyprotection();
	word_42851 = 0;
	//video_Draw_unk_0();

	word_3B4F3 = 0;
	Load_Sprite_Font();
	//intro_Music_Play();
	if (ShowImage_ForDuration( "cftitle.dat", 0x1F8 ))
		goto introDone;

	if (introPlayText())
		goto introDone;

	if (ShowImage_ForDuration( "virgpres.dat", 0x2D0 ))
		goto introDone;
	
	if (ShowImage_ForDuration( "sensprod.dat", 0x2D0 ))
		goto introDone;
	
	word_42851 = -1;
	if (ShowImage_ForDuration( "cftitle.dat", 0x318 ))
		goto introDone;

introDone:;
	mIntroDone = -1;
	//sub_1645F();

	g_Resource.fileLoadTo( "pstuff.dat", mDataPStuff );
	paletteLoad( mDataPStuff + 0xA000, 0x10, 0xF0 );
	//Sound_Unk();
	//Music_Unk();
}

int16 cFodder::ShowImage_ForDuration( const std::string& pFilename, uint16 pDuration ) {
	bool DoBreak = false;
	int16 Fade = -1;
	cSurface* img = g_Resource.image4PlaneLoad( pFilename, 0x100 );
	
	while( Fade == -1 || DoBreak == false  ) {
		--pDuration;

		if (pDuration) {
			if (Fade)
				Fade = img->paletteFade();

			mouse_GetData();
			if (mouse_Button_Status) {
				word_3B4F3 = -1;
				img->paletteFadeOut();
				Fade = -1;
				DoBreak = true;
			}
		}
		else {
			img->paletteFadeOut();
			Fade = -1;
			DoBreak = true;
		}

		g_Window.RenderAt( img, cPosition() );
		g_Window.FrameEnd();
	}

	delete img;
	return word_3B4F3;
}

void cFodder::mission_PhaseNext() {
	mMissionPhase += 1;
	mMissionPhaseRemain -= 1;
	if (mMissionPhaseRemain)
		return;

	for (unsigned int x = 0; x < 8; ++x) {
		mSquad[x].field_3 = 0;
	}

	word_390D0 = mMissionNumber;
	word_390D2 = mMapNumber;
	--word_390D2;

	mMissionPhaseRemain = mMissionPhases = mMissionPhaseTable[mMissionNumber];
	mMissionPhase = 0;
	++mMissionNumber;
	word_390CE += 0x0F;

	word_390E8 = word_390CE;
	word_390E8 -= 0x0F;
	word_390EA = -1;
	word_390D4 = 0;

	dword_3977E = word_394AC;
	word_394AC[0] = -1;
	dword_394A8 = dword_394A4;
}

void cFodder::videoSleep() {
	static uint64_t delta = 1;

	mTicksDiff = GetTickCount() - mTicksDiff;

	mTicks = mTicksDiff * 50 / 1000;

	sleepLoop(delta * 1000 / 50 - mTicksDiff);

	mTicksDiff = GetTickCount();
}

void cFodder::sleepLoop( int64 pMilliseconds ) {

	uint64 TimeStarted = GetTickCount();
	uint64 TimeFinish = TimeStarted + pMilliseconds;

	do {
		//_system->updateScreen();
		mWindow->EventCheck();

		if (GetTickCount() >= TimeFinish)
			break;

		Sleep( 10 );

	} while (1);

}

void cFodder::WonGame() {
	//seg003:3E6D
	cSurface* img = g_Resource.image4PlaneLoad( "won.dat", 0x100 );

	while(img->paletteFade()) {

		g_Window.RenderAt( img, cPosition() );
		g_Window.FrameEnd();
	}

	while (1) {
		g_Window.EventCheck();
	}
}

void cFodder::sub_20456( sSprite_0* pSprite, int16& pData8 ) {
	pData8 = pSprite->field_10;

	pData8 >>= 5;
	pData8 -= 1;
	pData8 ^= 0x0F;
	pData8 &= 0x0E;
}

void cFodder::sub_20478( sSprite_0* pSprite ) {
	int16 Data0 = pSprite->field_4;

	if (Data0 < 0 || Data0 <= 0x0D) {
		pSprite->field_4 = dword_3A395;
		word_3ABAD = -1;
	}

	Data0 = pSprite->field_4;

	if (Data0 >= word_3AA4F) {
		if (!pSprite->field_38 || pSprite->field_38 >= 0x32) {
			pSprite->field_4 = dword_3A395;
			word_3ABAD = -1;
		}
	}
	//loc_204E1
	Data0 = pSprite->field_0;
	if (Data0 <= 0) {
		if (dword_3A391 <= 0)
			return;

		goto loc_20521;
	}

	Data0 += 0x0C;
	if (Data0 < word_3AA4D)
		return;

	Data0 = dword_3A391 + 0x10 ;
	if (Data0 >= word_3AA4D)
		return;

loc_20521:;
	pSprite->field_0 = dword_3A391;
	word_3ABAD = -1;
}

void cFodder::sub_20E5C( sSprite_0* pSprite ) {
	int16 Data0 = pSprite->field_10;

	Data0 >>= 5;
	Data0 -= 1;
	Data0 ^= 0x0F;
	Data0 &= 0x0F;
	pSprite->field_3C = Data0;

	word_3A8CF = 0;
}

void cFodder::sub_211BA( sSprite_0* pSprite, int16& pData0, sSprite_0*& pData2C, sSprite_0*& pData30 ) {
	if (!word_3B15D) {

		if (pData0 == 2)
			goto loc_21234;

		pData2C = (sSprite_0*) mMapSpt_Loaded + 0x9AE;

		for (int16 Data1C = 0x2A; Data1C >= 0; --Data1C) {
			if (pData2C->field_0 == -32768)
				goto loc_21217;

			pData2C--;
		}
	}
	//loc_211F0
	pData2C = &word_3B4F7;
	pData30 = &word_3B4F7;
	pData0 = -1;
	word_3B15D = pData0;
	return;

loc_21217:;

	sub_212C4( pData2C );
	pData0 = 0;
	return;

loc_21234:;
	pData2C = (sSprite_0*) mMapSpt_Loaded;

	for( int16 Data1C = 0x29; Data1C >= 0; --Data1C, ++pData2C ) {
		
		if( pData2C->field_0 != -32768 )
			continue;
		
		if( (pData2C+1)->field_0 == -32768 )
			goto loc_2128F;
	}
	
	pData2C = &word_3B4F7;
	pData30 = &word_3B4F7;
	pData0 = -1;
	word_3B15D = pData0;
	return;

loc_2128F:;
	pData30 = pData2C + 1;

	sub_212C4( pData2C );
	sub_212C4( pData30 );
	pData0 = 0;
	return;
}

void cFodder::sub_212C4( sSprite_0* pSprite ) {
	pSprite->field_0 = -32768;
	pSprite->field_2 = 0;
	pSprite->field_4 = 0;
	pSprite->field_6 = 0;
	pSprite->field_8 = 0;
	pSprite->field_A = 0;
	pSprite->field_C = 0;
	pSprite->field_E = 0;
	pSprite->field_10 = 0;
	pSprite->field_12 = 0;
	pSprite->field_14 = 0;
	pSprite->field_16 = 0;
	pSprite->field_18 = 0;
	pSprite->field_1A = 0;
	pSprite->field_1E = 0;
	pSprite->field_20 = 0;
	pSprite->field_22 = 0;
	pSprite->field_24 = 0;
	pSprite->field_26 = 0;
	pSprite->field_28 = 0;
	pSprite->field_2A = 0;
	pSprite->field_2C = 0;
	pSprite->field_2E = 0;
	pSprite->field_30 = 0;
	pSprite->field_32 = 0;
	pSprite->field_34 = 0;
	pSprite->field_36 = 0;
	pSprite->field_38 = 0;
	pSprite->field_3A = 0;
	pSprite->field_3C = 0;
	pSprite->field_3E = 0;
	pSprite->field_40 = 0;
	pSprite->field_42 = 0;
	pSprite->field_43 = 0;
	pSprite->field_44 = 0;
	pSprite->field_45 = 0;
	pSprite->field_46 = 0;
	pSprite->field_4A = 0;
	pSprite->field_4C = 0;
	pSprite->field_4D = 0;
	pSprite->field_4E = 0;
	pSprite->field_4F = 0;
	pSprite->field_50 = 0;
	pSprite->field_52 = 0;
	pSprite->field_54 = 0;
	pSprite->field_55 = 0;
	pSprite->field_56 = 0;
	pSprite->field_58 = 0;
	pSprite->field_59 = 0;
	pSprite->field_5A = 0;
	pSprite->field_5B = 0;
	pSprite->field_5C = 0;
	pSprite->field_5E = 0;
	pSprite->field_60 = 0;
	pSprite->field_61 = 0;
	pSprite->field_62 = 0;
	pSprite->field_64 = 0;
	pSprite->field_65 = 0;
	pSprite->field_66 = 0;
	pSprite->field_6A = 0;
	pSprite->field_6E = 0;
	pSprite->field_6F = 0;
	pSprite->field_70 = 0;
	pSprite->field_72 = 0;
	pSprite->field_74 = 0;
	pSprite->field_75 = 0;
}

void cFodder::sub_223B2( sSprite_0* pSprite ) {
	int16 Data8 = pSprite->field_3C;
	
	Data8 += word_3A8CF;
	Data8 &= 0x0E;

	pSprite->field_3C = Data8;

	int16* Data28 = off_32AE4[ pSprite->field_22 ];
	Data28 += 0x40;
	Data28 += Data8;

	pSprite->field_8 = *Data28;
	pSprite->field_3E = pSprite->field_10;
	pSprite->field_A = 0;
}

void cFodder::sub_22AA9( sSprite_0* pSprite ) {
	pSprite->field_8 = 0x7C;
	pSprite->field_A = 0;
	pSprite->field_38 = 0;
	
	int16* Data24 = (int16*) pSprite->field_6A;
	if( (*Data24) == -32768 || *(Data24 + 0x0C )  == 0x0C ) {
		//loc_22AEE
		pSprite->field_6E = 0;
		pSprite->field_66 = 0;
		pSprite->field_6A = 0;
		pSprite->field_38 = 1;
		pSprite->field_64 = -1;
		
		int16 Data0 = sub_2A030() & 0x1FE;
		pSprite->field_10 = Data0;
	}
	
	//loc_22B3C

	pSprite->field_0 = *Data24;
	pSprite->field_4 = *(Data24+2);
	pSprite->field_20 = *(Data24 + 0x10);
}

void cFodder::sub_2E04C() {
	//TODO
	/*
	if( word_3B2FD ) {
		sub_2E72B();
		return;
	} 

	if( word_3B2FF ) {
		sub_2E064();
	}*/
}

void cFodder::Start() {

	mouse_Setup();
	mouse_Handle();

	for (;;) {
		sub_10BBC();

		word_3A9AC = 0;
		mMapNumber = 0;
		word_3901E = 0x3333;

		Troops_Clear();
		Heroes_Clear();

		dword_394A4 = word_391D2;
		word_391D2[0] = -1;

		mMissionPhaseRemain = 1;
		mMissionNumber = 0;

		mission_PhaseNext();

		word_3A9AA = -1;
		word_39096 = -1;

		size_t StuffSize = 0;
		g_Resource.fileLoadTo( "pstuff.dat", mDataPStuff );

		for (unsigned int x = 0; x < 0x30; ++x)
			byte_3DDA2[x] = mDataPStuff[0xA000 + x];

		//loc_1042E:;
		for (;;) {
			//video_?_1();

			if (!word_3A9B2 && !word_3A9AA) {

				if (mMapNumber == 71)
					WonGame();

				++mMapNumber;
				mission_PhaseNext();
				word_3901E = 0x3333;
			}

			// loc_1045F
			sub_10D61();
			sub_10D9F();
			sub_10DEC();
			//video_?_1();
			word_390A6 = 0;

			if (!mIntroDone)
				intro();

			if (dword_3901A != 0x12345678)
				dword_3901A = 0x12345678;

			//loc_10496
			sub_10EA4();
			sub_10EC3();
			if (word_390EA) {
				word_390EA = 0;

				map_Load_Spt();
				word_3ABA7 = -1;

				map_Troops_Prepare();
				map_Load_Players();
				sub_1142D();
				sub_115F7();

				word_3ABA7 = 0;
				Recruit_Show();
				sub_2E04C();
				
				if (!word_3B2FD) {
					if (word_3B2FF) {
						word_390B8 = -1;
						word_390EA = -1;
						word_3A9B2 = -1;
						continue;	// goto loc_1042E;
					}
					word_390B8 = 0;
					//sub_10CE7(); //TODO: This backs up a heap of mission variables
					word_3ABE9 = 0;
					word_3ABEB = 0;

					Mission_Brief();
				}
			}

			//loc_10513
			sub_18908();
			
			map_Load_TileSet();
			map_Load_Spt();

			word_3AA4D = readLEWord( &mMap[0x54] ) << 4;
			word_3AA4F = readLEWord( &mMap[0x56] ) << 4;

			map_Troops_Prepare();
			map_Load_Players();
			sub_1142D();
			sub_115F7();
			graphicsBlkPtrsPrepare();

			Map_Overview_Prepare();
			Briefing_Wait();
			if (word_3B4F5 == -1) {

				//TODO
				//sub_10D24();
				
				word_390B8 = -1;
				word_390EA = -1;
				word_3A9B2 = -1;
				word_3901E = -1;
				continue;
			}

			sub_12083();;
			Sprite_SetDataPtrToBase( off_32C0C );
			map_Tiles_Draw();
			sub_12083();
			map_SetTileType();
			mouse_Handle();
			sub_18D5E();
			sub_18DD3();
		}
	}
}

void cFodder::graphicsBlkPtrsPrepare() {
	int32* di = mGraphicBlkPtrs;
	uint16 bx = 0;

	for (int16 cx1 = 0x0C; cx1 > 0; --cx1) {

		uint16 bx2 = bx;
		for (int16 cx2 = 0x14; cx2 > 0; --cx2) {

			*di = (uint32) mDataBaseBlk + bx2;
			*(di + 0xF0) = (uint32) mDataSubBlk + bx2;

			++di;
			bx2 += 0x10;
		}

		bx += 0x1400;
	}
}

void cFodder::map_Tiles_Draw() {
	delete mSurfacePlayfield;
	mSurfacePlayfield =  new cSurface( 0x16 * 0x10, 0x0F * 0x10 );
	mSurfacePlayfield->paletteSet( mPalette, 0, true );

	word_40054 = 0;
	word_3B60E = 0;
	word_3B610 = 0;

	word_3B60C = (0x60 - 8) - (readLEWord( &mMap[0x54] ) << 1);
	word_3B612 = 0;
	word_3B614 = 0;
	word_3D473 = 0;
	word_3D475 = 0;

	uint8* si = &mMap[word_3B60C];
	//di = word_40056;

	for (uint16 cx = 0; cx < 0x0F; ++cx) {

		uint8* si2 = si;

		for (uint16 cx2 = 0; cx2 < 0x16; ++cx2) {

			video_Draw_MapTile( readLEWord(si2), cx2, cx );

			si2 += 2;
		}

		si += (mMapWidth << 1);
	}
}

void cFodder::video_Draw_MapTile( uint16 pTile, uint16 pPosX, uint16 pPosY ) {
	uint8* Target = mSurfacePlayfield->GetSurfaceBuffer();

	pPosX *= 16;
	pPosY *= 16;

	Target += pPosY * 352;
	Target += pPosX;

	uint8* TilePtr = (uint8*)mGraphicBlkPtrs[pTile & 0x1FF];

	for (uint16 i = 0; i < 16; ++i) {

		memcpy( Target, TilePtr, 16 );
		TilePtr += 0x140;
		Target += 352;
	}
}

void cFodder::Exit( unsigned int pExitCode ) {

}

void cFodder::sub_301F7() {
	sSquad_Member* Data38 = mSquad;
	
	for (int16 Data1c = 7; Data1c >= 0; --Data1c) {

		Data38->field_9 &= 0;

	}
}

void cFodder::sub_305D5() {
	

	int16 Data0 = word_39FD0;

	if (Data0 < 0)
		goto loc_306AD;

	sSprite_0** Data30 = off_3BDEF[Data0];
	// TODO: Does this work
	if (Data30[0] < 0)
		goto loc_306AD;

	int16* Data20 = 0;

	do {
		if (*Data30 < 0)
			goto loc_306AD;

		Data20 = (int16*) *Data30;
		++Data30;
		//seg011:1B61
		if (*(Data20 + 0x0C))
			continue;

		if (*(Data20 + 0x32) & 2)
			goto loc_3066E;

		if (*(Data20 + 0x1C)) {
			if (*(Data20 + 0x1C) < 0x32)
				goto loc_30662;
		}
		//loc_30656
		if (!*(Data20 + 0x2D))
			goto loc_30681;

	loc_30662:;
		if (!*(Data20 + 0x2D))
			continue;

	loc_3066E:;
		*(Data20 + 0x1C) = 0;
		*(Data20 + 0x2D) = 0;
	loc_30681:;

		if (!*(Data20 + 0x37))
			break;

	} while (*Data30 >= 0);
	//loc_3069A
	int16* Data8 = Data20;
	Data8 -= 0x20;
	goto loc_306BE;

loc_306AD:;
	Data8 = (int16*) -1;
	word_39FD0 = -1;

loc_306BE:;
	if (dword_3B20B)
		return;

	word_39FCE = (int8*) Data8;
}

