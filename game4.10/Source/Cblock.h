namespace game_framework {

	class CBlock {
	public:
		CBlock();												// Constructor
		bool HitTop(CEraser* eraser);							// 頂端是否碰到擦子
		bool HitBottom(CEraser* eraser);						// 底部是否碰到
		bool HitLeft(CEraser* eraser);							// 左邊是否碰到
		bool HitRight(CEraser* eraser);							// 右邊是否碰到
		void LoadBitmap();										// 載入圖形
		void OnShow();											// 將圖形貼到畫面
		void SetXY(int nx, int ny);								// 設定左上角座標
		void Initialize();
	protected:
		CMovingBitmap bmp;			// 圖	
		int x1, y1;					// 左上角座標
		int x2, y2;					// 右下角座標
		bool hit_left;				// 左邊是否碰撞
		bool hit_right;				// 右邊是否碰撞
		bool hit_top;				// 頂部是否碰撞
		bool hit_bottom;			// 底部是否碰撞
	private:
		bool HitRectangle(int tx1, int ty1, int tx2, int ty2);	// 是否碰到參數範圍的矩形
	};
}
