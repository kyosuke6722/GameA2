#include "Title.h"
#include"../Game01/Game01.h"

Title::Title():Base(eType_Scene) {
}

Title::~Title(){
	Base::KillAll();
	Base::Add(new Game01());
}

void Title::Update(){
	if (PUSH(CInput::eButton1)) {
		SetKill();
	}
}

void Title::Draw(){
}