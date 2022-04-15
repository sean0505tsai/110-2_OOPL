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
		void OnMove();					// 移動擦子
		void OnShow();					// 將圖形貼到畫面
		void SetMovingLeft(bool flag);	// 設定是否正在往左移動
		void SetMovingRight(bool flag); // 設定是否正在往右移動
		void SetJump(bool flag);	// 設定是否跳躍及初速
		void SetXY(int nx, int ny);		// 設定左上角座標
	protected:
		CMovingBitmap rightDefault;		// 角色向右預設圖
		CMovingBitmap leftDefault;		// 角色向左預設圖
		CAnimation moveRight;
		CAnimation moveLeft;
		int x, y;					// 左上角座標
		int floor;

		enum direction_flag {
			LEFT = 1,
			RIGHT = 0
		};

		int character_direction;			// 角色面對方向
		bool hitObject;				// 是否撞擊地圖物件
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isJumping;			// 是否正在往上移動
		bool rising;				// true表上升、false表下降
		int initial_velocity;		// 跳躍初速
		int velocity;				// 目前的速度(點/次)
	};
}