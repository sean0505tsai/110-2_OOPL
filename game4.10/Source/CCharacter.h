#pragma once

namespace game_framework {

	class CCharacter
	{
	public:
		CCharacter();
		int  GetX1();					// ���W�� x �y��
		int  GetY1();					// ���W�� y �y��
		int  GetX2();					// �k�U�� x �y��
		int  GetY2();					// �k�U�� y �y��
		void Initialize();				// �]�w���l����l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// �������l
		void OnShow();					// �N�ϧζK��e��
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetJump(bool flag);	// �]�w�O�_���D�Ϊ�t
		void SetXY(int nx, int ny);		// �]�w���W���y��
	protected:
		CMovingBitmap rightDefault;		// ����V�k�w�]��
		CMovingBitmap leftDefault;		// ����V���w�]��
		CAnimation moveRight;
		CAnimation moveLeft;
		int x, y;					// ���W���y��
		int floor;

		enum direction_flag {
			LEFT = 1,
			RIGHT = 0
		};

		int character_direction;			// ���⭱���V
		bool hitObject;				// �O�_�����a�Ϫ���
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isJumping;			// �O�_���b���W����
		bool rising;				// true��W�ɡBfalse��U��
		int initial_velocity;		// ���D��t
		int velocity;				// �ثe���t��(�I/��)
	};
}