#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CCharacter.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// CEraser: Eraser class
	/////////////////////////////////////////////////////////////////////////////

	CCharacter::CCharacter()	// Constructor
	{
		Initialize();
	}

	int CCharacter::GetX1()		// return ���W��x�y��
	{
		return x;
	}

	int CCharacter::GetY1()		//return ���W��y�y��
	{
		return y;
	}

	int CCharacter::GetX2()		// return �k�U��x�y��
	{
		return x + rightDefault.Width();
	}

	int CCharacter::GetY2()		// return �k�U��y�y��
	{
		return y + rightDefault.Height();
	}

	void CCharacter::Initialize()
	{
		const int X_POS = 280;
		const int Y_POS = 400;
		const int INITIAL_VELOCITY = 20;
		x = X_POS;
		y = Y_POS;
		character_direction = RIGHT;
		floor = 400;
		isMovingLeft = isMovingRight = isJumping = isMovingDown = false;
		initial_velocity = INITIAL_VELOCITY;
		velocity = initial_velocity;
	}

	void CCharacter::LoadBitmap()
	{

		rightDefault.LoadBitmap(IDB_CHARACTER_DEFAULT, RGB(0, 255, 0));
		leftDefault.LoadBitmap(IDB_DEFAULT_LEFT, RGB(0, 255, 0));
		moveRight.AddBitmap(IDB_MOVE_RIGHT_1, RGB(0, 255, 0));
		moveRight.AddBitmap(IDB_MOVE_RIGHT_2, RGB(0, 255, 0));
		moveRight.AddBitmap(IDB_MOVE_RIGHT_3, RGB(0, 255, 0));
		moveRight.AddBitmap(IDB_MOVE_RIGHT_2, RGB(0, 255, 0));

		moveLeft.AddBitmap(IDB_MOVE_LEFT_1, RGB(0, 255, 0));
		moveLeft.AddBitmap(IDB_MOVE_LEFT_2, RGB(0, 255, 0));
		moveLeft.AddBitmap(IDB_MOVE_LEFT_3, RGB(0, 255, 0));
		moveLeft.AddBitmap(IDB_MOVE_LEFT_2, RGB(0, 255, 0));
	}

	void CCharacter::OnMove()
	{
		const int STEP_SIZE = 2;
		moveRight.OnMove();
		moveLeft.OnMove();
		if (isMovingLeft)
			x -= STEP_SIZE;
		if (isMovingRight)
			x += STEP_SIZE;

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
				y += velocity;	// y�b�U��(����velocity���I�Avelocity����쬰 �I/��)
				velocity++;		// �����O�v�T�A�U�����U���t�׼W�[
			}
			else {
				y = floor - 1;  // ��y�y�ЧC��a�O�A�󥿬��a�O�W
				velocity = 0;
				isJumping = false;
			}
		}
	}

	void CCharacter::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
		character_direction = LEFT;
	}

	void CCharacter::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
		character_direction = RIGHT;
	}

	void CCharacter::SetJump(bool flag)
	{
		velocity = initial_velocity;
		isJumping = flag;
	}

	void CCharacter::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void CCharacter::OnShow()
	{
		rightDefault.SetTopLeft(x, y);
		leftDefault.SetTopLeft(x, y);
		moveRight.SetTopLeft(x, y);
		moveLeft.SetTopLeft(x, y);
		if (isMovingRight) moveRight.OnShow();
		else if (isMovingLeft) moveLeft.OnShow();
		else {
			if (character_direction == RIGHT) rightDefault.ShowBitmap();
			else leftDefault.ShowBitmap();
		}

	}
}