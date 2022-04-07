namespace game_framework {

	class CBlock {
	public:
		CBlock();												// Constructor
		bool HitTop(CEraser* eraser);							// ���ݬO�_�I�����l
		bool HitBottom(CEraser* eraser);						// �����O�_�I��
		bool HitLeft(CEraser* eraser);							// ����O�_�I��
		bool HitRight(CEraser* eraser);							// �k��O�_�I��
		void LoadBitmap();										// ���J�ϧ�
		void OnShow();											// �N�ϧζK��e��
		void SetXY(int nx, int ny);								// �]�w���W���y��
		void Initialize();
	protected:
		CMovingBitmap bmp;			// ��	
		int x1, y1;					// ���W���y��
		int x2, y2;					// �k�U���y��
		bool hit_left;				// ����O�_�I��
		bool hit_right;				// �k��O�_�I��
		bool hit_top;				// �����O�_�I��
		bool hit_bottom;			// �����O�_�I��
	private:
		bool HitRectangle(int tx1, int ty1, int tx2, int ty2);	// �O�_�I��Ѽƽd�򪺯x��
	};
}
