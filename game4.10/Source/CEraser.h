namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѥi�H����L�ηƹ�������l
	// �����N�i�H��g���ۤv���{���F
	/////////////////////////////////////////////////////////////////////////////

	class CEraser
	{
	public:
		CEraser();
		int  GetX1();					// ���l���W�� x �y��
		int  GetY1();					// ���l���W�� y �y��
		int  GetX2();					// ���l�k�U�� x �y��
		int  GetY2();					// ���l�k�U�� y �y��
		void Initialize();				// �]�w���l����l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// �������l
		void OnShow();					// �N���l�ϧζK��e��
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetJump(bool flag);
		//void SetJump(bool flag, int initial_velocity); //�]�w�O�_���D�Ϊ�l�t��
		void SetXY(int nx, int ny);		// �]�w���l���W���y��
	protected:
		CAnimation animation;		// ���l���ʵe
		int x, y;					// ���l���W���y��
		int initial_velocity;		// ��l�t��
		int velocity;				// �ثe���t��(�I/��)
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		bool isMovingDown;			// �O�_���b���U����
		bool isRising;				// �O�_���b�W��
		bool isFalling;				// �O�_���b�U��
		bool isJumping;
	};
}