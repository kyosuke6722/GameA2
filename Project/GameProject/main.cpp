//ゲーム係機能のインクルード
#include <GLLibrary.h>
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#include "Base/Base.h"
#include"Title/Title.h"
#include"Game03/AnimData03.h"
//--------------------------------------------
//グローバル変数領域
//--------------------------------------------




void MainLoop(void) {
	//--------------------------------------------------------------
	//ゲーム中の動きはここに書く
	//ゲーム中はこの関数_を1秒間に60回呼び出している
	//--------------------------------------------------------------
	Base::CheckKillAll();
	Base::UpdateAll();
	Base::CollisionAll();
	Base::DrawAll();


}
void Init(void)
{

	CFPS::SetFPS(60);
	//フレーム制御初期化
	CFPS::Init();
	//ボタンの設定
	CInput::Init();
	CInput::SetButton(0, CInput::eButton1, 'Z');
	CInput::SetButton(0, CInput::eButton2, 'X');
	CInput::SetButton(0, CInput::eButton3, 'C');
	CInput::SetButton(0, CInput::eButton4, 'V');
	CInput::SetButton(0, CInput::eButton5, VK_SPACE);
	CInput::SetButton(0, CInput::eButton10, VK_RETURN);
	CInput::SetButton(0, CInput::eUp, 'W');
	CInput::SetButton(0, CInput::eDown, 'S');
	CInput::SetButton(0, CInput::eLeft, 'A');
	CInput::SetButton(0, CInput::eRight, 'D');
	CInput::SetButton(0, CInput::eMouseL, VK_LBUTTON);
	CInput::SetButton(0, CInput::eMouseR, VK_RBUTTON);
	CInput::SetButton(0, CInput::eMouseC, VK_MBUTTON);
	//	CInput::SetMouseInside(true);
	//	CInput::ShowCursor(false);
	CInput::Update();
	CInput::Update();



	SetCurrentDirectory("data");
	CSound::GetInstance();

	//-----------------------------------------------------
	//初期化の命令を書く
	//ゲーム起動時に一度だけ呼ばれる
	//-----------------------------------------------------

	//-----------------------------------------------------
	//Game共通
	//-----------------------------------------------------
	ADD_RESOURCE("UI", CImage::CreateImage("Image/UI.png"));//タイム計測用(全ゲーム共通)
	SOUND("SE_Clear")->Load("Sound/SE/SE_Clear.wav", 1);//クリア時ジングル
	SOUND("SE_AllClear")->Load("Sound/SE/SE_AllClear.wav", 1);//オールクリア時ジングル
	ADD_RESOURCE("Bullet", CImage::CreateImage("Image/Bullet.png"));//シューティングゲームの弾(Game02,Game04)
	ADD_RESOURCE("MapTip", CImage::CreateImage("Image/MapTip.png"));//マップチップ(Game03,Game04)
	SOUND("SE_Bomb")->Load("Sound/SE/SE_Bomb02.wav", 10);//敵爆破SE(Game02,Game04)
	SOUND("SE_Hit")->Load("Sound/SE/SE_Hit.wav", 3);

	//-----------------------------------------------------
	//Game01(担当:森口)
	//-----------------------------------------------------
	ADD_RESOURCE("Ball01", CImage::CreateImage("Image/Ball2.png"));
	ADD_RESOURCE("Enemy01", CImage::CreateImage("Image/Bar.png"));
	ADD_RESOURCE("Player01", CImage::CreateImage("Image/Bar.png"));
	ADD_RESOURCE("Number", CImage::CreateImage("Image/Number.png"));
	ADD_RESOURCE("background", CImage::CreateImage("Image/Game01_background.png"));
	SOUND("BGM_Game01")->Load("Sound/BGM/BGM_Game01.wav", 1);
	SOUND("SE_Hit01")->Load("Sound/SE/SE_Hit_01.wav", 10);
	SOUND("SE_Get01")->Load("Sound/SE/SE_Get_01.wav", 1);
	//-----------------------------------------------------
	//Game02(担当:林)
	//-----------------------------------------------------
	ADD_RESOURCE("Player02", CImage::CreateImage("Image/Player02.png"));
	ADD_RESOURCE("Enemy02", CImage::CreateImage("Image/Enemy02.png"));
	ADD_RESOURCE("Effect_Bomb", CImage::CreateImage("Image/Effect_Bomb.png"));
	ADD_RESOURCE("Bullet2", CImage::CreateImage("Image/Bullet2.png"));

	SOUND("BGM_Game02")->Load("Sound/BGM/BGM_Game02.wav",1);
	//-----------------------------------------------------
	//Game03(担当:小山)
	//-----------------------------------------------------
	ADD_RESOURCE("Player03", CImage::CreateImage("Image/Player03.png", player_anim_data, 256, 256));
	ADD_RESOURCE("Enemy03", CImage::CreateImage("Image/Enemy03.png", enemy_anim_data, 256, 256));
	ADD_RESOURCE("Background03", CImage::CreateImage("Image/Dungeon.png"));
	ADD_RESOURCE("Goal", CImage::CreateImage("Image/Goal.png"));
	ADD_RESOURCE("Slash", CImage::CreateImage("Image/Effect_Slash.png", effect_slash_anim_data, 128, 128));
	ADD_RESOURCE("Effect_Smoke", CImage::CreateImage("Image/Effect_Smoke.png", effect_smoke_anim_data, 128, 128));
	ADD_RESOURCE("Effect_Blood", CImage::CreateImage("Image/Effect_Blood.png", effect_blood_anim_data, 128, 128));

	SOUND("BGM_Game03")->Load("Sound/BGM/BGM_Game03.wav", 1);
	SOUND("SE_EnemyDamage03")->Load("Sound/SE/SE_EnemyDamage_03.wav", 10);
	SOUND("SE_PlayerDamage03")->Load("Sound/SE/SE_PlayerDamage_03.wav", 1);

	//-----------------------------------------------------
	//Game04(担当:森口)
	//-----------------------------------------------------
	ADD_RESOURCE("Player04", CImage::CreateImage("Image/Player04.png"));
	ADD_RESOURCE("Enemy04", CImage::CreateImage("Image/Enemy04.png"));
	SOUND("BGM_Game04")->Load("Sound/BGM/BGM_Game04.wav", 1);
	
	





	//-----------------------------------------------------
	//Title(担当:小山)
	//-----------------------------------------------------
	ADD_RESOURCE("Title1", CImage::CreateImage("Image/Title.png"));
	ADD_RESOURCE("Title2", CImage::CreateImage("Image/Title2.png"));
	ADD_RESOURCE("Title_text", CImage::CreateImage("Image/Title_text.png"));
	ADD_RESOURCE("Result", CImage::CreateImage("Image/Result.png"));
	ADD_RESOURCE("Anatora", CImage::CreateImage("Image/anatora.png"));

	SOUND("BGM_Result")->Load("Sound/BGM/BGM_Result.wav", 1);
	SOUND("BGM_Title")->Load("Sound/BGM/BGM_Title.wav", 1);
	SOUND("BGM_Menu")->Load("Sound/BGM/BGM_Menu.wav", 1);
	SOUND("SE_Button1")->Load("Sound/SE/SE_Button_Title.wav", 1);
	SOUND("SE_Button2")->Load("Sound/SE/SE_Button_Menu.wav", 1);



	Base::Add(new Title());










}


