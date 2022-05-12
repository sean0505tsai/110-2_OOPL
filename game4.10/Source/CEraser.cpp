#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CEraser.h"

/*######�a�Ϯy��######
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

	int CPlayer::GetX1()		// return ���W��x�y��
	{
		return x;
	}

	int CPlayer::GetY1()		//return ���W��y�y��
	{
		return y;
	}

	int CPlayer::GetX2()		// return �k�U��x�y��
	{
		return x + rightDefault.Width();
	}

	int CPlayer::GetY2()		// return �k�U��y�y��
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
		

		if (isFalling) {						// �U�����A
			if (!bottomCollision)				// �|���I��a�O
			{				
				y += vertical_velocity;
				if (vertical_velocity < 20) vertical_velocity++;
			}
			else if (bottomCollision)			// �I��a�O
			{
				vertical_velocity = 0;
				initial_velocity = 0;
				isFalling = false;
			}
		}
		
		if (isRising) {			// �W�ɪ��A
			if (!topCollision) {

				if (vertical_velocity != 0) {			// �W�ɤ�
					y -= vertical_velocity;
					vertical_velocity--;
				}
				else			// ��F���I
				{
					isRising = false;			// �}�l�U�Y
					isFalling = true;
				}

			}
			else{		// �����I�� �}�l�U�Y
				vertical_velocity = 0;
				isRising = false;
				isFalling = true;
			}
		}
		
		if (isCharging) {		// �W�O���A
			if (initial_velocity <= 20) initial_velocity++;
			SetJump();
		}

		
		// ��a���A
		if (isMovingLeft)
			x -= STEP_SIZE;
		if (isMovingRight)
			x += STEP_SIZE;
		

		/*
		if (isJumping) {			// �W�ɪ��A
			if (velocity > 0) {
				y -= velocity;	// ��t�� > 0�ɡAy�b�W��(����velocity���I�Avelocity����쬰 �I/��)
				velocity--;		// �����O�v�T�A�U�����W�ɳt�׭��C
			}
			else {
				isJumping = false; // ��t�� <= 0�A�W�ɲפ�A�U���אּ�U��
				velocity = 1;	// �U������t(velocity)��1
			}
		}
		else {				// �U�����A
			if (y < floor - 1) {  // ��y�y���٨S�I��a�O
				initial_velocity = 0;
				y += velocity;	// y�b�U��(����velocity���I�Avelocity����쬰 �I/��)
				velocity++;		// �����O�v�T�A�U�����U���t�׼W�[
			}
			else {
				y = floor - 1;  // ��y�y�ЧC��a�O�A�󥿬��a�O�W
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