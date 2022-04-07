#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CEraser.h"
#include "Cblock.h"
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
		bmp.LoadBitmap(IDB_MAIN_CHARACTER, RGB(255, 255, 255));
	}

	void CBlock::OnShow() {
		bmp.ShowBitmap();
	}

	void CBlock::SetXY(int nx, int ny) {
		x1, y1 = nx, ny;
		x2 = x1 += bmp.Width();
		y2 = x2 += bmp.Height();
		bmp.SetTopLeft(x1, y1);
	}
	
	void CBlock::Initialize() {

	}
}
