/*
 *  Open Fodder
 *  ---------------
 *
 *  Copyright (C) 2008-2018 Open Fodder
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

namespace cxxopts {
	class Options;
}

class sFodderParameters {
public:
	static cxxopts::Options* mCliOptions;

	bool mAppVeyor;             // Running on AppVeyor
	bool mShowAbout;            // Show the about screen
	bool mSkipIntro;            // Skip the OpenFodder intro, and the game intro
	bool mSkipRecruit;          // Skip the recruit screen and go straight into the mission
	bool mSkipBriefing;         // Skip mission briefing
	bool mSkipService;          // Skip mission debrief

	bool mWindowMode;           // Start in a window
	size_t mWindowScale;		// Start with window scaled at
	bool mRandom;               // Start a random map
	ePlatform mDefaultPlatform; // Default platform to use
	eGame mDefaultGame;			// Default game to use for single/random

	bool mDemoRecord;               // Recording a demo
	bool mDemoPlayback;             // Playing back a demo
	size_t mDemoRecordResumeCycle;  // Record a demo, after playing back the event queue up until this cycle
	std::string mDemoFile;          // The Demo file to save/load to/from

	int64 mSleepDelta;              // Engine sleep delta

	std::string mCampaignName;      // Campaign to start
	size_t mMissionNumber;          // Mission to start on
	size_t mPhaseNumber;            // Phase to start on

	bool mCheatsEnabled;
	bool mUnitTesting;              // Execute unit testing
	bool mSinglePhase;              // Play a single phase
	bool mPlayground;               // Launch into the sprite playground

	bool mDisableVideo;             // Disable all video output
	bool mDisableSound;             // Disable all sound

	size_t mSpritesMax;
	size_t mSpawnEnemyMax;

	bool mShowHelp;

	sFodderParameters() {
		clear();
	}

	virtual void clear() {
		mShowHelp = false;
		mShowAbout = false;
		mPlayground = false;
		mDisableSound = false;
		mDisableVideo = false;
		mSleepDelta = 2;

		mAppVeyor = false;
		mSkipService = false;
		mSkipBriefing = false;
		mSkipIntro = false;
		mSkipRecruit = false;

		mMissionNumber = 0;
		mPhaseNumber = 0;
		mWindowMode = false;
		mWindowScale = 0;
		mRandom = false;
		mDefaultPlatform = ePlatform::Any;
		mDefaultGame = eGame::CF1;

		mDemoRecord = false;
		mDemoPlayback = false;
		mDemoRecordResumeCycle = 0;

		mCheatsEnabled = false;
		mUnitTesting = false;
		mSinglePhase = false;
		mSpritesMax = 45;
		mSpawnEnemyMax = 10;
	}

protected:
	virtual void PrepareOptions();
	virtual bool ProcessCLI(int argc, char *argv[]);
	bool ProcessINI();

public:
	std::string ToJson();
	bool FromJson(const std::string& pJson);

	void Process(int argc, char *argv[]) {
		ProcessINI();
		ProcessCLI(argc, argv);
	}
};