void Release()
{
	CLoadThread::ClearInstance();
	CSound::ClearInstance();
	CResourceManager::ClearInstance();
}

static void ResizeCallback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h);

	//画面解像度変動
	CCamera::GetCamera()->SetSize((float)w, (float)h);
	//画面解像度固定
	//CCamera::GetCamera()->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	CCamera::GetCamera()->Viewport(0, 0, w, h);
	CCamera::GetCurrent()->Perspective(DtoR(60.0), (float)w / (float)h, 1.0, 1000.0);

	glfwGetWindowPos(window, &GL::window_x, &GL::window_y);
	GL::UpdateWindowRect(GL::window_x, GL::window_y, w, h);
	CInput::UpdateClipCursor(true);

}
static void WheelCallback(GLFWwindow* _window, double _offsetx, double _offsety) {
	CInput::AddMouseWheel((int)_offsety);

}
static void PosCallback(GLFWwindow* _window, int x, int y) {
	GL::window_x = x;
	GL::window_y = y;
	GL::UpdateWindosRect(x, y, GL::window_width, GL::window_height);
	CInput::UpdateClipCursor(true);

}
static void FocusCallback(GLFWwindow* _window, int f) {
	CInput::UpdateClipCursor(f);
	GL::focus = f;
}

static void error_callback(int error, const char* description)
{
	printf("Error: %s\n", description);
}

//フルスクリーン?ウインドウモードの切り替え
//Alt+Enterで切り替える
void CheckFullScreen() {
	static int key_enter = 0;
	int key_enter_buf = key_enter;
	if (key_enter_buf ^ (key_enter = glfwGetKey(GL::window, GLFW_KEY_ENTER)) && key_enter && (glfwGetKey(GL::window, GLFW_KEY_LEFT_ALT) || glfwGetKey(GL::window, GLFW_KEY_RIGHT_ALT))) {
		GL::ChangeFullScreen(!GL::full_screen);
	}
}

int __main(int* argcp, char** argv) {
	// メモリリーク検出
	//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//OpenGL4.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) return -1;
	//	glutInit(argcp, argv);

	GL::window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple", nullptr, nullptr);
	glfwGetWindowSize(GL::window, &GL::window_width, &GL::window_height);
	glfwGetWindowPos(GL::window, &GL::window_x, &GL::window_y);

	glfwSetFramebufferSizeCallback(GL::window, ResizeCallback);
	glfwSetScrollCallback(GL::window, WheelCallback);
	glfwSetWindowFocusCallback(GL::window, FocusCallback);
	glfwSetWindowPosCallback(GL::window, PosCallback);
	if (!GL::window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(GL::window);
	glfwSwapInterval(1);
	ResizeCallback(GL::window, SCREEN_WIDTH, SCREEN_HEIGHT);

	GLenum err = glewInit();
	if (err == GLEW_OK) {
		printf("%s\n", glewGetString(GLEW_VERSION));
	}
	else {
		printf("%s\n", glewGetErrorString(err));
		getchar();
		return -1;
	}
	HDC glDc = wglGetCurrentDC();
	GL::hWnd = WindowFromDC(glDc);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);//ブレンドの有効化
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//固定シェーダー用
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_ALPHA_TEST);

	Init();
	while (!glfwWindowShouldClose(GL::window)) {
		CheckFullScreen();


		CInput::Update();
		//各バッファーをクリア
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		MainLoop();


		glfwSwapBuffers(GL::window);


		CFPS::Wait();

		char title[32];
		sprintf_s(title, "math fps:%d dt:%.3f", CFPS::GetFPS(), CFPS::GetDeltaTime());
		glfwSetWindowTitle(GL::window, title);

		glfwPollEvents();
		if (glfwGetKey(GL::window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(GL::window, GL_TRUE);
		}

	}

	glfwTerminate();




	Release();
	return 0;
}

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR argv, INT argc)
{
	return __main(&__argc, __argv);
}

int main(int argc, char** argv)
{
	return __main(&argc, argv);
}
