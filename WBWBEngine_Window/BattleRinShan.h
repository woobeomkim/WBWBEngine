#pragma once
#include "wbComponent.h"

namespace wb
{
    class BattleRinShan  : public Component
    {
	public:
		enum class State
		{
			Idle,
			NailAttack, // �������
			HighKick, // ����ű
			MiddleKick, // �̵�ű
			LowKick, //��ű
			Provocation, // ����
			skewer, // ��ì�̲��
			FacialSwanGwon, // �ȸ������
			LineGwon, // ���İ�
			IceGwon,
			Guard,

		};

		BattleRinShan();
		~BattleRinShan();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void idle();
		void nailAttack();
		void highKick();
		void middleKick();
		void lowKick();
		void provocation();
		void skewer();
		void facialSwanGwon();
		void lineGwon();
		void iceGwon();
		void guard();

	private:


    };
}

