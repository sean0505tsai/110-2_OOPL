#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CEraser.h"
#include "CBlock.h"
#include "CCharacter.h"

namespace game_framework {
	
	CBlock::CBlock() {
		Initialize();
	}
	
	bool CBlock::HitTop(CPlayer* player) {
		return hit_top;
	}

	bool CBlock::HitBottom(CPlayer* player) {
		return hit_bottom;
	}

	bool CBlock::HitLeft(CPlayer* player) {
		return hit_left;
	}

	bool CBlock::HitRight(CPlayer* player) {
		return hit_right;
	}

	void CBlock::LoadBitmap() {
		pic.LoadBitmap(IDB_BLOCK01);
	}

	void CBlock::SetXY(int nx, int ny) {
		x1, y1 = nx, ny;
	}
	
	void CBlock::OnMove() {
		
	}

	void CBlock::OnShow() {
		pic.SetTopLeft(x1, y1);
		pic.ShowBitmap();
	}

	void CBlock::Initialize() {
		hit_top = hit_bottom = hit_left = hit_right = false;
		this->SetXY(300, 400);
	}
}
