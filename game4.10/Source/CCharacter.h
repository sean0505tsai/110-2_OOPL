#pragma once

namespace game_framework {

	class CCharacter
	{
	public:
		CCharacter();
		int  GetX1();					// 左上角 x 座標
		int  GetY1();					// 左上角 y 座標
		int  GetX2();					// 右下角 x 座標
		int  GetY2();					// 右下角 y 座標
		void Initialize();				// 設定擦子為初始值
		void LoadBitmap();				// 載入圖形
		void OnMove();					// 移動
		void OnShow();					// 將圖形貼到畫面
		void SetMovingLeft(bool flag);	// 設定是否正在往左移動
		void SetMovingRight(bool flag); // 設定是否正在往右移動
		void SetJump(bool flag);		// 設定是否跳躍及初速
		void JumpCharge(bool flag);		// 跳躍蓄力
		void SetXY(int nx, int ny);		// 設定左上角座標
	protected:
		CMovingBitmap rightDefault;		// 角色向右預設圖
		CMovingBitmap leftDefault;		// 角色向左預設圖
		CMovingBitmap leftFallHitGround;	//	高處落下撞擊地面(左)
		CMovingBitmap rightFallHitGround;	//	高處落下撞擊地面(右)
		CMovingBitmap leftRising;
		CMovingBitmap rightRising;
		CMovingBitmap leftFalling;
		CMovingBitmap rightFalling;
		CMovingBitmap charge;
		CAnimation moveRight;
		CAnimation moveLeft;
		int x, y;					// 左上角座標
		int floor;

		enum direction_flag {
			LEFT = 1,
			RIGHT = 0
		};

		int character_direction;			// 角色面對方向
		bool upperCollision;				// 上方是否碰撞
		bool bottomCollision;				// 下方是否碰撞
		bool leftCollision;					// 左方是否碰撞
		bool rightCollision;				// 右方是否碰撞

		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isJumping;				// 是否正在往上移動
		bool rising;				// true表上升、false表下降

		bool isCharging;			// 是否正在蓄力
		int initial_velocity;		// 跳躍初速
		int velocity;				// 目前的速度(點/次)
	};
}