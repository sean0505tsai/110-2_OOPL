#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CEraser.h"
#include "mygame.h"
namespace game_framework {
	
	CBlock::CBlock() {
		Initialize();
	}
	
	bool CBlock::HitTop(CEraser *eraser) {
		return hit_top;
	}

	bool CBlock::HitBottom(CEraser* eraser) {
		return hit_bottom;
	}

	bool CBlock::HitLeft(CEraser* eraser) {
		return hit_left;
	}

	bool CBlock::HitRight(CEraser* eraser) {
		return hit_right;
	}

	void CBlock::LoadBitmap() {
		bmp.LoadBitmap(IDB_BLOCK00);
	}

	void CBlock::SetXY(int nx, int ny) {
		x1, y1 = nx, ny;
	}
	
	void CBlock::OnMove() {
		
	}

	void CBlock::OnShow() {
		bmp.SetTopLeft(x1, y1);
		bmp.ShowBitmap();
	}

	void CBlock::Initialize() {
		hit_top = hit_bottom = hit_left = hit_right = false;
		this->SetXY(400, 400);
	}
}
