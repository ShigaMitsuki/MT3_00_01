#include <Novice.h>
#include "Vector2.h"
#include "Vector3.h"

const char kWindowTitle[] = "学籍番号";

static const int kColmnWidth = 60;
static const int kRowHeight = 20;
void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColmnWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColmnWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColmnWidth * 3, y, "%s", label);

}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Vector3 v1{ 1.0f, 3.0f , -5.0f };
	Vector3 v2{ 4.0f, -1.0f , 2.0f };
	float k = { 4.0f };
	k;

	Vector3 ResultAdd = Add(v1, v2);
	Vector3 ResultSubtract = Subtract(v1, v2);
	Vector3 ResultMultiply = Multiply(k, v1);
	float ResultDot = Dot(v1, v2);
	float ResultLength = Length(v1);
	Vector3 ResiultNormalize = Normalize(v2);

	

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		VectorScreenPrintf(0, 0, ResultAdd, " : Add ");
		VectorScreenPrintf(0, kRowHeight, ResultSubtract, " : Subtract ");
		VectorScreenPrintf(0, kRowHeight * 2, ResultMultiply, " : Multiply ");
		Novice::ScreenPrintf(0, kRowHeight * 3, "%0.2f : Dot", ResultDot);
		Novice::ScreenPrintf(0, kRowHeight * 4, "%0.2f : Length", ResultLength);
		VectorScreenPrintf(0, kRowHeight * 5, ResiultNormalize, " : Normalize ");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

