#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CEraser.h"

/*######地圖座標######
*					x
*	  - . . . . . . +
*	  . . . . . . .
*	  . . . . . . . 
*	  . . . . . . . 
*	  . . . . . . .
*	  . . . . . . .
*	y +
*/

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	CPlayer::CPlayer()	// Constructor
	{
		Initialize();
	}

	int CPlayer::GetX1()		// return 左上角x座標
	{
		return x;
	}

	int CPlayer::GetY1()		//return 左上角y座標
	{
		return y;
	}

	int CPlayer::GetX2()		// return 右下角x座標
	{
		return x + rightDefault.Width();
	}

	int CPlayer::GetY2()		// return 右下角y座標
	{
		return y + rightDefault.Height();
	}

	void CPlayer::Initialize()
	{
		const int X_POS = 280;
		const int Y_POS = 380;
		const int INITIAL_VELOCITY = 0;
		x = X_POS;
		y = Y_POS;
		character_direction = RIGHT;
		floor = 380;

		isMovingLeft = isMovingRight = isRising = isFalling
			= isCharging = false;

		topCollision = leftCollision = rightCollision = false;
		bottomCollision = true;

		initial_velocity = INITIAL_VELOCITY;
		vertical_velocity = initial_velocity;
		horizontal_velocity = initial_velocity;
	}

	void CPlayer::LoadBitmap()
	{

		rightDefault.LoadBitmap(IDB_CHARACTER_DEFAULT, RGB(0, 255, 0));
		leftDefault.LoadBitmap(IDB_DEFAULT_LEFT, RGB(0, 255, 0));
		charge.LoadBitmap(IDB_CHARACTER_CHARGE, RGB(0, 255, 0));
		moveRight.AddBitmap(IDB_MOVE_RIGHT_1, RGB(0, 255, 0));
		moveRight.AddBitmap(IDB_MOVE_RIGHT_2, RGB(0, 255, 0));
		moveRight.AddBitmap(IDB_MOVE_RIGHT_3, RGB(0, 255, 0));
		moveRight.AddBitmap(IDB_MOVE_RIGHT_2, RGB(0, 255, 0));

		moveLeft.AddBitmap(IDB_MOVE_LEFT_1, RGB(0, 255, 0));
		moveLeft.AddBitmap(IDB_MOVE_LEFT_2, RGB(0, 255, 0));
		moveLeft.AddBitmap(IDB_MOVE_LEFT_3, RGB(0, 255, 0));
		moveLeft.AddBitmap(IDB_MOVE_LEFT_2, RGB(0, 255, 0));
	}

	void CPlayer::OnMove()
	{
		if (y <= 380) bottomCollision = true;

		const int STEP_SIZE = 2;
		moveRight.OnMove();
		moveLeft.OnMove();
		

		if (isFalling) {						// 下降狀態
			if (!bottomCollision)				// 尚未碰到地板
			{				
				y += vertical_velocity;
				if (vertical_velocity < 20) vertical_velocity++;
			}
			else if (bottomCollision)			// 碰到地板
			{
				vertical_velocity = 0;
				initial_velocity = 0;
				isFalling = false;
			}
		}
		
		if (isRising) {			// 上升狀態
			if (!topCollision) {

				if (vertical_velocity != 0) {			// 上升中
					y -= vertical_velocity;
					vertical_velocity--;
				}
				else			// 到達頂點
				{
					isRising = false;			// 開始下墜
					isFalling = true;
				}

			}
			else{		// 頂部碰撞 開始下墜
				vertical_velocity = 0;
				isRising = false;
				isFalling = true;
			}
		}
		
		if (isCharging) {		// 蓄力狀態
			if (initial_velocity <= 20) initial_velocity++;
			SetJump();
		}

		
		// 原地狀態
		if (isMovingLeft)
			x -= STEP_SIZE;
		if (isMovingRight)
			x += STEP_SIZE;
		

		/*
		if (isJumping) {			// 上升狀態
			if (velocity > 0) {
				y -= velocity;	// 當速度 > 0時，y軸上升(移動velocity個點，velocity的單位為 點/次)
				velocity--;		// 受重力影響，下次的上升速度降低
			}
			else {
				isJumping = false; // 當速度 <= 0，上升終止，下次改為下降
				velocity = 1;	// 下降的初速(velocity)為1
			}
		}
		else {				// 下降狀態
			if (y < floor - 1) {  // 當y座標還沒碰到地板
				initial_velocity = 0;
				y += velocity;	// y軸下降(移動velocity個點，velocity的單位為 點/次)
				velocity++;		// 受重力影響，下次的下降速度增加
			}
			else {
				y = floor - 1;  // 當y座標低於地板，更正為地板上
				velocity = 0;
				isJumping = false;
			}
		}
		*/
	}

	void CPlayer::SetMovingLeft(bool flag)
	{
		if (!isCharging) isMovingLeft = flag;
		character_direction = LEFT;
	}

	void CPlayer::SetMovingRight(bool flag)
	{
		if (!isCharging && !isRising && !isFalling)
		{
			isMovingRight = flag;
			character_direction = RIGHT;
		}
	}
	void CPlayer::JumpCharge(bool flag) {
		isCharging = flag;
	}

	void CPlayer::SetJump()
	{
		if (!isFalling && !isRising) {
			isRising = true;
			vertical_velocity = initial_velocity;
		}
	}

	void CPlayer::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void CPlayer::OnShow()
	{
		rightDefault.SetTopLeft(x, y);
		leftDefault.SetTopLeft(x, y);
		moveRight.SetTopLeft(x, y);
		moveLeft.SetTopLeft(x, y);
		charge.SetTopLeft(x, y);
		if (isCharging) charge.ShowBitmap();
		else if (isMovingRight) moveRight.OnShow();
		else if (isMovingLeft) moveLeft.OnShow();
		else {
			if (character_direction == RIGHT) rightDefault.ShowBitmap();
			else leftDefault.ShowBitmap();
		}

	}
}